#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
struct NodeBT
{
    T data;
    NodeBT *left;
    NodeBT *right;
    NodeBT() : left(nullptr), right(nullptr) {}
    NodeBT(T value) : data(value), left(nullptr), right(nullptr) {}
    void Killself()
    {
        if (left)
        {
            left->Killself();
        }
        if (right)
        {
            right->Killself();
        }
        delete this;
    }
};

template <typename T>
class BSTree
{
private:
    NodeBT *root;

public:
    BSTree() : root(nullptr){};
    void insert(NodeBT *node, T value)
    {
        if (node == nullptr)
            node = new NodeBT<T>(value);
        else if (value < node->data)
            insert(node->left, value);
        else
            insert(node->right, value);
    };
    bool find(NodeBT *node, T value)
    {
        if (node == nullptr)
        {
            return false;
        }
        else if (value < node->data)
        {
            return find(node->left, value);
        }
        else if (value > node->data)
        {
            return find(node->right, value);
        }
        else
            return true;
    };
    string displayInOrder(NodeBT<T> *node, string &result)
    {
        if (node == nullptr)
        {
            return result
        }
        displayInOrder(node->left, result);
        result += node->data + " ";
        displayInOrder(node->right, result);
        return result;
    };
    string displayPreOrder(NodeBT<T> *node, string &result)
    {
        if (node == nullptr)
        {
            return result
        }
        result += node->data + " ";
        displayInOrder(node->left, result);
        displayInOrder(node->right, result);
        return result;
    };
    string displayPostOrder(NodeBT<T> *node, string &result)
    {
        if (node == nullptr)
        {
            return result
        }
        displayInOrder(node->left, result);
        displayInOrder(node->right, result);
        result += node->data + " ";
        return result;
    };
    string displayBFS(){};
    string displayDFS(){};
    T minValue(NodeBT<T> *node)
    {
        if (node == nullptr)
        {
            throw("The tree is empty");
        }
        else if (node->left == nullptr)
        {
            return node->data;
        }
        else
        {
            minValue(node->left);
        }
    };
    T maxValue(NodeBT<T> *node)
    {
        if (node == nullptr)
        {
            throw("The tree is empty");
        }
        else if (node->right == nullptr)
        {
            return node->data;
        }
        else
        {
            maxValue(node->right);
        }
    };
    void remove(NodeBT<T> *&node, T value) {}
    {
        if (node == nullptr)
        {
            return;
        }
        else if (value < node->data)
        {
            remove(node->left, value);
        }
        else if (value > node->data)
        {
            remove(node->right, value);
        }
        else
        {
            // Leaf
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                node = nullptr
            }
            // One child
            else if (node->left == nullptr)
            {
                NodeBT<T> temp = node;
                node = node->right;
                delete temp;
            }

            else if (node->right == nullptr)
            {
                NodeBT<T> temp = node;
                node = node->left;
                delete temp;
            }
            // Two child
            else
            {
                T temp = maxValue(node->left);
                node->data = temp;
                remove(node->left, temp);
            }
        }
    }
    int Tree_size()
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            return 1 + size(root->left) + size(root->right);
        }
    }

    int height(NodeBT<T> *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return size(node->left) + size(node->right) + 1;
        }
    }
    T predecessor(T value)
    {
        T temp = MaxValue(root->left);
    }
    T successor(T value){};
    void clear(){};
    ~BSTree() {}
};
