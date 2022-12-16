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
	
	// Enum ohjaamaan switch-järjestelmää ja selkeyttämään missä valikossa ollaan
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

	// Käyttäjälän tiedot
	struct Kayttaja {
		string nimi{};
		string email{};
		int huone_valinta{};
		int yomaara{}; 
		int alennus_arvo{};
		int varausnumero{};
	}
	kayttaja;
	
	// Valikon käynnistykseen asetetut muuttujat.
	bool lopeta = false;
	char komento{};
	Ohjain ohjain = yksityis_tiedot;

	// Hotelli classin määrittämät arvot
	int huone_maara{};
	int vapaiden_huoneiden_maara{};
	int satunnaisen_huoneen_numero{};

	// Valikon ennaltamääritetyt viestit.
	const string VIRHE_1 =				"\nEpämääräinen vastaus. Yritä uudestaan.\n";
	const string VIRHE_2 =				"\nJokin meni vikaan. Keskeytetään ohjelma.\n";
	const string PALATAANKO_ALKUUN =	"\nPaina näppäintä 1, jos haluat palata alkuun.\nPaina näppäintä 2, jos haluat lopettaa ohjelman.\n";
	const string LOPPU_VIESTI =			"Kiitos kun kävitte, hyvää päivän jatkoa.\n";

//________________________________________________________________________________________________________________________________________________________
// Vastausfunktio ja sen overloadien julistus.

	// Ottaa sisään integerin. Varmistaa että vastaus ei ole viallinen.
	// Varmistaa että koko on rajoitusten mukainen.
	// Muuttujan pitää olla ennaltä määritetty.
	// Oletuskoko on 1-10 merkkiä.
	void Vastaus(int &syote, int a_raja = 1, int y_raja = 10);

	// Ottaa sisään stringin. Varmistaa että vastaus ei ole viallinen.
	// Varmistaa että pituus on rajoitusten mukainen.
	// Muuttujan pitää olla ennaltä määritetty.
	// Oletuspituus on max 20 merkkiä.
	void Vastaus(string& syote, int y_raja = 20);

	// Ottaa sisään charin. Varmistaa että vastaus ei ole viallinen.
	// Muuttujan pitää olla ennaltä määritetty.
	void Vastaus(char& syote);
	
//________________________________________________________________________________________________________________________________________________________
// Näppäinfunktio ja sen overloadien julistus.

	// Havaitsee näppäimistön painikkeet. Varmistaa että painike on sopiva.
	// Mahdollista syöttää neljä näppäintä.
	void Nappain(char ehto1, char ehto2, char ehto3, char ehto4);

	// Havaitsee näppäimistön painikkeet. Varmistaa että painike on sopiva.
	// Mahdollista syöttää kolme näppäintä.
	void Nappain(char ehto1, char ehto2, char ehto3);

	// Havaitsee näppäimistön painikkeet. Varmistaa että painike on sopiva.
	// Mahdollista syöttää kolme näppäintä.
	void Nappain(char ehto1, char ehto2);

	// Havaitsee näppäimistön painikkeet. Varmistaa että painike on sopiva.
	// Mahdollista syöttää yksi näppäin.
	void Nappain(char ehto1);

//________________________________________________________________________________________________________________________________________________________
// Vaihtofunktio ja sen overloadien julistus.

	// Vaihtaa valikon enum tilan toiseen tilaan. Puhdistaa lopuksi näytön.
	// Mahdollista syöttää neljä haluttua tilaa ja niiden näppäintä.
	// Oletusnäppäin charit ovat '1', '2', '3' ja '4'.
	void Siirry(Ohjain tila1, Ohjain tila2, Ohjain tila3, Ohjain tila4, const char ehto1 = '1', const char ehto2 = '2', const char ehto3 = '3', const char ehto4 = '4');

	// Vaihtaa valikon enum tilan toiseen tilaan. Puhdistaa lopuksi näytön.
	// Mahdollista syöttää kolme haluttua tilaa ja niiden näppäintä.
	// Oletusnäppäin charit ovat '1', '2' ja '3'.
	void Siirry(Ohjain tila1, Ohjain tila2, Ohjain tila3, const char ehto1 = '1', const char ehto2 = '2', const char ehto3 = '3');

	// Vaihtaa valikon enum tilan toiseen tilaan. Puhdistaa lopuksi näytön.
	// Mahdollista syöttää kaksi haluttua tilaa ja niiden näppäintä.
	// Oletusnäppäin charit ovat '1' ja '2'.
	void Siirry(Ohjain tila1, Ohjain tila2, const char ehto1 = '1', const char ehto2 = '2');

	// Vaihtaa valikon enum tilan toiseen tilaan. Puhdistaa lopuksi näytön.
	// Ei ota vastaan char arvoja
	void Siirry(Ohjain tila1);

};

/*
		
*/