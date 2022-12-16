#include "Valikko_Hd.h"

//________________________________________________________________________________________________________________________________________________________
// Vastausfunktio ja sen overloadit:

void Valikko::Vastaus(int &syote, int a_raja, int y_raja) {
	while (true) {
		if (cin >> syote && (syote >= a_raja && syote <= y_raja)) break;				// Whilelooppi kiert‰‰ kunnes saa haluamansa vastauksen
		cin.clear();
		cin.ignore();
		cout << VIRHE_1;																// Puhdista syˆte ja tulosta virheviesti virheellisen syˆtteen j‰lkeen
	}
}

/*
void Valikko::Vastaus(int &syote, int a_raja, int y_raja) {								// Toimivat yht‰ hyvin
	while (!(cin >> syote) || (syote < a_raja || syote > y_raja)) {						// Whilelooppi kiert‰‰ kunnes saa haluamansa vastauksen
		cin.clear();
		cin.ignore();
		cout << VIRHE_1;																// Puhdista syˆte ja tulosta virheviesti virheellisen syˆtteen j‰lkeen
	}
}
*/


void Valikko::Vastaus(string &syote, int y_raja) {
	while (!(cin >> syote) || syote.length() > y_raja) {								// Whilelooppi kiert‰‰ kunnes saa haluamansa vastauksen.
		cin.clear();
		cin.ignore();
		cout << VIRHE_1;																// Puhdista syˆte ja tulosta virheviesti virheellisen syˆtteen j‰lkeen
	}
}

void Valikko::Vastaus(char &syote) {
	while (!(cin >> syote)) {															// Whilelooppi kiert‰‰ kunnes saa haluamansa vastauksen.		
		cin.clear();
		cin.ignore();
		cout << VIRHE_1;																// Puhdista syˆte ja tulosta virheviesti virheellisen syˆtteen j‰lkeen
	}
}

//________________________________________________________________________________________________________________________________________________________
// N‰pp‰infunktio ja sen overloadit:

void Valikko::Nappain(char ehto1, char ehto2, char ehto3, char ehto4) {
	while (!(komento = _getch()) || (komento != 'l' && komento != 'L' &&				// Ota vastaan char ehto n‰pp‰imet sek‰ 'L' ja 'l' n‰pp‰imet
			komento != ehto1 && komento != ehto2 && komento != ehto3 && komento != ehto4)) {
		cout << VIRHE_1;																// Tulosta virheviesti jos k‰ytt‰j‰ painaa sopimatonta n‰pp‰int‰
	}
}

void Valikko::Nappain(char ehto1, char ehto2, char ehto3) {
	while (!(komento = _getch()) || (komento != 'l' && komento != 'L' &&				// Ota vastaan char ehto n‰pp‰imet sek‰ 'L' ja 'l' n‰pp‰imet
			komento != ehto1 && komento != ehto2 && komento != ehto3)) {
		cout << VIRHE_1;																// Tulosta virheviesti jos k‰ytt‰j‰ painaa sopimatonta n‰pp‰int‰
	}
}

void Valikko::Nappain(char ehto1, char ehto2) {
	while (!(komento = _getch()) || (komento != 'l' && komento != 'L' &&				// Ota vastaan char ehto n‰pp‰imet sek‰ 'L' ja 'l' n‰pp‰imet
			komento != ehto1 && komento != ehto2)) {
		cout << VIRHE_1;																// Tulosta virheviesti jos k‰ytt‰j‰ painaa sopimatonta n‰pp‰int‰
	}
}

void Valikko::Nappain(char ehto1) {
	while (!(komento = _getch()) || (komento != 'l' && komento != 'L' &&				// Ota vastaan char ehto n‰pp‰imet sek‰ 'L' ja 'l' n‰pp‰imet
			komento != ehto1)) {
		cout << VIRHE_1;																// Tulosta virheviesti jos k‰ytt‰j‰ painaa sopimatonta n‰pp‰int‰
	}
}

//________________________________________________________________________________________________________________________________________________________
// Siirryfunktio ja sen overloadit:

void Valikko::Siirry(Ohjain tila1, Ohjain tila2, Ohjain tila3, Ohjain tila4, const char ehto1, const char ehto2, const char ehto3, const char ehto4) {
	if		(komento == ehto1)						ohjain = tila1;						// Siirry tilaan tila1, jos char on ehto1. Oletus vaihtoehto on  '1'
	else if (komento == ehto2)						ohjain = tila2;						// Siirry tilaan tila2, jos char on ehto2. Oletus vaihtoehto on  '2'
	else if (komento == ehto3)						ohjain = tila3;						// Siirry tilaan tila3, jos char on ehto3. Oletus vaihtoehto on  '3'
	else if (komento == ehto4)						ohjain = tila4;						// Siirry tilaan tila4, jos char on ehto4. Oletus vaihtoehto on  '4'
	else if (komento == 'l' || komento == 'L')		ohjain = lopeta_ohjelma;			// Siirry tilaan lopeta ohjelma, jos komento on char 'l' tai 'L'
	else											{cout << VIRHE_2; lopeta = true;}	// Lopeta ohjelma ja tulosta virheviesti, jos virhe tapahtunut
	system("cls");									// Puhdista n‰yttˆ
}

void Valikko::Siirry(Ohjain tila1, Ohjain tila2, Ohjain tila3, const char ehto1, const char ehto2, const char ehto3) {
	if		(komento == ehto1)						ohjain = tila1;						// Siirry tilaan tila1, jos char on ehto1. Oletus vaihtoehto on  '1'
	else if (komento == ehto2)						ohjain = tila2;						// Siirry tilaan tila2, jos char on ehto2. Oletus vaihtoehto on  '2'
	else if (komento == ehto3)						ohjain = tila3;						// Siirry tilaan tila3, jos char on ehto3. Oletus vaihtoehto on  '3'
	else if (komento == 'l' || komento == 'L')		ohjain = lopeta_ohjelma;			// Siirry tilaan lopeta ohjelma, jos komento on char 'l' tai 'L'
	else											{cout << VIRHE_2; lopeta = true;}	// Lopeta ohjelma ja tulosta virheviesti, jos virhe tapahtunut
	system("cls");									// Puhdista n‰yttˆ
}

void Valikko::Siirry(Ohjain tila1,Ohjain tila2, const char ehto1, const char ehto2) {
	if		(komento == ehto1)						ohjain = tila1;						// Siirry tilaan tila1, jos char on ehto1. Oletus vaihtoehto on  '1'
	else if (komento == ehto2)						ohjain = tila2;						// Siirry tilaan tila2, jos char on ehto2. Oletus vaihtoehto on  '2'
	else if (komento == 'l' || komento == 'L')		ohjain = lopeta_ohjelma;			// Siirry tilaan lopeta ohjelma, jos komento on char 'l' tai 'L'
	else											{cout << VIRHE_2; lopeta = true;}	// Lopeta ohjelma ja tulosta virheviesti, jos virhe tapahtunut
	system("cls");									// Puhdista n‰yttˆ
}

void Valikko::Siirry(Ohjain tila1) {													// K‰yt‰nnˆss‰ tarkoitettu pit‰m‰‰n switchit mahdollisimman samanlaisina
	ohjain = tila1;									// Siirry tilaan tila1
	system("cls");									// Puhdista n‰yttˆ
}

