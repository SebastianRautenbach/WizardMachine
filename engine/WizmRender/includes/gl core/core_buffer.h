#pragma once


namespace wizmrenderer {
	class core_buffer_object {
	public:
		virtual void gen_buffer() {};
		virtual void bind_buffer() {};
		virtual void unbind_buffer() {};
		virtual void destroy_buffer() {};

	public:
		unsigned int buffer_id = 0;
	};
}