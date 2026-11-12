#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const float PI = 3.1416;

class Figura {
	protected:
		string color;
	public:
		Figura(string c);
};

Figura::Figura(string c) {
	color=c;
}

class Circulo : public Figura {
	private:
		float radio;
	public:
		Circulo(string c, float r);
		float calcularArea();
		float calcularPerimetro();
		void mostrar();
};

Circulo::Circulo(string c, float r) : Figura(c) {
	radio=r;
}

float Circulo::calcularArea() {
	return PI*radio*radio;
}

float Circulo::calcularPerimetro() {
	return 2*PI*radio;
}

void Circulo::mostrar() {
	cout << "Color: " << color << endl;
	cout << "Radio: " << radio << endl;
	cout << "Area: " << calcularArea() << endl;
	cout << "Perimetro: " << calcularPerimetro() << endl;
}

int main() {
	cout << fixed << setprecision(2);
	
	Circulo circulo("azul", 2);
	
	cout << "Circulo" << endl;
	circulo.mostrar();
	
	return 0;
}
