#include "Poly.h"

void readFromFile(string fileName, Polygon &poly, vector<Point> &M)
{
	fstream fin;
	fin.open(fileName, ios::in);

	fin >> poly.n;
	int data_x, data_y;
	vector<Point> s;
	for (int i = 0; i < poly.n; i++)
	{
		fin >> data_x;
		fin >> data_y;
		s.push_back(Point(data_x, data_y));
	}
	poly = Polygon(s, s.size());

	int n;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> data_x;
		fin >> data_y;
		M.push_back(Point(data_x, data_y));
	}
	fin.close();
}