#include <cmath>

#include "event.hpp"

#include "localcommon.hpp"
#include "obj_effect.hpp"
#include "obj_wing_enemy.hpp"

/*�O���[�o�����\�[�X��`*/
EventVsptr eventList;		//�C�x���g���X�g
void eventFactory(EventSptr event){
		eventList.push_back( event );			//���X�g�ɃI�u�W�F�N�g�ǉ�
}

/*�R���X�g���N�^*/
Event::Event(){
	pos = Vec2(0.0, 0.0);	//���݈ʒu
	dis = 0.0;				//�ړ���
	dir = 0.0;				//�p�x
	frameCnt = 0;			//�t���[���J�E���g
	phase = 0;				//�t�F�[�Y
	next = 0;			//�C�x���g�I���t���O
}

/*�X�V�֐�*/
void Event::update(){
	/*�J�E���g�A�b�v*/
	frameCnt++;
	/*�C�x���g�̈ʒu���X�V*/
	pos.x += cos(dir) * dis;
	pos.y += sin(dir) * dis;
}


/*�A�N�V�����֐��i�ʁj*/
void GameTitle::action(){

	/*���͎�t*/
	if(GetAsyncKeyState(VK_SPACE) && phase >= 1) {//SPACE
		next = 1;	//�I������t���O
		effectList.clear();
	}
	/*�^�C���X�P�W���[��*/
	if(phase == 0){
		phase++;
		effectFactory( EffectSptr(new DarkR()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new DarkY()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new DarkG()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new DarkB()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new LightB()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new LightG()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new LightY()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new LightR()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new TitleTo()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new TitleMa()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new TitleSe()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new TitleNi()) );		//���X�g�ɃI�u�W�F�N�g�ǉ�
	}
	else if(phase == 1 && frameCnt == 100){
		phase++;
		effectFactory( EffectSptr(new PushSpace()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�
		effectFactory( EffectSptr(new Explosion()) );	//���X�g�ɃI�u�W�F�N�g�ǉ�

	}
}

/*�R���X�g���N�^*/
Stage1::Stage1(){
	pos = Vec2(SCREEN_WIDTH-SCREEN_INDENT - 50, -wideArea);	//�����ʒu
}
/*�A�N�V�����֐��i�ʁj*/
void Stage1::action(){
	/*STAGE1�̓G�L��������*/


	/*test*/
	if(phase == 0 && frameCnt == 20 && frameCnt % 10 == 0 ){
		enemyFactory(EnemySptr( new EnemyJ ), 
			Vec2(SCREEN_WIDTH / 2, 100), 0);
	}

	/*1-1*/
	if(phase == 0 && frameCnt < 200 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(makeRand(pos.x, 7), pos.y));			//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 0 && frameCnt > 250){
		phase++;
	}
	/*1-2*/
	if(phase == 1 && frameCnt < 450 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_INDENT - 100, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(1);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 1 && frameCnt > 600){
		phase++;
	}
	/*1-3*/
	if(phase == 2 && frameCnt > 650){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyB()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 3 && frameCnt < 700 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_INDENT + 80, SCREEN_HEIGHT + 50));	//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(2);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 3 && frameCnt < 700 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH-SCREEN_INDENT-80, SCREEN_HEIGHT + 50));	//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(3);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 3 && frameCnt > 900){
		phase++;
	}
	/*1-4*/
	if(phase == 4){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyB()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_INDENT +50, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(1);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 5 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2,  -50));	//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(4);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 5 && frameCnt > 1100){
		phase++;
	}
	/*1-5*/
	if(phase == 6){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyC()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}
	if (phase ==7 && frameCnt > 1500){
		next = 2;
	}

}
/*�A�N�V�����֐��i�ʁj*/

Stage2::Stage2(){
	pos = Vec2(SCREEN_WIDTH-SCREEN_INDENT - 50, -wideArea);	//�����ʒu
}
/*�A�N�V�����֐��i�ʁj*/
void Stage2::action(){
	/*STAGE1�̓G�L��������*/


	/*test*/
	if(phase == 0 && frameCnt == 20 && frameCnt % 10 == 0 ){
		enemyList.push_back( EnemySptr(new EnemyJ()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, 50));			//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}

	/*2-1*/
	if(phase == 0 && frameCnt < 200 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyD()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(makeRand(pos.x, 7), pos.y));			//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 0 && frameCnt > 250){
		phase++;
	}
	/*2-2*/
	if(phase == 1 && frameCnt < 450 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyE()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_INDENT - 100, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(1);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 1 && frameCnt > 600){
		phase++;
	}
	/*2-3*/
	if(phase == 2){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyF()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 3 && frameCnt > 900){
		phase++;
	}
	if (phase == 4 && frameCnt > 1200){
		next = 3;
	}
}
/*�A�N�V�����֐��i�ʁj*/
Stage3::Stage3(){
	pos = Vec2(SCREEN_WIDTH-SCREEN_INDENT - 50, -wideArea);	//�����ʒu
}
/*�A�N�V�����֐��i�ʁj*/
void Stage3::action(){
	/*STAGE1�̓G�L��������*/


	/*test*/
	if(phase == 0 && frameCnt == 20 && frameCnt % 10 == 0 ){
		enemyList.push_back( EnemySptr(new EnemyJ()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, 50));			//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}

	/*3-1*/
	if(phase == 0 && frameCnt < 200 && frameCnt == 0){
		enemyList.push_back( EnemySptr(new EnemyC()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(makeRand(pos.x, 7), pos.y));			//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 0 && frameCnt > 250){
		phase++;
	}
	/*3-2*/
	if(phase == 1 && frameCnt < 450 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyH()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_INDENT - 100, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(1);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 1 && frameCnt > 600){
		phase++;
	}
	/*3-3*/
	if(phase == 2){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyI()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 3 && frameCnt > 900){
		phase++;
	}
	if (phase == 4 && frameCnt > 1200){
		next = 4;
	}
}
/*�A�N�V�����֐��i�ʁj*/
Stage4::Stage4(){
	pos = Vec2(SCREEN_WIDTH-SCREEN_INDENT - 50, -wideArea);	//�����ʒu
}
/*�A�N�V�����֐��i�ʁj*/
void Stage4::action(){
	/*STAGE1�̓G�L��������*/


	/*test*/
	if(phase == 0 && frameCnt == 20 && frameCnt % 10 == 0 ){
		enemyList.push_back( EnemySptr(new EnemyJ()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, 50));			//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}

	/*4-1*/
	if(phase == 0 && frameCnt < 200 && frameCnt == 0){
		enemyList.push_back( EnemySptr(new EnemyJ()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(makeRand(pos.x, 7), pos.y));			//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 0 && frameCnt > 250){
		phase++;
	}
	/*4-2*/
	if(phase == 1 && frameCnt < 450 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyK()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_INDENT - 100, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(1);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 1 && frameCnt > 600){
		phase++;
	}
	/*4-3*/
	if(phase == 2){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyL()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 3 && frameCnt > 900){
		phase++;
	}
	if (phase ==4 && frameCnt > 1100){
		next = 5;
	}
}
/*�A�N�V�����֐��i�ʁj*/
Stage5::Stage5(){
	pos = Vec2(SCREEN_WIDTH-SCREEN_INDENT - 50, -wideArea);	//�����ʒu
}
/*�A�N�V�����֐��i�ʁj*/
void Stage5::action(){
	/*STAGE1�̓G�L��������*/


	/*test*/
	if(phase == 0 && frameCnt == 20 && frameCnt % 10 == 0 ){
		enemyList.push_back( EnemySptr(new EnemyJ()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, 50));			//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}

	/*5-1*/
	if(phase == 0 && frameCnt < 200 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyA()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(makeRand(pos.x, 7), pos.y));			//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 0 && frameCnt > 250){
		phase++;
	}
	/*5-2*/
	if(phase == 1 && frameCnt < 450 && frameCnt % 10 == 0){
		enemyList.push_back( EnemySptr(new EnemyN()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_INDENT - 100, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(1);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 1 && frameCnt > 600){
		phase++;
	}
	/*5-3*/
	if(phase == 2){
		phase++;
		enemyList.push_back( EnemySptr(new EnemyO()) );				//���X�g�ɃI�u�W�F�N�g�ǉ�
		EnemyVsptr::iterator it = enemyList.end() - 1;				//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(Vec2(SCREEN_WIDTH / 2, -100));				//�G�@���C�x���g�ʒu�Ɉړ�
		(*it)->setPattern(0);										//�G�@�̍s���p�^�[���̎w��
	}
	if(phase == 3 && frameCnt > 900){
		phase++;
	}
	if (phase ==4){
		//next = 2;
	}
}
/*�A�N�V�����֐��i�ʁj*/
void GameOver::action(){

}
/*�A�N�V�����֐��i�ʁj*/
void GameClear::action(){
}