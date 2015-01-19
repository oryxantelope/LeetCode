/**
 * Given an array of strings, return all groups of strings that are anagrams.
 * 
 * Note: All inputs will be in lower-case.
 */

class Solution1 {
public:
	string sortAnagrams(string str) {
		int cnt[26];
		string ans;
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0;i < (int)str.length();i ++) {
			cnt[str[i] - 'a'] ++;
		}
		for(int i = 0;i < 26;i ++) {
			int j = cnt[i];
			while(j --)
				ans += ('a' + i);
		}
		return ans;
	}
    vector<string> anagrams(vector<string> &strs) {
    	vector<string> ans;
    	unordered_map<string, int > map;
    	for(int i = 0;i < (int)strs.size();i ++) {
    		string key = sortAnagrams(strs[i]);
    		if(map.find(key) == map.end()) {
    			map[key] = i;
    		} else {
    			if(map[key] != -1) {
    				ans.push_back(strs[map[key]]);
    				map[key] = -1;
    			}
    			ans.push_back(strs[i]);
    		}
    	}
    	return ans;
    }
};

class Solution2 {
public:
	string sortAnagrams(string str) {
		sort(str.begin(), str.end());
		return str;
	}
    vector<string> anagrams(vector<string> &strs) {
    	vector<string> ans;
    	unordered_map<string, int > map;
    	for(int i = 0;i < (int)strs.size();i ++) {
    		string key = sortAnagrams(strs[i]);
    		if(map.find(key) == map.end()) {
    			map[key] = i;
    		} else {
    			if(map[key] != -1) {
    				ans.push_back(strs[map[key]]);
    				map[key] = -1;
    			}
    			ans.push_back(strs[i]);
    		}
    	}
    	return ans;
    }
};