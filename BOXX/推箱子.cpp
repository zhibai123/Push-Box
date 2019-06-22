#undef UNICODE
#undef _UNICODE

#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
//1.二位数组把地图绘制出来
int  map[3][7][8] =
{
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 3, 4, 0, 0, 4, 3, 1,
	1, 0, 1, 0, 1, 1, 0, 1,
	1, 0, 0, 5, 4, 3, 0, 1,
	1, 0, 1, 0, 1, 1, 0, 1,
	1, 3, 4, 0, 0, 4, 3, 1,
	1, 1, 1, 1, 1, 1, 1, 1,

	1, 1, 1, 1, 1, 1, 1, 1,
	1, 3, 4, 0, 0, 4, 3, 1,
	1, 0, 1, 0, 1, 1, 0, 1,
	1, 3, 4, 5, 4, 3, 0, 1,
	1, 0, 1, 0, 1, 1, 0, 1,
	1, 3, 4, 0, 0, 4, 3, 1,
	1, 1, 1, 1, 1, 1, 1, 1,

	1, 1, 1, 1, 1, 1, 1, 1,
	1, 3, 4, 0, 0, 4, 3, 1,
	1, 0, 1, 0, 4, 3, 0, 1,
	1, 3, 4, 5, 4, 3, 0, 1,
	1, 0, 1, 0, 1, 1, 0, 1,
	1, 3, 4, 0, 0, 4, 3, 1,
	1, 1, 1, 1, 1, 1, 1, 1
};
IMAGE img[6];
int cos = 0;		//控制关卡
//0.bmp  1.bmp 3.bmp
int imgURLIndex[6] = { 0, 1, 3, 4, 5, 7 };
void loadResource()
{
	//批处理
	for (int i = 0; i < 6; i++)
	{
		char fileName[20] = "";
		//printf:打印到屏幕
		//0.bmp  1.bmp
		sprintf(fileName, "%d.bmp", imgURLIndex[i]);
		loadimage(img + i, fileName);
	}
}
void drawMap()
{
	int x, y;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			x = 64 * j;
			y = 64 * i;
			switch (map[cos][i][j])
			{
			case 0:
				putimage(x, y, img + 0);
				break;
			case 1:
				putimage(x, y, img + 1);
				break;
			case 3:
				putimage(x, y, img + 2);
				break;
			case 4:
				putimage(x, y, img + 3);
				break;
			case 5:
			case 8:
				putimage(x, y, img + 4);
				break;
			case 7:
				putimage(x, y, img + 5);
				break;
			}
		}
	}
}
void  keyDown()
{
	//定位人在哪里？
	int i, j;		//数组中值是5和8 时候是人
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (map[cos][i][j] == 5 || map[cos][i][j] == 8)
			{
				break;  //break跳出一层循环
			}
		}
		if (map[cos][i][j] == 5 || map[cos][i][j] == 8)
		{
			break;
		}
	}
	char userKey = _getch();
	//小键盘：72 80 75 77
	switch (userKey)
	{
	case 'w':
	case 'W':
	case 72:
		//什么时候能动？上面是空地0或者目的地3
		if (map[cos][i - 1][j] == 0 || map[cos][i - 1][j] == 3)
		{
			//能走是怎么走的
			map[cos][i][j] -= 5;
			map[cos][i - 1][j] += 5;
		}
		//是箱子 ：4  箱子+目的：7
		else if (map[cos][i - 1][j] == 4 || map[cos][i - 1][j] == 7)
		{
			if (map[cos][i - 2][j] == 0 || map[cos][i - 2][j] == 3)
			{
				//能走是怎么走的
				map[cos][i][j] -= 5;
				map[cos][i - 1][j] += 1;
				map[cos][i - 2][j] += 4;
			}
		}
		break;
	case 's':
	case 'S':
	case 80:
		if (map[cos][i + 1][j] == 0 || map[cos][i + 1][j] == 3)
		{
			//能走是怎么走的
			map[cos][i][j] -= 5;
			map[cos][i + 1][j] += 5;
		}
		//是箱子 ：4  箱子+目的：7
		else if (map[cos][i + 1][j] == 4 || map[cos][i + 1][j] == 7)
		{
			if (map[cos][i + 2][j] == 0 || map[cos][i + 2][j] == 3)
			{
				//能走是怎么走的
				map[cos][i][j] -= 5;
				map[cos][i + 1][j] += 1;
				map[cos][i + 2][j] += 4;
			}
		}
		break;
	case 'A':
	case 'a':
	case 75:
		if (map[cos][i][j - 1] == 0 || map[cos][i][j - 1] == 3)
		{
			//能走是怎么走的
			map[cos][i][j] -= 5;
			map[cos][i][j - 1] += 5;
		}
		//是箱子 ：4  箱子+目的：7
		else if (map[cos][i][j - 1] == 4 || map[cos][i][j - 1] == 7)
		{
			if (map[cos][i][j - 2] == 0 || map[cos][i][j - 2] == 3)
			{
				//能走是怎么走的
				map[cos][i][j] -= 5;
				map[cos][i][j - 1] += 1;
				map[cos][i][j - 2] += 4;
			}
		}
		break;
	case 'd':
	case 'D':
	case 77:
		if (map[cos][i][j + 1] == 0 || map[cos][i][j + 1] == 3)
		{
			//能走是怎么走的
			map[cos][i][j] -= 5;
			map[cos][i][j + 1] += 5;
		}
		else if (map[cos][i][j + 1] == 4 || map[cos][i][j + 1] == 7)
		{
			if (map[cos][i][j + 2] == 0 || map[cos][i][j + 2] == 3)
			{
				//能走是怎么走的
				map[cos][i][j] -= 5;
				map[cos][i][j + 1] += 1;
				map[cos][i][j + 2] += 4;
			}
		}
		break;
	}
}
int gameOver()
{
	int count = 1;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[cos][i][j] == 4)
			{
				count = 0;
				return count;
			}
		}
	}
	return count;
}

int main()
{
	initgraph(64 * 8, 64 * 7);
	loadResource();

	while (1)
	{
		drawMap();
		keyDown();
		if (gameOver())
		{
			drawMap();
			cos++;
			if (cos == 3)
				break;
		}
	}
	outtextxy(100, 100, ("GameOver"));
	getchar();
	closegraph();
	return 0;
}