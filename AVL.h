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
    int height;
    Node(T dato) : value(dato), height(0), left(nullptr), right(nullptr) {}
};
template<typename T>
class AVL {
private:
    Node<T>* root;
    void destroy_trees(Node<T>* nodo) {
        if(nodo == nullptr){
            return;
        }
        else {
            destroy_trees(nodo->left);
            destroy_trees(nodo->right);
            delete nodo;
        }
    }
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

    Node<T>* parentNode(Node<T>* temp, int dato){
        if(temp == nullptr || root->value == dato){
            return nullptr;
        }
        else if ((temp->right != nullptr && temp->right->value == dato) ||
                 (temp->left != nullptr && temp->left->value == dato)) {
            return temp;
        }
        if (dato < temp->value)
            return parentNode(temp->left, dato);
        else
            return parentNode(temp->right, dato);
    }
    int height(Node<T>* temp) {
        if (temp == nullptr) {
            return 0;
        } else {
            return 1 + max(height(temp->left), height(temp->right));
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
        th->height = 1 + max(height(th->left), height(th->right));
    }

    int balance_factor(Node<T>* temp) {
        return height(temp->left) - height(temp->right);
    }
    Node<T>* insertNode(Node<T>*& th, int dato) {
        if (th == nullptr) {
            return new Node(dato);
        } else if (dato < th->value) {
            th->left = insertNode(th->left, dato);
        } else if (dato > th->value) {
            th->right = insertNode(th->right, dato);
        } else {
            return th;
        }
        th->height = 1 + max(height(th->left), height(th->right));
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
    Node<T>* maxValueNode(Node<T>* node){
        Node<T>* th = node;
        while(th != nullptr && th->right != nullptr){
            th = th->right;
        }
        return th;
    }
    Node<T>* lowest_Common_Ancestor(Node<T>* temp, T x, T y) {
        if (temp == nullptr) {
            return nullptr;
        }
        if (temp->value > x && temp->value > y) {
            return lowest_Common_Ancestor(temp->left, x, y);
        } else if (temp->value < x && temp->value < y) {
            return lowest_Common_Ancestor(temp->right, x, y);
        } else {
            return temp;
        }
    }

    Node<T>* SuccessorNode(Node<T>* temp, T value) {
        Node<T>* node = temp;
        Node<T>* SuccessorNode = nullptr;

        while (node != nullptr) {
            if (node->value == value) {
                if (node->right != nullptr) {
                    SuccessorNode = minValueNode(node->right);
                } else {
                    Node<T>* lowest_common_Node = lowest_Common_Ancestor(temp, value, maxValueNode(temp)->value);
                    if (lowest_common_Node != nullptr) {
                        if(lowest_common_Node->value > value){
                            SuccessorNode = lowest_common_Node;
                        }else{
                            SuccessorNode = nullptr;
                        }
                    }
                }
                break;
            } else if (node->value > value) {
                SuccessorNode = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }

        return SuccessorNode;
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
                    if(th == root){
                        root = temp;
                    }
                    th->left = temp->left;
                    th->right = temp->right;
                    th->value = temp->value;
                    th->height = temp->height;
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
        th->height = 1 + max(height(th->left), height(th->right));
        int factor = balance_factor(th);
        rotate(th);
        return th; // Devuelve el puntero al nodo modificado
    }


public:
    AVL() : root(nullptr) {}
    bool remove(int dato){
        if(removeNode(root,dato) != nullptr){
            return true;
        }else{
            return false;
        }
    }
    Node<T>* parent(int valor){
        return parentNode(root,valor);
    }

    Node<T>* lowestCommon(int x, int y){
        return lowest_Common_Ancestor(root,x,y);
    }
    Node<T>* Sucessor(int value){
        return SuccessorNode(root,value);
    }

    void insert(int dato) {
        root = insertNode(root, dato);
    }

    bool search(int dato) {
        return search_Node(root, dato) != nullptr;
    }
    vector<T> inOrder() {
        vector<T> result;
        inOrderT(root, result);
        return result;
    }
    vector<T>PostOrder(){
        vector<T>result;
        PostOrderT(root,result);
        return result;
    }
    vector<T>PreOrden(){
        vector<T>result;
        PreOrdenT(root,result);
        return result;
    }
    void BFS() {
        queue<Node<T>*> temp;
        if (root == nullptr) {
            return;
        }else{
            temp.push(root);
        }
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
    Node<T>* Predecessor(T value) {
        Node<T>* node = root;
        while (node != nullptr && node->value != value) {
            if (value > node->value) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        if (node == nullptr) {
            return nullptr;
        }
        Node<T>* lowest_common_Node = lowest_Common_Ancestor(root, node->value, node->value-1);

        if (lowest_common_Node == nullptr) {
            return nullptr;}
        return maxValueNode(lowest_common_Node->left);}

    ~AVL() {
        destroy_trees(root);
    }
};
