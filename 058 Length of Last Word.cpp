/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * 
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
    	int ans = 0, i, len;
    	for(i = 0,len = 0;i < (int)strlen(s);i ++) {
    		if(s[i] == ' ') {
    			ans = len > 0 ? len : ans;
    			len = 0;
    		} else {
    			len ++;
    		}
    	}
    	ans = len > 0 ? len : ans;
    	return ans;
    }
};