#include <string>
#include <vector>
using namespace std;

class Problem438 {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.length() > s.length()) return {};
        vector<int> freq(26, 0);
        vector<int> wind(26, 0);
        
        for (int i = 0; i < p.length(); i++){
            freq[p[i]-'a']++;
            wind[s[i]-'a']++;
        }
        
        vector<int> res;
        if (freq == wind) res.push_back(0);
        for (int i = p.length(); i < s.length(); i++){
            wind[s[i-p.length()] - 'a']--;
            wind[s[i] - 'a']++;
            
            if (freq == wind) res.push_back(i-p.length()+1);
        }
        return res;
    }
};