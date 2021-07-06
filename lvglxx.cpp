#include "lvglxx.hpp"

/*******************************/
/*         lv::BaseObj         */
/*******************************/

// Returns Pointer to Internel lv_obj
lvc::lv_obj_t* lv::BaseObj::getLvObj()
{
	return lv_obj;
}

///////////////////////////////////////////////

// Getting Width of BaseObj
int lv::BaseObj::getWidth()
{
	return lvc::lv_obj_get_width(lv_obj);
}

// Getting Height of BaseObj
int lv::BaseObj::getHeight()
{
	return lvc::lv_obj_get_height(lv_obj);
}

// Getting Both Width & Height of BaseObj
lv::Vector2<int> lv::BaseObj::getSize()
{
	return {lvc::lv_obj_get_width(lv_obj),		//X
			lvc::lv_obj_get_height(lv_obj)};	//Y
}

///////////////////////////////////////////////

// Setting Width of BaseObj
void lv::BaseObj::setWidth(int width)
{
	lvc::lv_obj_set_width(lv_obj, width);
}

// Setting Hieght of BaseObj
void lv::BaseObj::setHeight(int height)
{
	lvc::lv_obj_set_height(lv_obj, height);
}

// Setting Both Width & Height of BaseObj (from Vector2)
void lv::BaseObj::setSize(lv::Vector2<int> dimensions)
{
	lvc::lv_obj_set_size(lv_obj, dimensions.x, dimensions.y);
}

// Setting Both Width & Height of BaseObj (from x and y)
void lv::BaseObj::setSize(int width, int height)
{
	lvc::lv_obj_set_size(lv_obj, width, height);
}

////////////////////////////////////////////////

// Constructor without aguments creates a Window
lv::BaseObj::BaseObj()
{
	lv_obj = lvc::lv_obj_create(NULL);
}

// BaseObj Constructor with Aguments adds BaseObj to Parent
lv::BaseObj::BaseObj(lv::BaseObj& parent)
{
	lv_obj = lvc::lv_obj_create(parent.getLvObj());
}

// BaseObj Destructor
lv::BaseObj::~BaseObj()
{
	lvc::lv_obj_del(lv_obj);
}