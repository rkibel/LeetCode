#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Problem165 {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        string curr = "";
        for (int i = 0; i < version1.length(); i++)
            (version1[i] == '.') ? v1.push_back(stoi(curr)), curr = "" : curr += version1[i];
        v1.push_back(stoi(curr));
        
        curr = "";
        for (int i = 0; i < version2.length(); i++)
            (version2[i] == '.') ? v2.push_back(stoi(curr)), curr = "" : curr += version2[i];
        v2.push_back(stoi(curr));
        
        for (int i = 0; i < max(v1.size(), v2.size()); i++){
            int a = (i >= v1.size()) ? 0 : v1[i];
            int b = (i >= v2.size()) ? 0 : v2[i];
            if (a > b) return 1;
            else if (a < b) return -1;
        }
        return 0;
    }
};