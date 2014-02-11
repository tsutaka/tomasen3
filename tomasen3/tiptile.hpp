/************

	TipTileクラス
		（D2Image(image.hpp)クラスのラッパー）

	チップ単位での描画転送処理

************/

#ifndef INCLUDED_TIPTILE_HPP
#define INCLUDED_TIPTILE_HPP

/*************
教訓
・inline関数はヘッダファイルに定義も書かなくてはならない。
・他の関数は宣言のみヘッダファイルに書く。
*************/
#include <windows.h>
#include "common.hpp"
#include "image.hpp"

/*D2Imageのラッパークラス*/
class TipTile{

private:
	D2Image *IMG;

public:
	/**************
	描画系関数の引数についてのルール
	double型座標(またはVec2型)	:	詳細座標
	int型座標(またはPOINT型)	:	チップ単位座標

	チップ：基本最小単位の正方形
	タイル：チップ以上のサイズの四角形
	**************/
	inline int tipNo(int x, int y);		//チップ番号算出

	inline void init(HWND hWnd, const char str[], int screenW, int screenH);			//初期化
	inline void set(int width, int height, int tipSize);	//BMPデータの設定

	inline void printText(int posx, int posy, const char str[]);	//テキストの表示

	inline void drawDot(int vecx, int vecy, int size, int TipNo);//一ドット描画

	inline void drawTip(void);//チップ一覧表示
	inline void drawTip(int posx, int posy, int TipNo);			//チップの描画
	inline void drawTip(double x, double y, int TipNo);			//チップの描画
	inline void drawTip(Vec2 vec, int TipNo);					//チップの描画
	inline void drawTip(Vec2 vec, int TipX, int TipY);			//チップの描画
	inline void drawTip(POINT pos, int TipNo);					//チップの描画

	inline void drawTip(int posx, int posy, int w, int h, int TipNo);			//チップの拡大描画
	inline void drawTip(double x, double y, double w, double h, int TipNo);		//チップの拡大描画

	inline void drawTile(int posx, int posy, int TileSize, int TileNo);				//タイルの描画
	inline void drawTile(Vec2 vec, int TileSize, int TileNo);						//タイルの描画
	inline void drawTile(Vec2 vec, int TileSize, double TileX, double TileY);				//タイルの描画
	inline void drawTile(int posx, int posy, int TileW, int TileH, int TileNo);				//タイルの描画
	inline void drawTile(int posx, int posy, int TileW, int TileH, int TileX, int TileY);	//タイルの描画

	inline void drawTile(int posx, int posy, int w, int h, int TileNo, int TileW, int TileH);		//タイルの拡大描画
	inline void drawTile(double x, double y, int w, int h, int TileNo, int TileW, int TileH);		//タイルの拡大描画
	inline void drawTile(double x, double y, double w, double h, int TileNo, int TileW, int TileH);	//タイルの拡大描画
	inline void drawTile(Vec2 vec, int w, int h, int TileNo, int TileW, int TileH);					//タイルの拡大描画
	inline void drawTile(Vec2 vec, int w, int h, int TileX, int TileY, int TileW, int TileH);		//タイルの拡大描画
	inline void drawTile(Vec2 vec, int tosize, int TileNo, int fromsize);		//タイルの拡大描画(送り先も元も正方形)
	inline void drawTile(Vec2 vec, double tosize, int TileNo, int fromsize);	//タイルの拡大描画(送り先も元も正方形)

	inline void drawFillTip(int x, int y, int w, int h, int TipNo);		//チップで範囲を埋める
	inline void drawFillTip(Vec2 vec, int w, int h, int TipNo);			//チップで範囲を埋める

	inline void drawEnd(void);//メモリの画像を転送

	inline void setBasicColor(int red, int  green, int blue, int black, int white);	//基本色のチップ番号を設定
	inline int getRed();		//赤のチップ番号の取得
	inline int getGreen();		//緑のチップ番号の取得
	inline int getBlue();		//青のチップ番号の取得
	inline int getBlack();		//黒のチップ番号の取得
	inline int getWhite();		//白のチップ番号の取得


private:
	int BMP_WIDTH;		//BMPの幅
	int BMP_HEIGHT;		//BMPウの高さ
	int MapTipSize;		//チップのサイズ
	int MapTipW;		//BMP上の横マップチップの数
	int MapTipH;		//BMP上の縦マップチップの数

	int redTipNo;		//赤チップ番号
	int greenTipNo;		//緑チップ番号
	int blueTipNo;		//青チップ番号
	int blackTipNo;		//黒チップ番号
	int whiteTipNo;		//白チップ番号
};


int TipTile::tipNo(int x, int y){		//チップ番号算出
	return y * MapTipW + x;
}
void TipTile::init(HWND hWnd, const char str[], int screenx, int screeny){
	IMG = new D2Image();
	IMG->init(hWnd, str, screenx, screeny);			//初期化
	BMP_WIDTH = 800;								//BMPの幅
	BMP_HEIGHT = 600;								//BMPの高さ
	MapTipSize = 16;								//チップのサイズ
	MapTipW = BMP_WIDTH / MapTipSize;				//BMP上の横マップチップの数
	MapTipH = BMP_HEIGHT / MapTipSize;				//BMP上の縦マップチップの数
}

void TipTile::set(int width, int height, int tipSize){
	BMP_WIDTH = width;						//ウィンドウの幅
	BMP_HEIGHT = height;					// ウィンドウの高さ
	MapTipSize = 16;						//チップのサイズ
	MapTipW = BMP_WIDTH / MapTipSize;	//BMP上の横マップチップの数
	MapTipH = BMP_HEIGHT / MapTipSize;	//BMP上の縦マップチップの数
}

void TipTile::printText(int posx, int posy, const char str[]){
	IMG->textToMem(
		posx * MapTipSize,	//描画先x
		posy * MapTipSize,	//描画先y
		str,				//描画文字列
		RGB(100,200,50)
		);
}
void TipTile::drawDot(int vecx, int vecy, int size, int TipNo){//ドットの描画
	IMG->bmpToMem(
		vecx, //描画先x
		vecy, //描画先y
		size, //幅
		size, //高
		(TipNo % MapTipW) * MapTipSize, //転送元x
		(TipNo / MapTipW) * MapTipSize //転送元y
		);
}
void TipTile::drawTip(void)
{
	/*マップチップ一覧の表示*/
	IMG->bmpToMem();
	
}
void TipTile::drawTip(int posx, int posy, int TipNo){//チップの描画
	IMG->bmpToMem(
		posx * MapTipSize, //描画先x
		posy * MapTipSize, //描画先y
		MapTipSize, //幅
		MapTipSize, //高
		(TipNo % MapTipW) * MapTipSize, //転送元x
		(TipNo / MapTipW) * MapTipSize //転送元y
		);
}
void TipTile::drawTip(double x, double y, int TipNo){//チップの描画
	IMG->bmpToMem(
		(int)x, //描画先x
		(int)y, //描画先y
		MapTipSize, //幅
		MapTipSize, //高
		(TipNo % MapTipW) * MapTipSize, //転送元x
		(TipNo / MapTipW) * MapTipSize //転送元y
		);
}
void TipTile::drawTip(Vec2 vec, int TipNo){//チップの描画
	IMG->bmpToMem(
		(int)vec.x, //描画先x
		(int)vec.y, //描画先y
		MapTipSize, //幅
		MapTipSize, //高
		(TipNo % MapTipW) * MapTipSize, //転送元x
		(TipNo / MapTipW) * MapTipSize //転送元y
		);
}
void TipTile::drawTip(Vec2 vec, int TipX, int TipY){//チップの描画
	IMG->bmpToMem(
		(int)vec.x, //描画先x
		(int)vec.y, //描画先y
		MapTipSize, //幅
		MapTipSize, //高
		TipX * MapTipSize, //転送元x
		TipY * MapTipSize //転送元y
		);
}
void TipTile::drawTip(POINT pos, int TipNo){//チップの描画
	IMG->bmpToMem(
		pos.x * MapTipSize, //描画先x
		pos.y * MapTipSize, //描画先y
		MapTipSize, //幅
		MapTipSize, //高
		(TipNo % MapTipW) * MapTipSize, //転送元x
		(TipNo / MapTipW) * MapTipSize //転送元y
		);
}
void TipTile::drawTip(int posx, int posy, int w, int h, int TipNo){//チップの拡大描画
	IMG->bmpToMem(
		posx * MapTipSize, //描画先x
		posy * MapTipSize, //描画先y
		w * MapTipSize, //幅
		h * MapTipSize, //高
		(TipNo % MapTipW) * MapTipSize, //転送元x
		(TipNo / MapTipW) * MapTipSize, //転送元y
		MapTipSize, //幅
		MapTipSize //高
		);
}
void TipTile::drawTip(double x, double y, double w, double h, int TipNo){//チップの拡大描画
	IMG->bmpToMem(
		(int)x, //描画先x
		(int)y, //描画先y
		(int)w, //幅
		(int)h, //高
		(TipNo % MapTipW) * MapTipSize, //転送元x
		(TipNo / MapTipW) * MapTipSize, //転送元y
		MapTipSize, //幅
		MapTipSize //高
		);
}
void TipTile::drawTile(int posx, int posy, int TileSize, int TileNo){//タイルの描画
	IMG->bmpToMem(
		posx * MapTipSize, //描画先x
		posy * MapTipSize, //描画先y
		TileSize * MapTipSize, //幅
		TileSize * MapTipSize, //高
		(TileNo % MapTipW) * MapTipSize, //転送元x
		(TileNo / MapTipW) * MapTipSize, //転送元y
		TileSize * MapTipSize, //幅
		TileSize * MapTipSize //高
		);
}
void TipTile::drawTile(Vec2 vec, int TileSize, int TileNo){//タイルの描画
	IMG->bmpToMem(
		(int)vec.x, //描画先x
		(int)vec.y, //描画先y
		TileSize * MapTipSize, //幅
		TileSize * MapTipSize, //高
		(TileNo % MapTipW) * MapTipSize, //転送元x
		(TileNo / MapTipW) * MapTipSize, //転送元y
		TileSize * MapTipSize, //幅
		TileSize * MapTipSize //高
		);
}
void TipTile::drawTile(Vec2 vec, int TileSize, double TileX, double TileY){//タイルの描画
	IMG->bmpToMem(
		(int)vec.x, //描画先x
		(int)vec.y, //描画先y
		TileSize * MapTipSize, //幅
		TileSize * MapTipSize, //高
		(int)TileX, //転送元x
		(int)TileY, //転送元y
		TileSize * MapTipSize, //幅
		TileSize * MapTipSize //高
		);
}
void TipTile::drawTile(int posx, int posy, int TileW, int TileH, int TileNo){//タイルの描画
	IMG->bmpToMem(
		posx * MapTipSize, //描画先x
		posy * MapTipSize, //描画先y
		TileW * MapTipSize, //幅
		TileH * MapTipSize, //高
		(TileNo % MapTipW) * MapTipSize, //転送元x
		(TileNo / MapTipW) * MapTipSize, //転送元y
		TileW * MapTipSize, //幅
		TileH * MapTipSize //高
		);
}
void TipTile::drawTile(int posx, int posy, int TileW, int TileH, int TileX, int TileY){//タイルの描画
	IMG->bmpToMem(
		posx * MapTipSize, //描画先x
		posy * MapTipSize, //描画先y
		TileW * MapTipSize, //幅
		TileH * MapTipSize, //高
		TileX * MapTipSize, //転送元x
		TileY * MapTipSize, //転送元y
		TileW * MapTipSize, //幅
		TileH * MapTipSize //高
		);
}
void TipTile::drawTile(int posx, int posy, int w, int h, int TileNo, int TileW, int TileH){//タイルの拡大描画
	IMG->bmpToMem(
		posx * MapTipSize, //描画先x
		posy * MapTipSize, //描画先y
		w * MapTipSize, //幅
		h * MapTipSize, //高
		(TileNo % MapTipW) * MapTipSize, //転送元x
		(TileNo / MapTipW) * MapTipSize, //転送元y
		TileW * MapTipSize, //幅
		TileH * MapTipSize //高
		);
}
void TipTile::drawTile(double x, double y, double w, double h, int TileNo, int TileW, int TileH){//タイルの拡大描画
	IMG->bmpToMem(
		(int)x, //描画先x
		(int)y, //描画先y
		(int)w, //幅
		(int)h, //高
		(TileNo % MapTipW) * MapTipSize, //転送元x
		(TileNo / MapTipW) * MapTipSize, //転送元y
		TileW * MapTipSize, //幅
		TileH * MapTipSize //高
		);
}
void TipTile::drawTile(double x, double y, int w, int h, int TileNo, int TileW, int TileH){//タイルの拡大描画
	IMG->bmpToMem(
		(int)x, //描画先x
		(int)y, //描画先y
		w * MapTipSize, //幅
		h * MapTipSize, //高
		(TileNo % MapTipW) * MapTipSize, //転送元x
		(TileNo / MapTipW) * MapTipSize, //転送元y
		TileW * MapTipSize, //幅
		TileH * MapTipSize //高
		);
}
void TipTile::drawTile(Vec2 vec, int w, int h, int TileNo, int TileW, int TileH){//タイルの拡大描画
	IMG->bmpToMem(
		(int)vec.x, //描画先x
		(int)vec.y, //描画先y
		w * MapTipSize, //幅
		h * MapTipSize, //高
		(TileNo % MapTipW) * MapTipSize, //転送元x
		(TileNo / MapTipW) * MapTipSize, //転送元y
		TileW * MapTipSize, //幅
		TileH * MapTipSize //高
		);
}
void TipTile::drawTile(Vec2 vec, int w, int h, int TileX, int TileY, int TileW, int TileH){//タイルの拡大描画
	IMG->bmpToMem(
		(int)vec.x, //描画先x
		(int)vec.y, //描画先y
		w * MapTipSize, //幅
		h * MapTipSize, //高
		TileX * MapTipSize, //転送元x
		TileY * MapTipSize, //転送元y
		TileW * MapTipSize, //幅
		TileH * MapTipSize //高
		);
}
void TipTile::drawTile(Vec2 vec, int tosize, int TileNo, int fromsize){//タイルの拡大描画
	IMG->bmpToMem(
		(int)vec.x, //描画先x
		(int)vec.y, //描画先y
		tosize * MapTipSize, //幅
		tosize * MapTipSize, //高
		(TileNo % MapTipW) * MapTipSize, //転送元x
		(TileNo / MapTipW) * MapTipSize, //転送元y
		fromsize * MapTipSize, //幅
		fromsize * MapTipSize //高
		);
}
void TipTile::drawTile(Vec2 vec, double tosize, int TileNo, int fromsize){//タイルの拡大描画
	IMG->bmpToMem(
		(int)vec.x, //描画先x
		(int)vec.y, //描画先y
		(int)tosize, //幅
		(int)tosize, //高
		(TileNo % MapTipW) * MapTipSize, //転送元x
		(TileNo / MapTipW) * MapTipSize, //転送元y
		fromsize * MapTipSize, //幅
		fromsize * MapTipSize //高
		);
}

void TipTile::drawFillTip(int x, int y, int w, int h, int TipNo){		//チップで範囲を埋める
	for(int j = y; j < y + h; j++){
		for(int i = x; i < x + w; i++){
			drawTip(i, j, TipNo);
		}
	}
}

void TipTile::drawFillTip(Vec2 vec, int w, int h, int TipNo){		//チップで範囲を埋める
	for(int j = 0; j < h; j++){
		for(int i = 0; i < w; i++){
			drawTip(vec.x + i * MapTipSize, vec.y + j * MapTipSize, TipNo);
		}
	}
}

void TipTile::drawEnd(void){
	IMG->memToDis();
}


void TipTile::setBasicColor(int red, int  green, int blue, int black, int white){	//基本色のチップ番号を設定
	redTipNo = red;
	greenTipNo = green;
	blueTipNo = blue;
	blackTipNo = black;
	whiteTipNo = white;
}
int TipTile::getRed(){			//赤のチップ番号の取得
	return redTipNo;
}
int TipTile::getGreen(){		//緑のチップ番号の取得
	return greenTipNo;
}
int TipTile::getBlue(){			//青のチップ番号の取得
	return blueTipNo;
}
int TipTile::getBlack(){		//黒のチップ番号の取得
	return blackTipNo;
}
int TipTile::getWhite(){		//白のチップ番号の取得
	return whiteTipNo;
}
#endif//INCLUDED_TIPTILE_HPP