#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	
	Node() {
		data = -1;
		next = nullptr;
	}
	
	Node(int _data) {
		data = _data;
		next = nullptr;
	}
};

struct linkedList {
	Node* head;
	
	linkedList() {
		head = nullptr;
	}
	
	void print() {
		Node* it = head;
		while(it != nullptr) {
			cout << it->data << ' ';
			it = it->next;
		}
		cout << endl;
	}
	
	void insert(int _data) {
		if(head == nullptr) head = new Node(_data);
		else {
			Node* temp = new Node(_data);
			if(_data <= head->data) {
				temp->next = head;
				head = temp;
			}
			else {
				Node* it = head;
				while(it->next != nullptr) {
					if(_data > it->next->data) it = it->next;
					else break;
				}
				if(it->next == nullptr) it->next = temp;
				else {
					temp->next = it->next;
					it->next = temp;	
				}
			}
		}
	}
	
	void remove(int pos) {
		if(pos == 0) head = head->next;
		else {
			int cur = 0;
			Node* it = head;
			while(cur < pos - 1) {
				cur++;
				it = it->next;
			}
			it->next = it->next->next;
		}
	}
	
	linkedList merge(linkedList other) {
		linkedList ans;
		Node* it1 = head;
		Node* it2 = other.head;
		while(it1 != nullptr) {
			ans.insert(it1->data);
			it1 = it1->next;
		}
		while(it2 != nullptr) {
			ans.insert(it2->data);
			it2 = it2->next;
		}
		return ans;
	}
};

linkedList llist[2];

int main() {
	int temp;
    freopen("test3.txt", "r", stdin);

	while(cin >> temp) {
		if(temp == -1) break;
		llist[1].insert(temp);
	}
	while(cin >> temp) {
		if(temp == -1) break;
		llist[2].insert(temp);
	}
	string tmp;
	int id, dt;
	while(cin >> tmp) {
		if(tmp == "print") {
			cin >> id;
			llist[id].print();
		}
		else if(tmp == "insert") {
			cin >> id >> dt;
			llist[id].insert(dt);
		}
		else if(tmp == "remove") {
			cin >> id >> dt;
			llist[id].remove(dt);
		}
		else if(tmp == "merge") {
			linkedList TEMP = llist[1].merge(llist[2]);
			TEMP.print();
		}
	}
	return 0;
}
