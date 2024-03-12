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
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* cut(vector<int>& nums, int begin, int end) {
        if (begin == end) {
            return NULL;
        }
        //max_element函数在algorithm头文件中
        //函数的返回值类型是std::vector<int>::iterator是一个迭代器类型
        int max = *(max_element(nums.begin() + begin, nums.begin() + end));
        //distance函数在iterator头文件中，用来取下标
        //find函数的头文件是algorithm，它用于在范围[first, last)内查找等于val的第一个元素,
        //并返回指向该元素的迭代器。如果没有找到,则返回last。
        // int index = distance(nums.begin() + begin, find(nums.begin() + begin, nums.begin() + end, maxVal));
        int index = 0;
        for (index = begin; index < end; ++index) {
            if (nums[index] == max) {
                break;
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = cut(nums, begin, index);
        root->right = cut(nums, index + 1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return cut(nums, 0, nums.size());
    }
};
// @lc code=end

