/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * 
 * For example,
 * If n = 4 and k = 2, a solution is:
 * 
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

class Solution {
public:
	void combine(int begin, int n, int k, vector<int> &tmp, vector<vector<int> > &ans) {
		if(n - begin + 1 < k)	return ;
		if(k == 0)	{
			ans.push_back(tmp);
			return ;
		}
		combine(begin + 1, n, k, tmp, ans);
		tmp.push_back(begin);
		combine(begin + 1, n, k - 1, tmp, ans);
		tmp.pop_back();
		return ;
	}
    vector<vector<int> > combine(int n, int k) {
    	vector<vector<int> > ans;
    	vector<int> tmp;
    	combine(1, n, k, tmp, ans);
    	return ans;
    }
};