#ifndef INCLUDED_MAIN_HPP
#define INCLUDED_MAIN_HPP


#define TIMER_ID1 1					//1/60�b�^�C�}�[
#define TIME1 1000/60				//�`�摬�xs

char checktext[256] = "test!";		//������`�F�b�N�p
HWND hWND;							//�E�B���h�E�n���h��

//�v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM InitApp(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);
DWORD WINAPI GameMain(LPVOID);//�X���b�h�p�֐��̃v���g�^�C�v�錾

char szClassName[] = "main";	//�E�B���h�E�N���X


#endif//INCLUDED_MAIN_HPP