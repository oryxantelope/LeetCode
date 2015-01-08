/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

class Solution {
public:
    string convert(string s, int nRows) {
    	if(nRows == 1)	return s;
    	string ans;
    	int len = s.length();
    	for(int i = 0;i < len;i += 2 * nRows - 2) {
    		ans += s[i];
    	}
    	for(int i = 1;i < nRows - 1;i ++) {
    		for(int j = i;j < len; j += 2 * nRows - 2) {
    			ans += s[j];
    			if((j + 2 * nRows - 2 - 2 * i) < len) {
    				ans += s[j + 2 * nRows - 2 - 2 * i];
    			}
    		}
    	}
    	for(int i = nRows - 1;i < len;i += 2 * nRows - 2) {
			ans += s[i];
		}
    	return ans;
    }
};