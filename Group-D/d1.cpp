#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Node {
    int key;
    int accessProbability;
    Node* left;
    Node* right;

    Node(int k, int p) : key(k), accessProbability(p), left(nullptr), right(nullptr) {}
};

Node* constructOBST(const vector<int>& keys, const vector<int>& probabilities, int start, int end) {
    if (start > end)
        return nullptr;

    int minCost = numeric_limits<int>::max();
    int minIndex = -1;
    int sumProbabilities = 0;

    for (int i = start; i <= end; i++)
        sumProbabilities += probabilities[i];

    for (int i = start; i <= end; i++) {
        Node* root = new Node(keys[i], probabilities[i]);
        int leftCost = (i == start) ? 0 : constructOBST(keys, probabilities, start, i - 1)->accessProbability;
        int rightCost = (i == end) ? 0 : constructOBST(keys, probabilities, i + 1, end)->accessProbability;
        int totalCost = leftCost + rightCost + sumProbabilities;

        if (totalCost < minCost) {
            minCost = totalCost;
            minIndex = i;
        }
    }

    Node* root = new Node(keys[minIndex], probabilities[minIndex]);
    root->left = constructOBST(keys, probabilities, start, minIndex - 1);
    root->right = constructOBST(keys, probabilities, minIndex + 1, end);

    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << "Key: " << root->key << ", Access Probability: " << root->accessProbability << endl;
    inorderTraversal(root->right);
}

int main() {
    vector<int> keys = {10, 20, 30, 40, 50};
    vector<int> probabilities = {4, 2, 6, 3, 1};

    Node* root = constructOBST(keys, probabilities, 0, keys.size() - 1);

    cout << "Optimal Binary Search Tree:" << endl;
    inorderTraversal(root);

    return 0;
}
