#pragma once


/*
Example implementation of 1 variable Kalman filter
Adapted for practice
Based on python code from  https://nbviewer.jupyter.org/github/rlabbe/Kalman-and-Bayesian-Filters-in-Python/blob/master/04-One-Dimensional-Kalman-Filters.ipynb
*/
class thermometer {

public:
	const float temp_change = 0; 
	const float voltage_std = 0.13;
	const float process_std = 0.05 * 0.05;
	const float voltage_actual = 16.3;
	g x = g(10, 100) = g(10, 1000); // initial state guess, 10 degrees and s^2 of 100
	const g process_model = g(temp_change, process_std); // model for change, assume no change with some variance


	g predict(g posterior, g movement);
	g update(g prior, g measurement);

	// example noisy reading with s = 10
	float volt(float voltage, float s);

	void generate_graph();

	
	thermometer();
};
