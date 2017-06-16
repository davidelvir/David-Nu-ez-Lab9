#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "Usuario.h"
#include <string>

using namespace std;

class Administrador : public Usuario{

  public: 
    Administrador();
    Administrador(string,string,string,string);
    string cargo;
    string numSS;
    void virtual LaVidaMeOdia();

    string getCargo();
    string getNumSS();
};

#endif
