#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>

using namespace std;

complex<double>comptan(double phi);

int main(){
  
  ofstream out("output.dat");
  ofstream outb("outputb.dat");
  

  // Example how to declare a single complex variable:
  complex<double> c;

  // d = 1 + 2i 
  complex<double> d = complex<double>(1.0, 2.0); 
  
  int N = 100;
  
  double data[N][4];
  double datab[N][4];
  double phi=0;
  double phib = 0;
  complex<double> z= complex<double>(0.0, 0.0);
  complex<double> zb= complex<double>(0.0, 0.0);
  
  //initialize phi_i
  for (int i=0; i<N; i++){
    //compute data
    phi = (2*M_PI/N) *i;
    phib = phi - M_PI;
    z = complex<double>(cos(phi), sin(phi));
    zb = comptan(phib);
    
    //save data
    data[i][0] = phi;
    data[i][1] = real(z);
    data[i][2] = imag(z);
    data[i][3] = abs(z);
    
    datab[i][0] = phib;
    datab[i][1] = real(zb);
    datab[i][2] = imag(zb);
    datab[i][3] = abs(zb);
  }
  
  //write data to file
  for (int i=0; i<N; i++){
    out << data[i][0] << "\t" << data[i][1] << "\t" << 
    data[i][2] << "\t" << data[i][3] << endl;
  }
  
  
  for (int i=0; i<N; i++){
    outb << datab[i][0] << "\t" << datab[i][1] << "\t" << 
    datab[i][2] << "\t" << datab[i][3] << endl;
  }
  

  out.close();
  outb.close();
  
  return 0;
}

complex<double> comptan(double phi){
  complex<double> z;
  complex<double> ii = complex<double>(0.0,1.0);
  z = tan(phi*(1.0+ii));
  return z;
}
