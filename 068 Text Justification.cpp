/**
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 * 
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 * 
 * Return the formatted lines as:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 * Note: Each word is guaranteed not to exceed L in length.
 * 
 * click to show corner cases.
 * 
 * Corner Cases:
 * A line other than the last line might contain only one word. What should you do in this case?
 * In this case, that line should be left-justified.
 */

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
    	vector<string> ans;
    	int start = 0, len = 0, end = 0;
    	string currentLine;
    	for(;start < (int)words.size();start = end + 1) {
    		len = 0;
    		currentLine = "";
    		for(end = start;end < (int)words.size();end ++) {
    			if(len + (int)words[end].length() <= L) {
    				len += words[end].length() + 1;
    			} else {
    				end --;
    				break;
    			}
    		}
    		if(end == (int)words.size() || end == start) {
        		if(end == (int)words.size())
        			end --;
    			for(int i = start;i <= end;i ++)
    				currentLine += words[i] + ((i == end) ? "" : " ");
				while((int)currentLine.length() < L)
					currentLine += " ";
    		} else {
				int space = (L - len + 1) / (end - start), redundantSpace = (L - len + 1) % (end - start);
				for(int i = 0;i < end - start;i ++) {
					currentLine += words[i + start] + " ";
					for(int j = 0;j < space + ((i < redundantSpace) ? 1 : 0);j ++)
						currentLine += " ";
				}
				currentLine += words[end];
    		}
    		ans.push_back(currentLine);
    	}
    	return ans;
    }
};