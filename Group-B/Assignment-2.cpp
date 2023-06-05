#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int val)
        { root = insertBST(root, val); }

    int longestPath()
        { return longestPathHelper(root); }

    void search(int val)
    {
        TreeNode* node = searchHelper(root, val);

        if (node == nullptr)
        {
            cout << "Value " << val << " not found in the BST." << endl;
        }
        else
        {
            cout << "Value " << val << " found in the BST." << endl;
        }
    }

    int minValue()
    { return minValueHelper(root); }

private:

    TreeNode* root;
    TreeNode* insertBST(TreeNode* node, int val)
    {
        if (node == nullptr)
            return new TreeNode(val);

        else if (val < node->val)
            node->left = insertBST(node->left, val);

        else if (val > node->val)
            node->right = insertBST(node->right, val);

        else
            cout << "Error: Value already exists in the BST" << endl;

        return node;

    }

    TreeNode* swapRoles(TreeNode* root) 
    {
        if (root == NULL)
            return NULL;

        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        swapRoles(root->left);
        swapRoles(root->right);

        return root;
    }

    TreeNode* searchHelper(TreeNode* node, int val)
    {
        if (node == nullptr || node->val == val)
            return node;

        if (val < node->val)
            return searchHelper(node->left, val);

        return searchHelper(node->right, val);
    }

    int minValueHelper(TreeNode* node)
    {
        if (node == nullptr)
            throw "Error: Tree is empty";

        while (node->left != nullptr)
            node = node->left;

        return node->val;
    }

    int longestPathHelper(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftHeight = longestPathHelper(node->left);
        int rightHeight = longestPathHelper(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

int main()
{
    BinarySearchTree obj;

    obj.insert(10);
    obj.insert(1);
    obj.insert(2);
    obj.insert(7);
    obj.insert(11);
    obj.insert(5);
    obj.insert(15);

    obj.search(15);

    cout << "Longest path from root : " << obj.longestPath() << endl;
    cout << "Minimum Data Value : " << obj.minValue()<<endl;
    
    return 0;
}
