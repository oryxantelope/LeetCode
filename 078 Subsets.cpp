/**
 * Given a set of distinct integers, S, return all possible subsets.
 * 
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,3], a solution is:
 * 
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */

class Solution1 {
private:
    vector<vector<int> >res;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //先排序，然后dfs每个元素选或者不选，最后叶子节点就是所有解
        res.clear();
        sort(S.begin(), S.end());
        vector<int>tmpres;
        dfs(S, 0, tmpres);
        return res;
    }
    void dfs(vector<int> &S, int iend, vector<int> &tmpres)
    {
        if(iend == S.size())
            {res.push_back(tmpres); return;}
        //选择S[iend]
        tmpres.push_back(S[iend]);
        dfs(S, iend+1, tmpres);
        tmpres.pop_back();
        //不选择S[iend]
        dfs(S, iend+1, tmpres);
    }
};

class Solution2 {
public:
	void subsetsRecur(vector<int> &S, int index, vector<vector<int> > &ans, vector<int> &tmp) {
		if(index == (int)S.size()) {
			ans.push_back(tmp);
		} else {
			tmp.push_back(S[index]);
			subsetsRecur(S, index + 1, ans, tmp);
			tmp.pop_back();
			subsetsRecur(S, index + 1, ans, tmp);
		}
	}
    vector<vector<int> > subsets(vector<int> &S) {
    	sort(S.begin(), S.end());
    	vector<vector<int> > ans;
    	vector<int> tmp;
    	subsetsRecur(S, 0, ans, tmp);
    	return ans;
    }
};