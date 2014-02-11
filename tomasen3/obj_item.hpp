#ifndef INCLUDED_OBJ_ITEM_HPP
#define INCLUDED_OBJ_ITEM_HPP

#include "common.hpp"
#include "object.hpp"
#include "obj_parts.hpp"

class Item : public Object{
	/*変動パラメータ*/
	Parts *parts;		//パーツ名
	
public:
	void update(Object obj);		//更新関数
};



#endif//INCLUDED_OBJ_ITEM_HPP