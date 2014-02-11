/************

	TipTile�N���X
		�iD2Image(image.hpp)�N���X�̃��b�p�[�j

	�`�b�v�P�ʂł̕`��]������

************/

#ifndef INCLUDED_TIPTILE_HPP
#define INCLUDED_TIPTILE_HPP

/*************
���P
�Einline�֐��̓w�b�_�t�@�C���ɒ�`�������Ȃ��Ă͂Ȃ�Ȃ��B
�E���̊֐��͐錾�̂݃w�b�_�t�@�C���ɏ����B
*************/
#include <windows.h>
#include "common.hpp"
#include "image.hpp"

/*D2Image�̃��b�p�[�N���X*/
class TipTile{

private:
	D2Image *IMG;

public:
	/**************
	�`��n�֐��̈����ɂ��Ẵ��[��
	double�^���W(�܂���Vec2�^)	:	�ڍ׍��W
	int�^���W(�܂���POINT�^)	:	�`�b�v�P�ʍ��W

	�`�b�v�F��{�ŏ��P�ʂ̐����`
	�^�C���F�`�b�v�ȏ�̃T�C�Y�̎l�p�`
	**************/
	inline int tipNo(int x, int y);		//�`�b�v�ԍ��Z�o

	inline void init(HWND hWnd, const char str[], int screenW, int screenH);			//������
	inline void set(int width, int height, int tipSize);	//BMP�f�[�^�̐ݒ�

	inline void printText(int posx, int posy, const char str[]);	//�e�L�X�g�̕\��

	inline void drawDot(int vecx, int vecy, int size, int TipNo);//��h�b�g�`��

	inline void drawTip(void);//�`�b�v�ꗗ�\��
	inline void drawTip(int posx, int posy, int TipNo);			//�`�b�v�̕`��
	inline void drawTip(double x, double y, int TipNo);			//�`�b�v�̕`��
	inline void drawTip(Vec2 vec, int TipNo);					//�`�b�v�̕`��
	inline void drawTip(Vec2 vec, int TipX, int TipY);			//�`�b�v�̕`��
	inline void drawTip(POINT pos, int TipNo);					//�`�b�v�̕`��

	inline void drawTip(int posx, int posy, int w, int h, int TipNo);			//�`�b�v�̊g��`��
	inline void drawTip(double x, double y, double w, double h, int TipNo);		//�`�b�v�̊g��`��

	inline void drawTile(int posx, int posy, int TileSize, int TileNo);				//�^�C���̕`��
	inline void drawTile(Vec2 vec, int TileSize, int TileNo);						//�^�C���̕`��
	inline void drawTile(Vec2 vec, int TileSize, double TileX, double TileY);				//�^�C���̕`��
	inline void drawTile(int posx, int posy, int TileW, int TileH, int TileNo);				//�^�C���̕`��
	inline void drawTile(int posx, int posy, int TileW, int TileH, int TileX, int TileY);	//�^�C���̕`��

	inline void drawTile(int posx, int posy, int w, int h, int TileNo, int TileW, int TileH);		//�^�C���̊g��`��
	inline void drawTile(double x, double y, int w, int h, int TileNo, int TileW, int TileH);		//�^�C���̊g��`��
	inline void drawTile(double x, double y, double w, double h, int TileNo, int TileW, int TileH);	//�^�C���̊g��`��
	inline void drawTile(Vec2 vec, int w, int h, int TileNo, int TileW, int TileH);					//�^�C���̊g��`��
	inline void drawTile(Vec2 vec, int w, int h, int TileX, int TileY, int TileW, int TileH);		//�^�C���̊g��`��
	inline void drawTile(Vec2 vec, int tosize, int TileNo, int fromsize);		//�^�C���̊g��`��(���������������`)
	inline void drawTile(Vec2 vec, double tosize, int TileNo, int fromsize);	//�^�C���̊g��`��(���������������`)

	inline void drawFillTip(int x, int y, int w, int h, int TipNo);		//�`�b�v�Ŕ͈͂𖄂߂�
	inline void drawFillTip(Vec2 vec, int w, int h, int TipNo);			//�`�b�v�Ŕ͈͂𖄂߂�

	inline void drawEnd(void);//�������̉摜��]��

	inline void setBasicColor(int red, int  green, int blue, int black, int white);	//��{�F�̃`�b�v�ԍ���ݒ�
	inline int getRed();		//�Ԃ̃`�b�v�ԍ��̎擾
	inline int getGreen();		//�΂̃`�b�v�ԍ��̎擾
	inline int getBlue();		//�̃`�b�v�ԍ��̎擾
	inline int getBlack();		//���̃`�b�v�ԍ��̎擾
	inline int getWhite();		//���̃`�b�v�ԍ��̎擾


private:
	int BMP_WIDTH;		//BMP�̕�
	int BMP_HEIGHT;		//BMP�E�̍���
	int MapTipSize;		//�`�b�v�̃T�C�Y
	int MapTipW;		//BMP��̉��}�b�v�`�b�v�̐�
	int MapTipH;		//BMP��̏c�}�b�v�`�b�v�̐�

	int redTipNo;		//�ԃ`�b�v�ԍ�
	int greenTipNo;		//�΃`�b�v�ԍ�
	int blueTipNo;		//�`�b�v�ԍ�
	int blackTipNo;		//���`�b�v�ԍ�
	int whiteTipNo;		//���`�b�v�ԍ�
};


int TipTile::tipNo(int x, int y){		//�`�b�v�ԍ��Z�o
	return y * MapTipW + x;
}
void TipTile::init(HWND hWnd, const char str[], int screenx, int screeny){
	IMG = new D2Image();
	IMG->init(hWnd, str, screenx, screeny);			//������
	BMP_WIDTH = 800;								//BMP�̕�
	BMP_HEIGHT = 600;								//BMP�̍���
	MapTipSize = 16;								//�`�b�v�̃T�C�Y
	MapTipW = BMP_WIDTH / MapTipSize;				//BMP��̉��}�b�v�`�b�v�̐�
	MapTipH = BMP_HEIGHT / MapTipSize;				//BMP��̏c�}�b�v�`�b�v�̐�
}

void TipTile::set(int width, int height, int tipSize){
	BMP_WIDTH = width;						//�E�B���h�E�̕�
	BMP_HEIGHT = height;					// �E�B���h�E�̍���
	MapTipSize = 16;						//�`�b�v�̃T�C�Y
	MapTipW = BMP_WIDTH / MapTipSize;	//BMP��̉��}�b�v�`�b�v�̐�
	MapTipH = BMP_HEIGHT / MapTipSize;	//BMP��̏c�}�b�v�`�b�v�̐�
}

void TipTile::printText(int posx, int posy, const char str[]){
	IMG->textToMem(
		posx * MapTipSize,	//�`���x
		posy * MapTipSize,	//�`���y
		str,				//�`�敶����
		RGB(100,200,50)
		);
}
void TipTile::drawDot(int vecx, int vecy, int size, int TipNo){//�h�b�g�̕`��
	IMG->bmpToMem(
		vecx, //�`���x
		vecy, //�`���y
		size, //��
		size, //��
		(TipNo % MapTipW) * MapTipSize, //�]����x
		(TipNo / MapTipW) * MapTipSize //�]����y
		);
}
void TipTile::drawTip(void)
{
	/*�}�b�v�`�b�v�ꗗ�̕\��*/
	IMG->bmpToMem();
	
}
void TipTile::drawTip(int posx, int posy, int TipNo){//�`�b�v�̕`��
	IMG->bmpToMem(
		posx * MapTipSize, //�`���x
		posy * MapTipSize, //�`���y
		MapTipSize, //��
		MapTipSize, //��
		(TipNo % MapTipW) * MapTipSize, //�]����x
		(TipNo / MapTipW) * MapTipSize //�]����y
		);
}
void TipTile::drawTip(double x, double y, int TipNo){//�`�b�v�̕`��
	IMG->bmpToMem(
		(int)x, //�`���x
		(int)y, //�`���y
		MapTipSize, //��
		MapTipSize, //��
		(TipNo % MapTipW) * MapTipSize, //�]����x
		(TipNo / MapTipW) * MapTipSize //�]����y
		);
}
void TipTile::drawTip(Vec2 vec, int TipNo){//�`�b�v�̕`��
	IMG->bmpToMem(
		(int)vec.x, //�`���x
		(int)vec.y, //�`���y
		MapTipSize, //��
		MapTipSize, //��
		(TipNo % MapTipW) * MapTipSize, //�]����x
		(TipNo / MapTipW) * MapTipSize //�]����y
		);
}
void TipTile::drawTip(Vec2 vec, int TipX, int TipY){//�`�b�v�̕`��
	IMG->bmpToMem(
		(int)vec.x, //�`���x
		(int)vec.y, //�`���y
		MapTipSize, //��
		MapTipSize, //��
		TipX * MapTipSize, //�]����x
		TipY * MapTipSize //�]����y
		);
}
void TipTile::drawTip(POINT pos, int TipNo){//�`�b�v�̕`��
	IMG->bmpToMem(
		pos.x * MapTipSize, //�`���x
		pos.y * MapTipSize, //�`���y
		MapTipSize, //��
		MapTipSize, //��
		(TipNo % MapTipW) * MapTipSize, //�]����x
		(TipNo / MapTipW) * MapTipSize //�]����y
		);
}
void TipTile::drawTip(int posx, int posy, int w, int h, int TipNo){//�`�b�v�̊g��`��
	IMG->bmpToMem(
		posx * MapTipSize, //�`���x
		posy * MapTipSize, //�`���y
		w * MapTipSize, //��
		h * MapTipSize, //��
		(TipNo % MapTipW) * MapTipSize, //�]����x
		(TipNo / MapTipW) * MapTipSize, //�]����y
		MapTipSize, //��
		MapTipSize //��
		);
}
void TipTile::drawTip(double x, double y, double w, double h, int TipNo){//�`�b�v�̊g��`��
	IMG->bmpToMem(
		(int)x, //�`���x
		(int)y, //�`���y
		(int)w, //��
		(int)h, //��
		(TipNo % MapTipW) * MapTipSize, //�]����x
		(TipNo / MapTipW) * MapTipSize, //�]����y
		MapTipSize, //��
		MapTipSize //��
		);
}
void TipTile::drawTile(int posx, int posy, int TileSize, int TileNo){//�^�C���̕`��
	IMG->bmpToMem(
		posx * MapTipSize, //�`���x
		posy * MapTipSize, //�`���y
		TileSize * MapTipSize, //��
		TileSize * MapTipSize, //��
		(TileNo % MapTipW) * MapTipSize, //�]����x
		(TileNo / MapTipW) * MapTipSize, //�]����y
		TileSize * MapTipSize, //��
		TileSize * MapTipSize //��
		);
}
void TipTile::drawTile(Vec2 vec, int TileSize, int TileNo){//�^�C���̕`��
	IMG->bmpToMem(
		(int)vec.x, //�`���x
		(int)vec.y, //�`���y
		TileSize * MapTipSize, //��
		TileSize * MapTipSize, //��
		(TileNo % MapTipW) * MapTipSize, //�]����x
		(TileNo / MapTipW) * MapTipSize, //�]����y
		TileSize * MapTipSize, //��
		TileSize * MapTipSize //��
		);
}
void TipTile::drawTile(Vec2 vec, int TileSize, double TileX, double TileY){//�^�C���̕`��
	IMG->bmpToMem(
		(int)vec.x, //�`���x
		(int)vec.y, //�`���y
		TileSize * MapTipSize, //��
		TileSize * MapTipSize, //��
		(int)TileX, //�]����x
		(int)TileY, //�]����y
		TileSize * MapTipSize, //��
		TileSize * MapTipSize //��
		);
}
void TipTile::drawTile(int posx, int posy, int TileW, int TileH, int TileNo){//�^�C���̕`��
	IMG->bmpToMem(
		posx * MapTipSize, //�`���x
		posy * MapTipSize, //�`���y
		TileW * MapTipSize, //��
		TileH * MapTipSize, //��
		(TileNo % MapTipW) * MapTipSize, //�]����x
		(TileNo / MapTipW) * MapTipSize, //�]����y
		TileW * MapTipSize, //��
		TileH * MapTipSize //��
		);
}
void TipTile::drawTile(int posx, int posy, int TileW, int TileH, int TileX, int TileY){//�^�C���̕`��
	IMG->bmpToMem(
		posx * MapTipSize, //�`���x
		posy * MapTipSize, //�`���y
		TileW * MapTipSize, //��
		TileH * MapTipSize, //��
		TileX * MapTipSize, //�]����x
		TileY * MapTipSize, //�]����y
		TileW * MapTipSize, //��
		TileH * MapTipSize //��
		);
}
void TipTile::drawTile(int posx, int posy, int w, int h, int TileNo, int TileW, int TileH){//�^�C���̊g��`��
	IMG->bmpToMem(
		posx * MapTipSize, //�`���x
		posy * MapTipSize, //�`���y
		w * MapTipSize, //��
		h * MapTipSize, //��
		(TileNo % MapTipW) * MapTipSize, //�]����x
		(TileNo / MapTipW) * MapTipSize, //�]����y
		TileW * MapTipSize, //��
		TileH * MapTipSize //��
		);
}
void TipTile::drawTile(double x, double y, double w, double h, int TileNo, int TileW, int TileH){//�^�C���̊g��`��
	IMG->bmpToMem(
		(int)x, //�`���x
		(int)y, //�`���y
		(int)w, //��
		(int)h, //��
		(TileNo % MapTipW) * MapTipSize, //�]����x
		(TileNo / MapTipW) * MapTipSize, //�]����y
		TileW * MapTipSize, //��
		TileH * MapTipSize //��
		);
}
void TipTile::drawTile(double x, double y, int w, int h, int TileNo, int TileW, int TileH){//�^�C���̊g��`��
	IMG->bmpToMem(
		(int)x, //�`���x
		(int)y, //�`���y
		w * MapTipSize, //��
		h * MapTipSize, //��
		(TileNo % MapTipW) * MapTipSize, //�]����x
		(TileNo / MapTipW) * MapTipSize, //�]����y
		TileW * MapTipSize, //��
		TileH * MapTipSize //��
		);
}
void TipTile::drawTile(Vec2 vec, int w, int h, int TileNo, int TileW, int TileH){//�^�C���̊g��`��
	IMG->bmpToMem(
		(int)vec.x, //�`���x
		(int)vec.y, //�`���y
		w * MapTipSize, //��
		h * MapTipSize, //��
		(TileNo % MapTipW) * MapTipSize, //�]����x
		(TileNo / MapTipW) * MapTipSize, //�]����y
		TileW * MapTipSize, //��
		TileH * MapTipSize //��
		);
}
void TipTile::drawTile(Vec2 vec, int w, int h, int TileX, int TileY, int TileW, int TileH){//�^�C���̊g��`��
	IMG->bmpToMem(
		(int)vec.x, //�`���x
		(int)vec.y, //�`���y
		w * MapTipSize, //��
		h * MapTipSize, //��
		TileX * MapTipSize, //�]����x
		TileY * MapTipSize, //�]����y
		TileW * MapTipSize, //��
		TileH * MapTipSize //��
		);
}
void TipTile::drawTile(Vec2 vec, int tosize, int TileNo, int fromsize){//�^�C���̊g��`��
	IMG->bmpToMem(
		(int)vec.x, //�`���x
		(int)vec.y, //�`���y
		tosize * MapTipSize, //��
		tosize * MapTipSize, //��
		(TileNo % MapTipW) * MapTipSize, //�]����x
		(TileNo / MapTipW) * MapTipSize, //�]����y
		fromsize * MapTipSize, //��
		fromsize * MapTipSize //��
		);
}
void TipTile::drawTile(Vec2 vec, double tosize, int TileNo, int fromsize){//�^�C���̊g��`��
	IMG->bmpToMem(
		(int)vec.x, //�`���x
		(int)vec.y, //�`���y
		(int)tosize, //��
		(int)tosize, //��
		(TileNo % MapTipW) * MapTipSize, //�]����x
		(TileNo / MapTipW) * MapTipSize, //�]����y
		fromsize * MapTipSize, //��
		fromsize * MapTipSize //��
		);
}

void TipTile::drawFillTip(int x, int y, int w, int h, int TipNo){		//�`�b�v�Ŕ͈͂𖄂߂�
	for(int j = y; j < y + h; j++){
		for(int i = x; i < x + w; i++){
			drawTip(i, j, TipNo);
		}
	}
}

void TipTile::drawFillTip(Vec2 vec, int w, int h, int TipNo){		//�`�b�v�Ŕ͈͂𖄂߂�
	for(int j = 0; j < h; j++){
		for(int i = 0; i < w; i++){
			drawTip(vec.x + i * MapTipSize, vec.y + j * MapTipSize, TipNo);
		}
	}
}

void TipTile::drawEnd(void){
	IMG->memToDis();
}


void TipTile::setBasicColor(int red, int  green, int blue, int black, int white){	//��{�F�̃`�b�v�ԍ���ݒ�
	redTipNo = red;
	greenTipNo = green;
	blueTipNo = blue;
	blackTipNo = black;
	whiteTipNo = white;
}
int TipTile::getRed(){			//�Ԃ̃`�b�v�ԍ��̎擾
	return redTipNo;
}
int TipTile::getGreen(){		//�΂̃`�b�v�ԍ��̎擾
	return greenTipNo;
}
int TipTile::getBlue(){			//�̃`�b�v�ԍ��̎擾
	return blueTipNo;
}
int TipTile::getBlack(){		//���̃`�b�v�ԍ��̎擾
	return blackTipNo;
}
int TipTile::getWhite(){		//���̃`�b�v�ԍ��̎擾
	return whiteTipNo;
}
#endif//INCLUDED_TIPTILE_HPP