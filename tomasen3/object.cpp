#include "object.hpp"

void Object::update(Object obj){
}

void Object::damageHp(int damage){
	hp -= damage;
	if(hp < 0) hp = 0;
}