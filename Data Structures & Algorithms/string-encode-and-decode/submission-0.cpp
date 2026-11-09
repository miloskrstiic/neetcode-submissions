class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(int i = 0; i < strs.size(); i++)
            result.append(to_string(strs[i].length()) + '#' + strs[i]);
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.length()) {
            string number = "";
            int j = i;
            while (s[j] != '#') {
                number += s[j];
                j++;
            }
            int string_length = stoi(number);
            result.push_back(s.substr(j+1, string_length));
            i = j + string_length + 1;
        }
        return result;
    }
};
