#ifndef CARRO_H
#define CARRO_H
#include <string>

using namespace std;

class Carro{

  public:
    Carro();
    Carro(string,string,string,int,double);
    string placa;
    string marca;
    string modelo;
    int year;
    double precio;
    bool rentado;

    void Rentar();
    
    //getters
    string getPlaca();
    string getMarca();
    string getModelo();
    int getYear();
    double getPrecio();
    bool getRentado();
};

#endif
