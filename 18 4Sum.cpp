/**
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 *     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * 
 *     A solution set is:
 *     (-1,  0, 0, 1)
 *     (-2, -1, 1, 2)
 *     (-2,  0, 0, 2)
 */

class Solution1 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
    	sort(num.begin(), num.end());
    	vector<vector<int> > ans;
    	for(int i = 0;i < (int)num.size() - 3;) {
    		for(int j = i + 1;j < (int)num.size() - 2;) {
    			for(int m = j + 1, n = num.size() - 1;m < n;) {
    				if(num[i] + num[j] + num[m] + num[n] == target) {
    					vector<int> tmp;
    					tmp.push_back(num[i]);
    					tmp.push_back(num[j]);
    					tmp.push_back(num[m]);
    					tmp.push_back(num[n]);
    					ans.push_back(tmp);
    					m ++;
    					n --;
    					while(m < n && num[m] == num[m - 1])
    						m ++;
    					while(m < n && num[n] == num[n + 1])
    					    n --;
    				} else if(num[i] + num[j] + num[m] + num[n] < target) {
    					m ++;
    				} else {
    					n --;
    				}
    			}
    			j ++;
    			while(j < (int)num.size() - 2 && num[j] == num[j - 1])
    				j ++;
    		}
    		i ++;
    		while(i < (int)num.size() - 3 && num[i] == num[i - 1])
    			i ++;
    	}
    	return ans;
    }
};

class Solution2 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
    	sort(num.begin(), num.end());
    	vector<vector<int> > ans;
    	unordered_map<int, vector<pair<int, int> > > map;
    	for(int i = 0;i < (int)num.size();i ++) {
    		for(int j = i + 1; j < (int)num.size();j ++) {
    			map[num[i] + num[j]].push_back(pair<int, int>(i, j));
    		}
    	}
    	for(auto it = map.begin();it != map.end();it ++) {
    		vector<pair<int, int> > sum1 = it->second;
    		if(map.find(target - it->first) == map.end())
    			continue;
    		vector<pair<int, int> > sum2 = map[target - it->first];
    		for(int i = 0;i < (int)sum1.size();i ++) {
    			//The solution set must not contain duplicate quadruplets.
    			if(i != 0 && num[sum1[i].first] == num[sum1[i - 1].first])
    				continue;
    			for(int j = 0;j < (int)sum2.size();j ++) {
    				//The solution set must not contain duplicate quadruplets.
    				if(j + 1 < (int)sum2.size() && num[sum2[j].first] == num[sum2[j + 1].first])
    					continue;
    				//Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    				if(sum1[i].second < sum2[j].first) {
    					vector<int> tmp;
    					tmp.push_back(num[sum1[i].first]);
    					tmp.push_back(num[sum1[i].second]);
    					tmp.push_back(num[sum2[j].first]);
    					tmp.push_back(num[sum2[j].second]);
    					ans.push_back(tmp);
    				}
    			}
    		}
    	}
    	return ans;
    }
};