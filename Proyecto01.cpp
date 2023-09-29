#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

struct Laptop {
    string modelo;
    string marca;
    int anyo;
    string procesador;
    int memoria;
    int cantidad;
    int disco;
};


int obtenerEntradaValida(const string& mensaje) {
    int entrada;
    while (true) {
        cout << mensaje;
        cin >> entrada;
        if (cin.fail()) {
            cin.clear();
            while (cin.get() != '\n'); 
            cout << "Entrada inválida. Intente nuevamente." << endl;
        } else {
            cin.ignore(); 
            return entrada;
        }
    }
}


string obtenerStringValido(const string& mensaje, int maxLongitud) {
    string entrada;
    while (true) {
        cout << mensaje;
        getline(cin, entrada);
        if (entrada.empty() || entrada.length() > maxLongitud) {
            cout << "Entrada inválida. Asegúrese de que no esté vacía y no exceda la longitud máxima (" << maxLongitud << " caracteres)." << endl;
        } else {
            return entrada;
        }
    }
}

void obtenerExtremos(int& mayor, int& menor, int& indiceMayor, int& indiceMenor, const Laptop* laptops, int n, int Laptop::*campo) {
    mayor = laptops[0].*campo;
    menor = laptops[0].*campo;
    indiceMayor = 0;
    indiceMenor = 0;
    for (int i = 1; i < n; i++) {
        if (laptops[i].*campo > mayor) {
            mayor = laptops[i].*campo;
            indiceMayor = i;
        }
        if (laptops[i].*campo < menor) {
            menor = laptops[i].*campo;
            indiceMenor = i;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Spanish");
    int n;

    cout << "========================================================================\n";
    cout << "                          Tienda Next Technology                        \n";
    cout << "========================================================================\n";

    n = obtenerEntradaValida("\nCantidad de laptops a ingresar: ");

    cout << "========================================================================\n";

    Laptop* laptops = new Laptop[n];

    int mayorMemoria, menorMemoria, indiceMayorMemoria, indiceMenorMemoria;
    int mayorCantidad, menorCantidad, indiceMayorCantidad, indiceMenorCantidad;
    int mayorDisco, menorDisco, indiceMayorDisco, indiceMenorDisco;

    for (int i = 0; i < n; i++) {
        cout << "\n\tModelo: ";
        laptops[i].modelo = obtenerStringValido("", 25);

        cout << "\tMarca: ";
        laptops[i].marca = obtenerStringValido("", 30);

        laptops[i].anyo = obtenerEntradaValida("\tIngrese año de fabricación: ");

        cout << "\tIngrese procesador: ";
        laptops[i].procesador = obtenerStringValido("", 50);

        laptops[i].memoria = obtenerEntradaValida("\tIngrese memoria RAM: ");
        laptops[i].cantidad = obtenerEntradaValida("\tIngrese Cantidad: ");
        laptops[i].disco = obtenerEntradaValida("\tIngrese memoria del Disco Duro: ");
    }

    obtenerExtremos(mayorMemoria, menorMemoria, indiceMayorMemoria, indiceMenorMemoria, laptops, n, &Laptop::memoria);
    obtenerExtremos(mayorCantidad, menorCantidad, indiceMayorCantidad, indiceMenorCantidad, laptops, n, &Laptop::cantidad);
    obtenerExtremos(mayorDisco, menorDisco, indiceMayorDisco, indiceMenorDisco, laptops, n, &Laptop::disco);

    cout << "\n=======================================================================\n";
    cout << "\nLa laptop con mayor memoria es: " << laptops[indiceMayorMemoria].modelo << "\n\tEs de la marca: " << laptops[indiceMayorMemoria].marca << "\n\tTiene procesador: " << laptops[indiceMayorMemoria].procesador << "\n\tEs del año: " << laptops[indiceMayorMemoria].anyo << "\n\tTiene una memoria RAM de: " << mayorMemoria << "GB";
    cout << "\nLa laptop con menor memoria es: " << laptops[indiceMenorMemoria].modelo << "\n\tEs de la marca: " << laptops[indiceMenorMemoria].marca << "\n\tTiene procesador: " << laptops[indiceMenorMemoria].procesador << "\n\tEs del año: " << laptops[indiceMenorMemoria].anyo << "\n\tTiene una memoria RAM de: " << menorMemoria << "GB\n";
    cout << "\n========================================================================\n";
    cout << "\nLa laptop con mayor cantidad en el almacen es: " << laptops[indiceMayorCantidad].modelo << "\n\tEs de la marca: " << laptops[indiceMayorCantidad].marca << "\n\tTiene procesador " << laptops[indiceMayorCantidad].procesador << "\n\tEs del año: " << laptops[indiceMayorCantidad].anyo << "\n\tCantidad en el almacen: " << mayorCantidad;
    cout << "\nLa laptop con menor cantidad en el almacen es: " << laptops[indiceMenorCantidad].modelo << "\n\tEs de la marca: " << laptops[indiceMenorCantidad].marca << "\n\tTiene procesador " << laptops[indiceMenorCantidad].procesador << "\n\tEs del año: " << laptops[indiceMenorCantidad].anyo << "\n\tCantidad en el almacen: " << menorCantidad << "\n";
    cout << "\n========================================================================\n";
    cout << "\nLa laptop con mayor memoria en el disco duro es: " << laptops[indiceMayorDisco].modelo << "\n\tEs de la marca: " << laptops[indiceMayorDisco].marca << "\n\tTiene procesador: " << laptops[indiceMayorDisco].procesador << "\n\tEs del año: " << laptops[indiceMayorDisco].anyo << "\n\tTiene una memoria RAM de: " << mayorDisco << "GB";
    cout << "\nLa laptop con menor memoria es el disco duro es: " << laptops[indiceMenorDisco].modelo << "\n\tEs de la marca: " << laptops[indiceMenorDisco].marca << "\n\tTiene procesador: " << laptops[indiceMenorDisco].procesador << "\n\tEs del año: " << laptops[indiceMenorDisco].anyo << "\n\tTiene una memoria RAM de: " << menorDisco << "GB\n";
    cout << "\n========================================================================\n";

    delete[] laptops;

    return 0;
}
