#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include <string>

using namespace std;

class Cliente : public Usuario{
  public:
    Cliente();
    Cliente(string,string,string);
    string membresia;
    void virtual LaVidaMeOdia();
    string getMembresia();
};

#endif
