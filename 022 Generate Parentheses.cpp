/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * 
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> v;
    	if(n == 0)	{
    		v.push_back("");
    		return v;
    	}
    	for(int i = 0;i < n;i ++) {
    		vector<string> inner = generateParenthesis(n - 1 - i);
    		vector<string> outter = generateParenthesis(i);
    		for(int i = 0;i < (int)inner.size();i ++) {
    			for(int j = 0;j < (int)outter.size();j ++) {
    				v.push_back("(" + inner[i] + ")" + outter[j]);
    			}
    		}
    	}
    	return v;
    }
};