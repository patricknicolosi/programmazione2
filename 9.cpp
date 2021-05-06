#include <iostream>
using namespace std;

/*
Implementare una classe che rappresenti una gerarchia di veicoli
Ogni veicolo ha un numero di ruote, un tipo di carburante, una velocità massima,
una marca ed un prezzo. 
Tra i veicoli distinguiamo motocicli, automobili, camion, mezzi speciali.
Si simuli una gara tra 10 veicoli di tipo diverso, riportando posizioni iniziali, sorpassi e classifica finale 
*/

//Dalla descrizione del cliente vediamo qualche metodo che potrebbe ritornare utile
class Veicolo{
    protected:
        int numeroRuote;
        string carburante; //No definitivo
        string motorizzazione; //No definitivo
        int velocitaMax; //Velocità massima
        string marca;
        double prezzo;
    
    public:
        int velocita; //Velocità istantanea
        int posizione; //La posizione attuale del veicolo
        int getNumeroRuote(){
            return numeroRuote;
        }
        string getCarburante(){
            return carburante;
        }
        string getMotorizzazione(){
            return motorizzazione;
        }
        int getVelocitaMax(){
            return velocitaMax;
        }
        string getMarca(){
            return marca;
        }
        double getPrezzo(){
            return prezzo;
        }
        void setNumeroRuote(int _numeroRuote){
            this->numeroRuote = _numeroRuote;
            return;
        }
        void setCarburante(string _carburante){
            this->carburante = _carburante;
            return;
        }
        void setMotorizzazione(string _motorizzazione){
            this->motorizzazione = _motorizzazione;
            return;
        }
        void setVelocitaMax(int _velocitaMax){
            this->velocitaMax = _velocitaMax;
            return;
        }
        void setMarca(string _marca){
            this->marca = _marca;
            return;
        }
        void setPrezzo(double _prezzo){
            this->prezzo = _prezzo;
            return;
        }
        void accelera(int _velocita){
            this->velocita += _velocita;
            return;
        }
        void decelera(int _velocita){
            int supp = this->velocita - _velocita;
            if(supp<0){
                cout << "Il veicolo non può decelerrare pi di cosi" << endl;
            }
            else{
                this->velocita -= _velocita;
            }
            return;
        }
        string toString(){
            return "ciao mondo";
        }
};

class Gara{
    public:
        void sorpassa(Veicolo& veicoloSorpassante, Veicolo& veicoloSorpassato){
            if(veicoloSorpassante.velocita > veicoloSorpassato.velocita){
                veicoloSorpassante.posizione++;
                veicoloSorpassato.posizione--;
                cout << "Il primo veicolo ha superato il secondo" << endl;
            }
            else{
                veicoloSorpassante.posizione--;
                veicoloSorpassato.posizione++;
                cout << "Il secondo veicolo ha superato il primo" << endl;
            }   
        }
};

int main(){
    Veicolo v;
    cout <<  v.getMotorizzazione() << endl;
    return 0;
}