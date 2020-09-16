#include <iostream>
using namespace std;

class Carro{
	private:
		string modelo;
		string color;
		string matricula;
		int numeropuertas;
		int numeropasajeros;
		string aire;
	public: 
		Carro(string _modelo, string _color, string _matricula, int _numeropuertas, int _numeropasajeros, string _aire);
	    Carro(string _modelo, string _color, string _matricula, string _aire);
		void setmodelo(string _modelo);
		string getmodelo();
		
		void setcolor(string _color);
		string getcolor();
		
		void setmatricula(string _matricula);
		string getmatricula();
		
		void setnumeropuertas(int _numeropuertas);
		int getnumeropuertas();
		
		void setnumeropasajeros(int _numeropasajeros);
		int getnumeropasajeros();
		
		void setaire(string _aire);
		string getaire();
		
		void mostrarmodelo();
		void mostrarcolor();
		void mostrarmatricula();
		void mostrarnumeropuertas();
		void mostrarnumeropasajeros();
		void mostraraire();
	
};

Carro:: Carro(string _modelo, string _color, string _matricula, string _aire){
	modelo = _modelo;
	color = _color;
	matricula =  _matricula;
	 aire = _aire;
}

Carro::Carro(string _modelo, string _color, string _matricula, int _numeropuertas, int _numeropasajeros, string _aire){
	
	modelo = _modelo;
	color = _color;
	matricula =  _matricula;
	numeropuertas = _numeropuertas;
    numeropasajeros = _numeropasajeros;
    aire = _aire;
	
}

void Carro::setmodelo(string _modelo){
	modelo = _modelo;
}
string Carro::getmodelo(){
	return modelo;
}
		
void Carro::setcolor(string _color){
	color = _color;
}
string Carro::getcolor(){
	return color;
}
		
void Carro::setmatricula(string _matricula){
	matricula = _matricula;
}
string Carro::getmatricula(){
	return matricula;
}
		
void Carro::setnumeropuertas(int _numeropuertas){
	numeropuertas = _numeropuertas;
}
int Carro::getnumeropuertas(){
	return numeropuertas;
}
		
void Carro::setnumeropasajeros(int _numeropasajeros){
	numeropasajeros = _numeropasajeros;
}
int Carro::getnumeropasajeros(){
	return numeropasajeros;
}
		
void Carro::setaire(string _aire){
	aire = _aire;
}
string Carro::getaire(){
	return aire;
}
void Carro::mostrarmodelo(){
	cout<<"el modelo del auto es "<<modelo<<endl;
	}
void Carro::mostrarcolor(){
	cout<<"el color del carro es: "<<color<<endl;	
	}
void Carro::mostrarmatricula(){
	cout<<"la matricula del carro es: "<<matricula<<endl;
	}
void Carro::mostrarnumeropuertas(){
	cout<<"el numero de puertas en el carro es: "<<numeropuertas<<endl;
	}
void Carro::mostrarnumeropasajeros(){
	cout<<"el numero de pasajeros que puede llevar el carro es: "<<numeropasajeros<<endl;
	}
void Carro::mostraraire(){
	cout<<"el vehiculo posee aire acondicionado: "<<aire<<endl;
	}

int main(int argc, char** argv) {
	string a,b,c,f;
	int d,e,g;
	
	for(int i=0; i<1; i++){
	
cout<<"bienvenido al concesionario virtual utp"<<endl;
cout<<"porfavor ingrese los siguientes datos"<<endl;
cout<<"modelo del vehiculo"<<endl;
cin>>a;
cout<<"color del vehiculo"<<endl;
cin>>b;
cout<<"matricula del vehiculo"<<endl;
cin>>c;
cout<<"ingrese el numero de puertas que tiene el vehiculo"<<endl;
cin>>d;
cout<<"el numero de pasajeros que soporta el vehiculo"<<endl;
cin>>e;
cout<<"indique si el aire acondicionado funciona o no"<<endl;
cin>>f;
Carro carro1 = Carro(a,b,c,d,e,f);

carro1.setmodelo(a);
carro1.setcolor(b);
carro1.setmatricula(c);
carro1.setaire(f);
carro1.setnumeropasajeros(e);
carro1.setnumeropuertas(d);

carro1.mostrarmodelo();
carro1.mostrarcolor();
carro1.mostrarmatricula();
carro1.mostrarnumeropuertas();
carro1.mostrarnumeropasajeros();
carro1.mostraraire();


cout<<"si desea cambiar algo ingrese 1, de lo contrario presione cualquie boton"<<endl;
cin>>g;

if(g == 1){
	i= i-1;
}
}
	return 0;
}

