#pragma once
#include "vec4.h"
#include <limits>
#include <cstddef>

namespace core {

	template<typename T>
	class mat4 {
	public:
		typedef vec<T> col_type;
		typedef vec<T> row_type;
		typedef mat4<4, 4, T, Q> type;
		typedef mat4<4, 4, T, Q> transpose_type;
		typedef T value_type;

	
	private:
		col_type value[4];

	public:

		mat4(mat4<T> const& m);

		mat4(
			T const& x0, T const& y0, T const& z0, T const& w0,
			T const& x1, T const& y1, T const& z1, T const& w1,
			T const& x2, T const& y2, T const& z2, T const& w2,
			T const& x3, T const& y3, T const& z3, T const& w3);
		
		mat(T s);

		mat4(
			col_type const& v0,
			col_type const& v1,
			col_type const& v2,
			col_type const& v3);

		template<
			typename X1, typename Y1, typename Z1, typename W1,
			typename X2, typename Y2, typename Z2, typename W2,
			typename X3, typename Y3, typename Z3, typename W3,
			typename X4, typename Y4, typename Z4, typename W4>
		constexpr mat4(
			X1 const& x1, Y1 const& y1, Z1 const& z1, W1 const& w1,
			X2 const& x2, Y2 const& y2, Z2 const& z2, W2 const& w2,
			X3 const& x3, Y3 const& y3, Z3 const& z3, W3 const& w3,
			X4 const& x4, Y4 const& y4, Z4 const& z4, W4 const& w4);

	};

}