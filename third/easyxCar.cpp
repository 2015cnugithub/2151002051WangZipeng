// easyxCar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <Windows.h>
using namespace std;




class Figure//构造一个画图基类
{
public:
	virtual void Draw() {}
	virtual void Hide() {}
	virtual void Move() {}
}; 

class Circle :public Figure//构造圆类
{
private:
	int x, y;//圆的坐标
	int radius;//圆的半径
public:
	Circle(){}
	Circle(int nx, int ny, int nr)
	{
		x = nx;
		y = ny;
		radius = nr;
	}
	void Move(int dx, int dy)
	{
		x = dx;
		y = dy;
	}
	void Draw()
	{
		circle(x, y, radius);
	}
	void Hide()
	{
		clearcircle(x, y, radius + 1);
	}
};//构造圆类

class Rectangles :public Figure//构造四边形类
{
private:
	int left, right, top, bottom;
public:
	Rectangles(){}
	Rectangles(int l, int t, int r, int b)
	{
		left = l;
		right = r;
		top = t;
		bottom = b;
	}
	void Draw()
	{
		rectangle(left, top, right, bottom);
	}
	void Move(int dl, int dt, int dr, int db)
	{
		left = dl;
		right = dr;
		top = dt;
		bottom = db;
	}

	void Hide()
	{
		clearrectangle(left, top, right, bottom);
	}
};//构造四边形类//构造四边形类

class Triangle :public Figure//画三角的类
{
private:
	int px;
	int py;
	int qx;
	int qy;
public:
	Triangle(){}
	Triangle(int npx, int npy,int nqx,int nqy)
	{
		px = npx;
		py = npy;
		qx = nqx;
		qy = nqy;
	}
	void Draw()
	{
		line(px, py, qx, qy);
	}
	void Move(int npx, int npy, int nqx, int nqy)
	{
		px = npx;
		py = npy;
		qx = nqx;
		qy = nqy;
	}
	void Hide()
	{
		setlinecolor(getbkcolor());
		line(px, py, qx, qy);
		graphdefaults();
	}

};

class FigureLink
{
public:
	Figure *node;
	int size;
	FigureLink(){}
	void setFiureLink(int s)
	{
		size = s;
		node = new Figure[size];
	}
	FigureLink(int size) :size(size)
	{
		node = new Figure[size];
	}
	FigureLink(FigureLink *p)
	{
		node = p->node;
	}
	void Insert(Figure *a,int i)
	{
		node[i] = *a;
	}
};
class vechiel
{public:
	FigureLink *contents;
	void Draw(){}
	void Move(int dx,int dy){}
	void Hide(){}
};

class Car :public vechiel
{
private:
	int wheel_size;
	int xstart;
	int ystart;
public:
	
	Car(int w, int x, int y)
	{
		contents->setFiureLink(6);
		wheel_size = w;
		xstart = x;
		ystart = y;
		Circle c1(xstart, ystart, wheel_size);
		Circle c2(xstart + 9 * wheel_size, ystart, wheel_size);
		Figure *a = &c1;
		Figure *b = &c2;
		contents->Insert(a,0);
		contents->Insert(b,1);
		Rectangles rec1(xstart - 3.5*wheel_size, ystart - 3 * wheel_size, xstart + 12.5*wheel_size, ystart - wheel_size);
		Rectangles rec2(xstart + wheel_size, ystart - 5 * wheel_size, xstart + 8 * wheel_size, ystart - 3 * ystart);
		Figure *c = &rec1;
		Figure *d = &rec2;
		contents->Insert(c,2);
		contents->Insert(d,3);
		Triangle t1(xstart + wheel_size, ystart - 5 * wheel_size, xstart - wheel_size, ystart - 3 * wheel_size);
		Triangle t2(xstart + 8 * wheel_size, ystart - 5 * wheel_size, xstart + 10 * wheel_size, ystart - 3 * wheel_size);
		Figure *e = &t1;
		Figure *f = &t2;
		contents->Insert(e,4);
		contents->Insert(f,5);
	}
	void Draw()
	{
		for (int i = 0; i < 6; i++)
			contents->node->Draw();
	}
	void Hide()
	{
		for (int i = 0; i < 6; i++)
			contents->node->Hide();
	}
	void Move(int dx,int dy)
	{
		xstart = dx;
		ystart = dy;
		Hide();
		Draw();
	}
	
};


class Truck :public vechiel
{
private:
	int wheel_size;
	int xstart;
	int ystart;
public:
	Truck(int w, int x, int y)
	{
		contents->setFiureLink(7);
		wheel_size = w;
		xstart = x;
		ystart = y;
		Circle c1(xstart, ystart, wheel_size);
		Circle c2(xstart+2.5*wheel_size,ystart,wheel_size);
		Circle c3(xstart+11.5*wheel_size,ystart,wheel_size);
		Circle c4(xstart+14*wheel_size,ystart,wheel_size);
		Circle c5(xstart+20*wheel_size+2,ystart,wheel_size);
		Figure *a = &c1;
		Figure *b = &c2;
		Figure *c = &c3;
		Figure *d = &c4;
		Figure *e = &c5;
		contents->Insert(a,0);
		contents->Insert(b,1);
		contents->Insert(c,2);
		contents->Insert(d,3);
		contents->Insert(e,4);
		Rectangles rec1(xstart-2*wheel_size,ystart-9*wheel_size,xstart+16*wheel_size,ystart-wheel_size);
		Rectangles rec2(xstart+16*wheel_size+2,ystart-7*wheel_size,xstart+20*wheel_size+2,ystart-wheel_size);
		Figure *f = &rec1;
		Figure *g = &rec2;
		contents->Insert(f,5);
		contents->Insert(g,6);
	}
	void Draw()
	{
		for (int i = 0; i < 7; i++)
			contents->node->Draw();
	}
	void Hide()
	{
		for (int i = 0; i < 7; i++)
			contents->node->Hide();
	}
	void Move(int dx, int dy)
	{
		xstart = dx;
		ystart = dy;
		Hide();
		Draw();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int xstart, ystart, wheel_size;
	cout << "请输入车轮的大小（半径）:" << endl;
	cin >> wheel_size;
	cout << "请输入起始位置坐标(21<x<780;)：" << endl;
	cin >> xstart;
	ystart = 500 - wheel_size;
	initgraph(800, 600);
	outtext(_T("1Car   2 Truck   3 Exit"));
	line(20, 20, 20, 580);
	line(20, 580, 780, 580);
	line(780, 580, 780, 20);
	line(20, 20, 780, 20);
	moveto(21, 21);
	outtext(_T("Press <S> key to start moving "));
	moveto(21, 40);
	outtext(_T("Press <P> key to pause/continue moving "));
	moveto(21, 60);
	outtext(_T("Press <E> key to end moving "));
	moveto(21, 80);
	outtext(_T("Press <+> key to speed up"));
	moveto(21, 100);
	outtext(_T("Press <-> key to speed down "));
	setlinestyle(PS_SOLID, 5);
	line(21, 500, 780, 500);
	graphdefaults();
	//line()
	//circle(20, 20, 20);
	int contral = 0;
	int choose = 0;
	int ms = 150;
	bool pause = false;
	Car car1(xstart, ystart, wheel_size);
	Truck truck1(xstart, ystart, wheel_size);
	vechiel *v = &car1;
	while (choose != 3)
	{
		switch (choose)
		{
		case 1:
		{
				  v = &car1;
				  v->Draw();
				  while (contral != 'E' || contral != 'e')
				  {
					  switch (contral)
					  {
					  case 's':
					  {
								  for (int i = 20; i < 700; i++)
								  {
									  v->Move(i, ystart);
									  Sleep(ms);
								  }


					  }
					  case 'p':
					  {
								  pause = !pause;
								  while (pause == true)
								  {
									  int p = _getch();
									  if (p == 'p') pause = false;
								  }
					  }
					  case '+':
					  {
								  ms = ms - 10;
								  if (ms < 20) ms = 20;
					  }
					  case '-':
					  {
								  ms = ms + 10;
								  if (ms>300) ms = 300;
					  }
					  }
					  if (_kbhit())
						  contral = _getch();
				  }

		}
		case 2:
		{
				  v = &truck1;
				  v->Draw();
				  while (contral != 'E' || contral != 'e')
				  {
					  switch (contral)
					  {
					  case 's':
					  {
								  for (int i = 20; i < 700; i++)
								  {
									  v->Move(i, ystart);
									  Sleep(ms);
								  }


					  }
					  case 'p':
					  {
								  pause = !pause;
								  while (pause == true)
								  {
									  int p = _getch();
									  if (p == 'p') pause = false;
								  }
					  }
					  case '+':
					  {
								  ms = ms - 10;
								  if (ms < 20) ms = 20;
					  }
					  case '-':
					  {
								  ms = ms + 10;
								  if (ms>300) ms = 300;
					  }
					  }
					  if (_kbhit())
						  contral = _getch();
				  }

		}
		}
		if (_kbhit())
			choose = _getch();
	}
	//_getch();
	closegraph();
	return 0;
}