#include <vector>
using namespace std;

class Solution {
	private:
		bool search(vector<vector<char>>& board, const string& word, int i, int j, int idx) {
			if(idx >= word.size()) return true;
			if(i < 0 || j < 0 || i >= (int)board.size() || j >= (int)board[0].size()) return false;

			if(board[i][j] == word[idx]) {
				auto c = board[i][j];
				board[i][j] = '*';

				auto res = search(board, word, i-1, j, idx+1) || search(board, word, i+1, j, idx+1) || 
					search(board, word, i, j+1, idx+1) || search(board, word, i, j-1, idx+1);

				board[i][j] = c;

				if(res) return true;
			}

			return false;
		}
	public:
		bool exist(vector<vector<char> > &board, string word) {
			if(word.size() == 0) return true;
			if(board.size() == 0 || board[0].size() == 0) return false;

			for(int i = 0; i < board.size(); ++i) {
				for(int j = 0; j < board[0].size(); ++j) {
					if(board[i][j] == word[0]) {
						if(search(board, word, i, j, 0)) return true;
					}
				}
			}

			return false;
		}
};

int main() {}
