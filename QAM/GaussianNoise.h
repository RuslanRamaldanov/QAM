#ifndef GAUSSIANNOISE_H
#define GAUSSIANNOISE_H
//Класс реализует аддитивный белый гауссовский шум (АБГШ)
#include <vector>
class GaussianNoise
{
public:
	static std::vector<double>& add_noise(std::vector<double>& signal, const int& noise_value, const int& number_of_signals, const int& energy);
};
#endif