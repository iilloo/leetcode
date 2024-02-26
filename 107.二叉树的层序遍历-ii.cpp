#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <list>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode*> tq;
        if (root) {
            tq.push(root);
        }
        while (!tq.empty()) {
            int csize = tq.size();
            vector<int> tres;
            for (int i = 0; i < csize; ++i) {
                TreeNode* node = tq.front();
                tq.pop();
                tres.push_back(node->val);
                if (node->left) {
                    tq.push(node->left);
                }
                if (node->right) {
                    tq.push(node->right);
                }
            }
            res.push_back(tres);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
