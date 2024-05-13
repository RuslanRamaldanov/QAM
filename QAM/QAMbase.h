#ifndef QAMBASE_H
#define QAMBASE_H
#include <vector>
class QAMbase
{
private:

protected:
	int amplitude;								//���������
	double signal_period;						//����� ���������� ������� � ������������
	int frequency;								//������� ������� �������
	int number_of_signals;						//���������� ��������: 4, 16 ��� 64
	int sampling_rate;							//������� �������������
	bool is_calculated;							//���������� - ����. ���������, ���� �� ��� ���������� ������� ���, ����� �� ������������� �� ��������

	std::vector<std::vector<double> > signals;  //�������������� �������
	std::vector<double> amp_component_x;		//���������� x ������� � ���������� ���������
	std::vector<double> amp_component_y;		//���������� y ������� � ���������� ���������

	

	std::vector<double> make_time_intervals() const;
	void make_qam_signals();					//�������� qam ��������.
	void sin_cos_basis_vector(std::vector<double>& cos_vect, std::vector<double>& sin_vect) const;
	
public:
	QAMbase(const int& amp, const int& period, const int& freq, const int& num, const int& rate);
	std::vector<std::vector<double> > get_signals();
	std::vector<std::vector<double> > get_constellation();
	double get_energy_of_signals();
	virtual void get_info() = 0;
};

#endif