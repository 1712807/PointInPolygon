#include "Poly.h"

void main()
{
	vector<Point> s;
	Polygon poly(s, s.size());
	
	readFromFile("METERAIN.INP", poly, s);
	
	ofstream out("METERAIN.OUT");
	for (int i = 0; i < s.size(); i++)
	{
		if (compare(s[i], poly)) out << "YES" << endl;
		else out << "NO" << endl;
	}
	out.close();
}