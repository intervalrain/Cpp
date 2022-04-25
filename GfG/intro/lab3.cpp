#include <bits/stdc++.h>
using namespace std;

class Triangle{
private:
    int a;
    int b;
    int c;
public:
    Triangle(int a, int b, int c){
        assert (a + b > c && b + c > a && c + a > b);
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double area(){
        double s = (a + b + c)/2.0;
        double res = sqrt(s*(s-a)*(s-b)*(s-c));
        return res;
    }
};

int main(){
    cout << "Please enter the lengths of 3 sides: ";
    int a, b, c;
    cin >> a >> b >> c;

    Triangle triangle(a, b, c);
    cout << setprecision(2) << fixed << triangle.area() << endl;

    return 0;
}
