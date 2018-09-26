#include <iostream>
#include <new>

typedef void (*new_handler)();

class X {
    public:
        static new_handler set_new_handler(new_handler h);
        static void* operator new(size_t size);
        static void operator delete(void* p, size_t size);

    private:
        static new_handler currentHandler;

        int member;
};

new_handler X::currentHandler;

new_handler X::set_new_handler(new_handler h) {
    new_handler oldHandler = currentHandler;
    currentHandler = h;
    return oldHandler;
}

void* X::operator new(size_t size) {
    std::cout << "X's new operator being called" << std::endl;
    std::cout << "size " << size << std::endl;
    std::cout << "X's size " << sizeof(X) << std::endl;

    new_handler globalHandler = std::set_new_handler(currentHandler);

    void* memory;

    try {
        memory = ::operator new(size);
    } catch (std::bad_alloc) {
        std::set_new_handler(globalHandler);
        throw;
    }

    std::set_new_handler(globalHandler);

    return memory;
}

void X::operator delete(void* p, size_t size) {
    std::cout << "X's delete operator being called" << std::endl;
    std::cout << "size " << size << std::endl;
    std::cout << "X's size " << sizeof(X) << std::endl;

    ::operator delete(p);
}

int main() {
    X* x = new X;
    delete x;
}
