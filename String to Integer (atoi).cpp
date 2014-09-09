class Solution {
public:
	bool isMulOverflow(int a, int b) {
		if(a == 0 || b == 0)	return false;
		int c = a * b;
		return (c / a) != b || (c / b) != a;
	}
    int atoi(const char *str) {
    	int ans = 0, len = strlen(str), i = 0;
    	while(i < len && str[i] == ' ')	i++;
    	if(i == len)	return 0;
    	bool neg = str[i] == '-';
    	int MAX = (neg ? INT_MAX : INT_MAX - 1);
    	i += ((str[i] == '-' || str[i] == '+') ? 1 : 0);
    	for(;i < len;i ++) {
    		if(str[i] < '0' || str[i] > '9')
    			return neg ? -ans : ans;
    		if(isMulOverflow(ans, 10))
    			return neg ? INT_MIN : INT_MAX;
    		ans = ans * 10;
    		if(ans > MAX - (str[i] - '0'))
    			return neg ? INT_MIN : INT_MAX;
    		ans += str[i] - '0';
    	}
    	return neg ? -ans : ans;
    }
};