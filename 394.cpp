#include <string>
#include <sstream>
using namespace std;

class Problem394 {
public:
    string decodeString(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++){
            int bracketBegin = i, bracketEnd = i, numBrackets = 0;
            if (!isdigit(s[i])) res += s[i];
            else{
                for (int j = i+1; j < s.length(); j++){
                    if (s[j] == '['){
                        numBrackets++;
                        if (numBrackets == 1) bracketBegin = j;
                    }
                    else if (s[j] == ']'){
                        numBrackets--;
                        if (numBrackets == 0){
                            bracketEnd = j; 
                            break;
                        }
                    }
                }
                stringstream stream(s.substr(i, bracketBegin-i));
                int x = 0;
                stream >> x;
                for (int j = 0; j < x; j++)
                    res += decodeString(s.substr(bracketBegin+1, bracketEnd-bracketBegin-1));
                i = bracketEnd;
            } 
        }
        return res;
    }
};