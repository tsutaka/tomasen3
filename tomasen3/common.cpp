//common.cpp
//�S�v���O�������ʂ̒萔���͊֐�

#include <windows.h>

#include "common.hpp"


/*int�ȊO�̒萔*/
double PI = 3.1415926535;

/*���W�\����*/
Vec2::Vec2(){
	x = 0.0;
	y = 0.0;
}
Vec2::Vec2(double vecx, double vecy){
	x = vecx;
	y = vecy;
}
Vec2& Vec2::operator+=(const Vec2& pos) {
    this->x += pos.x;
    this->y += pos.y;
    return *this;
}
Vec2& Vec2::operator-=(const Vec2& pos) {
    this->x -= pos.x;
    this->y -= pos.y;
    return *this;
}
const Vec2 Vec2::operator+(const Vec2& pos) const {
    Vec2 result(*this);
    result += pos;
    return result;
}
Vec2& Vec2::operator+(const int val) {
    this->x += val;
    this->y += val;
    return *this;
}
const Vec2 Vec2::operator-(const Vec2& pos) const {
    Vec2 result(*this);
    result -= pos;
    return result;
}
Vec2& Vec2::operator-(const int val) {
    this->x -= val;
    this->y -= val;
    return *this;
}

//�ҋ@�֐�
void await(DWORD ms)
{
	static DWORD prevtime = 0;
	DWORD nowtime;
	LONG sleeptime;
	nowtime = timeGetTime();
	sleeptime = ms - (nowtime-prevtime);
	if ( sleeptime < 0 ) sleeptime = 0;
	Sleep(sleeptime);
	prevtime = timeGetTime();
	
}

//��ʊO����֐�
bool isIn(int top, int bottom, int left, int right, int x, int y){
	if(y < top){			//��[�z������
		return false;
	}
	else if(y >= bottom){	//���[�z������
		return false;
	}
	else if(x < left){		//���[�z������
		return false;
	}
	else if(x >= right){	//�E�[�z������
		return false;
	}
	return true;
}

//���������֐�
int makeRand(int upper){
	return rand() % upper;
}
//���������֐�
int makeRand(int center, int difference){
	return center + rand() % ((difference * 2) + 1) - difference;
}
//���������֐�
double makeRand(double center, int difference){
	return center + rand() % ((difference * 2) + 1) - difference;
}
//�m���m�F�֐�
bool perCheck(int percent){
	return  rand() % 100 < percent;
}