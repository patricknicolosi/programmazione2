
/*

CODE (o QUEUE)
Una coda è un'organizzazione dati in cui il dato che arriva per primo viene servito
per primo (fila alle poste ad esempio).Questa caratteristica è comunemente detta "First in, First out" (FIFO).
->Quando inseriamo un elemento nella coda facciamo un operazione di ENQUEUE 
->Quando togliamo un elemento dalla coda facciamo un operazione di DEQUEUE

Le code possono essere implementate in varie modo, tra le alternative:
1) Array -> ENQUEUE avrà complessità O(1). DEQUEUE O(1) per l'estrazione e O(n) per lo shift successivo ce dovrà essereci per mantenere consistenza  
2) List -> ENQUEUE avraà complessità O(n) devo scorrere tutta la lista infatti. DEQUEUE O(1) perchè è l'estrazione della testa
3) ListDL -> ENQUEUE avrà complessità O(1) se ha tail, O(n) altrimenti. DEQUEUE O(1) per lo stesso motivo della List

In base alla struttura dati che scegliamo per implementare la lista, cambierà la complessità del nostro algoritmo
L'algoritmo più efficiente lo otteniamo con una ListDL, ma vedremo che ottimizzando alcune procedure, riusciamo ad ottenere buoni risultati anche con gli array

Esempio
Supponiamo adesso di avere un array di lunghezza 

--------------------------------------------------------------------------------------------------------------------------------------------------------------

PILE (o STACK)
Le pile sono strutture dati in cui il primo dato che è arrivato, viene processato per ultimo.
Un esempio di pila potrebbe essere un autobus, il primo che  sale scende per ultimo.
La pila segue cioè l'organizzazione Last in first out (LIFO). Nelle pile abbiamo due possibili azioni:
->Aggiungo un elemento in cima alla pila. (PUSH)
->Estraggo un elemento sempre dalla cima. (POP) 

L'elemento in cima alla lista si chiama top. Come per code anche le pile possono essere implementate in maniere differenti.
1) Array -> PUSH avrà complessità O(1). POP avrà complessità O(1)
2) List -> PUSH avrà complessità O(1). POP avrà complessità O(1)
3) ListDL -> PUSH avrà complessità O(1). POP avrà complessità O(1)
Sia il POP che il PUSH avrà sempre tempo costante a prescindere dall'implementazione
*/

//condizione coda piena (h-(t+1))%6 ==0 , se è vero la coda è piena
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

template<class T>
class Queue {
	int length;
	int nElem = 0;
	T *queue;
	int head = -1, tail = -1;

	public:
	
	Queue(int length): length(length) {
		queue = new T[length];
	}
	Queue() : Queue(10) {}
	
	void enqueue(T value) {
		if(this->isFull()) 
			return;
		if(this->isEmpty()) {
			head = 0;
		}

		this->queue[(++tail) % length] = value;
		tail %= length;
		nElem++;
	}
	T dequeue() {
		if(this->isEmpty()) {
			return 0;
		}
		//restituire l'elemento in testa e aggiornare head facendo attenzione alla circolarità
		nElem--;
		T temp = this->queue[head];
		head = (head+1) % length;
		return temp; //this->queue[head++%length];
	}
	bool isFull() {
		return ((head - (tail+1)) % length) == 0;
	}
	bool isEmpty() {
		return nElem == 0; //(head == tail);
	}
	int size() const {
		return this->length - (((this->length - (tail - head)) -1 ) % this->length);
	}
	friend ostream& operator<<(ostream& out, const Queue& q) {
		out << "Coda di lunghezza massima " << q.length << " con " << q.nElem << " inseriti size=" << q.size() << endl;
		out << "head = " << q.head << " tail = " << q.tail << endl;
		for(int i=0; i < q.length; i++) 
			out << "\t" << q.queue[i] << ((i == q.head) ? " <- head" : ((i == q.tail) ? " <- tail" : "")) << endl;
		return out;
    }
	~Queue() {
		delete [] queue;
	}
	
	
};


int main(){

	/*Coda<AAA> coda1; //Per istanziare questa classe ricordiamo di inserire il costruttore di default per la classe AAA perchè abbiamo instaziato nella classe Coda un array coda = new T[lunghezza]
	cout << coda1 << endl;*/

	Queue<int> queue;
	cout << queue << endl;

	queue.enqueue(1);
	cout << queue << endl;

	queue.enqueue(122);
	cout << queue << endl;

	queue.dequeue();
	cout << queue << endl;

	return 0;
}