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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        vector<vector<int>> stats;
        while (true)
        {
            if (q.empty())
            {
                break;
            }

            auto [node, level] = q.front();
            q.pop();

            if (!node)
            {
                continue;
            }

            if (level == stats.size())
            {
                stats.push_back({});
            }

            stats[level].push_back(node->val);

            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }

        vector<double> ret;
        for (auto stat : stats)
        {
            double tot = 0;
            for (auto data : stat)
            {
                tot += data;
            }
            ret.push_back(tot / stat.size());
        }

        return ret;
    }
};