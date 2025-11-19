
#include "math/mat4.h"
#include "math/mat3.h"
#include "math/mat2.h"
#include "math/quat.h"
#include "math/quat_utils.h"
#include "math/matrix_transform.h"

int main() {
	

	
	
	wizmcore::math::quat<double> q1 = wizmcore::math::quat<double>(1.0);
	wizmcore::math::vec3<double> v3(0);
	wizmcore::math::vec4<unsigned int> ex(0);
	wizmcore::math::mat2<unsigned int> m2 = wizmcore::math::mat2<unsigned int>(0);
	wizmcore::math::mat3<unsigned int> m3 = wizmcore::math::mat3<unsigned int>(0);
	wizmcore::math::mat4<unsigned int> m4 = wizmcore::math::mat4<unsigned int>(0);

	wizmcore::math::mat4<double> x = wizmcore::math::q_to_mat4(q1);
	wizmcore::math::from_rotation_matrix(q1, x);
	wizmcore::math::from_angle_axis(35.f, v3, q1);

	wizmcore::math::lookAt(v3, v3, v3);

	float q=1.f, w=2.f, e=3.f, r=4.f;
	wizmcore::math::mat4<float> m = wizmcore::math::perspective(q, w, e, r);

}