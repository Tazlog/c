/* Getraenke Automat Version 0.5 */

#include<stdio.h>

// --- Funktions-Prototypen ---------------------------
int auswahlGetraenkeSorte();
int eingabeMenge();
float ermittlePreis(int sorte);
float bezahlen(float zuZahlen);
int pruefeGeldstueck(float muenze);
void ausgabeGetraenke(int sorte, int menge);

// --- Hauptprogramm ----------------------------------
int main() {
	printf("Getraenke Automat v0.5\n\n");

	int sorte, menge;
	float preis, zuZahlen, gezahlt;

	sorte = auswahlGetraenkeSorte();
	preis = ermittlePreis(sorte);
	menge = eingabeMenge();
	zuZahlen = preis * menge;
	gezahlt = bezahlen(zuZahlen);

	if(gezahlt >= zuZahlen) {
		ausgabeGetraenke(sorte, menge);
		printf("\n\nVielen Dank, bitte entnehmen sie ihre Getraenke.\n");
	}else {
		printf("\n\nBezahlvorgang abgebrochen.\n");
		printf("Ausgabe von %.2f Euro.\n", gezahlt);
	}

	return 0;
}

// --- Funktionen -------------------------------------
int auswahlGetraenkeSorte() {
	int sorte;
	printf("Waehlen sie ihr Getraenk aus:\n");
	printf("1) Wasser (0,50 Euro)\n");
	printf("2) Limonade (1,00 Euro)\n");
	printf("3) Bier (2,00 Euro)\n\n");
	printf("Geben sie 1, 2 oder 3 ein: ");
	scanf("%d", &sorte);
	return sorte;
}

int eingabeMenge() {
	int menge=1;
	printf("\nGeben sie die gewuenschte Menge ein: ");
	scanf("%d", &menge);
	return menge;
}

/*	ermittelt den Preis zu einer Sorte
	Parameter:	sorte, Nummer der Sorte
	Return-Value:	Preis
*/
float ermittlePreis(int sorte) {
	float preis=0;
	switch(sorte) {
		case 1: preis = 0.5; break;
		case 2: preis = 1.0; break;
		case 3: preis = 2.0; break;
	}
	return preis;
}

/*	Startet Bezahlvorgang
	Parameter:  	zuZahlen, zu zahlender Betrag
	Return-Value:	gezahlter Betrag
*/
float bezahlen(float zuZahlen) {
	printf("\n--- Bezahlvorgang ---\n");
	printf("\nBezahlvorgang abbrechen mit 0\n");
	float einwurf, gezahlt=0;
	do {
		printf("\nEs fehlen noch %.2f Euro.", zuZahlen-gezahlt);
		printf("\nBitte werfen sie ein Geldstueck ein: ");
		scanf("%f", &einwurf);

		// Abbruch pruefen
		if(einwurf == 0) {
			break;
		}

		// eingeworfenen Betrag anrechnen
		if(pruefeGeldstueck(einwurf))  {
			gezahlt += einwurf;
		}else {
			printf("\nIhr Geldstueck ist ungueltig.");
		}

	} while(gezahlt < zuZahlen);

	return gezahlt;
}

/*	prueft Geldstueck auf Gueltigkeit
	Parameter:  	muenze, entpricht eingeworfenem Geldstueck
	Return-Value:	1, gueltige Muenze
			0, falsche Muenze
*/
int pruefeGeldstueck(float muenze) {
	// Muenzwert in ganze Zahl umrechnen, also in Cent.
	// Da die case Anweisung nicht mit floats arbeiten kann.
	int cent = muenze * 100;
	switch(cent) {
		case 5:		return 1;
		case 10:	return 1;
		case 20:	return 1;
		case 50:	return 1;
		case 100:	return 1;
		case 200:	return 1;
		default:	return 0;
	}
}

void ausgabeGetraenke(int sorte, int menge) {
	printf("\n--- Getraenkeausgabe ---\n");
	int i;
	for(i=0; i < menge; i++)  {
		printf("\nFlasche %d von %d der Sorte %d wurde ausgegeben.",
			i+1, menge, sorte);
	}
}
