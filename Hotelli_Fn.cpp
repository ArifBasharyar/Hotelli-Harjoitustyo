#include "Hotelli_Hd.h"
//________________________________________________________________________________________________________________________________________________________
// Hotellin luonti Constructor

Hotelli::Hotelli(int *ptr) {

	std::set<int> varaus_nro_set;																			

	vec_koko = Satunnainen_arvo(a_raja_huonekoko, y_raja_huonekoko);									// Asettaa parillisen m‰‰r‰n huoneita vektoriin.
	if (vec_koko % 2 != 0) {
		vec_koko++;
	} 
	huone_vektori.resize(vec_koko);

	int j = 0;
	for (auto& i : huone_vektori) {																		// M‰‰ritt‰‰ huoneiden muuttujien arvon
		i.saatavuus = Satunnainen_arvo(0, 1);															// !!Kun saatavuus arvo on 1, se on vapaa
		i.varausnumero = Satunnainen_arvo(a_raja_varausnumero, y_raja_varausnumero);
		i.huonemaara = (j++ < vec_koko / 2) ? 1 : 2;
		i.hinta = (i.huonemaara == 1) ? 100 : 150;

		while (varaus_nro_set.count(i.varausnumero) > 0) {												// Setti tarkistaa ettei samoja varausnumeroita ole
			i.varausnumero = Satunnainen_arvo(a_raja_varausnumero, y_raja_varausnumero);
		}
		varaus_nro_set.insert(i.varausnumero);
	}

	*ptr = vec_koko;
}

//________________________________________________________________________________________________________________________________________________________
// Huoneen Varaus ja peruutus

void Hotelli::Varaa_huone(const int & huone_valinta, const string& vieras_nimi, const string& vieras_email) {
	int k = huone_valinta - 1;																			// V‰hent‰‰ k‰ytt‰j‰n valitseman huoneen arvosta 1
	huone_vektori[k].saatavuus = 0;																		// Varaa k‰ytt‰j‰n valitseman huoneen
	huone_vektori[k].vieras_nimi = vieras_nimi;
	huone_vektori[k].vieras_email = vieras_email;
}


void Hotelli::Peruuta_varaus(const int& huone_valinta) {
	int k = huone_valinta - 1;																			// V‰hent‰‰ k‰ytt‰j‰n valitseman huoneen arvosta 1
	huone_vektori[k].saatavuus = 1;																		// Vapauttaa k‰ytt‰j‰n valitseman huoneen
	huone_vektori[k].vieras_nimi = {};
	huone_vektori[k].vieras_email = {};
}

//________________________________________________________________________________________________________________________________________________________
// Hinnan laskeminen

int Hotelli::Laske_alennus() {
	int random_nro = Satunnainen_arvo(1, 10);															// Valitsee alennuksen m‰‰r‰n
	if (random_nro <= 5) {
		if (random_nro <= 2) {
			return 2;
		}
		return 1;
	}
	return 0;
}

float Hotelli::Laske_lopullinen_hinta(const int& huone_valinta, const int& yomaara, const int& alennus_paatos) {
	int k = huone_valinta - 1;																			// V‰hent‰‰ k‰ytt‰j‰n valitseman huoneen arvosta 1
	if (alennus_paatos == 2) return huone_vektori[k].hinta * yomaara * 0.8f;							// Laskee huoneen lopullisen hinnan si‰‰notetuilla perusteilla
	else if (alennus_paatos == 1) return huone_vektori[k].hinta * yomaara * 0.9f;
	else return huone_vektori[k].hinta * yomaara * 1.0f;
}

//________________________________________________________________________________________________________________________________________________________
// Huoneen etsiminen

void Hotelli::Etsi_huonenumerot(const int& huone_varausnumero) {
	for (int i = 0; i < vec_koko; i++) {
		if (huone_vektori[i].varausnumero == huone_varausnumero) {
			cout << "Huoneesi numero on " << i + 1 << "\n";												// Tulostaa huonenumeron joka vastaa syˆtetty‰ arvoa
		}
	}
}

void Hotelli::Etsi_huonenumerot(const string& huone_vieras_nimi) {
	for (int i = 0; i < vec_koko; i++) {																
		if (huone_vektori[i].vieras_nimi == huone_vieras_nimi) {
			cout << "Huoneesi numero on " << i + 1 << "\n";												// Tulostaa huonenumeron joka vastaa syˆtetty‰ arvoa
		}
	}
}

//________________________________________________________________________________________________________________________________________________________
// Vapaiden huoneiden m‰‰r‰ lasku

int Hotelli::Laske_vapaiden_huoneiden_maara() {
	int vapaiden_huoneiden_maara = 0;
	for (const auto& i : huone_vektori) {
		vapaiden_huoneiden_maara += i.saatavuus;														// Laskee yhteen vapaiden huoneiden m‰‰r‰n
	}
	return vapaiden_huoneiden_maara;																	// Palautta lasketun arvon
}

//________________________________________________________________________________________________________________________________________________________
// Tulostetaan huone valinnat

void Hotelli::Tulosta_vapaat_huoneet_() {
	cout << "Huone\tSaatavuus\tHinta\tVarausnumero\n\n";
	for (int i = 0; i < vec_koko; i++) {
		if (huone_vektori[i].saatavuus == 1) {
			cout << i+1 << ".\tSaatavilla\t" 
				<< huone_vektori[i].hinta << "\t"
				<< huone_vektori[i].varausnumero << "\n";
		}
	}
}

//________________________________________________________________________________________________________________________________________________________
// Tulostetaan huone tiedot

void Hotelli::Tulosta_huone_varausnumero(const int& huone_valinta) {
	int k = huone_valinta - 1;																			// V‰hent‰‰ k‰ytt‰j‰n valitseman huoneen arvosta 1
	cout << "Varausnumeronne on " << huone_vektori[k].varausnumero << ".\n";							// Tulostaa k‰ytt‰j‰n valitseman huoneen varausnumeron
}

void Hotelli::Tulosta_huone_alennus(const int& huone_valinta, const int& alennus_paatos) {
	int k = huone_valinta - 1;																			// V‰hent‰‰ k‰ytt‰j‰n valitseman huoneen arvosta 1
	if (alennus_paatos == 2) {																			// Tulostaa k‰ytt‰j‰n valitseman huoneen alennuksen
		cout << "Onneksi olkoon! Olette voittaneet 20% alennuksen.\n";
	} else if (alennus_paatos == 1) {
		cout << "Onneksi olkoon! Olette voittaneet 10% alennuksen.\n";
	}
}

void Hotelli::Tulosta_huone_koko(const int& huone_valinta) {											// V‰hent‰‰ k‰ytt‰j‰n valitseman huoneen arvosta 1
	int k = huone_valinta - 1;																			// Tulostaa k‰ytt‰j‰n valitseman huoneen koon
	if (huone_vektori[k].huonemaara == 2) {
		cout << "Olette valinneen kahden hengen huoneen.\n";
	} else {
		cout << "Olette valinneen yhden hengen huoneen.\n";
	}
}

//________________________________________________________________________________________________________________________________________________________
// Tarkistetaan huoneiden saatavuus ja peruutettavuus

int Hotelli::Tarkista_satunnainen_huone_saatavuus() {	
	int random_numero{};
	for (int i = 0; i < vec_koko; i++) {
		random_numero = Satunnainen_arvo(0, vec_koko - 1);												// Luo satunnaisen arvon ja tarkistaa sen saatavuuden
		if (huone_vektori[random_numero].saatavuus == 1) {												// Jos huoneet loppuvat palauttaa arvon 0
			return random_numero + 1;
		}
	}
	return 0;
}

bool Hotelli::Tarkista_saatavuus(const int& huone_valinta) {
	int k = huone_valinta - 1;																			// V‰hent‰‰ k‰ytt‰j‰n valitseman huoneen arvosta 1
	if (huone_vektori[k].saatavuus == 1) {																// Tarkistaa k‰ytt‰j‰n valitseman huoneen saatavuuden
		return 1;
	}
	else return 0;
}

bool Hotelli::Tarkista_peruutettavuus(const int& huone_valinta, const string& vierasnimi) {
	int k = huone_valinta - 1;																			// V‰hent‰‰ k‰ytt‰j‰n valitseman huoneen arvosta 1
	if (huone_vektori[k].saatavuus == 0 && huone_vektori[k].vieras_nimi == vierasnimi) {				// Tarkistaa k‰ytt‰j‰n valitseman huoneen peruutettavuuden
		return 1;
	}
	else return 0;
}

//________________________________________________________________________________________________________________________________________________________
// Arvontafunktion m‰‰rittely.

int Hotelli::Satunnainen_arvo(int a_raja, int y_raja) {													// Luo satunnaisen numeron
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> jakauma(a_raja, y_raja);												// M‰‰ritt‰‰ jakauman
	return jakauma(rng);																				// Luo satunnaisen numeron jakauman sis‰ll‰
}
