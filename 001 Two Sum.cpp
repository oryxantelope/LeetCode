/**
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> answer;
    	int size = numbers.size();
    	vector<int> backup = numbers;
    	sort(backup.begin(), backup.end());
        int left = 0, right = size - 1, sum;
        while(left < right) {
        	sum = backup[left] + backup[right];
        	if(sum == target) {
        		for(int i = 0;i < size;i ++) {
        			if(backup[left] == numbers[i] || backup[right] == numbers[i]) {
        				answer.push_back(i + 1);
        			}
        		}
        		break;
        	} else if(sum < target) {
        		left ++;
        	} else {
        		right --;
        	}
        }
        return answer;
    }
};
