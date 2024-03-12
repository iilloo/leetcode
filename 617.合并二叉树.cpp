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
using namespace std;
/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    //递归法，前序遍历
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return NULL;
        }
        if (root1 == NULL && root2 != NULL) {
            return root2;
        }
        if (root1 != NULL && root2 == NULL) {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
    //迭代法，层序遍历
    TreeNode* mergeTrees_1(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL) {
            return root2;
        }
        if (root2 == NULL) {
            return root1;
        }
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            TreeNode* tmp1 = que.front();
            que.pop();
            TreeNode* tmp2 = que.front();
            que.pop();
            tmp1->val += tmp2->val;
            //压入队列的结点是两个树的最大'公约数'，即两个树在相同的位置都有非空节点
            if (tmp1->left != NULL && tmp2->left != NULL) {
                que.push(tmp1->left);
                que.push(tmp2->left);
            }
            if (tmp1->right != NULL && tmp2->right != NULL) {
                que.push(tmp1->right);
                que.push(tmp2->right);
            }
            if (tmp1->left == NULL && tmp2->left != NULL) {
                tmp1->left = tmp2->left;
            }
            if (tmp1->right == NULL && tmp2->right != NULL) {
                tmp1->right = tmp2->right;
            }
        }
        return root1;  
    }
};
// @lc code=end

