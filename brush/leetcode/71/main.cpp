#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> result;
        istringstream is(path);
        string sub;
        string str;

        while(getline(is, sub, '/')) {
            if(sub == "." || sub == "")
                continue;
            else if (sub == ".." && !result.empty())
                result.pop_back();
            else if (sub != "..")
                result.push_back(sub);
        }

        for(auto& s : result)
            str += "/" + s;
        return str == "" ? "/" : str;
    }
};

int main() {}

