#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    if(!root){
      return {};
    }

    queue<pair<TreeNode *, int>> q({{root, 0}});
    vector<vector<int>> ret;
    while (!q.empty())
    {
      auto [first, second] = q.front();
      q.pop();

      if (first->left)
      {
        q.push({first->left, second + 1});
      }
      if (first->right)
      {
        q.push({first->right, second + 1});
      }

      if (ret.size() < second + 1)
      {
        ret.push_back({});
      }

      ret[second].push_back({first->val});
    }

    reverse(ret.begin(), ret.end());

    return ret;
  }
};