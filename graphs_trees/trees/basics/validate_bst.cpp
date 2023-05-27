#include<bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    map<int, bool> mp;
    bool isValidBST(TreeNode* root, int mn=INT_MIN, int mx=INT_MAX) {
        if (!root) return true;
        if (mp.find(root->val) != mp.end()) return false;
        mp[root->val] = true;
        if (root->val < mn or root->val > mx) return false;
        if (root->left and root->val <= root->left->val) return false;
        if (root->right and root->val >= root->right->val) return false; 
        return isValidBST(root->left, mn, min(mx, root->val)) and isValidBST(root->right, max(mn, root->val), mx);
    }
};