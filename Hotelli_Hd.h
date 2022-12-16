#pragma once
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <set>
using std::cout;
using std::cin;
using std::string;

class Hotelli {
private:
	// Huone Struct. S�il�� huoneiden tiedot.
	struct Huone {
		bool saatavuus{};
		int huonemaara{};
		int varausnumero{};
		int hinta{};
		string vieras_nimi{};
		string vieras_email{};
	};

	// Huone vektori ja sen koko
	int vec_koko;
	std::vector<Huone> huone_vektori;


	// Perusmuuttujat huonekoon satunnaista arvoa varten
	const int a_raja_huonekoko = 40;
	const int y_raja_huonekoko = 300;

	// Perusmuuttujat varausnumeron satunnaista arvoa varten
	const int a_raja_varausnumero = 10000;
	const int y_raja_varausnumero = 99999;

public:
// Funktioiden julistus
//________________________________________________________________________________________________________________________________________________________
// Hotellin luonti Constructor julistus
	
	// M��ritt�� hotellin koon ja arvot
	Hotelli(int* ptr);
//________________________________________________________________________________________________________________________________________________________
// Huoneen Varaus ja peruutus julistus
	
	// Varaa huoneen. Ottaa sis��n k�ytt�j�n huone valinnan, nimen ja emailin.
	void Varaa_huone(const int& huone_valinta, const string& u_vieras_nimi, const string& u_vieras_email);
	
	// Peruuttaa varauksen. Ottaa sis��n k�ytt�j�n huone valinnan.
	void Peruuta_varaus(const int& huone_valinta);
//________________________________________________________________________________________________________________________________________________________
// Hinnan laskeminen julistus

	// Laskee alennuksen. Voidaan laskea hinta ja onnitteluviesti t�m�n avulla.
	int Laske_alennus();

	// Laskee lopullisen hinnan. Ottaa sis��n k�ytt�j�n huone valinnan, y�m��r�n ja alennusp��r�ksen.
	float Laske_lopullinen_hinta(const int& huone_valinta, const int& yomaara, const int& alennus_paatos);
//________________________________________________________________________________________________________________________________________________________
// Huoneen etsiminen julistus
	
	// Etsii varausnumeron perusteella kaytt�j�n varaaman huoneen numeron.
	void Etsi_huonenumerot(const int& huone_varausnumero);

	// Etsii k�ytt�j�n nimen perusteella kaytt�j�n varaaman huoneen numeron.
	void Etsi_huonenumerot(const string& huone_vieras_nimi);
//________________________________________________________________________________________________________________________________________________________
// Vapaiden huoneiden m��r� lasku julistus
	
	// Laskee vapaiden huoneiden m��r�n hotellissa.
	int Laske_vapaiden_huoneiden_maara();
//________________________________________________________________________________________________________________________________________________________
// Tulostetaan huone valinnat julistus

	// Tulostaa valittavat huoneet ja niiden saatavuudet.
	void Tulosta_vapaat_huoneet_();
//________________________________________________________________________________________________________________________________________________________
// Tulostetaan huone tiedot julistus

	// Tulostaa valittavan huoneen varausnumeron. Ottaa sis��n k�ytt�j�n huone valinnan.
	void Tulosta_huone_varausnumero(const int& huone_valinta);

	// Tulostaa valittavan alennus p��t�ksen. Ottaa sis��n k�ytt�j�n huone valinnan ja alennusp��t�ksen.
	void Tulosta_huone_alennus(const int& huone_valinta, const int& alennus_paatos);

	// Tulostaa valittavan huoneen koon. Ottaa sis��n k�ytt�j�n huone valinnan.
	void Tulosta_huone_koko(const int& huone_valinta);
//________________________________________________________________________________________________________________________________________________________
// Tarkistetaan huoneiden saatavuus ja peruutettavuus julistus

	// Tarkistaa huoneiden saatavuuden ja valitsee satummaisen huoneen.
	int Tarkista_satunnainen_huone_saatavuus();

	// Tarkistaa k�ytt�j�n huonevalinnan saatavuuden.
	bool Tarkista_saatavuus(const int& huone_valinta);

	// Tarkistaa k�ytt�j�n huonevalinnan peruutettavuuden.
	bool Tarkista_peruutettavuus(const int& huone_valinta, const string& u_vierasnimi);
//________________________________________________________________________________________________________________________________________________________
// Arvontafunktion m��rittely julistus

	// M��ritt�� satunnaisen arvon ohjelman k�ytt��n. Ottaa sis��n alarajan ja yl�rajan.
	int Satunnainen_arvo(int a_raja, int y_raja);
};

