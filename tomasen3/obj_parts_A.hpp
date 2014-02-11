#ifndef INCLUDED_OBJ_PARTS_A_HPP
#define INCLUDED_OBJ_PARTS_A_HPP

#include "common.hpp"
#include "obj_parts.hpp"


class EngineA : public PartsA{
private:

public:
	/*コンストラクタ*/
	EngineA();
	/*行動関数（各兵装固有処理）*/
	void action();
};

class CockpitA : public PartsA{
private:

public:
	/*コンストラクタ*/
	CockpitA();
	/*行動関数（各兵装固有処理）*/
	void action();
};

class MachineGunA : public PartsA{
private:
	int stopShot;
public:
	/*コンストラクタ*/
	MachineGunA();
	/*行動関数（各兵装固有処理）*/
	void action();
};

#endif//INCLUDED_OBJ_PARTS_A_HPP