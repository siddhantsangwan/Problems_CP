#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   string count(string str, int index) {
       char prev = str[index];
       int c = 0;
       while (index < str.size() && str[index] == prev)
       {
           c++;
           prev = str[index];
           index++;
       }
       string s;
       if (index == str.size())
       {
           return s = to_string(c) + prev;
       }
       else
           return s = to_string(c) + prev + count(str, index);
   }
    
    string countAndSay(int n) {
       string str = "1";
       for (int i = 0; i < n; i++) 
           str = count(str, 0);
        
       return str;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}