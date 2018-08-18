// delete all the Nodes that have odd value in linked list
#include <iostream>

using namespace std;

typedef struct Node{
	int val;
	Node* next;
	Node(int _val) : val(_val), next(nullptr) {};
} Node;

/** A silly impl
Node* deleteOddNode(Node* head) {
	Node* result = nullptr;

	while(head != nullptr && head->val % 2 == 1) head = head->next;

	if(head != nullptr) result = head;
	else return nullptr;

	auto curr = result;

	while(curr->next != nullptr) {
		if(curr->next->val % 2 == 1) {
			curr->next = curr->next->next;	
		} else {
			curr = curr->next;	
		}
	}

	return result;
}
*/

Node* deleteOddNode(Node* head) {
	Node* result = nullptr;
	Node* prev = nullptr;

	while(head != nullptr) {
		if(head->val % 2 == 0) {
			if(result == nullptr)
				result = head;
			if(prev == nullptr)
				prev = head;
			else
				prev = prev->next;

			head = head->next;
		} else {
			if(prev != nullptr)
				prev->next = head->next;
			head = head->next;
		}
	}

	return result;
}

int main() {
	auto a = new Node(1);
	auto b = new Node(2);
	auto c = new Node(3);
	a->next = b;
	b->next = c;

	auto result = deleteOddNode(a);

	cout << "TEST 1" << endl;
	while(result != nullptr) {
		cout << result->val << " ";	
		result = result->next;
	}
	cout << endl;
	delete a, b, c;

	a = new Node(1);
	b = new Node(5);
	c = new Node(3);
	a->next = b;
	b->next = c;

	result = deleteOddNode(a);

	cout << "TEST 2" << endl;
	while(result != nullptr) {
		cout << result->val << " ";	
		result = result->next;
	}
	cout << endl;
	delete a, b, c;

	a = new Node(2);
	b = new Node(4);
	c = new Node(6);
	a->next = b;
	b->next = c;

	result = deleteOddNode(a);

	cout << "TEST 3" << endl;
	while(result != nullptr) {
		cout << result->val << " ";	
		result = result->next;
	}
	cout << endl;
	delete a, b, c;

	result = deleteOddNode(nullptr);

	cout << "TEST 4" << endl;
	while(result != nullptr) {
		cout << result->val << " ";	
		result = result->next;
	}
	cout << endl;
}

