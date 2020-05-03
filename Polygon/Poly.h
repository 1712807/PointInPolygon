#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <fstream>

class Point
{
public:
	int x;
	int y;
public:
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
	bool operator !=(Point p)
	{
		if (this->x == p.x && this->y == p.y) return false;
		return true;
	}
	void pri()
	{
		cout << x << " " << y << endl;
	}
};

class Polygon
{
public:
	vector<Point> p;
	int n;
public:
	Polygon(vector<Point> point, int size)
	{
		n = size;

		for (int i = 0; i < n; i++)
		{
			p.push_back(Point(point[i].x, point[i].y));
		}
	}
	Polygon(Polygon& po)
	{
		n = po.n;
		for (int i = 0; i < n; i++)
		{
			p.push_back(Point(po.p[i].x, po.p[i].y));
		}
	}

	int getY_Min();

	int getY_Max();

	vector<Point> findToFX(Point M, int &left, int &right);
};

int compare(Point M, Polygon& po);
void readFromFile(string fileName, Polygon &poly, vector<Point> &M);
