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
  int minDepth(TreeNode *root)
  {
    if (!root)
    {
      return 0;
    }

    queue<pair<TreeNode *, int>> q;
    q.push({root, 1});

    int ret;
    while (true)
    {
      auto [node, level] = q.front();
      q.pop();

      if (!node->right && !node->left)
      {
        ret = level;
        break;
      }

      if (node->left)
      {
        q.push({node->left, level + 1});
      }

      if (node->right)
      {
        q.push({node->right, level + 1});
      }
    }

    return ret;
  }
};