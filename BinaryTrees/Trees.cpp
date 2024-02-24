#include "BinarySearchTree.cpp"
#include <iostream>

using namespace std;
using namespace Trees;

int main() {
    BinarySearchTree<int> tree;
    tree.insert(6);
    tree.insert(3);
    tree.insert(10);
    tree.insert(22);
    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.levelOrderTraversal();
    tree.printPaths();
    int x = tree.heightOfTree();
    cout << endl << x << endl;

}
