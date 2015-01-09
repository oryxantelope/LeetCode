/**
 * Given a digit string, return all possible letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * 
 * http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

class Solution {
public:
	void letterCombinations(string &digits, int index, string &tmp, vector<string> &ans) {
		static string digit2letter[] = {" ", "'", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		if(index == (int)digits.length()) {
			ans.push_back(tmp);
		} else {
		    string letter = digit2letter[digits[index] - '0'];
			for(int i = 0;i < (int)letter.length();i ++) {
				tmp += letter[i];
				letterCombinations(digits, index + 1, tmp, ans);
				tmp.erase(tmp.end() - 1);
			}
		}
	}
    vector<string> letterCombinations(string digits) {
    	vector<string> ans;
    	string tmp = "";
    	letterCombinations(digits, 0, tmp, ans);
    	return ans;
    }
};