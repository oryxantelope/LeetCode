/**
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * 
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 * 
 * click to show more practice.
 * 
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

class Solution1 {
public:
    int maxSubArray(int A[], int n) {
    	if(n == 0)	return 0;
    	int sum = A[0], maxSum = A[0];
    	for(int i = 1;i < n;i ++) {
    		if(sum < 0)	{
    			sum = A[i];
    		} else {
    			sum += A[i];
    		}
    		if(sum > maxSum) {
    			maxSum = sum;
    		}
    	}
    	return maxSum;
    }
};

class Solution2 {
public:
    int maxSubArray(int A[], int n) {
    	if(n == 0) return 0;
    	if(n == 1) return A[0];
    	int maxSum = A[n/2], tmp;
    	tmp = maxSum;
    	for(int i = n/2 - 1;i >= 0;i --) {
    		tmp += A[i];
    		maxSum = tmp > maxSum ? tmp : maxSum;
    	}
    	tmp = maxSum;
    	for(int i = n/2 + 1;i < n;i ++) {
    		tmp += A[i];
    		maxSum = tmp > maxSum ? tmp : maxSum;
    	}
    	if(n / 2 > 0) {
    		tmp = maxSubArray(A, n/2);
    		maxSum = tmp > maxSum ? tmp : maxSum;
    	}
    	if(n - n/2 - 1 > 0) {
    		tmp = maxSubArray(A + n/2 + 1, n - n/2 - 1);
    		maxSum = tmp > maxSum ? tmp : maxSum;
    	}
    	return maxSum;
    }
};