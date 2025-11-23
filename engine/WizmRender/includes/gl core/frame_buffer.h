#pragma once
#include <vector>
#include "core_buffer.h"


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


	class newframebuffer : public core_buffer_object {
	public:
		newframebuffer(int pwidth, int pheight);

		void bind_buffer() override;
		void unbind_buffer() override;
		void destroy_buffer() override;
		void resize(unsigned int new_width, unsigned int new_height);

		void initialize(unsigned int color_format = 0x8815, unsigned int depth_format = 0x1902, bool use_depth_buffer = true);
		unsigned int read_pixel(int x, int y);

	public:
		unsigned int color_texture = 0;
		unsigned int depth_buffer = 0;
		int width;
		int height;
	};
}
