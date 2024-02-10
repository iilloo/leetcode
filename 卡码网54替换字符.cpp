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
//二番战，双指针法
int func()
{
    string s = "";
    int count = 0, length = 0;
    cin>>s;
    length = s.size();
    for (int i = 0; i < length; ++i)
    {   //统计原字符串的大小
        if (s[i] >= '0' && s[i] <= '9')
        {
            ++count;
        }
    }   
    //新字符串的大小
    s.resize(length + count * 5);
    //od指向老字符串的结尾，nd指向新串的结尾
    //从后先前逐步填写新串
    int od = length - 1, nd = s.size() - 1;
    for (; od >= 0; --od)
    {
        if (s[od] >= '0' && s[od] <= '9')
        {
            s[nd] = 'r', --nd;
            s[nd] = 'e', --nd;
            s[nd] = 'b', --nd;
            s[nd] = 'm', --nd;
            s[nd] = 'u', --nd;
            s[nd] = 'n', --nd;
        }
        else 
        {
            s[nd] = s[od];
            --nd;
        }
    }
    cout<<s;
    return 0;
}


int main()
{
    string str;
    while (cin>>str)
    {
        int count = 0;//统计原字符串中数字的个数；
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                ++count;
            }
        }
        int os = str.size(), ns = os + 5 * count;
        str.resize(ns);
        int i = os - 1, j = ns - 1;
        for (; i >= 0; --i)
        {
            if ( str[i] >= '0' && str[i] <= '9')
            {
                str[j] = 'r', --j;
                str[j] = 'e', --j;
                str[j] = 'b', --j;
                str[j] = 'm', --j;
                str[j] = 'u', --j;
                str[j] = 'n', --j;
            }
            else
            {
                str[j] = str[i];
                --j;
            }
        }
        cout<<str;
    }
    return 0;
}