namespace lvc
{
	extern "C"
	{
		#include "lvgl/lvgl.h"
	}
}

namespace lv
{
	class BaseObj
	{
	private:
		lvc::lv_obj_t* lv_obj;
	
	public:
		// Getter Functions
		lvc::lv_obj_t* getLvObj();

		// Setter Functions
		void setWidth(int width);
		void setHeight(int height);
		void setSize(int width, int height);

		// Constructors & Destructors
		BaseObj();
		~BaseObj();
		BaseObj(lvc::lv_obj_t* parent);
	};
}