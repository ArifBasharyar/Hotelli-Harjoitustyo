#include "Valikko_Hd.h"

Valikko::Valikko() {
	// ƒ‰kkˆset
	setlocale(LC_ALL, "fi_Fi");

	// Hotellin Luominen
	Hotelli Hotelli(&huone_maara);																		// Hotelli Constructorfunktion kutsu ja ‰‰ritt‰‰ huonem‰‰r‰n t‰lle classille

	// Valikon looppi
	while (!lopeta) {																					// Valikko ohjelma on k‰ynniss‰ niin kauan kuin komento ei ole lopeta = true
		switch (ohjain) {																				// Ohjain on ohjain enum
//______________________________________________________________________________________________________________________________________________________________________
		case yksityis_tiedot:																			// Kirjaudutaan sis‰‰n
			cout	<< "Tervetuloa Arifin hotelliohjelmaan.\n"
					<< "Syˆt‰ ensin tietosi.\n\n"
					<< "Mik‰ on nimesi?\n"
					<< "Nimi: ";

			Vastaus(kayttaja.nimi);																		// Ottaa sis‰‰n k‰ytt‰j‰n nimen
			
			cout	<< "\nMik‰ on s‰hkˆpostisi?\n"
					<< "S‰kˆposti: ";

			Vastaus(kayttaja.email);																	// Ottaa sis‰‰n k‰ytt‰j‰n emailin
			Siirry(paavalikko);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case paavalikko:																				// Tulostetaan p‰‰valiko ja huoneiden m‰‰r‰
			vapaiden_huoneiden_maara = Hotelli.Laske_vapaiden_huoneiden_maara();						// Laskee vapaiden huoneiden m‰‰r‰n kun menn‰‰n p‰‰valikkoon

			cout	<< "------------------------------------------\n\t\tPƒƒVALIKKO\n" 
					<< "------------------------------------------\n\n"
					<< "Paina n‰pp‰int‰ 1, jos haluat varata huoneen.\n"
					<< "Paina n‰pp‰int‰ 2, jos haluat varata satunnaisen huoneen.\n"
					<< "Paina n‰pp‰int‰ 3, jos haluat peruuttaa varauksen.\n"
					<< "Paina n‰pp‰int‰ 4, jos haluat etsi‰ varaamasi huoneen numeron uudestaan.\n\n"
					<< "Voit myˆs painaa n‰pp‰int‰ L kun pyydet‰‰n komentoa. T‰m‰ lopettaa ohjelman.\n"
					<< "\nHuoneiden m‰‰r‰ on "
					<< huone_maara
					<< "\nVarattujen huoneiden m‰‰r‰ on "
					<< huone_maara - vapaiden_huoneiden_maara
					<< "\nVapaiden huoneiden m‰‰r‰ on "
					<< vapaiden_huoneiden_maara;

			Nappain('1', '2', '3', '4');
			Siirry(huone_valinta, satunnainen_huone, varauksen_peruutus, huoneen_etsiminen);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case huone_valinta:																				// K‰ytt‰j‰ valitsee huoneen
			cout	<< "Huoneita on vapaana " 
					<< huone_maara
					<< ".\nMink‰ huoneen haluat valita?\n\n";
					Hotelli.Tulosta_vapaat_huoneet_();													// Tulostaa valittavat huoneet
			cout	<< "\nHuone: ";

			Vastaus(kayttaja.huone_valinta, 1, huone_maara);
			
			if (Hotelli.Tarkista_saatavuus(kayttaja.huone_valinta)) {									// Tarkistaa k‰ytt‰j‰n huone valinnan saatavuuden
				Siirry(yomaara);
			} else {
				Siirry(huone_varattu);
			}
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case huone_varattu:																				// K‰ytt‰j‰n valitsema huone on varattu
			cout	<< "Huone on varattu\n\n"
					<< "Paina n‰pp‰int‰ 1, jos haluat kokeilla varata uudestaan.\n"
					<< "Paina n‰pp‰int‰ 2, jos haluat palata alkuun.\n";

			Nappain('1', '2');
			Siirry(huone_valinta, paavalikko);
			break;
//______________________________________________________________________________________________________________________________________________________________________
			case satunnainen_huone:																		// Valitaan satunnaista huonetta
			cout	<< "Varataan satunnaista huonetta\n";												// T‰m‰n ei pit‰isi k‰yt‰nnˆss‰ n‰ky‰

			satunnaisen_huoneen_numero = Hotelli.Tarkista_satunnainen_huone_saatavuus();				// Tarkistaa ett‰ huoneita on saatavilla
			if (satunnaisen_huoneen_numero > 0) {
				kayttaja.huone_valinta = satunnaisen_huoneen_numero;
				Siirry(yomaara);
			} else {
				Siirry(huoneita_ei_jaljella);
			}
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case huoneita_ei_jaljella:																		// Huoneita ei ole j‰ljell‰
			cout	<< "Pahoittelut, mutta varattavia huoneita ei ole en‰‰n j‰ljell‰.\n"
					<< "Yritt‰‰k‰‰ joskus toiste uudestaan.\n"
					<< PALATAANKO_ALKUUN;

			Nappain('1', '2');
			Siirry(paavalikko, lopeta_ohjelma);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case yomaara:																					// Valitaan yˆm‰‰r‰
			cout	<< "Montako yˆt‰ haluat yˆpy‰? (Huom! max 1 vuosi mahdollista varata)\n"
					<< "Yˆm‰‰r‰: ";

			Vastaus(kayttaja.yomaara, 1, 365);															// Valitsin max m‰‰r‰ksi 365 yˆt‰
			Siirry(hinta);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case hinta:																						// P‰‰tet‰‰n hyv‰ksyt‰‰nko hinta
			kayttaja.alennus_arvo = Hotelli.Laske_alennus();											// Lasketaan alennusarvo
			Hotelli.Tulosta_huone_koko(kayttaja.huone_valinta);											// Tulostetaan huonekoko
			Hotelli.Tulosta_huone_alennus(kayttaja.huone_valinta, kayttaja.alennus_arvo);				// Tulostetaan huonealennus

			cout	<< "\nKokonaishinnaksi tulee "														// Tulostetaan kokonaishinta
					<< Hotelli.Laske_lopullinen_hinta(kayttaja.huone_valinta, kayttaja.yomaara, kayttaja.alennus_arvo)
					<< "e.\n" 
					<< "Paina n‰pp‰int‰ 1, jos hyv‰ksyt hinnan.\n"
					<< "Paina n‰pp‰int‰ 2, jos et hyv‰ksy.\n";

			Nappain('1', '2');
			Siirry(lasku_hyvaksytty, lasku_hylatty);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case lasku_hyvaksytty:																			// lasku hyvaksytty
			Hotelli.Varaa_huone(kayttaja.huone_valinta, kayttaja.nimi, kayttaja.email);
			
			cout	<< "Maksu l‰hetetty osoitteeseen "
					<< kayttaja.email << ".\n";
					Hotelli.Tulosta_huone_varausnumero(kayttaja.huone_valinta);
			cout	<< "Varaamanne huoneen luku on " 
					<< kayttaja.huone_valinta << ".\n"
					<< PALATAANKO_ALKUUN;

			Nappain('1', '2');
			Siirry(paavalikko, lopeta_ohjelma);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case lasku_hylatty:																				// lasku hylatty
			cout	<< "Tilaus hyl‰tty. "
					<< PALATAANKO_ALKUUN;
			

			Nappain('1', '2');
			Siirry(paavalikko, lopeta_ohjelma);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case varauksen_peruutus:																		// P‰‰tet‰‰n mink‰ huoneen varaus peruutetaan
			cout	<< "Mink‰ huoneen varauksen haluat peruuttaa?\n"
					<< "Huonenumero: ";

			Vastaus(kayttaja.huone_valinta, 1, huone_maara);
			
			if (Hotelli.Tarkista_peruutettavuus(kayttaja.huone_valinta, kayttaja.nimi)) {				// Tarkistaa ett‰ huone on k‰ytt‰j‰n
				Siirry(peruutus_hyvaksytty);
			} else {
				Siirry(peruutus_hylatty);
			}
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case peruutus_hyvaksytty:																		// peruutus hyv‰ksytty
			Hotelli.Peruuta_varaus(kayttaja.huone_valinta);

			cout	<< "Varauksenne on peruutettu.\n"
					<< PALATAANKO_ALKUUN;

			Nappain('1', '2');
			Siirry(paavalikko, lopeta_ohjelma);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case peruutus_hylatty:																			// peruutus hyl‰tty
			cout	<< "Varausta ei voitu peruuttaa, pahoittelut.\n\n"
					<< PALATAANKO_ALKUUN;

			Nappain('1', '2');
			Siirry(paavalikko, lopeta_ohjelma);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case huoneen_etsiminen:																			// P‰‰tet‰‰n kuinka etsit‰‰n huonenumeroa
			cout	<< "Haluatko etsi‰ varausnumeron vai nimen perusteella.\n"
					<< "Paina n‰pp‰int‰ 1, jos haluat etsi‰ varausnumeron perusteella.\n"
					<< "Paina n‰pp‰int‰ 2, jos haluat etsi‰ nimen perusteella.\n";

			Nappain('1', '2');
			Siirry(vnmro_etsinta_vastaus, nimi_etsinta_valinta);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case vnmro_etsinta_vastaus:																		// Etsit‰‰n varausnumeroa vastaan
			cout	<< "Syˆt‰ varausnumero jonka perusteella haluat etsia huoneen.\n"
					<< "Varausnumero: ";

			Vastaus(kayttaja.varausnumero, 10000, 99999);
			Siirry(etsinta_vnrolla);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case nimi_etsinta_valinta:																		// Varmistetaan ettt‰ nimi on oikea
			cout	<< "Varmistamme ett‰ nimesi on "
					<< kayttaja.nimi << ".\n"
					<< "Paina n‰pp‰int‰ 1, jos hyv‰ksyt.\nPaina n‰pp‰int‰ 2, jos haluat palata alkuun.\n";

			Nappain('1', '2');
			Siirry(etsinta_nimella, paavalikko);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case etsinta_nimella:																			// Etsit‰‰n nimell‰
					Hotelli.Etsi_huonenumerot(kayttaja.nimi);											// Tulostaa huonenumerot
			cout	<< PALATAANKO_ALKUUN;
			
			Nappain('1', '2');
			Siirry(paavalikko, lopeta_ohjelma);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case etsinta_vnrolla:																			// Etsit‰‰n varausnumerolla
					Hotelli.Etsi_huonenumerot(kayttaja.varausnumero);									// Tulostaa huonenumeron
			cout	<< PALATAANKO_ALKUUN;

			Nappain('1', '2');
			Siirry(paavalikko, lopeta_ohjelma);
			break;
//______________________________________________________________________________________________________________________________________________________________________
		case lopeta_ohjelma:																			// lopetetaan ohjelma
			cout	<< LOPPU_VIESTI;
			lopeta = true;
			break;
//______________________________________________________________________________________________________________________________________________________________________
		default:																						// Ei pit‰isi tapahtua
			cout	<< VIRHE_2;
			lopeta = true;
			break;
		}
	}
};
