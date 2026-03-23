# Objektinis-programavimas
Vektoriu versija prašo vartotojo padaryti pasirinkimą: 1- ranka įvesti studentų vardus bei jų pažymius, 2 - prašo įvesti studento vardus, bet namų darbų bei egzamino pažymiai generuojami atsitiktinai nuo 1 iki 10, 3 - sugeneruoja studentų vardus bei pavardes, analogiškai ir visus gautus pažymius, 4 - nuskaito duomenis iš failo, 5 - nuskaityti is anksto sugeneruota faila, 6 - baigti.
Yra galimybė skaityti duomenis iš failo, taip pat juos rūšiuoti pagal vieną iš penkių parinkčių. Sukurti papildomi funkcionalumai, sukurta daugiau .cpp ir .h failų, panaudota exception handling funckija dviejuose vietuose. Dabartinėje versijoje pridėtas studentų atskirimas į vargšus ir kietuolius, taip pat pridėta galimybė skaityti duomenis iš vartotojo įvesto failo ir rašyti į vartotojo pasirinktą failą. Taip pat yra galimybė atlikti testavimą, o būtent programos veikimo laiko. Buvo atlikti du tyrimai: 1 tyrimas (darbas su failais tik failų sukūrimas, atskira testavimo funkcija):  
failų kūrimas ir jo uždarymas.
2 tyrimas: duomenų apdorojimas:
Duomenų nuskaitymas iš failo;
Studentų rūšiavimas į dvi grupes/kategorijas (į atskirus konteinerius);
Surūšiuotų studentų išvedimas į du naujus failus.
Visos programos veikimo laikas.

REZULTATAI.1 : 1 TYRIMAS — Failu kurimo sparta

1000 irasu failo kurimo laikas: 0.00373712
10000 irasu failo kurimo laikas: 0.0206178
100000 irasu failo kurimo laikas: 0.112169
1000000 irasu failo kurimo laikas: 0.895016
10000000 irasu failo kurimo laikas: 9.04963

2 TYRIMAS - Duomenu apdorojimas
| Failo dydis:                       | 1000        | 10000     | 100000   | 1000000  | 10000000 |
|------------------------------------|-------------|-----------|----------|----------|----------|
| Failo nuskaitymo laikas(s):        | 0.0016515   | 0.0165995 | 0.100474 | 0.964666 | 10.647   |
| Studentų skirstymo laikas(s):      | 0.000661208 | 0.0110059 | 0.050126 | 0.503981 | 4.96271  |
| Įrašymo į failus laikas(s):        | 0.00734433  | 0.0344782 | 0.222286 | 2.22069  | 25.1476  |
| Visos programos veikimo laikas(s): | 0.00967396  | 0.062123  | 0.37293  | 3.68938  | 40.7573  |
