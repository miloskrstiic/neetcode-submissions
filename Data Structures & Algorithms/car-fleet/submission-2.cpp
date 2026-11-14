#include <stack>
#include <vector>

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> fleets;

        int n = position.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) 
            vec.push_back({position[i], speed[i]});

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        vector<double> times;
        for (auto v: vec)
            times.push_back((double)(target - v.first) / v.second);

        fleets.push(times[0]);
        for (int i = 1; i < n; i++) {
            // fleets.push(times[i]);
            // if (times[i] <= fleets.top())
            //     fleets.pop();
            if (times[i] > fleets.top())
                fleets.push(times[i]);
        }

        return fleets.size();
    }
};
