/**
 * Given a collection of numbers, return all possible permutations.
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

class Solution {
public:
	void permuteRecur(vector<vector<int> > &ans, int index, vector<int> &num, vector<int> &tmp) {
		if(index == (int)num.size()) {
			ans.push_back(tmp);
		} else {
			for(int i = index;i < (int)num.size();i ++) {
				swap(num[i], num[index]);
				tmp.push_back(num[index]);
				permuteRecur(ans, index + 1, num, tmp);
				tmp.pop_back();
				swap(num[i], num[index]);
			}
		}
	}
    vector<vector<int> > permute(vector<int> &num) {
    	vector<vector<int> > ans;
    	if(num.size() == 0)	return ans;
    	vector<int> tmp;
    	permuteRecur(ans, 0, num, tmp);
    	return ans;
    }
};