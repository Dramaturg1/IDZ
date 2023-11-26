#if 0
Задание:
Составить функцию, заменяющую в исходном массиве у элементов все единицы нулями и
все нули единицами. Замена выполняется с помощью функции.

Ввод:
10101   -419    609     -2109   120     -3901   1818    -9090   1111    0
Вывод:
1010    -409    619     -2019   21      -3910   808     -9191   0       1

#endif

#include <iostream>

using namespace std;

void Change(int &x) {
    int temp = x;
    int digits = 0;
    do {
        digits++;
        temp/= 10;
    } while(temp);
    int dec = 1;
    for (int i = 1; i < digits; i++)
        dec*= 10;
    int newDigit, newNumber = 0;
    for (int i = 1; i <= digits; i++) {
        newDigit = abs(x) / dec % 10;
        if (newDigit == 1)
            newDigit = 0;
        else if (newDigit == 0)
            newDigit = 1;
        newNumber+= newDigit * dec;
        dec/= 10;
    }
    if (x < 0)
        x = -newNumber;
    else
        x = newNumber;
}

void Update(int *arr, int len) {
    for (int i = 0; i < len; i++)
        Change(arr[i]);
};

int main() {
    int N = 10;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    };
    cout << "Entered array" << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << "\t";
    cout << endl;
    Update(arr, N);
    cout << "New array:" << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << "\t";
    return 0;
}