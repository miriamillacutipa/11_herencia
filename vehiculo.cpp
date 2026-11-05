#include<iostream>
#include <string>
using namespace std;

class Vehiculo{
	protected:
		string numeroPlaca;
		string color;
		string marca;
		int velocimetro;
	public:
		Vehiculo(string, string, string, int);
		void mostrarDatos();
		void cambiarVelocidad(int);
};

Vehiculo::Vehiculo(string p, string c, string m, int v) {
	numeroPlaca=p;
	color=c;
	marca=m;
	velocimetro=v;
}
void Vehiculo::mostrarDatos() {
	cout << "Nro de placa: " << numeroPlaca <<endl;
	cout << "Color: " << color << endl;
	cout << "Marca: " << marca << endl;
	cout << "Velocimetro: " << velocimetro<< endl;
}
void Vehiculo::cambiarVelocidad(int nuevaVelocidad){
	velocimetro=nuevaVelocidad;
} 

class Automovil:public Vehiculo {
	private:
		int cantidadPuertas;
		int cantidadPasajeros;
	public:
		Automovil(string, string, string, int, int, int);
		void mostrarAutomovil();
		void subirPasajeros(int);
		void bajarPasajeros(int);
};

Automovil::Automovil(string p, string c, string m, int v, int pt, int ps): Vehiculo(p, c, m, v) {
	cantidadPuertas=pt;
	cantidadPasajeros=ps;
}
void Automovil::mostrarAutomovil() {
	mostrarDatos();
	cout << "Nro de puertas: " <<cantidadPuertas<< endl;
	cout << "Nro de pasajeros: " << cantidadPasajeros << endl;
}
void Automovil::subirPasajeros(int s) {
	cantidadPasajeros=cantidadPasajeros+s;
}
void Automovil::bajarPasajeros(int b) {
	cantidadPasajeros=cantidadPasajeros-b;
}

class Camion:public Vehiculo {
	private:
		int carga;
	public:
		Camion(string, string, string, int, int);
		void mostrarCamion();
		void cambiarCarga(int);
};	

Camion::Camion(string p, string c, string m, int v, int cg ):Vehiculo(p, c, m, v) {
	carga=cg;
}

void Camion::mostrarCamion() {
	mostrarDatos();
	cout << "Carga: " << carga << endl;
}
void Camion::cambiarCarga(int nuevaCarga) {
	carga=nuevaCarga;
}

int main() { 
	Vehiculo v("123456", "rojo", "toyota", 50);
	v.mostrarDatos();
	cout << endl;
	
	
	
	return 0; 
}



