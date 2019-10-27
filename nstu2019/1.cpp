// Задача 1.
// Считываем рёбра графа и запоминаем повторения.
// Суммируем длину всех уникальных рёбер.

//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

typedef __int64 bint;
struct POINT
{
	int x, y;
};
vector <POINT> coords;
set <pair<int, int>> edges;
map <pair<int, int>, bool> repeats;


double my_len(POINT a, POINT b) {
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void my_insert(pair<int, int> p) {
	if (edges.find(p) != edges.end())
		repeats[p] = true;
	else
	{
		repeats[p] = false;
		edges.insert(p);
	}
}

int main()
{
	//freopen("1.txt", "r", stdin);
	bint n, m;
	cin >> n >> m;
	coords.resize(n);
	int x, y;
	for (size_t i = 0; i < n; i++)
		cin >> coords[i].x >> coords[i].y;

	int a, b, c;
	for (size_t i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		a--;
		b--;
		c--;
		pair <int, int> p1, p2, p3;
		p1 = make_pair(min(a, b), max(a, b));
		p2 = make_pair(min(a, c), max(a, c));
		p3 = make_pair(min(b, c), max(b, c));
		my_insert(p1);
		my_insert(p2);
		my_insert(p3);
	}

	double length = 0;
	for (auto i : edges) {
		//cout << i.first << " " << i.second << endl;
		if (repeats[i] == false)
			length += my_len(coords[i.first], coords[i.second]);
	}



	cout << fixed;
	cout << setprecision(3) << length;
	return 0;
}