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
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    //  有返回值的递归法
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        //下面的就是当前root在[L, R]内
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
    //无返回值的递归法
    //TreeNode* pre = NULL;
    void travel(TreeNode* pre, TreeNode* root, int low, int high) {
        if (root == NULL) {
            return;
        }
        if (root->val < low) {
            pre->left = root->right;
            //pre = root->right;
            travel(pre, root->right, low, high);
        } else if (root->val > high) {
            pre->right = root->left;
            //pre = root->left;
            travel(pre, root->left, low, high);
        }else {
            pre = root;
            travel(pre, root->left, low, high);
            travel(pre, root->right, low, high);
        }
        
        return;
    }
    TreeNode* trimBST_1(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* VH = new TreeNode(high);
        int flag = 0;
        if (root->val > high) {
            VH->right = root;
            flag = 1;
        } else {
            VH->left = root;
        }
        travel(VH, root, low, high);
        if (flag == 1) {
            return VH->right;
        }
        return VH->left;
    }
};
// @lc code=end

