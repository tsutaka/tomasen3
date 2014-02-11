#ifndef INCLUDED_EVENT_HPP
#define INCLUDED_EVENT_HPP


#include <vector>		//vector
#include <memory>		//shared_ptr

// std::tr1:: �� std:: �Ə�����悤��
namespace std {
	using namespace tr1; 
}

#include "common.hpp"


class Event {
protected:
	/*�ϓ��p�����[�^*/
	Vec2 pos;				//�ʒu
	double dis;				//�ړ���
	double dir;				//�p�x
	long frameCnt;			//������̌o�߃t���[����
	string name;			//����
	int phase;				//���i�K
	int next;				//�C�x���g�I���t���O
public:
	/*getter�֐�*/
	Vec2 getPos(){ return pos; }
	double getDis(){ return dis; }
	double getDir(){ return dir; }
	long getFrameCnt(){ return frameCnt; }
	string getName(){ return name; }
	int getPhase(){ return phase; }
	int nextEvent(){ return next; }

	/*setter�֐�*/
	void setPos(Vec2 pos){ Event::pos = pos; }
	void setDis(double dis){ Event::dis = dis; }
	void setDir(double dir){ Event::dir = dir; }
	void setFrameCnt(int frameCnt){ Event::frameCnt = frameCnt; }
	void setName(string name){ Event::name = name; }
	void setPhase(int phase){ Event::phase = phase; }

	/*�R���X�g���N�^*/
	Event();
	/*�X�V�֐�*/
	void update();
	/*�A�N�V�����֐��i�ʁj*/
	virtual void action() = 0;
};

/*�O���[�o�����\�[�X�錾*/
typedef weak_ptr< Event > EventWptr;		//�C�x���g��weak�|�C���^
typedef shared_ptr< Event > EventSptr;		//�C�x���g��shared�|�C���^
typedef vector< EventSptr > EventVsptr;		//�C�x���g��shared�|�C���^�̔z��
extern EventVsptr eventList;				//�C�x���g���X�g
void eventFactory(EventSptr event);			//�C�x���g�t�@�N�g���[�֐�



class GameTitle : public Event{
public:
	/*�A�N�V�����֐��i�ʁj*/
	void action();
};

class Stage1 : public Event{
public:
	/*�R���X�g���N�^*/
	Stage1();
	/*�A�N�V�����֐��i�ʁj*/
	void action();
};

class Stage2 : public Event{
public:
	/*�R���X�g���N�^*/
	Stage2();
	/*�A�N�V�����֐��i�ʁj*/
	void action();
};
class Stage3 : public Event{
public:
	/*�R���X�g���N�^*/
	Stage3();
	/*�A�N�V�����֐��i�ʁj*/
	void action();
};
class Stage4 : public Event{
public:
	/*�R���X�g���N�^*/
	Stage4();
	/*�A�N�V�����֐��i�ʁj*/
	void action();
};
class Stage5 : public Event{
public:
	/*�R���X�g���N�^*/
	Stage5();
	/*�A�N�V�����֐��i�ʁj*/
	void action();
};
class GameOver : public Event{
public:
	/*�A�N�V�����֐��i�ʁj*/
	void action();
};

class GameClear : public Event{
public:
	/*�A�N�V�����֐��i�ʁj*/
	void action();
};


#endif//INCLUDED_EVENT_HPP