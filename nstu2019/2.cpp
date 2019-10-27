// Задача 2.
// Перебираем число "сраусов" от 1 до n.
// Считаем число "кокодилов". Выводим результат.

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef __int64 bint;

int main()
{
	bint n, k;
	cin >> n >> k;
	bint straus = 0;
	bint krok = 0;
	for (int i = 1; i < n; ++i) {

		straus = i * 4;
		krok = (n - i) * 2;
		if (straus + krok == k) {
			cout << i << " " << n - i;
			break;
		}
	}
	return 0;
}