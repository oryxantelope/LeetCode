/**
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string.
 */

class Solution {
public:
    string countAndSay(int n) {
    	string s = "1", tmp;
    	for(int i = 1;i < n;i ++) {
    		tmp = "";
    		for(int j = 0, count = 0;j <= (int)s.length();j ++) {
    			if(j == (int)s.length() || (j != 0 && s[j] != s[j - 1])) {
    				tmp += count + '0';
    				tmp += s[j - 1];
    				count = 1;
    			} else {
    				count ++;
    			}
    		}
    		s = tmp;
    	}
    	return s;
    }
};
