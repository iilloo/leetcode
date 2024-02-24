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
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return res;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
        return res;
    }
    //递归法实现后续遍历
    vector<int> postorderTraversal_1(TreeNode* root) {
        stack<TreeNode*> ts;
        ts.push(root);
        while (!ts.empty()) {
            TreeNode *tmp = ts.top();
            ts.pop();
            if (tmp == NULL) {
                continue;
            }
            res.push_back(tmp->val);  
            ts.push(tmp->left);
            ts.push(tmp->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<int> postorderTraversal_2(TreeNode* root) {
        stack<TreeNode*> ts;
        if (root) {
            ts.push(root);
        }
        while (!ts.empty()) {
            TreeNode *tmp = ts.top();
            ts.pop();
            if (tmp != NULL) {
                ts.push(tmp);
                ts.push(NULL);
                if (tmp->right) {
                    ts.push(tmp->right);
                }
                if (tmp->left) {
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

