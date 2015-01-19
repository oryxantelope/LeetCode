/**
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6] 
 */

class Solution {
public:
	void combinationSumRecur(vector<int> &candidates, int target, int index, vector<vector<int> > &ans, vector<int> &tmp) {
		if(target == 0) {
			ans.push_back(tmp);
		} else if(target < 0 || index >= (int)candidates.size() || candidates[index] > target) {
			return ;
		} else {
			int repeatCnt;
			for(repeatCnt = 1; (index + repeatCnt) < (int)candidates.size() && candidates[index + repeatCnt] == candidates[index + repeatCnt - 1]; repeatCnt ++);
			combinationSumRecur(candidates, target, index + repeatCnt, ans, tmp);
			for(int i = 1;target - candidates[index] * i >= 0 && i <= repeatCnt;i ++) {
				tmp.push_back(candidates[index]);
				combinationSumRecur(candidates, target - candidates[index] * i, index + repeatCnt, ans, tmp);
			}
			for(int i = 1;target - candidates[index] * i >= 0 && i <= repeatCnt;i ++) {
				tmp.pop_back();
			}
		}
	}
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int> > ans;
		vector<int> tmp;
		combinationSumRecur(num, target, 0, ans, tmp);
		return ans;
	}
};