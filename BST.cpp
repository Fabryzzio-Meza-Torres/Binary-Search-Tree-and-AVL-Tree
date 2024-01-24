#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
struct  NodeBT
{
    T data;
    NodeBT* left;
    NodeBT* right;
    NodeBT() : left(nullptr), right(nullptr) {}
    NodeBT(T value): data(value),left(nullptr), right(nullptr) {}
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
class BSTree{
    private: 
    NodeBT* root;
    public:
    BSTree(): root(nullptr){};
    void insert(NodeBT* node,T value){
    if (node == nullptr)
        node = new NodeBT<T>(value);
    else if (value < node->data)
        insert(node->left, value);
    else
        insert(node->right, value);  
    };
    bool find(NodeBT* node, T value){
        if(node==nullptr){
            return false;
        }
        else if (value<node->data){
            return find(node->left, value);
        }
        else if (value>node->data){
            return find(node->right, value);
        }
        else return true;
    };
    string displayInOrder(NodeBT<T> *node, string &result) {
        if(node==nullptr){
            return result
        }
        displayInOrder(node->left, result);
        result+= node->data + " ";
        displayInOrder(node->right, result);
        return result;
    };
    string displayPreOrder(NodeBT<T> *node, string &result){
        if(node==nullptr){
            return result
        }
        result+= node->data + " ";
        displayInOrder(node->left, result);
        displayInOrder(node->right, result);
        return result;
    };
    string displayPostOrder(NodeBT<T> *node, string &result){
        if(node==nullptr){
            return result
        }
        displayInOrder(node->left, result);
        displayInOrder(node->right, result);
        result+= node->data + " ";
        return result;
    };
    string displayBFS(){};
    string displayDFS(){};
    T minValue(){};
    T maxValue(){};
    void remove(T value){}{
        if(find){

        }
        else{
            cout<<"El nodo que quiere eliminar no esta en el BST"<<endl;
        }
    }
    int size(){};
    T predecessor(T value) {};
    T successor(T value){};
    void clear(){};
    ~BSTree(){}

};
