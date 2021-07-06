#include "lvglxx.hpp"

/*******************************/
/*         lv::BaseObj         */
/*******************************/

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

// Setting Both Width & Height of BaseObj
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