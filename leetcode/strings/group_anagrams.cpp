#include <bits/stdc++.h>
using namespace std;

string count_sort(string word)
{
    vector<int> table(26, 0);
    for (auto &c : word)
    {
        table[c - 97]++;
    }
    int num = 0;
    for (auto &c : table)
    {
        int x = c;
        c = num;
        num += x;
    }
    string sorted_word(word);
    // sorted_word.reserve(word.size());
    for (auto &c : word)
    {
        sorted_word[table[c - 97]] = c;
        table[c - 97]++;
    }
    return sorted_word;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map< string, vector<string> > dict(strs.size());
    string sorted_word;
    for (auto &word : strs)
    {
        sorted_word = count_sort(word);
        dict[sorted_word].emplace_back(word);
    }
    
    vector < vector<string> > a;
    a.reserve(strs.size());
    for (auto &key : dict)
        a.emplace_back(key.second);
    
    return a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    
    vector< vector <string> > a = groupAnagrams(input);
    for (auto vec : a)
    {
        for (auto str : vec)
            cout << str << ", ";
        cout << '\n';
    }
    return 0;
}