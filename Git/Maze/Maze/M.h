#pragma once

typedef struct box_1 
{
	int x;
	int y;
	int Dir[4];
	int dir;
}box_1;

typedef struct box_2 
{
	int x;
	int y;
	char dir;
}box_2;

typedef struct {
	int top;
	box_1 St[1600];
}stock;         // ջ���ݽṹ

typedef struct {
	box_1 Qu[1600];
	int rear;
	int prior;
}queue;
int Maze_inti();
int Maze_Init_GameEnd(int Time = 0);
int Maze_Slove_Mouse();
void Maze_Inti_Game();
void Maze_Print_Box(int x, int y);
void Maze_Print_Start_End(int x_1, int y_1, int x_2, int y_2);
void Maze_Game_Move(box_2 &A,char ch);
void Maze_Print_user(int x, int y);
void Maze_Print_Map(int xyz[][39]);
void Maze_Print_Clear(int x, int y); 
void Maze_Game();
void Maze_Game_GetStartEnd(box_2 &start, box_2 &end, int MAP[][39]);
void Maze_MakeMaze_Random(int MAP[][39], bool play);
void Maze_MakeMaze_Random_init(int MAP[][39]); 
void Maze_Meum_Play();  
void Maze_MakeMaze_Random_GetStart(box_2 &start);
void Maze_MakeMaze_Random_GetDir(int Dir[4]);
void Maze_MakeMaze_Random_PrintWay(int x, int y);
void Maze_MakeMaze_Random_PrintClean(int x, int y);
void Maze_MakeMaze_Random_Fuzhi(box_1 &A, box_1 &B);
void Maze();
void Maze_DFS();
void Maze_BFS();
void Maze_DFS_Solve(int MAP[][39], bool play, bool CreateMaze);
void Maze_BFS_Solve(int MAP[][39], bool play, bool CreateMaze);
void Maze_Solve_GetStartEnd(box_1 &start, box_1 &end, int MAP[][39]);
bool Maze_Is_Way(int Map[][39], box_2 &re);
void Maze_DFS_Button();
void Maze_BFS_Button();
