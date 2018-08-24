// compile with -std=c++14 option

#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

// Correct solution but LTE
class Solution {
	private:

		unordered_map<string, vector<string>> m;

		bool diffByOne(const string& a, const string& b) {
			int cnt = 0;
			for(size_t i = 0; i < a.size(); ++i) {
				if(a[i] != b[i]) cnt++;
			}
			return cnt == 1;
		}

		void construct_neighbor(const string& start, vector<string> v) {

			v.push_back(start);

			for(auto& s1 : v) {
				for(auto& s2 : v) {
					if(s1 == s2) continue;

					if(diffByOne(s1, s2)) {
						m[s1].push_back(s2);
					}
				}
			}

			return;
		}

		void dfs(vector<vector<string>>& result, vector<string>& curr, unordered_set<string>& visited, const string& end,
				const vector<string>& v) {
			if(curr.back() == end) {
				result.push_back(curr);
				return;
			}
			for(auto& s : v) {
				if(visited.find(s) != visited.end()) continue;
				if(diffByOne(curr.back(), s)) {
					curr.push_back(s);
					visited.insert(s);

					dfs(result, curr, visited, end, v);

					visited.erase(s);
					curr.pop_back();
				}
			}
		}

	public:
		vector<vector<string>> findLadders(string start, string end, vector<string> &dict) {
			construct_neighbor(start, dict);
			vector<vector<string>> result;
			vector<string> curr;
			unordered_set<string> visited;

			curr.push_back(start);
			visited.insert(start);

			dfs(result, curr, visited, end, dict);
			int size = std::numeric_limits<int>::max();
			for(auto& v: result)
				if(v.size() < size)
					size = v.size();

			result.erase(remove_if(result.begin(), result.end(), [&](auto& v) {return v.size() != size;}), result.end());

			return result;
		}
};

int main() {
	string start = "hit";
	string end = "cog";
	vector<string> s{"hot","dot","dog","lot","log","cog"};
	auto res = Solution().findLadders(start, end, s);
	for(auto& v : res) {
		for(auto& x : v)
			cout << x << " ";
		cout << endl;
	}
}
