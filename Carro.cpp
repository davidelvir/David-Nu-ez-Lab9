#include "Carro.h"

Carro::Carro(){

};

Carro::Carro(string placa,string marca,string modelo,int year,double precio){
  this->marca = marca;
  this->placa = placa;
  this->modelo = modelo;
  this->year = year;
  this->precio = precio;
  rentado = false;
}

void Carro::Rentar(){
  rentado = true;
}

string Carro::getPlaca(){
  return placa;
}

string Carro::getMarca(){
  return marca;
}

string Carro::getModelo(){
  return modelo;
}

int Carro::getYear(){
  return year;
}

double Carro::getPrecio(){
  return precio;
}

bool Carro::getRentado(){
  return rentado;
}
