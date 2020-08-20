#include <iostream>
using namespace std;

/*Diseñar un programa que permita el ingreso de 4 números de hasta 3 cifras máximo, que muestre el promedio de los datos e
 indique el número de digitos que tiene cada uno de ellos. En este caso el número que no cumpla con la condición deberá
  mostrarse una alerta de error y pedirse de nuevo por pantalla.*/
  	
  void promedio(double *pa);
  void numerodecifras(double *pa);
  
int main(int argc, char** argv) {
	
	double w[3],p,*pw;
	pw=&w[0];
	
	ingreso(pw);
	numerodecifras(pw);
	promedio(pw);	
	return 0;
}

void ingreso(double *pa){
	for(int i=0;i<3;){
		double x;
		int k;
		k=3-i;
		cout<<"ingrese "<< k<<" digitos entre una a tres cifras que sea positivo"<<endl;
		cin>>x;
		if(1<=x && x<1000){
			*pa++=x;
			i++;
		}
		else{
			cout<<"error,su numero no cumple las condiciones vuelva a intentar"<<endl;
		}
		
	}cout<<endl;
}

void numerodecifras(double *pa){
	for(int i=0;i<3;i++){
		while(i<3){
			if(pa[i]>=1 && pa[i]<=9){
				cout<<"el digito que ingreso en la posicion uno es de un cifra"<<endl;
				break;
			}
			if(pa[i]>=10 && pa[i]<=99){
				cout<<"el digito que ingreso en la posicion dos es de dos cifras"<<endl;
				break;
			}
			if(pa[i]>=100 && pa[i]<1000);{
				cout<<"el digito que ingreso en la posicion tres es de tres cifras"<<endl;
				break;
			}
		}
	}cout<<endl;
}

void promedio(double *pa){
	double x;
	x=(pa[0] + pa[1] + pa[2])/3;
	cout<<"su promedio es de "<<x<<endl;
}

