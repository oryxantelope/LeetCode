/**
 * Validate if a given string is numeric.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 * 
 * click to show spoilers.
 * 
 * Update (2014-12-06):
 * New test cases had been added. Thanks unfounder's contribution.
 */

class Solution {
public:
    bool isNumber(const char *s) {
    	static int transitionTable[][6] = {
    		// 0 SIGN 1 DIGIT 2 DOT 3 EXPONENT 4 SIGN 5 DIGIT 6
    		{ -1, 0, 1, 8, 2, -1}, 		// 0
    		{ -1, -1, -1, 8, 2, -1}, 	// 1
    		{ -1, 7, -1, 3, 2, 4}, 		// 2
    		{ -1, 7, -1, -1, 3, 4}, 	// 3
			{ -1, -1, 5, -1, 6, -1}, 	// 4
			{ -1, -1, -1, -1, 6, -1},	// 5
			{ -1, 6, -1, -1, 6, -1},	// 6
			{ -1, 7, -1, -1, -1, -1},	// 7 space after valid number
			{ -1, -1, -1, -1, 3, -1}	// 8 dot without digit before
    	};
    	int state = 0;
    	InputType inputType;
    	while(*s != '\0') {
    		if(isspace(*s)) {
    			inputType = SPACE;
    		} else if(*s == '+' || *s == '-') {
    			inputType = SIGN;
    		} else if(*s == '.') {
    			inputType = DOT;
    		} else if(isdigit(*s)) {
    			inputType = DIGIT;
    		} else if(*s == 'E' || *s == 'e') {
    			inputType = EXPONENT;
    		} else {
    			inputType = INVALID;
    		}

    		state = transitionTable[state][inputType];
    		if(state == -1) {
    			return false;
    		}
    		s++;
    	}
    	return (state == 2) || (state == 3) || (state == 6) || (state == 7);
    }

private:
    enum InputType {
    	INVALID,
    	SPACE,
    	SIGN,
    	DOT,
    	DIGIT,
    	EXPONENT
    };
};