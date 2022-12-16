# Hotelli-Harjoitustyo
Harjoitustyo "C++-ohjelmoinnin perusteet" kurssia varten.

Sain tästä työstä 5 pistettä.

Harjoitustyöni perustuu kahteen classiin, joihin olen sijoittanut kaikki funktioni. Classissa Valikko
sijaitsevat kaikki funktiot, jotka ottavat vastaan komentoja, syötteitä jne. ja siirtävät valikosta
toiseen. Valikkoni itsessään toimii Constructorissa while loopiin laitetulla switchillä joka vaihtaa tilaa
enumin mukaan. Headeriin olen laittanut Ohjain enumin, Käyttäjä structin, joitain huoneiden tietoja
ja muutamia ennaltamääritettyjä viestä joita tarvitsee toistaa jatkuvasti.

Valikko classin Siirryfunktiot muuttavat enumin tilan toiseen kun char komento on oikeanlainen.
Olen antanut niile oletuskomennot 1-4 numerot ja l kirjain. Nappainfunktio havaitsee kun käyttäjä
painaa näppäimistön näppäimiä ja päästää ohi jos ne ovat oikeanlaisia. Näille en ole antanut
oletusvaihtoehtoa jotta sitä kutsuttaessa olisi pakko kirjoittaa halutut komennot. Lopuksi ovat
Vastausfunktiot jotka ottavat vastaan syötteitä ja sisällyttävät ne halutulle muuttujalle. Olen antanut
näille kaikille noin 2-3 overloadia. Olen laittanut Valikko classin constructorin ja funktiot eri
tiedostoille, jotta ne olisivat helpommin selattavissa.

Hotelli classissa sijaitsevat kaikki Hotellinhuoneisiin liittyvät funktiot ja muuttujat. Sen headeriin olen
laittanut Huone structin, structin vektorin ja sen koon määrittävän muuttujan. Classin constructoriin
olen laittanut kaikki ohjelman alussa tuotettavat hotelli arvot. Ensin se määrittää koon vektorille,
jonka se varmistaa olevan välillä 40 ja 300. Sitten se lisää muuttujaan yhden arvon lisää jos se on
pariton. Lopuksi se antaa vektorille koon haluttujen muuttujien perusteella.

Tämän jälkeen Contructori antaa for loopissa lähes kaikille structin muuttujille jonkin arvon. Käytin
settiä varmistamaan että mikään varausnumero ei ole sama. Lopuksi määritän funktion kutsun
aikana annetun muuttujan arvon pointterilla. Tämä antaa tiedon valikolle kuinka monta huonetta
vektorissa on.

Classin funktioissa ovat Varaus- ja Peruutusfunktio. Ne tekevät mitä olettaisikin. Sitten ovat
Laskealennus- ja Loppuhintafunktio. Ensimmäinen arpoo annetaanko alennusta ja toinen laskee
huoneen hinnan, yömäärän ja alennuksen avulla loppuhinnan. Sitten ovat Etsifuktiot jotka käyvät for
loopin kanssa koko vektorin läpi ja tulostavat vastauksen. Sitten on vapaiden huoneiden
laskurifunktio joka laskee yhteen vapaiden huoneidenmäärät. Tämä on käytössä päävalikossa. Sitten
on tulosta vapaat huoneetfunktio joka tulostaa kaikkien niiden huoneiden tiedot jotka ovat vapaana.
Päätin tulostaa vain huone numeron, saatavuuden, hinnan ja varausnumeron. Sitten ovat tulosta
varausnumero, alennus ja koko funktiot, jotka kertovat halutut tiedot hintaa tai laskua antaessa.
Sitten on tarkista saatavuus ja peruutettavuus funktiot jotka tarkistavat nämä tiedot. Lopuksi on
satunnaisen arvon laskeva funktio joka laskee satunnaisen arvon mt19937 ohjelmalla.

Valikko classin constructorissa sitten koko ohjelma käytännössä toimii. Se on ainoa asia joka
kutsutaan mainissa.
