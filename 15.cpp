
/*
-Gli alberi sono strutture dati particolari, in cui ogni nodo può avere al massimo un genitore.
	

		Questo è un albero(un solo G)		 Questo non è un albero(due G)
			  [G]                                   [G]     [G]
		     | 	 |                                    |     |
		     v   v                                     >[F]<                                     
			[F]	[F]


-Un genitore può invece avere numero massimo di figli pari alla sua "arietà" (numero massimo di figli per genitore).


		   ---[G]---
           |   |   |
		   v   v   v		Albero di arietà 3 (3 figli)
 		  [F] [F] [F]


		   ---[G]---
           |   |   |
		   v   v   v		Albero di arietà 3 (3 figli)
 		  [F] [F] [F]		questo albero ha sempre arietà 3 perchè non ci sono nodi che superino questo numero di figli
               |
           ---------    
           |   |   | 
		   v   v   v
		  [F] [F] [F]


-Gli alberi che andiamo ad approfondire sono sempre alberi di arietà 2, che prendono cioè il nome di alberi binari.
-Il nodo più in alto prende il nome di radice (ROOT). Un nodo che non ha figli prende il nome di foglia (LEAF).
-Possono esistere anche alberi con un solo nodo, saranno alberi dove quest unico nodo viene detto radice

-Gli alberi possono essere suddivisi per livelli:

			[G]                --> livello 0 (1 nodo = 2^0) = (arietà = 2, livello = 0)  -->  (arietà^livello = 2^0 = 1)
		----  -----
		|         |
		v         v
	   [F1]      [F1]          --> livello 1  (2 nodi = 2^1) = (arietà = 2, livello = 1)  -->  (arietà^livello = 2^1 = 2)
	  ------    ------
	  |    |    |    |
	 [F2] [F2] [F2]  [F2]      --> livello 2  (4 nodi = 2^2) = (arietà = 2, livello = 2)  -->  (arietà^livello = 2^2 = 4)

In ogni livello il numero di nodi seguono l'ordine delle potenze di 2. Il numero di nodi è anche esprimibile come arietà^livello
Il numero di livelli totali in un albero è quindi sempre  uguale alla sommatoria per i che va da 1 al massimo livello di 2^i. Se chiamo n questo valore, allora l'altezza dell'albero h = log_2(n)


*/


#include <iostream>
using namespace std;


int main(){
  return 0;
}
