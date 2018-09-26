#include "Allocator.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace rookiealloc;

int main() {
    int a;
	int arr[]{1,2,3,4,5};

	vector<int, RookieAlloc<int>> v(arr, arr+sizeof(arr) / sizeof(arr[0]));
    
    for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});
	return 0;
}
