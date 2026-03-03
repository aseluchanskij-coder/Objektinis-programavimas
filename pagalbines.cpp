#include "pagalbines.h"
#include <iostream>
#include <cstdlib>
#include <cctype>

using std::cout;
using std::cin;

bool string_nusk(const string &s) {
    for (char c : s)
        if (!isalpha(c)) return false;
    return true;
}

int skaiciaus_nusk() {
    int x;
    while (true) {
        cin >> x;
        if (!cin.fail()) return x;
        cout << "Klaida! Prasome ivesti skaiciu: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int random_paz() {
    return rand() % 10 + 1;
}

string random_vardas() {
    string vardai[10] = {"Jonas","Petras","Mantas","Lukas","Tomas","Paulius","Alanas","Danielius","Povilas","Ernestas"};
    return vardai[rand() % 10];
}

string random_pavarde() {
    string pavardes[10] = {"Jonaitis","Petraitis","Kazlauskas","Balciunas","Jankauskas","Stankevicius","Vaitkus","Butkus","Urbonas","Zukauskas"};
    return pavardes[rand() % 10];
}