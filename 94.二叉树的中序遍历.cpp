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
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return res;
        }
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);

        return res;
    }
    //迭代法
    vector<int> inorderTraversal_1(TreeNode *root)
    {
        stack<TreeNode *> ts;
        TreeNode *cp = root;
        while (!ts.empty() || cp != NULL)
        {
            if (cp != NULL)
            {
                ts.push(cp);
                cp = cp->left;
                
            }
            else
            {
                cp = ts.top();
                ts.pop();
                res.push_back(cp->val);
                cp = cp->right;
            }
        }
        return res;
    }
    //统一迭代法,标记法
    vector<int> inorderTraversal_2(TreeNode *root)
    {
        stack<TreeNode*> ts;
        if (root) {
            ts.push(root);
        }
        while (!ts.empty()) {
            TreeNode* tmp = ts.top();
            ts.pop();
            if (tmp != NULL) {
                if (tmp->right) {
                    ts.push(tmp->right);
                }
                ts.push(tmp);
                ts.push(NULL);
                if(tmp->left) {
                    ts.push(tmp->left);
                }
            } else {
                res.push_back(ts.top()->val);
                ts.pop();
            }
        }
        return res;
    }
};
// @lc code=end
