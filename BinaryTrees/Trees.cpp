#include "BinarySearchTree.cpp"
#include "AVLTree.cpp"
#include <iostream>

using namespace std;
using namespace Trees;

int main() {
    AVLTree<int, int> tree;
    tree.insert(1,1);
    tree.insert(2,2);
    tree.insert(3,3);
    tree.insert(4,4);
    tree.insert(5,5);
    tree.insert(6,6);
    tree.insert(7,7);
    tree.insert(8,8);
    tree.insert(9,9);
//    tree.printTree();

    tree.inOrderTraversal();
    cout << endl;
    // tree.preOrderTraversal();
     tree.levelOrderTraversal();
    // cout << tree.sumDistances();
    // int x = tree.heightOfTree();
    // cout << endl << x << endl;

}
