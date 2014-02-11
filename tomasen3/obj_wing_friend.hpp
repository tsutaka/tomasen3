#ifndef INCLUDED_OBJ_WING_FRIEND_HPP
#define INCLUDED_OBJ_WING_FRIEND_HPP


#include "common.hpp"
#include "object.hpp"
#include "event.hpp"


#include "obj_parts_A.hpp"
#include "obj_parts_B.hpp"
#include "obj_wing.hpp"


class KosenWing : public Friend{
public:
	/*�ϓ��p�����[�^*/
	string name;	//���O�@���������̓R���X�g���N�^
	double maxMove;	//�ő�ړ��ʁ@���������̓R���X�g���N�^
	double subMove;	//�����ړ��ʔ{���@���������̓R���X�g���N�^


public:

	/*���\�[�X���X�g*/
	PartsBWptr core;								//���@�̃R�A�p�[�c

	/*�R���X�g���N�^*/
	KosenWing();


	/*�X�V�֐�*/
	void update(Object obj);



};



#endif//INCLUDED_OBJ_WING_FRIEND_HPP