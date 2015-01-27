/**
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 * 
 * Below is one possible representation of s1 = "great":
 * 
 *     great
 *    /    \
 *   gr    eat
 *  / \    /  \
 * g   r  e   at
 *            / \
 *           a   t
 * To scramble the string, we may choose any non-leaf node and swap its two children.
 * 
 * For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
 * 
 *     rgeat
 *    /    \
 *   rg    eat
 *  / \    /  \
 * r   g  e   at
 *            / \
 *           a   t
 * We say that "rgeat" is a scrambled string of "great".
 * 
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
 * 
 *     rgtae
 *    /    \
 *   rg    tae
 *  / \    /  \
 * r   g  ta  e
 *        / \
 *       t   a
 * We say that "rgtae" is a scrambled string of "great".
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */

class Solution {
public:
	bool isScramble(string &s1, string &s2, int s, int t, int cnt, int ***dp) {
		if(dp[s][t][cnt] != -1)
			return dp[s][t][cnt];
		bool ans = false;
		if(cnt == 1) {
			ans = (s1[s] == s2[t]);
		} else {
			for(int i = 1;i < cnt;i ++) {
				if(isScramble(s1, s2, s, t, i, dp) && isScramble(s1, s2, s + i, t + i, cnt - i, dp)) {
					ans = true;
					break;
				}
				if(isScramble(s1, s2, s, t + cnt - i, i, dp) && isScramble(s1, s2, s + i, t, cnt - i, dp)) {
					ans = true;
					break;
				}
			}
		}
		dp[s][t][cnt] = ans;
		return ans;
	}
    bool isScramble(string s1, string s2) {
    	if(s1.length() != s2.length())	return false;
    	if(s1.length() == 0)	return true;
    	int len = s1.length();
    	int ***dp = new int **[len];
    	for(int i = 0;i < len;i ++) {
    		dp[i] = new int *[len];
    		for(int j = 0;j < len;j ++) {
    			dp[i][j] = new int[len + 1];
    			for(int k = 0;k < len + 1;k ++) {
    				dp[i][j][k] = -1;
    			}
    		}
    	}
    	bool ans = isScramble(s1, s2, 0, 0, s1.length(), dp);
    	for(int i = 0;i < len;i ++) {
    		for(int j = 0;j < len;j ++) {
    			delete [] dp[i][j];
			}
    		delete [] dp[i];
		}
    	delete [] dp;
    	return ans;
    }
};