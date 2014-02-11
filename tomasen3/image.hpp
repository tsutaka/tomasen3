//D2Imageクラスver1.1 2012/8/20
#ifndef INCLUDED_IMAGE_HPP
#define INCLUDED_IMAGE_HPP

#include <windows.h>
#include "common.hpp"
#include <string.h>

// std:: を省略できるように
using namespace std;

class D2Image
{
private:
	/*ディスプレイサイズ*/
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	/*転送先ディスプレイ*/
	HWND hWnd;
	HDC hdc;
	/*画像用*/
	int bmpw, bmph;
	BITMAP bmp_info;
	HDC hdc_bmp;
	HBITMAP hBmp;
	/*マスク画像用*/
	HDC hdc_msk;
	HBITMAP hMsk;
	/*作業用*/
	HDC hdc_tmp;
	HBITMAP hTmp;
	/*仮想画面*/
	HDC hdc_mem;
	HBITMAP hMem;
public:
	D2Image();
	~D2Image();
	/*指定ビットマップを読み込み*/
	void init(HWND, string imagePath, int w, int h);				//ウィンドウハンドル, 画像パス,WindowW,WindowH
	/*メモリを表示させる*/
	void memToDis(void);							
	/*ビットマップ全体を転送*/
	void bmpToMem();								
	/*拡大なし転送*/
	void bmpToMem(int,int,int,int,int,int);			//転送先ｘ,転送先ｙ,画像幅,画像高,転送元ｘ,転送元ｙ
	/*拡大あり転送*/
	void bmpToMem(int,int,int,int,int,int,int,int);	//転送先ｘ,転送先ｙ,転送先画像幅,転送先画像高,転送元ｘ,転送元ｙ,転送元画像幅,転送先画像高
	/*文字出力*/
	void textToMem(int, int, const char[], COLORREF);//文字出力
private:
};




#endif//INCLUDED_IMAGE_HPP