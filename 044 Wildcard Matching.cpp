/**
 * Implement wildcard pattern matching with support for '?' and '*'.
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 */

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	int lenS = strlen(s), lenP = strlen(p), k = 0;
    	for(int i = 0;i < lenP;i ++) {
    		if(p[i] != '*')
    			k ++;
    	}
    	if(k > lenS)	return false;
    	bool dp[lenP + 1][lenS + 1];
    	memset(dp, 0, sizeof(dp));
    	for(int i = lenP;i >= 0;i --) {
    		for(int j = lenS;j >= 0;j --) {
    			if(i == lenP && j == lenS) {
    				dp[i][j] = true;
    			} else if(i == lenP) {
    				dp[i][j] = false;
    			} else if(j == lenS) {
    			    dp[i][j] = (p[i] == '*') && dp[i + 1][j];
    			} else {
					switch(p[i]) {
					case '?':
						dp[i][j] = dp[i + 1][j + 1];
						break;
					case '*':
						dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
						break;
					default:
						dp[i][j] = (p[i] == s[j]) && dp[i + 1][j + 1];
						break;
					}
    			}
    		}
    	}
    	return dp[0][0];
    }
};