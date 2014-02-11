#ifndef INCLUDED_OBJ_PRINT_HPP
#define INCLUDED_OBJ_PRINT_HPP

#include <vector>		//vector
#include <memory>		//shared_ptr

// std::tr1:: �� std:: �Ə�����悤��
namespace std {
	using namespace tr1; 
}


#include "common.hpp"
#include "object.hpp"


class Print : public Object{
protected:
	/*�ϓ��p�����[�^*/
	int value;				//���ݒl
	int printValue;			//�\���l

	/*�Œ�p�����[�^*/
	int maxValue;			//�ő�l
	int startValue;			//�����l

	int maxImageX;			//�o�[�Q�摜x���W
	int maxImageY;			//�o�[�Q�摜y���W
	int maxImageW;			//�o�[�Q�摜��
	int maxImageH;			//�o�[�Q�摜��
	int underImageX;		//���n�摜x���W
	int underImageY;		//���n�摜y���W
	int underImageW;		//���n�摜��
	int underImageH;		//���n�摜��
	int overImageX;			//��g�摜x���W
	int overImageY;			//��g�摜y���W
	int overImageW;			//��g�摜��
	int overImageH;			//��g�摜��

public:
	/*�R���X�g���N�^*/
	Print();
	/*setter�֐�*/
	void setValue(int value){ Print::value = value; }
	void setPrintValue(int printValue){ Print::printValue = printValue; }
	void setMaxValue(int maxValue){ Print::maxValue = maxValue; }
	void setStartValue(int startValue){ Print::startValue = startValue; }
	/*getter�֐�*/
	int getValue(){ return value; }
	int getPrintValue(){ return printValue; }
	int getMaxValue(){ return maxValue; }
	int getStartValue(){ return startValue; }
	int getMaxImageX(){ return maxImageX; }
	int getMaxImageY(){ return maxImageY; }
	int getMaxImageW(){ return maxImageW; }
	int getMaxImageH(){ return maxImageH; }
	int getUnderImageX(){ return underImageX + animeCnt * imageW; }
	int getUnderImageY(){ return underImageY; }
	int getUnderImageW(){ return underImageW; }
	int getUnderImageH(){ return underImageH; }
	int getOverImageX(){ return overImageX + animeCnt * imageW; }
	int getOverImageY(){ return overImageY; }
	int getOverImageW(){ return overImageW; }
	int getOverImageH(){ return overImageH; }

	/*�X�V�֐�*/
	virtual void update(Object obj) = 0;

};

class Bar : public Print{
public:
	/*�X�V�֐�*/
	void update(Object obj);
};
/*�O���[�o�����\�[�X�錾*/
typedef weak_ptr< Bar > BarWptr;		//�o�[��weak�|�C���^
typedef shared_ptr< Bar > BarSptr;		//�o�[��shared�|�C���^
typedef vector< BarSptr > BarVsptr;		//�o�[��shared�|�C���^�̔z��
extern BarVsptr barList;				//�o�[���X�g
BarWptr barFactory(BarSptr barList);	//�o�[�t�@�N�g���֐�

class Label : public Print{
public:
	/*�X�V�֐�*/
	void update(Object obj);
};
/*�O���[�o�����\�[�X�錾*/
typedef weak_ptr< Label > LabelWptr;			//���x����weak�|�C���^
typedef shared_ptr< Label > LabelSptr;			//���x����shared�|�C���^
typedef vector< LabelSptr > LabelVsptr;			//���x����shared�|�C���^�̔z��
extern LabelVsptr labelList;					//���x�����X�g
LabelWptr labelFactory(LabelSptr labelList);	//���x���t�@�N�g���֐�


class HpBar : public Bar{
public:
	/*�R���X�g���N�^*/
	HpBar();
};

class EnergyBar : public Bar{
public:
	/*�R���X�g���N�^*/
	EnergyBar();
};

class ManBar : public Bar{
public:
	/*�R���X�g���N�^*/
	ManBar();
};

class FireBar : public Bar{
public:
	/*�R���X�g���N�^*/
	FireBar();
};

class GoldLabel : public Label{
public:
	/*�R���X�g���N�^*/
	GoldLabel();
};

class ScoreLabel : public Label{
public:
	/*�R���X�g���N�^*/
	ScoreLabel();
};

#endif//INCLUDED_OBJ_PRINT_HPP