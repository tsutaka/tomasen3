#include "image.hpp"



D2Image::D2Image()
{
}
D2Image::~D2Image()
{
	DeleteObject(hMem);
	DeleteDC(hdc_mem);
	DeleteObject(hTmp);
	DeleteDC(hdc_tmp);
	DeleteObject(hMsk);
	DeleteDC(hdc_msk);
	DeleteObject(hBmp);
	DeleteDC(hdc_bmp);
	PostQuitMessage(0);
}
void D2Image::init(HWND _hWnd, string imagePath, int x, int y){
	/*�f�B�X�v���C�T�C�Y*/
	SCREEN_WIDTH = x;
	SCREEN_HEIGHT = y;
	/*�摜�̓ǂݍ���*/
	hWnd = _hWnd;
	hdc = GetDC(hWnd);
	hBmp = (HBITMAP)LoadImage(
		NULL,//�C���X�^���X�n���h��
		TEXT(imagePath.c_str()),//�C���[�W�̖��O
		IMAGE_BITMAP,//�C���[�W�^�C�v
		0,//��
		0,//����
		LR_LOADFROMFILE);//���[�h�I�v�V����
	if( hBmp == NULL )
	{
		MessageBox(
			NULL, TEXT("�r�b�g�}�b�v�̃��[�h�Ɏ��s���܂���"), TEXT("�G���["),
			MB_OK | MB_ICONWARNING
		);
	}
	GetObject(hBmp, (int)sizeof(bmp_info), &bmp_info);
	bmpw = bmp_info.bmWidth;
	bmph = bmp_info.bmHeight;
	hdc_bmp = CreateCompatibleDC(hdc);//�݊����̂���DC���擾
	SelectObject(hdc_bmp, hBmp);//MDC�Ƀr�b�g�}�b�v���Z�b�g
	SetBkColor(hdc_bmp, (COLORREF)RGB(255, 0, 255));//�w�i�F��ݒ�
	SetTextColor(hdc_bmp , (COLORREF)RGB(0, 0, 0));//�����F�����ɐݒ�

	/*���z�f�o�C�X�R���e�L�X�g*/
	hdc_mem = CreateCompatibleDC(hdc);//�݊����̂���DC���擾
	hMem = CreateCompatibleBitmap(hdc_bmp, 
		SCREEN_WIDTH, SCREEN_HEIGHT);//�r�b�g�}�b�v���쐬
	SelectObject(hdc_mem, hMem);//MDC�Ƀr�b�g�}�b�v���Z�b�g
	SetBkColor(hdc_bmp, (COLORREF)RGB(255, 0, 255));//�w�i�F��ݒ�
	SetTextColor(hdc_bmp , (COLORREF)RGB(0, 0, 0));//�����F�����ɐݒ�

	/*�}�X�N�摜*/
	hdc_msk = CreateCompatibleDC(hdc);//�݊����̂���DC���擾
	hMsk = CreateCompatibleBitmap(hdc_msk, 
		SCREEN_WIDTH, SCREEN_HEIGHT);//�r�b�g�}�b�v���쐬
	SelectObject(hdc_msk, hMsk);//MDC�Ƀr�b�g�}�b�v���Z�b�g
	SetBkColor(hdc_bmp, (COLORREF)RGB(255, 0, 255));//�w�i�F��ݒ�
	SetTextColor(hdc_bmp , (COLORREF)RGB(0, 0, 0));//�����F�����ɐݒ�
	/*�����r�b�g�}�b�v�ɂ���@���ߕ���:��*/
	BitBlt(hdc_msk, //�]����
		0, 0, //�]������W
		bmpw, bmph, //���ƍ���
		hdc_bmp, //�]����
		0, 0, //�]�������W
		SRCCOPY);//���X�^�I�y���[�V����

	/*��Ɨp�摜*/
	hdc_tmp = CreateCompatibleDC(hdc);//�݊����̂���DC���擾
	hTmp = CreateCompatibleBitmap(hdc_tmp, 
		SCREEN_WIDTH, SCREEN_HEIGHT);//�r�b�g�}�b�v���쐬
	SelectObject(hdc_tmp, hTmp);//MDC�Ƀr�b�g�}�b�v���Z�b�g
	SetBkColor(hdc_bmp, (COLORREF)RGB(255, 0, 255));//�w�i�F��ݒ�
	SetTextColor(hdc_bmp , (COLORREF)RGB(0, 0, 0));//�����F�����ɐݒ�
	/*�}�X�N�摜�̔������]���쐬*/
	BitBlt(hdc_tmp, //�]����
		0, 0, //�]������W
		bmpw, bmph, //���ƍ���
		hdc_msk, //�]����
		0, 0, //�]�������W
		NOTSRCCOPY);//���X�^�I�y���[�V����

	SetBkColor(hdc_bmp, (COLORREF)RGB(0xff, 0xff, 0xff));//�w�i�F��ݒ�
	SetBkColor(hdc_msk, (COLORREF)RGB(0xff, 0xff, 0xff));//�w�i�F��ݒ�
	SetBkColor(hdc_tmp, (COLORREF)RGB(0xff, 0xff, 0xff));//�w�i�F��ݒ�
	SetBkColor(hdc_mem, (COLORREF)RGB(0xff, 0xff, 0xff));//�w�i�F��ݒ�
	SetTextColor(hdc_bmp, (COLORREF)RGB(0, 0, 0));//�e�L�X�g�F��ݒ�
	SetTextColor(hdc_msk, (COLORREF)RGB(0, 0, 0));//�e�L�X�g�F��ݒ�
	SetTextColor(hdc_tmp, (COLORREF)RGB(0, 0, 0));//�e�L�X�g�F��ݒ�
	SetTextColor(hdc_mem, (COLORREF)RGB(0, 0, 0));//�e�L�X�g�F��ݒ�

	/*���摜�̉��H�@���ߕ����F��*/
	BitBlt(hdc_bmp, //�]����
		0, 0, //�]������W
		bmpw, bmph, //���ƍ���
		hdc_tmp, //�]����
		0, 0, //�]�������W
		SRCAND);//���X�^�I�y���[�V����


	ReleaseDC(hWnd, hdc);

}
void D2Image::memToDis(){
	hdc = GetDC(hWnd);
	/*���z��ʂ��f�B�X�v���C�֓]��*/
	BitBlt(hdc, //�]����
		0, 0, //�]������W
		bmpw, bmph, //���ƍ���
		hdc_mem, //�]����
		0, 0, //�]�������W
		SRCCOPY);//���X�^�I�y���[�V����
	ReleaseDC(hWnd, hdc);
}
void D2Image::bmpToMem(){//�g��Ȃ�

	/*�}�X�N�摜�Ɖ��z��ʂ�AND�@�]���������摜�����F��*/
	BitBlt(hdc_mem, //�]����
		0, 0, //�]������W
		bmpw, bmph, //���ƍ���
		hdc_msk, //�]����
		0, 0, //�]�������W
		SRCAND);//���X�^�I�y���[�V����
	
	/*���摜�Ɖ��z��ʂ�OR*/
	BitBlt(hdc_mem, //�]����
		0, 0, //�]������W
		bmpw, bmph, //�]���敝�ƍ���
		hdc_bmp, //�]����
		0, 0, //�]�������W
		SRCPAINT);//���X�^�I�y���[�V����
}
void D2Image::bmpToMem(int tox, int toy, int tow, int toh, int fromx, int fromy){//�g��Ȃ�

	/*�}�X�N�摜�Ɖ��z��ʂ�AND�@�]���������摜�����F��*/
	BitBlt(hdc_mem, //�]����
		tox, toy, //�]������W
		tow, toh, //���ƍ���
		hdc_msk, //�]����
		fromx, fromy, //�]�������W
		SRCAND);//���X�^�I�y���[�V����
	
	/*���摜�Ɖ��z��ʂ�OR*/
	BitBlt(hdc_mem, //�]����
		tox, toy, //�]������W
		tow, toh, //�]���敝�ƍ���
		hdc_bmp, //�]����
		fromx, fromy, //�]�������W
		SRCPAINT);//���X�^�I�y���[�V����
}
void D2Image::bmpToMem(int tox, int toy, int tow, int toh, 
					   int fromx, int fromy, int fromw, int fromh){//�g�傠��R�s�[

	/*�}�X�N�摜�Ɖ��z��ʂ�AND�@�]���������摜�����F��*/
	StretchBlt(hdc_mem, //�]����
		tox, toy, //�]������W
		tow, toh, //���ƍ���
		hdc_msk, //�]����
		fromx, fromy, //�]�������W
		fromw, fromh,//�]�������ƍ���
		SRCAND);//���X�^�I�y���[�V����
	
	/*���摜�Ɖ��z��ʂ�OR*/
	StretchBlt(hdc_mem, //�]����
		tox, toy, //�]������W
		tow, toh, //�]���敝�ƍ���
		hdc_bmp, //�]����
		fromx, fromy, //�]�������W
		fromw, fromh,//�]�������ƍ���
		SRCPAINT);//���X�^�I�y���[�V����
}
void D2Image::textToMem(int x, int y, const char* text,COLORREF color){
	SetTextColor(hdc_mem, color);//�e�L�X�g�F��ݒ�
	SetBkMode(hdc_mem, TRANSPARENT); //�w�i����
	TextOut(hdc_mem, 
		x,
		y,
		(LPCTSTR)text,
		strlen(text));
	SetTextColor(hdc_mem, (COLORREF)RGB(0, 0, 0));//�e�L�X�g�F��ݒ�


}