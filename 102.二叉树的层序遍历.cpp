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
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// Definition for a binary tree node.
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
    //用迭代法实现层次遍历
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode*> tq;
        if (root) {
            tq.push(root);
        }
        while (!tq.empty()) {
            int size = tq.size();
            vector<int> tres;
            for (int i = 0; i < size; ++i) {
                TreeNode* tmp = tq.front();
                tq.pop();
                if (tmp) {
                    tres.push_back(tmp->val);
                    if (tmp->left) {
                        tq.push(tmp->left);
                    }
                    if (tmp->right) {
                        tq.push(tmp->right);
                    }
                    
                }
            }
            res.push_back(tres);
        }
        return res;
    }
    //用递归法，遍历节点的顺序是先根遍历的顺序
    void order(TreeNode* cur, vector<vector<int>> &res,int deepth) {
        if (!cur) {
            return;
        }
        if (res.size() == deepth) {
            res.push_back(vector<int>());
        }
        if (cur) {
            res[deepth].push_back(cur->val);
            order(cur->left, res, deepth + 1);
            order(cur->right, res, deepth + 1);
        } /* else {
            return; //叶子的左右NULL儿子也会导致多创建一个vector<int>元素
            //所以要放到最开始判断
        } */
    }
    vector<vector<int>> levelOrder_1(TreeNode *root) {
        int deepth = 0;
        order(root, res, deepth);
        return res;
    }
};
// @lc code=end
