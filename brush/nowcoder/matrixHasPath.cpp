#include <iostream>
#include <cstring>

using namespace std;

class Solution {
	public:
		bool match(char* matrix, int rows, int cols, char* str, int curr_row, int curr_col, int str_idx) {
			if(str_idx >= strlen(str))
				return true;
			if(curr_row < 0 || curr_col < 0 || curr_row >= rows || curr_col >= cols)
				return false;
			char tmp = *(matrix + curr_col + curr_row * cols);
			if(*(matrix + curr_col + curr_row * cols) == str[str_idx]) {
				*(matrix + curr_col + curr_row * cols) = '#';
				bool result =  match(matrix, rows, cols, str, curr_row + 1, curr_col, str_idx + 1) ||
					match(matrix, rows, cols, str, curr_row, curr_col + 1, str_idx + 1) ||
					match(matrix, rows, cols, str, curr_row - 1, curr_col, str_idx + 1) ||
					match(matrix, rows, cols, str, curr_row, curr_col - 1, str_idx + 1);
				*(matrix + curr_col + curr_row * cols) = tmp;
				if(result)
					return true;
			}

			return false;
		}

		bool hasPath(char* matrix, int rows, int cols, char* str)
		{
			if(str == nullptr) return false;
			for(int i = 0; i < rows; ++i) {
				for(int j = 0; j < cols; ++j) {
					if(*(matrix + j + i * cols) == str[0]) {
						bool result = match(matrix, rows, cols, str, i, j, 0);
						if(result == true)
							return true;
					}
				}
			}

			return false;
		}
};

int main() {
	Solution s;
	char matrix[] = "ABCESFCSADEE";
	char str[] = "ABCCED";
	cout << s.hasPath(matrix,3,4,str);
	return 0;
}

