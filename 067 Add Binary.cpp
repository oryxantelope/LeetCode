/**
 * Given two binary strings, return their sum (also a binary string).
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */

class Solution1 {
public:
    string addBinary(string a, string b) {
    	int la = a.length(), lb = b.length(), ls = (la > lb) ? la : lb, carry = 0;
    	string sum = (la > lb) ? a : b;
    	char ca, cb;
    	for(int i = 0;i < ls;i ++) {
    		ca = (i < la) ? a[la - 1 - i] : '0';
    		cb = (i < lb) ? b[lb - 1 - i] : '0';
    		sum[ls - 1 - i] = (ca - '0' + cb - '0' + carry) % 2 + '0';
    		carry = (ca - '0' + cb - '0' + carry) / 2;
    	}
    	return (carry == 1) ? ("1" + sum) : sum;
    }
};

class Solution2 {
public:
    string addBinary(string a, string b) {
    	reverse(a.begin(), a.end());
    	reverse(b.begin(), b.end());
    	if(a.length() < b.length()) {
    		string c = a;
    		a = b;
    		b = c;
    	}
    	int carry = 0, index = 0;
    	for(index = 0;index < (int)b.length();index ++) {
    		a[index] += b[index] - '0' + carry;
    		if(a[index] - '0' > 1) {
    			a[index] -= 2;
    			carry = 1;
    		} else {
    			carry = 0;
    		}
    	}
    	for(;(index < (int)a.length()) && (carry == 1);index ++) {
    		a[index] += carry;
			if(a[index] - '0' > 1) {
				a[index] -= 2;
				carry = 1;
			} else {
				carry = 0;
			}
    	}
    	if(carry == 1) {
    		a += "1";
    	}
    	reverse(a.begin(), a.end());
    	return a;
    }
};