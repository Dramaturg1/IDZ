#if 0
Дано дерево двоичного поиска. Описать функцию, которая подсчитывает число вершин на N - ом
уровне непустого дерева. (Корень - вершина 0 - го уровня).

Тест 1:

Tree elements in pre-order traversal:
10 5 15
Enter level to count nodes at: 1
 Number of nodes at level 1: 2

 Тест 2:

 Tree elements in pre-order traversal:
50 10 -324 5 12 34 23 23 100 63 98
Enter level to count nodes at: 4
 Number of nodes at level 4: 1

#endif

#include <iostream>

using namespace std;

struct tree {
    int data;
    int level;
    tree* R;
    tree* L;
};

void add(tree *root, int x, int lvl) {
    if (root->data > x) {
        if (root->L == nullptr) {
            tree* Node = new(tree);
            Node->L = nullptr;
            Node->R = nullptr;
            Node->data = x;
            Node->level = lvl;
            root->L = Node;
        }
        else
            add(root->L, x, lvl+1);
    }
    else
        if (root->R == nullptr) {
            tree* Node = new(tree);
            Node->R = nullptr;
            Node->L = nullptr;
            Node->data = x;
            Node->level = lvl;
            root->R = Node;
        }
        else
            add(root->R, x, lvl+1);
}

void print(tree *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        print(root->L);
        print(root->R);
    }
}

int count(tree *root, int targetLevel) {
    if (root == nullptr) return 0;
    if (root->level == targetLevel) return 1;
    return count(root->L, targetLevel) + count(root->R, targetLevel);
}

int main() {
    int x;
    tree* root = nullptr;

    cout << "Input elements of the tree (enter 0 to stop):" << endl;
    cin >> x;

    if (x != 0) {
        root = new tree;
        root->data = x;
        root->L = nullptr;
        root->R = nullptr;
        root->level = 0;
    }

    while (true) {
        cin >> x;
        if (x == 0) break;
        add(root, x,1);
    }

    cout << "Tree elements in pre-order traversal:" << endl;
    print(root);
    cout << endl;

    int N;
    cout << "Enter level to count nodes at: ";
    cin >> N;
    int c = count(root, N);
    cout << "Number of nodes at level " << N << ": " << c << endl;
}
