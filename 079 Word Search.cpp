/**
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 * 
 * For example,
 * Given board =
 * 
 * [
 *   ["ABCE"],
 *   ["SFCS"],
 *   ["ADEE"]
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */

class Solution {
public:
	bool dfs(vector<vector<char> > &board, string &word, int index, bool **visited, int x, int y) {
		static int delta[2][4] = {{-1, 0, 0, 1}, {0, -1, 1, 0}};
		if(visited[x][y] || board[x][y] != word[index])
			return false;
		if(index == (int)word.length() - 1)
			return true;
		visited[x][y] = true;
		bool ans = false;
		for(int i = 0, m = board.size(), n = board[0].size();i < 4;i ++) {
			if(x + delta[0][i] < m && x + delta[0][i] >= 0 && y + delta[1][i] < n && y + delta[1][i] >= 0) {
				ans = ans || dfs(board, word, index + 1, visited, x + delta[0][i], y + delta[1][i]);
			}
		}
		visited[x][y] = false;
		return ans;
	}
    bool exist(vector<vector<char> > &board, string word) {
    	if(word.length() == 0)	return true;
    	if(board.size() == 0)	return false;
    	int m = board.size(), n = board[0].size();
    	bool **visited = new bool *[m];
    	for(int i = 0;i < m;i ++) {
    		visited[i] = new bool[n];
    		memset(visited[i], 0, n * sizeof(bool));
    	}
    	for(int i = 0;i < m;i ++) {
    		for(int j = 0;j < n;j ++) {
    			if(dfs(board, word, 0, visited, i, j)) {
    				for(int i = 0;i < m;i ++) {
						delete [] visited[i];
					}
					delete [] visited;
					return true;
    			}
    		}
    	}
    	for(int i = 0;i < m;i ++) {
			delete [] visited[i];
		}
    	delete [] visited;
    	return false;
    }
};