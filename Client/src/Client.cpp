#include <iostream>
#include "Client.h"
#include <string.h>
#include <random>

using namespace std;

Client::Client()
{
    strcpy(dni,"12345678A");
    strcpy(name, "Eduardo");
    balance = generate_random_balance(0, 1000);
    tlf = generate_random_tlf();
}

Client::Client(char d[], char n[], double b, long t) {
    strcpy(dni, d);
    strcpy(name, n);
    balance = b;
    tlf = t;
}


void Client::getDni(char d[]){
    strcpy(d, dni);
}


void Client::getName(char n[]){
    strcpy(n, name);
}

long Client::getTlf(){
    return tlf;
}

double Client::getBalance(){
    return balance;
}

void Client::write() {
    cout << "Client("<<dni<<", "<<name<<", "<<balance<<", "<<tlf<<")" << endl;
}

void Client::read(){
    // input vars
    string input_dni;
    string input_name;
    long input_tlf;
    double input_balance;

    // ask data
    cout << "What's your dni? ";
    getline (cin, input_dni);
    cout << "What's your name and surname? ";
    getline (cin, input_name);
    cout << "What's your tlf? ";
    cin >> input_tlf;
    cout << "What's your balance? ";
    cin >> input_balance;

    // set Client ats
    char input_dni_char[input_dni.length() + 1];
    strcpy(dni, input_dni.c_str());
    char input_name_char[input_name.length() + 1];
    strcpy(name, input_name.c_str());
    balance = input_balance;
    tlf = input_tlf;

    cout << "Inserted client: " << endl;
    write();

}

long generate_random_tlf() {
    long tlf = 600000000;
    long random_step;
    long base = 1;
    for (int i = 1; i < 9; ++i) {
        random_step = (long)rand() % 10;
        random_step = base * random_step;
        tlf = tlf + random_step;
        base = base * 10;
    };
    return tlf;
}

double generate_random_balance(double lower_boundd, double upper_boundd) {
    std::uniform_real_distribution<double> unif(lower_boundd, upper_boundd);
    std::default_random_engine re;
    double a_random_double = unif(re);
    return (double)a_random_double;
}

void generate_random_dni(char d[]){
    char random_dni[10];
    char nums[] = "0123456789";
    char chars[] = "TRWAGMYFPDXBNJZSQVHLCKE";

    for (int i = 0; i < 9; ++i) {
        random_dni[i] = nums[rand() % (sizeof(nums) - 1)];
    };
    int dni_number_rest = (int)random_dni % 16;
    random_dni[9] = chars[dni_number_rest];
    strcpy(d, random_dni);
}

void generate_random_name(char n[]){
    char names[20][10] = {
        "Liam", "Emma","Noah", "Olivia", "William",
        "Ava", "James", "Isabella", "Oliver", "Sophia",
        "Benjamin", "Charlotte", "Elijah", "Mia", "Lucas",
        "Amelia", "Mason", "Harper", "Logan", "Evelyn"
        };
    int name_index = rand() % (20 - 1);
    char random_name[10];
    for (int i = 0; i < 10; ++i) {
        random_name[i] = names[name_index][i];
    }
    strcpy(n, random_name);
}

