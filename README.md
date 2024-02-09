#include <iostream>
#include<string>

using namespace std;

int main() {
	string str = "";
	string inp;
	do {
		getline(cin, inp);
		cin.ignore();
		str += inp;
	} while (inp.find('.') != std::string::npos);
	int arr[10];
	for (int i = 0; i < str.size(); i++) {
		arr[str[i]]++;
	}
	string res = "";
	int min = 999;
	int ind;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[j] < min) {
				min = arr[j];
				ind = j;
				arr[j] = -1;
			}
		}
		cout << ind;
		min = 999;
	}
}
