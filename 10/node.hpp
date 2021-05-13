#include <iostream>
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

