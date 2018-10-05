class Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            if(matrix.size() == 0 || matrix[0].size() == 0) return false;
            pair<int, int> ind = {0, matrix[0].size() - 1};
            while(ind.first < matrix.size() && ind.second >= 0) {
                if(matrix[ind.first][ind.second] == target)
                    return true;
                else if (matrix[ind.first][ind.second] < target)
                    ind = {ind.first + 1, ind.second};
                else
                    ind = {ind.first, ind.second - 1};
            }
            return false;
        }
};

int main() {}
