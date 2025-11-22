
#include "wwindow.h"
#include "timer.h"




namespace wizmplatform {
	class wplatform {

	public:
		wplatform();
		~wplatform();

	private:
		wizmplatform::wwindow m_window;
		wizmplatform::core_timer m_timer;

	};
}





int main() {

	wizmplatform::wwindow example("", 900, 900);
	wizmplatform::core_timer timer;


	while (true)
	{
		timer.update_delta_time();
		example.pre_update(timer.get_delta_time());
		example.update(timer.get_delta_time());
		example.post_update(timer.get_delta_time());
	}
}