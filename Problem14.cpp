#include <string>
using namespace std;

class Problem14 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output = "";
        for (int i = 0; i < strs[0].length(); i++){
            char p = strs[0][i];
            for (int j = 0; j < strs.size(); j++){
                if (strs[j].length() <= i || strs[j][i] != p)
                    return output;
            }
            output += p;
        }
        return output;
    }
};