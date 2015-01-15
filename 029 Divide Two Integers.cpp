/**
 * Divide two integers without using multiplication, division and mod operator.
 * 
 * If it is overflow, return MAX_INT.
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
    	long long lDividend = dividend;
    	long long lDivisor = divisor;
    	assert(divisor != 0);
        long long quotient = 0;
        long long step = 1;
        int negCount = 0;
        if(dividend < 0) {
        	lDividend = -(long long)dividend;
        	negCount ++;
        }
        if(divisor < 0) {
        	lDivisor = -(long long)divisor;
			negCount ++;
		}
        if(lDividend < lDivisor){
        	return 0;
        }
        while(lDividend >= lDivisor) {
        	lDividend -= lDivisor;
        	quotient += step;
        	step <<= 2;
        	lDivisor <<= 2;
        }
        lDivisor >>= 2;
        step >>= 2;
        while(step > 0 && lDividend != 0) {
			while(lDividend >= lDivisor) {
				lDividend -= lDivisor;
				quotient += step;
			}
			step >>= 2;
			lDivisor >>= 2;
		}
        return  quotient * ((negCount == 1) ? -1 : 1);
    }
};