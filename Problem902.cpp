#include <vector>
#include <string>
using namespace std;

class Problem902 {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string limit = to_string(n);
        int digit = limit.size(), digitsize = digits.size(), res = 0;

        for(int i = 1; i < digit; i++) res += pow(digitsize, i);
        for(int i = 0; i < digit; i++){
            bool start = false;
            for(string &s :digits){
                if(s[0] < limit[i]) res += pow(digitsize, digit - i - 1);
                else if (s[0]==limit[i]) start=true;
            }
            if(!start) return res;
        }   
        return res+1;
    }
};