#include <vector>
#include <string>
using namespace std;
/*
class Solution {
	public:
		bool palin(const string& s) {
			for(unsigned long i = 0; i < s.size() / 2; ++i) {
				if(s[i] != s[s.size() - i - 1]) return false;
			}
			return true;
		}

		void combine(vector<vector<string>>& v, const string& s) {
			if(v.empty()) {
				vector<string> tmp{s};
				v.push_back(tmp);
				return;
			}
			for(auto& vic : v) {
				vic.push_back(s);
			}
			return;
		}

		vector<vector<string>> partition(string s) {
			vector<vector<string>> result;
			if(s.size() == 0) return result;

			for(int i = s.size() - 1; i >= 0; --i) {
				if(palin(s.substr(i, s.size() - i))) {
					auto sub_res = partition(s.substr(0, i));
					combine(sub_res, s.substr(i, s.size() - i));
					result.insert(result.end(), sub_res.begin(), sub_res.end());
				}
			}
			return result;
		}
};
*/

class Solution {
	public:
		bool palindrome(const string& s) {
			return s == string(s.rbegin(), s.rend());
		}

		void dfs(const string& s, vector<vector<string>>& result, vector<string>& curr) {
			if(s.empty()) {
				result.push_back(curr);
				return;
			}

			for(int i = 1 ; i <= s.size(); ++i) {
				if(palindrome(s.substr(0, i))) {
					curr.push_back(s.substr(0, i));
					dfs(s.substr(i, s.size() - i), result, curr);
					curr.pop_back();
				}
			}
			return;
		}

		vector<vector<string>> partition(string s) {
			vector<vector<string>> result;
			vector<string> curr;
			dfs(s, result, curr);
			return result;
		}
};

int main() {}
