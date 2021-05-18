#include <iostream>
using namespace std;


class Studente{
    string nome;
    string cognome;
    
    public:
        Studente(string nome, string cognome){
            this->nome = nome;
            this->cognome = cognome;
        }
        friend ostream& operator<< (ostream& stream, const Studente& studente){
            stream << studente.nome << ", " << studente.cognome;
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
    List<Studente> list;
    Studente studente = {"Patrick", "Nicolosi"};

    list.add(studente);

    cout << list << endl;
    
    return 0;
}
