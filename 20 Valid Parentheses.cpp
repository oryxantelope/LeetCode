/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

class Solution {
public:
	char close(char endC) {
		switch(endC) {
		case ')':
			return '(';
			break;
		case ']':
			return '[';
			break;
		case '}':
			return '{';
			break;
		default:
			return ' ';
			break;
		}
	}
    bool isValid(string s) {
    	int length = s.length();
    	if(length == 0) return true;
    	if(length % 2 == 1)	return false;
    	stack<char> st;
    	for(int i = 0;i < length;i ++) {
    		if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
    			st.push(s[i]);
    		} else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
    			if(st.empty()) {
    				return false;
    			} else if(st.top() != close(s[i])) {
    				return false;
    			} else {
    				st.pop();
    			}
    		} else {
    			return false;
    		}
    	}
    	return st.empty();
    }
};