class Solution {
	public:
		void merge(int A[], int m, int B[], int n) {
			int k = m + n;
			m--;
			n--;
			k--;
			while(m >= 0 && n >= 0) {
				if(A[m] > B[n]) {
					A[k--] = A[m--];
				} else {
					A[k--] = B[n--];
				}
			}
			while(m >= 0) {
				A[k--] = A[m--];
			}
			while(n >= 0) {
				A[k--] = B[n--];
			}
			return;
		}
};

int main() {}
