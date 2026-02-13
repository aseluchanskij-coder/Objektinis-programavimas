#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::endl;

struct studentas {
    string vardas="A";
    string pavarde="B";
    // int *paz; //jei dinaminis masyvas, tai reikia rodykles
    vector<int> paz; //jei naudojame vektoriu
    int egz;
    double rez;
};
void input (vector<studentas> &grupe){
        
        for (int ii=0;ii<2;ii++){
        studentas A;
        cout<<"Iveskite studento varda ir pavarde: ";
        cin>>A.vardas>>A.pavarde;
        cout<<"Iveskite studento pazymius. Kiek ju bus? ";
        int n, sum=0, vidurkis;
        cin>>n;
        for(int i=0;i<n;i++){
            int temp;
            cout<<"Iveskite "<<i+1<<" pazymi is: "<< n << " : ";
            cin>>temp;
            A.paz.push_back(temp); sum +=temp;
        }
        cout << "Iveskite egzamino bala: ";
        cin >> A.egz;
        A.rez = 0.4 * vidurkis + 0.6 * A.egz;
        grupe.push_back(A);
        A.paz.clear();
        }
    
}
void output (vector<studentas> &grupe){
    int vidurkis, sum=0, n;
    for (const auto& A : grupe){
        sum=0;
        n=A.paz.size();
        for(auto k: A.paz) sum +=k;
        vidurkis = sum/n;
        cout <<left<<setw(10)<<A.vardas<<left<<setw(20)<<A.pavarde<<setw(10)<<vidurkis<<endl;
    }
}
int main() {

    vector<studentas> grupe;
    input(grupe);
    output(grupe);
    
    
   /* for (int ii=0;ii<2;ii++){
    studentas A;
    cout<<"Iveskite studento varda ir pavarde: ";
    cin>>A.vardas>>A.pavarde;
    cout<<"Iveskite studento pazymius. Kiek ju bus? ";
    int n, sum=0, vidurkis;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cout<<"Iveskite "<<i+1<<" pazymi is: "<< n << " : ";
        cin>>temp;
        A.paz.push_back(temp); sum +=temp;
    }
    cout << "Iveskite egzamino bala: ";
    cin >> A.egz;
    A.rez = 0.4 * vidurkis + 0.6 * A.egz;
    grupe.push_back(A);
    A.paz.clear();
    }
    for (const auto& A : grupe){
    vidurkis = sum*1.0/n;
    cout <<left<<setw(10)<<A.vardas<<left<<setw(20)<<A.pavarde;
   // for(auto k: A.paz)   cout<<setw(4)<<k;
    // cout<<setw(10)<<A.rez<<endl;
    } */
    return 0;
}