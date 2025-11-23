#include "wplatform.h"


int main() {
	
	wizmplatform::wwindow m_window("test", 900, 900);
	wizmplatform::wplatform platform(m_window);


	while (true) {
		platform.pre_update(0.0);
		platform.update(0.0);
		platform.post_update(0.0);
	}


}