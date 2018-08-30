#include <vector>
#include <list>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <iterator>
#include <functional>

using namespace std;

inline
void print(int i) {
	cout << i << " ";
}

class Printer {
	public:
		explicit Printer(int i) : m(i) {};
		void print() const { cout << m <<  " ";};
	private:
		int m;
};

int main() {
	vector<int> v{1,2,3,4,5,6};

	ostream_iterator<int> ooi(std::cout, " ");
	cout << "Output to console with ostream iterator" << endl;
	std::copy(v.begin(), v.end(), ooi);
	cout << endl;

	cout << "Number of elements in v that are not greater than 4" << endl;
	cout << std::count_if(v.begin(), v.end(), std::not1(std::bind2nd(std::greater<int>(), 4)));
	cout << endl;

	cout << "Print to console with function pointer and ptr_fun adaptor" << endl;
	std::for_each(v.begin(), v.end(), print);
	cout << endl;
	std::for_each(v.begin(), v.end(), ptr_fun(print));
	cout << endl;

	cout << "Print to console with memeber function pointer and mem_fun_ref adaptor" << endl;
	vector<Printer> vp;
	vp.emplace_back(2);
	vp.emplace_back(3);
	vp.emplace_back(5);
	vp.emplace_back(9);
	std::for_each(vp.begin(), vp.end(), mem_fun_ref(&Printer::print));
	cout << endl;

	cout << "Reverse Iterator" << endl;
	std::for_each(reverse_iterator<vector<int>::iterator>(v.end()), reverse_iterator<vector<int>::iterator>(v.begin()), ptr_fun(print));
	cout << endl;
}
