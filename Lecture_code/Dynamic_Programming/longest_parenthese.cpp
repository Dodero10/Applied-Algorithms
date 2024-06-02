// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
// substring
// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        stk.push(-1);
        int ans = 0;
        for(int i = 0 ; i < s.size();  i++)
        {
            if(s[i] == '(')
                stk.push(i);
            else
            {
                if(stk.size() == 1)
                    stk.top() = i;
                else
                {
                    stk.pop();
                    ans = max(ans , i - stk.top());
                }
            }
        }
        return ans;
    }
};