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
class BinaryTree {

    Node* root;
public:
    BinaryTree() {
        root = nullptr;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        // Recursive insertion:
        if (node->left == nullptr) {
            node->left = insert(node->left, value);
        }
        else if (node->right == nullptr) {
            node->right = insert(node->right, value);
        }
        else {
            // Agar dono full hain, left subtree me aage insert karo
            node->left = insert(node->left, value);
        }

        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void print(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        print(node->left);
        print(node->right);
    }
    void display(){
        print(root);
    }
};

int main() {
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);

    cout << "Binary Tree Preorder Traversal: ";
    bt.display();

    return 0;
}
