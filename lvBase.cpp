#include "lvBase.hpp"

/*******************************/
/*         lv::BaseObj         */
/*******************************/

// Returns Pointer to Internel lv_obj
lvc::lv_obj_t* lv::BaseObj::getLvObj()
{
	return lv_obj;
}

///////////////////////////////////////////////

int lv::BaseObj::getX()
{
	return lvc::lv_obj_get_x(lv_obj);
}

int lv::BaseObj::getY()
{
	return lvc::lv_obj_get_y(lv_obj);
}

lv::Vector2<int> lv::BaseObj::getPos()
{
	return {getX(), getY()};
}

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
	return {getWidth(), getHeight()};
}

lv::BaseObj& lv::BaseObj::getParent()
{
	return *selfParent;	 // will need to handle deleted parent as well
						 // and destruct all children when parent is destructed
	//return lvc::lv_obj_get_parent(lv_obj);
}

std::vector<lv::BaseObj&> lv::BaseObj::getChildren()
{	// WORK IN PROGRESS //
	std::vector<lv::BaseObj&> child_list;
	uint32_t child_count = lvc::lv_obj_get_child_cnt(lv_obj);
	return child_list;
}

///////////////////////////////////////////////

void lv::BaseObj::setX(int x)
{
	lvc::lv_obj_set_x(lv_obj, x);
}

void lv::BaseObj::setY(int y)
{
	lvc::lv_obj_set_y(lv_obj, y);
}

void lv::BaseObj::setPos(int x, int y)
{
	lvc::lv_obj_set_pos(lv_obj, x, y);
}

void lv::BaseObj::setPos(lv::Vector2<int> coords)
{
	lvc::lv_obj_set_pos(lv_obj, coords.x, coords.y);
}

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

// Setting Parent Object
void lv::BaseObj::setParent(lv::BaseObj& parent)
{
	selfParent = &parent;
	lvc::lv_obj_set_parent(lv_obj, parent.getLvObj());
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

////////////////////////////////////////////////