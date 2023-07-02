#include "vector"
using namespace std;

class Problem2079 {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        steps = 1;
        waterPlants(plants, capacity, capacity-plants[0], 1);
        return steps;
    }
    void waterPlants(vector<int>plants, int capacity, int currAmount, int i){
        if (i == plants.size()){
            return;
        }
        else if (currAmount >= plants[i]){
            steps++;
            waterPlants(plants, capacity, currAmount-plants[i], i+1);
        }
        else{
            steps += 2*i+1;
            waterPlants(plants, capacity, capacity-plants[i], i+1);
        }
    }
private:
    int steps;
};