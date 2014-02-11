#ifndef INCLUDED_OBJ_PARTS_A_HPP
#define INCLUDED_OBJ_PARTS_A_HPP

#include "common.hpp"
#include "obj_parts.hpp"


class EngineA : public PartsA{
private:

public:
	/*�R���X�g���N�^*/
	EngineA();
	/*�s���֐��i�e�����ŗL�����j*/
	void action();
};

class CockpitA : public PartsA{
private:

public:
	/*�R���X�g���N�^*/
	CockpitA();
	/*�s���֐��i�e�����ŗL�����j*/
	void action();
};

class MachineGunA : public PartsA{
private:
	int stopShot;
public:
	/*�R���X�g���N�^*/
	MachineGunA();
	/*�s���֐��i�e�����ŗL�����j*/
	void action();
};

#endif//INCLUDED_OBJ_PARTS_A_HPP