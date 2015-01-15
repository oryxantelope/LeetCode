/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    	if(strs.size() == 0)	return "";
    	for(int i = 0, j;i < (int)strs[0].length();i ++) {
    		for(j = 1;j < (int)strs.size();j ++) {
    			if(strs[j][i] != strs[j - 1][i])
    				break;
    		}
    		if(j != (int)strs.size())
    			return strs[0].substr(0, i);
    	}
    	return strs[0];
    }
};