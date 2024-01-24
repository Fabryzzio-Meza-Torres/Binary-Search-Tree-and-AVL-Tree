#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* rigth;
    int altura;
    Node(int dato):value(dato),altura(0), left(nullptr),rigth(nullptr) {}
};
class AVL{
private:
    int altura(Node* temp){
        if(temp == nullptr){
            return 0;
        }else{
            int A_left = altura(temp->left);
            int A_right = altura(temp->rigth);
            if(A_left > A_right){
                return A_left +1;
            }else{
                return A_right +1;
            }
        }
    }
    Node* raiz;
    Node* rotate_right(Node* T){
        Node* temp = T->left;
        T->left = temp->rigth;
        temp->rigth = T;
        T = temp;
    };
    Node* rotate_left(Node* T){
        Node* temp = T;
        temp = T->rigth;
        Node* temp2 = T;
        T->rigth = temp2->left;
        temp2->left = T;
        T = temp;
    }
    int factor_Equilibrio(Node* temp){
        return altura(temp->left)-altura(temp->rigth);
    }
public:
    void insert();
    void eliminar();
    void buscar();
    void imprimir();

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
