#pragma once


namespace wizmplatform {

	class window_context {

	public:
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual bool ShouldClose() const = 0;

		virtual void* GetNativeHandle() = 0;
	};

}
