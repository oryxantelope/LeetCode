/**
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * 
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
    	sort(num.begin(), num.end());
    	int length = num.size(), ans = num[0] + num[1] + num[2];
    	for(int i = 0;i < length;i ++) {
    		for(int m = 0,n = length - 1;m < n;) {
    			if(m == i) {
    				m ++;
    			} else if(n == i) {
    				n --;
    			} else if(num[i] + num[m] + num[n] > target) {
    				if(abs(num[i] + num[m] + num[n] - target) < abs(ans - target)) {
    					ans = num[i] + num[m] + num[n];
    				}
    				n --;
    			} else {
    				if(abs(num[i] + num[m] + num[n] - target) < abs(ans - target)) {
						ans = num[i] + num[m] + num[n];
					}
    				m ++;
    			}
    		}
    	}
    	return ans;
    }
};