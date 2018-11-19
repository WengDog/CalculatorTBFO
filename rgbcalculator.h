#include "boolean.h"

#ifndef RGBCALCULATOR_H_INCLUDED
#define RGBCALCULATOR_H_INCLUDED


#define Error -99999.99
#define MathError -99999.98

extern char *P; // Akan digunakan sebagai penunjuk character
extern boolean OpExist; //Menandakan apakah terdapat operator dalam ekspresi


boolean IsNumber(char p);
// Menghasilkan true jika karakter merupakan angka [0..9]

double CheckSymbol(char *p);
// Mengecek apakah bilangan berada dalam tanda kurung, bernilai negatif atau tidak keduanya

double GetNumber();
// Mengubah string angka menjadi double

double OperationA();
// Memproses dan menghasilkan hasil dari penjumlahan atau pengurangan pada bilangan

double OperationB();
// Memproses dan menghasilkan hasil dari perkalian atau pembagian pada bilangan

double CalcExp(double f);
// Memproses perpangkatan pada bilangan

double Expn();
// Menghasilkan hasil perpangkatan bilangan

double CalcPar();
// Memproses dan menghasilkan hasil dari operasi bilangan dalam tanda kurung

void ExpImg(double a, double b);
//mencetak nilai akar bilangan minus

#endif
