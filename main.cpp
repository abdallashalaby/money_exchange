#include <iostream>
# include "stdlib.h"
using namespace std;
void print_error_message(){
    cout << "invalid input, please try again!" << endl;
}
double verify_amount(string amount){
    double x;
    try {
        x = stod(amount);
    }
    catch (...) {
        print_error_message();
        return -1;
    }
    return x;
}
char verify_currency_type(char choice){
    if(choice != '$' && choice != 'D' && choice != 'A' && choice != 'S'){
        print_error_message();
        choice = 'z';
    }
    return choice;
}
void usd_to_s(int amount){
    amount *= 7.3;
    cout << amount << " Shekel" << endl;
}
void s_to_usd(int amount){
    amount /= 7.3;
    cout << amount << " Dollar" << endl;
}
void d_to_s(int amount){
    amount *= 5;
    cout << amount << " Shekel" << endl;
}
void s_to_d(int amount){
    amount /= 5;
    cout << amount << " Deenar" << endl;
}
void d_to_usd(int amount){
    amount *= 1.3;
    cout << amount << " Dollar" << endl;
}
void usd_to_d(int amount){
    amount /= 1.3;
    cout << amount << " Deenar" << endl;
}
void all(char currency_type, double amount) {
    if (currency_type == '$') {
        usd_to_s(amount);
        usd_to_d(amount);
    } else if (currency_type == 'D') {
        d_to_usd(amount);
        d_to_s(amount);
    } else {
        s_to_usd(amount);
        s_to_d(amount);
    }
}

string currency_name(char curr){
    string name;
    if(curr == '$'){
        name = "Dollar";
    }
    else if(curr == 'D'){
        name = "Deenar";
    }
    else{
        name = "Shekel";
    }
    return name;
}
char let_me_convert(){
    char currency_from, currency_to;
    double amount;
    string amount_input;
    system("clear");
    do {
        cout << " Press $ to convert from Dollar" << endl << " Press D to convert from Deenar" << endl << " Press S to convert from Shekel" << endl;
        cin >> currency_from;
        currency_from = verify_currency_type(currency_from);
    }while(currency_from == 'z');

    system("clear");
    do {
        cout << "enter the amount of money : " << endl;
        cin >> amount_input;
        amount = verify_amount(amount_input);

    }while(amount <= 0);

    system("clear");
    cout << " Press $ to convert to Dollar" << endl << " Press D to convert to Deenar" << endl << " Press S to convert to Shekel" << endl << " Press A to convert to all currencies $DS" << endl;
    do {
        cout << "enter the currency that you want to convert to : " << endl;
        cin >> currency_to;
        currency_to = verify_currency_type(currency_to);
    } while(currency_to == 'z');

    system("clear");

    cout << "you asked to convert " << amount << " " << currency_name(currency_from) << " , that will be: " << endl;

    if(currency_from == '$' && currency_to == 'S')
        usd_to_s(amount);
    else if(currency_from == 'S' && currency_to == '$')
        s_to_usd(amount);

    else if (currency_from == 'D' && currency_to == 'S')
        d_to_s(amount);
    else if (currency_from == 'S' && currency_to == 'D')
        s_to_d(amount);

    else if (currency_from == 'D' && currency_to == '$')
        d_to_usd(amount);
    else if (currency_from == '$' && currency_to == 'D')
        usd_to_d(amount);

    else if (currency_to == 'A')
        all(currency_from, amount);
    else
        print_error_message();
    return 0;
}
char display(){
    char input1, input2;
    cout << "Press C or c to continue" << endl << "Press E or e to stop running" << endl;
    cin >> input1;

    return input1;
}
int main() {
    system("clear");
    int i = display();
    while(i != 'e' and i != 'E') {
        if (i == 'C' or i == 'c') {
            let_me_convert();
        } else {
            print_error_message();
        }
        i = display();
    }
//    if(typeid(1.023023) == typeid(double)){
//        cout << "Hola\n";
//        x = stod("");
//        cout << x;
//    }

//    try {
//        x = stod("");
//    }
//    catch (...) {
//        cout << "Exception Caught \n";
//    }
    return 0;
}
