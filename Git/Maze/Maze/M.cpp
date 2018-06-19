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
// ��ʼ��һ����Ϸ����
void Maze_Inti_Game()
{
	initgraph(1200,800);
//	setfillcolor(CYAN);                       // ������ʾ���������ɫ
	HRGN rgn = CreateRectRgn(800,0,1200,800); // ����һ��������
	setcliprgn(rgn);                          // ����rgn�������
	DeleteObject(rgn);                        // ɾ��rgn������
//	solidrectangle(800, 0, 1200, 800);        // ��һ��ʵ�ĵľ���
	IMAGE imag;
	loadimage(&imag,L"Back_1.jpg",400,800,0);
	putimage(800, 0, &imag);

// ���������ʾ
	setcolor(WHITE);
	setfillcolor(RED);
	fillcircle(860, 530, 9);
	setcolor(RED);                    // ������ɫ
	settextstyle(25, 0, L"����");     // ���������С25��������
	setbkmode(TRANSPARENT);           // ͸�������屳�����
	outtextxy(902, 514, L":�յ�");

// �����յ���ʾ
	setcolor(WHITE);
	setfillcolor(YELLOW);
	fillcircle(860, 590, 9);
	setcolor(RED);                    // ������ɫ
	settextstyle(25, 0, L"����");     // ���������С25��������
	setbkmode(TRANSPARENT);           // ͸�������屳�����
	outtextxy(902, 575, L":���");

	setcolor(RGB(3,12,65));                    // ������ɫ
	settextstyle(60, 0, L"����");     // ���������С50��������
	setbkmode(TRANSPARENT);           // ͸�������屳�����
	outtextxy(945, 50, L"�Թ�");      // ��850,50,�ĵط��������
	RECT rect = {850,150,1150,750 };
	settextstyle(25, 0, L"����");     // ���������С50��������
	drawtext(_T("[��Ϸ˵��]\n\n����һ���Թ���Ϸ\n\nw   :��\n\ns   :��\n\na   :��\n\nd   :��\n\nesc :�˳�"), &rect, DT_WORDBREAK);

	HRGN rgn_2 = CreateRectRgn(0, 0, 790, 10);    // ����һ��������
	setcliprgn(rgn_2);                            // ����rgn�������
	DeleteObject(rgn_2);                          // ɾ��rgn������
	solidrectangle(0, 0, 790, 10);             // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                  // ����һ��������ɫ
	cleardevice();

	HRGN rgn_3 = CreateRectRgn(0, 10, 10, 800);    // ����һ��������
	setcliprgn(rgn_3);                            // ����rgn�������
	DeleteObject(rgn_3);                          // ɾ��rgn������
	solidrectangle(0, 10, 10, 800);             // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                  // ����һ��������ɫ
	cleardevice();

	HRGN rgn_4 = CreateRectRgn(790, 0, 800, 790);    // ����һ��������
	setcliprgn(rgn_4);                            // ����rgn�������
	DeleteObject(rgn_4);                          // ɾ��rgn������
	solidrectangle(790, 0, 800, 790);             // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                  // ����һ��������ɫ
	cleardevice();

	HRGN rgn_5 = CreateRectRgn(10, 790, 800, 800);    // ����һ��������
	setcliprgn(rgn_5);                            // ����rgn�������
	DeleteObject(rgn_5);                          // ɾ��rgn������
	solidrectangle(10, 790, 800, 800);             // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                  // ����һ��������ɫ
	cleardevice();

	HRGN rgn_1 = CreateRectRgn(10,10,790,790);    // ����һ��������
	setcliprgn(rgn_1);                            // ����rgn�������
	DeleteObject(rgn_1);                          // ɾ��rgn������
	solidrectangle(10, 10, 790, 790);             // ��һ��ʵ�ĵľ���
	
	setbkcolor(RGB(50,60,25));                  // ����һ��������ɫ
	cleardevice();                                // �����Ļ
}
// ��x,y����һ��С����
void Maze_Print_Box(int x, int y)
{
	x = x * 20 + 10;
	y = y * 20 + 10;
	setcolor(WHITE);                     // ����������ɫ
	setfillcolor(LIGHTGRAY);                 // ���������ɫ 
	fillrectangle(x+1,y+1,x+19,y+19);    // ����һ��������
}
// ��ӡ��Ϸ��㣬�յ㷽��
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
// �û������뷽����Ӧ������Ӧ������б任
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
// ��ӡ�û�����
void Maze_Print_user(int x, int y)
{
	x = x * 20 + 10;
	y = y * 20 + 10;
	setcolor(WHITE);
	setfillcolor(YELLOW);
	fillcircle(x + 10, y + 10, 9);
	
}
// ��ӡ����ɫ�Իָ�����
void Maze_Print_Clear(int x, int y)
{
	x = x * 20 + 10;
	y = y * 20 + 10;
	setcolor(RGB(50, 60, 25));
	setfillcolor(RGB(50, 60, 25));
	fillcircle(x + 10, y + 10, 9);
}
// ��ӡxyz�е��Թ���ͼ
void Maze_Print_Map(int xyz[][39])
{
	for (int i = 0; i < 39; i++) {
		for (int j = 0; j < 39; j++) {
			if (xyz[i][j] == 1)
				Maze_Print_Box(i, j);
		}
	}
}
// �жϵ�ǰ�����ǲ���ͨ·���Ƿ���true�����Ƿ���false�����˻�ԭ����
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
// �Թ���Ϸ����
void Maze_Game()
{
	int MAP[39][39];
	time_t T_1, T_2;                                      // ����ʱ�䣬��¼�û���Ϸ��ʱ��
	do {
		Maze_MakeMaze_Random(MAP, false);
		Maze_Inti_Game();                                // ��ʼ��һ����Ϸ���� 
		Maze_Print_Map(MAP);                             // ��ӡ�Թ���ͼ
		box_2 start,end,user;                            // ����һ����ʼ�㣬һ�������㣬һ���û��ṹ  
		Maze_Game_GetStartEnd(start, end, MAP);          // ������һ������յ�����
		user.x = start.x;              
		user.y = start.y;                                // �û������ʼ��Ϊ�������
		Maze_Print_Start_End(start.x, start.y, end.x, end.y); // ��ӡ������յ�����
		T_1 = time(NULL);                                     // ��õ�ǰϵͳʱ��
		while (!(user.x == end.x && user.y == end.y)) {
			char ch;                                 // �û�����ķ���
			box_2 temp;                              // ��¼��ǰ�ķ���
			temp.x = user.x;           
			temp.y = user.y;      
			ch = _getch();                     
			Maze_Game_Move(user, ch);                     // ���û�����ķ����λ�� 
			if (Maze_Is_Way(MAP, user))                   // �����һ��������ͨ·�������ԭ���ķ���
				Maze_Print_Clear(temp.x, temp.y);   
			Maze_Print_user(user.x, user.y);              // ��ӡ�û��������һ������
		}
		T_2 = time(NULL);
	} while(Maze_Init_GameEnd((int)T_2 - (int)T_1));
}
// ��Ϸ���ش��ڣ�����1��������һ�֡�������0����������Ϸ��
int Maze_Init_GameEnd(int Time)
{
	initgraph(480, 640);
	// ���ñ���ͼƬ
	IMAGE end;
	loadimage(&end,L"end.jpg",480, 640, 0);
	putimage(0, 0, &end);

	settextstyle(60, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(175, 50, L"���أ�");
	// �����������
	settextstyle(40, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(120, 150, L"������ʱ    ��");

	// ��Timeת��Ϊ��������ַ���
	settextstyle(40, 0, L"����");
	TCHAR s[5];                            
	swprintf_s(s, _T("%d"), Time);     
	outtextxy(290,150 , s);

	// ����button1��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(100, 250, 380, 350, 50, 50);
	// ��ť����
	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(140, 275, L"����һ��");
	// ����button2��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(100, 450, 380, 550, 50, 50);
	//��ť����
	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(140, 475, L"�����˵�");
	// ���������Ϣ
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
// �����ȡ��ʼ���������
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
// �������һ���Թ�����,MAPΪ�Թ����飬palyΪ�Ƿ���ʾ���ɹ���
void Maze_MakeMaze_Random(int MAP[][39], bool play)
{
	int T = 20;                                   // ��ʱʱ��
	box_2 start;
	Maze_MakeMaze_Random_init(MAP);                // ��ʼ��һ������ͨͼ
	if (play)                                      // �Ƿ���Ҫ��ʾ
		Maze_Print_Map(MAP);
	Maze_MakeMaze_Random_GetStart(start);          // ������һ����ʼλ��
	stock A; A.top = -1;                           // ����һ��ջ
	box_1 temp;                                    // ����һ����������
	temp.x = start.x; temp.y = start.y; temp.dir = 0;  // temp��ʼ��
	for (int i = 0; i < 4; i++)
		temp.Dir[i] = i + 1;
	Maze_MakeMaze_Random_GetDir(temp.Dir);             // ����һ�������������
	Maze_MakeMaze_Random_Fuzhi(A.St[++A.top], temp);     // ��ʼλ�ý�ջ
	MAP[start.x][start.y] = -1;                        // �߹���·�����Ϊ -1
	if (play) {
		Maze_MakeMaze_Random_PrintWay(start.x, start.y);
		Sleep(T);
	}
	int dir = A.St[A.top].dir;                       // ���������±꣬������ڼ�������
	int Dir = A.St[A.top].Dir[dir];                  // �����������ݣ���������
	int find, x, y;                                  // �ҵ�·����ǣ�����
	while (A.top > -1) {                             // ջ����ѭ��
		find = 0;
		while (dir < 4 && find == 0) {               // ����һ�����߷���
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
			A.St[A.top].dir = dir;                               // ����ֵ
			temp.x = x; temp.y = y; temp.dir = 0;
			Maze_MakeMaze_Random_GetDir(temp.Dir); 
			Maze_MakeMaze_Random_Fuzhi(A.St[++A.top], temp);     // ��һ�����߷����ջ
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
// ��ʼ���Թ���ͼΪ����ͨͼ
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
// ��ʾ����
void Maze_Meum_Play()
{
	int MAP[39][39];
	initgraph(800, 800);
	// ����Ϊ������ʾ����
	HRGN rgn_1 = CreateRectRgn(0, 0, 790, 10);    // ����һ��������
	setcliprgn(rgn_1);                            // ����rgn�������
	DeleteObject(rgn_1);                          // ɾ��rgn������
	solidrectangle(0, 0, 790, 10);                // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
	cleardevice();                                // �ñ�����ɫ����

	HRGN rgn_2 = CreateRectRgn(790, 0, 800, 790);    // ����һ��������
	setcliprgn(rgn_2);                            // ����rgn�������
	DeleteObject(rgn_2);                          // ɾ��rgn������
	solidrectangle(790, 0, 800, 790);                // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
	cleardevice();

	HRGN rgn_3 = CreateRectRgn(0, 10, 10, 790);    // ����һ��������
	setcliprgn(rgn_3);                            // ����rgn�������
	DeleteObject(rgn_3);                          // ɾ��rgn������
	solidrectangle(0, 10, 10, 790);                // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
	cleardevice();

	HRGN rgn_4 = CreateRectRgn(0, 790, 800, 800);    // ����һ��������
	setcliprgn(rgn_4);                            // ����rgn�������
	DeleteObject(rgn_4);                          // ɾ��rgn������
	solidrectangle(0, 790, 800, 800);                // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
	cleardevice();
	// ����Ϊ������
	HRGN rgn_5 = CreateRectRgn(10, 10, 790, 790);    // ����һ��������
	setcliprgn(rgn_5);                            // ����rgn�������
	DeleteObject(rgn_5);                          // ɾ��rgn������
	solidrectangle(10, 10, 790, 790);                // ��һ��ʵ�ĵľ���
	setbkcolor(RGB(50, 60, 25));                         // ����һ��������ɫ
	cleardevice();

	Maze_MakeMaze_Random(MAP, true);

	getchar();
}
// ������һ����ʼ����
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
// ��������������
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
// ��ӡ��ʾ����
void Maze_MakeMaze_Random_PrintWay(int x, int y)
{
	x = x * 20 + 10;
	y = y * 20 + 10;
	setcolor(LIGHTBLUE);
	setfillcolor(LIGHTBLUE);
	fillrectangle(x + 1, y + 1, x + 19, y + 19);
}
// �����ʾ����
void Maze_MakeMaze_Random_PrintClean(int x, int y)
{
	x = x * 20 + 10;
	y = y * 20 + 10;
	setcolor(RGB(50, 60, 25));
	setfillcolor(RGB(50, 60, 25));
	fillrectangle(x + 1, y + 1, x + 19, y + 19);
}
// ��B��ֵ��A
void Maze_MakeMaze_Random_Fuzhi(box_1 &A, box_1 &B)
{
	A.x = B.x;
	A.y = B.y;
	A.dir = B.dir;
	for (int i = 0; i < 4; i++) {
		A.Dir[i] = B.Dir[i];
	}
}
// �˵�����
int Maze_inti()
{
	initgraph(600, 800);
	// �������˵�����ͼƬ
	IMAGE end;
	loadimage(&end, L"meum.jpg", 600, 800, 0);
	putimage(0, 0, &end);
	// ����
	settextstyle(70, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(200, 50, L"���˵�");

	// ����button1��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 150, 450, 250 , 50, 50);
	// ��ť����
	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(200, 175, L"�Թ���Ϸ");

	// ����button2��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 300, 450, 400, 50, 50);
	// ��ť����
	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(150,325, L"�����Թ���ʾ");

	// ����button3��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 450, 450, 550, 50, 50);
	// ��ť����
	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(220, 475, L"DFS���");

	// ����button4��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(150, 600, 450, 700, 50, 50);
	// ��ť����
	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(220, 625, L"BFS���");

	// ����button5��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(425, 725, 575, 775, 50, 50);
	// ��ť����
	settextstyle(25, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(480, 735, L"�˳�");

	// ���������Ϣ
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
// ���˵��
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
	HRGN rgn = CreateRectRgn(800, 0, 1200, 800); // ����һ��������
	setcliprgn(rgn);                          // ����rgn�������
	DeleteObject(rgn);                        // ɾ��rgn������
											  //	solidrectangle(800, 0, 1200, 800);        // ��һ��ʵ�ĵľ���
	IMAGE imag;
	loadimage(&imag, L"Back_1.jpg", 400, 800, 0);
	putimage(800, 0, &imag);

	Maze_DFS_Button();                            // ����Ӧ�ĵط�����Button��ť

	// ����Ϊ������ʾ����
	HRGN rgn_1 = CreateRectRgn(0, 0, 790, 10);    // ����һ��������
	setcliprgn(rgn_1);                            // ����rgn�������
	DeleteObject(rgn_1);                          // ɾ��rgn������
	solidrectangle(0, 0, 790, 10);                // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
	cleardevice();                                // �ñ�����ɫ����

	HRGN rgn_2 = CreateRectRgn(790, 0, 800, 790);    // ����һ��������
	setcliprgn(rgn_2);                            // ����rgn�������
	DeleteObject(rgn_2);                          // ɾ��rgn������
	solidrectangle(790, 0, 800, 790);                // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
	cleardevice();

	HRGN rgn_3 = CreateRectRgn(0, 10, 10, 790);    // ����һ��������
	setcliprgn(rgn_3);                            // ����rgn�������
	DeleteObject(rgn_3);                          // ɾ��rgn������
	solidrectangle(0, 10, 10, 790);                // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
	cleardevice();

	HRGN rgn_4 = CreateRectRgn(0, 790, 800, 800);    // ����һ��������
	setcliprgn(rgn_4);                            // ����rgn�������
	DeleteObject(rgn_4);                          // ɾ��rgn������
	solidrectangle(0, 790, 800, 800);                // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
	cleardevice();
	// ����Ϊ������
	HRGN rgn_5 = CreateRectRgn(10, 10, 790, 790);    // ����һ��������
	setcliprgn(rgn_5);                            // ����rgn�������
	DeleteObject(rgn_5);                          // ɾ��rgn������
	solidrectangle(10, 10, 790, 790);                // ��һ��ʵ�ĵľ���
	setbkcolor(RGB(50, 60, 25));                         // ����һ��������ɫ
	cleardevice();
	int flag = 0;
	int mouse;
	do {
		mouse = Maze_Slove_Mouse();                    // ��������Ϣ
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
// BFS ����Թ�
void Maze_BFS()
{
	int MAP[39][39];
	initgraph(1200, 800);
	HRGN rgn = CreateRectRgn(800, 0, 1200, 800); // ����һ��������
	setcliprgn(rgn);                          // ����rgn�������
	DeleteObject(rgn);                        // ɾ��rgn������
											  //	solidrectangle(800, 0, 1200, 800);        // ��һ��ʵ�ĵľ���
	IMAGE imag;
	loadimage(&imag, L"Back_1.jpg", 400, 800, 0);
	putimage(800, 0, &imag);

	Maze_BFS_Button();                            // ����Ӧ�ĵط�����Button��ť                 // �ñ�����ɫ����

												  // ����Ϊ������ʾ����
	HRGN rgn_1 = CreateRectRgn(0, 0, 790, 10);    // ����һ��������
	setcliprgn(rgn_1);                            // ����rgn�������
	DeleteObject(rgn_1);                          // ɾ��rgn������
	solidrectangle(0, 0, 790, 10);                // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
	cleardevice();                                // �ñ�����ɫ����

	HRGN rgn_2 = CreateRectRgn(790, 0, 800, 790);    // ����һ��������
	setcliprgn(rgn_2);                            // ����rgn�������
	DeleteObject(rgn_2);                          // ɾ��rgn������
	solidrectangle(790, 0, 800, 790);                // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                         // ����һ��������ɫ
	cleardevice();

	HRGN rgn_3 = CreateRectRgn(0, 10, 10, 790);    // ����һ��������
	setcliprgn(rgn_3);                                 // ����rgn�������
	DeleteObject(rgn_3);                               // ɾ��rgn������
	solidrectangle(0, 10, 10, 790);                    // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                              // ����һ��������ɫ
	cleardevice();

	HRGN rgn_4 = CreateRectRgn(0, 790, 800, 800);       // ����һ��������
	setcliprgn(rgn_4);                                  // ����rgn�������
	DeleteObject(rgn_4);                                // ɾ��rgn������
	solidrectangle(0, 790, 800, 800);                   // ��һ��ʵ�ĵľ���
	setbkcolor(LIGHTRED);                               // ����һ��������ɫ
	cleardevice();
	// ����Ϊ������
	HRGN rgn_5 = CreateRectRgn(10, 10, 790, 790);        // ����һ��������
	setcliprgn(rgn_5);                                   // ����rgn�������
	DeleteObject(rgn_5);                                 // ɾ��rgn������
	solidrectangle(10, 10, 790, 790);                    // ��һ��ʵ�ĵľ���
	setbkcolor(RGB(50, 60, 25));                         // ����һ��������ɫ
	cleardevice();

	int flag = 0;
	int mouse;
	do {
		mouse = Maze_Slove_Mouse();                    // ��������Ϣ
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
// play �Ƿ���Ҫ��ʾ�����̣�CreateMaze�Ƿ���Ҫ�������һ���Թ���clean�Ƿ������ӡ��ķ���
void Maze_DFS_Solve(int MAP[][39], bool play,bool CreateMaze)
{
	int T = 20;                        // ��ʱ������
	box_1 start, end, temp;
	if (CreateMaze == false)
		Maze_MakeMaze_Random(MAP, false);    // �������һ���Թ�
	Maze_Print_Map(MAP);                     // ��ӡ�Թ�����
	stock A; A.top = -1;                 // ����һ��ջ
	Maze_Solve_GetStartEnd(start, end, MAP);           // ������һ�������һ���յ�
	if (play) {
		Maze_Print_Start_End(start.x, start.y, end.x, end.y);  // ��ӡ������յ�
		Sleep(2000);
	}
	temp.dir = 1;                                          // tempΪ��������
	Maze_MakeMaze_Random_Fuzhi(A.St[++A.top], start);      // ��Ԫ�ؽ�ջ
	if (play) {
		Maze_MakeMaze_Random_PrintWay(start.x, start.y);
		Sleep(T);
	}
	MAP[start.x][start.y] = -1;                           // �����Ԫ���Ѿ��߹�
	while (A.top > -1 && !(A.St[A.top].x == end.x && A.St[A.top].y == end.y)) {
		int find = 0;                                      // ����Ƿ��ҵ����߷���
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
	int T = 10; // ��ʱ������
	if (CreateMaze == false)
		Maze_MakeMaze_Random(MAP, false);          // �������һ���Թ�
	Maze_Print_Map(MAP);
	queue A;
	A.prior = -1; A.rear = -1;                      // ���岢�ҳ�ʼ��һ������
	box_1 temp, start, end;                            // ����������յ�͵�������
	Maze_Solve_GetStartEnd(start, end, MAP);           // ������һ�������һ���յ�
	Maze_MakeMaze_Random_Fuzhi(A.Qu[++A.rear], start);      // ��Ԫ�ؽ���
	MAP[A.Qu[A.rear].x][A.Qu[A.rear].y] = -1;                //  ����Ԫ�ر��
	if (play) {
		Maze_Print_Start_End(start.x, start.y, end.x, end.y);  // ��ӡ������յ�
		Sleep(2000);
	}
	if (play) {
		Maze_MakeMaze_Random_PrintWay(start.x, start.y);           // ��ӡ��Ԫ��
		Sleep(T);
	}
	while (A.rear != A.prior) {
		A.prior++;                            // ��Ԫ�س���
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
				Maze_MakeMaze_Random_Fuzhi(A.Qu[++A.rear], temp);     // �ҵ���Ԫ�ض�
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
	// ����button1��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 50, 1150, 100, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(895, 60 , L"�����Թ�(����ʾ����)");

	// ����button2��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 150, 1150, 200, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(905, 160, L"�����Թ�(��ʾ����)");

	// ����button3��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 250, 1150, 300, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(930, 260, L"DFS������");

	// ����button4��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 350, 1150, 400, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(945, 360, L"�������˵�");
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
	// ����button1��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 50, 1150, 100, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(895, 60, L"�����Թ�(����ʾ����)");

	// ����button2��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 150, 1150, 200, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(905, 160, L"�����Թ�(��ʾ����)");

	// ����button3��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 250, 1150, 300, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(930, 260, L"BFS������");

	// ����button4��ť
	setfillcolor(LIGHTGRAY);
	setcolor(BLACK);
	fillroundrect(850, 350, 1150, 400, 50, 50);
	// ��ť����
	settextstyle(30, 0, L"΢���ź�");
	setbkmode(TRANSPARENT);           // ��������͸�����
	settextcolor(BLACK);
	outtextxy(945, 360, L"�������˵�");
}
