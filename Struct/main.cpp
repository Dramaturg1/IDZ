#if 0

Задание:
Описать структуру с именем PRICE, содержащую следующие поля: название товара; тип
товар; стоимость товара в руб. Вывести информацию о товарах заданного типа, цена которых
больше средней цены всех товаров, а в названии есть буква "a".

Ввод:
Apple
food
30
Orange
food
45
Glue
material
80
Pencil
office stuff
95.89
Headphones
electronics
100
Diamond ring
jewellery
200

Вывод:
Product's name: headphones
Product's type: electronics
Product's price 100 rubles

Product's name: Diamond ring
Product's type: jewellery
Product's price: 200 rubles


Average price: 91.815

#endif

#include <iostream>
#include <string>

using namespace std;

struct PRICE {
    string name;
    string type;
    double price;
};

bool Substr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'A')
            return true;
    }
    return false;
}

void print(PRICE x) {
    cout << "Product's name: " << x.name << endl;
    cout << "Product's type: " << x.type << endl;
    cout << "Product's price: " << x.price << " rubles" << endl;
    cout << endl;
}

int main() {
    int N = 6;
    PRICE goods[N];
    cout << "Enter the list of goods:" << endl;
    for (int i = 0; i < N; i++) {
        getline(cin, goods[i].name);
        getline(cin, goods[i].type);
        cin >> goods[i].price;
        cin.ignore();
    }
    cout << endl;
    double avPrice = 0;
    for (int i = 0; i < N; i++)
        avPrice += goods[i].price;
    avPrice/= N;
    for (int i = 0; i < N; i++) {
        if ((goods[i].price > avPrice) && (Substr(goods[i].name)))
            print(goods[i]);
    }
    cout << endl << "Average price: " << avPrice;
    return 0;
}