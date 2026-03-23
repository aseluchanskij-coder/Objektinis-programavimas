#include "testavimas.h"
#include "studentas.h"
#include "ivedimas_isvedimas.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void failo_kurimo_testas(int kiek)
{
    auto start = high_resolution_clock::now();

    ofstream f("studentai_" + to_string(kiek) + ".txt");

    for(int i=0;i<kiek;i++){
        f << "Vardas" << i << " Pavarde" << i;

        for(int j=0;j<5;j++)
            f << " " << rand()%10+1;

        f << " " << rand()%10+1 << "\n";
    }

    f.close();

    auto end = high_resolution_clock::now();

    cout << kiek << " irasu failo kurimo laikas: "
         << duration<double>(end-start).count() << endl;
}

 void skaitymas_is_galutinio(const string& failas, vector<studentas>& grupe)
{
    ifstream in(failas);

    if (!in) {
        cout << "Nepavyko atidaryti failo!\n";
        return;
    }

    string line;

    getline(in, line);
    getline(in, line);

    string vardas, pavarde;
    double galutinis;
    string temp;

    while (in >> vardas >> pavarde >> galutinis >> temp) {
        studentas s;
        s.vardas = vardas;
        s.pavarde = pavarde;
        s.rez = galutinis; 

        grupe.push_back(s);
    }

    cout << "Duomenys nuskaityti is failo!\n";
}
void apdorojimo_testas(const string& failas)
{
    vector<studentas> grupe;

    auto viso_start = high_resolution_clock::now();

    auto start = high_resolution_clock::now();

    skaitymas_is_galutinio(failas, grupe);

    auto end = high_resolution_clock::now();

    cout << "Failo nuskaitymo laikas: "
         << duration<double>(end-start).count() << " sekundes." <<endl;

    vector<studentas> vargsai, kietuoliai;

    start = high_resolution_clock::now();
    sort(grupe.begin(), grupe.end(), pagalRez);
    padalinti_studentus(grupe, vargsai, kietuoliai);

    end = high_resolution_clock::now();

    cout << "Studentu skirstymo laikas: "
         << duration<double>(end-start).count() << " sekundes." <<endl;

    start = high_resolution_clock::now();

    ofstream f1("vargsai.txt");
    output(f1, vargsai);
    f1.close();

    ofstream f2("kietuoliai.txt");
    output(f2, kietuoliai);
    f2.close();

    end = high_resolution_clock::now();

    cout << "Irasymo i failus laikas: "
         << duration<double>(end-start).count() << " sekundes." <<endl;


    auto viso_end = high_resolution_clock::now();

    cout << "Visos programos laikas: "
         << duration<double>(viso_end-viso_start).count() << " sekundes." << endl;
}