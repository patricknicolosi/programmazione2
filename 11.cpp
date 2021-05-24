#include <iostream>
using namespace std;

template <class T>
class NodeDL{
	NodeDL* prev;
	NodeDL* next;
	T value;

	public:	
		NodeDL(NodeDL* prev, NodeDL* next, T value) : prev(prev), next(next), value(value){}
		NodeDL(T value) : NodeDL(NULL, NULL, value){}
		NodeDL* getNext() const{
			return this->next;
		}
		NodeDL* getPrev() const{
			return this->prev;
		}
		T getValue() const{
			return this->value;
		}
		void setValue(T value){
			this->value = value;
			return;
		}
		void setPrev(NodeDL<T>* newNode){
			this->prev = newNode;
			return;
		}
		void setNext(NodeDL<T>* newNode){
			this->prev = newNode;
			return;
		}
		friend ostream& operator << (ostream& stream, const NodeDL& node){
			stream << "prev = " << node->getPrev() << ", next = " << node->getNext() << ", value = " << node->getValue();
			return stream;
		}
		bool operator < (NodeDL& node){
			if(node->getValue() < this->value) return true;
			return false;
		}
		bool operator <= (NodeDL& node){
			if(node->getValue() <= this->value) return true;
			return false;
		}
		bool operator > (NodeDL& node){
			if(node->getValue() > this->value) return true;
			return false;
		}
		bool operator >= (NodeDL& node){
			if(node->getValue() >= this->value) return true;
			return false;
		}
};

template <class T>
class ListDL{
	NodeDL<T>* head;
	NodeDL<T>* tail;
	int length;

	public:
		ListDL(NodeDL<T>* head, NodeDL<T>* tail, int length) : head(head), tail(tail), length(length){}
		ListDL() : ListDL(NULL, NULL, 0){}
		void add(NodeDL<T>* newNode){
			if(head == NULL){
				head = newNode;
				return;
			}
			
			return;
		}
		friend ostream& operator << (ostream& stream, const ListDL& list){
			stream << "Stampo la lista";
			return stream;
		}
};


int main(){
	ListDL<int> list;
	cout << list << endl;
	return 0;
}