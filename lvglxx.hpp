#pragma once

namespace lvc
{
	#include "lvgl/lvgl.h"
}

namespace lv
{
	/* // Broken Concepts in MSVC (or broken code ?)
	#include <concepts>
	template<typename T>		// Defining "numeric" Concept
	concept numeric = std::integral<T> or std::floating_point<T>;
	template<numeric T>
	*/
	template<typename T> struct Vector2
	{
		T x;
		T y;
	};
}

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
		int getX();
		int getY();
		lv::Vector2<int> getPos();

		int getWidth();
		int getHeight();
		lv::Vector2<int> getSize();

		int getAlign();
		BaseObj& getParent(BaseObj& parent);
		BaseObj& getChild(BaseObj& parent);

		// Setter Functions
		void setX(int x);
		void setY(int y);
		void setPos(int x, int y);
		void setPos(lv::Vector2<int> dimensions);

		void setWidth(int width);
		void setHeight(int height);
		void setSize(lv::Vector2<int> dimensions);
		void setSize(int width, int height);

		void setAlign(int alignment);
		void setParent(BaseObj& parent);

		// Constructors & Destructors
		BaseObj();
		BaseObj(BaseObj& parent);
	   ~BaseObj();
	};
}