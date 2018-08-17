#include <vector>

class Solution {
	public:
		bool satisfy(int threshold, int rows, int cols) {
			int sum = 0;
			while(rows) {
				sum += rows % 10;
				rows /= 10;
			}
			while(cols) {
				sum += cols % 10;
				cols /= 10;
			}
			if(sum <= threshold)
				return true;
			else
				return false;
		}

		void move(int threshold, int rows, int cols, int row, int col, int& result, vector<vector<bool>>& miniMap) {
			if(!satisfy(threshold, row, col) || row < 0 || col < 0 || row >= rows || col >= cols || miniMap[row][col] == false)
				return;

			result++;
			miniMap[row][col] = false;
			move(threshold, rows, cols, row+1, col, result, miniMap);
			move(threshold, rows, cols, row-1, col, result, miniMap);
			move(threshold, rows, cols, row, col+1, result, miniMap);
			move(threshold, rows, cols, row, col-1, result, miniMap);

			return;
		}

		int movingCount(int threshold, int rows, int cols)
		{
			int result = 0;
			vector<vector<bool>> miniMap(rows, vector<bool>(cols, true));
			move(threshold, rows, cols, 0, 0, result, miniMap);
			return result;
		}
};

int main() {}
