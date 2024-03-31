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
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    //递归法
    TreeNode* travel(vector<int>& nums, int begin, int end) {
        if (begin == end) {
            return NULL;
        }
        int rootIndex = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[rootIndex]);
        root->left = travel(nums, begin, rootIndex);
        root->right = travel(nums, rootIndex + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return travel(nums, 0, nums.size());
    }
    //迭代法,类似层次遍历
    TreeNode* sortedArrayToBST_1(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        queue<TreeNode*> nodeQ;
        queue<int> leftIndexQ;
        queue<int> rightIndexQ;
        leftIndexQ.push(0);
        rightIndexQ.push(nums.size());
        TreeNode* root = new TreeNode(nums[(0 + nums.size()) / 2]);
        nodeQ.push(root);
        while (!nodeQ.empty()) {
            TreeNode* cur = nodeQ.front();
            nodeQ.pop();

            int left_1 = leftIndexQ.front();
            leftIndexQ.pop();
            int right_2 = rightIndexQ.front();
            rightIndexQ.pop();
            int rootIndex = (left_1 + right_2) / 2;
            int left_2 = rootIndex + 1;
            int right_1 = rootIndex;

            if (left_1 != right_1) {
                cur->left = new TreeNode(nums[(left_1 + right_1)/2]);
                nodeQ.push(cur->left);
                leftIndexQ.push(left_1);
                rightIndexQ.push(right_1);
            }
            
            if (left_2 != right_2) {
                cur->right = new TreeNode(nums[(left_2 + right_2)/2]);
                nodeQ.push(cur->right);
                leftIndexQ.push(left_2);
                rightIndexQ.push(right_2);
            }
        }
        return root;
    }

};
// @lc code=end

