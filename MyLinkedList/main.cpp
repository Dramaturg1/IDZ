#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) :data(value), next(nullptr) {};
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {};

    ~LinkedList() {
        while (head) {
            Node* current = head;
            head = head->next;
            delete current;
        }
    }

    void clear() {
        while (head) {
            Node* current = head;
            head = head->next;
            delete current;
        }
        head = nullptr;
    }

    Node* first() {
        return head;
    }

    Node* last() {
        Node* current = head;
        while (current->next)
            current = current->next;
        return current;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        Node* current = head;
        int counter = 0;
        while (current) {
            current = current->next;
            counter++;
        }
        return counter;
    }

    void print() {
        if (empty())
            cout << "The List is empty" << endl;
        else {
            Node* current = head;
            while (current) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    void prepend(int value) {
        Node* newHead = new Node(value);
        newHead->next = head;
        head = newHead;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = newNode;
        }
        else {
            Node* current = head;
            while(current->next)
                current = current->next;
            current->next = newNode;
        }
    }

    void insert(int value, int index) {
        if (index >= size())
            throw out_of_range("Trying to access a node out of range");
        if (index == 0)
            prepend(value);
        else {
            Node* newNode = new Node(value);
            Node* current = head;
            int counter = 0;
            for (int i = 0; i < index-1; i++)
                current = current->next;
            Node* toLink = current->next;
            current->next = newNode;
            newNode->next = toLink;
        }
    }

    void erase(int index) {
        if (index >= size())
            throw out_of_range("Trying to access a node out of range");
        if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        else {
            int counter = 0;
            Node* current = head;
            for (int i = 0; i < index-1; i++)
                current = current->next;
            Node* toDelete = current->next;
            Node* toLink = toDelete->next;
            current->next = toLink;
            delete toDelete;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size())
            throw out_of_range("Trying to access a node out of range");
        Node* current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        return current->data;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size())
            throw out_of_range("Trying to access a value out of range");
        Node* current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        return current->data;
    }

};

void Test(LinkedList& list, int* arr, int size) {
    for (int i = 0; i < size; i++)
        list.append(arr[i]);
    list.print();
    list.append(10);
    list.prepend(10);
    list.print();
    list.insert(10, 5);
    list.erase(2);
    list.print();
    cout << list.size() << endl;
    list.clear();
    list.print();
}

int main() {
    const int SIZE = 10;
    int arr[SIZE]{1, 2, 3, 4, 5, 6 ,7 ,8 ,9, 10};
    LinkedList list;
    Test(list, arr, SIZE);
    return 0;
}