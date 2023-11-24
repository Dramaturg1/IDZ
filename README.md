#include<iostream>
#include <string>

using namespace std;

struct Student {
	string fio;
	int marks[5];
};

void grade(int* arr, int* ex, int* good, int* udovl, int* neud) {
	int sum = 0;
	for (int i = 0; i < 5; i++)
		sum += arr[i];
	if (sum == 25)
		*ex = *ex + 1;
	else if (sum >= 20 && sum <= 24)
		*good = *good + 1;
	else if (sum >= 15 && sum <= 19)
		*udovl = *udovl + 1;
	else
		*neud = *neud + 1;
	return;
}

int main() {

	Student student[5];
	for (int i = 0; i < 5; i++) {
		cin >> student[i].fio;
		for (int j = 0; j < 5; j++) {
			cin >> student[i].marks[j];
		};
	};

	int ex = 0, good = 0, udovl = 0, neud = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			grade(student[i].marks, &ex, &good, &udovl, &neud);
		}
	}

	cout << ex << endl << good << endl << udovl << endl << neud << endl;
}

Описать структуру с именем STUDENT, содержащую следующие поля: Ф.И.О. 
номер группы, оценки (алгебра, мат. анализ, дискретная математика, информатика, 
физкультура). Найти количество отличников, хорошистов, троечников и двоечников.

