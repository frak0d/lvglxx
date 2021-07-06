#pragma once

namespace lvc
{
	extern "C"
	{
		#include "lvgl/lvgl.h"
	}
}

#include <concepts>

template<typename T>		// Defining "numeric" Concept
concept numeric = std::integral<T> or std::floating_point<T>;

template<numeric T>
struct Vector2
{
	T x;
	T y;
};

namespace lv
{
	class BaseObj
	{
	private:
		lvc::lv_obj_t* lv_obj;
	
	public:
		// Special Functions
		lvc::lv_obj_t* getLvObj();

		// Getter Functions
		int getWidth();
		int getHeight();
		Vector2<int> getSize();

		// Setter Functions
		void setWidth(int width);
		void setHeight(int height);
		void setSize(Vector2<int> x_and_y);
		void setSize(int width, int height);

		// Constructors & Destructors
		BaseObj();
		BaseObj(lv::BaseObj& parent);
	   ~BaseObj();
	};
}