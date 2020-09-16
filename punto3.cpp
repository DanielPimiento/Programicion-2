#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;


class menu
{
private:
    string nombre;
    string domicilio;
    string celular;
    string FechaPago;
    string codigoCliente;

public:
    void CrearCliente();
    void BorrarCliente();
    void modificarCliente();
    void menuPrincipal();
    void detallesCliente();
    void mostarRegistro(string codigo);
};

void pausa();
void error();

void menu::menuPrincipal()
{
    int opcion;
    do
    {
        cout<<"\t\t\t\t***Menu De Usuario***\t\t\t\t\n\n";
        cout<<"1. Crear cliente\n\n";
        cout<<"2. Selecionar cliente\n\n";
        cout<<"3. Borrar cliente\n\n";
        cout<<"4. Editar cliente\n\n";
        cout<<"5. Salir\n\n";
        cout<<"Opci\242n: ";
        cin>>opcion;
        system(CLEAR);
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opcion no valida!\n\n";
            break;

        case 1:
            CrearCliente();
            break;

        case 2:
            detallesCliente();
            break;
            
        case 3:
            BorrarCliente();
            break;

        case 4:
            modificarCliente();
            break;

        case 5:
            break;
        }
    }
    while(opcion!=6);
}

void menu::CrearCliente()
{
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("clientes.txt",ios::in);
    escritura.open("clientes.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t***Crea cuenta***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el codigo del cliente: ";
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                cout<<"codigo de cliente no valido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,codigoCliente);
            while(!verificador.eof())
            {
                getline(verificador,nombre);
                getline(verificador,domicilio);
                getline(verificador,celular);
                getline(verificador,FechaPago);

                if(codigoCliente==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un cliente con ese codigo\n\n";
                    cout<<"El cliente con ese codigo es: "<<nombre<<"\n\n";
                    cout<<"Ingresa un codigo valido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"\ncodigo de cliente no valido!, intentalo nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,codigoCliente);
            }

            if(verificador.eof()&&auxCodigo!=codigoCliente)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        codigoCliente=auxCodigo;
        cout<<"\t\t\t\t***Dar de alta un cliente***\t\t\t\t\n\n";
        cout<<"Ingresa el codigo del cliente: ";
        cout<<codigoCliente;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre del cliente: ";
        getline(cin,nombre);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el domicilio del cliente: ";
        getline(cin,domicilio);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el numero de telefono del cliente: ";
        getline(cin,celular);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la fecha de inscripcion del cliente: ";
        getline(cin,FechaPago);
        cout<<"\n\n";

        escritura<<codigoCliente<<"\n"<<nombre<<"\n"<<domicilio<<"\n"<<celular
                 <<"\n"<<FechaPago<<"\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
    pausa();
}

void menu::BorrarCliente()
{
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    string auxCodigo;
    char respuesta[5];
    lectura.open("clientes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Borrar un cliente***\t\t\t\t\n\n";
    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el codigo del cliente que deseas dar de baja: ";
        getline(cin,auxCodigo);
        getline(lectura,codigoCliente);
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,domicilio);
            getline(lectura,celular);
            getline(lectura,FechaPago);

            if(auxCodigo==codigoCliente)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"Codigo: "<<codigoCliente<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Domicilio: "<<domicilio<<endl;
                cout<<"Celular: "<<celular<<endl;
                cout<<"Fecha de inscripcion: "<<FechaPago<<endl;
                cout<<"\n\n";
                cout<<"Realmente deseas dar de baja a: "<<nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                    cout<<"\n\nEl cliente se ha dado de baja correctamente\n\n";
                }

                else
                {

                    cout<<"\n\nCliente conservado\n\n";
                    auxiliar<<codigoCliente<<"\n"<<nombre<<"\n"<<domicilio<<"\n"<<celular
                            <<"\n"<<FechaPago<<"\n";

                }

            }
            else
            {
                auxiliar<<codigoCliente<<"\n"<<nombre<<"\n"<<domicilio<<"\n"<<celular
                        <<"\n"<<FechaPago<<"\n";
            }
            getline(lectura,codigoCliente);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontro el codigo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("clientes.txt");
    rename("auxiliar.txt","clientes.txt");
    pausa();
}

void menu::detallesCliente()
{
    string auxCodigo;
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("clientes.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"\t\t\t\t***Consultar detalles de un cliente***\t\t\t\t\n\n";
        cout<<"Ingresa el codigo del cliente que deseas consultar detalles: ";
        getline(cin,auxCodigo);
        getline(mostrar,codigoCliente);
        while(!mostrar.eof())
        {
            getline(mostrar,nombre);
            getline(mostrar,domicilio);
            getline(mostrar,celular);
            getline(mostrar,FechaPago);

            if(auxCodigo==codigoCliente)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<codigoCliente<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Domicilio: "<<domicilio<<endl;
                cout<<"Celular: "<<celular<<endl;
                cout<<"Fecha de inscripcion: "<<FechaPago<<endl;
                cout<<"\n\n";
            }

            getline(mostrar,codigoCliente);
        }

        if(encontrado==false)
        {
            cout<<"\n\nNo se encontro el registro: "<<auxCodigo<<"\n\n";
        }
    }

    else
    {
        error();
    }

    mostrar.close();
    pausa();
}

void menu::modificarCliente()
{
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    string auxCodigo;
    string codigoModif;
    string auxNombre;
    string auxDomicilio;
    string auxCelular;
    string auxFecha;
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("clientes.txt",ios::in);
    verificador.open("clientes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Modificar los datos de un cliente***\t\t\t\t\n\n";
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el codigo del cliente que deseas modificar: ";
        getline(cin,auxCodigo);

        if(auxCodigo=="")
        {
            do
            {
                cout<<"codigo de cliente no valido, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        }

        codigoModif=auxCodigo;

        getline(lectura,codigoCliente);
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,domicilio);
            getline(lectura,celular);
            getline(lectura,FechaPago);

            if(auxCodigo==codigoCliente)
            {
                encontrado=true;
                mostarRegistro(codigoModif);

                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informacion para el cliente\n\n";
                fflush(stdin);
                cout<<"Ingresa el codigo del cliente: ";
                getline(cin,auxCodigo);
                if(auxCodigo==codigoModif)
                {
                    mismoCodigo=true;
                }
                if(mismoCodigo==false)
                {
                    do
                    {
                        if(auxCodigo==codigoModif)
                        {
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        getline(verificador,codigoCliente);
                        while(!verificador.eof())
                        {
                            getline(verificador,nombre);
                            getline(verificador,domicilio);
                            getline(verificador,celular);
                            getline(verificador,FechaPago);

                            if(auxCodigo==codigoCliente)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un cliente con ese codigo!\n\n";
                                cout<<"El cliente con ese codigo es: "<<nombre<<"\n\n";
                                cout<<"Ingresa un codigo valido!: ";
                                getline(cin,auxCodigo);

                                if(auxCodigo=="")
                                {
                                    do
                                    {
                                        cout<<"\ncodigo de cliente no valido, ";
                                        cout<<"intentalo nuevamente: ";
                                        getline(cin,auxCodigo);
                                    }
                                    while(auxCodigo=="");
                                }
                                break;
                            }

                            getline(verificador,codigoCliente);
                        }

                        if(verificador.eof()&&auxCodigo!=codigoCliente)
                        {
                            coincidencia=false;
                        }

                    }
                    while(coincidencia==true);
                }
                system(CLEAR);
                cout<<"***Modificar los datos de un cliente***\n\n";
                cout<<"Ingresa el codigo del cliente que deseas modificar: ";
                cout<<codigoModif;
                mostarRegistro(codigoModif);
                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informacion para el cliente\n\n";
                cout<<"Ingresa el codigo del cliente: ";
                cout<<auxCodigo;
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el nombre del cliente: ";
                getline(cin,auxNombre);;
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa el domicilio del cliente: ";
                getline(cin,auxDomicilio);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el numero de telefono del cliente: ";
                getline(cin,auxCelular);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa la fecha de inscripcion del cliente: ";
                getline(cin,auxFecha);
                cout<<"\n\n";
                auxiliar<<auxCodigo<<"\n"<<auxNombre<<"\n"<<auxDomicilio<<"\n"<<auxCelular
                        <<"\n"<<auxFecha<<"\n";
                cout<<"El Registro se ha modificado correctamente.\n\n";
            }


            else
            {

                auxiliar<<codigoCliente<<"\n"<<nombre<<"\n"<<domicilio<<"\n"<<celular
                        <<"\n"<<FechaPago<<"\n";
            }


            getline(lectura,codigoCliente);
        }

    }
    else
    {
        error();
    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontrro ningun registro con ese codigo!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("clientes.txt");
    rename("auxiliar.txt","clientes.txt");
    pausa();
}

void pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system(CLEAR);
}

int main()
{
    menu inicio;
    inicio.menuPrincipal();
    return 0;
}

void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicacion que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre renombrelo al ya mencionado\n\n";
}

void menu::mostarRegistro(string codigo)
{

    ifstream mostrar;
    mostrar.open("clientes.txt",ios::in);
    getline(mostrar,codigoCliente);
    while(!mostrar.eof())
    {
        getline(mostrar,nombre);
        getline(mostrar,domicilio);
        getline(mostrar,celular);
        getline(mostrar,FechaPago);

        if(codigo==codigoCliente)
        {
            cout<<"\n\nRegistro Encontrado\n\n";
            cout<<"Codigo: "<<codigoCliente<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Domicilio: "<<domicilio<<endl;
            cout<<"Celular: "<<celular<<endl;
            cout<<"Fecha de inscripcion: "<<FechaPago<<endl;
            cout<<"\n\n";
        }

        getline(mostrar,codigoCliente);
    }

    mostrar.close();
}
