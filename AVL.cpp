#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;
    int altura;
    Node(int dato):value(dato),altura(0), left(nullptr),right(nullptr) {}
};
class AVL{
private:
    int altura(Node* temp){
        if(temp == nullptr){
            return 0;
        }else{
            return 1+max(altura(temp->left),altura(temp->right));
        }
    }
    Node* raiz;
    Node* rotate_right(Node* T){
        Node* temp = T->left;
        T->left = temp->right;
        temp->right = T;
        T = temp;
        return temp;
    }
    Node* rotate_left(Node* T){
        Node* temp = T;
        temp = T->right;
        Node* temp2 = T;
        T->right = temp2->left;
        temp2->left = T;
        T = temp;
        return T;
    }
    Node* rotate(Node* T){
        if(balance_factor(T) > 1){
            rotate_right(T);
        }else if(balance_factor(T) < -1){
            rotate_left(T);
        }
    }
    int balance_factor(Node* temp){
        return altura(temp->left)-altura(temp->right);
    }
    Node* inserta(Node* T, int dato){
        if(T ==nullptr){
            return new Node(dato);
        }
        else if(dato < T->value){
            T->left= inserta(T->left,dato);}
        else if(dato > T->value){
                T->right= inserta(T->right,dato);}
        else {
            return T;
        }
        T->altura = 1 + max(altura(T->left),altura(T->right));
        int n = balance_factor(T);
        if(n > 1){
            if(T->left->value < dato){
                return rotate_right(T);
            }else{
                T->left = rotate_left(T->left);
                return rotate_right(T);
            }
        }else if(n < -1){
            if(T->right->value > dato){
                return rotate_left(T);
            }else{
                T->right = rotate_right(T->right);
                return rotate_left(T);
            }
        }
        return T;
        }
    Node* Busca(Node* T, int dato){

    }
    Node* Elimina(Node* T, int dato){

    }
    public:
    void insert(){

    }
    void eliminar(){

    }
    void buscar(){

    }
    void imprimir(){

    }

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
