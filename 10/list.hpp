#include "node.hpp"


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
		Node<T>* cancel(T value){
			if(this->search(value)){ //se il valore è presente nella lista
				if(head->getValue() == value){ //Se il valore è in testa
					Node<T>* tmp = head;
					head = head->getNext();
					return tmp;
				}
				else{ //Se il valore non è in testa
					Node<T>* prev = head;
					Node<T>* current = head->getNext();
					while(current != NULL){
						if(current->getValue() == value){
							prev->setNext(current->getNext());
							return current;
						}
						prev = current;
						current = current->getNext();
					}
				}
			}
			return NULL;
		}
		bool search(T value){
			if(head == NULL) return false;
			Node<T>* current = head;
			while(current != NULL){ 
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