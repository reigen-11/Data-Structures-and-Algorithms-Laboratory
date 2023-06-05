#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* constructExpressionTree(string prefixExpression) {
    stack<TreeNode*> stk;
    
    // Traverse the prefix expression in reverse order
    for (int i = prefixExpression.length() - 1; i >= 0; i--) {
        char ch = prefixExpression[i];
        
        // Create a new node for each character in the expression
        TreeNode* newNode = new TreeNode;
        newNode->data = ch;
        newNode->left = newNode->right = NULL;
        
        // If the character is an operand, push it onto the stack
        if (isalnum(ch)) {
            stk.push(newNode);
        }
        // If the character is an operator, pop two operands from the stack
        // and assign them as the left and right children of the operator node
        else {
            newNode->left = stk.top();
            stk.pop();
            newNode->right = stk.top();
            stk.pop();
            stk.push(newNode);
        }
    }
    
    // The top of the stack will be the root of the expression tree
    return stk.top();
}

void postOrderTraversal(TreeNode* root) {
    if (root == NULL)
        return;
    
    stack<TreeNode*> stk;
    TreeNode* current = root;
    TreeNode* lastVisited = NULL;
    
    while (!stk.empty() || current != NULL) {
        if (current != NULL) {
            stk.push(current);
            current = current->left;
        }
        else {
            TreeNode* topNode = stk.top();
            
            // If the right child exists and has not been visited yet
            if (topNode->right != NULL && topNode->right != lastVisited) {
                current = topNode->right;
            }
            else {
                // Process the node
                cout << topNode->data << " ";
                stk.pop();
                lastVisited = topNode;
            }
        }
    }
}

void deleteTree(TreeNode* root) {
    if (root == NULL)
        return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string prefixExpression = "+--a*bc/def";
    TreeNode* root = constructExpressionTree(prefixExpression);

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;
    deleteTree(root);

    return 0;
}
