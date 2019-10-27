// Задача 5.
// Считываем диагональ, min и max ширину и число телефонов.
// Для каждого телефона считываем пропорцию его экрана
// считаем ширину экрана и проверяем на принадлежнось отрезку [W1, W2]

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef __int64 bint;

int main()
{
	float D, W1, W2, N;
	float A, B;
	cin >> D >> W1 >> W2 >> N;
	/*D = 6;
	W1 = 2.9;
	W2 = 3;
	N = 1;*/
	bint count = 0;
	for (size_t i = 0; i < N; i++)
	{
		cin >> A >> B;
		float size = sqrt(A * A + B * B);
		float width = D / size * B;
		//cout << width << endl;
		if (W1 <= width && width <= W2)
			count++;
	}
	
	cout << count;
	return 0;
}