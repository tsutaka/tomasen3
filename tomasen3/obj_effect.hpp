#ifndef INCLUDED_OBJ_EFFECT_HPP
#define INCLUDED_OBJ_EFFECT_HPP

#include <vector>		//vector
#include <memory>		//shared_ptr

// std::tr1:: を std:: と書けるように
namespace std {
	using namespace tr1; 
}

#include "common.hpp"
#include "object.hpp"

class Effect : public Object{
protected:
	int timeOfLife;		//生存フレーム
	Vec2 targetPos;		//移動目的座標

public:
	/*コンストラクタ*/
	Effect();
	/*getter関数*/
	int getTimeOfLife(){return timeOfLife;}
	Vec2 getTargetPos(){return targetPos;}
	/*setter関数*/
	void setTimeOfLife(int timeOfLife){Effect::timeOfLife = timeOfLife;}
	void setTargetPos(Vec2 targetPos){Effect::targetPos = targetPos;}
	/*更新関数*/
	void update(Object obj);
};
/*グローバルリソース宣言*/
typedef weak_ptr< Effect > EffectWptr;		//エフェクトのweakポインタ
typedef shared_ptr< Effect > EffectSptr;	//エフェクトのsharedポインタ
typedef vector< EffectSptr > EffectVsptr;	//エフェクトのsharedポインタの配列
extern EffectVsptr effectList;				//エフェクトリスト
void effectFactory(EffectSptr effectList);	//エフェクトファクトリ関数
void effectFactory(EffectSptr effectList, Vec2 pos, Vec2 targetPos);	//エフェクトファクトリ関数

class Explosion : public Effect {
public:
	Explosion();
};
class TitleTo : public Effect {
public:
	TitleTo();
};
class TitleMa : public Effect {
public:
	TitleMa();
};
class TitleSe : public Effect {
public:
	TitleSe();
};
class TitleNi : public Effect {
public:
	TitleNi();
};

class DarkR : public Effect {
public:
	DarkR();
};
class LightR : public Effect {
public:
	LightR();
};
class DarkY : public Effect {
public:
	DarkY();
};
class LightY : public Effect {
public:
	LightY();
};
class DarkG : public Effect {
public:
	DarkG();
};
class LightG : public Effect {
public:
	LightG();
};
class DarkB : public Effect {
public:
	DarkB();
};
class LightB : public Effect {
public:
	LightB();
};
class PushSpace : public Effect {
public:
	PushSpace();
};

#endif//INCLUDED_OBJ_EFFECT_HPP