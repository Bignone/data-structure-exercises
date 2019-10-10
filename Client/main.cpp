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

int main()
{
   cout << "***** Client program *****" << endl;

   Client c1;
   c1.write();

   char dni[10] = "12345678A";
   char name[50] = "Eduardo";
   Client c2(dni, name, 100.10, 666666666);
   c2.write();

   test_generate_random_dni();
   test_generate_random_name();
   test_generate_random_balance();
   test_generate_random_tlf();

    //Result
    cout << "***** END *****" << endl;

    return 0;
}
