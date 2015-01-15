/**
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 */

class Solution {
public:
	void combinationSumRecur(vector<int> &candidates, int target, int index, vector<vector<int> > &ans, vector<int> &tmp) {
		if(target == 0) {
			ans.push_back(tmp);
		} else if(target < 0 || index >= (int)candidates.size() || candidates[index] > target) {
			return ;
		} else {
			combinationSumRecur(candidates, target, index + 1, ans, tmp);
			for(int i = 1;target - candidates[index] * i >= 0;i ++) {
				tmp.push_back(candidates[index]);
				combinationSumRecur(candidates, target - candidates[index] * i, index + 1, ans, tmp);
			}
			for(int i = 1;target - candidates[index] * i >= 0;i ++) {
				tmp.pop_back();
			}
		}
	}
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    	sort(candidates.begin(), candidates.end());
		vector<vector<int> > ans;
    	vector<int> tmp;
    	combinationSumRecur(candidates, target, 0, ans, tmp);
    	return ans;
    }
};