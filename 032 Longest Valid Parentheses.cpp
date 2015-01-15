/**
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * 
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 * 
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

class Solution {
public:
    int longestValidParentheses(string s) {
    	stack<int> st;
    	int start = 0, ans = 0;
    	for(int i = 0;i < (int)s.length();i ++) {
    		if(s[i] == '(')
    			st.push(i);
    		else {
    			if(st.empty())
    				start = i + 1;
    			else {
					st.pop();
					if(st.empty()) {
						ans = max(i - start + 1, ans);
					} else {
						ans = max(i - st.top(), ans);
					}
    			}
    		}
    	}
    	return ans;
    }
};