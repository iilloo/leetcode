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
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> tq;
        if (root)
        {
            tq.push(root);
        }
        while (!tq.empty())
        {
            int csize = tq.size();
            Node *node_1 = NULL;
            for (int i = 0; i < csize; ++i)
            {
                Node* node = tq.front();
                tq.pop();
                if (i < csize - 1) {
                    node_1 = tq.front();
                } else {
                    node_1 = NULL;
                }
                if (node->left)
                {
                    tq.push(node->left);
                }
                if (node->right)
                {
                    tq.push(node->right);
                }
                if (node_1) {
                    node->next = node_1;
                }
                
            }
        }
        return root;
    }
};
// @lc code=end

