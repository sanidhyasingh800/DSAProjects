#include "BinarySearchTree.cpp"
#include <iostream>

using namespace std;
using namespace Trees;

int main() {
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(0);
    tree.insert(8);
    tree.insert(2);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);
    tree.insert(2);
    tree.insert(0);
    tree.insert(4);

    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.levelOrderTraversal();
    cout << tree.sumDistances();
    int x = tree.heightOfTree();
    cout << endl << x << endl;

}
