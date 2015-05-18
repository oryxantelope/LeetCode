/**
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 * 
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 * 
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 * 
 * Return 3.
 */

class Solution {
public:
	int numDistinct(string &S, string &T, int indexS, int indexT, int **dp) {
		if(indexS < indexT)	return 0;
		if(indexS == -1 || indexT == -1)	return 1;
		if(dp[indexS][indexT] != -1)	return dp[indexS][indexT];
		dp[indexS][indexT] = numDistinct(S, T, indexS - 1, indexT, dp);
		if(S[indexS] == T[indexT])
			dp[indexS][indexT] += numDistinct(S, T, indexS - 1, indexT - 1, dp);
		return dp[indexS][indexT];
	}
	int numDistinct(string S, string T) {
    	int lenS = S.length(), lenT = T.length(), ans;
    	int **dp;
    	dp = new int*[lenS];
    	for(int i = 0;i < lenS;i ++) {
    		dp[i] = new int [lenT];
    		for(int j = 0;j < lenT;j ++) {
    			dp[i][j] = -1;
    		}
    	}
    	ans = numDistinct(S, T, lenS - 1, lenT - 1, dp);
    	for(int i = 0;i < lenS;i ++) {
    		delete [] dp[i];
    	}
    	delete [] dp;
    	return ans;
    }
};