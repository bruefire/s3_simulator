#pragma once

#include <Windows.h>
#include <string>
#include <GL/gl.h>
#include "constants.h"
#include "engine3dGL.h"
#include "PyInteract.h"


class engine3dWin : public engine3dGL
{
public:
	HINSTANCE hInst;
	int nCmdShow;
	HWND preWnd;
	HDC hdc;
	HGLRC hGLRC;
	HDC hMemDC;
	HBITMAP hBitmap;
	UINT* bmp;
	int DIBS_WIDTH;
	int DIBS_HEIGHT;

	bool disposeFlg;
	double MOUSE_FIX;

	JOYCAPS joyCaps;	// ゲームパッド情報
	PyInteract pyInter;

	HWND(*initWndFunc)(HINSTANCE hCurInst, int nCmdShow);
	bool (*wndProcFunc)(MSG*);


	engine3dWin();

	virtual int init(void** params, HWND (*a)(HINSTANCE hCurInst, int nCmdShow), bool (*b)(MSG*));
	virtual int start();
	virtual int update();
	virtual int dispose();

	// openGL overrides
	int GL_CreateContextPls();
	int GL_DeleteContextPls();
	int GL_SwapBuffer();

	bool InitWindow();
	int createDIBS();
	int disposeDIBS();
	virtual void CreateNewEngine(std::string) override;

	int SaveDIB32(char *lpFileName,const BYTE *lpPixel,const BITMAPINFO *lpBmpInfo, int loop);
	char* nextInt(char* nowInt, char len, char rank);
	void Write32(HANDLE fh,const BYTE *lpPixel,int w,int h);
};
