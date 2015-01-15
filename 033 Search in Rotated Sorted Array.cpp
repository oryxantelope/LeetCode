/**
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 */

class Solution {
public:
	int searchInRange(int A[], int target, int begin, int end) {
		if(begin > end)	return -1;
		if(begin == end)	return (A[begin] == target) ? begin : -1;
		if(A[begin] == target)	return begin;
		if(A[end] == target)	return end;
		int mid = (begin + end) / 2;
		if(A[mid] == target)	return mid;
		if(A[begin] < A[mid]) {
			if(A[begin] <= target && target < A[mid])
				return searchInRange(A, target, begin, mid - 1);
			else
				return searchInRange(A, target, mid + 1, end);
		} else {
			if(A[mid] < target && target <= A[end])
				return searchInRange(A, target, mid + 1, end);
			else
				return searchInRange(A, target, begin, mid - 1);
		}
	}
    int search(int A[], int n, int target) {
    	return searchInRange(A, target, 0, n - 1);
    }
};