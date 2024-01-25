#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
template<typename T>
struct Node {
    T value;
    Node* left;
    Node* right;
    int altura;
    Node(T dato) : value(dato), altura(0), left(nullptr), right(nullptr) {}
};
template<typename T>
class AVL {
private:
    Node<T>* raiz;
    void inOrderT(Node<T>* temp, vector<T>& result) {
        if (temp != nullptr) {
            inOrderT(temp->left, result);
            result.push_back(temp->value);
            inOrderT(temp->right, result);
        }
    }
    void PostOrderT(Node<T>* temp, vector<T>&result){
        if(temp != nullptr){
            PostOrderT(temp->left, result);
            PostOrderT(temp->right, result);
            result.push_back(temp->value);
        }
    }
    void PreOrdenT(Node<T>* temp,vector<T>&result){
        if(temp != nullptr){
            result.push_back(temp->value);
            PreOrdenT(temp->left,result);
            PreOrdenT(temp->right,result);
        }
    }

    Node<T>* padre(Node<T>* temp, int dato){
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
    int altura(Node<T>* temp) {
        if (temp == nullptr) {
            return 0;
        } else {
            return 1 + max(altura(temp->left), altura(temp->right));
        }
    }

    Node<T>* rotate_right(Node<T>*& th) {
        Node<T>* temp = th->left;
        th->left = temp->right;
        temp->right = th;
        th = temp;
        return th;
    }

    Node<T>* rotate_left(Node<T>*& th) {
        Node<T>* temp = th;
        temp = th->right;
        Node<T>* temp2 = th;
        th->right = temp2->left;
        temp2->left = th;
        th = temp;
        return th;
    }

    void rotate(Node<T>*& th) {
        if (balance_factor(th) > 1) {
            if (balance_factor(th->left) < 0) {
                th->left = rotate_left(th->left);
            }
            th = rotate_right(th);
        } else if (balance_factor(th) < -1) {
            if (balance_factor(th->right) > 0) {
                th->right = rotate_right(th->right);
            }
            th = rotate_left(th);
        }
        th->altura = 1 + max(altura(th->left), altura(th->right));
    }

    int balance_factor(Node<T>* temp) {
        return altura(temp->left) - altura(temp->right);
    }
    Node<T>* inserta(Node<T>*& th, int dato) {
        if (th == nullptr) {
            return new Node(dato);
        } else if (dato < th->value) {
            th->left = inserta(th->left, dato);
        } else if (dato > th->value) {
            th->right = inserta(th->right, dato);
        } else {
            return th;
        }
        th->altura = 1 + max(altura(th->left), altura(th->right));
        rotate(th);
        return th;
    }
    Node<T>* search_Node(Node<T>* th, int dato) {
        if (th == nullptr) {
            return nullptr;
        } else if (th->value == dato) {
            return th;
        } else if (dato < th->value) {
            return search_Node(th->left, dato);
        } else {
            return search_Node(th->right, dato);
        }
    }
    Node<T>* minValueNode(Node<T>* node) {
        Node<T>* th = node;
        while (th != nullptr && th->left != nullptr) {
            th = th->left;
        }
        return th;
    }

    Node<T>* removeNode(Node<T>* th, int dato) {
        if (th == nullptr) {
            return nullptr;
        }
        if (th->value > dato) {
            th->left = removeNode(th->left, dato);
        } else if (th->value < dato) {
            th->right = removeNode(th->right, dato);
        } else {
            if (th->left == nullptr || th->right == nullptr) {
                Node<T>* temp = th->left ? th->left : th->right; // si temp no es nulo el puntero se asigna T->left, caso contrario T->right;

                // Hoja
                if (temp == nullptr) {
                    delete th;
                    return nullptr;
                } else {
                    if(th == raiz){
                        raiz = temp;
                    }
                    th->left = temp->left;
                    th->right = temp->right;
                    th->value = temp->value;
                    th->altura = temp->altura;
                }
                delete temp;
            } else {
                //ambos hijos
                Node<T>* temp = minValueNode(th->right); //trae el minimo valor del subarbol derecho del arbol
                th->value = temp->value;
                th->right = removeNode(th->right, temp->value);
            }
        }
        if(th == nullptr){ // este es para en caso de que el nodo luego de las operaciones quedara nulo retorne ese valor
            return nullptr;
        }
        th->altura = 1 + max(altura(th->left), altura(th->right));
        int factor = balance_factor(th);
        rotate(th);
        return th; // Devuelve el puntero al nodo modificado
    }


public:
    AVL() : raiz(nullptr) {}
    bool remove(int dato){
        if(removeNode(raiz,dato) != nullptr){
            return true;
        }else{
            return false;
        }
    }
    Node<T>* padree(int valor){
        return padre(raiz,valor);
    }

    void insert(int dato) {
        raiz = inserta(raiz, dato);
    }

    bool search(int dato) {
        return search_Node(raiz, dato) != nullptr;
    }
    vector<T> inOrder() {
        vector<T> result;
        inOrderT(raiz, result);
        return result;
    }
    vector<T>PostOrder(){
        vector<T>result;
        PostOrderT(raiz,result);
        return result;
    }
    vector<T>PreOrden(){
        vector<T>result;
        PreOrdenT(raiz,result);
        return result;
    }
    void BFS() {
        queue<Node<T>*> temp;
        if (raiz == nullptr) {
            return;
        }
        temp.push(raiz);
        while (!temp.empty()) {
            Node<T>* node = temp.front();
            temp.pop();
            cout << node->value << " ";
            if (node->left != nullptr) {
                temp.push(node->left);
            }
            if (node->right != nullptr) {
                temp.push(node->right);
            }
        }
    }

    ~AVL() {
    }
};

int main() {
    AVL<int> arbol;

    arbol.insert(4);
    arbol.insert(2);
    arbol.insert(6);
    arbol.insert(1);
    arbol.insert(3);
    arbol.insert(5);
    arbol.insert(7);
    Node<int>* padre = arbol.padree(7);
    if (padre != nullptr)
        cout << "El padre de 7 es: " << padre->value << endl;
    else
        cout << "No tiene padre" << endl;

    int valor = 3;
    cout << boolalpha << arbol.search(valor) << endl ;
    cout << arbol.remove(valor) << endl;
    cout << boolalpha << arbol.search(valor) << endl;
    //cout << "¿El valor " << valor << " esta en el arbol? " << (arbol.search(valor) ? "Sí" : "No") << endl;
    vector<int> inOrderResult = arbol.inOrder();
    vector<int>prueba = arbol.PostOrder();
    vector<int>prueba1 = arbol.PreOrden();

    cout << "Inorden: ";
    for (int elem : inOrderResult) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Postorden: ";
    for (int elem : prueba) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Preorden: ";
    for (int elem : prueba1) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "BFS:";
    arbol.BFS();
    return 0;
}
