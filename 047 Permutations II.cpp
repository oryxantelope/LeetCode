/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * 
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 */

class Solution {
public:
	void reverse(vector<int> &num, int begin, int end) {
		for(; begin < end; begin ++, end --) {
			swap(num[begin], num[end]);
		}
	}
    bool nextPermutation(vector<int> &num) {
    	int length = num.size(), i, j;
    	for(i = length - 2;i >= 0 && num[i] >= num[i + 1];i --);
    	if(i < 0) {
    		return false;
    	} else {
    		reverse(num, i + 1, length - 1);
    		for(j = i + 1;num[i] >= num[j];j ++);
    		swap(num[i], num[j]);
    		return true;
    	}
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int> > ans;
		sort(num.begin(), num.end());
		ans.push_back(num);
		while(nextPermutation(num)) {
			ans.push_back(num);
		}
		return ans;
	}
};