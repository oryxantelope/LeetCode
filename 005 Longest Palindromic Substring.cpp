/**
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

class Solution {
public:
	string longestPalindrome(string s) {
		int length = s.length();
		int start, end;
		bool dp[1010][1010];
		for(int l = 1;l <= length;l ++) {
			for(int i = 0;i + l - 1 < length;i ++) {
				if(l == 1) {
					dp[i][i + l - 1] = true;
				} else if(l == 2) {
					dp[i][i + l - 1] = s[i] == s[i + l - 1];
				} else {
					dp[i][i + l - 1] = (s[i] == s[i + l -1]) && dp[i + 1][i + l - 2];
				}
				if(dp[i][i + l - 1]) {
					start = i;
					end = i + l - 1;
				}
			}
		}
		return s.substr(start, end - start + 1);
    }
};