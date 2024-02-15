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
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    //重定义()操作符，可以让对象像函数一样使用 "对象(参数1， 参数2)"
    //返回true的意思是第一个参数的优先级小于第二个参数
    class myCompare {
    public:
        bool operator()(const pair<int, int>& l, const pair<int, int>& r) {
            return l.second > r.second;
        }  
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //map用于统计每个元素出现的次数
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }
        //定义一个小顶堆用来维护second值为前k大的元素
        //第一个参数指定该堆内存储的元素类型，第二个参数储存的是实现该堆的底层容器
        //第三个参数指定的是各个元素之间比较优先级的规则
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> mh;
        //不能用下标的方法遍历map因为map的key值是不连续的
        //遍历map要用迭代器
        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            mh.push(*it);
            //第二种写法
            //mh.push(pair<int, int>(it->first, it->second));
            if (mh.size() > k) {
                mh.pop();
            }
        }

        vector<int> res(k);//k指定了res的大小
        for (int i = k - 1; i >= 0; --i) {
            res[i] = mh.top().first;
            mh.pop();
        }
        return res;  //返回res
    }
};
// @lc code=end

