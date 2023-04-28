#include <iostream>
#include <vector>
#include<queue>

using namespace std;

class Node {
public:
    string data;
    vector<Node*> children;

    Node(string d) {
        data = d;
    }

    void addChild(Node* child) {
        children.push_back(child);
    }
};

void constructTree(Node* root) {
    int n;
    cout << "Enter the number of chapters for " << root->data << ": ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string childData;
        cout << "Enter the data for Chapter " << i + 1 << " of " << root->data << ": ";
        cin >> childData;

        Node* child = new Node(childData);
        root->addChild(child);

        constructTree(child); 
    }
}

// void printTree(Node* root) {
//     if (root == NULL) {
//         return;
//     }

//     cout << root->data << " ";

//     for (int i = 0; i < root->children.size(); i++) {
//         printTree(root->children[i]);
//         // cout << "-->";
//     }
// }

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        for (int i = 0; i < current->children.size(); i++) {
            q.push(current->children[i]);
        }
    }
}


int main() {
    string rootData;
    cout << "Enter the data for the root node: ";
    cin >> rootData;

    Node* root = new Node(rootData);

    constructTree(root);

    cout << "The tree in pre-order traversal: ";
    printTree(root);

    return 0;
}
