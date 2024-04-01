#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    //递归法，反中序遍历
    int curNum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        root->right = convertBST(root->right);
        curNum += root->val;
        root->val = curNum;
        root->left = convertBST(root->left);
        return root;
    }
    //迭代法，反中序遍历
    TreeNode* convertBST_1(TreeNode* root) {
        int curNum = 0;
        stack<TreeNode*> ts;
        TreeNode* cur = root;
        while (cur != NULL || !ts.empty()) {
            if (cur != NULL) {
                ts.push(cur);
                cur = cur->right;
            } else {
                cur = ts.top();
                ts.pop();
                curNum += cur->val;
                cur->val = curNum;
                cur = cur->left;
            }
        }
        return root;
    }
};
// @lc code=end

