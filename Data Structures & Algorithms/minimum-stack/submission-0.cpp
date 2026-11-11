#include <stack>
#include <unordered_set>
#include <climits>

class MinStack {
public:
    stack<pair<int, int>> stek;
    int minimum = INT_MAX;

    MinStack() {

    }
    
    void push(int val) {
        if (stek.empty()) {
            stek.push(make_pair(val, val));
        }
        else {
            stek.push(make_pair(val, min(val, stek.top().second)));
        }
    }
    
    void pop() {
        if (!stek.empty()) {
            stek.pop();
        }
    }
    
    int top() {
        return stek.top().first;
    }
    
    int getMin() {
        return stek.top().second;
    }
};
