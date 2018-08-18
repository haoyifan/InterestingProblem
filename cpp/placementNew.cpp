#include <new>
#include <cstring>
class T {
	private:
		int val[1024];

	public:
		T() {memset(val, 1, sizeof(val));};
};
int main() {
	int a;
	new(&a) T;
}
