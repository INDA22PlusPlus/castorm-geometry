#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	double x, y;
};

bool isInside(vector<Point> polygon, Point p)
{
	bool inside = false;

	int n = polygon.size();
	for (int i = 0; i < n; i++)
	{
		auto p0 = polygon[i];
		auto p1 = polygon[(i + 1) % n];
		if (((p0.y <= p.y && p.y < p1.y) || (p1.y <= p.y && p.y < p0.y)) && (p.x < (p1.x - p0.x) * (p.y - p0.y) / (p1.y - p0.y) + p0.x))
		{
			inside = !inside;
		}
	}

	return inside;
}

bool isOn(vector<Point> polygon, Point p)
{
	int n = polygon.size();
	for (int i = 0; i < n; i++)
	{
		auto a = polygon[i];
		auto b = polygon[(i + 1) % n];
		auto AB = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
		auto AP = (p.x - a.x) * (p.x - a.x) + (p.y - a.y) * (p.y - a.y);
		auto PB = (b.x - p.x) * (b.x - p.x) + (b.y - p.y) * (b.y - p.y);
		if (AB == AP + PB)
			return true;
	}
	return false;
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

		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			Point p;
			cin >> p.x >> p.y;
			// Function call
			if (isOn(polygon, p))
				cout << "on" << endl;
			else if (isInside(polygon, p))
				cout << "in" << endl;
			else
				cout << "out" << endl;
		}
	}

	return 0;
}
