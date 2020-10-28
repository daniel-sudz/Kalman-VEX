#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

// https://github.com/rlabbe/Kalman-and-Bayesian-Filters-in-Python


/* 
https://nbviewer.jupyter.org/github/rlabbe/Kalman-and-Bayesian-Filters-in-Python/blob/master/03-Gaussians.ipynb
The product of two independent Gaussians is given by: 

u = (s1)^2 * u2 + (s2)^2 * u1
    -------------------------
    (s1)^2 + (s2)^2

s^2 = (s1)^2 * (s2)^2
      ---------------
      (s1)^2 + (s2)^2

The sum of two Gaussians is given by: 

u = u1 + u2
s^2 = (s1)^2 + (s2)^2

Implemented as a Guassian class g with methods add, multipy

Inputs: float u, float s^2
Outputs: 0th index: float u, 1st index float s^2
*/
class g {
    private: 
        float* tuple;
    public: 
        // overloading [] notation (https://www.geeksforgeeks.org/overloading-subscript-or-array-index-operator-in-c/)
        float& operator[](int);
        g multiply(g g2) {
            float u_new = (tuple[1] * g2[0] + g2[1] * tuple[0]) / (tuple[1] + g2[1]);
            float s2_new = (tuple[1] * g2[1])/(tuple[1] + g2[1]);
            return g(u_new, s2_new);
        }
        g add(g g2) {
            float u_new = tuple[0] + g2[0]; 
            float s2_new = g2[1] + tuple[1];
            return g(u_new, s2_new); 
        }
    g(float u, float s2) {
        tuple = new float[2]{ u, s2 };
     }


};
// overloading [] notation
float& g::operator[](int index) {
    return tuple[index];
}

void g_test() {
    g g1(10.15, 10.15); 
    g g2(10.00, 10.00); 
    cout << g1.add(g2)[0];
    assert(abs(g1.add(g2)[0] - 20.15) < 0.001);
    assert(abs(g1.add(g2)[1] - 20.15) < 0.001);
    assert(abs(g1.multiply(g2)[0] - 10.07444169) < 0.001);
    assert(abs(g1.multiply(g2)[1] - 5.037220844) < 0.001);
}


int main()
{
    g_test(); 
}