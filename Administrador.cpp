#include "Administrador.h"

Administrador::Administrador(){}

Administrador::Administrador(string nombre,string password,string cargo,string numss):Usuario(nombre,password){
  this->cargo = cargo;
  this->numSS = numss;
}
void Administrador::LaVidaMeOdia(){


}
string Administrador::getCargo(){
	return cargo;
}
string Administrador::getNumSS(){
	return numSS;
}

