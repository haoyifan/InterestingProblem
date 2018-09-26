#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
#include <limits>
using namespace std;

class Solution {
	public:
		string minWindow(string S, string T) {
			unordered_map<char, int> charCnt;
			unsigned min_len = -1;
			string result;
			int cnt = 0;
			int left = -1;
			bool flag = false;
			queue<int> q;
			for(auto c : T)
				charCnt[c]++;
			
			for(int right = 0; right < S.size(); ++right) {
				if(charCnt.find(S[right]) != charCnt.end()) {
					q.push(right);
					if(charCnt[S[right]] > 0)
						cnt++;
					charCnt[S[right]]--;

					if(left == -1) left = right;

					if(cnt == T.size()) {
						while(charCnt[S[q.front()]] < 0) {
							charCnt[S[q.front()]]++;
							q.pop();
							left = q.front();
						}	

						if(flag == false || right - left + 1 < min_len) {
							flag = true;
							min_len = right - left + 1;
							result = S.substr(left, min_len);
						}
					}
				}	
			}
			return result;
		}
};

int main() {
	string S = "ADOBECODEBANC";
	string T = "ABC";
	cout << Solution().minWindow(S, T);
}
