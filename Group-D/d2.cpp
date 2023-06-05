#include <iostream>
#include <string>
using namespace std;

struct Node {
    string keyword;
    string meaning;
    int height;
    Node* left;
    Node* right;
};

int getHeight(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

int getBalanceFactor(Node* node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

void updateHeight(Node* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

Node* rotateLeft(Node* root) {
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

Node* rotateRight(Node* root) {
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

Node* insert(Node* root, const string& keyword, const string& meaning) {
    if (root == nullptr) {
        Node* newNode = new Node{keyword, meaning, 1, nullptr, nullptr};
        return newNode;
    }
    if (keyword < root->keyword)
        root->left = insert(root->left, keyword, meaning);
    else if (keyword > root->keyword)
        root->right = insert(root->right, keyword, meaning);
    else {
        root->meaning = meaning;
        return root;
    }
    updateHeight(root);
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
        if (keyword < root->left->keyword)
            return rotateRight(root);
        else {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (balanceFactor < -1) {
        if (keyword > root->right->keyword)
            return rotateLeft(root);
        else {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;
}

void displayInOrder(Node* root) {
    if (root == nullptr)
        return;
    displayInOrder(root->left);
    cout << root->keyword << ": " << root->meaning << endl;
    displayInOrder(root->right);
}

Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* remove(Node* root, const string& keyword) {
    if (root == nullptr)
        return nullptr;
    if (keyword < root->keyword)
        root->left = remove(root->left, keyword);
    else if (keyword > root->keyword)
        root->right = remove(root->right, keyword);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = (root->left != nullptr) ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = findMin(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = remove(root->right, temp->keyword);
        }
    }
    if (root == nullptr)
        return root;
    updateHeight(root);
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
        if (getBalanceFactor(root->left) >= 0)
            return rotateRight(root);
        else {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if (balanceFactor < -1) {
        if (getBalanceFactor(root->right) <= 0)
            return rotateLeft(root);
        else {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;
}

int main() {
    Node* dictionary = nullptr;

    // Adding new keywords and meanings
    dictionary = insert(dictionary, "Apple", "A fruit");
    dictionary = insert(dictionary, "Banana", "A tropical fruit");
    dictionary = insert(dictionary, "Cucumber", "A vegetable");

    // Displaying the dictionary data in ascending order
    cout << "Dictionary data in ascending order:" << endl;
    displayInOrder(dictionary);
    cout << endl;

    // Removing a keyword from the dictionary
    dictionary = remove(dictionary, "Banana");

    // Displaying the updated dictionary data
    cout << "Dictionary data after removing 'Banana':" << endl;
    displayInOrder(dictionary);

    return 0;
}

