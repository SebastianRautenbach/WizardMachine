#pragma once

namespace wizmcore {
	namespace system {
		class updateable {
		public:
			virtual void pre_update(float delta_time) = 0;
			virtual void update(float delta_time) = 0;
			virtual void post_update(float delta_time) = 0;
			virtual ~updateable() = default;
		};
	}
}
