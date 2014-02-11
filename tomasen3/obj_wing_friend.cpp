#include <cmath>

#include "obj_wing_friend.hpp"

/*�O���[�o�����\�[�X��`*/
FriendVsptr friendList;			//���@���X�g
FriendWptr friendFactory(FriendSptr friendw, Vec2 pos){
		friendList.push_back( friendw );					//���X�g�ɃI�u�W�F�N�g�ǉ�
		FriendVsptr::iterator it = friendList.end() - 1;	//���O�̃I�u�W�F�N�g���Q��
		(*it)->setPos(pos);
		return (*it);
}

KosenWing::KosenWing(){
	/*������*/
	name = TEXT("�R�[�Z���E�B���O");				//���̂̐ݒ�
	maxMove = 4.0;									//�ő�ړ���
	subMove = 0.90;									//�����ړ��ʔ{��
	maxHp = 10;										//�ő�ϋv�x
	imageX = 0;										//�摜x���W
	imageY = 0;										//�摜y���W
	imageW = 1;										//�摜��
	imageH = 1;										//�摜��
	size = tipSize;									//�����蔻�蔼�a
	frameCnt = 0;									//�o�߃t���[����
	
	partsANum = 0;	//�����_�p�[�cA��
	partsALost = 0;	//�ݐϑr���p�[�cA��
	partsBNum = 0;	//�����_�p�[�cB��
	partsBLost = 0;	//�ݐϑr���p�[�cB��


	/*���@����*/	
	core = partsBFactory( PartsBSptr(new CoreA()) );			//�ア�X�}�|�Őe�q�֌W
	if(PartsBSptr coreSptr = core.lock()){						//�R�A�Ƀp�[�c��ǉ�����B

/*
		//
		coreSptr->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new EngineA()) )
			);					//�R�A�ɃG���W���ǉ�

		PartsBSptr base1A = partsBFactory( PartsBSptr(new Base1A()) ).lock();//lock���s�̃G���[�����ȗ�
		coreSptr->setPartsB(upJoint, base1A);					//�R�A�Ƀx�[�X�P�`�ǉ�
		base1A->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new CockpitA()) )
			);				//�x�[�X�P�`�ɃR�b�N�s�b�g�ǉ�

		PartsBSptr base1D = partsBFactory( PartsBSptr(new Base1D()) ).lock();//lock���s�̃G���[�����ȗ�
		coreSptr->setPartsB(downJoint, base1D);					//�R�A�Ƀx�[�X�P�c�ǉ�
		base1D->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//�x�[�X�P�c�Ƀ}�V���K���`�ǉ�
*/	
		coreSptr->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new EngineA()) )
			);					//�R�A�ɃG���W���ǉ�

		PartsBSptr base2B_E16 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock���s�̃G���[�����ȗ�
		coreSptr->setPartsB(upJoint, base2B_E16);					//�R�A�Ƀx�[�X�P�`�ǉ�
		base2B_E16->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new EngineA()) )
			);				//�x�[�X2B�ɃR�b�N�s�b�g�ǉ�

		PartsBSptr base2F_D18 = partsBFactory( PartsBSptr(new Base2F()) ).lock();//lock���s�̃G���[�����ȗ�
		coreSptr->setPartsB(leftJoint, base2F_D18);					//�R�A�Ƀx�[�X�R�`�ǉ�
		base2F_D18->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//�x�[�X�R�`�Ƀ}�V���K���`�ǉ�
		
		
		PartsBSptr base2E_F18 = partsBFactory( PartsBSptr(new Base2E()) ).lock();//lock���s�̃G���[�����ȗ�
		coreSptr->setPartsB(rightJoint, base2E_F18);					//�x�[�X�R�`�Ƀx�[�X�Q�e�ǉ�
		base2E_F18->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//�x�[�X�Q�e�Ƀ}�V���K���`�ǉ�

		PartsBSptr base2B_E20 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock���s�̃G���[�����ȗ�
		coreSptr->setPartsB(downJoint, base2B_E20);					//�x�[�X�R�`�Ƀx�[�X�Q�e�ǉ�
		base2B_E20->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new EngineA()) )
			);				//�x�[�X�Q�e�Ƀ}�V���K���`�ǉ�
		
		PartsBSptr base1D_E22 = partsBFactory( PartsBSptr(new Base1D()) ).lock();//lock���s�̃G���[�����ȗ�
		base2B_E20->setPartsB(downJoint, base1D_E22);					//�x�[�X�R�`�Ƀx�[�X�Q�e�ǉ�
		base2B_E20->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new EngineA()) )
			);				//�x�[�X�Q�e�Ƀ}�V���K���`�ǉ�

		PartsBSptr base2B_E14 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock���s�̃G���[�����ȗ�
		base2B_E16->setPartsB(upJoint, base2B_E14);					//�x�[�X�R�`�Ƀx�[�X�Q�e�ǉ�
		base2B_E14->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new CockpitA()) )
			);				//�x�[�X�Q�e�Ƀ}�V���K���`�ǉ�
		
		PartsBSptr base1A_E12 = partsBFactory( PartsBSptr(new Base1A()) ).lock();//lock���s�̃G���[�����ȗ�
		base2B_E14->setPartsB(upJoint, base1A_E12);					//�x�[�X�R�`�Ƀx�[�X�Q�e�ǉ�
		base1A_E12->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//�x�[�X�Q�e�Ƀ}�V���K���`�ǉ�

		PartsBSptr base2B_D20 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock���s�̃G���[�����ȗ�
		base2F_D18->setPartsB(downJoint, base2B_D20);					//�x�[�X�R�`�Ƀx�[�X�Q�e�ǉ�
		base2B_D20->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//�x�[�X�Q�e�Ƀ}�V���K���`�ǉ�

		PartsBSptr base2B_F20 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock���s�̃G���[�����ȗ�
		base2E_F18->setPartsB(downJoint, base2B_F20);					//�x�[�X�R�`�Ƀx�[�X�Q�e�ǉ�
		base2B_F20->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//�x�[�X�Q�e�Ƀ}�V���K���`�ǉ�

		PartsBSptr base2B_F22 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock���s�̃G���[�����ȗ�
		base2B_F20->setPartsB(downJoint, base2B_F22);					//�x�[�X�R�`�Ƀx�[�X�Q�e�ǉ�
		base2B_F22->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new CockpitA()) )
			);				//�x�[�X�Q�e�Ƀ}�V���K���`�ǉ�

		PartsBSptr base2B_D22 = partsBFactory( PartsBSptr(new Base2B()) ).lock();//lock���s�̃G���[�����ȗ�
		base2B_D20->setPartsB(downJoint, base2B_D22);					//�x�[�X�R�`�Ƀx�[�X�Q�e�ǉ�
		base2B_D22->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new CockpitA()) )
			);				//�x�[�X�Q�e�Ƀ}�V���K���`�ǉ�

		PartsBSptr base1D_F24 = partsBFactory( PartsBSptr(new Base1D()) ).lock();//lock���s�̃G���[�����ȗ�
		base2B_F22->setPartsB(downJoint, base1D_F24);					//�x�[�X�R�`�Ƀx�[�X�Q�e�ǉ�
		base1D_F24->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//�x�[�X�Q�e�Ƀ}�V���K���`�ǉ�

		PartsBSptr base1D_D24 = partsBFactory( PartsBSptr(new Base1D()) ).lock();//lock���s�̃G���[�����ȗ�
		base2B_D22->setPartsB(downJoint, base1D_D24);					//�x�[�X�R�`�Ƀx�[�X�Q�e�ǉ�
		base1D_D24->setPartsA(mainWeapon, 
			partsAFactory( PartsASptr(new MachineGunA()) )
			);				//�x�[�X�Q�e�Ƀ}�V���K���`�ǉ�


		


		Object obj;					//�_�~�[
		this->update(obj);			//���@�X�V�i�T���؁j
		startHp = maxHp;			//����HP�̋L�^
		startEnergy = maxEnergy;	//����EN�̋L�^
		startMan = maxMan;			//�����l�̋L�^
	}
	
}


/*�X�V�֐�*/
void KosenWing::update(Object obj){
	/*�e�p�����[�^���X�V����*/
	frameCnt++;										//�t���[���J�E���g�̍X�V
	if(frameCnt > 50000) frameCnt = 0;

	/*�p�[�c�֌W�̍X�V*/
	if(PartsBSptr tmp = core.lock()){
		/*�p�[�c����̏����W*/
		TellUpBox box = {
			0,0,		//hp, maxHp
			0,0,0,		//energy,maxEnergy,chargeEnergy
			0,0,0,		//man,requireMan,maxMan
			0,0,0,		//fire,burnFire,maxFire
			0,0,1,0};	//A,lostA,B,lostB				
		tmp->tellUp(box);
		hp = box.hp;
		maxHp = box.maxHp;
		energy = box.energy;
		chargeEnergy = box.chargeEnergy;
		maxEnergy = box.maxEnergy;
		man = box.man;
		requireMan = box.requireMan;
		maxMan = box.maxMan;
		fire = box.fire;
		burnFire = box.burnFire;
		maxFire = box.maxFire;
		partsANum = box.pertsANum;
		partsALost += box.pertsALost;
		partsBNum = box.pertsBNum;
		partsBLost += box.pertsBLost;

		/*���l�̍X�V*/
		tmp->setKaihi(kaihi);
	}
	else{//�R�A������Ă�
		//mb("�R�A�j��");
	}
	
	/*���@�ړ�*/
	dir = atan2(move.y, move.x);					//���݂̐i�s�p�Z�o
	dis = sqrt(move.x * move.x + move.y * move.y);	//�ړ��ʎZ�o
	if(dis > maxMove){
		dis = maxMove;						//�ړ��ʗ}�~
	}
	else{
		dis *= subMove;
	}
	move.x = cos(dir) * dis;				//�ړ��ʗ}�~
	move.y = sin(dir) * dis;				//�ړ��ʗ}�~
	pos.x = pos.x + cos(dir) * dis;			//���@�ړ�
	pos.y = pos.y + sin(dir) * dis;			//���@�ړ�
	/*�ړ�������*/
	if(pos.x < SCREEN_INDENT){
		pos.x = SCREEN_INDENT;
	}
	if(pos.y < 0){
		pos.y = 0;
	}
	if(pos.x > SCREEN_WIDTH - SCREEN_INDENT - size){
		pos.x = SCREEN_WIDTH - SCREEN_INDENT - size;
	}
	if(pos.y > SCREEN_HEIGHT - size){
		pos.y = SCREEN_HEIGHT - size;
	}

	/*�R�A�̍X�V*/
	if(PartsBSptr tmp = core.lock()){
		tmp->update((Object)(*this));	//�R�A�X�V�i�T���؁j
	}

	/*���l�̍X�V*/
	addKaihi(-4);
}
