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
void guardarCarros(vector<Carro*>&);
void cargarTodo(vector<Usuario*>&,vector<Carro*>&);

int main(){

	bool vivo = true;
	vector<Usuario*>usuarios;
	vector<Carro*>carros;
  //prueba
	cargarTodo(usuarios,carros);
	
	/*Usuario* prueba = new Administrador("juan","hola","jefe","2234");
	usuarios.push_back(prueba);*/
	while(vivo){
		int op;
		cout<<"------Menu------"<<endl;
		cout<<"1. Crear usuario"<<endl;
		cout<<"2. Log in"<<endl;
		cout<<"3. Guardar"<<endl;
		cout<<"4. Salir"<<endl;
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
    	
    	guardarCarros(carros);
    	
    	break;

    }
    case 4:{
    	cout<<"Gracias!!"<<endl;
    	vivo = false;
    	break;

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
	cout<<"2. Salir"<<endl;
	cin>>op;
	switch(op){
		case 1:{
			int rentar;
			cout<<"Elija el carro que desea alquilar: "<<endl;
			ListarCarros2(carros);
			cin>>rentar;
			carros[rentar]->Rentar();
			ofstream archivo;
			string ruta = "Facturas.txt";
			archivo.open(ruta.c_str(),ios::app);
			archivo << "Carro rentado: "<<carros[rentar]->getMarca()<<" "<<carros[rentar]->getModelo()<<" "<<"Precio: "<<carros[rentar]->getPrecio()<<endl;
			archivo.close();
			volver = true;
			break;
		}
		case 2:{
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
			if(!carros[i]->getRentado()){
				cout<<"Carro: "<<i<<" ||Marca: "<<carros[i]->getMarca()<<" ||Modelo: "<<carros[i]->getModelo()<<" ||Rentado: "<<carros[i]->getRentado()<<endl;
			}
		}
	}
}
void guardarUsuarios(vector<Usuario*>& usuarios){

	ofstream archivo;
	string rutaAdmin = "Administrador.txt";
	string rutaCliente = "Cliente.txt";
	archivo.open(rutaAdmin.c_str());
	archivo.open(rutaCliente.c_str());
	for (int i = 0; i < usuarios.size(); ++i)
	{
		ofstream archivo;
		string rutaAdmin = "Administrador.txt";
		string rutaCliente = "Cliente.txt";
		if(dynamic_cast<Administrador*>(usuarios[i])){
			Administrador* tem1 = dynamic_cast<Administrador*>(usuarios[i]);
			archivo.open(rutaAdmin.c_str(),ios::app);
			archivo<<usuarios[i]->getNombre()<<" "<<usuarios[i]->getPassword()<<" "<<tem1->getCargo()<<" "<<tem1->getNumSS()<<endl;
			//archivo.close();
		}
		if(dynamic_cast<Cliente*>(usuarios[i])){
			Cliente* tem2 = dynamic_cast<Cliente*>(usuarios[i]);
			archivo.open(rutaCliente.c_str(),ios::app);
			archivo<<usuarios[i]->getNombre()<<" "<<usuarios[i]->getPassword()<<" "<<tem2->getMembresia()<<endl;
			//archivo.close();
		}
	}
	archivo.close();
}
void guardarCarros(vector<Carro*>& carros){

	ofstream archivo;
	string rutaCarro = "Carros.txt";
	//archivo.open(rutaCarro.c_str());
	archivo.open(rutaCarro.c_str(),ios::app);
	for(int i=0;i<carros.size();i++){
		archivo<<carros[i]->getPlaca()<<" "<<carros[i]->getMarca()<<" "<<carros[i]->getModelo()<<" "<<carros[i]->getYear()<<" "<<carros[i]->getPrecio()<<endl;
	}
	archivo.close();
}

void cargarTodo(vector<Usuario*>& usuarios,vector<Carro*>& carros){

	usuarios.clear();
	carros.clear();

	ifstream archivo1("Administrador.txt");
	ifstream archivo2("Cliente.txt");
	ifstream archivo3("Carros.txt");

	if(archivo1.is_open()){
		while(!archivo1.eof()){
			string nombre;
			string password;
			string puesto;
			string numSS;

			archivo1>>nombre;
			archivo1>>password;
			archivo1>>puesto;
			archivo1>>numSS;

			Usuario* tem = new Administrador(nombre,password,puesto,numSS);
			usuarios.push_back(tem);

			archivo1>>nombre;
			archivo1>>password;
			archivo1>>puesto;
			archivo1>>numSS;
		}
		archivo1.close();
	}
	if(archivo2.is_open()){
		while(!archivo2.eof()){
			string nombre;
			string password;
			string membresia;

			archivo2>>nombre;
			archivo2>>password;
			archivo2>>membresia;

			Usuario* tem = new Cliente(nombre,password,membresia);
			usuarios.push_back(tem);

			archivo2>>nombre;
			archivo2>>password;
			archivo2>>membresia;
		}
		archivo2.close();
	}
	if(archivo3.is_open()){

		while(!archivo3.eof()){
			string placa;
			string marca;
			string modelo;
			int year;
			double precio;
			archivo3>>placa;
			archivo3>>marca;
			archivo3>>modelo;
			archivo3>>year;
			archivo3>>precio;

			Carro* temCarro = new Carro(placa,marca,modelo,year,precio);
			carros.push_back(temCarro);

			archivo3>>placa;
			archivo3>>marca;
			archivo3>>modelo;
			archivo3>>year;
			archivo3>>precio;
			archivo3>>placa;
		}
		archivo3.close();
	}

}