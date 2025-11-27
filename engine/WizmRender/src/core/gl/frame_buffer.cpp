#include "core/gl/frame_buffer.h"
#include "glad.h"
#include <iostream>

bool wizmrenderer::is_depth_format(framebuffer_texture_format format)
{
	switch (format)
	{
	case framebuffer_texture_format::DEPTH24STENCIL8:  return true;
	}

	return false;
}

unsigned int wizmrenderer::texture_target(bool multisampled)
{
	return multisampled ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D;
}

void wizmrenderer::create_texture(bool multisampled, uint32_t* outID, uint32_t count)
{
	glCreateTextures(texture_target(multisampled), count, outID);
}

void wizmrenderer::bind_texture(bool multisampled, uint32_t id)
{
	glBindTexture(texture_target(multisampled), id);
}

unsigned int wizmrenderer::framebuffer_texture_format_to_gl(framebuffer_texture_format format)
{
	switch (format)
	{
	case framebuffer_texture_format::RGBA8:       return GL_RGBA8;
	case framebuffer_texture_format::RED_INTEGER: return GL_RED_INTEGER;
	}

	return 0;
}

void wizmrenderer::attach_color_texture(uint32_t id, int samples, unsigned int internalFormat, unsigned int format, uint32_t width, uint32_t height, int index)
{
	bool multisampled = samples > 1;
	if (multisampled)
	{
		glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples, internalFormat, width, height, GL_FALSE);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, nullptr);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + index, texture_target(multisampled), id, 0);
}

void wizmrenderer::attach_depth_texture(uint32_t id, int samples, unsigned int format, unsigned int attachmentType, uint32_t width, uint32_t height)
{
	bool multisampled = samples > 1;
	if (multisampled)
	{
		glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples, format, width, height, GL_FALSE);
	}
	else
	{
		glTexStorage2D(GL_TEXTURE_2D, 1, format, width, height);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}

	glFramebufferTexture2D(GL_FRAMEBUFFER, attachmentType, texture_target(multisampled), id, 0);
}

wizmrenderer::core_framebuffer::core_framebuffer(framebuffer_spec spec)
	:m_spec(spec)
{
	for (auto format : m_spec.attachment.attachments) {
		if (!is_depth_format(format.texture_format))
			m_color_attachment_spec.emplace_back(format);
		else
			m_depth_attachment_spec = format.texture_format;
	}

	create_fbuffer();
}

wizmrenderer::core_framebuffer::~core_framebuffer()
{
	destroy_buffer();
}

int wizmrenderer::core_framebuffer::read_pixel(unsigned int color_attachement_index, int x, int y)
{
	glReadBuffer(GL_COLOR_ATTACHMENT0 + color_attachement_index);

	float r, g, b;
	float pixels[3];
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, pixels);

	r = pixels[0];
	g = pixels[1];
	b = pixels[2];

	int red = static_cast<int>(r * 255.0f);
	int green = static_cast<int>(g * 255.0f);
	int blue = static_cast<int>(b * 255.0f);

	int pick_color = (red << 16) | (green << 8) | blue;

	return pick_color;
}

void wizmrenderer::core_framebuffer::clear_attachment(unsigned int attachment_index, int value)
{
	if (attachment_index > m_color_attachment_spec.size())
		throw std::invalid_argument("index out of range for fbo");

	auto& spec = m_color_attachment_spec[attachment_index];
	glClearTexImage(m_color_attachments[attachment_index], 0, framebuffer_texture_format_to_gl(spec.texture_format), GL_INT, &value);
}

void wizmrenderer::core_framebuffer::create_fbuffer()
{
	if (this->buffer_id)
	{
		destroy_buffer();
	}

	glGenFramebuffers(1, &this->buffer_id);
	glBindFramebuffer(GL_FRAMEBUFFER, this->buffer_id);

	bool multisample = m_spec.Samples > 1;

	if (m_color_attachment_spec.size()) {

		m_color_attachments.resize(m_color_attachment_spec.size());
		create_texture(multisample, m_color_attachments.data(), (uint32_t)m_color_attachments.size());


		for (int i = 0; i < m_color_attachments.size(); i++) {
			bind_texture(multisample, m_color_attachments[i]);
			switch (m_color_attachment_spec[i].texture_format) {
			case framebuffer_texture_format::RGBA8:
				attach_color_texture(m_color_attachments[i], m_spec.Samples, GL_RGBA8, GL_RGBA, m_spec.Width, m_spec.Height, i);
				break;

			case framebuffer_texture_format::RED_INTEGER:
				attach_color_texture(m_color_attachments[i], m_spec.Samples, GL_R32I, GL_RED_INTEGER, m_spec.Width, m_spec.Height, i);
				break;

			case framebuffer_texture_format::RGBA16:
				attach_color_texture(m_color_attachments[i], m_spec.Samples, GL_RGBA16F, GL_RGBA, m_spec.Width, m_spec.Height, i);
				break;
			}
		}
	}
	if (m_depth_attachment_spec.texture_format != framebuffer_texture_format::None) {
		create_texture(multisample, &m_depth_attachment, 1);
		bind_texture(multisample, m_depth_attachment);
		switch (m_depth_attachment_spec.texture_format) {
		case framebuffer_texture_format::DEPTH24STENCIL8:
			attach_depth_texture(m_depth_attachment, m_spec.Samples, GL_DEPTH24_STENCIL8, GL_DEPTH_STENCIL_ATTACHMENT, m_spec.Width, m_spec.Height);
			break;
		}
	}
	if (m_color_attachments.size() > 1) {
		GLenum buffers[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };
		glDrawBuffers((GLsizei)m_color_attachments.size(), buffers);
	}
	else if (m_color_attachments.empty()) {

		GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
		if (status != GL_FRAMEBUFFER_COMPLETE) {
			std::cerr << "Framebuffer not complete!" << std::endl;
		}

		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);
	}
	unbind_buffer();
}

void wizmrenderer::core_framebuffer::resize(unsigned int width, unsigned int height)
{
	if (width == 0 || height == 0 || width > MAX_FB_SIZE || height > MAX_FB_SIZE)
	{
		return;
	}

	m_spec.Width = width;
	m_spec.Height = height;

	invalidate();
}

void wizmrenderer::core_framebuffer::invalidate()
{
	if (buffer_id)
	{
		glDeleteFramebuffers(1, &buffer_id);

		glDeleteTextures((GLsizei)m_color_attachments.size(), m_color_attachments.data());
		glDeleteTextures(1, &m_depth_attachment);

		m_color_attachments.clear();
		m_depth_attachment = 0;
	}

	glCreateFramebuffers(1, &buffer_id);
	glBindFramebuffer(GL_FRAMEBUFFER, buffer_id);

	bool multisample = m_spec.Samples > 1;

	if (m_color_attachment_spec.size())
	{
		m_color_attachments.resize(m_color_attachment_spec.size());
		create_texture(multisample, m_color_attachments.data(), (uint32_t)m_color_attachments.size());

		for (int i = 0; i < m_color_attachments.size(); i++)
		{
			bind_texture(multisample, m_color_attachments[i]);
			switch (m_color_attachment_spec[i].texture_format)
			{
			case framebuffer_texture_format::RGBA8:
				attach_color_texture(m_color_attachments[i], m_spec.Samples, GL_RGBA8, GL_RGBA, m_spec.Width, m_spec.Height, i);
				break;
			case framebuffer_texture_format::RED_INTEGER:
				attach_color_texture(m_color_attachments[i], m_spec.Samples, GL_R32I, GL_RED_INTEGER, m_spec.Width, m_spec.Height, i);
				break;
			}
		}
	}

	if (m_depth_attachment_spec.texture_format != framebuffer_texture_format::None)
	{
		create_texture(multisample, &m_depth_attachment, 1);
		bind_texture(multisample, m_depth_attachment);
		switch (m_depth_attachment_spec.texture_format)
		{
		case framebuffer_texture_format::DEPTH24STENCIL8:
			attach_depth_texture(m_depth_attachment, m_spec.Samples, GL_DEPTH24_STENCIL8, GL_DEPTH_STENCIL_ATTACHMENT, m_spec.Width, m_spec.Height);
			break;
		}
	}

	if (m_color_attachments.size() > 1)
	{
		if (!(m_color_attachments.size() <= 4))
			throw std::invalid_argument("m_color_attachments.size() <= 4");

		GLenum buffers[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };
		glDrawBuffers((GLsizei)m_color_attachments.size(), buffers);
	}
	else if (m_color_attachments.empty())
	{
		glDrawBuffer(GL_NONE);
	}

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
		throw std::invalid_argument("framebuffer isnt built");
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void wizmrenderer::core_framebuffer::gen_buffer()
{
}

void wizmrenderer::core_framebuffer::bind_buffer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, this->buffer_id);
	glViewport(0, 0, m_spec.Width, m_spec.Height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void wizmrenderer::core_framebuffer::unbind_buffer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void wizmrenderer::core_framebuffer::destroy_buffer()
{
	if (this->buffer_id)
	{
		glDeleteFramebuffers(GL_FRAMEBUFFER, &this->buffer_id);
		for (auto attachment : m_color_attachments) {
			glDeleteTextures(1, &attachment);
		}
		m_color_attachments.clear();

		glDeleteTextures(1, &m_depth_attachment);
	}
}

unsigned int wizmrenderer::core_framebuffer::get_color_attachment_render_id(int index)
{
	if (index > m_color_attachments.size())
		throw std::invalid_argument("index out of range for fbo");
	return m_color_attachments[index];
}

unsigned int wizmrenderer::core_framebuffer::get_depth_attachment_render_id()
{
	return m_depth_attachment;
}
