#include <iostream>
#include <Client.h>
#include <string.h>

using namespace std;

void test_generate_random_tlf(){
    long random_tlf = generate_random_tlf();
    cout << "test random tlf: " << random_tlf << endl;
}

void test_generate_random_balance(){
    double random_balance = generate_random_balance(0, 1000);
    cout << "test random balance: " << random_balance << endl;
}

void test_generate_random_dni(){
    char random_dni[10];
    generate_random_dni(random_dni);
    cout << "test random dni: " << random_dni << endl;
}

void test_generate_random_name(){
    char random_name[10];
    generate_random_name(random_name);
    cout << "test random name: " << random_name << endl;
}

void test_all_randoms(){
    test_generate_random_dni();
    test_generate_random_name();
    test_generate_random_balance();
    test_generate_random_tlf();
}

void test_contructors(){
    cout << "Client 1: default client" << endl;
    Client c1;
    c1.write();

    cout << "Client 2: client from args" << endl;
    char dni[10] = "12345678A";
    char name[50] = "Eduardo";
    Client c2(dni, name, 100.10, 666666666);
    c2.write();

    cout << "Client 3: client from user input args" << endl;
    Client c3;
    c3.read();
}

int main()
{
    cout << "-------------------------------------------------" << endl;
    cout << "           Programa de clientes" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "   1- Rellenar estructura." << endl;
    cout << "   2- Visualizar todo el contenido." << endl;
    cout << "   3- Visualizar nombre y apellidos." << endl;
    cout << "   5- Visualizar DNI." << endl;
    cout << "   6- Visualizar numero de tlf." << endl;
    cout << "   8- Visualizar balance." << endl;
    cout << "   9- Salir del programa." << endl;
    cout << "-------------------------------------------------" << endl;

    Client input_client;
    string option;

    while (option != "9")  {
        cout << "<< Selecciona una opcion >> " << endl;
        getline (cin, option);

        if (option == "1") {
            cout << "1 > Rellenar estructura" << endl;
            input_client.read();

        } else if (option == "2") {
            cout << "2 > Visualizar todo el contenido" << endl;
            input_client.write();

        }
         else if (option == "3") {
            cout << "3 > Visualizar nombre y apellidos" << endl;
            char name[10];
            input_client.getName(name);
            cout << "Name: " << name << endl;

        }
         else if (option == "5") {
            cout << "5 > Visualizar DNI" << endl;
            char dni[10];
            input_client.getDni(dni);
            cout << "DNI: "<< dni << endl;
        }
         else if (option == "6") {
            cout << "6 > Visualizar numero de tlf" << endl;
            cout << "TLF: "<< input_client.getTlf() << endl;

        }
         else if (option == "8") {
            cout << "8 > Visualizar balance" << endl;
            cout << "Balance: "<< input_client.getBalance() << endl;
        }
        else if (option == "9") {
            cout << "9 > Salir del programa" << endl;
            return 0;
        } else {
            cout << "Option not valid" << endl;
        }
    }

    return 0;
}
