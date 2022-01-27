#include <bitset>
#include <algorithm>
#include <vector>
using namespace std;

class TrieNode{
public:
    TrieNode* child[2];
    TrieNode() { child[0] = NULL, child[1] = NULL; }
};
class Problem421 {
public:
    TrieNode* trie;
    
    void add(int x){
        TrieNode* node = trie;
        bitset<32> bs(x);
        for (int i = 31; i >= 0; i--){
            if (!node->child[bs[i]]) node->child[bs[i]] = new TrieNode();
            node = node->child[bs[i]];
        }
    }
    
    int maxXOR(int num){
        TrieNode* node = trie;
        bitset<32> bs(num);
        int res = 0;
        
        for (int i = 31; i >= 0; i--)
            (node->child[!bs[i]]) ?  res += (1<<i), node = node->child[!bs[i]] : node = node->child[bs[i]];
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        trie = new TrieNode();
        for (int num: nums) add(num);
        
        int res = 0;
        for (int num: nums) res = max(res, maxXOR(num));
        return res;
    }
};