// firstWindowsProject.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "firstWindowsProject.h"
#include"squares.h"
#include <stdlib.h>
#include<time.h>
#define  TIMER1 timer
#define MAX_LOADSTRING 100

void draw(HDC hdc);//drawing squares
// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
Point *p;
bool squares = true;//一个控制draw的开关
int i = 0;//标记方块
int type = 1;//旋转之后的类型

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_FIRSTWINDOWSPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_FIRSTWINDOWSPROJECT));

    MSG msg;
	
    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);//将消息处理一下
            DispatchMessage(&msg);//将消息交给Windows处理
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FIRSTWINDOWSPROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_FIRSTWINDOWSPROJECT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_EX_LAYERED | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
      CW_USEDEFAULT, 0, 1000, 700, nullptr, nullptr, hInstance, nullptr);
   SetTimer(hWnd, 1, 1000, NULL);
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}



//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此处添加使用 hdc 的任何绘图代码...

		

		if (squares == true)
		{
			draw(hdc);
			squares = false;
			falling = true;
		}
		else
			p->fall(hdc);

		for (int i = 0; i < 32; i++)
		{
			static int  y = 0, x = 20;
			theLine(hdc, y,x);
			y = (y == 620) ? y = 0 : y = y + 20;
			x = (x == 600) ? x = 0 : x = x + 20;
		}
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_KEYDOWN:
		switch(wParam)
	{
	case VK_RIGHT:
	{
		HDC hdc = GetDC(hWnd);
		p->right(hdc);
	}
	break;
	case VK_LEFT:
	{
		HDC hdc = GetDC(hWnd);
		p->left(hdc);
	}
	break;
	case VK_UP:
	{
		HDC hdc = GetDC(hWnd);
		p->up(hdc);
		
	}
	break;
	case VK_DOWN:
	{
		HDC hdc = GetDC(hWnd);
		p->down(hdc);
	}
	break;
	case VK_RETURN:
		type = p->changeType(type);
		break;
	default:
		break;
	}
		break;
    case WM_DESTROY:
		KillTimer(hWnd, 1);
		DeleteObject(hbrush);
		delete p;
        PostQuitMessage(0);
        break;
	case WM_TIMER:
	{
		HDC hdc = GetDC(hWnd);
		
		InvalidateRect(hWnd, NULL, TRUE);
		GetUpdateRect(hWnd, NULL, TRUE);
		UpdateWindow(hWnd);
		p->squaresShow(hdc,type);
		
	}
		break;
	
	
	
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void draw(HDC hdc)
{
	
	
		srand((unsigned)time(NULL));
		i = (rand() % (7 - 2)) + 1;
		switch (i)
		{
		case 1:
			p = new Bigsquare(300, 50);
			p->squaresShow(hdc,type);
			
			break;
		case 2:
			p = new Stick(300, 50);
			p->squaresShow(hdc,type);
			break;
		case 3:
			p = new Z(300, 50);
			p->squaresShow(hdc,type);
			break;
		case 4:
			p = new S(300, 50);
			p->squaresShow(hdc,type);
			break;
		case 5:
			p = new L(300, 50);
			p->squaresShow(hdc,type);
			break;
		case 6:
			p = new J(300, 50);
			p->squaresShow(hdc,type);
			break;
		case 7:
			p = new T(300, 50);
			p->squaresShow(hdc,type);
			break;
		}
	
}


// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

