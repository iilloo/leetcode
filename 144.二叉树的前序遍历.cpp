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
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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

// Definition for a binary tree node.


class Solution
{
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode *root)
    {

        if (root == nullptr)
        {
            return res;
        }
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
    //迭代法实现前序遍历
    vector<int> preorderTraversal_1(TreeNode *root) {
        stack<TreeNode*> ts;
        ts.push(root);
        while (!ts.empty()) {
            TreeNode *tmp = ts.top();
            ts.pop();
            if (tmp == NULL) {
                continue;
            }
            
            res.push_back(tmp->val);
            ts.push(tmp->right);
            ts.push(tmp->left);
            
        }
        return res;
    }
};
// @lc code=end
