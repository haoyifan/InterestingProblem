#include <iostream>

using namespace std;
class Base {
    public:
        Base() {cout << "base default ctor " << endl;};
        Base(int i) : i_(i){cout << "base int i ctor " << i << endl;};
        virtual ~Base() {cout << "base dtor" << endl;};
        Base* clone() {return new Base(*this);};

    private:
        int i_;
};

class D1 : public virtual Base {
    public:
        D1() {cout << "D1 default ctor " << endl;};
        D1(int i) : Base(i){cout << "D1 int i ctor " << i << endl;};
        virtual ~D1() {cout << "D1 dtor" << endl;};
        D1* clone() {return new D1(*this);};
};

class D2 : public virtual Base {
    public:
        D2() {cout << "D2 default ctor " << endl;};
        D2(int i) : Base(i){cout << "D2 int i ctor " << i << endl;};
        virtual ~D2() {cout << "D2 dtor" << endl;};
        D2* clone() {return new D2(*this);};
};

class D : public D1, public D2 {
    public:
        D() {cout << "D default ctor " << endl;};
        // only default Base ctor is called. C++ standard enforces most derived
        // class do virtual base class initialization via default ctor.
        D(int i) : D1(2), D2(3) {cout << "D int i ctor " << i << endl;};
        virtual ~D() {cout << "D dtor" << endl;};
        D* clone() {return new D(*this);};
};

int main() {
    D(2);
}
