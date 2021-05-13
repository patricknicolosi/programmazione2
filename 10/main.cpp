#include "list.hpp"


class Studente{ //Voglio adesso usare la lista che ho creato in una classe personalizzata Studente
	string nome;
	string cognome;
	int eta;
	string matricola;
	int compareTo(const Studente& studente){ //Per semplificare confrontiamo gli studenti solo per cognomi, questo metodo dovrà comparare due studenti e tornetrà utile nell'overload degli operatori
		int GREATER = 1, LESS = -1, EQUAL = 0;
		if(this->cognome > studente.getCognome()) return GREATER;
		else return LESS;
		return EQUAL;
	}
	
	public:
		Studente(string _nome, string _cognome, int _eta, string _matricola){
			this->nome = _nome;
			this->cognome = _cognome;
			this->eta = _eta;
			this->matricola = _matricola;
		}
		string getNome(){
			return this->nome;
		}
		string getCognome() const{
			return this->cognome;
		}
		string getMatricola(){
			return this->matricola;
		}
		int getEta(){
			return eta;
		}
		void setNome(string _nome){
			this->nome = _nome;
			return;
		}
		void setCognome(string _cognome){
			this->cognome = _cognome;
			return;
		}
		void setMatricola(int _matricola){
			this->matricola = _matricola;
			return;
		}
		void setEta(int _eta){
			this->eta = _eta;
			return;
		}	
		//Per implementare la lista dobbiamo fare l'overload di <, >, ==
		bool operator<(const Studente& studente){
			return this->compareTo(studente) == -1;
		}
		bool operator>(const Studente& studente){
			return this->compareTo(studente) == 1;
		}
		bool operator==(const Studente& studente){
			return this->compareTo(studente) == 0;
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
	cout << "X Cancello il valore " << list.cancel(15)->getValue() << " ..." <<  endl << endl;
	cout << list << endl;
	
	Studente s0 = Studente("mario", "rossi", 20, "mrrss");
	Studente s1 = Studente("luca", "verdi", 21, "lcvrd");
	Studente s2 = Studente("fabrizio", "corona", 40, "fbrzcrn");
	
	cout << (s0 < s1) << endl;
	cout << (s0 < s2) << endl;


	return 0;
}