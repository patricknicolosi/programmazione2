#include <iostream>
#include <sstream>
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
        Veicolo(int _velocitaMax, double _prezzo, string _marca, string _motorizzazione, string _carburante, int _numeroRuote):
        velocitaMax(_velocitaMax), prezzo(_prezzo), marca(_marca), motorizzazione(_motorizzazione), carburante(_carburante), numeroRuote(_numeroRuote){}
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
            if(velocita <= velocitaMax){
                this->velocita++;
            }
            return;
        }
        void decelera(int _velocita){
            if(velocita > 0){
                this->velocita--;
            }
            return;
        }
        virtual string toString() const = 0; //virtual perchè non puo essere richiamata da un'istanza di Veicolo ma da una sua sottoclasse
        friend ostream& operator<<(ostream& stream, const Veicolo& veicolo){
            stream << veicolo.toString(); //Per accedere a questa funzione dobbiamo dichiare const la funzione toString
            return stream;
        }
};

class Moto : public Veicolo{
    public: 
        Moto(int _velocitaMax, double _prezzo, string _marca, string _motorizzazione) : 
        Veicolo (velocitaMax, _prezzo, _marca, _motorizzazione, "benzina", 2){
            velocitaMax = _velocitaMax;
        }
        string toString() const{
            stringstream stream;
            stream << "Moto: " << endl;
            stream << "-Velocita massima: " << velocitaMax << endl;
            stream << "-Prezzo: " << prezzo << endl;
            stream << "-Marca: " << marca << endl;
            stream << "-Motorizzazione: " << motorizzazione << endl;
            return stream.str();
        }
};

class Automobile : public Veicolo{
    public: 
        Automobile(int _velocitaMax, double _prezzo, string _marca, string _motorizzazione, string _carburante) : 
        Veicolo (velocitaMax, _prezzo, _marca, _motorizzazione, _carburante, 4){
            velocitaMax = _velocitaMax;
        }
        string toString() const{
            stringstream stream;
            stream << "Automobile: " << endl;
            stream << "-Velocita massima: " << velocitaMax << endl;
            stream << "-Prezzo: " << prezzo << endl;
            stream << "-Marca: " << marca << endl;
            stream << "-Motorizzazione: " << motorizzazione << endl;
            stream << "-Carburante: " << carburante << endl;
            return stream.str();
        }    
};

class Camion : public Veicolo{
    public: 
        Camion(int _velocitaMax, double _prezzo, string _marca, string _motorizzazione, string _carburante, int _numeroRuote) : 
        Veicolo (velocitaMax, _prezzo, _marca, _motorizzazione, _carburante, _numeroRuote){
            velocitaMax = _velocitaMax;
        }
        string toString() const{
            stringstream stream;
            stream << "Camion: " << endl;
            stream << "-Velocita massima: " << velocitaMax << endl;
            stream << "-Prezzo: " << prezzo << endl;
            stream << "-Marca: " << marca << endl;
            stream << "-Motorizzazione: " << motorizzazione << endl;
            stream << "-Carburante: " << carburante << endl;
            stream << "-Numero ruote: " << numeroRuote << endl;
            return stream.str();
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
    Moto moto = Moto(30, 100.50, "Ducati", "1000cc");
    cout << moto << endl;

    Automobile automobile = Automobile(30, 100.50, "Scania", "1000cc", "Diesel");
    cout << automobile << endl;

    Camion camion = Camion(30, 100.50, "Fiat Punto", "1000cc", "Diesel", 6);
    cout << camion << endl;

    return 0;
}