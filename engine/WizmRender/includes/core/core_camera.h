#pragma once
#include "math/vec_types.h"

namespace wizmrenderer {


	enum e_camera_type {
		eCameraType_2D,
		eCameraType_3D,
	};



	class core_camera {
		public:
		virtual void set_model_view_matrix() = 0;
		virtual void set_projection_matrix() = 0;
		virtual e_camera_type get_camera_type() = 0;
	};
}
