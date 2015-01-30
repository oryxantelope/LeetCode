/**
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 * 
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 * 
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 */

class Solution {
public:
	bool isInterleave(string &s1, int len1, string &s2, int len2, string &s3, int len3, int **dp) {
		if(len1 == (int)s1.length() && len2 == (int)s2.length())
			return true;
		if(len1 == (int)s1.length() && len2 != (int)s2.length())
			return !s2.substr(len2).compare(s3.substr(len3));
		if(len1 != (int)s1.length() && len2 == (int)s2.length())
			return !s1.substr(len1).compare(s3.substr(len3));
		if(dp[len1][len2] == -1) {
			bool ans = false;
			if(s1[len1] == s3[len3])
				ans = ans || isInterleave(s1, len1 + 1, s2, len2, s3, len3 + 1, dp);
			if(s2[len2] == s3[len3])
				ans = ans || isInterleave(s1, len1, s2, len2 + 1, s3, len3 + 1, dp);
			dp[len1][len2] = ans;
		}
		return dp[len1][len2];
	}
    bool isInterleave(string s1, string s2, string s3) {
    	int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
    	if(len1 + len2 != len3)
    		return false;
    	int **dp = new int *[len1], ans;
    	for(int i = 0;i < len1;i ++) {
    		dp[i] = new int [len2];
    		for(int j = 0;j < len2;j ++)
    			dp[i][j] = -1;
    	}
    	ans = isInterleave(s1, 0, s2, 0, s3, 0, dp);
    	for(int i = 0;i < len1;i ++) {
    		delete [] dp[i];
    	}
    	delete [] dp;
    	return ans;
    }
};