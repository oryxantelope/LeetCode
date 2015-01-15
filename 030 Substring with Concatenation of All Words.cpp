/**
 * You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
 * 
 * For example, given:
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]
 * 
 * You should return the indices: [0,9].
 * (order does not matter).
 */

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
    	unordered_map<string, int> wordtime;
    	vector<int> ans;
    	int len = L[0].length();
    	for(int i = 0;i < (int)L[0].length();i ++) {
    		wordtime.clear();
        	for(int j = 0;j < (int)L.size();j ++) {
        		if(wordtime.find(L[j]) == wordtime.end())
        			wordtime[L[j]] = 1;
        		else
        			wordtime[L[j]] ++;
        	}
    		int start = i;
    		for(int end = i;end <= (int)S.length() - len;end += len) {
    			string current = S.substr(end, len);
    			if(wordtime.find(current) != wordtime.end()) {
    				if(wordtime[current] == 0) {
    					while(S.substr(start, len).compare(current) != 0) {
    						wordtime[S.substr(start, len)] ++;
    						start += len;
    					}
    					start += len;
    				} else {
    					wordtime[current] --;
    				}
    				if((end + len - start) / len == (int)L.size())
    					ans.push_back(start);
    			} else {
    				while(start < end) {
						wordtime[S.substr(start, len)] ++;
						start += len;
					}
    				start += len;
    			}
    		}
    	}
    	return ans;
    }
};