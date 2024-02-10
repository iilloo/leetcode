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
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    queue<int> q;
    queue<int> sq;
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        --size;
        while (size != 0)
        {
            sq.push(q.front());
            q.pop();
            --size;
        }
        int result = q.front();
        q.pop();
        q = sq; //竟然可以直接赋值；
        while (!sq.empty())
        {
            sq.pop();
        }
        return result;
    }
    
    int top() {
        return q.back();

    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// @lc code=end

