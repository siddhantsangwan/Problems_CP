#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ignore_s = 0, ignore_t = 0;
        int ptr_s = s.size() - 1, ptr_t = t.size() - 1;
        int flag_s = 0, flag_t = 0;
        
        while (ptr_s != -1 && ptr_t != -1)
        {
            flag_s = 0;
            flag_t = 0;
            if (ptr_s >= 0)
            {
                if (s[ptr_s] == '#')
                {
                    ignore_s++;
                    ptr_s--;
                }
                else
                {   
                    if (ignore_s > 0)
                    {
                        ptr_s--;
                        ignore_s--;
                        flag_s = 0;
                    }   
                    else
                        flag_s = 1;
                }
            }
            if (ptr_t >= 0)
            {
                if (t[ptr_t] == '#')
                {
                    ignore_t++;
                    ptr_t--;
                }
                else
                {
                    if (ignore_t > 0)
                    {
                        ptr_t--;
                        ignore_t--;
                        flag_s = 0;
                    }
                    else
                        flag_t = 1;
                }
            }
            if (flag_t && flag_s)
            {
                if (s[ptr_s] != t[ptr_t])
                    return false;
                else
                {
                    ptr_s--;
                    ptr_t--;
                }
            }
        }
        if (ptr_s == -1 && ptr_t == -1)
            return true;
        else
            return false;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        getline(cin, line);
        string T = stringToString(line);
        
        bool ret = Solution().backspaceCompare(S, T);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}