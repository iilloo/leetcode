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
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> tq;
        if (root) {
            tq.push(root);
        }
        while (!tq.empty()) {
            vector<int> cres;
            int csize = tq.size();
            for (int i = 0; i < csize; ++i) {
                Node* node = tq.front();
                tq.pop();
                cres.push_back(node->val);
                for (int i = 0; i < node->children.size(); ++i) {
                    if (node->children[i]) {
                        tq.push(node->children[i]);
                    }
                }
            }
            res.push_back(cres);
        }
        return res;
    }
};
// @lc code=end

