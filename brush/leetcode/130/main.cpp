#include <vector>
#include <iostream>
using namespace std;
class Solution {
	public:

		void markStar(vector<vector<char>>& board, int i, int j) {
			board[i][j] = '*';

			if(i - 1 >= 0 && board[i - 1][j] == 'O') markStar(board, i - 1, j);
			if(i + 1 < (int)board.size() && board[i +1][j] == 'O') markStar(board, i + 1, j);
			if(j - 1 >= 0 && board[i][j - 1] == 'O') markStar(board, i, j - 1);
			if(j + 1 < (int)board[0].size() && board[i][j + 1] == 'O') markStar(board, i, j + 1);

			return;
		}

		void solve(vector<vector<char>> &board) {
			if(board.size() == 0) return;

            for(int i = 0; i < board.size(); ++i) {
                int inc;
                if(i == 0 || i == board.size() - 1) {
                    inc = 1;
                } else {
                    inc = board[0].size() - 1;
                }
                for(int j = 0; j < board[0].size(); j += inc) {
                    if(board[i][j] == 'O')
                        markStar(board, i, j);
                }
            }
            
            for(int i = 0; i < board.size(); ++i) {
                for(int j = 0; j < board[0].size(); ++j) {
                    if(board[i][j] == '*') board[i][j] = 'O';
                    else board[i][j] = 'X';
                }
            }

			return;
		}
};

int main() {
	// vector<vector<char>> v{{'X', 'X', 'X', 'X', 'O'},
	// 						{'X', 'O', 'O', 'X', 'X'},
	// 						{'X', 'X', 'O', 'X', 'O'},
	// 						{'X', 'O', 'X', 'X', 'X'}};
	vector<vector<char>> v{{'O', 'O'},
							{'O', 'O'}};
	Solution s;
	s.solve(v);

	for(auto& vis : v) {
		for(auto val : vis) {
			cout << val << " "; 
		}
		cout << endl;
	}
}
