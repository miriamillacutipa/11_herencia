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

class Aereo : public Vehiculo {
	private:
		int altura;
	public:
		Aereo();
		Aereo(string id, string p, string m, int a);
		int getAltura();
		void setAltura(int a);
		void mostrar();
};
Aereo::Aereo() : Vehiculo() {
	altura=0;
}
Aereo::Aereo(string id, string p, string m, int a) : Vehiculo(id, p, m) {
	altura=a;
}
int Aereo::getAltura() {
	return altura;
}
void Aereo::setAltura(int a) {
	altura=a;
}
void Aereo::mostrar() {
	mostrarDatos();
	cout << "Altura maxima: " << altura << endl;
}

class Helicoptero : public Aereo {
	private:
		int helices;
	public:
		Helicoptero();
		Helicoptero(string id, string p, string m, int a, int h);
		int getHelices();
		void setHelices(int h);
		void mostrar();
};

Helicoptero::Helicoptero() : Aereo() {
	helices=0;
}
Helicoptero::Helicoptero(string id, string p, string m, int a, int h) : Aereo(id, p, m, a) {
	helices=h;
}
int Helicoptero::getHelices() {
	return helices;
}
void Helicoptero::setHelices(int h) {
	helices=h;
}
void Helicoptero::mostrar() {
	Aereo::mostrar();
	cout << "Nro de helices: " << helices << endl;
}

class Maritimo : public Vehiculo {
	private:
		int capacidad;
	public:
		Maritimo();
		Maritimo(string id, string p, string m, int c);
		int getCapacidad();
		void setCapacidad(int c);
		void mostrar();
};

Maritimo::Maritimo() : Vehiculo() {
	capacidad=0;
}
Maritimo::Maritimo(string id, string p, string m, int c) : Vehiculo(id, p, m) {
	capacidad=c;
}
int Maritimo::getCapacidad() {
	return capacidad;
}
void Maritimo::setCapacidad(int c) {
	capacidad=c;
}
void Maritimo::mostrar() {
	mostrarDatos();
	cout << "Capacidad: " << capacidad << endl;
}

class Lancha : public Maritimo {
	private:
		int motores;
	public:
		Lancha();
		Lancha(string id, string p, string m, int c, int mo);
		int getMotores();
		void setMotores(int mo);
		void mostrar();
};

Lancha::Lancha() : Maritimo() {
	motores=0;
}
Lancha::Lancha(string id, string p, string m, int c, int mo) : Maritimo(id, p, m, c) {
	motores=mo;
}
int Lancha::getMotores() {
	return motores;
}
void Lancha::setMotores(int mo) {
	motores=mo;
}

void Lancha::mostrar() {
	Maritimo::mostrar();
	cout << "Nro de motores: " << motores << endl;
}
Carro carros[10];
Helicoptero helis[1];
Lancha lanchas[2];
int nc=0, nh=0, nl=0;

Vehiculo* buscar(string id) {
	for (int i=0; i<nc; i++) {
		if (carros[i].getIdentificador()==id) return &carros[i];
	}
	for (int i=0; i<nh; i++) {
		if (helis[i].getIdentificador()==id) return &helis[i];
	}
	for (int i=0; i<nl; i++) {
		if (lanchas[i].getIdentificador()==id) return &lanchas[i];
	}
	return NULL;
}

void registrar() {
	int tipo;
	string id, placa, marca;
	cout << "Tipo (1 Carro, 2 Helicoptero, 3 Lancha): ";
	cin >> tipo;
	if (tipo==1 && nc>=10) {
		cout << "Ya hay 10 carros registrados." << endl;
		return;
	}
	if (tipo==2 && nh>=1) {
		cout << "Ya hay 1 helicoptero registrado." << endl;
		return;
	}
	if (tipo==3 && nl>=2) {
		cout << "Ya hay 2 lanchas registradas." << endl;
		return;
	}
	if (tipo<1 || tipo>3) {
		cout << "Tipo no valido." << endl;
		return;
	}
	cout << "Identificador: ";
	cin >> id;
	if (buscar(id)!=NULL) {
		cout << "El identificador ya existe." << endl;
		return;
	}
	cout << "Placa: ";
	cin >> placa;
	cout << "Marca: ";
	cin >> marca;
	if (tipo==1) {
		int p;
		string c;
		cout << "Puertas: ";
		cin >> p;
		cout << "Combustible: ";
		cin >> c;
		carros[nc]=Carro(id, placa, marca, p, c);
		nc++;
	}
	if (tipo==2) {
		int a, h;
		cout << "Altura maxima: ";
		cin >> a;
		cout << "Helices: ";
		cin >> h;
		helis[nh]=Helicoptero(id, placa, marca, a, h);
		nh++;
	}
	if (tipo==3) {
		int c, m;
		cout << "Capacidad: ";
		cin >> c;
		cout << "Motores: ";
		cin >> m;
		lanchas[nl]=Lancha(id, placa, marca, c, m);
		nl++;
	}
	cout << "Vehiculo registrado." << endl;
}

void listarDisponibles() {
	int tipo, cont=0;
	cout << "Tipo (1 Carro, 2 Helicoptero, 3 Lancha): ";
	cin >> tipo;
	if (tipo==1) {
		for (int i=0; i<nc; i++) {
			if (carros[i].estaDisponible()) {
				carros[i].mostrar();
				cout << endl;
				cont++;
			}
		}
	} else if (tipo==2) {
		for (int i=0; i<nh; i++) {
			if (helis[i].estaDisponible()) {
				helis[i].mostrar();
				cout << endl;
				cont++;
			}
		}
	} else if (tipo==3) {
		for (int i=0; i<nl; i++) {
			if (lanchas[i].estaDisponible()) {
				lanchas[i].mostrar();
				cout << endl;
				cont++;
			}
		}
	} else {
		cout << "Tipo no valido." << endl;
		return;
	}
	if (cont==0) {
		cout << "No hay vehiculos disponibles de ese tipo." << endl;
	}
}

void consultarTerrestres() {
	if (nc==0) {
		cout << "No hay vehiculos terrestres registrados." << endl;
		return;
	}
	for (int i=0; i<nc; i++) {
		carros[i].mostrar();
		cout << endl;
	}
}

void reservar() {
	string id;
	cout << "Identificador: ";
	cin >> id;
	Vehiculo *v=buscar(id);
	if (v==NULL) {
		cout << "Advertencia: el vehiculo no existe." << endl;
	} else if (v->reservar()) {
		cout << "Reserva realizada." << endl;
	} else {
		cout << "Advertencia: el vehiculo ya esta reservado." << endl;
	}
}
void cancelar() {
	string id;
	cout << "Identificador: ";
	cin >> id;
	Vehiculo *v=buscar(id);
	if (v==NULL) {
		cout << "El vehiculo no existe." << endl;
	} else if (v->cancelarReserva()) {
		cout << "Reserva cancelada, el vehiculo esta disponible." << endl;
	} else {
		cout << "Ese vehiculo no tiene reserva." << endl;
	}
}
void estadoFlota() {
	int d, r;
	
	d=0; r=0;
	for (int i=0; i<nc; i++) {
		if (carros[i].estaDisponible()) 
		d++; 
		else 
		r++;
	}
	cout << "Carros: " << nc << "/10, disponibles " << d << ", reservados " << r << endl;
	
	d=0; r=0;
	for (int i=0; i<nh; i++) {
		if (helis[i].estaDisponible()) d++; else r++;
	}
	cout << "Helicopteros: " << nh << "/1, disponibles " << d << ", reservados " << r << endl;
	
	d=0; r=0;
	for (int i=0; i<nl; i++) {
		if (lanchas[i].estaDisponible()) d++; else r++;
	}
	cout << "Lanchas: " << nl << "/2, disponibles " << d << ", reservadas " << r << endl;
}

int main() {
	int op;
	do {
		cout << endl;
		cout << "SISTEMA DE RESERVAS - TRANSPORTE TURISTICO" << endl;
		cout << "1. Registrar vehiculos" << endl;
		cout << "2. Listar vehiculos disponibles" << endl;
		cout << "3. Consultar vehiculos terrestres" << endl;
		cout << "4. Reservar un vehiculo" << endl;
		cout << "5. Cancelar una reserva" << endl;
		cout << "6. Mostrar estado de la flota" << endl;
		cout << "7. Salir" << endl;
		cout << "Opcion: ";
		cin >> op;
		cout << endl;
		switch (op) {
			case 1: 
			registrar(); 
			break;
			case 2: 
			listarDisponibles(); 
			break;
			case 3: 
			consultarTerrestres();
			break;
			case 4: 
			reservar(); 
			break;
			case 5: 
			cancelar(); 
			break;
			case 6: 
			estadoFlota(); 
			break;
			case 7: 
			cout << "Hasta luego." << endl; 
			break;
			default: 
			cout << "Opcion no valida." << endl;
		}
	} while (op!=7);
	return 0;
}
