/**
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * 
 * The digits are stored such that the most significant digit is at the head of the list.
 */

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	int length = digits.size(), carry = 0;
    	digits[length - 1] ++;
    	for(int i = length - 1;i >= 0;i --) {
    		digits[i] += carry;
    		if(digits[i] > 9) {
    			carry = 1;
    			digits[i] -= 10;
    		} else {
    			carry = 0;
    		}
    	}
    	vector<int> res;
    	if(carry == 1) {
    		res.push_back(1);
    	}
    	for(int i = 0;i < length;i ++) {
    		res.push_back(digits[i]);
    	}
    	return res;
    }
};