#pragma once

#include "lvdef.hpp"

namespace lv
{
	class BaseObj
	{
	private:
		lvc::lv_obj_t* lv_obj;
        BaseObj* selfParent;
	
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
		BaseObj& getParent();
		BaseObj& getChild();

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