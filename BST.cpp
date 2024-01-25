#include <iostream>
#include <queue>
#include <stack>
#include "BST.h"
using namespace std;

int main()
{
    BSTree<int> bst;

    // Insert elements into the BST
    bst.insert(bst.getRoot(), 50);
    bst.insert(bst.getRoot(), 30);
    bst.insert(bst.getRoot(), 20);
    bst.insert(bst.getRoot(), 40);
    bst.insert(bst.getRoot(), 70);
    bst.insert(bst.getRoot(), 60);
    bst.insert(bst.getRoot(), 80);
    // Display the BST using different traversal methods
    string inOrderResult = "";
    cout << "InOrder Traversal: " << bst.displayInOrder(bst.getRoot(), inOrderResult) << endl;

    string preOrderResult = "";
    cout << "PreOrder Traversal: " << bst.displayPreOrder(bst.getRoot(), preOrderResult) << endl;

    string postOrderResult = "";
    cout << "PostOrder Traversal: " << bst.displayPostOrder(bst.getRoot(), postOrderResult) << endl;

    cout << "BFS Traversal: " << bst.displayBFS() << endl;
    cout << "DFS Traversal: " << bst.displayDFS() << endl;

    // Find elements in the BST
    int valueToFind = 40;
    cout << "Is " << valueToFind << " in the BST? " << (bst.find(bst.getRoot(), valueToFind) ? "Yes" : "No") << endl;

    // Find the minimum and maximum values in the BST
    cout << "Minimum value: " << bst.minValue(bst.getRoot()) << endl;
    cout << "Maximum value: " << bst.maxValue(bst.getRoot()) << endl;

    // Find the predecessor and successor of a value in the BST
    int valueToFindPredecessorSuccessor = 40;
    cout << "Predecessor of " << valueToFindPredecessorSuccessor << ": " << bst.predecessor(valueToFindPredecessorSuccessor) << endl;
    cout << "Successor of " << valueToFindPredecessorSuccessor << ": " << bst.successor(valueToFindPredecessorSuccessor) << endl;

    // Remove an element from the BST
    int valueToRemove = 30;
    NodeBT<int> *root = bst.getRoot();
    bst.remove(root, valueToRemove);

    // Display the BST after removal
    string inorderResult = "";
    cout << "InOrder Traversal after removal: " << bst.displayInOrder(bst.getRoot(), inorderResult) << endl;

    // Display the size and height of the BST
    cout << "Size of the BST: " << bst.Tree_size(bst.getRoot()) << endl;
    cout << "Height of the BST: " << bst.height(bst.getRoot()) << endl;

    // Clear the BST
    bst.clear();

    // Display the BST after clearing
    string InorderResult = "";
    cout << "InOrder Traversal after clearing: " << bst.displayInOrder(bst.getRoot(), InorderResult) << endl;

    return 0;
}