#include <stack>
#include <vector>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stek; // cuvamo indekse
        vector<int> result(temperatures.size());

        for(int i = 0; i < temperatures.size(); i++) {
            if (stek.empty()) {
                stek.push(i);
                continue;
            }

            if (temperatures[i] <= temperatures[stek.top()]) {
                stek.push(i);
            }
            else {
                while (!stek.empty() && temperatures[i] > temperatures[stek.top()]) {
                    result[stek.top()] = i - stek.top();
                    stek.pop();
                }
                stek.push(i);
            }
        }
        return result;
    }
};
