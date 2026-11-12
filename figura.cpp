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
	cout << "Color: " <<color << endl;
	cout << "Radio: " <<radio<< endl;
	cout << "Area: " <<calcularArea()<< endl;
	cout << "Perimetro: " << calcularPerimetro()<< endl;
}

class Rectangulo : public Figura {
	private:
		float base;
		float altura;
	public:
		Rectangulo(string c, float b, float a);
		float calcularArea();
		void mostrar();
};

Rectangulo::Rectangulo(string c, float b, float a) : Figura(c) {
	base=b;
	altura=a;
}

float Rectangulo::calcularArea() {
	return base*altura;
}

void Rectangulo::mostrar() {
	cout <<"Color: " <<color<< endl;
	cout <<"Base: " <<base << endl;
	cout <<"Altura: " <<altura << endl;
	cout <<"Area: " <<calcularArea()<< endl;
}

class Triangulo : public Figura {
	private:
		float base;
		float altura;
		string tipo;
	public:
		Triangulo(string c, float b, float a, string t);
		float calcularArea();
		void mostrar();
};

Triangulo::Triangulo(string c, float b, float a, string t) : Figura(c) {
	base=b;
	altura=a;
	tipo=t;
}

float Triangulo::calcularArea() {
	return base*altura/2;
}

void Triangulo::mostrar() {
	cout <<"Color: " << color<< endl;
	cout <<"Tipo: " << tipo<< endl;
	cout <<"Base: " << base<< endl;
	cout <<"Altura: " << altura<< endl;
	cout <<"Area: " << calcularArea() << endl;
}
int main() {
	cout << fixed << setprecision(2);
	
	Circulo circulo("azul",2);
	Rectangulo rectangulo("verde", 5, 3);
	Triangulo triangulo("amarillo",4, 3, "isosceles");
	
	cout << "Circulo" << endl;
	circulo.mostrar();
	cout << "\nRectangulo" << endl;
	rectangulo.mostrar();
	cout << "\nTriangulo" << endl;
	triangulo.mostrar();
	
	return 0;
}
