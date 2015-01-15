/**
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

class Solution {
public:
	double findKthSortedArrays(int A[], int m, int B[], int n, int K) {
		if(m > n)
			return findKthSortedArrays(B, n, A, m, K);
		if(m == 0)
			return B[K - 1];
		if(K == 1)
			return min(A[0], B[0]);
		int a = min(m, K / 2), b = K - a;
		if(A[a - 1] == B[b - 1])
			return A[a - 1];
		else if(A[a - 1] < B[b - 1])
			return findKthSortedArrays(A + a, m - a, B, n, K - a);
		else
			return findKthSortedArrays(A, m, B + b, n - b, K - b);
	}
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	if((m + n) % 2 == 0)
    		return (findKthSortedArrays(A, m, B, n, (m + n) / 2) +
    				findKthSortedArrays(A, m, B, n, (m + n) / 2 + 1)) / 2;
    	else
    		return findKthSortedArrays(A, m, B, n, (m + n) / 2 + 1);
    }
};