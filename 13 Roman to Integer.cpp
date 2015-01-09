/**
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */

class Solution {
public:
	int letterTpInt(char l) {
		switch(l) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		}
		return -1;
	}
    int romanToInt(string s) {
    	if(s.length() == 1) {
    		return letterTpInt(s[0]);
    	}
    	if(letterTpInt(s[0]) < letterTpInt(s[1])) {
    		return romanToInt(s.substr(1)) - letterTpInt(s[0]);
    	} else {
    		return romanToInt(s.substr(1)) + letterTpInt(s[0]);
    	}
    }
};