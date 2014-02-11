#include <windows.h>
#include <string.h>
#include <stdio.h>

#include "main.hpp"
#include "common.hpp"
#include "tomasen.hpp"



int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE hPrevInst,
				   LPSTR lpsCmdLine, int nCmdShow)
{
	MSG msg;
	BOOL bRet;



	if (!InitApp(hCurInst))
		return FALSE;
	if (!InitInstance(hCurInst, nCmdShow)) 
		return FALSE;



	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
		if (bRet == -1) {
			break;
		} else {
			TranslateMessage(&msg);//���b�Z�[�W��K�؂ɕϊ�
			DispatchMessage(&msg);//�E�B���h�E�v���V�[�W���Ƀ��b�Z�[�W�𑗐M
		}
	}
	return (int)msg.wParam;//�v���O�������I��
}

//�E�B���h�E�E�N���X�̓o�^

ATOM InitApp(HINSTANCE hInst)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;	//�v���V�[�W����
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;//�C���X�^���X
	/*wc.hIcon = (HICON)LoadImage(NULL,
		MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON,
		0,
		0,
		LR_DEFAULTSIZE | LR_SHARED);*/
	wc.hIcon = LoadIcon(hInst , TEXT("ICON1"));
	wc.hCursor = (HCURSOR)LoadImage(NULL,
		MAKEINTRESOURCE(IDC_ARROW),
		IMAGE_CURSOR,
		0,
		0,
		LR_DEFAULTSIZE | LR_SHARED);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;	//���j���[��
	wc.lpszClassName = (LPCSTR)szClassName;
	wc.hIconSm = (HICON)LoadImage(NULL,
		MAKEINTRESOURCE(IDI_APPLICATION),
		IMAGE_ICON,
		0,
		0,
		LR_DEFAULTSIZE | LR_SHARED);

	return (RegisterClassEx(&wc));
}

//�E�B���h�E�̐���

BOOL InitInstance(HINSTANCE hInst, int nCmdShow)
{
	HWND hWnd;
	DEVMODE    devMode;
	TCHAR      szAppName[] = TEXT("Tomasen2");
	/*�X���b�h�p*/
	DWORD dwID;

	hWnd = CreateWindowEx(
		WS_EX_LEFT,//WS_EX_TOPMOST,//�g���E�B���h�E�N���X�@�őO�ʕ\��
		szClassName,//�E�B���h�E�N���X��
		"Tomasen2", //�^�C�g���o�[�ɂ��̖��O���\�������
		WS_VISIBLE | WS_POPUP, //�E�B���h�E�̎��
		0,	//�w���W
		0,	//�x���W
		SCREEN_WIDTH,	//��
		SCREEN_HEIGHT,	//����
		NULL, //�e�E�B���h�E�̃n���h���A�e�����Ƃ���NULL
		NULL, //���j���[�n���h���A�N���X���j���[���g���Ƃ���NULL
		hInst, //�C���X�^���X�n���h��
		NULL);

	hWND = hWnd;//�O���[�o���ϐ��ɕێ�
	if (!hWnd) return FALSE;

	devMode.dmSize       = sizeof(DEVMODE);
	devMode.dmFields     = DM_PELSWIDTH | DM_PELSHEIGHT;
	devMode.dmPelsWidth  = SCREEN_WIDTH;
	devMode.dmPelsHeight = SCREEN_HEIGHT;
	//ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);//�f�B�X�v���C�̉𑜓x�̕ύX

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	/*�X���b�h�̍쐬*/
	if(CreateThread(NULL, 0, GameMain, NULL, 0, &dwID) == NULL)//3  (LPVOID)&param
	{
		MessageBox(
			NULL, TEXT("�X���b�h�̍쐬�Ɏ��s���܂���"), TEXT("�G���["),
			MB_OK | MB_ICONWARNING
		);
	}

	return TRUE;
}

//�E�B���h�E�v���V�[�W��

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	static RECT rc;
	static HBRUSH hBrush;
	int clw = 0, clh = 0;				//�E�B���h�E�T�C�Y

	switch (msg) {//�����̋C�ɂȂ���̂ݎ󂯎��
		case WM_CREATE:
			SetTimer(hWnd, TIMER_ID1, TIME1, NULL);//�^�C�}���Z�b�g
			ShowCursor(FALSE);//�}�E�X�J�[�\�����\��
			break;
		case WM_TIMER:
			if(wp == TIMER_ID1) {//�^�C�}1
			}
			break;
		case WM_KEYDOWN:
			switch(wp){
				case VK_BACK:
					break;
				case VK_RETURN:
					break;
				case VK_TAB:
					break;
				case VK_ESCAPE:
					PostQuitMessage(0);
					break;
				default:
					return DefWindowProc(hWnd, msg, wp, lp);
			}
			break;
		case WM_PAINT://�`�揈��
			/*GetClientRect(hWnd, &rc);
			clw = rc.right;//�E�B���h�E���̎擾
			clh = rc.bottom;//�E�B���h�E���̎擾
			
			hdc = BeginPaint(hWnd, &ps);//�f�o�C�X�R���e�L�X�g�̎擾
			
			sprintf(checktext, "a");
			SetTextColor(hdc, RGB(255,100,100));
			TextOut(hdc, 0, 0, checktext, strlen(checktext) );

			EndPaint(hWnd, &ps);//�f�o�C�X�R���e�L�X�g�̊J��*/
			break;
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default://���̑��̏����̓f�t�H���g�ǂ���ɔC����
			return (DefWindowProc(hWnd, msg, wp, lp));
	}
	return (DefWindowProc(hWnd, msg, wp, lp));
}

DWORD WINAPI GameMain(LPVOID vdParam){
	HWND hWnd;

	//hWnd = ((ThreadParam *)vdParam)->owner;
	hWnd = hWND; //�O���[�o���ϐ�����E�B���h�E�n���h�����󂯎��
	if(hWnd == NULL)
	{
		MessageBox(
			NULL, TEXT("�X���b�h�ւ̃E�B���h�E�n���h���̎󂯓n���Ɏ��s�Ɏ��s"), TEXT("�G���["),
			MB_OK | MB_ICONWARNING
		);
	}

	/*�Q�[���p�N���X�̐���*/
	Tomasen game;

	/*�Q�[���p�N���X�̎��s*/
	game.runGame(hWND);

	return TRUE;
}