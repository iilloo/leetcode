#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
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

class Solution
{
public:
    void Next(string needle, int *next)
    {
        next[0] = 0;
        int j = 0, i = 1;
        for (; i < needle.size(); ++i)
        {

            while (j > 0 && needle[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (needle[i] == needle[j])
            {
                ++j;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle)
    {
        int i = 0, j = 0;
        int *next = new int[needle.size()];
        Next(needle, next);
        for(int i = 0; i < needle.size(); ++i)
        {
            cout<<next[i] ;
        }
        cout<<endl;
        for (; i < haystack.size(); ++i)
        {
            if (haystack[i] == needle[j])
            {
                if (j == needle.size() -1)
                {
                    return i - j;
                }
                ++j;
            }
            else if (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
                --i;
            }
        }
        return -1;
    }
};
int main()
{
    string haystack = "", needle = "";
    cin>>haystack;
    cin>>needle;
    Solution *s = new Solution();
    cout<<(s->strStr(haystack, needle));
    return 0;
}
