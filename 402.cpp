#include <string>
using namespace std;

class Problem402 {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        if (num.length() == k) return "0";
        for (int i = 0; i < num.length(); i++){
            while(!res.empty() && res.back() > num[i] && k > 0) res.pop_back(), k--;
            if (!res.empty() || num[i] != '0') res.push_back(num[i]);
        }
        while (k > 0 && !res.empty()){
            res.pop_back();
            k--;
        }
        return res.empty() ? "0" : res;
    }
};