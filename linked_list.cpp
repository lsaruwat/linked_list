#include <iostream>
#include <string>


using namespace std;


class Person{
	public:
		string name;
		int age;
		Person *next;

	Person(){
		this->next =NULL;
	}


	Person(string _name, int _age){
		this->name = _name;
		this->age = _age;
	}

	Person(string _name, int _age, Person *_next){

	}
};

void insert(Person *newPerson, Person *head, Person *tail){
	Person *current;

	if(head->next == tail){
		head->next = newPerson;
		newPerson->next = tail;
	}
	else{
		current = head;
		Person *previous;
		while(current->next != NULL && newPerson->age >= current->age){
			previous = current;
			current = current->next;
		}

		previous->next = newPerson;
		newPerson->next = current;
	}

}

void printList(Person *head){
	Person *current = head->next;
	while(current->next != NULL){
		cout << current->name << " " << current->age << endl;
		current = current->next;
	}
}


int main(int argc, char *argv[]){
	Person head = Person();
	Person tail = Person();
	head.next = &tail;
	tail.next = NULL;
	
	Person logan = Person("Logan", 27);
	Person john = Person("John", 21);
	Person rick = Person("Rick", 22);
	Person james = Person("James", 20);
	Person dave = Person("Dave", 28);

	insert(&logan,&head,&tail);
	insert(&john,&head,&tail);
	insert(&rick,&head,&tail);
	insert(&james,&head,&tail);
	insert(&dave,&head,&tail);

	printList(&head);


	return 0;
}