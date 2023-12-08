#include <iostream>
#include <string>

using namespace std;

struct sstring {
	string str;
	bool print;
};

void Task6() {
	const int N = 5;
	sstring arr[N];
	for (int i = 0; i < N; i++) {
		getline(cin, arr[i].str);
		arr[i].print = 0;
	}
	for (int i = 0; i < N / 2; i++) {
		bool Char = 0;
		bool NoDigit = 0;
		for (int j = 0; j < arr[i].str.size() / 2; j++) {
			if ((arr[i].str[j] == '+') || (arr[i].str[j] == '-') || (arr[i].str[j] == '*'))
				Char = 1;
		}
		for (int j = arr[i].str.size() / 2; j < arr[i].str.size(); j++) {
			if ((static_cast<int>(arr[i].str[j]) <= 48) && (static_cast<int>(arr[i].str[j]) >= 57))
				NoDigit = 1;
		}
		if (NoDigit && Char == 1)
			arr[i].print = 1;
	}
	for (int i = 0; i < N; i++) {
		if (arr[i].print == 1)
			cout << arr[i].str;
	}
}

int main() {
	
	Task6();
}

Дано несколько строк без пробелов. Напечатать строки, в которые входят знаки «+», «–», «*» в первую половину, а вторая половина строки не содержит цифр.
