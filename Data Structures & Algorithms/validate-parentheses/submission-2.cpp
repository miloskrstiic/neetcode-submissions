class Solution {
public:
    bool isValid(string s) {
        stack<char> stek;
        for(int i = 0; i < s.length(); i++) {
            
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                stek.push(s[i]);
                continue;
            }

            if (stek.empty())
                return false;

            if ((s[i] == ']' && stek.top() != '[') ||
                (s[i] == ')' && stek.top() != '(') ||
                (s[i] == '}' && stek.top() != '{')) {
                return false;
            }
                
            stek.pop();
        }

        return stek.empty();
    }
};
