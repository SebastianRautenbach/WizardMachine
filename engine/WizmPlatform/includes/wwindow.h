#pragma once
#include <memory>
#include "window_context.h"


namespace wizmplatform   {
		
	class wwindow : public window_context {
	public:

		int GetWidth() const override;
		int GetHeight() const override;
		bool ShouldClose() const override;
		void* GetNativeHandle() override;
		
		
		wwindow(const char* name, double w, double h);	
		~wwindow();
				

	private:
		void* m_window;
		double m_screen_width =900., m_screen_height=900.;
	};
}
