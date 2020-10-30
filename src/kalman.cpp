#include "g.h"
#include "oneVarKalman.h";
#include <Eigen/Dense>
#include <iostream>


using Eigen::MatrixXd;


int main()
{
    g_test();
    thermometer singleVarTest;
    singleVarTest.generate_graph(); 

    MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    m.transpose(); 
    std::cout << m << std::endl;
}