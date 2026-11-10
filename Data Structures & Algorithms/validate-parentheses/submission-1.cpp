class Solution {
public:
    bool isValid(string s) {
        stack<char> stek;
        for(int i = 0; i < s.length(); i++) {
            if (stek.empty()) {
                stek.push(s[i]);
                continue;
            }
            if (s[i] == ']' && stek.top() == '[')
                stek.pop();
            else if (s[i] == ')' && stek.top() == '(')
                stek.pop();
            
            else if (s[i] == '}' && stek.top() == '{')
                stek.pop();
            else
                stek.push(s[i]);
        }

        return stek.empty();
    }
};
