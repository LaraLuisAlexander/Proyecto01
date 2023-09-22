#include <iostream>
#include <string.h>
#include <locale.h>
using namespace std;

struct laptop{
	char modelo[25];
	char marca[30];
	int anyo;
	char procesador[50];
	int memoria;
	int cantidad;
	int disco;
};

int main(){
	setlocale(LC_ALL, "Spanish");
	int*n = new int;
	float *mayor = new float, *menor = new float;
	int *bM = new int, *bm = new int, *memoria = new int, *cantidad = new int, *disco = new int;
	*cantidad = 0;
	*memoria = 0;
	*disco = 0;
cout<<"========================================================================\n";
cout<<"                          Tienda Next Technology                        \n";
cout<<"========================================================================\n";
	cout<<"\nCantidad de laptops a ingresar: ";
	cin>>*n;
	int const n1 =*n;
	laptop *Laptop = new laptop[n1];
	for(int a = 0; a<*n; a++){
	cout<<"\n\tModelo: ";
	fflush(stdin);
	cin.getline(Laptop[a].modelo,25);
	fflush(stdin);
	cout<<"\tMarca: ";
	cin.getline(Laptop[a].marca,50);
	cout<<"\tIngrese año de fabricación: ";
	cin>>Laptop[a].anyo;
	cout<<"\tIngrese procesador: ";
	fflush(stdin);
	cin.getline(Laptop[a].procesador,50);
	cout<<"\tIngrese memoria RAM: ";
	cin>>Laptop[a].memoria;
	*memoria += Laptop[a].memoria;
	if(a==0){
		*mayor = Laptop[a].memoria;
		*menor = Laptop[a].memoria;
		*bM = a;
	}
	if (*mayor < Laptop[a].memoria){
		*mayor = Laptop[a].memoria;
		*bM = a;
	}
	else if(*menor > Laptop[a].memoria){
		*menor = Laptop[a].memoria;
		*bm = a;
	}
		
	cout<<"\tIngrese Cantidad: ";
	cin>>Laptop[a].cantidad;
	*cantidad += Laptop[a].cantidad;
	if(a==0){
		*mayor = Laptop[a].cantidad;
		*menor = Laptop[a].cantidad;
		*bM = a;
	}
	if (*mayor < Laptop[a].cantidad){
		*mayor = Laptop[a].cantidad;
		*bM = a;
	}
	else if(*menor > Laptop[a].cantidad){
		*menor = Laptop[a].cantidad;
		*bm = a;
	}
		
	cout<<"\tIngrese memoria del Disco Duro: ";
	cin>>Laptop[a].disco;
	*disco += Laptop[a].disco;
	if(a==0){
		*mayor = Laptop[a].disco;
		*menor = Laptop[a].disco;
		*bM = a;
	}
	if (*mayor < Laptop[a].disco){
		*mayor = Laptop[a].disco;
		*bM = a;
	}
	else if(*menor > Laptop[a].disco){
		*menor = Laptop[a].disco;
		*bm = a;
	}
}
cout<<"\nLa laptop con mayor memoria es: "<<Laptop[*bM].modelo<<"\n\tEs de la marca: "<<Laptop[*bM].marca<<"\n\tTiene procesador: "<<Laptop[*bM].procesador<<"\n\tEs del año: "<<Laptop[*bM].anyo<<"\n\tTiene una memoria RAM de: "<<Laptop[*bM].memoria<<"GB";
cout<<"\nLa laptop con menor memoria es: "<<Laptop[*bm].modelo<<"\n\tEs de la marca: "<<Laptop[*bm].marca<<"\n\tTiene procesador: "<<Laptop[*bm].procesador<<"\n\tEs del año: "<<Laptop[*bm].anyo<<"\n\tTiene una memoria RAM de: "<<Laptop[*bm].memoria<<"GB";
cout<<"\nLa laptop con mayor cantidad en el almacen es: "<<Laptop[*bM].modelo<<"\n\tEs de la marca: "<<Laptop[*bM].marca<<"\n\tTiene procesador "<<Laptop[*bM].procesador<<"\n\tEs del año: "<<Laptop[*bM].anyo<<"\n\tCantidad en el almacen: "<<Laptop[*bM].cantidad;
cout<<"\nLa laptop con menor cantidad en el almacen es: "<<Laptop[*bm].modelo<<"\n\tEs de la marca: "<<Laptop[*bm].marca<<"\n\tTiene procesador "<<Laptop[*bm].procesador<<"\n\tEs del año: "<<Laptop[*bm].anyo<<"\n\tCantidad en el almacen: "<<Laptop[*bm].cantidad;
cout<<"\nLa laptop con mayor memoria en el disco duro es: "<<Laptop[*bM].modelo<<"\n\tEs de la marca: "<<Laptop[*bM].marca<<"\n\tTiene procesador: "<<Laptop[*bM].procesador<<"\n\tEs del año: "<<Laptop[*bM].anyo<<"\n\tTiene una memoria RAM de: "<<Laptop[*bM].disco<<"GB";
cout<<"\nLa laptop con menor memoria es el disco duro es: "<<Laptop[*bm].modelo<<"\n\tEs de la marca: "<<Laptop[*bm].marca<<"\n\tTiene procesador: "<<Laptop[*bm].procesador<<"\n\tEs del año: "<<Laptop[*bm].anyo<<"\n\tTiene una memoria RAM de: "<<Laptop[*bm].disco<<"GB";
	delete[]Laptop;
	delete n, bm, bM, cantidad, menor, mayor, memoria, disco;
	return 0;
}

