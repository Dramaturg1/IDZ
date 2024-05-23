#if 0
Дан массив целых чисел. Найти наименьший элемент, индекс которого является числом
Фибоначчи.

Тест

10 10 10 10 10 10 10 10 10 10 10 1 1 1 1 1 1 1 1 1 1 1 1 0
Minimum value is v[13]=1


#endif

#include <iostream>
#include <vector>

using namespace std;

void fibb(vector<int> &vec) {
    int a = 0, b = 1, c = 1;
    int min = vec[1];
    int ind = 1;
    for (; c < vec.size(); c = a + b) {
        a = b;
        b = c;
        if (vec[c] < min) {
            min = vec[c];
            ind = c;
        }
    }
    cout << "Minimum value is v[" << ind << "]=" << min;
    return;
};

int main() {
    vector<int> v;
    int x;
    while(x) {
        cin >> x;
        if(x)
            v.push_back(x);
    }
    fibb(v);
}

