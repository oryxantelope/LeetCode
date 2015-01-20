/**
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x.
 */

class Solution1 {
public:
    int sqrt(int x) {
    	if (x == 0) return 0;
    	double res = 1, last = 0;
    	while(abs(res - last) >= 1e-8) {
    		last = res;
    		res = (res + x / res) / 2;
    	}
    	return res;
    }
};

class Solution2 {
public:
    int sqrt(int x) {
    	long long i = 0, j = x / 2 + 2, mid;
    	while(i <= j) {
    		mid = (i + j) / 2;
    		if(mid * mid == x)
    			return mid;
    		else if(mid * mid < x)
    			i = mid + 1;
    		else
    			j = mid - 1;
    	}
    	return j;
    }
};