#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int calcularSecuenciaAleatoria(void)
{
 int numaleat;
 numaleat=rand()%9999;
 return numaleat;
}

int calculateRandomSecuence(int rango)
{
     int numaleat;
     numaleat=rand()%rango;
     return numaleat;
}

int main()
{
 int i,j = 0;
 int MAX = 5;
 int num=0;
 srand(time(NULL));
 int h, m, s;
 for (i=1;i<4;i++)
 {
     h = calculateRandomSecuence(24);
     m = calculateRandomSecuence(60);
     s = calculateRandomSecuence(60);
     cout << "Secuencia aleatoria: " << i << endl;
     //cout << calcularSecuenciaAleatoria();
     cout << ((h<10)?"0":"") << h << ":" << ((m<10)?"0":"") << m << ":" << ((s<10)?"0":"") << s << endl << endl;
 }
}
