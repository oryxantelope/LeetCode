/**
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * click to show corner cases.
 * 
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */

class Solution {
public:
	static vector<string> split(char *cstr,const char* c) {
	    char *p;
	    vector<string> res;
	    p = strtok(cstr,c);
	    while(p!=NULL)
	    {
	        res.push_back(p);
	        p = strtok(NULL,c);
	    }
	    return res;
	}
    string simplifyPath(string path) {
    	char separator = '/';
    	char *cstr = new char[path.size() + 1];
    	strcpy(cstr, path.c_str());
    	vector<string> input = split(cstr, &separator);
    	vector<string> st;
    	string ans = "";
    	for(int i = 0;i < (int)input.size();i ++) {
    		if(input[i].compare(".") == 0) {
    			continue;
    		} else if(input[i].compare("..") == 0) {
    			if(!st.empty())
    				st.pop_back();
    		} else {
    			st.push_back(input[i]);
    		}
    	}
    	for(int i = 0;i < (int)st.size();i ++) {
    		ans += separator;
    		ans += st[i];
    	}
    	delete [] cstr;
    	return (ans.length() == 0) ? ans + separator : ans;
    }
};