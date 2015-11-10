#include <iostream>
#include <complex>

using namespace std;

int main(){

  
  int Nmax= 400;
  double tol = 10E-8;
  double err = 1;
  
  int i;
  complex<double> zlimit;
  complex<double> z0;
  
  for (double re=-2; re<=2; re+= 0.01){
    for (double im= -2; im<= 2; im+=0.01){
      
      z0 = complex<double>(re, im);
      err= 1;
      i = 0;
      while(i <= Nmax && err >= tol){
	zlimit = z0 - (pow(z0,3)-1.0)/(3.0*pow(z0,2));
	
	err = abs(zlimit- z0);
	z0 = zlimit;
	i++;
      }
      //print current values to consol
      cout << re << "\t" << im << "\t" << i << endl;
    }
  }

  return 0;
}
