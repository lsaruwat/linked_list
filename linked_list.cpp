#include <iostream>
#include <string>


using namespace std;


class Node{
	public:
		string name;
		int age;
		Node *next;

	Node(){
		this->name = "";
		this->age = 0;
		this->next = NULL;
	}


	Node(string _name, int _age){
		this->name = _name;
		this->age = _age;
		this->next = NULL;
	}
};

class LinkedList{
	public:
		Node head;
		Node tail;

		LinkedList(){
			this->head = Node();
			this->tail = Node();

			this->head.next = &tail;
		}

		void insertNode(Node *newNode){
			Node *current;
			Node *previous;
			
			current = &this->head;
			while(current->next != NULL && newNode->name >= current->name){
				previous = current;
				current = current->next;
			}

			previous->next = newNode;
			newNode->next = current;

		}

		void deleteNode(Node *markedNode){
			Node *current;
			Node *previous;

			previous = &this->head;
			current = this->head.next;
			while(current->next != NULL && markedNode->name != current->name && markedNode->age != current->age){
				previous = current;
				current = current->next;
			}
			if(current->next)previous->next = current->next;
			

		}

		void printList(){
			Node *current = this->head.next;
			while(current->next != NULL){
				cout << current->name << " " << current->age << endl;
				current = current->next;
			}

			cout << "*---end---*" << endl;
		}
};


int main(int argc, char *argv[]){
	LinkedList l = LinkedList();
	
	Node logan = Node("Logan", 27);
	Node frank = Node("Frank", 40);
	Node john = Node("John", 21);
	Node rick = Node("Rick", 22);
	Node james = Node("James", 20);
	Node dave = Node("Dave", 28);
	Node rogue = Node("Rogue", 45);

	l.insertNode(&logan);
	l.insertNode(&frank);
	l.insertNode(&john);
	l.insertNode(&rick);
	l.insertNode(&james);
	l.insertNode(&dave);

	l.printList();

	l.deleteNode(&john);
	l.deleteNode(&rick);

	l.printList();

	l.deleteNode(&rogue);

	l.printList();


	return 0;
}