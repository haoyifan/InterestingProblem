#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
	public:
		bool diffByOne(const string& a, const string& b) {
			int diff = 0;
			for(int i = 0; i < (int)a.size(); ++i) {
				if(a[i] != b[i])
					diff++;
			}
			return diff == 1;
		}

		vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
			queue<string> q;
			q.push(start);
			unordered_map<string, vector<string>> m; // vector end with key
			m[start] = vector<string>({start});
			vector<vector<string>> result;

			while(!q.empty()) {
				int size = q.size();
				while(size-- > 0) {
					auto curr = q.front(); q.pop();
					if(diffByOne(curr, end)) {
						vector<string> newvec = m[curr];
						newvec.push_back(end);
						result.push_back(newvec);
						continue;
					}
					unordered_set<string> toDelete;
					for(auto& s : dict) {
						if(diffByOne(curr, s)) {
							toDelete.insert(s);
							vector<string> newvec = m[curr];
							newvec.push_back(s);
							m[s] = newvec;
							q.push(s);
						}
					}
					for(auto& s : toDelete)
						dict.erase(s);
				}
			}
			return result;
		}
};

int main() {}
