#include <vector>
using namespace std;

class Solution {
    public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        bool obstacle = false;
        for(int i = 0; i < obstacleGrid.size(); ++i) {
            if(obstacleGrid[i][0] || obstacle) {
                obstacle = true;
                dp[i][0] = 0;
            } else {
                dp[i][0] = 1;
            }
        }
        obstacle = false;
        for(int i = 0; i < obstacleGrid[0].size(); ++i) {
            if(obstacleGrid[0][i] || obstacle) {
                obstacle = true;
                dp[0][i] = 0;
            } else {
                dp[0][i] = 1;
            }
        }
        for(int i = 1 ; i < obstacleGrid.size(); ++i)
            for(int j = 1; j < obstacleGrid[0].size(); ++j) {
                if(!obstacleGrid[i-1][j]) dp[i][j] += dp[i-1][j];
                if(!obstacleGrid[i][j-1]) dp[i][j] += dp[i][j-1];
                if(obstacleGrid[i][j]) dp[i][j] = 0;
            }
        return dp.back().back();

    }
};

int main() {}
