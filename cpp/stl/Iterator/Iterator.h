#ifndef __ROOKIE_ITERATOR__
#define __ROOKIE_ITERATOR__

#include <algorithm>
#include <iostream>
#include <ostream>
#include <cstddef>
#include <iterator>

namespace rookieiterator {
	template<class T>
		class RookieList;
}

namespace rookieiterator {
	template<class T>
	class RookieList {
			class RookieNode {
				friend class RookieList<T>;

				private:
					T val;
					RookieNode* _next;

				public:
					RookieNode() : _next(nullptr) {};

					explicit RookieNode(const T& _val) : val(_val), _next(nullptr) {}; 

					virtual ~RookieNode() = default;

					T& value() { return val; }

					RookieNode* next() const { return _next; }
			};

			class Iterator {

				typedef T value_type;
				typedef typename std::forward_iterator_tag iterator_category;
				typedef typename std::ptrdiff_t difference_type;
				typedef T* pointer;
				typedef T& reference;

				private:
					RookieNode* _p;

				public:

					explicit Iterator(RookieNode *p = nullptr) : _p(p) {}; 

					Iterator& operator++() {
						_p= _p->next();
						return *this;
					}

					Iterator operator++(int) {
						Iterator tmp = *this;
						++*this;
						return tmp;
					}

					T& operator*() {
						return _p->value();
					}

					T* operator->() {
						return &_p->value();
					}

					bool operator==(const Iterator& other) const {
						return _p == other._p;
					}

					bool operator!=(const Iterator& other) const {
						return _p != other._p;
					}
			};

		private:
			RookieNode* _head;
			unsigned long _size;

		public:
			RookieList() : _head(nullptr), _size(0) {};

			RookieList(const RookieList& other) {
				*this = other;
			}

			RookieList& operator=(const RookieList& other) {
				if(this != &other) {
					_size = other._size;
					auto other_curr = other->_head;	
					RookieNode* prev = nullptr;

					while(other_curr != nullptr) {
						RookieNode* curr = new RookieNode(other_curr->val);
						if(prev != nullptr) {
							prev->_next = curr;	
						}
						prev = curr;
						other_curr = other_curr->_next;
					}
				}
				return *this;
			};

			virtual ~RookieList() {
				auto curr = _head;
				while(curr != nullptr) {
					auto next = curr->_next;
					delete curr;
					curr = next;
				}
				return;
			}

			RookieNode* head() { return _head; };

			Iterator begin() {
				return Iterator(_head);
			}		

			Iterator end() {
				return Iterator();
			}		

			virtual RookieList& insert_front(const T& val) {
				auto node = new RookieNode(val);
				node->_next = _head;
				_head = node;
				_size++;
				return *this;
			}

			virtual void pop_front() {
				if(_head == nullptr)
					throw "pop an empty list";

				auto victim = _head;
				_head = _head->_next;
				delete victim;
				_size--;
				return;
			}

			virtual T& front() {
				if(_head == nullptr)
					throw "peek an empty list";

				return _head->value();
			}

			virtual unsigned long size() { return _size; }

	};

	template<class T>
	class RookieVector {
		private:
			static const unsigned INIT_CAP = 16;
		private:
			T* _arr;
			unsigned long _size;
			unsigned long _capacity;
			static std::ostream& _os;

		public:
			RookieVector() : _arr(new T[INIT_CAP]), _size(0), _capacity(INIT_CAP) {}	

			RookieVector(const RookieVector& other) { *this = other; }	

			RookieVector& operator=(const RookieVector& other) {
				if(this != &other) {
					_size = other._size;
					_capacity = other._capacity;
					if(_size < other._size) {
						delete[] _arr;	
						_arr = new T[other._capacity];
						_capacity = other._capacity;
					}

					for(auto i = 0; i < _size; ++i) {
						_arr[i] = other._arr[i];	
					}	
				}	
				return *this;
			}

			RookieVector(RookieVector&& other) { *this = other; }
			
			RookieVector& operator=(RookieVector&& other) {
				if(this != &other) {
					delete[] _arr;
					_arr = other._arr;
					_size = other._size;
					_capacity = other._capacity;
					other._arr = nullptr;
					other._arr = 0;
				}
				return *this;
			}

			unsigned long size() const { return _size; }

			unsigned long capacity() const { return _capacity; }

			// NOTE: not consider exception safety
			RookieVector& push_back(const T& val) {
				_os << "push back " << val << std::endl;
				if(_size == _capacity) {
					_capacity *= 2;
					T* new_arr = new T[_capacity];	
					std::copy(_arr, _arr + _size, new_arr);
					delete[] _arr;
					_arr = new_arr;
				}
				_arr[_size++] = val;
				return *this;
			}

			RookieVector& pop_back() {
				if(_size == 0) {
					throw "pop an empty vector";
				}
				_os << "pop back " << *(--end())<< std::endl;
				erase(--end());
				return *this;
			}

			RookieVector& pop_front() {
				if(_size == 0) {
					throw "pop an empty vector";
				}
				_os << "pop front " << *(begin())<< std::endl;
				erase(begin());
				return *this;
			}

			T& back() {
				if(_size == 0) {
					throw "pop an empty vector";
				}
				return _arr[_size - 1];
			}

			void show(std::ostream& os = std::cout) const {
				for(unsigned long i = 0; i < _size; ++i)
					os << _arr[i] << " ";
				os << std::endl;
			}

			class Iterator {
				friend class RookieVector;

				typedef T value_type;
				typedef typename std::random_access_iterator_tag iterator_category;
				typedef typename std::ptrdiff_t difference_type;
				typedef T* pointer;
				typedef T& reference;

				private:
					T* _p;	

					explicit Iterator(T* ptr) : _p(ptr) {}
				public:
					Iterator() : _p(nullptr) {}

					Iterator(const Iterator& other) : _p(other._p) {}

					T& operator*() {
						return *_p;	
					}

					T* operator->() {
						return _p;	
					}

					Iterator& operator++() {
						_p++;
						return *this;
					}

					Iterator operator++(int) {
						auto tmp = *this;
						_p++;
						return tmp;
					}

					Iterator& operator--() {
						_p--;
						return *this;
					}

					Iterator operator--(int) {
						auto tmp = *this;
						_p--;
						return tmp;
					}

					bool operator==(Iterator other) {
						return _p == other._p;
					}

					bool operator!=(Iterator other) {
						return _p != other._p;
					}
			};

			Iterator begin() { return Iterator(_arr); }
			Iterator end() { return Iterator(_arr + _size); }

			RookieVector& erase(const Iterator& iter) {
				auto curr = begin();

				while(curr != iter && curr != end()) {
					++curr;
				}

				if(curr == end())
					throw "cannot erase element of that iterator";

				_os << "erase " << *curr._p << std::endl;

				for(auto i = curr._p + 1; i < _arr + _size; ++i) {
					*(i - 1) = *i;	
				}
				_size--;
				
				return *this;
			}

	};

	template<class T>
	std::ostream& RookieVector<T>::_os = std::cout;

	template<class I>
	struct iterator_traits {
		typedef typename I::iterator_category iterator_category;
		typedef typename I::value_type value_type;
		typedef typename I::difference_type difference_type;
		typedef typename I::pointer pointer;
		typedef typename I::reference reference;
	};

	template<class I>
	struct iterator_traits<I*> {
		typedef I value_type;
		typedef std::random_access_iterator_tag iterator_category;
		typedef std::ptrdiff_t difference_type;
		typedef I* pointer;
		typedef I& reference;
	};

	template<class I>
	struct iterator_traits<const I*> {
		typedef I value_type;
		typedef std::random_access_iterator_tag iterator_category;
		typedef std::ptrdiff_t difference_type;
		typedef const I* pointer;
		typedef const I& reference;
	};
}

#endif
