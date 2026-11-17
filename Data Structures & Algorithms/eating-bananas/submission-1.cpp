class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long int upper = *max_element(piles.begin(), piles.end());
        long int lower = 1;
        long int answer = upper;

        while (lower <= upper) {
            long int middle = (upper - lower) / 2 + lower;
            long int current_sum = 0;
            for (long int i = 0; i < piles.size(); i++) {
                current_sum += ceil((double)piles[i] / middle);
            }
            if (current_sum <= h) {
                answer = middle;
                upper = middle-1;
            } else
                lower = middle+1;
        }

        return answer;
    }
};
