#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "Hotelli_Hd.h"
using std::cout;
using std::cin;
using std::string;

class Valikko {
public:
//________________________________________________________________________________________________________________________________________________________
// Valikon luonti Constructor
	Valikko();

private:
//________________________________________________________________________________________________________________________________________________________
// Muuttujat ohjelman hallintaan.
	
	// Enum ohjaamaan switch-j�rjestelm�� ja selkeytt�m��n miss� valikossa ollaan
	const enum Ohjain {
		yksityis_tiedot,				
		paavalikko,
		
		huone_valinta,
		huone_varattu,
		
		satunnainen_huone,
		huoneita_ei_jaljella,
		
		yomaara,
		hinta,
		lasku_hyvaksytty,
		lasku_hylatty,
		
		varauksen_peruutus,
		peruutus_hyvaksytty,
		peruutus_hylatty,
		
		huoneen_etsiminen,
		vnmro_etsinta_vastaus,
		nimi_etsinta_valinta,
		etsinta_nimella,
		etsinta_vnrolla,

		lopeta_ohjelma,
	};

	// K�ytt�j�l�n tiedot
	struct Kayttaja {
		string nimi{};
		string email{};
		int huone_valinta{};
		int yomaara{}; 
		int alennus_arvo{};
		int varausnumero{};
	}
	kayttaja;
	
	// Valikon k�ynnistykseen asetetut muuttujat.
	bool lopeta = false;
	char komento{};
	Ohjain ohjain = yksityis_tiedot;

	// Hotelli classin m��ritt�m�t arvot
	int huone_maara{};
	int vapaiden_huoneiden_maara{};
	int satunnaisen_huoneen_numero{};

	// Valikon ennaltam��ritetyt viestit.
	const string VIRHE_1 =				"\nEp�m��r�inen vastaus. Yrit� uudestaan.\n";
	const string VIRHE_2 =				"\nJokin meni vikaan. Keskeytet��n ohjelma.\n";
	const string PALATAANKO_ALKUUN =	"\nPaina n�pp�int� 1, jos haluat palata alkuun.\nPaina n�pp�int� 2, jos haluat lopettaa ohjelman.\n";
	const string LOPPU_VIESTI =			"Kiitos kun k�vitte, hyv�� p�iv�n jatkoa.\n";

//________________________________________________________________________________________________________________________________________________________
// Vastausfunktio ja sen overloadien julistus.

	// Ottaa sis��n integerin. Varmistaa ett� vastaus ei ole viallinen.
	// Varmistaa ett� koko on rajoitusten mukainen.
	// Muuttujan pit�� olla ennalt� m��ritetty.
	// Oletuskoko on 1-10 merkki�.
	void Vastaus(int &syote, int a_raja = 1, int y_raja = 10);

	// Ottaa sis��n stringin. Varmistaa ett� vastaus ei ole viallinen.
	// Varmistaa ett� pituus on rajoitusten mukainen.
	// Muuttujan pit�� olla ennalt� m��ritetty.
	// Oletuspituus on max 20 merkki�.
	void Vastaus(string& syote, int y_raja = 20);

	// Ottaa sis��n charin. Varmistaa ett� vastaus ei ole viallinen.
	// Muuttujan pit�� olla ennalt� m��ritetty.
	void Vastaus(char& syote);
	
//________________________________________________________________________________________________________________________________________________________
// N�pp�infunktio ja sen overloadien julistus.

	// Havaitsee n�pp�imist�n painikkeet. Varmistaa ett� painike on sopiva.
	// Mahdollista sy�tt�� nelj� n�pp�int�.
	void Nappain(char ehto1, char ehto2, char ehto3, char ehto4);

	// Havaitsee n�pp�imist�n painikkeet. Varmistaa ett� painike on sopiva.
	// Mahdollista sy�tt�� kolme n�pp�int�.
	void Nappain(char ehto1, char ehto2, char ehto3);

	// Havaitsee n�pp�imist�n painikkeet. Varmistaa ett� painike on sopiva.
	// Mahdollista sy�tt�� kolme n�pp�int�.
	void Nappain(char ehto1, char ehto2);

	// Havaitsee n�pp�imist�n painikkeet. Varmistaa ett� painike on sopiva.
	// Mahdollista sy�tt�� yksi n�pp�in.
	void Nappain(char ehto1);

//________________________________________________________________________________________________________________________________________________________
// Vaihtofunktio ja sen overloadien julistus.

	// Vaihtaa valikon enum tilan toiseen tilaan. Puhdistaa lopuksi n�yt�n.
	// Mahdollista sy�tt�� nelj� haluttua tilaa ja niiden n�pp�int�.
	// Oletusn�pp�in charit ovat '1', '2', '3' ja '4'.
	void Siirry(Ohjain tila1, Ohjain tila2, Ohjain tila3, Ohjain tila4, const char ehto1 = '1', const char ehto2 = '2', const char ehto3 = '3', const char ehto4 = '4');

	// Vaihtaa valikon enum tilan toiseen tilaan. Puhdistaa lopuksi n�yt�n.
	// Mahdollista sy�tt�� kolme haluttua tilaa ja niiden n�pp�int�.
	// Oletusn�pp�in charit ovat '1', '2' ja '3'.
	void Siirry(Ohjain tila1, Ohjain tila2, Ohjain tila3, const char ehto1 = '1', const char ehto2 = '2', const char ehto3 = '3');

	// Vaihtaa valikon enum tilan toiseen tilaan. Puhdistaa lopuksi n�yt�n.
	// Mahdollista sy�tt�� kaksi haluttua tilaa ja niiden n�pp�int�.
	// Oletusn�pp�in charit ovat '1' ja '2'.
	void Siirry(Ohjain tila1, Ohjain tila2, const char ehto1 = '1', const char ehto2 = '2');

	// Vaihtaa valikon enum tilan toiseen tilaan. Puhdistaa lopuksi n�yt�n.
	// Ei ota vastaan char arvoja
	void Siirry(Ohjain tila1);

};

/*
		
*/