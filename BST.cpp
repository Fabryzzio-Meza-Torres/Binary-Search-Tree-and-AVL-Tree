#include <iostream>
#include <queue>
#include <stack>
#include "BST.h"
using namespace std;

int main()
{
    BSTree<int> bst;

    // Insert elements into the BST
    bst.insert(bst.getRoot(), 8);
    bst.insert(bst.getRoot(), 3);
    bst.insert(bst.getRoot(), 1);
    bst.insert(bst.getRoot(), 6);
    bst.insert(bst.getRoot(), 4);
    bst.insert(bst.getRoot(), 7);
    bst.insert(bst.getRoot(), 10);
    bst.insert(bst.getRoot(), 14);
    bst.insert(bst.getRoot(), 13);

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
    cout << "Removing " << valueToRemove << " from the BST." << endl;
    bst.remove(bst.getRoot(), valueToRemove);

    // Display the BST after removal
    cout << "InOrder Traversal after removal: " << bst.displayInOrder(bst.getRoot(), inOrderResult) << endl;

    // Display the size and height of the BST
    cout << "Size of the BST: " << bst.Tree_size(bst.getRoot()) << endl;
    cout << "Height of the BST: " << bst.height(bst.getRoot()) << endl;

    // Clear the BST
    bst.clear();

    // Display the BST after clearing
    cout << "InOrder Traversal after clearing: " << bst.displayInOrder(bst.getRoot(), inOrderResult) << endl;

    return 0;
}