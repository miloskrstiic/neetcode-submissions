class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> chars;
        int l = 0;
        int d = 0;
        int maxstring = 0;

        while (d < s.length()) {
            chars[s[d]]++;
            
            int most_freq = -1;
            for (const auto& [character, freq] : chars)
                most_freq = max(freq, most_freq);

            while (d-l+1 - most_freq > k) {
                chars[s[l]]--;
                l++;

                int most_freq = -1;
                for (const auto& [character, freq] : chars)
                    most_freq = max(freq, most_freq);
            }
            
            maxstring = max(maxstring, d - l + 1);
            d++;
        }

        return maxstring;
    }
};
