/**
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 * 
 * For example:
 * Given "25525511135",
 * 
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

class Solution {
public:
	void restoreIpAddresses(string &s, int index, vector<string> &ans, vector<string> &tmp) {
		if(tmp.size() == 4) {
			if(index == (int)s.length())
				ans.push_back(tmp[0] + '.' + tmp[1] + '.' + tmp[2] + '.' + tmp[3]);
			else
				return ;
		} else {
			string ip;
			for(int i = 0;i < 3;i ++) {
				if(index + i < (int)s.length()) {
					ip = s.substr(index, i + 1);
					if((i == 1 && ip[0] == '0') || (i == 2 && (ip[0] == '0' || ip > "255")))
						continue;
					tmp.push_back(s.substr(index, i + 1));
					restoreIpAddresses(s, index + i + 1, ans, tmp);
					tmp.pop_back();
				}
			}
		}
	}
    vector<string> restoreIpAddresses(string s) {
    	vector<string> tmp;
    	vector<string> ans;
    	restoreIpAddresses(s, 0, ans, tmp);
    	return ans;
    }
};