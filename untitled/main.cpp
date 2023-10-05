#include <iostream>

using namespace std;

int main() {
    double a, b, c;
    int n, m;
    cout << "Enter the coefficients>> ";
    cin >> a >> b >> c;
    cout << "Enter the counters>> ";
    cin >> n >> m;
    double sum = 0, comp = 1, v1 = 1, v2 = b * b, v3 = 1, result;

    for (int k = 1; k <= n; k++) {
        v1 *= k;
        v2 *= b;
        sum += v1 + v2;
    };

    for (int j = 1; j <= m; j++) {
        v3 *= j + 1;
        comp *= v3 * c + 2;
    };

    result = a * (sum + comp);
    cout << "Result>> ";
    cout << result;
    return 0;
}

#if 0
Тест 1.

Ввод
2 2 2
5 5

Вывод
2,931,298,402

Тест 2.

Ввод
1 2 3
4 4

Вывод
4,286,233

#endif