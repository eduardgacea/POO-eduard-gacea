#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>
#include <iomanip>
#include <typeinfo>

#define MAX_NAME_SIZE 99

using namespace std;

class Account {
  private:
    char* username;
    float balance = 0;

  public:
    Account(const char* desiredName) {
      int size = strlen(desiredName) + 1;
      username = new char[size];
      strcpy_s(username, size, desiredName);
    };

    ~Account() {
      delete[] username;
    };

    char* getUsername() {
      return username;
    }

    float getBalance() {
      return balance;
    }

    void deposit(float depositAmount) {
      balance += max(0.0f, depositAmount);
    }

    void withdraw(float withdrawAmount) {
      balance -= max(0.0f, withdrawAmount);
    }
};

template<typename T>
void validateInput(const char* message, T& variable);

void printMenu();
void deleteAccount(Account*& a);

int main() {
  cout << fixed << setprecision(2);

  bool running = true;
  int selectedInstruction;
  float amount;
  char desiredName[MAX_NAME_SIZE + 1];
  Account* account = nullptr;

  printMenu();

  do {
    validateInput("YOUR OPTION: ", selectedInstruction);

    switch (selectedInstruction) {
      case 1:
        printMenu();
        break;
      case 2:
        if (account) {
          cout << "YOU ALREADY HAVE AN ACCOUNT!" << endl;
        } else {
          validateInput("ENTER YOUR NAME: ", desiredName);
          account = new Account(desiredName);
          cout << "ACCOUNT WITH USERNAME " << desiredName << " CREATED" << endl;
        }
        break;
      case 3:
        if (account)
          cout << "YOUR BALANCE IS: " << account->getBalance() << " RON" << endl;
        else
          cout << "NO ACCOUNT FOUND!" << endl;
        break;
      case 4:
        if (account)
          cout << "YOUR ACCOUNT USERNAME IS: " << account->getUsername() << endl;
        else
          cout << "NO ACCOUNT FOUND!" << endl;
        break;
      case 5:
        if (account) {
          validateInput("ENTER DEPOSIT AMOUNT: ", amount);
          account->deposit(amount);
          cout << "DEPOSITED " << amount << " RON" << endl;
        } else {
          cout << "NO ACCOUNT FOUND!" << endl;
        }
        break;
      case 6:
        if (account) {
          validateInput("ENTER WITHDRAW AMOUNT: ", amount);
          if (amount > account->getBalance()) {
            cout << "INSUFFICIENT FUNDS!" << endl;
          } else {
            account->withdraw(amount);
            cout << "WITHDREW " << amount << " RON" << endl;
          }
        } else {
          cout << "NO ACCOUNT FOUND!" << endl;
        }
        break;
      case 7:
        if (account) {
          deleteAccount(account);
          cout << "ACCOUNT DELETED!" << endl;
        } else {
          cout << "NO ACCOUNT FOUND!" << endl;
        }
        break;
      case 0:
        running = false;
        break;
      default:
        cout << "INVALID OPTION" << endl << endl;
        break;
    }
  } while (running);

  return 0;
}

void printMenu() {
  cout << endl << "=== SELECT OPTION ===" << endl;
  cout << "01 SHOW MENU" << endl;
  cout << "02 OPEN ACCOUNT" << endl;
  cout << "03 VIEW BALANCE" << endl;
  cout << "04 VIEW USERNAME" << endl;
  cout << "05 DEPOSIT AMOUNT" << endl;
  cout << "06 WITHDRAW AMOUNT" << endl;
  cout << "07 DELETE ACCOUNT" << endl;
  cout << "00 EXIT" << endl << endl;
}

void deleteAccount(Account*& a) {
  delete a;
  a = nullptr;
}

template<typename T>
void validateInput(const char* message, T& variable) {
  while (true) {
    cout << message;
    cin >> variable;
    if (!cin.fail()) {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      break;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "INVALID! PLEASE ENTER A VALUE OF TYPE (" << typeid(T).name() << ")" << endl;
  }
}