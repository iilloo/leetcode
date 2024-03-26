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
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* travel(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        if (root->val < val) {
            root->right = travel(root->right, val);
        }
        if (root->val >= val) {
            root->left= travel(root->left, val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return travel(root, val);
    }
    //迭代法
    TreeNode* insertIntoBST_1(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur != NULL) {
            pre = cur;
            if (cur->val > val) {
                cur = cur->left; 
            } else {
                cur = cur->right;
            }
        }
        TreeNode* tmp = new TreeNode(val);
        if (pre->val > val) {
            pre->left = tmp;
        } else {
            pre->right = tmp;
        }
        return root;
    }
};
// @lc code=end

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    solution.insertIntoBST(root, 5);
    cout<<root->right->left->val<<endl;
    return 0;
}

