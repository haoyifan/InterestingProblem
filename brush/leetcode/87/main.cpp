#include <string>
using namespace std;
class Solution {
	public:
		bool isScramble(string s1, string s2) {
			if(s1.size() != s2.size()) return false;
			if(s1 == s2) return true;
			int v[26] ={0};
			for(int i = 0; i < s1.size(); ++i) {
				v[s1[i] - 'a']++;
				v[s2[i] - 'a']--;
			}
			for(auto i : v) {
				if(i != 0)
					return false;
			}

			for(int i = 1; i < s1.size(); ++i) {
				if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
					return true;
				if(isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) && isScramble(s1.substr(i), s2.substr(0, s2.size() - i)))
					return true;
			}
			return false;
		}
};

int main() {
	Solution().isScramble("ab", "ba");
}
