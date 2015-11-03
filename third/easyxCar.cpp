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
	virtual void Draw() {};
	virtual void Hide() {};
	virtual void Move() {};
}; 

class Circle :public Figure//构造圆类
{
private:
	int x, y;//圆的坐标
	int radius;//圆的半径
public:
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
	Figure *node[10];
	int size;
	FigureLink():size(0){}
	void Insert(Figure *a)
	{
		node[size++] = a;
	}
};

class vechiel
{public:
	FigureLink contents;
	virtual void Draw(){}
	virtual void Move(int dx,int dy){}
	virtual void Hide(){}
	virtual void Defaultvechiel(){}
};

class Car :public vechiel
{
private:
	int wheel_size;
	int xstart;
	int ystart;
	int origin_x;
	int origin_y;
public:
	Car(int x, int y, int w) :origin_x(x), origin_y(y)
	{
		wheel_size = w;
		xstart = x;
		ystart = y;
		Circle c1=Circle(xstart, ystart, wheel_size); 
		Circle c2= Circle(xstart + 9 * wheel_size, ystart, wheel_size);
		Figure *a = &c1;
		Figure *b = &c2;
		contents.Insert(a); 
		contents.Insert(b); 
		Rectangles rec1=Rectangles(xstart - 3.5*wheel_size, ystart - 3 * wheel_size, xstart + 12.5*wheel_size, ystart - wheel_size);
		Rectangles rec2=Rectangles(xstart + wheel_size, ystart - 5 * wheel_size, xstart + 8 * wheel_size, ystart - 3 * wheel_size);
		Figure *c = &rec1;
		Figure *d = &rec2;
		contents.Insert(c); 
		contents.Insert(d); 
		Triangle t1=Triangle(xstart + wheel_size, ystart - 5 * wheel_size, xstart - wheel_size, ystart - 3 * wheel_size);
		Triangle t2=Triangle(xstart + 8 * wheel_size, ystart - 5 * wheel_size, xstart + 10 * wheel_size, ystart - 3 * wheel_size);
		Figure *e =& t1;
		Figure *f = &t2;
		contents.Insert(e);
		contents.Insert(f); 
	}

	void Draw()
	{
		contents.size = 0;
		Circle c1 = Circle(xstart, ystart, wheel_size);
		Circle c2 = Circle(xstart + 9 * wheel_size, ystart, wheel_size);
		Figure *a = &c1;
		Figure *b = &c2;
		contents.Insert(a);
		contents.Insert(b);
		Rectangles rec1 = Rectangles(xstart - 3.5*wheel_size, ystart - 3 * wheel_size, xstart + 12.5*wheel_size, ystart - wheel_size);
		Rectangles rec2 = Rectangles(xstart + wheel_size, ystart - 5 * wheel_size, xstart + 8 * wheel_size, ystart - 3 * wheel_size);
		Figure *c = &rec1;
		Figure *d = &rec2;
		contents.Insert(c);
		contents.Insert(d);
		Triangle t1 = Triangle(xstart + wheel_size, ystart - 5 * wheel_size, xstart - wheel_size, ystart - 3 * wheel_size);
		Triangle t2 = Triangle(xstart + 8 * wheel_size, ystart - 5 * wheel_size, xstart + 10 * wheel_size, ystart - 3 * wheel_size);
		Figure *e = &t1;
		Figure *f = &t2;
		contents.Insert(e);
		contents.Insert(f);
		for (int i = 0; i < contents.size; i++)
			contents.node[i]->Draw();
	}
	void Hide()
	{
		contents.size = 0;
		Circle c1 = Circle(xstart, ystart, wheel_size);
		Circle c2 = Circle(xstart + 9 * wheel_size, ystart, wheel_size);
		Figure *a = &c1;
		Figure *b = &c2;
		contents.Insert(a);
		contents.Insert(b);
		Rectangles rec1 = Rectangles(xstart - 3.5*wheel_size, ystart - 3 * wheel_size, xstart + 12.5*wheel_size, ystart - wheel_size);
		Rectangles rec2 = Rectangles(xstart + wheel_size, ystart - 5 * wheel_size, xstart + 8 * wheel_size, ystart - 3 * wheel_size);
		Figure *c = &rec1;
		Figure *d = &rec2;
		contents.Insert(c);
		contents.Insert(d);
		Triangle t1 = Triangle(xstart + wheel_size, ystart - 5 * wheel_size, xstart - wheel_size, ystart - 3 * wheel_size);
		Triangle t2 = Triangle(xstart + 8 * wheel_size, ystart - 5 * wheel_size, xstart + 10 * wheel_size, ystart - 3 * wheel_size);
		Figure *e = &t1;
		Figure *f = &t2;
		contents.Insert(e);
		contents.Insert(f);
		for (int i = 0; i < contents.size; i++)
			contents.node[i]->Hide();
	}
	void Move(int dx,int dy)
	{
		
		Hide();
		xstart = dx;
		ystart = dy;
		Draw();
	}
	void Defaultvechiel()
	{
		xstart = origin_x;
		ystart = origin_y;
	}
};


class Truck :public vechiel
{
private:
	int wheel_size;
	int xstart;
	int ystart;
	int origin_x;
	int origin_y;
public:
	Truck(int x, int y, int w) :origin_x(x), origin_y(y)
	{
		wheel_size = w;
		xstart = x;
		ystart = y;
	}
	void Draw()
	{
		contents.size = 0;
		Circle c1 = Circle(xstart, ystart, wheel_size);
		Circle c2 = Circle(xstart + 2.5*wheel_size, ystart, wheel_size);
		Circle c3 = Circle(xstart + 11.5*wheel_size, ystart, wheel_size);
		Circle c4 = Circle(xstart + 14 * wheel_size, ystart, wheel_size);
		Circle c5 = Circle(xstart + 20 * wheel_size + 2, ystart, wheel_size);
		Figure *a = &c1;
		Figure *b = &c2;
		Figure *c = &c3;
		Figure *d = &c4;
		Figure *e = &c5;
		contents.Insert(a);
		contents.Insert(b);
		contents.Insert(c);
		contents.Insert(d);
		contents.Insert(e);
		Rectangles rec1(xstart - 2 * wheel_size, ystart - 9 * wheel_size, xstart + 16 * wheel_size, ystart - wheel_size);
		Rectangles rec2(xstart + 16 * wheel_size + 2, ystart - 7 * wheel_size, xstart + 20 * wheel_size + 2, ystart - wheel_size);
		Figure *f = &rec1;
		Figure *g = &rec2;
		contents.Insert(f);
		contents.Insert(g);
		for (int i = 0; i < contents.size; i++)
			contents.node[i]->Draw();
	}
	void Hide()
	{
		contents.size = 0;
		Circle c1 = Circle(xstart, ystart, wheel_size);
		Circle c2 = Circle(xstart + 2.5*wheel_size, ystart, wheel_size);
		Circle c3 = Circle(xstart + 11.5*wheel_size, ystart, wheel_size);
		Circle c4 = Circle(xstart + 14 * wheel_size, ystart, wheel_size);
		Circle c5 = Circle(xstart + 20 * wheel_size + 2, ystart, wheel_size);
		Figure *a = &c1;
		Figure *b = &c2;
		Figure *c = &c3;
		Figure *d = &c4;
		Figure *e = &c5;
		contents.Insert(a);
		contents.Insert(b);
		contents.Insert(c);
		contents.Insert(d);
		contents.Insert(e);
		Rectangles rec1(xstart - 2 * wheel_size, ystart - 9 * wheel_size, xstart + 16 * wheel_size, ystart - wheel_size);
		Rectangles rec2(xstart + 16 * wheel_size + 2, ystart - 7 * wheel_size, xstart + 20 * wheel_size + 2, ystart - wheel_size);
		Figure *f = &rec1;
		Figure *g = &rec2;
		contents.Insert(f);
		contents.Insert(g);
		for (int i = 0; i < contents.size; i++)
			contents.node[i]->Hide();
	}
	void Move(int dx, int dy)
	{
		Hide();
		xstart = dx;
		ystart = dy;
		Draw();
	}
	void Defaultvechiel()
	{
		xstart = origin_x;
		ystart = origin_y;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int xstart=70, ystart, wheel_size=7;
	//cout << "请输入车轮的大小（半径）:" << endl;
	//cin >> wheel_size;
	//cout << "请输入起始位置坐标(50<x<780;)：" << endl;
	//cin >> xstart;
	xstart = xstart + wheel_size;
	ystart = 500 - wheel_size;
	initgraph(800, 600);
	//circle(700,500,20);
	//circle(30,30,20);
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
	bool pause = false;
	Car car1(xstart, ystart, wheel_size); 
	Truck truck1(xstart, ystart, wheel_size); 
	vechiel *v=&truck1;
	int one = 0;
	int ms = 1500;

	char two;
	while (one != '3')
	{
		one = _getch();
		if (one =='1') {
			v = &car1; v->Defaultvechiel(); v->Draw();
		}
		if (one == '2') {
			v = &truck1; v->Defaultvechiel(); v->Draw();
		}
		if (one == '1'|| one =='2')
		{
			two = _getch();
			if (two=='s')
			for (int i = xstart; i < 780; i += 50)
			{
				v->Move(i, ystart);
				Sleep(ms);
				if (_kbhit()) 
				{ two = _getch(); 
				if (two == 'e') { v->Hide(); break; }
				if (two == 'p')
				{
					pause = true;
					while (pause == true)
					{
						two = _getch();
						if (two == 'p')
							pause = !pause;
					}
				}
				if (two == '+') ms = ms-200;
				if (two == '-') ms = ms + 200;
				}
			}
		
		}
	}
	closegraph();
	return 0;
}
