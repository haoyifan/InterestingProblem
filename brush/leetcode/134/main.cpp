#include <vector>

using namespace std;

class Solution {
	public:
		/*
		 * start: start index
		 * end: next index that the car goes to
		 * sum: keeps the gas needed from start -> end
		 * Therefore, when start == end, sum keeps the total gas needed
		 * for the circuit.
		 */
		 /*
		int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
			int start = gas.size() - 1;
			int end = 0;
			int sum = gas[start] - cost[start];
			while(start > end) {
				if(sum < 0) {
					start--;
					sum += gas[start] - cost[start];
				} else {
					sum += gas[end] - cost[end];
					end++;
				}
			}

			return sum >= 0 ? start : -1;
		}
		*/

		/*
		 * Assume start with 0
		 * If curr < 0, that means we cannot go from res+1 to i+1
		 * so reset curr
		 */
		int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
			int res = -1;
			int sum = 0;
			int curr = 0;
			for(int i = 0; i < gas.size(); ++i) {
				sum += gas[i] - cost[i];
				curr += gas[i] - cost[i];
				if(curr < 0) {
					res = i;
					curr = 0;
				}
			}

			return sum >= 0 ?  res + 1 : -1;
		}
};

int main() {}
