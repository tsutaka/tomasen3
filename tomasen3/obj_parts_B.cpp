#include "obj_parts_B.hpp"

CoreA::CoreA(){
	name = TEXT("�R�AA");	//���O
	maxHp = 30;				//�ő�ϋv�x
	hp = maxHp;				//���ݑϋv�x
	imageX = 0;				//�摜x���W
	imageY = 4;				//�摜y���W
	imageW = 1;				//�摜��
	imageH = 1;				//�摜��
	animeMax = 4;			//�A�j������
	animeWait = 4;			//�P������̃t���[��
	size = tipSize;			//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[0] = 0;
	jointPosY[0] = -tipSize;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[1] = tipSize;
	jointPosY[1] = 0;
	joint[(int)downJoint] = jointEmp;
	jointPosX[2] = 0;
	jointPosY[2] = tipSize;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[3] = -tipSize;
	jointPosY[3] = 0;

}

Base2B::Base2B(){
	name = TEXT("�x�[�X2B");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 28;				//�摜x���W
	imageY = 4;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[0] = 0;
	weaponPosY[0] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = tipSize;
	joint[(int)leftJoint] = jointEmp;
}

Base1A::Base1A(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X1A");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 0;					//�摜x���W
	imageY = 5;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = tipSize;
	joint[(int)leftJoint] = jointNG;
}

Base4::Base4(){
	name = TEXT("�x�[�X4");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 4;				//�摜x���W
	imageY = 4;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = tipSize;
	jointPosY[(int)downJoint] = 0;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base3A::Base3A(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X3�`");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 8;					//�摜x���W
	imageY = 4;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base3B::Base3B(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X3B");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 12;				//�摜x���W
	imageY = 4;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = -tipSize;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base3C::Base3C(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X3C");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 16;				//�摜x���W
	imageY = 4;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = -tipSize;
	joint[(int)leftJoint] = jointNG;
}

Base3D::Base3D(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X3D");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 20;				//�摜x���W
	imageY = 4;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = -tipSize;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base2A::Base2A(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X2A");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 24;				//�摜x���W
	imageY = 4;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base2C::Base2C(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X2C");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 32;				//�摜x���W
	imageY = 4;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base2D::Base2D(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X2D");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 36;				//�摜x���W
	imageY = 4;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointNG;
}

Base2E::Base2E(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X2E");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 40;				//�摜x���W
	imageY = 4;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = tipSize;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base2F::Base2F(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X2F");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 44;				//�摜x���W
	imageY = 4;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointEmp;
	jointPosX[(int)downJoint] = 0;
	jointPosY[(int)downJoint] = tipSize;
	joint[(int)leftJoint] = jointNG;
}

Base1B::Base1B(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X1B");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 4;					//�摜x���W
	imageY = 5;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointEmp;
	jointPosX[(int)leftJoint] = -tipSize;
	jointPosY[(int)leftJoint] = 0;
}

Base1C::Base1C(){
	/*�I�u�W�F�N�g�p�����[�^*/
	name = TEXT("�x�[�X1C");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 8;					//�摜x���W
	imageY = 5;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	/*����*/
	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	/*�W���C���g*/
	joint[(int)upJoint] = jointNG;
	joint[(int)rightJoint] = jointEmp;
	jointPosX[(int)rightJoint] = tipSize;
	jointPosY[(int)rightJoint] = 0;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointNG;
}

Base1D::Base1D(){
	name = TEXT("�x�[�X1D");	//���O
	maxHp = 10;					//�ő�ϋv�x
	hp = maxHp;					//���ݑϋv�x
	imageX = 12;				//�摜x���W
	imageY = 5;					//�摜y���W
	imageW = 1;					//�摜��
	imageH = 1;					//�摜��
	animeMax = 4;				//�A�j������
	animeWait = 4;				//�P������̃t���[��
	size = tipSize;				//�����蔻�蔼�a

	weapon[(int)mainWeapon] = weaponEmp;
	weaponPosX[(int)mainWeapon] = 0;
	weaponPosY[(int)mainWeapon] = 0;
	weapon[(int)subWeapon] = weaponNG;

	joint[(int)upJoint] = jointEmp;
	jointPosX[(int)upJoint] = 0;
	jointPosY[(int)upJoint] = -tipSize;
	joint[(int)rightJoint] = jointNG;
	joint[(int)downJoint] = jointNG;
	joint[(int)leftJoint] = jointNG;
}