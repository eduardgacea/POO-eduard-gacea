#include <iostream>
#include <cstring>

using namespace std;

class Produs {
  private:
    const int id;
    static int numarProduse;
    char* nume;
    float pret;
    int stoc;

  public:
    Produs() :id(++numarProduse) {
      const char* numeDefault = "necunoscut";
      this->nume = new char[strlen(numeDefault) + 1];
      strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      this->pret = 0.0;
      this->stoc = 0;
    }

    Produs(const char* nume, float pret, int stoc) :id(++numarProduse) {
      if(nume == nullptr || strlen(nume) == 0) {
        const char* numeDefault = "necunoscut";
        this->nume = new char[strlen(numeDefault) + 1];
        strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      } else {
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
      }
      this->pret = pret;
      this->stoc = stoc;
    }

    Produs(const Produs& copie) :id(++numarProduse) {
      if(copie.nume == nullptr) {
        this->nume = nullptr;
      } else {
        this->nume = new char[strlen(copie.nume) + 1];
        strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
      }
      this->pret = copie.pret;
      this->stoc = copie.stoc;
    }

    void operator=(const Produs& copie) {
      if(this->nume != nullptr) {
        delete[] this->nume;
        this->nume = nullptr;
      };
      if(copie.nume == nullptr) {
        this->nume = nullptr;
      }
      else {
        this->nume = new char[strlen(copie.nume) + 1];
        strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
      }
      
      this->pret = copie.pret;
      this->stoc = copie.stoc;
    }

    ~Produs() {
      if(this->nume != nullptr) delete[] this->nume;
    }

    // getters
    const char* getNume() {
      return this->nume;
    }

    float getPret() {
      return this->pret;
    }

    float getStoc() {
      return this->stoc;
    }

    // setters
    void setNume(const char* nume) {
      if(strlen(nume) > 0) {
        if(this->nume != nullptr) {
          delete[] this->nume;
        }
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
      }
    }

    void setPret(float pret) {
      this->pret = pret;
    }

    void setStoc(int stoc) {
      this->stoc = stoc;
    }

    void afisareProdus() {
      cout << "(" << id << ") " << nume << " - " << pret << "; stoc: " << stoc << endl;
    }
};

int Produs::numarProduse = 0;

int main() {
  Produs p1;
  Produs p2("scaun", 12.99, 100);
  Produs p3("", 2.99, 10);
  Produs p4(p2);
  Produs p5 = p4;
  Produs p6("canapea", 139.49, 14);

  p1.afisareProdus();
  p2.afisareProdus();
  p3.afisareProdus();
  p4.afisareProdus();
  p5.afisareProdus();

  p5 = p6;

  p5.afisareProdus();
  p6.afisareProdus();

  p6.setNume("canapea 3 locuri");

  p5.afisareProdus();
  p6.afisareProdus();

  return 0;
}