#include <iostream>

using namespace std;

int main() {
    //Ввод матрицы
    const int SIZE = 100;
    int mat[SIZE][SIZE];
    int b[SIZE];
    int n;
    cout << "Enter the matrix size:" << endl;
    cin >> n;
    cout << "Enter the matrix:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    //Вывод исходной матрицы
    cout << "Entered matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << "\t";
        cout << endl;
    }
    //Обработка матрицы и формирование одномерного массива b
    cout << "Enter the 'x' value:" << endl;
    int x;
    cin >> x;
    for (int i = 0; i < n; i++) {
        int p = 1;
        for (int j = 0; j < n; j++) {
            if ((j+1) % 2 == 1)
                p *= mat[j][i];
        }
        if (p > x)
            b[i] = 1;
        else
            b[i] = 0;
    };
    //Вывод результата
    cout << "The resulting array:" << endl;
    for (int i = 0; i < n; i++)
        cout << b[i] << "\t";
    return 0;
}

#if 0

Входные данные:
5
10 1 20 1 0
1 1 70 1 1
1 10 1 2 1
1 1 1 1 1
10 90 44 1 999
500
Вывод:
0 1 1 0 0

#endif