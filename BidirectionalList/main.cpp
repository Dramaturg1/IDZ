#if 0
Дан кольцевой двунаправленный список.
а) Из списка L, содержащего не менее двух элементов, удалить все элементы, у которых
одинаковые соседи (первый и последний элемент считать соседями).
б) в списке L удвоить каждое вхождение элемента Е.

Тест1:

Ввод:
1       2       -1      2       4       5       -1      5       6       7       -1      8       9       0
Вывод:
1       2       2       4       5       5       6       7       -1      8       9

Тест2:

Ввод:
1       1       5       1       5       5       1       1       5       1       0
5
Вывод:
1       1       10      1       10      10      1       1       10      1
#endif

#include <iostream>

using namespace std;

struct list {
    int data;
    list* next;
    list* prev;
};

list* make_list() {
    list* head = new(list);
    int x;
    cin >> x;
    if (x) {
        head->data = x;
        head->next = nullptr;
        head->prev = nullptr;
    };
    list* curr = head;
    while (x) {
        cin >> x;
        if (x) {
            list* node = new(list);
            node->data = x;
            node->next = nullptr;
            node->prev = curr;
            curr->next = node;
            curr = node;
        }
    }
    curr->next = head;
    head->prev = curr;
    return head;
}

bool have2elements(list* head) {
    if (head->next || head->prev)
        return true;
    else
        return false;
}

void print(list* head) {
    list* curr = head->next;
    cout << head->data << "\t";
    while(curr != head) {
        cout << curr->data << "\t";
        curr = curr->next;
    }
    cout << endl;
}

void Task1(list* head) {
    if (!have2elements(head)) {
        cout << "Not enough elements!" << endl;
        return;
    }
    list* curr = head->next;
    while (curr != head) {
        if (curr->next->data == curr->prev->data) {
            list* Prev = curr->prev;
            list* Next = curr->next;
            Prev->next = Next;
            Next->prev = Prev;
            list* to_delete = curr;
            curr = curr->next;
            delete to_delete;
        }
        else
            curr = curr->next;
    }
}

void Task2(list* head, int x) {
    list* curr1 = head->next;
    list* curr2 = head->prev;
    if (head->data == x)
        head->data *= 2;
    while (curr1 != curr2 && curr1->prev != curr2) {
        if ( curr1->data == x)
            curr1->data *= 2;
        curr1 = curr1->next;
        if (curr2->data == x)
            curr2->data *= 2;
        curr2 = curr2->prev;
    }
    if (curr1 == curr2) {
        if (curr1->data == x)
            curr1->data *= 2;
    }
}

void clear_list(list* head) {
    list* curr = head->next;
    while (curr != head) {
        list* to_delete = curr;
        curr = curr->next;
        delete to_delete;
    }
    delete head;
}

void Test1() {
    list* head = make_list();
    print(head);
    Task1(head);
    print(head);
    clear_list(head);
}

void Test2() {
    list* head = make_list();
    print(head);
    int x;
    cin >> x;
    Task2(head, x);
    print(head);
    clear_list(head);
}

int main() {
    Test1();
    Test2();
}