/**
 * Implement pow(x, n).
 */

class Solution {
public:
    double pow(double x, int n) {
    	if(n == 0)	return 1.0;
    	if(n == 1)	return x;
    	bool neg = n < 0;
    	n = n < 0 ? -n : n;
    	double ans = pow(x, n / 2);
    	ans = (n&1) ? ans * ans * x : ans * ans;
    	return neg ? 1.0/ans : ans;
    }
};