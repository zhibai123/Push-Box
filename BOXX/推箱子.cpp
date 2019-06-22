#undef UNICODE
#undef _UNICODE

#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
//1.��λ����ѵ�ͼ���Ƴ���
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
int cos = 0;		//���ƹؿ�
//0.bmp  1.bmp 3.bmp
int imgURLIndex[6] = { 0, 1, 3, 4, 5, 7 };
void loadResource()
{
	//������
	for (int i = 0; i < 6; i++)
	{
		char fileName[20] = "";
		//printf:��ӡ����Ļ
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
	//��λ�������
	int i, j;		//������ֵ��5��8 ʱ������
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (map[cos][i][j] == 5 || map[cos][i][j] == 8)
			{
				break;  //break����һ��ѭ��
			}
		}
		if (map[cos][i][j] == 5 || map[cos][i][j] == 8)
		{
			break;
		}
	}
	char userKey = _getch();
	//С���̣�72 80 75 77
	switch (userKey)
	{
	case 'w':
	case 'W':
	case 72:
		//ʲôʱ���ܶ��������ǿյ�0����Ŀ�ĵ�3
		if (map[cos][i - 1][j] == 0 || map[cos][i - 1][j] == 3)
		{
			//��������ô�ߵ�
			map[cos][i][j] -= 5;
			map[cos][i - 1][j] += 5;
		}
		//������ ��4  ����+Ŀ�ģ�7
		else if (map[cos][i - 1][j] == 4 || map[cos][i - 1][j] == 7)
		{
			if (map[cos][i - 2][j] == 0 || map[cos][i - 2][j] == 3)
			{
				//��������ô�ߵ�
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
			//��������ô�ߵ�
			map[cos][i][j] -= 5;
			map[cos][i + 1][j] += 5;
		}
		//������ ��4  ����+Ŀ�ģ�7
		else if (map[cos][i + 1][j] == 4 || map[cos][i + 1][j] == 7)
		{
			if (map[cos][i + 2][j] == 0 || map[cos][i + 2][j] == 3)
			{
				//��������ô�ߵ�
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
			//��������ô�ߵ�
			map[cos][i][j] -= 5;
			map[cos][i][j - 1] += 5;
		}
		//������ ��4  ����+Ŀ�ģ�7
		else if (map[cos][i][j - 1] == 4 || map[cos][i][j - 1] == 7)
		{
			if (map[cos][i][j - 2] == 0 || map[cos][i][j - 2] == 3)
			{
				//��������ô�ߵ�
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
			//��������ô�ߵ�
			map[cos][i][j] -= 5;
			map[cos][i][j + 1] += 5;
		}
		else if (map[cos][i][j + 1] == 4 || map[cos][i][j + 1] == 7)
		{
			if (map[cos][i][j + 2] == 0 || map[cos][i][j + 2] == 3)
			{
				//��������ô�ߵ�
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