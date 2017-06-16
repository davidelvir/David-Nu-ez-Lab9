#include "Usuario.h"
#include "Cliente.h"
#include "Administrador.h"
#include "Carro.h"
#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <sstream>
#include <fstream>

using namespace std;

bool menuAdmin(vector<Carro*>&);
bool menuCliente(vector<Carro*>&);
void ListarCarros(vector<Carro*>&);
void ListarCarros2(vector<Carro*>&);
void guardarUsuarios(vector<Usuario*>&);

int main(){

	bool vivo = true;
	vector<Usuario*>usuarios;
	vector<Carro*>carros;
  //prueba
	Usuario* prueba = new Administrador("juan","hola","jefe","2234");
	usuarios.push_back(prueba);
	while(vivo){
		int op;
		cout<<"------Menu------"<<endl;
		cout<<"1. Crear usuario"<<endl;
		cout<<"2. Log in"<<endl;
		cout<<"3. Guardar"<<endl;
		cout<<"4. Guardar y salir"<<endl;
		cout<<"5. Listar"<<endl;
		cin>>op;
		switch(op){
			case 1:{
				int op2;
				cout<<"------Menu Creacio de Usuario------"<<endl;
				cout<<"1. Administrador"<<endl;
				cout<<"2. Cliente"<<endl;
				cin>>op2;
				switch(op2){
					case 1:{
						string nombre;
						string password;
						string puesto;
						string numSS;
						cout<<"Ingrese el nombre de usuario: ";
						cin>>nombre;
						cout<<"Ingrese la contraseña: ";
						cin>>password;
						cout<<"Ingrese el puesto en la empresa: ";
						cin>>puesto;
						cout<<"Ingrese el numero de seguro social: ";
						cin>>numSS;

						Usuario* tem = new Administrador(nombre,password,puesto,numSS);
						usuarios.push_back(tem);
						break;
					}
					case 2:{
						string nombre;
						string password;
						string membresia;
						int opMem;

						cout<<"Ingrese el nombre de usuario: ";
						cin>>nombre;
						cout<<"Ingrese la contraseña: ";
						cin>>password;
						cout<<"Elija el tipo de membresia: "<<endl;
						cout<<"1. Normal"<<endl<<"2. Gold"<<endl<<"3. Platinum"<<endl;
						cin>>opMem;
						if(opMem==1){
							membresia = "Normal";
						}
						if(opMem==2){
							membresia = "Gold";
						}
						if(opMem==3){
							membresia = "Platinum";
						}
						Usuario* tem = new Cliente(nombre,password,membresia);
						usuarios.push_back(tem);
						break;
					}

        }//fin switch creacion
        break;
    }
    case 2:{

    	string temUser;
    	string temPass;
    	cout<<"Ingrese el nombre de usuario: ";
    	cin>>temUser;
    	for(int i=0;i<usuarios.size();i++){
    		if(temUser.compare(usuarios[i]->getNombre())==0){
    			cout<<"Ingrese su contraseña: ";
    			cin>>temPass;
    			if(temPass.compare(usuarios[i]->getPassword())==0){
    				//Usuario* temp = usuarios[i];
    				if(dynamic_cast<Administrador*>(usuarios[i])){
    					//menu admin
    					//cout<<"Administrador"<<endl;
    					//bool Admin = true;
    					while(menuAdmin(carros)){}
    						break;
    				}
    				if(dynamic_cast<Cliente*>(usuarios[i])){
    					//menu cliente
    					//cout<<"Cliente"<<endl;
    					while(menuCliente(carros)){}
    						break;
    				}
    			}else{
    				cout<<"Contraseña equivocada !"<<endl;
    				break;
    			}
    		}
    	}
    	break;
    }
    case 3:{
    	guardarUsuarios(usuarios);
    	break;

    }
    case 4:{

    }
    case 5:{
    	cout<<"Personas: "<<endl;
    	for (int i = 0; i < usuarios.size(); ++i){
    		cout<<"Nombre de usuario: "<<usuarios[i]->getNombre()<<endl;
    		cout<<"Password: "<<usuarios[i]->getPassword()<<endl;

    	}
    	cout<<"Carros: "<<endl;
    	ListarCarros(carros);
    	break;
    }
    }//fin switch menu
  }//fin while

}
bool menuCliente(vector<Carro*>& carros){
	bool volver;
	int op;
	cout<<"------Menu Cliente------"<<endl;
	cout<<"1. Rentar un carro"<<endl;
	cout<<"2. Guardar factura"<<endl;
	cout<<"3. Salir"<<endl;
	cin>>op;
	switch(op){
		case 1:{
			int rentar;
			cout<<"Elija el carro que desea alquilar: "<<endl;
			ListarCarros2(carros);
			cin>>rentar;
			carros[rentar]->Rentar();
			volver = true;
			break;
		}
		case 2:{
			volver = true;
			break;
		}
		case 3:{
			volver = false;
			break;
		}

	}
	return volver;
}
bool menuAdmin(vector<Carro*>& carros){
	bool volver;
	int op;
	cout<<"------Menu de Administrador------"<<endl;
	cout<<"1. Agregar auto"<<endl;
	cout<<"2. Eliminar auto"<<endl;
	cout<<"3. Salir"<<endl;
	cin>>op;
	switch(op){
		case 1:{
			string placa;
			string marca;
			string modelo;
			int year;
			double precio;
			bool rentado;
			cout<<"Ingrese la marca del carro: ";
			cin>>marca;
			cout<<"Ingrese el modelo del carro: ";
			cin>>modelo;
			cout<<"Ingrese el año del carro: ";
			cin>>year;
			cout<<"Ingrese el precio: ";
			cin>>precio;
			placa = "aaaa";
			Carro* temCarro = new Carro(placa,marca,modelo,year,precio);
			carros.push_back(temCarro);
			volver =  true;
			break;
			
		}
		case 2:{
			int elim;
			cout<<"Elija el carro que desea eliminar: "<<endl;
			ListarCarros(carros);
			cin>>elim;
			carros.erase(carros.begin()+elim);
			volver = true;
			break;
		}
		case 3:{
			volver = false;
			break;
		}
	}
	return volver;
}

void ListarCarros(vector<Carro*>& carros){
	if(carros.size()==0){
		cout<<"NO HAY CARROS CREADOS!"<<endl;
	}else{
		for (int i = 0; i < carros.size(); ++i)
		{
			cout<<"Carro: "<<i<<" ||Marca: "<<carros[i]->getMarca()<<" ||Modelo: "<<carros[i]->getModelo()<<" ||Rentado: "<<carros[i]->getRentado()<<endl;
		}
	}
}
void ListarCarros2(vector<Carro*>& carros){
	if(carros.size()==0){
		cout<<"NO HAY CARROS CREADOS!"<<endl;
	}else{
		for (int i = 0; i < carros.size(); ++i)
		{
			if(!carros[i]){
				cout<<"Carro: "<<i<<" ||Marca: "<<carros[i]->getMarca()<<" ||Modelo: "<<carros[i]->getModelo()<<" ||Rentado: "<<carros[i]->getRentado()<<endl;
			}
		}
	}
}
void guardarUsuarios(vector<Usuario*>& usuarios){

	ofstream archivo;
	string rutaAdmin = "Administrador.txt";
	string rutaCliente = "Cliente.txt";
	for (int i = 0; i < usuarios.size(); ++i)
	{
		ofstream archivo;
		string rutaAdmin = "Administrador.txt";
		string rutaCliente = "Cliente.txt";
		if(dynamic_cast<Administrador*>(usuarios[i])){
			Administrador* tem1 = dynamic_cast<Administrador*>(usuarios[i]);
			archivo.open(rutaAdmin.c_str());
			archivo<<usuarios[i]->getNombre()<<" "<<usuarios[i]->getPassword()<<" "<<tem1->getCargo()<<" "<<tem1->getNumSS()<<endl;
			archivo.close();
		}
		if(dynamic_cast<Cliente*>(usuarios[i])){
			Cliente* tem2 = dynamic_cast<Cliente*>(usuarios[i]);
			archivo.open(rutaCliente.c_str());
			archivo<<usuarios[i]->getNombre()<<" "<<usuarios[i]->getPassword()<<endl;
			archivo.close();
		}
	}
	archivo.close();
}