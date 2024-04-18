#include <iostream>
#include <cmath>

//shortcuts for outputs
using std::cout; 
using std::cin;

//global a b and c
double a, b, c;

//creates separate input function, sets a b and c
void input() {
    cout << "Input 3 numbers: " << std::endl;
    cin >> a >> b >> c; 
}



//gets the number of roots of the quadratic
int numRoots() {
    bool SQRT = (pow(b, 2)) - (4 * a * c) > 0;
    if (SQRT) return 2;
    else if (pow(b, 2) == 4 * a * c) return 1;
    else return 0; 
}




int main() {
    //runs input
    input();
    
    //if a == 0, find the single answer to the form bx + c = 0
    if (a == 0) {
        cout << "There is one root: " << (-1 * c) / b << std::endl;
        return 0;
    }

    //find number of roots
    int n = numRoots(); 

    //if all imaginary solutions, output no real roots
    if (n == 0) 
        cout << "There are no real roots of the quadratic: " << a << "x^2 + " << b << "x + " << c << "." << std::endl;

    //if one root, calculate it (the vertex of the parabola (-b / 2a))
    else if (n == 1) 
        cout << "There is one root: " << (-1 * b / 2 * a) << std::endl;

    //if two roots
    else {
        //output start of answer
        cout << "The two real roots of the quadratic: " << a << "x^2 + " << b << "x + " << c << " are: ";

        //+ form of quadratic formula
        double x1 = -1 * b;
        x1 += sqrt(pow(b,2) - (4 * a * c));
        x1 /= (2 * a);

        //- form of quadratic formula
        double x2 = -1 * b;
        x2 -= sqrt(pow(b,2) - (4 * a * c));
        x2 /= (2 * a);

        //output
        cout << x1 << ", and " << x2 << std::endl;
        
    }

}