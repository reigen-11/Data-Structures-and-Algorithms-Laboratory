#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    bool isThreaded;
};

Node* createNode(int value) {
    Node* node = new Node();
    node->value = value;
    node->isThreaded = false;
    return node;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* leftMostNode(Node* node) {
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

void inorder(Node* root) {
    Node* node = leftMostNode(root);
    while (node != NULL) {
        cout << node->value << " ";
        if (node->isThreaded) {
            node = node->right;
        } else {
            node = leftMostNode(node->right);
        }
    }
}

void thread(Node* node, Node*& prev) {
    if (node == NULL) {
        return;
    }
    thread(node->left, prev);
    if (node->left == NULL) {
        node->left = prev;
        node->isThreaded = true;
    }
    if (prev != NULL && !prev->isThreaded) {
        prev->right = node;
        prev->isThreaded = true;
    }
    prev = node;
    thread(node->right, prev);
}

Node* convertToThreaded(Node* root) {
    Node* prev = NULL;
    thread(root, prev);
    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    root = convertToThreaded(root);
    inorder(root);
    return 0;
}
