#include <iostream>
#include <cstring>

using namespace std;

class Angajat {
  private:
    const int id;
    static int nrAngajati;
    
    char* nume;
    float salariu;
    int nrCalificative;
    int nrSubalterni;
    float* calificative;
    char** subalterni;

  public:
    // constructor fara parametrii (default)
    Angajat() :id(++nrAngajati) {
      const char* numeDefault = "necunoscut";
      this->nume = new char[strlen(numeDefault) + 1];
      strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      this->salariu = 0;
      this->nrCalificative = 0;
      this->nrSubalterni = 0;
      this->calificative = nullptr;
      this->subalterni = nullptr;
    }

    // constructor cu parametrii
    Angajat(const char* nume, float salariu, int nrCalificative, int nrSubalterni, const float* calificative, const char** subalterni) :id(++nrAngajati) {
      const char* numeDefault = "necunoscut";
      if(nume == nullptr || strlen(nume) == 0) {
        this->nume = new char[strlen(numeDefault) + 1];
        strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      } else {
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
      }

      this->salariu = salariu > 0 ? salariu : 0;
      this->nrCalificative = nrCalificative > 0 ? nrCalificative : 0;
      this->nrSubalterni = nrSubalterni > 0 ? nrSubalterni : 0;

      if(this->nrCalificative > 0) {
        this->calificative = new float[this->nrCalificative];
        for(int i = 0 ; i < this->nrCalificative ; i++) {
          this->calificative[i] = calificative[i];
        }
      } else {
        this->calificative = nullptr;
      }

      if(this->nrSubalterni > 0) {
        this->subalterni = new char*[this->nrSubalterni];
        for(int i = 0 ; i < this->nrSubalterni ; i++) {
          this->subalterni[i] = new char[strlen(subalterni[i]) + 1];
          strcpy_s(this->subalterni[i], strlen(subalterni[i]) + 1, subalterni[i]);
        }
      } else {
        this->subalterni = nullptr;
      }
    }

    // constructor de copiere
    Angajat(const Angajat& copie) :id(++nrAngajati) {
      const char* numeDefault = "necunoscut";
      if(copie.nume == nullptr || strlen(copie.nume) == 0) {
        this->nume = new char[strlen(numeDefault) + 1];
        strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      } else {
        this->nume = new char[strlen(copie.nume) + 1];
        strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
      }

      this->salariu = copie.salariu > 0 ? copie.salariu : 0;
      this->nrCalificative = copie.nrCalificative > 0 ? copie.nrCalificative : 0;
      this->nrSubalterni = copie.nrSubalterni > 0 ? copie.nrSubalterni : 0;

      if(this->nrCalificative > 0) {
        this->calificative = new float[this->nrCalificative];
        for(int i = 0 ; i < this->nrCalificative ; i++) {
          this->calificative[i] = copie.calificative[i];
        }
      } else {
        this->calificative = nullptr;
      }

      if(this->nrSubalterni > 0) {
        this->subalterni = new char*[this->nrSubalterni];
        for(int i = 0 ; i < this->nrSubalterni ; i++) {
          this->subalterni[i] = new char[strlen(copie.subalterni[i]) + 1];
          strcpy_s(this->subalterni[i], strlen(copie.subalterni[i]) + 1, copie.subalterni[i]);
        }
      } else {
        this->subalterni = nullptr;
      }
    }

    // supraincarcare operator =
    Angajat& operator=(const Angajat& copie) {
      if(this == &copie) return *this;

      const char* numeDefault = "necunoscut";
      if(this->nume != nullptr) {
        delete[] this->nume;
        this->nume = nullptr;
      }
      if(copie.nume == nullptr || strlen(copie.nume) == 0) {
        this->nume = new char[strlen(numeDefault) + 1];
        strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      } else {
        this->nume = new char[strlen(copie.nume) + 1];
        strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
      }

      this->salariu = copie.salariu > 0 ? copie.salariu : 0;

      if(this->nrCalificative > 0) {
        delete[] this->calificative;
        this->calificative = nullptr;
      }

      if(this->nrSubalterni > 0) {
        for(int i = 0 ; i < nrSubalterni ; i++) {
          delete[] this->subalterni[i];
          this->subalterni[i] = nullptr;
        }
        delete[] this->subalterni;
        this->subalterni = nullptr;
      }

      this->nrCalificative = copie.nrCalificative > 0 ? copie.nrCalificative : 0;
      this->nrSubalterni = copie.nrSubalterni > 0 ? copie.nrSubalterni : 0;

      if(this->nrCalificative > 0) {
        this->calificative = new float[this->nrCalificative];
        for(int i = 0 ; i < this->nrCalificative ; i++) {
          this->calificative[i] = copie.calificative[i];
        }
      } else {
        this->calificative = nullptr;
      }

      if(this->nrSubalterni > 0) {
        this->subalterni = new char*[this->nrSubalterni];
        for(int i = 0 ; i < this->nrSubalterni ; i++) {
          this->subalterni[i] = new char[strlen(copie.subalterni[i]) + 1];
          strcpy_s(this->subalterni[i], strlen(copie.subalterni[i]) + 1, copie.subalterni[i]);
        }
      } else {
        this->subalterni = nullptr;
      }

      return *this;
    }

    // getters
    char* getNume() {
      return this->nume;
    }

    float getSalariu() {
      return this->salariu;
    }

    int getNrCalificative() {
      return this->nrCalificative;
    }

    int getNrSubalterni() {
      return this->nrSubalterni;
    }

    float* getCalificative() {
      return this->calificative;
    }

    char** getSubalterni() {
      return this->subalterni;
    }

    // setters
    void setNume(const char* nume) {
      const char* numeDefault = "necunoscut";
      if(this->nume != nullptr) {
        delete[] this->nume;
        this->nume = nullptr;
      }

      if(nume == nullptr || strlen(nume) == 0) {
        this->nume = new char[strlen(numeDefault) + 1];
        strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      } else {
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
      }
    }
    
    void setSalariu(float salariu) {
      this->salariu = salariu > 0 ? salariu : 0;
    }
    
    void setCalificative(int nrCalificative, const float* calificative) {
      if(this->calificative != nullptr) {
        this->nrCalificative = 0;
        delete[] this->calificative;
        this->calificative = nullptr;
      }

      if(nrCalificative > 0) {
        this->nrCalificative = nrCalificative;
        this->calificative = new float[this->nrCalificative];
        for(int i = 0 ; i < this->nrCalificative ; i++) {
          this->calificative[i] = calificative[i];
        }
      } else {
        this->nrCalificative = 0;
        this->calificative = 0;
      }
    }
    
    void setSubalterni(int nrSubalterni, const char** subalterni) {
      if(this->subalterni != nullptr) {
        for(int i = 0 ; i < this->nrSubalterni ; i++) {
          delete[] this->subalterni[i];
          this->subalterni[i] = nullptr;
        }
        this->nrSubalterni = 0;
        this->subalterni = nullptr;
      }

      if(nrSubalterni > 0) {
        this->nrSubalterni = nrSubalterni;
        this->subalterni = new char*[this->nrSubalterni];
        for(int i = 0 ; i < this->nrSubalterni ; i++) {
          this->subalterni[i] = new char[strlen(subalterni[i]) + 1];
          strcpy_s(this->subalterni[i], strlen(subalterni[i]) + 1, subalterni[i]);
        }
      } else {
        this->nrSubalterni = 0;
        this->subalterni = nullptr;
      }
    }

    // destructor
    ~Angajat() {
        if(this->nume != nullptr) delete[] this->nume;
        if(this->calificative != nullptr) delete[] this->calificative;
        if(this->subalterni != nullptr) {
          for(int i = 0 ; i < nrSubalterni ; i++) {
            if(this->subalterni[i] != nullptr) delete[] this->subalterni[i];
          }
          if(this->subalterni != nullptr) delete[] this->subalterni;
        }
    }

    // metoda afisare
    void afisare() const {
      cout << "id: " << id << endl;
      cout << "nume: " << nume << endl;
      cout << "salariu: " << salariu << endl;
      if(nrCalificative > 0) {
        cout << "calificative: ";
        for(int i = 0 ; i < nrCalificative - 1 ; i++) {
          cout << calificative[i] << ", ";
        }
        cout << calificative[nrCalificative - 1] << "." << endl;
      }
      if(nrSubalterni > 0) {
        cout << "subalterni: ";
        for(int i = 0 ; i < nrSubalterni - 1 ; i++) {
          cout << subalterni[i] << ", ";
        }
        cout << subalterni[nrSubalterni - 1] << "." << endl;
      }
      cout << endl;
    }

    // supraincarcare operator <<
    friend ostream& operator<<(ostream& consola, const Angajat& angajat) {
      consola << "id: " << angajat.id << endl;
      consola << "nume: " << angajat.nume << endl;
      consola << "salariu: " << angajat.salariu << endl;
      if(angajat.nrCalificative > 0) {
        consola << "calificative: ";
        for(int i = 0 ; i < angajat.nrCalificative - 1 ; i++) {
          consola << angajat.calificative[i] << ", ";
        }
        consola << angajat.calificative[angajat.nrCalificative - 1] << "." << endl;
      }
      if(angajat.nrSubalterni > 0) {
        consola << "subalterni: ";
        for(int i = 0 ; i < angajat.nrSubalterni - 1 ; i++) {
          consola << angajat.subalterni[i] << ", ";
        }
        consola << angajat.subalterni[angajat.nrSubalterni - 1] << "." << endl;
      }
      consola << endl;

      return consola; // pt a permite chaining de mai multe afisari
    }

    // supraincarcare operator >>
    friend istream& operator>>(istream& consola, Angajat& angajat) {
      if(angajat.nume != nullptr) {
        delete[] angajat.nume;
        angajat.nume = nullptr;
      }
      if(angajat.calificative != nullptr) {
        delete[] angajat.calificative;
        angajat.calificative = nullptr;
        angajat.nrCalificative = 0;
      }
      if(angajat.subalterni != nullptr) {
        for(int i = 0 ; i < angajat.nrSubalterni ; i++) {
          delete[] angajat.subalterni[i];
          angajat.subalterni[i] = nullptr;
        }
        angajat.nrSubalterni = 0;
        delete[] angajat.subalterni;
        angajat.subalterni = nullptr;
      }
      cout << endl << "nume: ";
      char buffer[50];
      consola >> buffer;
      angajat.nume = new char[strlen(buffer) + 1];
      strcpy_s(angajat.nume, strlen(buffer) + 1, buffer);
      cout << endl << "salariu: ";
      consola >> angajat.salariu;
      cout << endl << "nr calificative: ";
      consola >> angajat.nrCalificative;
      if(angajat.nrCalificative > 0) {
        angajat.calificative = new float[angajat.nrCalificative];
        for(int i = 0 ; i < angajat.nrCalificative ; i++) {
          cout << endl << "calificativul[" << i << "]: ";
          consola >> angajat.calificative[i];
        }
      } else {
        angajat.calificative = nullptr;
      }

      cout << endl << "nr subalterni: ";
      consola >> angajat.nrSubalterni;
      if(angajat.nrSubalterni > 0) {
        angajat.subalterni = new char*[angajat.nrSubalterni];
        for(int i = 0 ; i < angajat.nrSubalterni ; i++) {
          cout << endl << "subalternul[" << i << "]: ";
          consola >> buffer;
          angajat.subalterni[i] = new char[strlen(buffer) + 1];
          strcpy_s(angajat.subalterni[i], strlen(buffer) + 1, buffer);
        }
      } else {
        angajat.subalterni = nullptr;
      }

      return consola;
    }

    // supraincarcare operator preincrementare
    Angajat operator++() {
      this->salariu = this->salariu + 100;
      return *this;
    }

    // supraincarcare operator postincrementare
    Angajat operator++(int) {
      Angajat copie = *this;
      this->salariu = this->salariu + 100;
      return copie;
    }
};

int Angajat::nrAngajati = 0;

int main() {
  Angajat a1;
  const float calificativeAngajat2[] = {4, 4, 5, 3};
  const char* subalterniAngajat2[] = {"Popescu", "Ionescu", "Vasile"};
  Angajat a2("Tudor", 7900, 4, 3, calificativeAngajat2, subalterniAngajat2);
  Angajat a3(a2);
  Angajat a4;

  a4 = a2;

  a1.afisare();
  a2.afisare();
  a3.afisare();
  a4.afisare();

  a4 = a1;

  a4.afisare();

  a1.setCalificative(4, calificativeAngajat2);
  a1.setSubalterni(3, subalterniAngajat2);

  a1.afisare();

  cout << a2 << a1;

  Angajat a5;
  cout << endl << "introduceti datele angajatului ";
  cin >> a5;
  cout << endl << "angajatul introdus este" << endl;
  cout << a5;

  ++a5;
  cout << "salariu angajat 5 creste cu 100: ";
  cout << a5;

  a5++;
  cout << "salariu angajat 5 creste cu 100: ";
  cout << a5;

  return 0;
}