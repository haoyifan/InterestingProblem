class Solution {
	public:
		int removeDuplicates(int A[], int n) {
			int next_insert_point = 0;
			int curr_idx = 0;
			while(curr_idx < n) {
				int times = 1;
				A[next_insert_point++] = A[curr_idx];
				auto val = A[curr_idx];
				while(++curr_idx < n && A[curr_idx] == val) {
					if(times++ < 2) A[next_insert_point++] = A[curr_idx];
				}
			}
			return next_insert_point;
		}
};

int main {}
