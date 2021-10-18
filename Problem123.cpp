#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using namespace std;
class Problem123{
    int maxProfit (vector<int>& prices){
        vector<int> answer;
        int highest = INT_MAX, int lowest = INT_MIN;
        int profit1 = 0, int profit2 = 0;

        for (int i = 0; i < prices.size(); ++i){
            lowest = min(lowest, prices[i]);
            profit1 = max(profit1, prices[i] - lowest);
            answer.push_back(profit1);
        }
        for (int j = prices.size()-1; j >= 0; j--){
            highest = max(highest, prices[j]);
            profit2 = max(profit2, highest - prices[j]);
            answer[j] += profit2;
        }
        return *max_element(answer.begin(), answer.end());
    }
};