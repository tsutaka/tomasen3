#ifndef INCLUDED_OBJ_ITEM_HPP
#define INCLUDED_OBJ_ITEM_HPP

#include "common.hpp"
#include "object.hpp"
#include "obj_parts.hpp"

class Item : public Object{
	/*�ϓ��p�����[�^*/
	Parts *parts;		//�p�[�c��
	
public:
	void update(Object obj);		//�X�V�֐�
};



#endif//INCLUDED_OBJ_ITEM_HPP