#include <stdio.h>
#include <stdlib.h>

float zahl_eingabe();
float fakultaet_berechnen(float basis);

//this easy programm waits for an input of an number (integer or double)
//an returns the faculty
int main()
{
    printf("%.2f", fakultaet_berechnen(zahl_eingabe()));
    return 0;
}

//get's userinput (one number)
float zahl_eingabe() {
    float basis;
    printf("---  Fakultaet - Rechner  ---\n");
    printf("Geben Sie bitte eine Zahl ein: ");
    scanf("%f", &basis);
    return basis;
}

//calculates faculty
float fakultaet_berechnen(float basis) {
    float fakultaet = basis * basis;
    return fakultaet;
}
