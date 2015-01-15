/**
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

class Solution {
public:
	void reverse(vector<int> &num, int begin, int end) {
		for(; begin < end; begin ++, end --) {
			swap(num[begin], num[end]);
		}
	}
    void nextPermutation(vector<int> &num) {
    	int length = num.size(), i, j;
    	for(i = length - 2;i >= 0 && num[i] >= num[i + 1];i --);
    	if(i < 0) {
    		reverse(num, 0, length - 1);
    	} else {
    		reverse(num, i + 1, length - 1);
    		for(j = i + 1;num[i] >= num[j];j ++);
    		swap(num[i], num[j]);
    	}
    }
};