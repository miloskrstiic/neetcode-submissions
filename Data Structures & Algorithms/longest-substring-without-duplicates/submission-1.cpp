class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int d = 0;
        int substr = 0;
        unordered_set<char> chars;
        
        while (d < s.length()) {
            if (chars.find(s[d]) == chars.end()) {
                chars.insert(s[d]);
            }
            else {
                while (chars.find(s[d]) != chars.end() && l < d) {
                    chars.erase(s[l]);
                    l++;
                }
                chars.insert(s[d]);
            }

            substr = max(substr, d - l + 1);
            d++;
        }
        return substr;
    }
};
