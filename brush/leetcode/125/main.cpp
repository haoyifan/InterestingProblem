#include <string>
#include <algorithm>
using namespace std;

class Solution {
	public:
		bool isPalindrome(string s) {
			string tmp;
			for(char c : s) {
				if(std::isalnum(c)) tmp+=std::tolower(c);
			}
			string rev(tmp);
			reverse(rev.begin(), rev.end());
			return tmp == rev;
		}
};

int main() {}
