/**
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 * 
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 * 
 * The number of ways decoding "12" is 2.
 */

class Solution {
public:
    int numDecodings(string s) {
    	if(s.length() == 0)	return 0;
    	int dp[s.length()];
    	for(int index = s.length() - 1;index >= 0;index --) {
    		dp[index] = 0;
    		if(s[index] == '0')
    			continue;
    		dp[index] += (index + 1 < (int)s.length()) ? dp[index + 1] : 1;
    		if(index + 1 < (int)s.length() && ((s[index] - '0') * 10 + s[index + 1] - '0') <= 26) {
    			dp[index] += (index + 2 < (int)s.length()) ? dp[index + 2] : 1;
    		}
    	}
    	return dp[0];
    }
};