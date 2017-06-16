#include "Cliente.h"

Cliente::Cliente(){}

Cliente::Cliente(string nombre,string password,string membresia):Usuario(nombre,password){
  this->membresia = membresia;
}
void Cliente::LaVidaMeOdia(){


}
string Cliente::getMembresia(){
	return	membresia;
}
