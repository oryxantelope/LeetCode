/**
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
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
    	height.pop_back();
    	return ans;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
    	if(matrix.size() == 0)	return 0;
    	vector<int> v(matrix[0].size());
    	int ans = 0;
    	for(int i = 0;i < (int)matrix.size();i ++) {
    		for(int j = 0;j < (int)matrix[0].size();j ++) {
    			if(matrix[i][j] == '0') {
    				v[j] = 0;
    			} else {
    				v[j] ++;
    			}
    		}
    		ans = max(ans, largestRectangleArea(v));
    	}
    	return ans;
    }
};