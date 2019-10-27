// Задача 6.
// Идём от n до 0 в поиске числа, сумма которого
// и его реверса состоит только из нечётных чисел.

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

typedef __int64 bint;

int reverseInt(bint n) {

	auto s = to_string(n);
	reverse(s.begin(), s.end());
	return stoi(s);
}

bool isNotEven(bint n) {

	auto x = n + reverseInt(n);
	auto s = to_string(x);
	for (auto& c : s) {

		auto a = int(c) - '0';
		if (a % 2 == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	bint n;
	cin >> n;
	bint max = -1;
	for (int i = n; i > 0; --i) {

		if (isNotEven(i)) {

			max = i;
			break;
		}
	}

	cout << max;
}