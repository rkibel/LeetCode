#include "vector"
#include <cmath>
#include <algorithm>
using namespace std;

class Problem2078 {
public:
    int maxDistance(vector<int>& colors) {
        int maxDist = 0;
        for (int i = 0; i < colors.size(); i++){
            int color1 = colors[i];
            for (int j = i+1; j < colors.size(); j++){
                int color2  = colors[j];
                if (color2 != color1){
                    maxDist = max(maxDist, abs(j-i));
                }
            }
        }
        return maxDist;
    }
};