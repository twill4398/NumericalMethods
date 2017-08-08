#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <limits>
#include <array>

//some tester functions
//TODO: implement a feature that allows a user to input a function as a string
//      and have it parsed into a function

double randomPolynomial(double x) {return pow(x, 2);}
double sinFunc(double x) {return 4 * sin(x) + 4;}

double FindMax(double (*function)(double), 
			   double lb, double ub, double stepsize = .01) {
	// Returns the max of the function over the given interval
	// TODO: reimplement with a more efficient optimization technique
	
	//set seed
	double max = std::numeric_limits<double>::min();
	while (lb <= ub) {
		if ((*function)(lb) > max)
			max = (*function)(lb);
		lb += stepsize;	
	}
	
	return max;

}

double FindMin(double (*function)(double), 
			   double lb, double ub, double stepsize = .01) {
	// Returns the min of the given function over the given interval
	
	//set seed
	double min = std::numeric_limits<double>::max();
	while (lb <= ub) {
		if ((*function)(lb) < min)
			min = (*function)(lb);
		lb += stepsize;	
	}
	return min;
}

double MonteCarloIntegrate(double (*function)(double x), double lb, double ub, 
						   size_t iterations = 100000) {
	// Performs Monte Carlo integration on a given function, 
	// Checking if random points placed in a "box" lie under the function to 
	// estimate the value of the integral 
	
	double ymax = FindMax(function, lb, ub);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937_64 generator(seed);
	std::uniform_real_distribution<double> xdist(lb, ub);
	// TODO: reimplement to account for integrals that are not strictly positive
	std::uniform_real_distribution<double> ydist(0, ymax);
	double box_area = (ub - lb) * ymax;
	size_t count = 0;
	for (size_t i = 1; i != iterations; ++i) {
		if (function(xdist(generator)) > ydist(generator)) 
			++count; 
	}
	return count * box_area / iterations;	
}


int main() {
	
	std::cout << MonteCarloIntegrate(sinFunc, 1, 10) << std::endl;
	
	
	
	
}

