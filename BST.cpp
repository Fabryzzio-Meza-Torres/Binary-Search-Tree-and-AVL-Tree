#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
struct  Node
{
    T data;
    Node* left;
    Node* right;
    Node() : left(nullptr), right(nullptr) {}
    Node(T value): data(value),left(nullptr), right(nullptr) {}
    void Killself(){
        if(left){
            left->Killself();
        }
        if (right){
            right->Killself();
        }
        delete this;
    }
};

template<typename T>
class BST{
    private: 
    Node* root;
    public:
    BST(): root(nullptr){};
    void insert(T value){};
    bool find(T value){};
    string displayInOrder() {};
    string displayPreOrder(){};
    string displayPostOrder(){};
    string displayBFS(){};
    string displayDFS(){};
    T minValue(){};
    T maxValue(){};
    void remove(T value){};
    int size(){};
    T predecessor(T value) {};
    T successor(T value){};
    void clear(){};
    ~BST(){}

};
