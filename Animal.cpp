#include <iostream>
#include <cstring>

using namespace std;

class Animal {
  private:
    char* nume;
    int varsta;
    float greutate;
    bool carnivor;
    int nrAlimente;
    char** dieta;

  public:
    Animal() {
      const char* numeDefault = "necunoscut";
      this->nume = new char[strlen(numeDefault) + 1];
      strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      this->varsta = 0;
      this->greutate = 0;
      this->carnivor = false;
      this->nrAlimente = 0;
      this->dieta = nullptr;
    }

    Animal(const char* nume, int varsta, float greutate, bool carnivor, int nrAlimente, const char** dieta) {
      const char* numeDefault = "necunoscut";
      if(nume == nullptr || strlen(nume) == 0) {
        this->nume = new char[strlen(numeDefault) + 1];
        strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      } else {
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
      }
      this->varsta = varsta > 0 ? varsta : 0;
      this->greutate = greutate > 0 ? greutate : 0;
      this->carnivor = carnivor;
      this->nrAlimente = nrAlimente > 0 ? nrAlimente : 0;
      if(this->nrAlimente == 0) {
        this->dieta = nullptr;
      } else {
        this->dieta = new char*[this->nrAlimente];
        for(int i = 0 ; i < this->nrAlimente ; i++) {
          this->dieta[i] = new char[strlen(dieta[i]) + 1];
          strcpy_s(this->dieta[i], strlen(dieta[i]) + 1, dieta[i]);
        }
      }
    }

    Animal(const Animal& copie) {
      const char* numeDefault = "necunoscut";
      if(copie.nume == nullptr || strlen(copie.nume) == 0) {
        this->nume = new char[strlen(numeDefault) + 1];
        strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      } else {
        this->nume = new char[strlen(copie.nume) + 1];
        strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
      }
      this->varsta = copie.varsta;
      this->greutate = copie.greutate;
      this->carnivor = copie.carnivor;
      this->nrAlimente = copie.nrAlimente;
      if(this->nrAlimente == 0) {
        this->dieta = nullptr;
      } else {
        this->dieta = new char*[this->nrAlimente];
        for(int i = 0 ; i < this->nrAlimente ; i++) {
          this->dieta[i] = new char[strlen(copie.dieta[i]) + 1];
          strcpy_s(this->dieta[i], strlen(copie.dieta[i]) + 1, copie.dieta[i]);
        }
      }
    }

    Animal& operator=(const Animal& copie) {
      if(this == &copie) return *this;

      if(this->nume != nullptr) {
        delete[] this->nume;
        this->nume = nullptr;
      }
      if(copie.nume != nullptr) {
        this->nume = new char[strlen(copie.nume) + 1];
        strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
      } else {
        this->nume = nullptr;
      }

      this->varsta = copie.varsta;
      this->greutate = copie.greutate;
      this->carnivor = copie.carnivor;
      
      if(this->nrAlimente != 0) {
        for(int i = 0 ; i < nrAlimente ; i++) {
          delete[] this->dieta[i];
          this->dieta[i] = nullptr;
        }
        delete[] this->dieta;
        this->dieta = nullptr;
      }

      this->nrAlimente = copie.nrAlimente;

      if(this->nrAlimente != 0) {
        this->dieta = new char*[this->nrAlimente];
        for(int i = 0 ; i < this->nrAlimente ; i++) {
          this->dieta[i] = new char[strlen(copie.dieta[i]) + 1];
          strcpy_s(this->dieta[i], strlen(copie.dieta[i]) + 1, copie.dieta[i]);
        }
      } else {
        this->dieta = nullptr;
      }

      return *this;
    }

    ~Animal() {
      if(this->nume != nullptr) delete[] this->nume;
      for(int i = 0 ; i < this->nrAlimente ; i++) {
        if(this->dieta[i] != nullptr) delete[] this->dieta[i];
      }
      if(this->dieta != nullptr) delete[] this->dieta;
    }

    void afisare() {
      cout << "Animalul " << nume << ", in varsta de " << varsta << " ani, cu greutatea de " << greutate << " kg";
      if(nrAlimente > 0) {
        cout << ", avand o dieta" << (this->carnivor ? " carnivora" : " ierbivora") << " de urmatoarele alimente: ";
        for(int i = 0; i < nrAlimente - 1; i++) {
          cout << dieta[i] << ", ";
        }
        cout << dieta[nrAlimente - 1] << "." << endl;
      } else {
        cout << endl;
      }
    }
};

int main() {
  Animal a1;
  const char* dietaAnimal2[] = {"insecte", "rozatoare", "peste"};
  Animal a2("urs", 8, 250, true, 3, dietaAnimal2);
  Animal a3(a2);
  Animal a4;

  a1.afisare();
  a2.afisare();
  a3.afisare();
  a4.afisare();

  a4 = a2;

  a4.afisare();

  return 0;
}