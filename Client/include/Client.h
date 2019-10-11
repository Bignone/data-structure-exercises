#ifndef CLIENT_H
#define CLIENT_H

class Client
{
    public:
        // Contructors
        Client();
        Client(char dni[], char name[], double balance, long tlf);
        // Functions
        void write();
        void read();
        void getDni(char dni[]);
        void getName(char name[]);
        long getTlf();
        double getBalance();


    private:
        char dni[10];
        char name[8];
        double balance;
        long tlf;
};

void generate_random_dni(char d[]);
void generate_random_name(char n[]);
double generate_random_balance(double lower_boundd, double upper_boundd);
long generate_random_tlf();

#endif // CLIENT_H
