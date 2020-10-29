#pragma once

class g {
private:
    float* tuple;
public:
    float& operator[](int);
    g multiply(g g2);
    g add(g g2);
    g(float u, float s2);
    g();
};

void g_test();
