/**
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * 
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 * 
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n == 0)	return 0;
    	int i, j;
    	for(i = 0, j = 1;j < n;j ++) {
    		if(A[j] != A[i] || (i == 0 || A[j] != A[i - 1])) {
    			A[++i] = A[j];
    		}
    	}
    	return i + 1;
    }
};