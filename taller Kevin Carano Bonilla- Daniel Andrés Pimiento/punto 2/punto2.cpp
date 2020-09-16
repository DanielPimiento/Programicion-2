#include <iostream>

using namespace std;


class Serie{
	private:  //Atributos
		string titulo;
		string estado;
		string genero;
		string fecha;
		string anio;
		int temporadas;
	public:   //Metodos
		Serie(string _titulo,int _temporadas,string _estado, string _genero,string _fecha,string _anio);   //Constructor
		Serie(string _titulo, string _genero, string _fecha, string _anio);
		Serie(string _titulo, int _temporadas, string _genero);
		
		void settitulo(string _titulo);
		string gettitulo();
		
		void settemporadas(int _temporadas);
		int gettemporadas();
		
		void setestado(string _estado);
		string getestado();
		
		void setgenero(string _genero);
		string getgenero();
		
		void setfecha(string _fecha);
		string getfecha();
		
		void setanio(string _anio);
		string getanio();
		
		void mostrardatos();
		void mostrardatosA();
		void mostrardatosB();
};

Serie::Serie(string _titulo, int _temporadas, string _genero){   //constructor
	titulo = _titulo;
	temporadas = _temporadas;
	genero = _genero;
}
Serie::Serie(string _titulo, string _genero, string _fecha, string _anio){     //Constructor

    titulo = _titulo;
	genero = _genero;
	fecha = _fecha;
	anio = _anio;
	
}

Serie::Serie(string _titulo, int _temporadas, string _estado, string _genero, string _fecha,string _anio){     //Constructor

    titulo = _titulo;
    estado = _estado;
	temporadas = _temporadas;
	genero = _genero;
	fecha = _fecha;
	anio = _anio;
	
}

//set y gets
void Serie::settitulo(string _titulo){   
	titulo = _titulo;
}

string Serie::gettitulo(){
	return titulo; 
}


void Serie::setestado(string _estado){
	estado= _estado;
}

string Serie::getestado(){
	return estado;
}

void Serie::settemporadas(int _temporadas){
	temporadas = _temporadas;
}

int Serie::gettemporadas(){
	return temporadas; 
}


void Serie::setgenero(string _genero){
	genero = _genero;
}

string Serie::getgenero(){
	return genero;
}


void Serie::setfecha(string _fecha){
	fecha = _fecha;
}

string Serie::getfecha(){
	return fecha;
}


void Serie::setanio(string _anio){
	anio = _anio;
}

string Serie::getanio(){
	return anio;
}

//mostrar datos de las series
void Serie::mostrardatos(){
	cout<<"serie: "<<titulo<<endl;
		cout<<"genero: "<<genero<<endl;
		cout<<"fecha de lanzamiento: "<<fecha<<endl;
		cout<<"anio de emision: "<<anio<<endl;	
}

void Serie::mostrardatosA(){
	cout<<"serie: "<<titulo<<endl;
		cout<<"numero de temporadas: "<<temporadas<<endl;
		cout<<"estado: "<<estado<<endl;
		cout<<"genero: "<<genero<<endl;
		cout<<"fecha de lanzamiento: "<<fecha<<endl;
		cout<<"anio de emision: "<<anio<<endl;	
}
 
 void Serie::mostrardatosB(){
	cout<<"serie: "<<titulo<<endl;
		cout<<"numero de temporadas: "<<temporadas<<endl;
		cout<<"genero: "<<genero<<endl;
}

int main(int argc, char** argv) {
	
	Serie Primera = Serie("Lucifer",2,"emitiendo","adultos","19/5","2001");
Primera.mostrardatosA();
cout<<endl;
	Serie segunda = Serie("young justice", 3, "caricaturas");
	segunda.mostrardatosB();
	return 0;
}
