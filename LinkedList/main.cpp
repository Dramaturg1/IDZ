#if 0
Описать процедуру, которая
а) вставляет в непустой список L, элементы которого упорядочены по не убыванию новый
элемент Е так, чтобы сохранилась упорядоченность.
б) удаляет из списка L первый отрицательный элемент.

Тест1:

Ввод:
1       2       3       4       5       6       7       8       9       0
5
Вывод:
1       2       3       4       5       5       6       7       8       9

Тест2:

Ввод:
1       2       3       4       -1      5       6       -1      7       -1      0
Вывод:
1       2       3       4       5       6       -1      7       -1

#endif

#include <iostream>

using namespace std;

struct list {
    int data;
    list* next;
};

list* make_list() {
    list* head = new(list);
    int x;
    cin >> x;
    head->data = x;
    head->next = nullptr;
    list* curr = head;
    while (x) {
        cin >> x;
        if (x) {
            list* node = new(list);
            node->data = x;
            node->next = nullptr;
            curr->next = node;
            curr = node;
        }
    }
    return head;
}

void print(list* head) {
    list* curr = head;
    while(curr) {
        cout << curr->data << "\t";
        curr = curr->next;
    }
    cout << endl;
}

bool empty(list* head) {
    if (head == nullptr)
        return true;
    else
        return false;
}



void Task1(list* head, int x) {
    if (empty(head)) {
        cout << "List is empty!";
        return;
    };
    list* curr = head;
    bool f = false;
    while(curr->next && !f) {
        if (x >= curr->data && x <= curr->next->data) {
            list* node = new(list);
            node->data = x;
            node->next = curr->next;
            curr->next = node;
            f = true;
            curr = curr->next->next;
        }
        else
            curr = curr->next;
    }
    if (!f) {
        list* node = new(list);
        node->data = x;
        node->next = nullptr;
        curr->next = node;
    };
}

void Task2(list* head) {
    if (head->data < 0) {
        list* curr = head;
        head = head->next;
        delete curr;
        return;
    }
    list* curr = head;
    while(curr->next->next) {
        if (curr->next->data < 0) {
            list* to_delete = curr->next;
            curr->next = curr->next->next;
            delete to_delete;
            return;
        }
        curr = curr->next;
    };
    if (curr->next->data < 0) {
        delete curr->next;
        curr->next = nullptr;
    }
}

void clear_list(list* head) {
    list* curr = head;
    while(head) {
        head = head->next;
        delete curr;
        curr = head;
    }
}

void Test1() {
    list* head = make_list();
    print(head);
    int x;
    cin >> x;
    Task1(head, x);
    print(head);
    clear_list(head);
}

void Test2() {
    list* head2 = make_list();
    print(head2);
    Task2(head2);
    print(head2);
    clear_list(head2);
}

int main() {
    Test1();
    Test2();
}