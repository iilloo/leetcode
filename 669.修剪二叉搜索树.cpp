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
    //以下的方法构造了一个最大虚拟头节点，但要考虑该头节点不在low-high的情况，
    //所以有了label_1
    //其实可以不用构造头节点，如果root超范围，则可以在左右子树找出第一个符合范围的节点当作新的root节点
    //下面的迭代法就用了这种方法
    void travel(TreeNode* pre, TreeNode* root, int low, int high) {
        if (root == NULL) {
            return;
        }
        if (root->val < low) {
            pre->left = root->right;
            //pre = root->right;
            travel(pre, root->right, low, high);
        } else if (root->val > high) {
            //label_1
            if (pre->val >= root->val) {
                pre->left = root->left;
            } else {
                pre->right = root->left;
            }
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
        TreeNode* VH = new TreeNode(0x7fffffff);
        VH->left = root;
        travel(VH, root, low, high);
        return VH->left;
    }
    //迭代法
    TreeNode* trimBST_2(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return NULL;
        }
        while (root != NULL && (root->val < low || root->val > high)) {
            if (root->val < low) {
                root = root->right;
            } else if (root->val > high) {
                root = root->left;
            }
        }
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        //修剪左子树
        while (cur != NULL) {
            if (cur->val < low) {
                pre->left = cur->right;
                cur = cur->right;
            } else {
                pre = cur;
                cur = cur->left;
            }
        }
        cur = root;
        pre = NULL;
        //修剪右子树
        while (cur != NULL) {
            if (cur->val > high) {
                pre->right = cur->left;
                cur = cur->left;
            } else {
                pre = cur;
                cur = cur->right;
            }
        }

        return root;
    }
};
// @lc code=end

