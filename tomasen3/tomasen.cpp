
#include <cassert>
#include <cmath>

#include "tomasen.hpp"
#include "event.hpp"
#include "obj_effect.hpp"
#include "obj_wing_friend.hpp"

/*::::::::���C�����[�v::::::::*/
void Tomasen::runGame(HWND _hWnd){
	Tomasen::hWnd = _hWnd;
	//�P�v���C���[�v
	while(true){

		//�Q�[���S�̂̏�����
		Tomasen::initGame();
		
		//�t���[�����[�v
		while(true){
			Tomasen::inputGame();			//���͏���
			Tomasen::communicationGame();	//�`�B����
			Tomasen::updateGame();			//�X�V����
			Tomasen::deleteGame();			//�폜����
			Tomasen::printGame();			//�`�揈��
			await(1000/60);
		}
	};

	return;
}

/*::::::::��������::::::::*/
void Tomasen::initGame(){
	/*�����̏�����*/
	srand((unsigned int)1);

	/*�摜�N���X�̉�����*/
	IMAGE = new TipTile();
	IMAGE->init(hWnd, TEXT("image.bmp"), SCREEN_WIDTH, SCREEN_HEIGHT);
	IMAGE->setBasicColor(	IMAGE->tipNo(9,16), IMAGE->tipNo(10,16), IMAGE->tipNo(12,16),	//R, G, B
							IMAGE->tipNo(0,16), IMAGE->tipNo(15,16));						//B, W

	/*���y�N���X�̂�������*/
	MUSIC = new Music();
	musicBGM_5 = MUSIC->Open("music/BGM_5.wav");
	musicShot = MUSIC->Open("music/Shot.wav");
	musicEnemyDown = MUSIC->Open("music/EnemyDown.wav");
	musicFriendHit = MUSIC->Open("music/UseItem.wav");
	//MUSIC->Play(musicBGM_5);

	/*�e�평���ݒ�*/
	canInput = false;			//���͉ۃt���O
	stage = startStage;			//�����X�e�[�W�̐ݒ�
	mode = startMode;			//������ʂ̐ݒ�
	gold = 0;
	score = 0;
	stringV.push_back("���������@�L�[�F�ړ�");
	stringV.push_back("Shift:�k�� Z:�ˌ� X:��C");

	/*���@�z�u*/
	kosenWing = friendFactory( 
		FriendSptr(new KosenWing()), Vec2(startPosX, startPosY) );	//��X�}�|���擾

	/*�Q�[�W�̏�����*/	
	hpBar = barFactory( BarSptr(new HpBar()) );			//��X�}�|���擾
	energyBar = barFactory( BarSptr(new EnergyBar()) );	//��X�}�|���擾
	manBar = barFactory( BarSptr(new ManBar()) );		//��X�}�|���擾
	fireBar = barFactory( BarSptr(new FireBar()) );		//��X�}�|���擾


	/*���x���̏�����*/
	goldLabel = labelFactory( LabelSptr(new GoldLabel()) );		//��X�}�|���擾
	scoreLabel = labelFactory( LabelSptr(new ScoreLabel()) );	//��X�}�|���擾


	/*�C�x���g�̐ݒu*/
	eventFactory( EventSptr(new GameTitle()) );	//�C�x���g�𐶐����ă��X�g��
}

/*::::::::���͏���::::::::*/
void Tomasen::inputGame(){
	/*���@�ɑ΂������*/
	shotPerm = 0;
	if(!canInput) return;
	if(FriendSptr tmp = kosenWing.lock()){
		/*�ړ��ʂ̍X�V*/
		if(GetAsyncKeyState(VK_UP)){//��
			tmp->setMove(Vec2(0, -moveAmount) + tmp->getMove() );	//���@����Ɉړ�
		}
		if(GetAsyncKeyState(VK_DOWN)) {//��
			tmp->setMove(Vec2(0, moveAmount) + tmp->getMove() );	//���@�����Ɉړ�
		}
		if(GetAsyncKeyState(VK_LEFT)) {//��
			tmp->setMove(Vec2(-moveAmount, 0) + tmp->getMove() );	//���@�����Ɉړ�
		}
		if(GetAsyncKeyState(VK_RIGHT)) {//��
			tmp->setMove(Vec2(moveAmount, 0) + tmp->getMove() );	//���@���E�Ɉړ�
		}
		if(GetAsyncKeyState('Z')) {//Z
			shotPerm = 1;											//�ˌ�����
			//MUSIC->Play(musicShot);
		}
		if(GetAsyncKeyState(VK_SHIFT)) {//Shift
			tmp->addKaihi(12);										//���
			//MUSIC->Play(musicShot);
		}
	}

} 

/*::::::::�`�B����::::::::*/
void Tomasen::communicationGame(){

	/*�Q�[�W�\���̓`�B*/
	if(FriendSptr tmp = kosenWing.lock()){		
		if(BarSptr tmp2 = hpBar.lock()){				
			tmp2->setValue( tmp->getHp() );					//����HP�̍X�V
			tmp2->setMaxValue( tmp->getMaxHp() );			//�ő�HP�̍X�V
			tmp2->setStartValue( tmp->getStartHp() );		//����HP�̍X�V
		}
		if(BarSptr tmp2 = energyBar.lock()){				
			tmp2->setValue( tmp->getEnergy() );				//����EN�̍X�V
			tmp2->setMaxValue( tmp->getMaxEnergy() );		//�ő�EN�̍X�V
			tmp2->setStartValue( tmp->getStartEnergy() );	//����EN�̍X�V
		}
		if(BarSptr tmp2 = manBar.lock()){				
			tmp2->setValue( tmp->getMan() );				//���ݐl�̍X�V
			tmp2->setMaxValue( tmp->getMaxMan() );			//�ő�l�̍X�V
			tmp2->setStartValue( tmp->getStartMan() );		//�����l�̍X�V
		}
		if(BarSptr tmp2 = fireBar.lock()){				
			tmp2->setValue( tmp->getFire() );				//���݉��̍X�V
			tmp2->setMaxValue( tmp->getBurnFire() );		//���Ή��̍X�V
			tmp2->setStartValue( tmp->getMaxFire() );		//�ő削�̍X�V
		}
	}

	/*���x���̍X�V*/
	if(LabelSptr tmp = goldLabel.lock()){				
		tmp->setValue( gold );			//�S�[���h�̍X�V
	}
	if(LabelSptr tmp = scoreLabel.lock()){				
		tmp->setValue( score );			//�X�R�A�̍X�V
	}
}

/*::::::::�X�V����::::::::*/
void Tomasen::updateGame(){

	/*�C�x���g�̍X�V����*/
	for(EventVsptr::iterator it = eventList.begin(); it != eventList.end(); it++){
		(*it)->update();
	}
	for(EventVsptr::iterator it = eventList.begin(); it != eventList.end(); it++){
		(*it)->action();
	}

	/*�G�@�̍X�V*/
	for(EnemyVsptr::iterator it = enemyList.begin(); it != enemyList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
		(*it)->action(dummy);
	}

	/*���@�n���̍X�V*/
	if(FriendSptr tmp = kosenWing.lock()){
		Object obj;			//�_�~�[
		tmp->update(obj);	//���@�X�V�i�T���؁j
	}
	/*�e�p�[�c�ŗL�̏���*/
	for(PartsAVsptr::iterator it = partsAList.begin(); it != partsAList.end(); it++){
		if(shotPerm) (*it)->action();
	}

	/*���e�X�V����*/
	for(FriendBulletVsptr::iterator it = friendBulletList.begin(); it != friendBulletList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
	}

	/*�G�e�X�V����*/
	for(EnemyBulletVsptr::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
		(*it)->action(dummy);
	}

	/*�G�t�F�N�g�X�V����*/
	for(EffectVsptr::iterator it = effectList.begin(); it != effectList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
	}

	/*�o�[�̍X�V*/
	for(BarVsptr::iterator it = barList.begin(); it != barList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
	}

	/*���x���̍X�V*/
	for(LabelVsptr::iterator it = labelList.begin(); it != labelList.end(); it++){
		Object dummy;
		(*it)->update(dummy);
	}
	/*�C�x���g�n���̍X�V*/
	/*���̑��n���̍X�V*/
}

/*::::::::�폜����::::::::*/
void Tomasen::deleteGame(){

	/*�G�t�F�N�g���Ŕ���*/
	for(int cnt = 1; cnt > 0; cnt--){//�C�e���[�^�̍폜�Ȃ̂ŏ��׍H
		for(EffectVsptr::iterator it = effectList.begin(); it != effectList.end(); it++){
			if((*it)->getTimeOfLife() == 0){	//���ԏ���
				effectList.erase(it);
				cnt = 1;
				break;
			}
			if(isIn(0 - wideArea, SCREEN_HEIGHT + wideArea, 
					0 - wideArea, SCREEN_WIDTH + wideArea, 
					(int)( (*it)->getPos().x + (*it)->getSize()/2 ), 
					(int)( (*it)->getPos().y + (*it)->getSize()/2 ) ) == false){	//��ʊO����
				effectList.erase(it);
				cnt = 1;
				break;
			}
		}
	}

	/*�C�x���g�I���t���O����*/
	for(int cnt = 1; cnt > 0; cnt--){//�C�e���[�^�̍폜�Ȃ̂ŏ��׍H
		for(EventVsptr::iterator it = eventList.begin(); it != eventList.end(); it++){
			int next = (*it)->nextEvent();
			if(next > 0){	//�t���O����
				eventList.erase(it);
				switch(next){
				case 1:
					stringV.push_back("Stage1�J�n");
					eventFactory( EventSptr(new Stage1()) );
					break;
				case 2:
					stringV.push_back("Stage2�J�n");
					eventFactory( EventSptr(new Stage2()) );
					break;
				case 3:
					stringV.push_back("Stage3�J�n");
					eventFactory( EventSptr(new Stage3()) );
					break;
				case 4:
					stringV.push_back("Stage4�J�n");
					eventFactory( EventSptr(new Stage4()) );
					break;
				case 5:
					stringV.push_back("Stage5�J�n");
					eventFactory( EventSptr(new Stage5()) );
					break;
				}
				canInput = true;
				cnt = 1;
				break;
			}
		}
	}


	/*���e�����蔻��*/
	for(FriendBulletVsptr::iterator it = friendBulletList.begin(); it != friendBulletList.end(); it++){
		double bulletX = (*it)->getPos().x + (*it)->getSize() / 2;		//���eX���W
		double bulletY = (*it)->getPos().y + (*it)->getSize() / 2;		//���eY���W
		int bulletSize = (*it)->getSize();	//���e�T�C�Y
		int bulletHp = (*it)->getHp();		//���e�ϋv�x
		for(EnemyVsptr::iterator it2 = enemyList.begin(); it2 != enemyList.end(); it2++){
			double enemyX = (*it2)->getPos().x + (*it2)->getSize() / 2;	//�G�@X���W
			double enemyY = (*it2)->getPos().y + (*it2)->getSize() / 2;	//�G�@Y���W
			int enemySize = (*it2)->getSize();//�G�@�T�C�Y
			int enemyHp = (*it2)->getHp();	//�G�@�ϋv�x
			if(	(bulletX - enemyX) * (bulletX - enemyX) + 
			(bulletY - enemyY) * (bulletY - enemyY) <
			(bulletSize + enemySize) * (bulletSize + enemySize) ){
				(*it)->damageHp(enemyHp);	//���e�ϋv�x����
				(*it2)->damageHp(bulletHp);	//�G�@�ϋv�x����
			}
			
		}
	}
	/*���e���Ŕ���*/
	for(int cnt = 1; cnt > 0; cnt--){//�C�e���[�^�̍폜�Ȃ̂ŏ��׍H
		for(FriendBulletVsptr::iterator it = friendBulletList.begin(); it != friendBulletList.end(); it++){
			if(isIn(0, SCREEN_HEIGHT, 
					0, SCREEN_WIDTH, 
					(int)( (*it)->getPos().x + (*it)->getSize()/2 ), 
					(int)( (*it)->getPos().y + (*it)->getSize()/2 ) ) == false){	//��ʊO����
				friendBulletList.erase(it);
				cnt = 1;
				break;
			}
			if((*it)->getHp() == 0){	//�ϋv�x����
				friendBulletList.erase(it);
				cnt = 1;
				break;
			}
		}
	}

	/*�G�@�����蔻��*/
	for(EnemyVsptr::iterator it = enemyList.begin(); it != enemyList.end(); it++){
		double EnemyX = (*it)->getPos().x + (*it)->getSize() / 2;		//�G�@X���W
		double EnemyY = (*it)->getPos().y + (*it)->getSize() / 2;		//�G�@Y���W
		int EnemySize = (*it)->getSize();		//�G�@�T�C�Y
		int EnemyHp = (*it)->getHp();			//�G�@�ϋv�x
		/*�΃p�[�cA*/
		for(PartsAVsptr::iterator it2 = partsAList.begin(); it2 != partsAList.end(); it2++){
			double partsX = (*it2)->getPos().x + (*it2)->getSize() / 2;	//�p�[�cX���W
			double partsY = (*it2)->getPos().y + (*it2)->getSize() / 2;	//�p�[�cY���W
			int partsSize = (*it2)->getSize();	//�p�[�c�T�C�Y
			int partsHp = (*it2)->getHp();		//�p�[�c�ϋv�x
			if(	(EnemyX - partsX) * (EnemyX - partsX) + 
			(EnemyY - partsY) * (EnemyY - partsY) <
			(EnemySize + partsSize) * (EnemySize + partsSize) ){
				(*it)->damageHp(partsHp);			//�G�@�ϋv�x����
				(*it2)->damageHp(EnemyHp);			//�p�[�c�ϋv�x����
				MUSIC->Play(musicFriendHit);		//��e��
			}
		}
		EnemyHp = (*it)->getHp();			//�G�e�ϋv�x
		/*�΃p�[�cB*/
		for(PartsBVsptr::iterator it2 = partsBList.begin(); it2 != partsBList.end(); it2++){
			double partsX = (*it2)->getPos().x + (*it2)->getSize() / 2;	//�p�[�cX���W
			double partsY = (*it2)->getPos().y + (*it2)->getSize() / 2;	//�p�[�cY���W
			int partsSize = (*it2)->getSize();	//�p�[�c�T�C�Y
			int partsHp = (*it2)->getHp();		//�p�[�c�ϋv�x
			if(	(EnemyX - partsX) * (EnemyX - partsX) + 
			(EnemyY - partsY) * (EnemyY - partsY) <
			(EnemySize + partsSize) * (EnemySize + partsSize) ){
				(*it)->damageHp(partsHp);			//�G�@�ϋv�x����
				(*it2)->damageHp(EnemyHp);			//�p�[�c�ϋv�x����
				MUSIC->Play(musicFriendHit);		//��e��
			}
		}
	}
	/*�G�@���Ŕ���*/
	for(int cnt = 1; cnt > 0; cnt--){//�C�e���[�^�̍폜�Ȃ̂ŏ��׍H
		for(EnemyVsptr::iterator it = enemyList.begin(); it != enemyList.end(); it++){
			if(isIn(0 - wideArea, SCREEN_HEIGHT + wideArea, 
					0 - wideArea, SCREEN_WIDTH + wideArea, 
					(int)( (*it)->getPos().x + (*it)->getSize()/2 ), 
					(int)( (*it)->getPos().y + (*it)->getSize()/2 ) ) == false){	//��ʊO����
				enemyList.erase(it);
				cnt = 1;
				break;
			}
			if((*it)->getHp() == 0){					//�ϋv�x����
				score += (*it)->getMaxHp() * 10;		//�X�R�A���Z
				MUSIC->Play(musicEnemyDown);			//���j��
				//����
				effectFactory(EffectSptr(new Explosion()), 
					(*it)->getPos(), Vec2( (*it)->getPos().x, (*it)->getPos().y - 100.0 )
					);
				enemyList.erase(it);
				cnt = 1;
				break;
			}
		}
	}


	/*�G�e�����蔻��*/
	for(EnemyBulletVsptr::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); it++){
		double bulletX = (*it)->getPos().x + (*it)->getSize() / 2;		//�G�eX���W
		double bulletY = (*it)->getPos().y + (*it)->getSize() / 2;		//�G�eY���W
		int bulletSize = (*it)->getSize();		//�G�e�T�C�Y
		int bulletHp = (*it)->getHp();			//�G�e�ϋv�x
		int bulletFire = (*it)->getFire();		//�e�̉Η�
		/*�΃p�[�cA*/
		for(PartsAVsptr::iterator it2 = partsAList.begin(); it2 != partsAList.end(); it2++){
			double partsX = (*it2)->getPos().x + (*it2)->getSize() / 2;	//�p�[�cX���W
			double partsY = (*it2)->getPos().y + (*it2)->getSize() / 2;	//�p�[�cY���W
			int partsSize = (*it2)->getSize();	//�p�[�c�T�C�Y
			int partsHp = (*it2)->getHp();		//�p�[�c�ϋv�x
			if(	(bulletX - partsX) * (bulletX - partsX) + 
			(bulletY - partsY) * (bulletY - partsY) <
			(bulletSize + partsSize) * (bulletSize + partsSize) ){
				(*it)->damageHp(partsHp);			//�G�e�ϋv�x����
				(*it2)->damageHp(bulletHp);			//�p�[�c�ϋv�x����
				(*it2)->killMan(bulletHp);			//�E��
				(*it2)->addFire( bulletFire );		//�Ἠ_���[�W
				//����
				effectFactory(EffectSptr(new Explosion()), 
					(*it)->getPos(), 
					Vec2( (*it)->getPos().x + makeRand(0.0, 50), 
						(*it)->getPos().y + makeRand(200.0, 60) )
					);
				//MUSIC->Play(musicFriendHit);		//��e��
			}
		}
		bulletHp = (*it)->getHp();			//�G�e�ϋv�x
		/*�΃p�[�cB*/
		for(PartsBVsptr::iterator it2 = partsBList.begin(); it2 != partsBList.end(); it2++){
			double partsX = (*it2)->getPos().x + (*it2)->getSize() / 2;	//�p�[�cX���W
			double partsY = (*it2)->getPos().y + (*it2)->getSize() / 2;	//�p�[�cY���W
			int partsSize = (*it2)->getSize();	//�p�[�c�T�C�Y
			int partsHp = (*it2)->getHp();		//�p�[�c�ϋv�x
			if(	(bulletX - partsX) * (bulletX - partsX) + 
			(bulletY - partsY) * (bulletY - partsY) <
			(bulletSize + partsSize) * (bulletSize + partsSize) ){
				(*it)->damageHp(partsHp);			//�G�e�ϋv�x����
				(*it2)->damageHp(bulletHp);			//�p�[�c�ϋv�x����
				(*it2)->killMan(bulletHp);			//�E��
				(*it2)->addFire( bulletFire );		//�Ἠ_���[�W
				//����
				effectFactory(EffectSptr(new Explosion()), 
					(*it)->getPos(), 
					Vec2( (*it)->getPos().x + makeRand(0.0, 30), 
						(*it)->getPos().y + makeRand(250.0, 90) )
					);

				//MUSIC->Play(musicFriendHit);		//��e��
			}
		}
	}
	/*�G�e���Ŕ���*/
	for(int cnt = 1; cnt > 0; cnt--){//�C�e���[�^�̍폜�Ȃ̂ŏ��׍H
		for(EnemyBulletVsptr::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); it++){
			if(isIn(0, SCREEN_HEIGHT, 
					0, SCREEN_WIDTH, 
					(int)( (*it)->getPos().x + (*it)->getSize()/2 ), 
					(int)( (*it)->getPos().y + (*it)->getSize()/2 ) ) == false){	//��ʊO����
				enemyBulletList.erase(it);
				cnt = 1;
				break;
			}
			if((*it)->getHp() == 0){	//�ϋv�x����
				enemyBulletList.erase(it);
				cnt = 1;
				break;
			}
		}
	}

	/*�p�[�cA���Ŕ���*/
	for(int cnt = 1; cnt > 0; cnt--){//�C�e���[�^�̍폜�Ȃ̂ŏ��׍H
		for(PartsAVsptr::iterator it = partsAList.begin(); it != partsAList.end(); it++){
			if((*it)->getHp() == 0){	//�ϋv�x����
				partsAList.erase(it);
				cnt = 1;
				break;
			}
		}
	}
	/*�p�[�cB���Ŕ���*/
	for(int cnt = 1; cnt > 0; cnt--){//�C�e���[�^�̍폜�Ȃ̂ŏ��׍H
		for(PartsBVsptr::iterator it = partsBList.begin(); it != partsBList.end(); it++){
			if((*it)->getHp() == 0){	//�ϋv�x����
				partsBList.erase(it);
				cnt = 1;
				break;
			}
		}
	}


}

/*::::::::�\������::::::::*/
void Tomasen::printGame(){
	/*��ʂ̓h��Ԃ�*/
	IMAGE->drawTip(	0.0, 0.0, 
					(double)SCREEN_WIDTH, (double)SCREEN_HEIGHT, 
					IMAGE->getBlack());
	/*�G�t�F�N�g�`�揈��*/
	for(EffectVsptr::iterator it = effectList.begin(); it != effectList.end(); it++){
		IMAGE->drawTile((*it)->getPos(), 
						(*it)->getOutputW(), 
						(*it)->getOutputH(), 
						(*it)->getImageX(), (*it)->getImageY(), 
						(*it)->getImageW(), (*it)->getImageH());

	}
	/*�p�[�cB�`�揈��*/
	for(PartsBVsptr::iterator it = partsBList.begin(); it != partsBList.end(); it++){
		IMAGE->drawTip( (*it)->getPos().x, (*it)->getPos().y, 
						(double)tipSize * (*it)->getOutputW(), 
						(double)tipSize * (*it)->getOutputW(), 
						IMAGE->tipNo(	(*it)->getImageX(), 
										(*it)->getImageY() ) );
	}
	/*�p�[�cA�`�揈��*/
	for(PartsAVsptr::iterator it = partsAList.begin(); it != partsAList.end(); it++){
		IMAGE->drawTip( (*it)->getPos().x, (*it)->getPos().y, 
						(double)tipSize * (*it)->getOutputW(), 
						(double)tipSize * (*it)->getOutputW(), 
						IMAGE->tipNo(	(*it)->getImageX(), 
										(*it)->getImageY() ) );
	}
	
	/*���e�`�揈��*/
	for(FriendBulletVsptr::iterator it = friendBulletList.begin(); it != friendBulletList.end(); it++){
		IMAGE->drawTip( (*it)->getPos().x, (*it)->getPos().y, 
						(double)tipSize * (*it)->getOutputW(), 
						(double)tipSize * (*it)->getOutputW(), 
						IMAGE->tipNo(	(*it)->getImageX(), 
										(*it)->getImageY() ) );
	}
	
	/*�G�@�`�揈��*/
	for(EnemyVsptr::iterator it = enemyList.begin(); it != enemyList.end(); it++){
		IMAGE->drawTile( (*it)->getPos().x, (*it)->getPos().y,	//x, y,
						(double)tipSize * (*it)->getOutputW(), 
						(double)tipSize * (*it)->getOutputW(), 
						IMAGE->tipNo(	(*it)->getImageX(),		//ino
										(*it)->getImageY() ), 
						(*it)->getImageW(), (*it)->getImageH()	//ix, iy, 
						);
	}
	
	/*�G�e�`�揈��*/
	for(EnemyBulletVsptr::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); it++){
		IMAGE->drawTip( (*it)->getPos().x, (*it)->getPos().y, 
						(double)tipSize * (*it)->getOutputW(), 
						(double)tipSize * (*it)->getOutputW(), 
						IMAGE->tipNo(	(*it)->getImageX(), 
										(*it)->getImageY() ) );
	}
	


	/*�����h��Ԃ�*/
	IMAGE->drawTip(	0.0, 0.0, 
					(double)SCREEN_INDENT, (double)SCREEN_HEIGHT, 
					IMAGE->tipNo(4,16));
	IMAGE->drawTip(	(double)(SCREEN_WIDTH - SCREEN_INDENT), 0.0, 
					(double)SCREEN_INDENT, (double)SCREEN_HEIGHT, 
					IMAGE->tipNo(4,16));

	/*�f�o�b�O������\��*/
	if(FriendSptr tmp = kosenWing.lock()){
		char str[256];
		sprintf_s(str, "A:%03d, B:%03d, cnt:%d", partsAList.size(), partsBList.size(), tmp->getFrameCnt());
		IMAGE->printText(0, 0, str);
		sprintf_s(str, "X:%+03.3f  MoveX:%+03.3f", tmp->getPos().x, tmp->getMove().x);
		IMAGE->printText(0, 1, str);
		sprintf_s(str, "Y:%+03.3f  MoveY:%+03.3f", tmp->getPos().y, tmp->getMove().y);
		IMAGE->printText(0, 2, str);
		sprintf_s(str, "���e:%03d, �G�e:%03d", friendBulletList.size(), enemyBulletList.size());
		IMAGE->printText(0, 3, str);
		sprintf_s(str, "�G�@:%03d, Event��:%03d", enemyList.size(), eventList.size());
		IMAGE->printText(0, 4, str);
		sprintf_s(str, "effect:%03d, hp:%03d/%03d", effectList.size(), tmp->getHp(), tmp->getMaxHp());
		IMAGE->printText(0, 5, str);
		sprintf_s(str, "A:%03d/%03d, B:%03d/B:%03d",	tmp->getPartsANum(), tmp->getPartsANum() + tmp->getPartsALost(), 
														tmp->getPartsBNum(), tmp->getPartsBNum() + tmp->getPartsBLost());
		IMAGE->printText(0, 6, str);
		sprintf_s(str, "%03d %03d %03d",	tmp->getFire(), tmp->getMaxMan(), tmp->getStartMan() );
		IMAGE->printText(0, 7, str);
	}
	
	/*���b�Z�[�W���g*/
	IMAGE->drawFillTip(1, 15, 11, 20, IMAGE->tipNo(21,17));
	/*�R�}���h��*/
	IMAGE->drawFillTip(1, 36, 11, 1, IMAGE->tipNo(21,17));

	/*���b�Z�[�W*/
	int cnt = 0;	//20���܂ŕ\��
	for(StringV::iterator it = stringV.begin(); it != stringV.end(); it++){
		IMAGE->printText(1, 15 + (20 - stringV.size()) + cnt, (*it).c_str());
		cnt++;
		if(cnt >= 20) break;
	}

	/*�o�[�̕\��*/
	for(BarVsptr::iterator it = barList.begin(); it != barList.end(); it++){
		IMAGE->printText((int)(*it)->getPos().x/tipSize - 2, 
			(int)(*it)->getPos().y/tipSize, (*it)->getName().c_str());
		IMAGE->drawFillTip((*it)->getPos(), 
			(*it)->getSize(), 1, 
		IMAGE->tipNo((*it)->getUnderImageX(), (*it)->getUnderImageY()) );		//���n
		if((*it)->getStartValue() > 0){											//�돜�Z�̉��
			IMAGE->drawTip((*it)->getPos().x, (*it)->getPos().y, 
				(double)(*it)->getSize() * tipSize * (*it)->getMaxValue() / (*it)->getStartValue(), 
				(double)1 * tipSize, 
				IMAGE->tipNo((*it)->getMaxImageX(), (*it)->getMaxImageY()));	//���ő�o�[
			IMAGE->drawTip((*it)->getPos().x, (*it)->getPos().y, 
				(double)(*it)->getSize() * tipSize * (*it)->getPrintValue() / (*it)->getStartValue(), 
				(double)1 * tipSize, 
				IMAGE->tipNo((*it)->getImageX(), (*it)->getImageY()));			//���ݒl�̃o�[
		}
		else{
			//mb("�ő�l���떔�͕��̐�");
		}
		IMAGE->drawFillTip((*it)->getPos(), 
			(*it)->getSize(), 1, 
			IMAGE->tipNo((*it)->getOverImageX(), (*it)->getOverImageY()) );		//��g
	}
	
	/*���x���̕\��*/
	for(LabelVsptr::iterator it = labelList.begin(); it != labelList.end(); it++){
		IMAGE->printText((int)(*it)->getPos().x/tipSize, 
			(int)(*it)->getPos().y/tipSize, 
			(*it)->getName().c_str());
		sprintf_s(checktext, sizeof(checktext), "%08d", (*it)->getPrintValue());
		IMAGE->printText((int)(*it)->getPos().x/tipSize + 7, 
			(int)(*it)->getPos().y/tipSize, 
			checktext);
		
	}

	/*�f�B�X�v���C�ɕ\��*/
	IMAGE->drawEnd();
}