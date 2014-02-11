//D2Image�N���Xver1.1 2012/8/20
#ifndef INCLUDED_IMAGE_HPP
#define INCLUDED_IMAGE_HPP

#include <windows.h>
#include "common.hpp"
#include <string.h>

// std:: ���ȗ��ł���悤��
using namespace std;

class D2Image
{
private:
	/*�f�B�X�v���C�T�C�Y*/
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	/*�]����f�B�X�v���C*/
	HWND hWnd;
	HDC hdc;
	/*�摜�p*/
	int bmpw, bmph;
	BITMAP bmp_info;
	HDC hdc_bmp;
	HBITMAP hBmp;
	/*�}�X�N�摜�p*/
	HDC hdc_msk;
	HBITMAP hMsk;
	/*��Ɨp*/
	HDC hdc_tmp;
	HBITMAP hTmp;
	/*���z���*/
	HDC hdc_mem;
	HBITMAP hMem;
public:
	D2Image();
	~D2Image();
	/*�w��r�b�g�}�b�v��ǂݍ���*/
	void init(HWND, string imagePath, int w, int h);				//�E�B���h�E�n���h��, �摜�p�X,WindowW,WindowH
	/*��������\��������*/
	void memToDis(void);							
	/*�r�b�g�}�b�v�S�̂�]��*/
	void bmpToMem();								
	/*�g��Ȃ��]��*/
	void bmpToMem(int,int,int,int,int,int);			//�]���悘,�]���悙,�摜��,�摜��,�]������,�]������
	/*�g�傠��]��*/
	void bmpToMem(int,int,int,int,int,int,int,int);	//�]���悘,�]���悙,�]����摜��,�]����摜��,�]������,�]������,�]�����摜��,�]����摜��
	/*�����o��*/
	void textToMem(int, int, const char[], COLORREF);//�����o��
private:
};




#endif//INCLUDED_IMAGE_HPP