#ifndef BINARYSIGNAL_H
#define BINARYSIGNAL_H
//����� ��������� ������������ ������� ������������������.
//������� ������������������ �������� � ���������� ���� int.
//��������: ����� 53 ������������� ������� ������������������ 110101.
//�� ���� ��������� ��������� ������ ������������� QAM ������� �� ����������� ��������.
#include <string>
#include <vector>
class BinarySignal
{
private:
	int upper_limit; //������� ������� ��� ��������. ��������, ��� QAM-16 ������������ ������� ������������������ ����� 1111, ��� ����� 15 � ���������� ������� ���������
public:
	BinarySignal(const int& qam_type);
	int generate_signal() const;
	int get_upper_limit() const;
	void reset_qam_type(const int& qam_type);
};

#endif