#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int value;
    Node* left;
    Node* right;
    int altura;
    Node(int dato) : value(dato), altura(0), left(nullptr), right(nullptr) {}
};

class AVL {
private:
    Node* raiz;

    int altura(Node* temp) {
        if (temp == nullptr) {
            return 0;
        } else {
            return 1 + max(altura(temp->left), altura(temp->right));
        }
    }

    Node* rotate_right(Node*& T) {
        Node* temp = T->left;
        T->left = temp->right;
        temp->right = T;
        T = temp;
        return T;
    }

    Node* rotate_left(Node*& T) {
        Node* temp = T;
        temp = T->right;
        Node* temp2 = T;
        T->right = temp2->left;
        temp2->left = T;
        T = temp;
        return T;
    }

    void rotate(Node*& T) {
        if (balance_factor(T) > 1) {
            if (balance_factor(T->left) < 0) {
                T->left = rotate_left(T->left);
            }
            T = rotate_right(T);
        } else if (balance_factor(T) < -1) {
            if (balance_factor(T->right) > 0) {
                T->right = rotate_right(T->right);
            }
            T = rotate_left(T);
        }
        T->altura = 1 + max(altura(T->left), altura(T->right));
    }

    int balance_factor(Node* temp) {
        return altura(temp->left) - altura(temp->right);
    }
    Node* inserta(Node*& T, int dato) {
        if (T == nullptr) {
            return new Node(dato);
        } else if (dato < T->value) {
            T->left = inserta(T->left, dato);
        } else if (dato > T->value) {
            T->right = inserta(T->right, dato);
        } else {
            return T;
        }
        T->altura = 1 + max(altura(T->left), altura(T->right));
        rotate(T);
        return T;
    }
    Node* search_Node(Node* T, int dato) {
        if (T == nullptr) {
            return nullptr;
        } else if (T->value == dato) {
            return T;
        } else if (dato < T->value) {
            return search_Node(T->left, dato);
        } else {
            return search_Node(T->right, dato);
        }
    }

public:
    AVL() : raiz(nullptr) {}

    void insert(int dato) {
        raiz = inserta(raiz, dato);
    }

    bool search(int dato) {
        return search_Node(raiz, dato) != nullptr;
    }
    ~AVL() {
    }
};

int main() {
    AVL arbol;
    arbol.insert(5);
    arbol.insert(3);
    arbol.insert(7);
    arbol.insert(2);
    arbol.insert(4);
    arbol.insert(6);
    arbol.insert(8);

    int valor = 2;
    cout << boolalpha << arbol.search(valor);
    //cout << "¿El valor " << valor << " esta en el arbol? " << (arbol.search(valor) ? "Sí" : "No") << endl;

    return 0;
}
