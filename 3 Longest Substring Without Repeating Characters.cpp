/**
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int length = 0, ans = 0, start = -1;
    	int table[256];
    	for(int i = 0;i < 256;i ++) {
    		table[i] = -1;
    	}
    	for(int i = 0;i < (int)s.length();i ++) {
    		if(table[(int)s[i]] > start) {
    			ans = max(ans, length);
    			start = table[(int)s[i]];
    			length = i - start;
    		} else {
    			length ++;
    		}
    		table[(int)s[i]] = i;
    	}
    	return max(ans, length);
    }
};