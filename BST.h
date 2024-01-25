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
    NodeBT *parent;
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
    NodeBT<T> *root;

public:
    BSTree() : root(nullptr){};

    NodeBT<T> *getRoot()
    {
        return root;
    }

    void insert(NodeBT<T> *node, T value)
    {
        if (node == nullptr)
            node = new NodeBT<T>(value);
        else if (value < node->data)
            insert(node->left, value);
        else
            insert(node->right, value);
    }

    bool find(NodeBT<T> *&node, T value)
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
    }
    string displayInOrder(NodeBT<T> *node, string &result)
    {
        if (node == nullptr)
        {
            return result;
        }
        displayInOrder(node->left, result);
        result += node->data + " ";
        displayInOrder(node->right, result);
        return result;
    }
    string displayPreOrder(NodeBT<T> *node, string &result)
    {
        if (node == nullptr)
        {
            return result;
        }
        result += node->data + " ";
        displayInOrder(node->left, result);
        displayInOrder(node->right, result);
        return result;
    }
    string displayPostOrder(NodeBT<T> *node, string &result)
    {
        if (node == nullptr)
        {
            return result;
        }
        displayInOrder(node->left, result);
        displayInOrder(node->right, result);
        result += node->data + " ";
        return result;
    }
    string displayBFS()
    {
        if (root == nullptr)
        {
            return "";
        }
        else
        {
            string result = "";
            queue<NodeBT<T> *> q;
            q.push(root);
            while (!q.empty())
            {
                NodeBT<T> *temp = q.front();
                q.pop();
                result += temp->data + " ";
                if (temp->left != nullptr)
                {
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
            }
            return result;
        }
    }
    string displayDFS()
    {
        if (root == nullptr)
        {
            return "";
        }
        else
        {
            string result = "";
            stack<NodeBT<T> *> s;
            s.push(root);
            while (!s.empty())
            {
                NodeBT<T> *temp = s.top();
                s.pop();
                result += temp->data + " ";
                if (temp->left != nullptr)
                {
                    s.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    s.push(temp->right);
                }
            }
            return result;
        }
    }
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
    }

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
    void remove(NodeBT<T> *&node, T value)
    {
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
                    node = nullptr;
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
    }
    int Tree_size(NodeBT<T> *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            return 1 + Tree_size(root->left) + Tree_size(root->right);
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
            return Tree_size(node->left) + Tree_size(node->right) + 1;
        }
    }
    T predecessor(T value)
    {
        NodeBT<T> *temp = root;
        NodeBT<T> *predecessor = nullptr;
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            while (temp != nullptr && temp->data != value)
            {
                if (value < temp->data)
                {
                    temp = temp->left;
                    predecessor = temp;
                }
                else
                {
                    temp = temp->right;
                    predecessor = temp;
                }
            }
        }
        if (temp == nullptr)
        {
            return 0; // No se encontro el valor en el arbol
        }
        if (temp->left != nullptr)
        {
            return maxValue(temp->left);
        }
        else
        {
            return (predecessor != nullptr) ? predecessor->data : 0;
        }
    }

    T successor(T value)
    {
        NodeBT<T> *temp = root;
        NodeBT<T> *successor = nullptr;
        if (root == nullptr)
        {
            return 0;
        }
        else
        {

            while (temp != nullptr && temp->data != value)
            {
                if (value < temp->data)
                {
                    temp = temp->left;
                    successor = temp;
                }
                else
                {
                    temp->right;
                    successor = temp;
                }
            }
        }
        if (temp == nullptr)
        {
            return 0;
        }
        if (temp->right != nullptr)
        {
            return minValue(temp->right);
        }
        else
        {
            return (successor != nullptr) ? successor->data : 0;
        }
    }
    void clear()
    {
        if (root != nullptr)
        {
            root->Killself();
            root = nullptr;
        }
    }
    ~BSTree()
    {
        clear();
    }
};
