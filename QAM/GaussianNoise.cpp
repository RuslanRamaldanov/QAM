#include "GaussianNoise.h"
#include <cmath>
#include <iostream>
#include <random>
using namespace std;

vector<double>& GaussianNoise::add_noise(vector<double>& signal, const int& noise_value, const int& number_of_signals, const int& energy)
{
	double noiseDB = pow(10.0, static_cast<double>(noise_value / 10.0));
	double dispersion = sqrt(energy * number_of_signals/ (2 * noiseDB));
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(0, number_of_signals); // Равномерное распределение

	//добавляем шум к сигналу
	for (double& d : signal)
		d = d + distribution(generator) * dispersion;

	return signal;
}
