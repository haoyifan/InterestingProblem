/**
 * A rookie impl of stl allocator from __Annotated STL__
 */

#ifndef __ROOKIE_ALLOCATOR__
#define __ROOKIE_ALLOCATOR__

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <limits>
#include <iostream>

namespace rookiealloc{
	template<typename T>
	static inline T* _allocate(size_t size, T*) {
		set_new_handler(nullptr);	
		T* tmp = (T*)(::operator new((size_t)size * sizeof(T)));
		if(tmp == nullptr) {
			throw "out of memory";	
		}
		return tmp;
	}

	template<typename T>
	static inline void _deallocate(T* ptr) {
		::operator delete(ptr);
	}

	template<typename T1, typename T2>
	static inline void _construct(T1* p, const T2& other) {
		new(p) T1(other);
	}

	template<typename T1>
	static inline void _destroy(T1* p) {
		p->~T1();
	}

	template<typename T>
	class RookieAlloc {
		public:
			typedef T value_type;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef T& reference;
			typedef const T& const_reference;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;

			template<typename U>
			struct rebind {
				typedef RookieAlloc<U> other;	
			};

			pointer allocate(size_type size, const void* hint = nullptr) {
				return _allocate(size, (pointer)nullptr);
			}

			void deallocate(pointer p, size_type n) {
				_deallocate(p);
			}

			void construct(pointer p, const T& other) {
				_construct(p, other);
			}

			void destroy(pointer p) {
				_destroy(p);
			}

			pointer address(reference obj) {
				return (pointer)&obj;	
			}

			const_pointer address(const_reference obj) {
				return (const_pointer)&obj;	
			}

			size_type max_size() const {
				return (size_type)(std::numeric_limits<unsigned>::max() / sizeof(T));	
			}
	};
}

#endif // __ROOKIE_ALLOCATOR__


