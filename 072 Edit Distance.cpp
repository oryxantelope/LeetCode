/**
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 */

class Solution {
public:
	int minDistance(string &word1, int end1, string &word2, int end2, int **distance) {
		if(end1 == -1 || end2 == -1)	return end2 + end1 + 2;
		if(distance[end1][end2] != -1)	return distance[end1][end2];
		if(word1[end1] == word2[end2]) {
			distance[end1][end2] = minDistance(word1, end1 - 1, word2, end2 - 1, distance);
		} else {
			distance[end1][end2] =  1 + min(min(minDistance(word1, end1 - 1, word2, end2, distance),
					minDistance(word1, end1, word2, end2 - 1, distance)), minDistance(word1, end1 - 1, word2, end2 - 1, distance));
		}
		return distance[end1][end2];
	}
    int minDistance(string word1, string word2) {
    	int len1 = word1.length(), len2 = word2.length(), ans;
    	if(len1 == 0 || len2 == 0)	return len1 + len2;
    	int **distance = new int*[len1];
    	for(int i = 0;i < len1;i ++) {
    		distance[i] = new int[len2];
    		for(int j = 0;j < len2;j ++)
    			distance[i][j] = -1;
    	}
    	ans = minDistance(word1, len1 - 1, word2, len2 - 1, distance);
    	for(int i = 0;i < len1;i ++) {
			delete [] distance[i];
		}
    	delete []distance;
    	return ans;
    }
};