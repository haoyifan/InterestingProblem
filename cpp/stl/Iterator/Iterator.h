#ifndef __ROOKIE_ITERATOR__
#define __ROOKIE_ITERATOR__

namespace rookieiterator {
	template<class T>
		class RookieList;
	template<class T>
		class RookieNode;
	template<class Item>
		class RookieIterator;
}

namespace rookieiterator {
	template<class T>
	class RookieList {
		private:
			RookieNode<T>* _head;
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
					RookieNode<T>* prev = nullptr;

					while(other_curr != nullptr) {
						RookieNode<T>* curr = new RookieNode<T>(other_curr->val);
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

			RookieIterator<RookieNode<T>> begin() {
				return RookieIterator<RookieNode<T>>(_head);
			}		

			RookieIterator<RookieNode<T>> end() {
				return RookieIterator<RookieNode<T>>();
			}		

			virtual RookieList& insert_front(const T& val) {
				auto node = new RookieNode<T>(val);
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

	template<class Item>
	class RookieIterator {
		private:
			Item* pItem;

		public:

			RookieIterator(Item *p = nullptr) : pItem(p) {}; 

			RookieIterator& operator++() {
				pItem = pItem->next();
				return *this;
			}

			RookieIterator operator++(int) {
				RookieIterator tmp = *this;
				++*this;
				return tmp;
			}

			Item& operator*() const {
				return *pItem;
			}

			Item* operator->() const {
				return pItem;
			}

			bool operator==(const RookieIterator& other) const {
				return pItem == other->pItem;
			}

			bool operator!=(const RookieIterator& other) const {
				return pItem != other.pItem;
			}
	};
}

#endif
