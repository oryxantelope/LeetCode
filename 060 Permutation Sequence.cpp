/**
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 */

class Solution1 {
public:
    string getPermutation(int n, int k) {
    	string s;
    	int factorial[n], i, j, t;
    	bool num[n];
    	memset(factorial, 0, sizeof(factorial));
    	memset(num, 0, sizeof(num));
    	factorial[0] = 1;
    	for(i = 1;i < n;i ++) {
    		factorial[i] = i * factorial[i - 1];
    	}
    	for(i = n - 1;k != 0 && i >= 0; i --) {
			t = (k + factorial[i] - 1) / factorial[i];
			k -= (t - 1) * factorial[i];
			for(j = 1;t > 0 && j <= n; j ++) {
				if(!num[j - 1]) {
					t --;
					if(t == 0)
						break;
				}
			}
    		num[j - 1] = true;
    		s += j + '0';
    	}
    	return s;
    }
};

class Solution2 {
public:
	void reverse(vector<int> &num, int begin, int end) {
		for(; begin < end; begin ++, end --) {
			swap(num[begin], num[end]);
		}
	}
	bool nextPermutation(vector<int> &num) {
		int length = num.size(), i, j;
		for(i = length - 2;i >= 0 && num[i] >= num[i + 1];i --);
		if(i < 0) {
			return false;
		} else {
			reverse(num, i + 1, length - 1);
			for(j = i + 1;num[i] >= num[j];j ++);
			swap(num[i], num[j]);
			return true;
		}
	}
    string getPermutation(int n, int k) {
    	vector<int> num;
    	for(int i = 1;i <= n;i ++) {
    		num.push_back(i);
    	}
    	while(-- k) {
    		nextPermutation(num);
    	}
    	string ans;
    	for(int i = 0;i < (int)num.size();i ++) {
    		ans += num[i] + '0';
    	}
    	return ans;
    }
};