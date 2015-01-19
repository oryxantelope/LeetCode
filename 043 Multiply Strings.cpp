/**
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 * 
 * Note: The numbers can be arbitrarily large and are non-negative.
 */

class Solution {
public:
	void calSum(string &ans, string &tmp, int index) {
		int carry = 0, sum;
		for(sum = tmp.size() + index - ans.size();sum > 0;sum --)
			ans += '0';
		for(int i = 0;i < (int)tmp.size();i ++) {
			sum = carry + (tmp[i] - '0') + (ans[i + index] - '0');
			ans[i + index] = '0' + (sum % 10);
			carry = sum / 10;
		}
		while(carry != 0) {
			ans += '0' + (carry % 10);
			carry /= 10;
		}
	}
    string multiply(string num1, string num2) {
    	string ans = "", tmp;
    	int carry = 0, sum;
    	reverse(num1.begin(), num1.end());
    	reverse(num2.begin(), num2.end());
    	if(num1.size() < num2.size()) {
    		tmp = num1;
    		num1 = num2;
    		num2 = tmp;
    	}
    	for(int i = 0;i < (int)num2.size();i ++) {
    		carry = 0;
    		tmp = "";
    		for(int j = 0;j < (int)num1.size();j ++) {
    			sum = (num1[j] - '0') * (num2[i] - '0') + carry;
    			tmp += '0' + (sum % 10);
    			carry = sum / 10;
    		}
    		while(carry != 0) {
    			tmp += '0' + (carry % 10);
    			carry /= 10;
    		}
    		calSum(ans, tmp, i);
    	}
    	for(carry = ans.size() - 1; carry >= 0 && ans[carry] == '0'; carry --);
    	ans.resize(carry + 1);
    	reverse(ans.begin(), ans.end());
    	if(ans.size() == 0)
    		return "0";
    	return ans;
    }
};