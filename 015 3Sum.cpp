/**
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *     For example, given array S = {-1 0 1 2 -1 -4},
 * 
 *     A solution set is:
 *     (-1, 0, 1)
 *     (-1, -1, 2)
 */

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	sort(num.begin(), num.end());
    	vector<vector<int> > ans;
    	for(int i = 0;i < (int)num.size();i ++) {
    		if(i - 1 >= 0 && num[i] == num[i - 1])
    			continue;
    		for(int j = i + 1,k = num.size() - 1;j < k;) {
    			if(num[j] + num[k] + num[i] < 0)
    				j ++;
    			else if(num[j] + num[k] + num[i] > 0)
    				k --;
    			else {
    				vector<int> tmp;
    				tmp.push_back(num[i]);
    				tmp.push_back(num[j++]);
    				tmp.push_back(num[k--]);
    				ans.push_back(tmp);
    				while(j < k && num[j] == num[j - 1])
    					j ++;
    				while(k > j && num[k] == num[k + 1])
    					k --;
    			}
    		}
    	}
    	return ans;
    }
};