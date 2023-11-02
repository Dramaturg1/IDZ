#include <iostream>

using namespace std;

int main() {
    // Ввод массива
    const int SIZE = 100;
    int arr[SIZE];
    int n;
    cout << "Enter the array size:" << endl;
    cin >> n;
    cout << "Enter the array:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // Вывод введенного массива
    cout << "Your array:" << endl;
    for (int i = 0; i < n; i++)
        cout << "a[" << i << "]=" << arr[i] << endl;
    cout << "Enter an interval:" << endl;
    int A, B;
    cin >> A >> B;
    // Обработка входных данных интервала
    if (A > B) {
        int temp = A;
        A = B;
        B = temp;
    };
    if (A < 0 || B < 0) {
        cout << "Interval must be a positive number!";
        return 0;
    }
    // Обработка элементов массива
    int count = 0;
    for (int i = 0; i < n; i++) {
        int copy = arr[i];
        int dig_sum = 0;
        while (copy) {
            dig_sum += copy % 10;
            copy /= 10;
        }
        if (dig_sum >= A && dig_sum <= B)
            count++;
    };
    //Вывод результата
    cout << "Number of elements which digits' sum belongs to an interval [" << A << ", " << B << "]: " << count;
    return 0;
}

#if 0

Входные данные:
10
111 222 333 444 555 666 777 888 999 1010
8 15
Вывод:
3

#endif