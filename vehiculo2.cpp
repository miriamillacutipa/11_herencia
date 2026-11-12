#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
	protected:
		string identificador;
		string placa;
		string marca;
		bool disponible;
	public:
		Vehiculo();
		Vehiculo(string id, string p, string m);
		
		string getIdentificador();
		string getPlaca();
		string getMarca();
		
		bool estaDisponible();
		void setIdentificador(string id);
		void setPlaca(string p);
		void setMarca(string m);
		bool reservar();
		bool cancelarReserva();
		void mostrarDatos();
};

Vehiculo::Vehiculo() {
	identificador="";
	placa="";
	marca="";
	disponible=true;
}

Vehiculo::Vehiculo(string id, string p, string m) {
	identificador=id;
	placa=p;
	marca=m;
	disponible=true;
}

string Vehiculo::getIdentificador() {
	return identificador;
}

string Vehiculo::getPlaca() {
	return placa;
}

string Vehiculo::getMarca() {
	return marca;
}

bool Vehiculo::estaDisponible() {
	return disponible;
}

void Vehiculo::setIdentificador(string id) {
	identificador=id;
}

void Vehiculo::setPlaca(string p) {
	placa=p;
}

void Vehiculo::setMarca(string m) {
	marca=m;
}

bool Vehiculo::reservar() {
	if (disponible) {
		disponible=false;
		return true;
	}
	return false;
}

bool Vehiculo::cancelarReserva() {
	if (!disponible) {
		disponible=true;
		return true;
	}
	return false;
}

void Vehiculo::mostrarDatos() {
	cout << "Identificador: " << identificador << endl;
	cout << "Placa: " << placa << endl;
	cout << "Marca: " << marca << endl;
	if (disponible) {
		cout << "Estado: Disponible" << endl;
	} else {
		cout << "Estado: Reservado" << endl;
	}
}

class Terrestre : public Vehiculo {
	private:
		int numeroPuertas;
	public:
		Terrestre();
		Terrestre(string id, string p, string m, int np);
		int getNumeroPuertas();
		void setNumeroPuertas(int np);
		void mostrar();
};

Terrestre::Terrestre() : Vehiculo() {
	numeroPuertas=0;
}

Terrestre::Terrestre(string id, string p, string m, int np) : Vehiculo(id, p, m) {
	numeroPuertas=np;
}

int Terrestre::getNumeroPuertas() {
	return numeroPuertas;
}

void Terrestre::setNumeroPuertas(int np) {
	numeroPuertas=np;
}

void Terrestre::mostrar() {
	mostrarDatos();
	cout << "Nro de puertas: " << numeroPuertas << endl;
}

class Carro : public Terrestre {
	private:
		string tipoCombustible;
	public:
		Carro();
		Carro(string id, string p, string m, int np, string comb);
		string getTipoCombustible();
		void setTipoCombustible(string comb);
		void mostrar();
};

Carro::Carro() : Terrestre() {
	tipoCombustible="";
}

Carro::Carro(string id, string p, string m, int np, string comb) : Terrestre(id, p, m, np) {
	tipoCombustible=comb;
}

string Carro::getTipoCombustible() {
	return tipoCombustible;
}

void Carro::setTipoCombustible(string comb) {
	tipoCombustible=comb;
}

void Carro::mostrar() {
	Terrestre::mostrar();
	cout << "Combustible: " << tipoCombustible << endl;
}

int main() {
	Carro carro1("C01", "ABC-123", "Toyota", 4, "gasolina");
	
	carro1.mostrar();
	
	cout << "\nReservar: " << carro1.reservar() << endl;
	cout << "Reservar otra vez: " << carro1.reservar() << endl;
	carro1.mostrar();
	
	cout << "\nCancelar: " << carro1.cancelarReserva() << endl;
	carro1.mostrar();
	
	return 0;
}
