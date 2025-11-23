#pragma once
#include "system/updateable.h"
#include "wwindow.h"


namespace wizmplatform {
	class wplatform : public wizmcore::system::updateable {

	public:
		wplatform(wizmplatform::wwindow window);
		~wplatform();


		void pre_update(float delta_time) override;
		void update(float delta_time) override;
		void post_update(float delta_time) override;

	private:
		wizmplatform::wwindow m_window;
	};
}
