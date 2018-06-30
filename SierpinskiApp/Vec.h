#pragma once
#include "glew.h"
#include "Utility.h"

namespace Vec
{

	struct Vec2
	{

		GLfloat x, y;

		// Constructors

		Vec2() : x(0), y(0)
		{
		}

		Vec2(GLfloat _x, GLfloat _y) : x(_x), y(_y)
		{
		}

		Vec2(const Vec2& _v)
		{
			x = _v.x;
			y = _v.y;
		}


		// indexing operator
		const GLfloat& operator[] (int _i)
		{
			return *(&x + _i);
		}

		// Arithmetic Operators

		Vec2 operator -() const
		{
			return Vec2(-x, -y);
		}

		Vec2 operator +( const Vec2& _vec) const
		{
			return Vec2(x + _vec.x, y + _vec.y);
		}

		Vec2 operator -( const Vec2& _vec) const
		{
			return Vec2(x - _vec.x, y - _vec.y);
		}

		Vec2 operator *(const GLfloat _scala) const
		{
			return Vec2(_scala * x, _scala*y);
		}

		Vec2 operator /(const GLfloat _d) const
		{
			if (std::fabs(_d) < Utility::DivideByZeroTolerance)
			{
				return Vec2();
			}

			GLfloat r = GLfloat(1.0f) / _d;
			
			return *this * r;
		}

		Vec2& operator += (const Vec2& _vec)
		{
			x += _vec.x;
			y += _vec.y;

			return *this;
		}

		Vec2& operator -= (const Vec2& _vec)
		{
			x -= _vec.x;
			y -= _vec.y;

			return *this;
		}

		Vec2& operator *=(const Vec2& _vec)
		{

			x *= _vec.x;
			y *= _vec.y;

			return *this;

		}

		Vec2& operator *=(const GLfloat _scalar)
		{

			x *= _scalar;
			y *= _scalar;

			return *this;

		}

		Vec2& operator /=(const GLfloat _d)
		{

			if (std::fabs(_d) < Utility::DivideByZeroTolerance)
			{
				return Vec2();
			}

			GLfloat r = GLfloat(1.0f) / _d;

			return *this *= r;

		}

		// Output

		friend std::ostream& operator << (std::ostream& os, const Vec2& v) {
			return os << "( " << v.x << ", " << v.y << " )";
		}

		friend std::istream& operator >> (std::istream& is, Vec2& v)
		{
			return is >> v.x >> v.y;
		}

		
		//  Conversion Operators
		

		operator const GLfloat* () const
		{
			return static_cast<const GLfloat*>(&x);
		}

		operator GLfloat* ()
		{
			return static_cast<GLfloat*>(&x);
		}


		// inline functions / methods

		inline GLfloat dot(const Vec2& _u, const Vec2& _v)
		{
			return _u.x * _v.x + _u.y * _v.y;
		}


		inline GLfloat length(const Vec2& _vec)
		{
			return std::sqrt(dot(_vec, _vec));
		}


		inline Vec2 normalize(const Vec2& _vec)
		{
			return _vec / length(_vec);
		}


	};

	struct Vec3
	{

		GLfloat x, y, z;

		// Constructors

		Vec3() : x(0), y(0), z(0)
		{
		}

		Vec3(GLfloat _x, GLfloat _y, GLfloat _z) : x(_x), y(_y), z(_z)
		{

		}

		Vec3(const Vec3& _v)
		{
			x = _v.x;
			y = _v.y;
			z = _v.z;
		}


		// indexing operator
		const GLfloat& operator[] (int _i)
		{
			return *(&x + _i);
		}

		// Arithmetic Operators

		Vec3 operator -() const
		{
			return Vec3(-x, -y, -z);
		}

		Vec3 operator +(const Vec3& _vec) const
		{
			return Vec3(x + _vec.x, y + _vec.y, z + _vec.z);
		}

		Vec3 operator -(const Vec3& _vec) const
		{
			return Vec3(x - _vec.x, y - _vec.y, z - _vec.z);
		}

		Vec3 operator *(const GLfloat _scala) const
		{
			return Vec3(_scala * x, _scala*y, _scala * z);
		}

		Vec3 operator /(const GLfloat _d) const
		{
			if (std::fabs(_d) < Utility::DivideByZeroTolerance)
			{
				return Vec3();
			}

			GLfloat r = GLfloat(1.0f) / _d;

			return *this * r;
		}

		Vec3& operator += (const Vec3& _vec)
		{
			x += _vec.x;
			y += _vec.y;
			z += _vec.z;
			return *this;
		}

		Vec3& operator -= (const Vec3& _vec)
		{
			x -= _vec.x;
			y -= _vec.y;
			z -= _vec.z;
			return *this;
		}

		Vec3& operator *=(const Vec3& _vec)
		{

			x *= _vec.x;
			y *= _vec.y;
			z *= _vec.z;
			return *this;

		}

		Vec3& operator *=(const GLfloat _scalar)
		{

			x += _scalar;
			y += _scalar;
			z += _scalar;
			return *this;

		}

		Vec3& operator /=(const GLfloat _d)
		{

			if (std::fabs(_d) < Utility::DivideByZeroTolerance)
			{
				return Vec3();
			}

			GLfloat r = GLfloat(1.0f) / _d;

			return *this *= r;

		}

		// Output

		friend std::ostream& operator << (std::ostream& os, const Vec3& v) 
		{
			return os << "( " << v.x << ", " << v.y << ", " << v.z << " )";
		}

		friend std::istream& operator >> (std::istream& is, Vec3& v)
		{
			return is >> v.x >> v.y >> v.z;
		}


		//  Conversion Operators


		operator const GLfloat* () const
		{
			return static_cast<const GLfloat*>(&x);
		}

		operator GLfloat* ()
		{
			return static_cast<GLfloat*>(&x);
		}


		// inline functions / methods

		inline GLfloat dot(const Vec3& _u, const Vec3& _v)
		{
			return _u.x * _v.x + _u.y * _v.y + _u.z * _v.z;
		}


		inline GLfloat length(const Vec3& _vec)
		{
			return std::sqrt(dot(_vec, _vec));
		}


		inline Vec3 normalize(const Vec3& _vec)
		{
			return _vec / length(_vec);
		}

		inline Vec3 cross(const Vec3& _u, const Vec3& _v)
		{
			return Vec3(_u.y * _v.z - _u.z * _v.y,
						_u.z * _v.x - _u.x * _v.z,
						_u.x * _v.y - _u.y * _v.x);
		}


	};

	struct Vec4
	{

		GLfloat x, y, z, w;

		// Constructors

		Vec4() : x(0), y(0), z(0), w(0)
		{
		}

		Vec4(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w) : x(_x), y(_y), z(_z), w(_w)
		{

		}

		Vec4(const Vec4& _v)
		{
			x = _v.x;
			y = _v.y;
			z = _v.z;
			w = _v.w;
		}

		Vec4(const Vec3& _v)
		{
			x = _v.x;
			y = _v.y;
			z = _v.z;
			w = 1.0f;
		}


		// indexing operator
		const GLfloat& operator[] (int _i)
		{
			return *(&x + _i);
		}

		// Arithmetic Operators

		Vec4 operator -() const
		{
			return Vec4(-x, -y, -z, -w);
		}

		Vec4 operator +(const Vec4& _vec) const
		{
			return Vec4(x + _vec.x, y + _vec.y, z + _vec.z, w + _vec.w);
		}

		Vec4 operator -(const Vec4& _vec) const
		{
			return Vec4(x - _vec.x, y - _vec.y, z - _vec.z, w - _vec.w);
		}

		Vec4 operator *(const GLfloat _scala) const
		{
			return Vec4(_scala * x, _scala*y, _scala * z, _scala * w);
		}

		Vec4 operator /(const GLfloat _d) const
		{
			if (std::fabs(_d) < Utility::DivideByZeroTolerance)
			{
				return Vec4();
			}

			GLfloat r = GLfloat(1.0f) / _d;

			return *this * r;
		}

		Vec4& operator += (const Vec4& _vec)
		{
			x += _vec.x;
			y += _vec.y;
			z += _vec.z;
			w += _vec.w;
			return *this;
		}

		Vec4& operator -= (const Vec4& _vec)
		{
			x -= _vec.x;
			y -= _vec.y;
			z -= _vec.z;
			w -= _vec.w;
			return *this;
		}

		Vec4& operator *=(const Vec4& _vec)
		{

			x *= _vec.x;
			y *= _vec.y;
			z *= _vec.z;
			w *= _vec.w;
			return *this;

		}

		Vec4& operator *=(const GLfloat _scalar)
		{

			x *= _scalar;
			y *= _scalar;
			z *= _scalar;
			w *= _scalar;
			return *this;

		}

		Vec4& operator /=(const GLfloat _d)
		{

			if (std::fabs(_d) < Utility::DivideByZeroTolerance)
			{
				return Vec4();
			}

			GLfloat r = GLfloat(1.0f) / _d;

			return *this *= r;

		}

		// Output

		friend std::ostream& operator << (std::ostream& os, const Vec4& v) {
			return os << "( " << v.x << ", " << v.y
				<< ", " << v.z << ", " << v.w << " )";
		}

		friend std::istream& operator >> (std::istream& is, Vec4& v)
		{
			return is >> v.x >> v.y >> v.z >> v.w;
		}


		//  Conversion Operators


		operator const GLfloat* () const
		{
			return static_cast<const GLfloat*>(&x);
		}

		operator GLfloat* ()
		{
			return static_cast<GLfloat*>(&x);
		}


		// inline functions / methods

		inline GLfloat dot(const Vec4& _u, const Vec4& _v)
		{
			return _u.x * _v.x + _u.y * _v.y + _u.z * _v.z + _u.w * _v.w;
		}


		inline GLfloat length(const Vec4& _vec)
		{
			return std::sqrt(dot(_vec, _vec));
		}


		inline Vec4 normalize(const Vec4& _vec)
		{
			return _vec / length(_vec);
		}

		inline Vec3 cross(const Vec4& _u, const Vec4& _v)
		{
			return Vec3(_u.y * _v.z - _u.z * _v.y,
				_u.z * _v.x - _u.x * _v.z,
				_u.x * _v.y - _u.y * _v.x);
		}


	};

}