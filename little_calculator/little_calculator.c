#include <stdio.h>
#include <stdlib.h>

float input_zahl1();
float input_zahl2();
char input_operation();
float berechnung(int zahla, int zahlb, char operation);

int main() {
    float ergebnis;
    ergebnis = berechnung(input_zahl1(), input_zahl2(), input_operation());
    printf("\n%f", ergebnis);
    return 0;

}

float input_zahl1() {
    float a;
    printf("Wie lautet die erste Zahl?:        ");
    scanf("%f", &a);
    return a;
}

char input_operation() {
    char c;
    printf("Welche Operation wird gewuenscht?: ");
    scanf("%s", &c);
    return c;
}

float input_zahl2() {
    float b;
    printf("Wie lautet die zweite Zahl?:       ");
    scanf("%f", &b);
    return b;
}

float berechnung(int zahla, int zahlb, char operation) {
    float ergebnis;
    switch(operation) {
        case '+': ergebnis = zahla + zahlb;
        break;
        case '-': ergebnis = zahla - zahlb;
        break;
        case '*': ergebnis = zahla * zahlb;
        break;
        case '/': ergebnis = zahla / zahlb;
        break;
        case '|': ergebnis = zahla | zahlb;
        break;
        case '&': ergebnis = zahla & zahlb;
        break;
        case '^': ergebnis = zahla ^ zahlb;
        break;
        default:  printf("falsches ergebnis");
        return 0;
        break;
    }
    return ergebnis;
}
