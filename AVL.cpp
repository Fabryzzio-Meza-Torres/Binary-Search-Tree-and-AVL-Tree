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
    Node* padre(Node* temp, int dato){
        if(temp == nullptr || raiz->value == dato){
            return nullptr;
        }
        else if ((temp->right != nullptr && temp->right->value == dato) ||
                 (temp->left != nullptr && temp->left->value == dato)) {
            return temp;
        }
        if (dato < temp->value)
            return padre(temp->left, dato);
        else
            return padre(temp->right, dato);
    }
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
    Node* minValueNode(Node* node) {
        Node* T = node;
        while (T != nullptr && T->left != nullptr) {
            T = T->left;
        }
        return T;
    }

    Node* removeNode(Node* T, int dato) {
        if (T == nullptr) {
            return T;
        }
        if (T->value > dato) {
            T->left = removeNode(T->left, dato);
        } else if (T->value < dato) {
            T->right = removeNode(T->right, dato);
        } else {
            if (T->left == nullptr || T->right == nullptr) {
                Node* temp = T->left ? T->left : T->right; // si temp no es nulo el puntero se asigna T->left, caso contrario T->right;

                // Hoja
                if (temp == nullptr) {
                    temp = T;
                    T = nullptr;
                } else {
                    T->left = temp->left;
                    T->right = temp->right;
                    T->value = temp->value;
                    T->altura = temp->altura;
                }
                delete temp;
            } else {
                //ambos hijos
                Node* temp = minValueNode(T->right); //trae el minimo valor del subarbol derecho del arbol
                T->value = temp->value;
                T->right = removeNode(T->right, temp->value);
            }
        }
        if(T == nullptr){ // este es para en caso de que el nodo luego de las operaciones quedara nulo retorne ese valor
            return T;
        }
        T->altura = 1 + max(altura(T->left), altura(T->right));
        int factor = balance_factor(T);
        rotate(T);
        return T; // Devuelve el puntero al nodo modificado
    }


public:
    AVL() : raiz(nullptr) {}
    bool remove(int dato){
        return removeNode(raiz,dato) != nullptr;
    }
    Node* padree(int valor){
        return padre(raiz,valor);
    }

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

    arbol.insert(4);
    arbol.insert(2);
    arbol.insert(6);
    arbol.insert(1);
    arbol.insert(3);
    arbol.insert(5);
    arbol.insert(7);
    Node* padre = arbol.padree(7);
    if (padre != nullptr)
        cout << "El padre de 7 es: " << padre->value << endl;
    else
        cout << "No tiene padre" << endl;

    int valor = 8;
    cout << boolalpha << arbol.search(valor);
    cout << boolalpha << arbol.remove(valor);
    cout << boolalpha << arbol.search(valor);
    //cout << "¿El valor " << valor << " esta en el arbol? " << (arbol.search(valor) ? "Sí" : "No") << endl;

    return 0;
}
