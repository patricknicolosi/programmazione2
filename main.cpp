#include <iostream>
using namespace std;

template <class T>
class Queue{
	int head, tail = -1;
	int nElements = 0;
	int length;
	T* queue;

	public:
		Queue(int length): length(length) {
			queue = new T[length];
		}
		Queue() : Queue(5) {}

		void enqueue(T value){
			if(isFull()){
				return;
			}
			if(isEmpty()){
				head = 0;
			}
			tail = ((tail+1) % length); //inserisco questo perchè devo prendere in considerazione l'eventualità in cui la coda sia piena, questa condizione di accesso funziona bene in tutti i casi, sia in una coda piena che in una coda vuota o semi vuota
			this->queue[tail] = value; 
			nElements++;
		}
		bool dequeue(){
			if(isEmpty()) return false;
			head = (head+1) % length;
			nElements--;
			return true;
		}
		bool isFull(){
			if((head - (tail+1)) % length == 0) return true;
			return false;
		}
		bool isEmpty(){
			if(nElements == 0) return true;
			return false;
		}
		int getLength() const{
			return length;
		}
		friend ostream& operator << (ostream& stream, const Queue& queue){
			for(int i=0; i<queue.length; i++){
				stream << queue.queue[i] <<  ((i==queue.head) ? " <-- head" : (i == queue.tail) ? " <-- tail" : " ") << endl;
			}
			return stream;
		}


};


int main(){
	Queue<int> queue;

	for(int i=1; i<queue.getLength()+1; i++){
		queue.enqueue(i);
		cout << queue << endl;
		cout << ".............................." << endl << endl;
	}

	queue.dequeue();
	cout << queue << endl;

	return 0;
}