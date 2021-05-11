#include<iostream>
#include <sstream>
using namespace std;

template <class T>
class Node{
	T value; //contenuto di ogni nodo
	Node<T>* next; //puntatore al prossimo nodo

	public:
		Node(T value, Node<T>* next) : value(value), next(next){}
		Node(T value) : Node(value, NULL){}
		Node() : Node(0, NULL){}

		Node<T>* getNext(){ 
			return this->next;
		}
		T getValue(){
			return this->value;
		}
		void setNext(Node<T>* next){
			this->next = next;
			return;
		}
		void setValue(T value){
			this->value = value;
		}
		string toString(){
			stringstream ss;
			ss << "Node value = " << value << ", next = " << next;
			return ss.str();
		}
		friend ostream& operator<<(ostream& stream, Node<T> node){
			stream << "Node value = " << node.getValue() << ", next = " << node.getNext();
			return stream;
		}
};

template <class T>
class List{
	Node<T>* head;
	int length;

	public:
		List(Node<T>* head) : head(head){}
		List() : List(NULL){}

		void add(T value){ //Metodo alternativo
			Node<T>* newNode = new Node<T>(value); //da fare cosi per una questione di ciclo di vita nello scope
			add(newNode);
			return;
		}
		void add(Node<T>* newNode){
			//Per inserire in coda bisogna scorrere tutta la lista e andare ad inserire alla fine il nodo
			if(head == NULL){ //Se la lista è vuota allora head è uguale al nodo che voglio inserire
				head = newNode;
				length++;
				return;
			}
			else{
				Node<T>* current = head;
				while(current->getNext() != NULL){ 
					current = current->getNext();
				}
				//una volta finito il cilco mi trovo sull'ultimo nodo, posso quindi assegnare il nuovo valore
				current->setNext(newNode);
				length++;
				return;
			}
		}
		/*void remove(){

		}*/
		bool search(T value){
			Node<T>* current = head;
			while(current->getNext() != NULL){ 
				if(current->getValue() == value) return true;
				current = current->getNext();
			}
			return false;
		}
		friend ostream& operator<<(ostream& stream, const List<T>& list){
			Node<T>* current = list.head;
			while(current != NULL){
				stream << *current << endl;
				current = current->getNext();
			}
			return stream;
		}
};

int main(){
	Node<int> n0 = Node<int>(10);
	Node<int> n1 = Node<int>(15);
	Node<int> n2 = Node<int>(20);

	List<int> list;
	list.add(&n0);
	list.add(&n1);
	list.add(&n2);
	list.add(50);
	cout << list << endl;

	cout << list.search(50) << endl;

	return 0;
}