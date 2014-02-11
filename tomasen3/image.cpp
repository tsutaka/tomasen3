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
	/*ディスプレイサイズ*/
	SCREEN_WIDTH = x;
	SCREEN_HEIGHT = y;
	/*画像の読み込み*/
	hWnd = _hWnd;
	hdc = GetDC(hWnd);
	hBmp = (HBITMAP)LoadImage(
		NULL,//インスタンスハンドル
		TEXT(imagePath.c_str()),//イメージの名前
		IMAGE_BITMAP,//イメージタイプ
		0,//幅
		0,//高さ
		LR_LOADFROMFILE);//ロードオプション
	if( hBmp == NULL )
	{
		MessageBox(
			NULL, TEXT("ビットマップのロードに失敗しました"), TEXT("エラー"),
			MB_OK | MB_ICONWARNING
		);
	}
	GetObject(hBmp, (int)sizeof(bmp_info), &bmp_info);
	bmpw = bmp_info.bmWidth;
	bmph = bmp_info.bmHeight;
	hdc_bmp = CreateCompatibleDC(hdc);//互換性のあるDCを取得
	SelectObject(hdc_bmp, hBmp);//MDCにビットマップをセット
	SetBkColor(hdc_bmp, (COLORREF)RGB(255, 0, 255));//背景色を設定
	SetTextColor(hdc_bmp , (COLORREF)RGB(0, 0, 0));//文字色を黒に設定

	/*仮想デバイスコンテキスト*/
	hdc_mem = CreateCompatibleDC(hdc);//互換性のあるDCを取得
	hMem = CreateCompatibleBitmap(hdc_bmp, 
		SCREEN_WIDTH, SCREEN_HEIGHT);//ビットマップを作成
	SelectObject(hdc_mem, hMem);//MDCにビットマップをセット
	SetBkColor(hdc_bmp, (COLORREF)RGB(255, 0, 255));//背景色を設定
	SetTextColor(hdc_bmp , (COLORREF)RGB(0, 0, 0));//文字色を黒に設定

	/*マスク画像*/
	hdc_msk = CreateCompatibleDC(hdc);//互換性のあるDCを取得
	hMsk = CreateCompatibleBitmap(hdc_msk, 
		SCREEN_WIDTH, SCREEN_HEIGHT);//ビットマップを作成
	SelectObject(hdc_msk, hMsk);//MDCにビットマップをセット
	SetBkColor(hdc_bmp, (COLORREF)RGB(255, 0, 255));//背景色を設定
	SetTextColor(hdc_bmp , (COLORREF)RGB(0, 0, 0));//文字色を黒に設定
	/*白黒ビットマップにする　透過部分:白*/
	BitBlt(hdc_msk, //転送先
		0, 0, //転送先座標
		bmpw, bmph, //幅と高さ
		hdc_bmp, //転送元
		0, 0, //転送元座標
		SRCCOPY);//ラスタオペレーション

	/*作業用画像*/
	hdc_tmp = CreateCompatibleDC(hdc);//互換性のあるDCを取得
	hTmp = CreateCompatibleBitmap(hdc_tmp, 
		SCREEN_WIDTH, SCREEN_HEIGHT);//ビットマップを作成
	SelectObject(hdc_tmp, hTmp);//MDCにビットマップをセット
	SetBkColor(hdc_bmp, (COLORREF)RGB(255, 0, 255));//背景色を設定
	SetTextColor(hdc_bmp , (COLORREF)RGB(0, 0, 0));//文字色を黒に設定
	/*マスク画像の白黒反転を作成*/
	BitBlt(hdc_tmp, //転送先
		0, 0, //転送先座標
		bmpw, bmph, //幅と高さ
		hdc_msk, //転送元
		0, 0, //転送元座標
		NOTSRCCOPY);//ラスタオペレーション

	SetBkColor(hdc_bmp, (COLORREF)RGB(0xff, 0xff, 0xff));//背景色を設定
	SetBkColor(hdc_msk, (COLORREF)RGB(0xff, 0xff, 0xff));//背景色を設定
	SetBkColor(hdc_tmp, (COLORREF)RGB(0xff, 0xff, 0xff));//背景色を設定
	SetBkColor(hdc_mem, (COLORREF)RGB(0xff, 0xff, 0xff));//背景色を設定
	SetTextColor(hdc_bmp, (COLORREF)RGB(0, 0, 0));//テキスト色を設定
	SetTextColor(hdc_msk, (COLORREF)RGB(0, 0, 0));//テキスト色を設定
	SetTextColor(hdc_tmp, (COLORREF)RGB(0, 0, 0));//テキスト色を設定
	SetTextColor(hdc_mem, (COLORREF)RGB(0, 0, 0));//テキスト色を設定

	/*元画像の加工　透過部分：黒*/
	BitBlt(hdc_bmp, //転送先
		0, 0, //転送先座標
		bmpw, bmph, //幅と高さ
		hdc_tmp, //転送元
		0, 0, //転送元座標
		SRCAND);//ラスタオペレーション


	ReleaseDC(hWnd, hdc);

}
void D2Image::memToDis(){
	hdc = GetDC(hWnd);
	/*仮想画面をディスプレイへ転送*/
	BitBlt(hdc, //転送先
		0, 0, //転送先座標
		bmpw, bmph, //幅と高さ
		hdc_mem, //転送元
		0, 0, //転送元座標
		SRCCOPY);//ラスタオペレーション
	ReleaseDC(hWnd, hdc);
}
void D2Image::bmpToMem(){//拡大なし

	/*マスク画像と仮想画面をAND　転送したい画像部分：黒*/
	BitBlt(hdc_mem, //転送先
		0, 0, //転送先座標
		bmpw, bmph, //幅と高さ
		hdc_msk, //転送元
		0, 0, //転送元座標
		SRCAND);//ラスタオペレーション
	
	/*元画像と仮想画面をOR*/
	BitBlt(hdc_mem, //転送先
		0, 0, //転送先座標
		bmpw, bmph, //転送先幅と高さ
		hdc_bmp, //転送元
		0, 0, //転送元座標
		SRCPAINT);//ラスタオペレーション
}
void D2Image::bmpToMem(int tox, int toy, int tow, int toh, int fromx, int fromy){//拡大なし

	/*マスク画像と仮想画面をAND　転送したい画像部分：黒*/
	BitBlt(hdc_mem, //転送先
		tox, toy, //転送先座標
		tow, toh, //幅と高さ
		hdc_msk, //転送元
		fromx, fromy, //転送元座標
		SRCAND);//ラスタオペレーション
	
	/*元画像と仮想画面をOR*/
	BitBlt(hdc_mem, //転送先
		tox, toy, //転送先座標
		tow, toh, //転送先幅と高さ
		hdc_bmp, //転送元
		fromx, fromy, //転送元座標
		SRCPAINT);//ラスタオペレーション
}
void D2Image::bmpToMem(int tox, int toy, int tow, int toh, 
					   int fromx, int fromy, int fromw, int fromh){//拡大ありコピー

	/*マスク画像と仮想画面をAND　転送したい画像部分：黒*/
	StretchBlt(hdc_mem, //転送先
		tox, toy, //転送先座標
		tow, toh, //幅と高さ
		hdc_msk, //転送元
		fromx, fromy, //転送元座標
		fromw, fromh,//転送元幅と高さ
		SRCAND);//ラスタオペレーション
	
	/*元画像と仮想画面をOR*/
	StretchBlt(hdc_mem, //転送先
		tox, toy, //転送先座標
		tow, toh, //転送先幅と高さ
		hdc_bmp, //転送元
		fromx, fromy, //転送元座標
		fromw, fromh,//転送元幅と高さ
		SRCPAINT);//ラスタオペレーション
}
void D2Image::textToMem(int x, int y, const char* text,COLORREF color){
	SetTextColor(hdc_mem, color);//テキスト色を設定
	SetBkMode(hdc_mem, TRANSPARENT); //背景透過
	TextOut(hdc_mem, 
		x,
		y,
		(LPCTSTR)text,
		strlen(text));
	SetTextColor(hdc_mem, (COLORREF)RGB(0, 0, 0));//テキスト色を設定


}