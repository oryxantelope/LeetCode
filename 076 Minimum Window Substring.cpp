/**
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 * 
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, return the emtpy string "".
 * 
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */

class Solution {
public:
    string minWindow(string S, string T) {
    	int cnt[2][128], validCnt = 0, start = 0, end = 0;
    	string ans = "";
    	memset(cnt, 0, sizeof(cnt));
    	for(int i = 0;i < (int)T.length();i ++)
    		cnt[0][(int)T[i]] ++;
    	for(start = 0; start < (int)S.length(); start ++) {
    		for(;end <= (int)S.length();end ++) {
    			if(validCnt == (int)T.length()) {
    				for(;cnt[0][(int)S[start]] == 0 || cnt[0][(int)S[start]] < cnt[1][(int)S[start]]; start++) {
						if(cnt[1][(int)S[start]] > 0)
							cnt[1][(int)S[start]] --;
					}
    				if(ans.length() == 0 || end - start < (int)ans.length()) {
    					ans = S.substr(start, end - start);
    				}
    				break;
    			}
    			if(end == (int)S.length())
    				break;
    			if(cnt[0][(int)S[end]] > 0) {
    				cnt[1][(int)S[end]] ++;
    				if(cnt[1][(int)S[end]] <= cnt[0][(int)S[end]])
    					validCnt ++;
    			}
    		}
    		cnt[1][(int)S[start]] --;
    		validCnt --;
    	}
    	return ans;
    }
};