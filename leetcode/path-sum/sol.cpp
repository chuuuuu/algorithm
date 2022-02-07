#include <bits/stdc++.h>

using namespace std;

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
    bool hasPathSum(TreeNode* root, int target) {
        return dfs(root, 0, target);
    }
    
    int dfs(TreeNode* node, int sum, int target){
        if(!node){
            return false;
        }
        
        sum += node->val;
        
        if(!node->left && !node->right){
            return sum == target;
        }
        
        return dfs(node->left, sum, target) | dfs(node->right, sum, target);
    }
};