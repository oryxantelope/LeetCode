/**
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * 
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	int i = m - 1,j = n - 1, k = m + n - 1;
    	while(i >= 0 && j >= 0) {
    		if(A[i] < B[j]) {
    			A[k--] = B[j--];
    		} else {
    			A[k--] = A[i--];
    		}
    	}
    	if(i = -1) {
    		while(j >= 0) {
    			A[k--] = B[j--];
    		}
    	}
    	if(j == -1) {
    		while(i >= 0) {
				A[k--] = A[i--];
			}
    	}
    }
};