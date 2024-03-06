#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    //递归，前序遍历
    bool travel(TreeNode* root, int count) {
        if (root == NULL) {
            return false;
        }
        count -= root->val;
        if (root->left == NULL && root->right == NULL && count == 0) {
            return true;
        }
        if (root->left == NULL && root->right == NULL) {
            return false;
        }
        
        if (root->left) {
            if (travel(root->left, count)) {
                return true;
            }
        }
        if (root->right) {
            if (travel(root->right, count)) {
                return true;
            }
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return travel(root,targetSum);
    }

    //迭代法，前序，对组法
    bool hasPathSum_1(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        stack<pair<TreeNode*, int>> ts;
        ts.push(pair<TreeNode*, int>(root, root->val));
        while (!ts.empty()) {
            pair<TreeNode*, int> tmp = ts.top();
            ts.pop();
            if (tmp.first->left == NULL && tmp.first->right == NULL && tmp.second == targetSum) {
                return true;
            }
            if (tmp.first->right) {
                ts.push(pair<TreeNode*, int>(tmp.first->right, 
                    tmp.second + tmp.first->right->val));
            }
            if (tmp.first->left) {
                ts.push(pair<TreeNode*, int>(tmp.first->left,
                    tmp.second + tmp.first->left->val));
            }
        }
        return false;
    }
    //迭代法，前序双栈法
    bool hasPathSum_2(TreeNode* root, int targetSum) {
        stack<TreeNode*> ts;
        stack<int> csum;
        if (root == NULL) {
            return false;
        }
        ts.push(root);
        csum.push(root->val);
        while (!ts.empty()) {
            TreeNode* tmp = ts.top();
            ts.pop();
            int tmpSum = csum.top();
            csum.pop();
            if (tmp->left == NULL && tmp->right == NULL && tmpSum == targetSum) {
                return true;
            }
            if (tmp->right) {
                ts.push(tmp->right);
                csum.push(tmpSum + tmp->right->val);
            }
            if (tmp->left) {
                ts.push(tmp->left);
                csum.push(tmpSum + tmp->left->val);
            }
        }
        return false;
    }
};
// @lc code=end

