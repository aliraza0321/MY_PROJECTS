#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Recursive insert
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        // agar equal value aaye to ignore kar sakte ho (BST me duplicates optional hote hain)

        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    // Preorder traversal (Root, Left, Right)
    void preorder(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Inorder traversal (Left, Root, Right) → sorted output
  
};

int main() {
    BST tree;

    // Insert some data
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "BST Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    
    return 0;
}
