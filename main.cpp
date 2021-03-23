//Сoffee_machine_LEI700/Servise_menu/Version_1.0
#include <iostream>
using namespace std;

#define PIN 1234
#define ATTEMPT 3

bool checkPin(int pin);
bool inputPin();
void addingCups();
void withdrawalOfProceeds();
void printOnConsole(string massage);
void printOnConsole(string massage, int parametr);

int pushButton = 0, cupsAdd = 0;
int proceeds = 100;

int main()
{
    printOnConsole("\t1. Back to Main menu \n\t2. Input PIN");
    printOnConsole("\n\nPlease select: ");
    cin >> pushButton;
    
    if(pushButton == 1) {
        return 0;
    } else if(inputPin()) {
        
        while (true) {
            printOnConsole("\nWelcome to service menu: \n");
            printOnConsole("\n\t1 – Add cups \n\t2 – Withdrawal of proceeds \n\t3 – Back to Main Menu");
            printOnConsole("\n\nPlease select: ");
            cin >> pushButton;
        
            if(pushButton == 1) {
                addingCups();
            } else if (pushButton == 2) {
                withdrawalOfProceeds();
            } else if(pushButton == 3){
                return 0;
            }
        }
        
    } else {
        printOnConsole("\nMachine is blocked!\n");
    }
    
    return 0;
}

bool checkPin (int pin) {
    if(pin == PIN) {
        return true;
    }
    return false;
}

bool inputPin() {
    int pin = 0, attempt = 1;
    
    printOnConsole("\nEnter pin: ");
    cin >> pin;
    
    while(!checkPin(pin) and attempt < ATTEMPT) {
        printOnConsole("Pin is incorrect. Try again: ");
        cin >> pin;
        attempt++;
    }
    if(checkPin(pin)) {
        return true;
    }
    return false;
}

void addingCups() {
    int cups = 0;
    
    printOnConsole("\nHow many cups are you adding? Cups adding are: ");
    cin >> cupsAdd;
    cups = cupsAdd;
    printOnConsole("\n\t1 – Cups are: ", cups);
}

void withdrawalOfProceeds () {
    printOnConsole("\n\t<proceeds> BYN were given away\n");
    proceeds = 0;
    printOnConsole("\n\t2 - Proceeds are BYN: ", proceeds);
}

void printOnConsole(string massage) {
    cout << massage;
}

void printOnConsole(string massage, int parametr) {
    cout << massage << parametr;
}
