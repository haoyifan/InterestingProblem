#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> fullJustify(vector<string> &words, int L) {
            int wordsLen = 0;
            int startInd = 0;
            vector<string> result;
            int ind = 0;
            while(ind < words.size()) {
                if(wordsLen + words[ind].size() + ind - startInd <= L) {
                    wordsLen += words[ind].size();
                    ind++;
                } else {
                    if(ind - startInd - 1 == 0) {
                        string str;
                        str += words[startInd++];
                        while(str.size() < L)
                            str += " ";
                        result.push_back(str);
                        wordsLen = 0;
                    } else {
                        int spaceLen = L - wordsLen;
                        int avgSpaceLen = spaceLen / (ind - startInd - 1);
                        int extraSpaceLen = spaceLen % (ind - startInd - 1);
                        string str;
                        while(startInd < ind) {
                            str += words[startInd++];
                            if(startInd != ind) {
                                for(int i = 0; i < avgSpaceLen; ++i)
                                    str += " ";
                                if(extraSpaceLen > 0) {
                                    str += " ";
                                    extraSpaceLen--;
                                }
                            }
                        }
                        result.push_back(str);
                        wordsLen = 0;
                    }
                }
            }
            string str;
            while(ind > startInd) {
                str += words[startInd++];
                str += " ";
            }
            while(str.size() > L) str.pop_back();
            while(str.size() < L) str += " ";
            result.push_back(str);
            return result;
        }
};

int main() {
    /* vector<string> words = {"a","b","c","d","e"}; */
    /* vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."}; */
    /* vector<string> words = {"What","must","be","acknowledgment","shall","be"}; */
    vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"};
    auto v = Solution().fullJustify(words, 20);
    for(auto& ele : v)
        cout << ele << endl;
}
