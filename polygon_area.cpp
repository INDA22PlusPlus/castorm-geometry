#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Point
{
	double x, y;
};

double area(vector<Point> polygon) {
    double area = 0;
    int n = polygon.size();
	for (int i = 0; i < n; i++)
	{
		auto p0 = polygon[i];
		auto p1 = polygon[(i + 1) % n];
		area += (p1.x - p0.x) * (p1.y + p0.y);
	}
    area *= 0.5;
    return area;
}

int main()
{

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		vector<Point> polygon;
		for (int i = 0; i < n; i++)
		{
			Point p;
			cin >> p.x >> p.y;
			polygon.push_back(p);
		}
        double A = area(polygon);
        cout << (A >= 0 ? "CW" : "CCW") << " " << round(abs(A) * 10)/10;
        if (A == round(A)) cout << ".0";
        cout << endl;
	}

	return 0;
}