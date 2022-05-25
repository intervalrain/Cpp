#include <iostream>
using namespace std;

class Complex{
public:
    double real;
    double img;

    Complex(double real, double img){
        this->real = real;
        this->img = img;
    }
    Complex operator+(Complex &other){
        Complex res(this->real + other.real, this->img += other.img);
        return res;
    }
    Complex operator-(Complex &other){
        Complex res (this->real -= other.real, this->img -= other.img);
        return res;
    }
    Complex operator*(Complex &other){
        Complex res (this->real * other.real + this->img * other.img, this->real * other.img + this->img * other.real);
        return res;
    }
};

int main(){
    Complex a(3,4);
    Complex b(4,-3);
    Complex c = a * b;
    cout << c.real << "+" << c.img << "i" << endl;

    return 0;
}