class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int d = s1.length()-1;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        if (s1.length() > s2.length())
            return false;

        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        while (d < s2.length()) {
            if (freq1 == freq2)
                return true;
            
            freq2[s2[l]-'a']--;
            l++;
            d++;
            if (d < s2.length())
                freq2[s2[d]-'a']++;
        }
        return false;
    }
};
