#include <stack>
#include <vector>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stek;

        for (const auto& token: tokens) {
            if (token != "+" && token != "-" && token != "/" && token != "*") {
                stek.push(stoi(token));
            }
            else {
                int op2 = stek.top();
                stek.pop();
                int op1 = stek.top();
                stek.pop();
                
                if (token == "+") {
                    stek.push(op1 + op2);
                }
                else if (token == "-") {
                    stek.push(op1 - op2);
                }
                else if (token == "*") {
                    stek.push(op1 * op2);
                }
                else if (token == "/") {
                    stek.push(op1 / op2);
                }
            }
        }
        return stek.top();
    }
};
