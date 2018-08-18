class Solution {
	unordered_map<string, vector<string>> mem;

	void combine(const string& s, vector<string>& sub_res) {
		for(auto& str : sub_res) {
			str += " " + s;
		}
		return;
	}
	public:
	vector<string> wordBreak(const string& s, vector<string>& wordDict) {

		if(mem.find(s) != mem.end()) return mem[s];

		unordered_set<string> dict(wordDict.begin(), wordDict.end());

		vector<string> res;

		if(dict.find(s) != dict.end())
			res.push_back(s);

		for(int i = 1; i < s.size(); ++i) {
			string post = s.substr(i);
			string pre = s.substr(0, i);
			if(dict.find(post) != dict.end()) {
				auto sub_res = wordBreak(pre, wordDict);
				combine(post, sub_res);
				res.insert(res.end(), sub_res.begin(), sub_res.end());
			}
		}

		mem[s] = res;
		return res;

	}
};

int main() {}
