/**
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

class Solution {
public:
	int searchRange(int A[], int n, int target, int begin, int end, bool first) {
		if(begin > end)	return -1;
		if(begin == end && A[begin] == target)	return begin;
		int mid = begin + (end - begin) / 2;
		if((first && (A[mid] == target && (mid == 0 || A[mid - 1] != target)))
				|| (!first && (A[mid] == target && (mid == (n - 1) || A[mid + 1] != target)))) {
			return mid;
		} else if((first && A[mid] >= target) || (!first && A[mid] > target)) {
			return searchRange(A, n, target, begin , mid - 1, first);
		} else {
			return searchRange(A, n, target, mid + 1 , end, first);
		}
	}
    vector<int> searchRange(int A[], int n, int target) {
    	vector<int> ans;
    	ans.push_back(searchRange(A, n, target, 0, n - 1, true));
    	ans.push_back(searchRange(A, n, target, 0, n - 1, false));
    	return ans;
    }
};