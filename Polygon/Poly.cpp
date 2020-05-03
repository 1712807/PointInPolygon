#include "Poly.h"

int Polygon::getY_Min()
{
	int y_min = 0;
	for (int i = 1; i < n; i++)
	{
		if (p[i].y < p[y_min].y || (p[i].y == p[y_min].y && p[i].x < p[y_min].x))
		{
			y_min = i;
		}
	}
	return y_min;
}

int  Polygon::getY_Max()
{
	int y_max = 0;
	for (int i = 1; i < n; i++)
	{
		if (p[i].y > p[y_max].y || (p[i].y == p[y_max].y && p[i].x > p[y_max].x))
		{
			y_max = i;
		}
	}
	return y_max;
}

// tim cap canh giao voi f(x) = duong thang qua diem dang xet (M)
vector<Point> Polygon::findToFX(Point M, int &left, int &right)
{
	vector<Point> tmp;
	
	if (right >= left)
	{
		int mid = left + (right - left) / 2;
		Point X = p[mid - 1], Y = p[mid];
		if (X.y == M.y || Y.y == M.y || ((X.y < M.y) && (Y.y > M.y)))
		{
			tmp.push_back(X);
			tmp.push_back(Y);
			return tmp;
		}
		if (X.y < M.y && Y.y < M.y)
		{
			left = mid + 1;
			return findToFX(M, left, right);
		}
		else
		{
			right = mid - 1;
			return findToFX(M, left, right);
		}

	}
}

double S(vector<Point> po)
{
	int value1 = po[0].x * (po[2].y - po[1].y);
	int value2 = po[1].x * (po[0].y - po[2].y);
	int value3 = po[2].x * (po[1].y - po[0].y);
	return (double)(value1 + value2 + value3) / 2;
}

int compare(Point M, Polygon& po)
{
	int index_A = po.getY_Min();
	int index_B = po.getY_Max();
	
	if (M.y < po.p[index_A].y || M.y > po.p[index_B].y) return 0;// nam ngoai da giac
	else
	{
		vector<Point> tmp;
		vector<Point> t;
		int left, right;

		// 1 canh cat f(x) 
		if (index_A > index_B)
		{
			left = index_B;
			right = index_A;
		}
		else
		{
			left = index_A;
			right = index_B;
		}

		t = po.findToFX(M, left, right);
		tmp.push_back(t[0]);
		tmp.push_back(t[1]);

		// AB la 1 canh cua da giac
		if (abs(index_A - index_B) == 1 || abs(index_A - index_B) == po.n - 1)
		{
			tmp.push_back(po.p[index_A]);
			tmp.push_back(po.p[index_B]);
			cout << "aaaa" << endl;
		}
		// AB la duong cheo
		else
		{
			t.clear();
			for (int i = left; i >= 0; i--)
			{
				t.push_back(po.p[i]);
			}
			for (int i = po.n - 1; i >= right; i--)
			{
				t.push_back(po.p[i]);
			}

			Polygon poly_tmp(t, t.size());
			left = 0, right = t.size() - 1;
			t.clear();
			t = poly_tmp.findToFX(M, left, right);

			tmp.push_back(t[1]);
			tmp.push_back(t[0]);
		}

	/*	
		for (int i = 0; i < tmp.size(); i++)
			tmp[i].pri();*/

		Polygon poly(tmp, tmp.size());
		Point T1 = poly.p[0];
		Point T2 = poly.p[1];
		Point T3 = poly.p[2];
		Point T4 = poly.p[3];
		
		vector<Point> T1MT2;
		T1MT2.push_back(T1);
		T1MT2.push_back(M);
		T1MT2.push_back(T2);
		
		vector<Point> T2MT3;
		T2MT3.push_back(T2);
		T2MT3.push_back(M);
		T2MT3.push_back(T3);
	
		vector<Point> T3MT4;
		T3MT4.push_back(T3);
		T3MT4.push_back(M);
		T3MT4.push_back(T4);
		
		vector<Point> T4MT1;
		T4MT1.push_back(T4);
		T4MT1.push_back(M);
		T4MT1.push_back(T1);
		
		if (((S(T1MT2) < 0 && (S(T2MT3) < 0 || S(T2MT3) == 0) && S(T3MT4) < 0 && (S(T4MT1) < 0 || S(T4MT1) == 0))
			|| (S(T1MT2) > 0 && (S(T2MT3) > 0 || S(T2MT3) == 0) && S(T3MT4) > 0 && (S(T4MT1) > 0 || S(T4MT1) == 0)))
			&& M != T1 && M != T2 && M != T3 && M != T4)
		{
			return 1;
		}
		else return 0;
	}
}