#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void inorder(TreeNode* root, vector<int>& ans){
        // Inorder traversal --> left - root - right
        if(root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

// Function to create a new Node
TreeNode* newNode(int val) {
    TreeNode* temp = new TreeNode(val);
    return temp;
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    cout << "Inorder traversal of the binary tree is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
