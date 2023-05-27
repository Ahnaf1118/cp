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
    set<int> st;
    void dfs(TreeNode* root) {
        if (not root) return;
        st.insert(root->val);
        dfs(root->left); dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        int ans = 0;
        while(k--) {
            ans = *st.begin();
            st.erase(st.begin());
        }
        return ans;
    }
};