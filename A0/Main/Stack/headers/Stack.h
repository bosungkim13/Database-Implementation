
#ifndef STACK_H
#define STACK_H

// this is the node class used to build up the LIFO stack
template <class Data>
class Node {

private:

	Data holdMe;
	Node *next;
	
public:
	Node (Data data) : holdMe(data), next(nullptr) {}
	Data getData () { return holdMe; }
	Node* getNext () { return next; }
	void setNext (Node* node) { next = node;}

};

// a simple LIFO stack
template <class Data> 
class Stack {

	Node <Data> *head;

public:

	// destroys the stack
	~Stack () { 
		Node <Data> *current = head;
		while (current != nullptr) {
			Node <Data> *next = current->getNext();
			delete current;
			current = next;
		}
	}

	// creates an empty stack
	Stack () {
		head = nullptr;
	}

	// adds pushMe to the top of the stack
	void push (Data data) {
		Node <Data> *newNode = new Node <Data> (data);
		newNode->setNext(head);
		head = newNode;
	}

	// return true if there are not any items in the stack
	bool isEmpty () {
		return head == nullptr;
	}

	// pops the item on the top of the stack off, returning it...
	// if the stack is empty, the behavior is undefined
	Data pop () { 
		if (isEmpty()) {
			throw std::runtime_error("Stack is empty");
		}
		Node <Data> *temp = head;
		head = head->getNext();
		Data data = temp->getData();
		delete temp;
		return data;
	}
};

#endif
