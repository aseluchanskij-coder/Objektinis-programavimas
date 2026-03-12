#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "studentas.h"
#include "ivedimas_isvedimas.h"
#include "testavimas.h"

int main() {

    /*
    vector<studentas> grupe;

    auto start = std::chrono::high_resolution_clock::now();

    try {
        input(grupe);

        if (!grupe.empty()) {
            rusiuotistud(grupe);  
        }
    }
    catch (const std::exception &e) {
        std::cout << "Klaida: " << e.what() << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Visos programos veikimo laikas yra: "
              << elapsed.count() << " sekundes\n";
    */
    std::cout << "1 TYRIMAS – Failu kurimo sparta\n";

    failo_kurimo_testas(1000);
    failo_kurimo_testas(10000);
    failo_kurimo_testas(100000);
    failo_kurimo_testas(1000000);
    failo_kurimo_testas(10000000);


    std::cout << "\n=============================\n";

    std::cout << "2 TYRIMAS - Duomenu apdorojimas\n";

    apdorojimo_testas("studentai_1000.txt");
    apdorojimo_testas("studentai_10000.txt");
    apdorojimo_testas("studentai_100000.txt");
    apdorojimo_testas("studentai_1000000.txt");
    apdorojimo_testas("studentai_10000000.txt");

    return 0;
}