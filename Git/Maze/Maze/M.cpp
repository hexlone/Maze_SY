#include "stdafx.h"
#include "M.h"
#include <graphics.h>
#include <easyx.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
// 初始化一个游戏界面
void Maze_Inti_Game()
{
	initgraph(1200,800);
//	setfillcolor(CYAN);                       // 设置提示界面填充颜色
	HRGN rgn = CreateRectRgn(800,0,1200,800); // 创建一个矩形区
	setcliprgn(rgn);                          // 剪裁rgn这个区域
	DeleteObject(rgn);                        // 删除rgn这个句柄
//	solidrectangle(800, 0, 1200, 800);        // 画一个实心的矩形
	IMAGE imag;
	loadimage(&imag,L"Back_1.jpg",400,800,0);
	putimage(800, 0, &imag);

// 定义起点提示
	setcolor(WHITE);
	setfillcolor(RED);
	fillcircle(860, 530, 9);
	setcolor(RED);                    // 设置颜色
	settextstyle(25, 0, L"宋体");     // 设置字体大小25，字体风格
	setbkmode(TRANSPARENT);           // 透明的字体背景风格
	outtextxy(902, 514, L":终点");

// 定义终点提示
	setcolor(WHITE);
	setfillcolor(YELLOW);
	fillcircle(860, 590, 9);
	setcolor(RED);                    // 设置颜色
	settextstyle(25, 0, L"宋体");     // 设置字体大小25，字体风格
	setbkmode(TRANSPARENT);           // 透明的字体背景风格
	outtextxy(902, 575, L":起点");

	setcolor(RGB(3,12,65));                    // 设置颜色
	settextstyle(60, 0, L"宋体");     // 设置字体大小50，字体风格
	setbkmode(TRANSPARENT);           // 透明的字体背景风格
	outtextxy(945, 50, L"迷宫");      // 在850,50,的地方输出文字
	RECT rect = {850,150,1150,750 };
	settextstyle(25, 0, L"宋体");     // 设置字体大小50，字体风格
	drawtext(_T("[游戏说明]\n\n这是一个迷宫游戏\n\nw   :上\n\ns   :下\n\na   :左\n\nd   :右\n\nesc :退出"), &rect, DT_WORDBREAK);

	HRGN rgn_2 = CreateRectRgn(0, 0, 790, 10);    // 创建一个矩形区
	setcliprgn(rgn_2);                            // 剪裁rgn这个区域
	DeleteObject(rgn_2);                          // 删除rgn这个句柄
	solidrectangle(0, 0, 790, 10);             // 画一个实心的矩形
	setbkcolor(LIGHTRED);                  // 设置一个背景颜色
	cleardevice();

	HRGN rgn_3 = CreateRectRgn(0, 10, 10, 800);    // 创建一个矩形区
	setcliprgn(rgn_3);                            // 剪裁rgn这个区域
	DeleteObject(rgn_3);                          // 删除rgn这个句柄
	solidrectangle(0, 10, 10, 800);             // 画一个实心的矩形
	setbkcolor(LIGHTRED);                  // 设置一个背景颜色
	cleardevice();

	HRGN rgn_4 = CreateRectRgn(790, 0, 800, 790);    // 创建一个矩形区
	setcliprgn(rgn_4);                            // 剪裁rgn这个区域
	DeleteObject(rgn_4);                          // 删除rgn这个句柄
	solidrectangle(790, 0, 800, 790);             // 画一个实心的矩形
	setbkcolor(LIGHTRED);                  // 设置一个背景颜色
	cleardevice();

	HRGN rgn_5 = CreateRectRgn(10, 790, 800, 800);    // 创建一个矩形区
	setcliprgn(rgn_5);                            // 剪裁rgn这个区域
	DeleteObject(rgn_5);                          // 删除rgn这个句柄
	solidrectangle(10, 790, 800, 800);             // 画一个实心的矩形
	setbkcolor(LIGHTRED);                  // 设置一个背景颜色
	cleardevice();

	HRGN rgn_1 = CreateRectRgn(10,10,790,790);    // 创建一个矩形区
	setcliprgn(rgn_1);                            // 剪裁rgn这个区域
	DeleteObject(rgn_1);                          // 删除rgn这个句柄
	solidrectangle(10, 10, 790, 790);             // 画一个实心的矩形
	
	setbkcolor(RGB(50,60,25));                  // 设置一个背景颜色
	cleardevice();                                // 清除屏幕
}
// 在x,y处画一个小方格
void Maze_Print_Box(int x, int y)
{
	x = x * 20 + 10;
	y = y * 20 + 10;
	setcolor(WHITE);                     // 设置线条颜色
	setfillcolor(LIGHTGRAY);                 // 设置填充颜色 
	fillrectangle(x+1,y+1,x+19,y+19);    // 创建一个填充矩形
}
// 打印游戏起点，终点方块
void Maze_Print_Start_End(int x_1, int y_1, int x_2, int y_2)
{
	x_1 = x_1 * 20 + 10;
	x_2 = x_2 * 20 + 10;
	y_1 = y_1 * 20 + 10;
	y_2 = y_2 * 20 + 10;
	setcolor(WHITE);
	setfillcolor(YELLOW);
	fillcircle(x_1 + 10, y_1 + 10, 9);

	setcolor(WHITE);
	setfillcolor(RED);
	fillcircle(x_2 + 10, y_2 + 10, 9);
}
// 用户的输入方向响应，对响应坐标进行变换
void Maze_Game_Move(box_2 &A, char ch)
{
	switch (ch)
	{
	case 'w':
		A.y--;
		A.dir = 'w';
		break;
	case 'W':
		A.dir = 'w';
		A.y--;
		break;
	case 's':
		A.dir = 's';
		A.y++;
		break;
	case 'S':
		A.dir = 's';
		A.y++;
		break;
	case 'a':
		A.dir = 'a';
		A.x--;
		break;
	case 'A':
		A.dir = 'a';
		A.x--;
		break;
	case 'd':
		A.dir = 'd';
		A.x++;
		break;
	case 'D':
		A.dir = 'd';
		A.x++;
		break;
	default:
		break;
	}
}
// 打印用户方块
void Maze_Print_user(int x, int y)
{
	x = x * 20 + 10;
	y = y * 20 + 10;
	setcolor(WHITE);
	setfillcolor(YELLOW);
	fillcircle(x + 10, y + 10, 9);
	
}
// 打印背景色以恢复方块
void Maze_Print_Clear(int x, int y)
{
	x = x * 20 + 10;
	y = y * 20 + 10;
	setcolor(RGB(50, 60, 25));
	setfillcolor(RGB(50, 60, 25));
	fillcircle(x + 10, y + 10, 9);
}
// 打印xyz中的迷宫地图
void Maze_Print_Map(int xyz[][39])
{
	for (int i = 0; i < 39; i++) {
		for (int j = 0; j < 39; j++) {
			if (xyz[i][j] == 1)
				Maze_Print_Box(i, j);
		}
	}
}
// 判断当前方块是不是通路，是返回true，不是返回false并且退回原坐标
bool Maze_Is_Way(int Map[][39], box_2 &A)
{
	if (Map[A.x][A.y] == 1) {
		switch (A.dir)
		{
		case 'w':
			A.y++;
			break;
		case 's':
			A.y--;
			break;
		case 'a':
			A.x++;
			break;
		case 'd':
			A.x--;
			break;
		default:
			break;
		}
		return false;
	}
	return true;
}
// 迷宫游戏函数
void Maze_Game()
{
	int MAP[39][39];
	time_t T_1, T_2;                                      // 两个时间，记录用户游戏总时间
	do {
		Maze_MakeMaze_Random(MAP, false);
		Maze_Inti_Game();                                // 初始化一个游戏界面 
		Maze_Print_Map(MAP);                             // 打印迷宫地图
		box_2 start,end,user;                            // 定义一个开始点，一个结束点，一个用户结构  
		Maze_Game_GetStartEnd(start, end, MAP);          // 随机获得一个起点终点坐标
		user.x = start.x;              
		user.y = start.y;                                // 用户坐标初始化为起点坐标
		Maze_Print_Start_End(start.x, start.y, end.x, end.y); // 打印起点与终点坐标
		T_1 = time(NULL);                                     // 获得当前系统时间
		while (!(user.x == end.x && user.y == end.y)) {
			char ch;                                 // 用户输入的方向
			box_2 temp;                              // 记录当前的方块
			temp.x = user.x;           
			temp.y = user.y;      
			ch = _getch();                     
			Maze_Game_Move(user, ch);                     // 找用户输入的方向的位置 
			if (Maze_Is_Way(MAP, user))                   // 如果下一个方向是通路，则清除原来的方块
				Maze_Print_Clear(temp.x, temp.y);   
			Maze_Print_user(user.x, user.y);              // 打印用户输入的下一个方块
		}
		T_2 = time(NULL);
	} while(Maze_Init_GameEnd((int)T_2 - (int)T_1));
}
// 游戏过关窗口，返回1代表“再来一局”，返回0代表“结束游戏”
int Maze_Init_GameEnd(int Time)
{
	initgraph(480, 640);
	// 设置背景图片
	IMAGE end;
	loadimage(&end,L"end.jpg",480, 640, 0);
	putimage(0, 0, &end);

	settextstyle(60, 0, L"宋体");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(175, 50, L"过关！");
	// 设置相关文字
	settextstyle(40, 0, L"宋体");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(120, 150, L"本次用时    秒");

	// 把Time转化为可输出的字符串
	settextstyle(40, 0, L"宋体");
	TCHAR s[5];                            
	swprintf_s(s, _T("%d"), Time);     
	outtextxy(290,150 , s);

	// 设置button1按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(100, 250, 380, 350, 50, 50);
	// 按钮文字
	settextstyle(50, 0, L"宋体");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(140, 275, L"再来一局");
	// 设置button2按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(100, 450, 380, 550, 50, 50);
	//按钮文字
	settextstyle(50, 0, L"宋体");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(140, 475, L"回主菜单");
	// 设置鼠标消息
	int m_x, m_y;
	MOUSEMSG mou;
	while (true) {
		while (MouseHit()) {
			mou = GetMouseMsg();
			if (mou.uMsg == WM_LBUTTONDOWN) {
				m_x = mou.x;
				m_y = mou.y;
				if ((m_x >= 100 && m_x <= 380) && (m_y >= 250 && m_y <= 350)) {
					return 1;
				}
				else if ((m_x >= 100 && m_x <= 380) && (m_y >= 450 && m_y <= 550)) {
					return 0;
				}
			}
		}
	}
}
// 随机获取开始与结束坐标
void Maze_Game_GetStartEnd(box_2 &start, box_2 &end,int MAP[][39])
{
	srand((unsigned)time(NULL));
	do {
		do {
			start.x = rand() % 37 + 1;
			start.y = rand() % 37 + 1;
		} while (MAP[start.x][start.y] == 1);
		do {
			end.x = rand() % 37 + 1;
			end.y = rand() % 37 + 1;
		} while (MAP[end.x][end.y] == 1);
	} while (start.x == end.x && start.y == end.y);
}
// 随机生成一个迷宫数组,MAP为迷宫数组，paly为是否演示生成过程
void Maze_MakeMaze_Random(int MAP[][39], bool play)
{
	int T = 20;                                   // 延时时间
	box_2 start;
	Maze_MakeMaze_Random_init(MAP);                // 初始化一个非连通图
	if (play)                                      // 是否需要演示
		Maze_Print_Map(MAP);
	Maze_MakeMaze_Random_GetStart(start);          // 随机获得一个开始位置
	stock A; A.top = -1;                           // 定义一个栈
	box_1 temp;                                    // 定义一个第三变量
	temp.x = start.x; temp.y = start.y; temp.dir = 0;  // temp初始化
	for (int i = 0; i < 4; i++)
		temp.Dir[i] = i + 1;
	Maze_MakeMaze_Random_GetDir(temp.Dir);             // 定义一个随机方向数组
	Maze_MakeMaze_Random_Fuzhi(A.St[++A.top], temp);     // 开始位置进栈
	MAP[start.x][start.y] = -1;                        // 走过的路径标记为 -1
	if (play) {
		Maze_MakeMaze_Random_PrintWay(start.x, start.y);
		Sleep(T);
	}
	int dir = A.St[A.top].dir;                       // 方向数组下标，即代表第几个方向
	int Dir = A.St[A.top].Dir[dir];                  // 方向数组内容，即代表方向
	int find, x, y;                                  // 找到路径标记，坐标
	while (A.top > -1) {                             // 栈不空循环
		find = 0;
		while (dir < 4 && find == 0) {               // 找下一个可走方块
			switch (Dir)
			{
			case 1:
				x = A.St[A.top].x - 2;
				y = A.St[A.top].y;
				break;
			case 2:
				x = A.St[A.top].x;
				y = A.St[A.top].y - 2;
				break;
			case 3:
				x = A.St[A.top].x + 2;
				y = A.St[A.top].y;
				break;
			case 4:
				x = A.St[A.top].x;
				y = A.St[A.top].y + 2;
				break;
			}

			if (x >= 0 && y >= 0 && x <= 38 && y <= 38 && MAP[x][y] == 0) {
				find = 1;
				if (play) {
					Maze_MakeMaze_Random_PrintWay((A.St[A.top].x + x) / 2, (A.St[A.top].y + y) / 2);
					Sleep(T);
					Maze_MakeMaze_Random_PrintWay(x, y);
					Sleep(T);
				}
			}
			else {
				dir++;
				Dir = A.St[A.top].Dir[dir];
			}	
		}
		if (find == 1) {
			A.St[A.top].dir = dir;                               // 方向赋值
			temp.x = x; temp.y = y; temp.dir = 0;
			Maze_MakeMaze_Random_GetDir(temp.Dir); 
			Maze_MakeMaze_Random_Fuzhi(A.St[++A.top], temp);     // 下一个可走方块进栈
			MAP[(A.St[A.top - 1].x + A.St[A.top].x)/2][(A.St[A.top - 1].y + A.St[A.top].y)/2] = -1;
			MAP[x][y] = -1;
			dir = A.St[A.top].dir;
			Dir = A.St[A.top].Dir[dir];                          
		}
		else {
			if (play) {
				Maze_MakeMaze_Random_PrintClean(A.St[A.top].x, A.St[A.top].y);
				Sleep(T);
				Maze_MakeMaze_Random_PrintClean((A.St[A.top - 1].x + A.St[A.top].x) / 2, (A.St[A.top - 1].y + A.St[A.top].y) / 2);
				Sleep(T);
			}
			A.top--;
			if (A.top > -1) {
				dir = A.St[A.top].dir + 1;
				Dir = A.St[A.top].Dir[dir];
			}
		}
 	}
	for (int i = 0; i < 39; i++) {
		for (int j = 0; j < 39; j++) {
			if (MAP[i][j] == -1)
				MAP[i][j] = 0;
		}
	}
}
// 初始化迷宫地图为非连通图
void Maze_MakeMaze_Random_init(int MAP[][39]) 
{
	for (int i = 0; i < 39; i++) {
		for (int k = 0; k < 39; k++) {
			if (i % 2 != 0 && k % 2 != 0)
				MAP[i][k] = 0;
			else
				MAP[i][k] = 1;
		}
	}
}
// 演示功能
void Maze_Meum_Play()
{
	int MAP[39][39];
	initgraph(800, 800);
	// 以下为绘制演示窗口
	HRGN rgn_1 = CreateRectRgn(0, 0, 790, 10);    // 创建一个矩形区
	setcliprgn(rgn_1);                            // 剪裁rgn这个区域
	DeleteObject(rgn_1);                          // 删除rgn这个句柄
	solidrectangle(0, 0, 790, 10);                // 画一个实心的矩形
	setbkcolor(LIGHTRED);                         // 设置一个背景颜色
	cleardevice();                                // 用背景颜色清屏

	HRGN rgn_2 = CreateRectRgn(790, 0, 800, 790);    // 创建一个矩形区
	setcliprgn(rgn_2);                            // 剪裁rgn这个区域
	DeleteObject(rgn_2);                          // 删除rgn这个句柄
	solidrectangle(790, 0, 800, 790);                // 画一个实心的矩形
	setbkcolor(LIGHTRED);                         // 设置一个背景颜色
	cleardevice();

	HRGN rgn_3 = CreateRectRgn(0, 10, 10, 790);    // 创建一个矩形区
	setcliprgn(rgn_3);                            // 剪裁rgn这个区域
	DeleteObject(rgn_3);                          // 删除rgn这个句柄
	solidrectangle(0, 10, 10, 790);                // 画一个实心的矩形
	setbkcolor(LIGHTRED);                         // 设置一个背景颜色
	cleardevice();

	HRGN rgn_4 = CreateRectRgn(0, 790, 800, 800);    // 创建一个矩形区
	setcliprgn(rgn_4);                            // 剪裁rgn这个区域
	DeleteObject(rgn_4);                          // 删除rgn这个句柄
	solidrectangle(0, 790, 800, 800);                // 画一个实心的矩形
	setbkcolor(LIGHTRED);                         // 设置一个背景颜色
	cleardevice();
	// 以下为主窗口
	HRGN rgn_5 = CreateRectRgn(10, 10, 790, 790);    // 创建一个矩形区
	setcliprgn(rgn_5);                            // 剪裁rgn这个区域
	DeleteObject(rgn_5);                          // 删除rgn这个句柄
	solidrectangle(10, 10, 790, 790);                // 画一个实心的矩形
	setbkcolor(RGB(50, 60, 25));                         // 设置一个背景颜色
	cleardevice();

	Maze_MakeMaze_Random(MAP, true);

	getchar();
}
// 随机获得一个开始坐标
void Maze_MakeMaze_Random_GetStart(box_2 &start)
{
	srand((unsigned)time(NULL));
	start.x = rand() % 37 + 1;
	start.y = rand() % 37 + 1;
	if (start.x % 2 == 0)
		start.x++;
	if (start.y % 2 == 0)
		start.y++;
}
// 获得随机方向数组
void Maze_MakeMaze_Random_GetDir(int Dir[4])
{
	srand((unsigned)time(NULL));
	int p, temp;
	for (int i = 0; i < 77; i++) {
		p = rand() % 4;
		temp = Dir[0];
		Dir[0] = Dir[p];
		Dir[p] = temp;
	}
}
// 打印演示方块
void Maze_MakeMaze_Random_PrintWay(int x, int y)
{
	x = x * 20 + 10;
	y = y * 20 + 10;
	setcolor(LIGHTBLUE);
	setfillcolor(LIGHTBLUE);
	fillrectangle(x + 1, y + 1, x + 19, y + 19);
}
// 清除演示方块
void Maze_MakeMaze_Random_PrintClean(int x, int y)
{
	x = x * 20 + 10;
	y = y * 20 + 10;
	setcolor(RGB(50, 60, 25));
	setfillcolor(RGB(50, 60, 25));
	fillrectangle(x + 1, y + 1, x + 19, y + 19);
}
// 把B的值给A
void Maze_MakeMaze_Random_Fuzhi(box_1 &A, box_1 &B)
{
	A.x = B.x;
	A.y = B.y;
	A.dir = B.dir;
	for (int i = 0; i < 4; i++) {
		A.Dir[i] = B.Dir[i];
	}
}
// 菜单界面
int Maze_inti()
{
	initgraph(600, 800);
	// 加载主菜单背景图片
	IMAGE end;
	loadimage(&end, L"meum.jpg", 600, 800, 0);
	putimage(0, 0, &end);
	// 文字
	settextstyle(70, 0, L"黑体");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(200, 50, L"主菜单");

	// 设置button1按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 150, 450, 250 , 50, 50);
	// 按钮文字
	settextstyle(50, 0, L"宋体");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(200, 175, L"迷宫游戏");

	// 设置button2按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 300, 450, 400, 50, 50);
	// 按钮文字
	settextstyle(50, 0, L"宋体");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(150,325, L"生成迷宫演示");

	// 设置button3按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 450, 450, 550, 50, 50);
	// 按钮文字
	settextstyle(50, 0, L"宋体");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(220, 475, L"DFS求解");

	// 设置button4按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 600, 450, 700, 50, 50);
	// 按钮文字
	settextstyle(50, 0, L"宋体");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(220, 625, L"BFS求解");

	// 设置button5按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(425, 725, 575, 775, 50, 50);
	// 按钮文字
	settextstyle(25, 0, L"微软雅黑");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(480, 735, L"退出");

	// 设置鼠标消息
	int m_x, m_y;
	MOUSEMSG mou;
	while (true) {
		while (MouseHit()) {
			mou = GetMouseMsg();
			if (mou.uMsg == WM_LBUTTONDOWN) {
				m_x = mou.x;
				m_y = mou.y;
				if ((m_x >= 150 && m_x <= 450) && (m_y >= 150 && m_y <= 250)) {
					return 1;
				}
				else if ((m_x >= 150 && m_x <= 450) && (m_y >= 300 && m_y <= 400)) {
					return 2;
				}
				else if ((m_x >= 150 && m_x <= 450) && (m_y >= 450 && m_y <= 550)) {
					return 3;
				}
				else if ((m_x >= 150 && m_x <= 450) && (m_y >= 600 && m_y <= 700 )) {
					return 4;
				}
				else if ((m_x >= 425 && m_x <= 575) && (m_y >= 725 && m_y <= 775)) {
					return 0;
				}
			}
		}
	}
}
// 主菜单搭建
void Maze()
{
	int flag;
	mciSendString(L"open MazeMusic.mp3 alias ARNO", 0, 0, 0);
	mciSendString(L"play ARNO repeat", 0, 0, 0);
	Sleep(1000);
	do {
		flag = Maze_inti();
		switch (flag)
		{
		case 1:
			Maze_Game();
			break;
		case 2:
			Maze_Meum_Play();
			break;
		case 3:
			Maze_DFS();
			break;
		case 4:
			Maze_BFS();
			break;
		default:
			break;
		}
	} while (flag != 0);
	
}

void Maze_DFS()
{
	int MAP[39][39];
	initgraph(1200, 800);
	HRGN rgn = CreateRectRgn(800, 0, 1200, 800); // 创建一个矩形区
	setcliprgn(rgn);                          // 剪裁rgn这个区域
	DeleteObject(rgn);                        // 删除rgn这个句柄
											  //	solidrectangle(800, 0, 1200, 800);        // 画一个实心的矩形
	IMAGE imag;
	loadimage(&imag, L"Back_1.jpg", 400, 800, 0);
	putimage(800, 0, &imag);

	Maze_DFS_Button();                            // 在相应的地方绘制Button按钮

	// 以下为绘制演示窗口
	HRGN rgn_1 = CreateRectRgn(0, 0, 790, 10);    // 创建一个矩形区
	setcliprgn(rgn_1);                            // 剪裁rgn这个区域
	DeleteObject(rgn_1);                          // 删除rgn这个句柄
	solidrectangle(0, 0, 790, 10);                // 画一个实心的矩形
	setbkcolor(LIGHTRED);                         // 设置一个背景颜色
	cleardevice();                                // 用背景颜色清屏

	HRGN rgn_2 = CreateRectRgn(790, 0, 800, 790);    // 创建一个矩形区
	setcliprgn(rgn_2);                            // 剪裁rgn这个区域
	DeleteObject(rgn_2);                          // 删除rgn这个句柄
	solidrectangle(790, 0, 800, 790);                // 画一个实心的矩形
	setbkcolor(LIGHTRED);                         // 设置一个背景颜色
	cleardevice();

	HRGN rgn_3 = CreateRectRgn(0, 10, 10, 790);    // 创建一个矩形区
	setcliprgn(rgn_3);                            // 剪裁rgn这个区域
	DeleteObject(rgn_3);                          // 删除rgn这个句柄
	solidrectangle(0, 10, 10, 790);                // 画一个实心的矩形
	setbkcolor(LIGHTRED);                         // 设置一个背景颜色
	cleardevice();

	HRGN rgn_4 = CreateRectRgn(0, 790, 800, 800);    // 创建一个矩形区
	setcliprgn(rgn_4);                            // 剪裁rgn这个区域
	DeleteObject(rgn_4);                          // 删除rgn这个句柄
	solidrectangle(0, 790, 800, 800);                // 画一个实心的矩形
	setbkcolor(LIGHTRED);                         // 设置一个背景颜色
	cleardevice();
	// 以下为主窗口
	HRGN rgn_5 = CreateRectRgn(10, 10, 790, 790);    // 创建一个矩形区
	setcliprgn(rgn_5);                            // 剪裁rgn这个区域
	DeleteObject(rgn_5);                          // 删除rgn这个句柄
	solidrectangle(10, 10, 790, 790);                // 画一个实心的矩形
	setbkcolor(RGB(50, 60, 25));                         // 设置一个背景颜色
	cleardevice();
	int flag = 0;
	int mouse;
	do {
		mouse = Maze_Slove_Mouse();                    // 获得鼠标消息
		switch (mouse)
		{
		case 1:
			cleardevice();
			Maze_MakeMaze_Random(MAP, false);
			Maze_Print_Map(MAP);
			flag = 1;
			break;
		case 2:
			cleardevice();
			Maze_MakeMaze_Random(MAP, true);
			flag = 1;
			break;
		case 3:
			if (flag == 1) {
				cleardevice();
				Maze_DFS_Solve(MAP, true, true);
			}
			else {
				cleardevice();
				Maze_DFS_Solve(MAP, true, false);
			}
			break;
		}
	} while (mouse);

	
}
// BFS 求解迷宫
void Maze_BFS()
{
	int MAP[39][39];
	initgraph(1200, 800);
	HRGN rgn = CreateRectRgn(800, 0, 1200, 800); // 创建一个矩形区
	setcliprgn(rgn);                          // 剪裁rgn这个区域
	DeleteObject(rgn);                        // 删除rgn这个句柄
											  //	solidrectangle(800, 0, 1200, 800);        // 画一个实心的矩形
	IMAGE imag;
	loadimage(&imag, L"Back_1.jpg", 400, 800, 0);
	putimage(800, 0, &imag);

	Maze_BFS_Button();                            // 在相应的地方绘制Button按钮                 // 用背景颜色清屏

												  // 以下为绘制演示窗口
	HRGN rgn_1 = CreateRectRgn(0, 0, 790, 10);    // 创建一个矩形区
	setcliprgn(rgn_1);                            // 剪裁rgn这个区域
	DeleteObject(rgn_1);                          // 删除rgn这个句柄
	solidrectangle(0, 0, 790, 10);                // 画一个实心的矩形
	setbkcolor(LIGHTRED);                         // 设置一个背景颜色
	cleardevice();                                // 用背景颜色清屏

	HRGN rgn_2 = CreateRectRgn(790, 0, 800, 790);    // 创建一个矩形区
	setcliprgn(rgn_2);                            // 剪裁rgn这个区域
	DeleteObject(rgn_2);                          // 删除rgn这个句柄
	solidrectangle(790, 0, 800, 790);                // 画一个实心的矩形
	setbkcolor(LIGHTRED);                         // 设置一个背景颜色
	cleardevice();

	HRGN rgn_3 = CreateRectRgn(0, 10, 10, 790);    // 创建一个矩形区
	setcliprgn(rgn_3);                                 // 剪裁rgn这个区域
	DeleteObject(rgn_3);                               // 删除rgn这个句柄
	solidrectangle(0, 10, 10, 790);                    // 画一个实心的矩形
	setbkcolor(LIGHTRED);                              // 设置一个背景颜色
	cleardevice();

	HRGN rgn_4 = CreateRectRgn(0, 790, 800, 800);       // 创建一个矩形区
	setcliprgn(rgn_4);                                  // 剪裁rgn这个区域
	DeleteObject(rgn_4);                                // 删除rgn这个句柄
	solidrectangle(0, 790, 800, 800);                   // 画一个实心的矩形
	setbkcolor(LIGHTRED);                               // 设置一个背景颜色
	cleardevice();
	// 以下为主窗口
	HRGN rgn_5 = CreateRectRgn(10, 10, 790, 790);        // 创建一个矩形区
	setcliprgn(rgn_5);                                   // 剪裁rgn这个区域
	DeleteObject(rgn_5);                                 // 删除rgn这个句柄
	solidrectangle(10, 10, 790, 790);                    // 画一个实心的矩形
	setbkcolor(RGB(50, 60, 25));                         // 设置一个背景颜色
	cleardevice();

	int flag = 0;
	int mouse;
	do {
		mouse = Maze_Slove_Mouse();                    // 获得鼠标消息
		switch (mouse)
		{
		case 1:
			cleardevice();
			Maze_MakeMaze_Random(MAP, false);
			Maze_Print_Map(MAP);
			flag = 1;
			break;
		case 2:
			cleardevice();
			Maze_MakeMaze_Random(MAP, true);
			flag = 1;
			break;
		case 3:
			if (flag == 1) {
				cleardevice();
				Maze_BFS_Solve(MAP, true, true);
			}
			else {
				cleardevice();
				Maze_BFS_Solve(MAP, true, false);
			}
			break;
		}
	} while (mouse);
}
// play 是否需要演示求解过程，CreateMaze是否需要随机生成一个迷宫，clean是否清除打印后的方格
void Maze_DFS_Solve(int MAP[][39], bool play,bool CreateMaze)
{
	int T = 20;                        // 延时毫秒数
	box_1 start, end, temp;
	if (CreateMaze == false)
		Maze_MakeMaze_Random(MAP, false);    // 随机生成一个迷宫
	Maze_Print_Map(MAP);                     // 打印迷宫数组
	stock A; A.top = -1;                 // 定义一个栈
	Maze_Solve_GetStartEnd(start, end, MAP);           // 随机获得一个起点与一个终点
	if (play) {
		Maze_Print_Start_End(start.x, start.y, end.x, end.y);  // 打印起点与终点
		Sleep(2000);
	}
	temp.dir = 1;                                          // temp为第三变量
	Maze_MakeMaze_Random_Fuzhi(A.St[++A.top], start);      // 首元素进栈
	if (play) {
		Maze_MakeMaze_Random_PrintWay(start.x, start.y);
		Sleep(T);
	}
	MAP[start.x][start.y] = -1;                           // 标记首元素已经走过
	while (A.top > -1 && !(A.St[A.top].x == end.x && A.St[A.top].y == end.y)) {
		int find = 0;                                      // 标记是否找到可走方块
		while (temp.dir < 5 && find == 0) {
			switch (temp.dir)
			{
			case 1:
				temp.x = A.St[A.top].x - 1;
				temp.y = A.St[A.top].y;
				break;
			case 2:
				temp.x = A.St[A.top].x;
				temp.y = A.St[A.top].y - 1;
				break;
			case 3:
				temp.x = A.St[A.top].x + 1;
				temp.y = A.St[A.top].y;
				break;
			case 4:
				temp.x = A.St[A.top].x;
				temp.y = A.St[A.top].y + 1;
				break;
			}
			if (temp.x > 0 && temp.y > 0 && temp.x < 38 && temp.y < 38 && MAP[temp.x][temp.y] == 0) {
				find = 1;
			}
			else
				temp.dir++;
		}
		if (find == 1) {
			A.St[A.top].dir = temp.dir;
			Maze_MakeMaze_Random_Fuzhi(A.St[++A.top], temp);
			if (play) {
				Maze_MakeMaze_Random_PrintWay(temp.x, temp.y);
				Sleep(T);
			}
			temp.dir = 1;
			MAP[temp.x][temp.y] = -1;
		}
		else {
			MAP[A.St[A.top].x][A.St[A.top].y] = 0;
			if (play) {
				Maze_MakeMaze_Random_PrintClean(A.St[A.top].x, A.St[A.top].y);
				Sleep(T);
			}
			temp.dir = A.St[--A.top].dir + 1;
		}
	}
	for (int i = 0; i <= A.top; i++)
		MAP[A.St[i].x][A.St[i].y] = 0;
}

void Maze_BFS_Solve(int MAP[][39], bool play, bool CreateMaze)
{
	int T = 10; // 延时毫秒数
	if (CreateMaze == false)
		Maze_MakeMaze_Random(MAP, false);          // 随机生成一个迷宫
	Maze_Print_Map(MAP);
	queue A;
	A.prior = -1; A.rear = -1;                      // 定义并且初始化一个队列
	box_1 temp, start, end;                            // 定义起点与终点和第三变量
	Maze_Solve_GetStartEnd(start, end, MAP);           // 随机获得一个起点与一个终点
	Maze_MakeMaze_Random_Fuzhi(A.Qu[++A.rear], start);      // 首元素进队
	MAP[A.Qu[A.rear].x][A.Qu[A.rear].y] = -1;                //  进队元素标记
	if (play) {
		Maze_Print_Start_End(start.x, start.y, end.x, end.y);  // 打印起点与终点
		Sleep(2000);
	}
	if (play) {
		Maze_MakeMaze_Random_PrintWay(start.x, start.y);           // 打印首元素
		Sleep(T);
	}
	while (A.rear != A.prior) {
		A.prior++;                            // 首元素出队
		int find = 0;
		for (int i = 1; i <= 4; i++) {
			switch (i) {
			case 1:
				temp.x = A.Qu[A.prior].x - 1;
				temp.y = A.Qu[A.prior].y;
				temp.dir = A.prior;
				break;
			case 2:
				temp.x = A.Qu[A.prior].x;
				temp.y = A.Qu[A.prior].y - 1;
				temp.dir = A.prior;
				break;
			case 3:
				temp.x = A.Qu[A.prior].x + 1;
				temp.y = A.Qu[A.prior].y;
				temp.dir = A.prior;
				break;
			case 4:
				temp.x = A.Qu[A.prior].x;
				temp.y = A.Qu[A.prior].y + 1;
				temp.dir = A.prior;
				break;
			}
			if (temp.x > 0 && temp.y > 0 && temp.x < 38 && temp.y < 38 && MAP[temp.x][temp.y] == 0) {
				Maze_MakeMaze_Random_Fuzhi(A.Qu[++A.rear], temp);     // 找到的元素队
				if (play) {
					Maze_MakeMaze_Random_PrintWay(temp.x, temp.y);
					Sleep(T);
				}
				MAP[temp.x][temp.y] = -1;
				if (A.Qu[A.rear].x == end.x && A.Qu[A.rear].y == end.y) {
					find = 1;
					break;
				}
			}
		}
		if (find == 1)
			break;
	}
	Sleep(2000);
	
	for (int i = A.rear; i >= 0; i--) {
		if (play) {
			Maze_MakeMaze_Random_PrintClean(A.Qu[i].x, A.Qu[i].y);
			Maze_Print_Start_End(start.x, start.y, end.x, end.y);
			Sleep(20);
		}
		MAP[A.Qu[i].x][A.Qu[i].y] = 0;
	}
	int p = A.rear;
	if (play) {
		for (; p > -1;) {
			Maze_MakeMaze_Random_PrintWay(A.Qu[p].x,A.Qu[p].y);
			Sleep(T);
			p = A.Qu[p].dir;
		}
	}
}

void Maze_Solve_GetStartEnd(box_1 &start, box_1 &end,int MAP[][39])
{
	srand((unsigned)time(NULL));
	do {
		do {
			start.x = rand() % 37 + 1;
			start.y = rand() % 37 + 1;
		} while (MAP[start.x][start.y] == 1);
		do {
			end.x = rand() % 37 + 1;
			end.y = rand() % 37 + 1;
		} while (MAP[end.x][end.y] == 1);
	} while (start.x == end.x && start.y == end.y);
}

void Maze_DFS_Button()
{
	// 设置button1按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 50, 1150, 100, 50, 50);
	// 按钮文字
	settextstyle(30, 0, L"微软雅黑");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(895, 60 , L"创建迷宫(不演示过程)");

	// 设置button2按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 150, 1150, 200, 50, 50);
	// 按钮文字
	settextstyle(30, 0, L"微软雅黑");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(905, 160, L"创建迷宫(演示过程)");

	// 设置button3按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 250, 1150, 300, 50, 50);
	// 按钮文字
	settextstyle(30, 0, L"微软雅黑");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(930, 260, L"DFS求解过程");

	// 设置button4按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 350, 1150, 400, 50, 50);
	// 按钮文字
	settextstyle(30, 0, L"微软雅黑");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(945, 360, L"返回主菜单");
}

int Maze_Slove_Mouse()
{
	int m_x, m_y;
	MOUSEMSG msg;
	while (true) {
		while (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN) {
				m_x = msg.x;
				m_y = msg.y;
				if ((m_x >= 850 && m_x <= 1150) && (m_y >= 50 && m_y <= 100)) {
					return 1;
				}
				else if ((m_x >= 850 && m_x <= 1150) && (m_y >= 150 && m_y <= 200)) {
					return 2;
				}
				else if ((m_x >= 850 && m_x <= 1150) && (m_y >= 250 && m_y <= 300)) {
					return 3;
				}
				else if ((m_x >= 850 && m_x <= 1150) && (m_y >= 350 && m_y <= 400)) {
					return 0;
				}
			}
		}
	}
}

void Maze_BFS_Button()
{
	// 设置button1按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 50, 1150, 100, 50, 50);
	// 按钮文字
	settextstyle(30, 0, L"微软雅黑");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(895, 60, L"创建迷宫(不演示过程)");

	// 设置button2按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 150, 1150, 200, 50, 50);
	// 按钮文字
	settextstyle(30, 0, L"微软雅黑");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(905, 160, L"创建迷宫(演示过程)");

	// 设置button3按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 250, 1150, 300, 50, 50);
	// 按钮文字
	settextstyle(30, 0, L"微软雅黑");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(930, 260, L"BFS求解过程");

	// 设置button4按钮
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 350, 1150, 400, 50, 50);
	// 按钮文字
	settextstyle(30, 0, L"微软雅黑");
	setbkmode(TRANSPARENT);           // 设置字体透明风格
	settextcolor(BLACK);
	outtextxy(945, 360, L"返回主菜单");
}
