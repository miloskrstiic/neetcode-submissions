#include <unordered_map>

class TimeMap {
private:
    unordered_map< string, vector<pair<string, int>> > mapa;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mapa[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& current = mapa[key];

        string result = "";
        int l = 0;
        int d = current.size() - 1;

        while (l <= d) {
            int s = (d - l) / 2 + l;

            if (current[s].second <= timestamp) {
                result = current[s].first;
                l = s+1;
            }
            else 
                d = s-1;
        }
        return result;
    }
};
