#ifndef INCLUDED_COMMON_HPP
#define INCLUDED_COMMON_HPP

#pragma comment(lib, "winmm.lib") //�^�C�}

#include <windows.h>
#include <string>
#include <sstream>
#include <cassert>

// std:: ���ȗ��ł���悤��
using namespace std;

/*****************�萔*****************/
const int SCREEN_WIDTH = 800;		// �E�B���h�E�̕�
const int SCREEN_HEIGHT = 600;		// �E�B���h�E�̍���
const int SCREEN_INDENT = 200;		// ���E�]��
const int tipSize = 16;				//�`�b�v�̃T�C�Y
extern double PI;

/*****************���W�\����*****************/
struct Vec2{
	double x;
	double y;
	Vec2();
	Vec2(double, double);
    const Vec2 operator+(const Vec2&) const;
    const Vec2 operator-(const Vec2&) const;
	Vec2& operator+=(const Vec2&);
    Vec2& operator-=(const Vec2&);
    Vec2& operator+(const int);
    Vec2& operator-(const int);
};


//�ҋ@�֐�
void await(DWORD);

//��ʊO����֐�
bool isIn(int left, int right, int top, int bottom, int x, int y);

//�����^���當����^
template<typename T> string valToStr(T val)
{
	ostringstream temp; //�����w�肵�₷��������^
	temp << val;
	return temp.str();
}

//���b�Z�[�W�{�N�X�֐�
template<typename T> void mb(T val){
	MessageBox(NULL,valToStr(val).c_str(),"mb",MB_OK);
	return;
}
//���b�Z�[�W�{�N�X�֐�
template<typename T, typename T2> void mb(T val, T2 val2){
	MessageBox(NULL,valToStr(val).c_str(),valToStr(val2).c_str(),MB_OK);
	return;
}

//���������֐�
int makeRand(int upper);
int makeRand(int center, int difference);
double makeRand(double center, int difference);

//�m���m�F�֐�
bool perCheck(int percent);

#endif//INCLUDED_COMMON_HPP