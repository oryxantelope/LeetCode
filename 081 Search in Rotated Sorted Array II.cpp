/**
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * 
 * Would this affect the run-time complexity? How and why?
 * 
 * Write a function to determine if a given target is in the array.
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
		while(begin <= mid && A[begin] == A[mid])	begin ++;
		while(mid <= end && A[end] == A[mid])	end --;
		if(begin > mid) {
			return searchInRange(A, target, mid + 1, end);
		} else if(end < mid) {
			return searchInRange(A, target, begin, mid - 1);
		} else if(A[begin] < A[mid]) {
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
    bool search(int A[], int n, int target) {
    	return searchInRange(A, target, 0, n - 1) != -1;
    }
};