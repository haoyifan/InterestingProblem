#include <iostream>

using namespace std;

class Component {
	public:
		Component();

		Component(Component& _c);
		Component& operator=(Component& _c);

		Component(Component&& _c);
		Component& operator=(Component&& _c);

		virtual ~Component() = default;

};

Component::Component() {
	cout << "default constructor" << endl;
}

Component::Component(Component& _c) {
	cout << "copy constructor" << endl;
}

Component& Component::operator=(Component& _c) {
	cout << "copy assignment" << endl;
	return *this;
}

Component::Component(Component&& _c) {
	cout << "move constructor" << endl;
}

Component& Component::operator=(Component&& _c) {
	cout << "move assignment" << endl;
	return *this;
}

// NOTE: might perform copy elision
auto maker() {
	Component c;
	return c;
}

auto move_maker() {
	Component c;
	return std::move(c);
}

/*
 * Might output:
 * default constructor
 * default constructor
 * move constructor
 * If so, copy elision happens
 */
int main() {
	auto c1 = maker();
	auto c2 = move_maker();
	return 0;
}
