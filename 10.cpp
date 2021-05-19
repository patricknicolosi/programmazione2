#include <iostream>
using namespace std;


class Punto{
    int x;
    int y;
    
    public:
        Punto(int x, int y){
            this->x = x;
            this->y = y;
        }
        friend bool operator <= (const Punto& p1, const Punto& p2){
            if(p1.x <= p2.x && p1.y <= p2.y) return true;
            return false;
        }
        friend bool operator >= (const Punto& p1, const Punto& p2){
            if(p1.x >= p2.x && p1.y >= p2.y) return true;
            return false;
        }
        friend bool operator == (const Punto& p1, const Punto& p2){
            if(p1.x == p2.x && p1.y == p2.y) return true;
            return false;
        }
        friend ostream& operator<< (ostream& stream, const Punto& Punto){
            stream << "(" << Punto.x << ";" << Punto.y << ")";
            return stream;
        }
};


template <class T>
class Node{
    Node* next;
    T value;
    
    public:
        Node(T value, Node<T> * next) : value(value), next(next) {}
        Node(T value) : Node(value, NULL) {}
        
        T getValue() const {
            return this->value;
        }
        Node* getNext() const{
            return this->next;
        }
        void setNext(Node* newNode){
            this->next = newNode;
            return;
        }
        friend ostream& operator<< (ostream& stream, const Node& node){
            stream << "Prossimo nodo =  " << node.next << ", di valore = " << node.getValue();
            return stream;
        }
};


template <class T>
class List{
    Node<T>* head;
    int length;
    
    public:
        List(){
            this->head = NULL;
            this->length = 0;
        }
        void add(T value){            
            Node<T> * temp = new Node<T>(value);
            this->add(temp);
        }
        void add(Node<T>* newNode){
            if(head == NULL){
                head = newNode;
                length++;
                return;
            }
            Node<T>* currentNode = head;
            while(currentNode->getNext() != NULL){
                currentNode = currentNode->getNext();
            }
            currentNode->setNext(newNode);
            length++;
            return;
        }
		void addInOrder(T value) {
			Node<T> * newNode = new Node<T>(value);
			if(head == NULL) {
				add(newNode);
				return;
			}
			if(head->getValue() > value){
				newNode->setNext(head);
				head = newNode;
				length++;
				return;
			}
			
			Node<T> * prevNode = head;
			Node<T>	* currentNode = head->getNext();

			while(currentNode != NULL) {
				if(prevNode->getValue() <= value && currentNode->getValue() > value) {
					prevNode->setNext(newNode);
					newNode->setNext(currentNode);
					length++;
					return;
				}
				else {
					prevNode = currentNode; 
					currentNode = currentNode->getNext();
				}
			}
			prevNode->setNext(newNode);
			length++;
			return;
		}

        bool search(T value){
            if(head == NULL) return false;
            Node<T>* currentNode = head;
            while(currentNode != NULL){
            	if(currentNode->getValue() == value){
            		return true;
            	}
            	currentNode = currentNode->getNext();
            }
            return false;
        }
        void remove(T value) {
            if(this->search(value)){
                if(head->getValue() == value) {
                    Node<T> * temp = head;
                    head = head->getNext();
                    length--;
                    return;
                }   
                Node<T> * prev = head;
                Node<T> * currentNode = head->getNext();
                while(currentNode != NULL){
                    if(currentNode->getValue() == value){
                        prev->setNext(currentNode->getNext());
                        length--;
                        return;
                    }
                    prev = currentNode;
                    currentNode = currentNode->getNext();
                }
            }
            return;
        }
        friend ostream& operator<< (ostream& stream, const List& list){
            Node<T>* currentNode = list.head;
            stream << "[  ";
            while(currentNode != NULL){
                stream << currentNode->getValue() << "  ";
                currentNode = currentNode->getNext();
            }
            stream << "]";
            return stream;
        }
};



int main(){     
    List<Punto> list;
    Punto punto = {12, 34};
    Punto punto2 = {12, -3};

    list.add(punto);
    list.add(punto2);

    cout << "Stato iniziale--> " << list << endl;

    list.remove(punto);

    cout << "Dopo rimozione--> " << list << endl;

    List<int> list2;

    cout << "Cerco in list2: " << list2.search(345) << endl;

    list2.addInOrder(4);
    list2.addInOrder(1);
    list2.addInOrder(10);
    list2.addInOrder(345);

    cout << "Cerco in list2: " << list2.search(345) << endl;
    cout << list2 << endl;
    
    return 0;
}
