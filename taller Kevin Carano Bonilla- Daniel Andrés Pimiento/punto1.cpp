#include <iostream>
using namespace std;

class Rectangulo{
	private:
		int altura,base;
	
	public:
		Rectangulo(int _altura,int _base );
		void calularparametroyarea(int _altura,int _base);	
		void mostrardatosdelrectangulo(); 
};

Rectangulo::Rectangulo(int _altura,int _base){
	altura=_altura;
	base=_base;
}

void Rectangulo::calularparametroyarea(int _altura,int _base){
	int parametro=(2*_base) + (2*_altura);
	int area= base*altura;
	cout<<"area del rectangulo = "<<area<<endl;
	cout<<"parametro del rectangulo = "<<parametro<<endl;
}
void Rectangulo::mostrardatosdelrectangulo(){
	cout<<"altura del rectangulo = "<<altura<<endl;
	cout<<"base del rectangulo = "<<base<<endl;

}
int main() {
	int _altura,_base,area,parametro;
	cout<<"ingres altura del rectangulo y base del rectangulo"<<endl;
	cin>>_altura;
	cin>>_base;
	Rectangulo Datos = Rectangulo(_altura,_base);
	Datos.calularparametroyarea(_altura,_base);
	Datos.mostrardatosdelrectangulo();
	return 0;
}
