#include <iostream>
#include <queue>
#include <vector>
#include <string>

// Linked implemebtation of a Binary Search Tree 
// search and insert work in log n time on average but degrade to O(n) in worst case (non balancing)
// 

using namespace std;

namespace Trees {
    // Data must be comparable!!!
    template<typename Data>
    class BinarySearchTree {
    private:
        struct Node {
            Node* left = NULL;
            Node* right = NULL;
            Data data;
        };
        Node* root;
        vector<Node*> levelOrderTraversalV;


        void insert(Data& d, Node*& root) {
            if (root == NULL) {
                root = new Node();
                root->data = d;
                return;
            }
            else if (d >= root->data) {
                insert(d, root->right);
            }
            else if (d < root->data) {
                insert(d, root->left);
            }
        }

        void inOrderTraversal(Node* root) {
            if (root->left != NULL) {
            inOrderTraversal(root->left);
            }
            cout << root->data << " ";
            if (root->right != NULL) {
            inOrderTraversal(root->right);
            }
        }

        void preOrderTraversal(Node* root) {
            cout << root->data << " ";
            if (root->left != NULL) {
            preOrderTraversal(root->left);
            }
            if (root->right != NULL) {
            preOrderTraversal(root->right);
            }
        }

        void postOrderTraversal(Node* root) {
            if (root->left != NULL) {
                postOrderTraversal(root->left);
            }
            if (root->right != NULL) {
                postOrderTraversal(root->right);
            }
            cout << root->data << " ";
        }

        void levelOrderTraversal(Node* root) {
            if (root == NULL) {
                return;
            }
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                cout << q.front()->data << " ";
                if (q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }

        
        void levelOrderTraversalVector(Node* root) {
            if (root == NULL) {
                return;
            }
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                levelOrderTraversalV.push_back(q.front());
                if (q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }

        bool search (Data data, Node* node) {
            if (data > node->data) {
                if (node->right == NULL) {
                    return false;
                }
                return search (data, node->right);
            }
            if (data < node->data) {
                if (node->left == NULL) {
                    return false;
                }
                return search (data, node->left);
            }
            return true;
        }

        int heightOfTree(Node* subroot) {
            if (subroot == NULL) {
                return -1;
            }
            if(subroot->right == NULL && subroot->left == NULL) {
                return 0;
            }
            int rightTreeHeight = 0;
            int leftTreeHeight = 0;
            if (subroot->right != NULL){
                rightTreeHeight = heightOfTree(subroot->right);
            }
            if (subroot->left != NULL) {
                leftTreeHeight = heightOfTree(subroot->left);
            }
            if (rightTreeHeight > leftTreeHeight) {
                return 1+ rightTreeHeight;
            }
            return 1 + leftTreeHeight;
        }

        void printPaths(vector<Node*>& path, Node* subRoot) const  {
            path.push_back(subRoot);
            if(subRoot->left != NULL) {
                printPaths(path, subRoot->left);
            }
            if (subRoot->right != NULL) {
                printPaths(path, subRoot->right);
            }
            if (subRoot->right == NULL && subRoot->left == NULL) {
                cout  << "Path: ";
                for (Node* x : path) {
                    cout << x->data << " ";
                }
                cout << endl;
            }
            path.pop_back();
        }

        int sumDistances(int pathlength, Node* subRoot) const {
            int currentPath = pathlength;
            if (subRoot->left == NULL && subRoot->right == NULL) {
                return pathlength;
            }
            if (subRoot->left != NULL && subRoot->right == NULL) {
                return currentPath + sumDistances(++pathlength, subRoot->left);
            }
            if (subRoot->right != NULL && subRoot->left == NULL) {
                return currentPath + sumDistances(++pathlength, subRoot->right);
            } if (subRoot->left != NULL && subRoot->right != NULL) {
                 return currentPath + sumDistances(++pathlength, subRoot->left) + sumDistances(pathlength, subRoot->right);
            }
            return 0;
        }

        void deleteNode(Data data, Node* subRoot, Node* parent, bool isLeftChild) {
            if (data > subRoot->data) {
                if (subRoot->right == NULL) {
                    return;
                }
                deleteNode(data, subRoot->right, subRoot, false);
                return;
            }
            if (data < subRoot->data) {
                if (subRoot->left == NULL) {
                    return;
                }
                deleteNode(data, subRoot->left, subRoot, true);
                return;
            }
            if (subRoot->left == NULL && subRoot->right == NULL) {
                deleteNoChildren(subRoot, parent, isLeftChild);
                return;
            }
            if (subRoot->left == NULL || subRoot->right == NULL) {
                deleteOneChild(subRoot, parent, isLeftChild);
                return;
            }
            deleteTwoChildren(subRoot, parent, isLeftChild);
            
        }

        void deleteNoChildren(Node* subRoot, Node* parent, bool isLeftChild) {
            delete subRoot;
            subRoot = NULL;
            if(parent) {
                if(isLeftChild) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
            } else {
                root = NULL;
            }
        }

        void deleteOneChild(Node* subRoot, Node* parent, bool isLeftChild) {
            Node* temp = subRoot->right;
            if(temp == NULL) {
                temp = subRoot->left;
            }
            delete subRoot;
            subRoot = NULL;
            if (parent) {
                if(isLeftChild) {
                    parent->left = temp;
                } else {
                    parent->right = temp;
                }
            } else {
                root = temp;
            }
        }

        void deleteTwoChildren(Node* subRoot, Node* parent, bool isLeftChild) {
            // find predeccesor 
            Node* predecessor = subRoot->left;
            Node* predeccesorParent = predecessor;
            while (predecessor->right != NULL) {
                predeccesorParent = predecessor;
                predecessor = predecessor->right;
            }
            if (predecessor->left == NULL) {
                if (predeccesorParent == predecessor) {
                    predecessor->right = subRoot->right;
                } else {
                    predecessor->right = subRoot->right;
                    if (predecessor != subRoot->left) {
                        predecessor->left = subRoot->left;
                    }
                    predeccesorParent->right = NULL;
                }

            } else {
                if (predeccesorParent == predecessor){
                    predeccesorParent->left = predecessor->left;
                } else {
                    predeccesorParent->right = predecessor->left;
                }
                predecessor->left = subRoot->left;
                predecessor->right = subRoot->right;

            }
            if (parent) {
                if (isLeftChild) {
                    parent->left = predecessor;
                } else {
                    parent->right = predecessor;
                }
            } else {
                    root = predecessor;
            }
            delete subRoot;
            subRoot = NULL;

        }

        void cleanUpTree(Node* subRoot) {
            if(subRoot != NULL) {
                cleanUpTree(subRoot->left);
                cleanUpTree(subRoot->right);
                delete subRoot;
            }
        }

        public:
        BinarySearchTree() {
            root = NULL;
        }

        void insert(Data data) {
            insert(data, root);
        }

        bool search (Data data) {
            return search(data, root);
        }

        void deleteNode (Data data) {
            deleteNode(data, root, NULL, false);
        }

        void preOrderTraversal(){
            preOrderTraversal(root);
        } 

        void inOrderTraversal() {
            inOrderTraversal(root);
        }

        void postOrderTraversal()  {
            postOrderTraversal(root);
        }

        void levelOrderTraversal() {
            levelOrderTraversal(root);
        }

        int heightOfTree() {
            return heightOfTree(root);
        }

        void printPaths() const {
            vector<Node*> path;
            printPaths(path, root);
        }

        int sumDistances() const {
            int pathlength = 0;
            return sumDistances(pathlength, root);
        }

        void printTree() {
            levelOrderTraversalVector(root);
            int currentLine = 1;
            int height = heightOfTree();
            string numSpaces = " ";
            while(height>0) {
                numSpaces = numSpaces + numSpaces;
                height--;
            }
            int total = 0;

            while(total < levelOrderTraversalV.size()) {
                int temp = 0;
                height = heightOfTree(levelOrderTraversalV[temp + total+1]);
                while(temp<currentLine) {
                    cout <<  numSpaces << levelOrderTraversalV[temp + total]->data << numSpaces;
                    temp++;
                }
                cout << endl;

                numSpaces = " ";
                while(height>0) {
                numSpaces = numSpaces + numSpaces;
                height--;
                }
                numSpaces = numSpaces + " ";
                total = currentLine + total;
                currentLine++;
            }

        }

        void examletFunction(Node* subroot) {
            if(subRoot->left != NULL) {
                examletFunction(subRoot->left);
            }   
            if (subRoot->left->)
            if(subRoot->right != NULL) {
                examletFunction(subRoot->right);
            }    
        }

        ~BinarySearchTree() {
            cleanUpTree(root);
            root = NULL;
        }



        


    };
}