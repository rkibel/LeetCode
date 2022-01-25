#include <vector>
using namespace std;

class Problem941 {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0;
        while(i < arr.size()-1 && arr[i] < arr[i+1]) i++;
        if (i == 0 || i == arr.size()-1 || arr[i] == arr[i+1]) return false;
        while(i < arr.size()-1 && arr[i] > arr[i+1]) i++;
        return (i == arr.size()-1);
    }
};