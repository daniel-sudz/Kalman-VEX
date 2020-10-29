using namespace std; 
#include <stdlib.h>
#include <vector>
#include "g.h"; 
#include <iostream>
#include "oneVarKalman.h";


/* 
Example implementation of 1 variable Kalman filter
Adapted for practice 
Based on python code from  https://nbviewer.jupyter.org/github/rlabbe/Kalman-and-Bayesian-Filters-in-Python/blob/master/04-One-Dimensional-Kalman-Filters.ipynb
*/


float thermometer::volt(float voltage, float s) {
	return voltage + ((double)rand() / (RAND_MAX)) * s;
}

g thermometer::update(g prior, g measurement) {
	return prior.multiply(measurement);
}

g thermometer::predict(g posterior, g movement) {
	return posterior.add(movement);
}

void thermometer::generate_graph() {
	for (int i = 0; i < 50; i++) {
		// generate noisy readings
		g reading = g(volt(16.3, 0.13 * 0.13), 0.13 * 0.13);
		g prior = predict(x, process_model);
		x = update(prior, reading);
		cout << reading[0] << " " << x[0] << endl;
		//cout << x[0] << endl;
	}
}

thermometer::thermometer() {}; 