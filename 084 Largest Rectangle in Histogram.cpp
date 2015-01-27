/**
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 * 
 * http://www.leetcode.com/wp-content/uploads/2012/04/histogram.png
 * 
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 * 
 * http://www.leetcode.com/wp-content/uploads/2012/04/histogram_area.png
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 * 
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.	
 */

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
    	stack<int> st;
    	int ans = 0, last, tmp;
    	height.push_back(0);
    	for(int i = 0;i < (int)height.size();i ++) {
    		last = -1;
    		while(!st.empty() && height[st.top()] > height[i]) {
    			tmp = st.top();
    			st.pop();
    			last = (last == -1) ? tmp : last;
    			if(st.empty()) {
					ans = max(ans, (last - 0 + 1) * height[tmp]);
				} else {
					ans = max(ans, (last - st.top()) * height[tmp]);
				}
    		}
    		st.push(i);
    	}
    	return ans;
    }
};