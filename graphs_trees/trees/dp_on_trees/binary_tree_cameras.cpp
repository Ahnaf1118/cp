#include <bits/stdc++.h>
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
    map<pair<TreeNode*, pair<int, int>>, int> mp;
    int dfs(TreeNode* root, bool cam, bool par_cam) {
        if (not root) {if (cam) return 1e9; else return 0;}
        if (not root->left and not root->right) {
            if (cam) return 1;
            else {
                if (par_cam) return 0;
                else return 1e9;
            }
        }
        if (mp.find({root, {cam, par_cam}}) != mp.end()) return mp[{root, {cam, par_cam}}];
        if (cam) {
            return mp[{root, {cam, par_cam}}] = 1 + min(dfs(root->left, 1, 1), dfs(root->left, 0, 1)) + min(dfs(root->right, 1, 1), dfs(root->right, 0, 1));
        }
        else if (par_cam) {
            return mp[{root, {cam, par_cam}}] = min(dfs(root->left, 0, 0), dfs(root->left, 1, 0)) + min(dfs(root->right, 0, 0), dfs(root->right, 1, 0));
        }
        else {
            int op1 = dfs(root->left, 1, 0) + min(dfs(root->right, 0, 0), dfs(root->right, 1, 0));
            int op2 = dfs(root->right, 1, 0) + min(dfs(root->left, 0, 0), dfs(root->left, 1, 0)); 
            return mp[{root, {cam, par_cam}}] = min(op1, op2);
        }
    }
    int minCameraCover(TreeNode* root) {
        return min(dfs(root, 0, 0), dfs(root, 1, 0));
    }
};