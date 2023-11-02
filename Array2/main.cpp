#include <iostream>

using namespace std;

int main() {
    // Ввод массива
    const int SIZE = 100;
    int arr[SIZE];
    int n;
    cout << "Enter the array size:" << endl;
    cin >> n;
    cout << "Enter an array:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    //Вывод исходного массива
    cout << "Entered array:" << endl;
    for (int i = 0; i < n; i++)
        cout << "a[" << i << "]=" << arr[i] << endl;
    //Поиск индекса последнего максимального элемента
    int max_ind = 0;
    for (int i = 1; i < n; i++) {
        if (arr[max_ind] <= arr[i])
            max_ind = i;
    };
    //Обработка случая, при котором максимумом является последний элемент
    if (max_ind == n-1) {
        cout << "The sum cannot be found";
        return 0;
    }
    //Поиск суммы
    int sum = 0;
    for (int i = max_ind + 1; i < n; i++)
        sum += arr[i];
    //Вывод результата
    cout << "The sum of elements following after the max element is " << sum;
    return 0;
}

#if 0

Входные данные:
10
11 22 999 999 33 44 55 999 66 77
Вывод:
143

#endif