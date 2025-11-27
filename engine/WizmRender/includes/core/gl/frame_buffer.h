#pragma once
#include "core_buffer.h"
#include <vector>

#define MAX_FB_SIZE  8192

namespace wizmrenderer {

	enum class framebuffer_texture_format {
		None = 0,

		// color
		RGBA8,
		RGBA16,
		RED_INTEGER,

		// depth
		DEPTH24STENCIL8,
		Depth = DEPTH24STENCIL8
	};


	struct framebuffer_texture_sepc {
		framebuffer_texture_sepc() = default;
		framebuffer_texture_sepc(framebuffer_texture_format format)
			: texture_format(format) {
		}

		framebuffer_texture_format texture_format;

	};

	struct framebuffer_attachment_spec {
		framebuffer_attachment_spec() = default;
		framebuffer_attachment_spec(const std::initializer_list<framebuffer_texture_sepc> specs)
			: attachments(specs) {
		}
		std::vector<framebuffer_texture_sepc> attachments;
	};

	struct framebuffer_spec
	{
		uint32_t Width = 0, Height = 0;
		framebuffer_attachment_spec attachment;
		uint32_t Samples = 1;

		bool SwapChainTarget = false;
	};


	inline bool is_depth_format(framebuffer_texture_format format);
	inline unsigned	int texture_target(bool multisampled);
	inline void create_texture(bool multisampled, uint32_t* outID, uint32_t count);
	inline void bind_texture(bool multisampled, uint32_t id);
	inline unsigned	int framebuffer_texture_format_to_gl(framebuffer_texture_format format);
	inline void attach_color_texture(uint32_t id, int samples, unsigned	int internalFormat, unsigned int format, uint32_t width, uint32_t height, int index);
	inline void attach_depth_texture(uint32_t id, int samples, unsigned	int format, unsigned int attachmentType, uint32_t width, uint32_t height);

	class core_framebuffer : public core_buffer_object {
	public:
		core_framebuffer(framebuffer_spec spec);
		~core_framebuffer();

		int read_pixel(unsigned int color_attachement_index, int x, int y);
		void clear_attachment(unsigned int attachment_index, int value);

		void create_fbuffer();
		void resize(unsigned int width, unsigned int height);
		void invalidate();

		framebuffer_spec& get_specs() { return m_spec; }

		void gen_buffer() override;
		void bind_buffer() override;
		void unbind_buffer() override;
		void destroy_buffer() override;
		unsigned int get_color_attachment_render_id(int index = 0);
		unsigned int get_depth_attachment_render_id();

	private:
		//unsigned int m_tex_id;
		//unsigned int m_depth_id;

		/*
			I like how Cherno did his
		*/
		framebuffer_spec m_spec;
		std::vector<framebuffer_texture_sepc> m_color_attachment_spec;
		framebuffer_texture_sepc m_depth_attachment_spec = framebuffer_texture_format::None;

		std::vector<unsigned int> m_color_attachments;
		unsigned int m_depth_attachment = 0;

	};

}
