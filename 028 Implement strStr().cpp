/**
 * Implement strStr().
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * Update (2014-11-02):
 * The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
 */

class Solution {
public:
    void initPartialMatchTable(char *needle, int * partialMatchTable) {
		partialMatchTable[0] = 0;
		for(int i = 1;i < (int)strlen(needle);i ++) {
			int k = partialMatchTable[i - 1];
			while(k != 0 && needle[i] != needle[k])
				k = partialMatchTable[k - 1];
			if(needle[i] == needle[k]) {
				partialMatchTable[i] = k + 1;
			} else {
				partialMatchTable[i] = 0;
			}
		}
	}
    int strStr(char *haystack, char *needle) {
    	if(strlen(needle) == 0)	return 0;
    	char *original = haystack;
    	int partialMatchTable[strlen(needle)];
    	initPartialMatchTable(needle, partialMatchTable);
    	char *pNeedle = needle;
    	while(*haystack != '\0' && *pNeedle != '\0') {
    		if(*haystack == *pNeedle) {
    			haystack ++;
    			pNeedle ++;
    		} else if(pNeedle == needle) {
    			haystack ++;
    		} else {
    			pNeedle = needle + partialMatchTable[pNeedle - needle - 1];
    		}
    	}
    	if(*pNeedle == '\0') {
    		return haystack - strlen(needle) - original;
    	}
    	return -1;
    }
};
