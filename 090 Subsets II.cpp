/**
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.
 * 
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,2], a solution is:
 * 
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */

class Solution {
public:
	void subsetsRecur(vector<int> &S, int index, vector<vector<int> > &ans, vector<int> &tmp) {
		if(index == (int)S.size()) {
			ans.push_back(tmp);
		} else {
			int i, j;
			for(i = index + 1;i < (int)S.size() && S[i] == S[index];i ++);
			for(j = 1;j <= i - index;j ++) {
				tmp.push_back(S[index]);
				subsetsRecur(S, i, ans, tmp);
			}
			for(j = 1;j <= i - index;j ++) {
				tmp.pop_back();
			}
			subsetsRecur(S, i, ans, tmp);
		}
	}
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
    	sort(S.begin(), S.end());
    	vector<vector<int> > ans;
    	vector<int> tmp;
    	subsetsRecur(S, 0, ans, tmp);
    	return ans;
    }
};