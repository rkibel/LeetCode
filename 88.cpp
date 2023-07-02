#include <vector>
#include <iostream>
using namespace std;

class Problem88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums;
        int currM = 0;
        int currN = 0;
        int i = 0;
        while(i < m+n){
            //cout << currM << " " << currN << endl;
            if (currM == m){
                nums.push_back(nums2.at(currN));
                currN++;
            }
            else if (currN == n){
                nums.push_back(nums1.at(currM));
                currM++;
            }
            else{
                if (nums2.at(currN) < nums1.at(currM)){
                    nums.push_back(nums2.at(currN));
                    currN++;
                }
                else{
                    nums.push_back(nums1.at(currM));
                    currM++;
                }
            }
            i++;
        }
        for (int j = 0; j < nums1.size(); j++){
            nums1[j] = nums[j];
        }
    }
};