#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void valideazaNume(char* &destinatie, const char* sursa) {
  if(sursa == nullptr || strlen(sursa) == 0) {
      const char* numeDefault = "necunoscut";
      destinatie = new char[strlen(numeDefault) + 1];
      strcpy_s(destinatie, strlen(numeDefault) + 1, numeDefault);
    } else {
      destinatie = new char[strlen(sursa) + 1];
      strcpy_s(destinatie, strlen(sursa) + 1, sursa);
    }
}

class Magazin {
  private:
    char* nume;
    int nrProduse;
    char** produse;
    float* preturiProduse;

  public:
    Magazin(const char* nume, int nrProduse, const char** produse, const float* preturiProduse) {
      valideazaNume(this->nume, nume);
      this->nrProduse = nrProduse;
      if(this->nrProduse == 0) {
        this->produse = nullptr;
        this->preturiProduse = nullptr;
      } else {
        this->produse = new char*[nrProduse];
        this->preturiProduse = new float[nrProduse];
        for(int i = 0 ; i < this->nrProduse ; i++) {
          this->produse[i] = new char[strlen(produse[i]) + 1];
          strcpy_s(this->produse[i], strlen(produse[i]) + 1, produse[i]);
          this->preturiProduse[i] = preturiProduse[i];
        }
      }
    }

    ~Magazin() {
      delete[] this->nume;
      this->nume = nullptr;
      for(int i = 0 ; i < this->nrProduse ; i++) {
        delete[] this->produse[i];
        this->produse[i] = nullptr;
      }
      delete[] this->produse;
      this->produse = nullptr;
      delete[] this->preturiProduse;
      this->preturiProduse = nullptr;
    }

    void afisare() {
      cout << "nume: " << nume << endl;
      if(nrProduse == 0) {
        cout << "magazinul nu are momentan produse in stoc";
      } else {
        cout << "produse: " << endl;
        for(int i = 0 ; i < nrProduse; i++) {
          cout << produse[i] << " - " << preturiProduse[i] << " ron" << endl;
        }
      }
    }

    void afisare(const char* numeFisier) {
      if(numeFisier == nullptr || strlen(numeFisier) == 0) {
        cout << "fisierul nu a putut fi creat";
      } else {
        fstream f(numeFisier, ios::app);
        f << "nume: " << nume << endl;
        if(nrProduse == 0) {
          f << "magazinul nu are momentan produse in stoc";
        } else {
          f << "produse: " << endl;
          for(int i = 0 ; i < nrProduse; i++) {
            f << produse[i] << " - " << preturiProduse[i] << " ron" << endl;
          }
        }
        f.close();
      }
    }
};

int main() {
  const char* produse1[] = {"morcovi", "cartofi", "rosii", "castraveti"};
  const float preturi1[] = {1.22, 2.59, 6.48, 8.32};

  Magazin m1("magazin cu legume", 4, produse1, preturi1);

  m1.afisare();
  m1.afisare("text.txt");
  m1.afisare("text.txt");

  return 0;
}