#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using namespace std;

class Usuario{
  public:

    Usuario();
    Usuario(string,string);
    void virtual LaVidaMeOdia();
    string nombre;
    string password;

    //getters
    string getNombre();
    string getPassword();
    
};

#endif
