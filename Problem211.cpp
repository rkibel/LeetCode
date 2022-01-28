#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Problem211 {
public:
    unordered_map<int, vector<string>> map;
    
    bool equal(string word1, string word2){
        for (int i = 0; i < word1.length(); i++){
            if (word2[i] == '.') continue;
            if (word1[i] != word2[i]) return false;
        }
        return true;
    }
    
    Problem211() {}
    
    void addWord(string word) {
        map[word.length()].push_back(word);
    }
    
    bool search(string word) {
        for (auto i: map[word.length()])
            if (equal(i, word)) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */