#include <iostream>
#include <cstring>

using namespace std;

class Student {
  private:
    const int id;
    static int nrStudenti;
    
    char* nume;
    char* prenume;
    int anStudiu;
    bool buget;
    int nrNote;
    float* note;
    
  public:
    // constructor fara parametrii
    Student() :id(++nrStudenti) {
      const char* numeDefault = "necunoscut";
      
      this->nume = new char[strlen(numeDefault) + 1];
      strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      
      this->prenume = new char[strlen(numeDefault) + 1];
      strcpy_s(this->prenume, strlen(numeDefault) + 1, numeDefault);
      
      this->anStudiu = 1;
      this->buget = false;
      
      this->nrNote = 0;
      this->note = nullptr;
    }

    // constructor cu parametrii
    Student(const char* nume, const char* prenume, int anStudiu, bool buget, int nrNote, float* note) :id(++nrStudenti) {
      const char* numeDefault = "necunoscut";
      
      if(nume == nullptr || strlen(nume) == 0) {
        this->nume = new char[strlen(numeDefault) + 1];
        strcpy_s(this->nume, strlen(numeDefault) + 1, numeDefault);
      } else {
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
      }
      
      if(prenume == nullptr || strlen(prenume) == 0) {
        this->prenume = new char[strlen(numeDefault) + 1];
        strcpy_s(this->prenume, strlen(numeDefault) + 1, numeDefault);
      } else {
        this->prenume = new char[strlen(prenume) + 1];
        strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
      }
      
      this->anStudiu = anStudiu > 0 ? anStudiu : 1;
      this->buget = buget;
      
      this->nrNote = nrNote > 0 ? nrNote : 0;
      
      if(this->nrNote == 0) {
        this->note = nullptr;
      } else {
        this->note = new float[this->nrNote];
        for(int i = 0 ; i < this->nrNote ; i++) {
          this->note[i] = note[i];
        }
      }
    }

    // constructor de copiere
    Student(const Student& copie) :id(++nrStudenti) {
      if(copie.nume == nullptr) this->nume = nullptr;
      else {
        this->nume = new char[strlen(copie.nume) + 1];
        strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
      }
      if(copie.prenume == nullptr) this->prenume = nullptr;
      else {
        this->prenume = new char[strlen(copie.prenume) + 1];
        strcpy_s(this->prenume, strlen(copie.prenume) + 1, copie.prenume);
      }

      this->anStudiu = copie.anStudiu;
      this->buget = copie.buget;

      this->nrNote = copie.nrNote;

      if(this->nrNote == 0) this->note = nullptr;
      else {
        this->note = new float[this->nrNote];
        for(int i = 0 ; i < this->nrNote ; i++) {
          this->note[i] = copie.note[i];
        }
      }
    }

    // supraincarcare operator de asignare
    Student& operator=(const Student& copie) {
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
      
      if(this->prenume != nullptr) {
        delete[] this->prenume;
        this->prenume = nullptr;
      }
      if(copie.prenume != nullptr) {
        this->prenume = new char[strlen(copie.prenume) + 1];
        strcpy_s(this->prenume, strlen(copie.prenume) + 1, copie.prenume);
      } else {
        this->prenume = nullptr;
      }
      
      this->anStudiu = copie.anStudiu;
      this->buget = copie.buget;
      this->nrNote = copie.nrNote;

      if(this->note != nullptr) {
        delete[] this->note;
        this->note = nullptr;
      }
      if(nrNote == 0) this->note = nullptr;
      else {
        this->note = new float[this->nrNote];
        for(int i = 0 ; i < this->nrNote ; i++) {
          this->note[i] = copie.note[i];
        }
      }

      return *this;
    }

    // destructor
    ~Student() {
      if(this->nume != nullptr) delete[] this->nume;
      if(this->prenume != nullptr) delete[] this->prenume;
      if(this->note != nullptr) delete[] this->note;
    }

    // getters
    const char* getNume() {
      return this->nume;
    }

    const char* getPrenume() {
      return this->prenume;
    }

    int getAnStudiu() {
      return this->anStudiu;
    }

    bool getBuget() {
      return this->buget;
    }

    int getNrNote() {
      return this->nrNote;
    }

    const float* getNote() {
      return this->note;
    }

    // setters
    void setNume(const char* nume) {
      if(strlen(nume) > 0) {
        if(this->nume != nullptr) delete[] this->nume;
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
      }
    }

    void setPrenume(const char* prenume) {
      if(strlen(prenume) > 0) {
        if(this->prenume != nullptr) delete[] this->prenume;
        this->prenume = new char[strlen(prenume) + 1];
        strcpy_s(this->prenume, strlen(prenume) + 1, prenume);
      }
    }

    void setAnStudiu(int anStudiu) {
      this->anStudiu = anStudiu;
    }

    void setBuget(bool buget) {
      this->buget = buget;
    }

    void setNote(int nrNote, const float* note) {
      if(nrNote > 0) {
        this->nrNote = nrNote;
        if(this->note != nullptr) delete[] this->note;
        this->note = new float[nrNote];
        for(int i = 0 ; i < this->nrNote; i++) {
          this->note[i] = note[i];
        }
      }
    }

    // metoda calcul medie
    float medie() {
      float s = 0;
      for(int i = 0 ; i < this->nrNote ; i++) s += this->note[i];
      return s/((float) this->nrNote);
    }

    // operator ! pt toggle forma finantare buget/taxa
    bool operator!() {
      return this->buget = this->buget ? false : true;
    }

    // operator < pt compararea mediilor a doi studenti
    bool operator<(Student& s) {
      float m1 = this->medie();
      float m2 = s.medie();
      return m1 < m2;
    }

    // metoda de afisare
    void afisareStudent() {
      cout << "(" << id << ") " << "nume: " << nume << "; prenume: " << prenume << "; an studiu: " << anStudiu << "; forma finantare: " << (buget ? "buget" : "taxa") << endl;
      if(nrNote == 0) return;
      cout << "note: ";
      for(int i = 0 ; i < nrNote - 1 ; i++) {
        cout << note[i] << ", ";
      }
      cout << note[nrNote - 1] << endl;
    }
};

int Student::nrStudenti = 0;

int main() {
  Student s1;
  float noteS2[] = {4.5, 7.0, 9.55};
  Student s2("Popescu", "Ion", 2, false, 3, noteS2);
  Student s3("Ionescu", "Popa", 1, true, 0, nullptr);
  Student s4(s2);
  Student s5;

  s1.afisareStudent();
  s2.afisareStudent();
  s3.afisareStudent();
  s4.afisareStudent();

  s2 = s2;
  s2.afisareStudent();

  s5 = s3;
  s5.afisareStudent();
  
  s5 = s2;
  s5.afisareStudent();

  s1.setNume("Vasile");
  s1.setPrenume("Marius");
  s1.setAnStudiu(3);
  s1.setBuget(true);
  float noteS1[] = {5, 7.5, 8, 3};
  s1.setNote(4, noteS1);

  s1.afisareStudent();

  float noteS6[] = {1.1, 7, 10, 9.5, 4.75};
  Student s6("Tudor", "Maria", 1, false, 5, noteS6);

  int nrNote = s6.getNrNote();
  const float* note = s6.getNote();

  cout << "note s6: ";
  for(int i =  0 ; i < nrNote - 1 ; i++) cout << note[i] << ", ";
  cout << note[nrNote - 1] << "." << endl;

  float medieS1 = s1.medie();
  cout << "medie s1: " << medieS1 << endl;

  s1.afisareStudent();
  !s1;
  s1.afisareStudent();

  if(s1 < s2) {
    cout << "s2 are media mai mare (" << s2.medie() << ")" << endl;
  } else {
    cout << "s1 are media mai mare (" << s1.medie() << ")" << endl ;
  }

  return 0;
}