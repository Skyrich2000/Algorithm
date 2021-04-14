#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
	T data; 
	Node<T>* link;

	Node() : link(nullptr) { }

	Node(T _data, Node<T>* _link) : data(_data), link(_link) { }

	~Node() { delete link; }
};

template <typename T>
class List {
private:
	Node<T>* head;

public:
	List() { head = new Node<T>(); }

	void push(T data) {
		Node<T>* ptr = new Node<T>(data, head->link);
		head->link = ptr;
		size++;
	}

	void pop() {
		if (!empty()) {
			Node<T>* ptr = head->link;
			head->link = head->link->link;
			ptr->link = nullptr;
			delete ptr;
		}
	}

	bool empty() { return head->link == nullptr; }

	~List() { delete head; }

	template <typename K>
	friend ostream& operator<<(ostream& os, List<K>& self);
};

template <typename T>
ostream& operator<<(ostream& os, List<T>& self) {
	Node<T>* p = self.head;
	cout << "[";
	while(p->link != nullptr) {
		p = p->link;
		cout << p->data << " ";
	}
	cout << "]";
	return os;
}

int main() {
	List<int> l;
    l.push(1); cout << l << endl;
    l.push(2); cout << l << endl;
    l.push(3); cout << l << endl;
    l.push(4); cout << l << endl;
    l.push(5); cout << l << endl;
    l.pop(); cout << l << endl;
    l.pop(); cout << l << endl;
    l.pop(); cout << l << endl;
    l.push(9); cout << l << endl;
    l.pop(); cout << l << endl;
    l.push(10); cout << l << endl;
	return 0;
}