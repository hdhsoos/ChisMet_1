#include <iostream>
#include <string>
#include <iomanip>
#include "myfuncs.h"

/*������� ��� �������� ���������������� �����*/
//�������� �������� ������������� ������ �� ����������� �������������� � �����.
bool checkStrIsNumeric(std::string const& tempStr)
{
	bool negative_number{ false }, separator{ false };
	for (int i{}; i < tempStr.length(); i++)
	{
		if ((i == 0) && (tempStr[i] == '-'))
		{
			negative_number = true;
			continue;
		}
		if (!separator && i != 0 && (i != tempStr.length() - 1) && (tempStr[i] == '.' || tempStr[i] == ',' || tempStr[i] == '/'))
		{
			separator = true;
			continue;
		}
		if ((tempStr[i] < '0') || (tempStr[i] > '9'))
			return false;
	}
	return !tempStr.empty();
}
//�������������� �������� ������������� ������ � �����.
double convertStrToNumber(std::string convertStr)
{
	double number{}, number_for_fraction{};
	bool negative_number{ false }, fraction{ false };
	int separator_index{ -1 }, k{};
	for (int i{}; i < convertStr.length(); i++)
	{
		if (convertStr[i] == '.' || convertStr[i] == ',' || convertStr[i] == '/')
		{
			if (convertStr[i] == '/') fraction = true;
			separator_index = i;
			break;
		}
	}
	for (int i{}; i < convertStr.length(); i++)
	{
		if ((i == 0) && convertStr[i] == '-')
		{
			negative_number = true;
			continue;
		}
		if (convertStr[i] == '.' || convertStr[i] == ',' || convertStr[i] == '/')
			continue;
		if (separator_index == -1)
			number += static_cast<double>(convertStr[i] - '0') * pow(10, convertStr.length() - i - 1);
		else
			if (!fraction)
				number += static_cast<double>(convertStr[i] - '0') * pow(10, (i < separator_index) ? (convertStr.length() - i - 1 - 1) : (convertStr.length() - i - 1));
			else
			{
				i < separator_index ? number += static_cast<double>(convertStr[i] - '0')* pow(10, separator_index - i - 1)
					: number_for_fraction += static_cast<double>(convertStr[i] - '0') * pow(10, convertStr.length() - separator_index - 1 - k - 1);
				if (i > separator_index) k++;
			}	
	}
	if (separator_index != -1 && !fraction)
		number /= pow(10, convertStr.length() - separator_index - 1);
	if (!fraction)
		return negative_number ? static_cast<double>(-number) : static_cast<double>(number);
	else
		return negative_number ? static_cast<double>(-number / number_for_fraction) : static_cast<double>(number / number_for_fraction);
}

/*������� ��� ������ ���������� �� �������*/
//����� ���������� �� ������, ��������, �������.

//����� �������������� �����.
void printDash()
{
	std::cout << std::string(208, '-') << std::endl;
}

void printTask()
{
	std::cout << std::setw(210) << "�������� ����� ����������, ������ 4318" << std::endl;
	printDash();
	std::cout << "������� ��������������� �������: 2." << std::endl;
	std::cout << "������� �������� �������������� ��������� (����):" << std::endl;
	std::cout << " _\n|  3x - y + z = 4;\n|\n<  2x - 5y - 3z = -17;\n|\n|_ x + y - z = 1." << std::endl;
}
//����� ����� �������� ������� ��� ��� � ��.
void printSIMandSMTable()
{
	std::cout << std::string(168, '_') << std::endl;
	std::cout << "|" << std::setw(6) << "k + 1"
		"|" << std::setw(12) << "x_k"
		"|" << std::setw(12) << "y_k"
		"|" << std::setw(12) << "z_k"
		"|" << std::setw(15) << "x_(k+1)"
		"|" << std::setw(15) << "y_(k+1)"
		"|" << std::setw(15) << "z_(k+1)"
		"|" << std::setw(20) << "   |x_(k+1) - x_k|   "
		"|" << std::setw(20) << "   |y_(k+1) - y_k|   "
		"|" << std::setw(20) << "   |z_(k+1) - z_k|   "
		"|" << std::setw(14) << "�����|" << std::endl;
	std::cout << std::string(168, '_') << std::endl;
}
//����� ����� �������� ������� ��� ��.
void printRMTable()
{
	std::cout << std::string(108, '_') << std::endl;
	std::cout << "|" << std::setw(6) << "k"
		"|" << std::setw(12) << "x_k"
		"|" << std::setw(12) << "y_k"
		"|" << std::setw(12) << "z_k"
		"|" << std::setw(15) << "R_x^(k)"
		"|" << std::setw(15) << "R_y^(k)"
		"|" << std::setw(15) << "R_z^(k)"
		"|" << std::setw(20) << "   max|R^(k)|   |" << std::endl;
	std::cout << std::string(108, '_') << std::endl;
}

/*���������������� �������*/
//���������������� ����.
void MenuForChoices()
{
	std::cout << "��� �� ������ �������?" << std::endl <<
		"1) ��������� ��������� �� ��������� (�������� ����������)." << std::endl <<
		"2) ������ � ��������� ��� �������� �������� �������, � ����� ��������� ���, �� � �� ��� ��������� ����." << std::endl <<
		"3) ����� �� ���������." << std::endl;
}
//������ �������� � ������������.
char getCase()
{
	while (true)
	{
		MenuForChoices();
		std::cout << "��� �����: ";
		std::string choice{};
		std::getline(std::cin, choice);
		if (choice == "1" || choice == "2" || choice == "3")
			return choice[0];
		else
			std::cout << std::endl << "������ �����, ��� ����� ������ ����� ������ ������ � ������������ � ������������������ �������� (�� 1 �� 3). ��������� ����:" << std::endl;
	}
}

/*��������������� �������*/
//��������� �������� �������� ������� �� ������������.
double getEpsilon()
{
	std::cout << "������� �������� �������: ";
	std::string f_epsilon{};
	while (true)
	{
		std::getline(std::cin, f_epsilon);
		if (checkStrIsNumeric(f_epsilon))
		{
			double f_numeric_epsilon{ convertStrToNumber(f_epsilon) };
			if (f_numeric_epsilon > 0)
				return f_numeric_epsilon;
			else
				std::cout << "������ �����! �������� ������� ������ ���� ������ 0 (�� �������). ��������� ����: ";
		}
		else
			std::cout << "������ �����! �� ����� �� �����. ��������� ����: ";
	}
}
//����� ������ �������� �������� ������� �� ������������ ��� ���������� �������.
void reselectEpsilonValue(double& f_epsilon)
{
	std::cout << "�� ������� �������� ������ �������� �������� ������� ��� ������� �����?(\"enter\"/������� �����)" << std::endl;
	std::string new_or_old_epsilon{};
	while (true)
	{
		std::getline(std::cin, new_or_old_epsilon);
		if (new_or_old_epsilon.empty())
			break;
		else if (checkStrIsNumeric(new_or_old_epsilon))
		{
			f_epsilon = convertStrToNumber(new_or_old_epsilon);
			break;
		}
		else
			std::cout << "������ �����! �� ������ ������ Enter ��� ������ ����� ��������. ��������� ����: ";
	}
}
//��������� ����� �� ��������� ���������� ����������� �� ������������.
double getComponentOfInitApprox()
{
	std::string componet_initApprox{};
	while (true)
	{
		std::getline(std::cin, componet_initApprox);
		if (checkStrIsNumeric(componet_initApprox))
			return convertStrToNumber(componet_initApprox);
		else
			std::cout << "������ �����! �� ����� �� �����. ��������� ����: ";
	}
}
//������� ���������� �����������.
void getInitialApproximation(double f_init_approx_mas[], bool& f_flag_init_approx)
{
	std::cout << "������� ��������� �����������:" << std::endl;
	if (!f_flag_init_approx)
	{
		std::cout << "x^(0) = ";
		f_init_approx_mas[0] = getComponentOfInitApprox();
		std::cout << "y^(0) = ";
		f_init_approx_mas[1] = getComponentOfInitApprox();
		std::cout << "z^(0) = ";
		f_init_approx_mas[2] = getComponentOfInitApprox();
		f_flag_init_approx = true;
	}
	else
	{
		std::cout << "���������� ���������� ����������� x^(0): " << f_init_approx_mas[0] << "." << std::endl;
		std::cout << "���������� ���������� ����������� y^(0): " << f_init_approx_mas[1] << "." << std::endl;
		std::cout << "���������� ���������� ����������� z^(0): " << f_init_approx_mas[2] << "." << std::endl;
	}
}
//��������� ��������� �� 3-� �����.
double getMaxOfThreeNumbers(const double& number_1, const double& number_2, const double& number_3)
{
	double max_value{};
	if (number_1 > max_value) max_value = number_1;
	if (number_2 > max_value) max_value = number_2;
	if (number_3 > max_value) max_value = number_3;
	return max_value;
}

/*�������� �������*/
//����� ������� �������� (���).
void simpleIterationMethod(double& f_epsilon, double f_init_approx_mas[], bool& f_flag_init_approx)
{
	//������� ���������� �����������.
	getInitialApproximation(f_init_approx_mas, f_flag_init_approx);
	printDash();
	//����� ���������� ��� ���.
	std::cout << "����� ������� �������� (���) ��� �������� ����." << std::endl;
	std::cout << std::setw(33) << "_" << std::endl;
	std::cout << "��������� �����������:\t\tW^(0) = " << "(" << f_init_approx_mas[0] << ", " << f_init_approx_mas[1] << ", " << f_init_approx_mas[2] << ")." << std::endl;
	std::cout << "�������� �������� �������:\t" << f_epsilon << "." << std::endl;
	//������������� ���������� ��� �������� k-�� � (k+1)-�� �����������.
	double x_k{ f_init_approx_mas[0] }, y_k{ f_init_approx_mas[1] }, z_k{ f_init_approx_mas[2] },
		x_k_plus_1{}, y_k_plus_1{}, z_k_plus_1{};
	unsigned int k{ 1 };
	//����� ����� ������� ���.
	printSIMandSMTable();
	//������������ �������.
	while (true)
	{
		//���������� ����������� �� (k+1)-� ���� ��������.
		x_k_plus_1 = 4.f / 3.f + 1.f / 3.f * y_k - 1.f / 3.f * z_k;
		y_k_plus_1 = 40.f / 11.f - 1.f / 11.f * x_k - 5.f / 11.f * z_k;
		z_k_plus_1 = 84.f / 31.f - 1.f / 31.f * x_k - 1.f / 31.f * y_k;
		//���������� �������.
		std::cout << "|" << std::setw(5) << k << 
			"|" << std::setw(11) << x_k <<
			"|" << std::setw(11) << y_k <<
			"|" << std::setw(11) << z_k <<
			"|"	<< std::setw(14) << x_k_plus_1 <<
			"|" << std::setw(14) << y_k_plus_1 <<
			"|" << std::setw(14) << z_k_plus_1 <<
			"|" << std::setw(21) << abs(x_k_plus_1 - x_k) <<
			"|" << std::setw(21) << abs(y_k_plus_1 - y_k) <<
			"|" << std::setw(21) << abs(z_k_plus_1 - z_k) <<
			"|"	<< std::setw(13) << abs(x_k_plus_1 - x_k) + abs(y_k_plus_1 - y_k) + abs(z_k_plus_1 - z_k) <<
			"|" << std::endl;
		std::cout << std::string(168, '_') << std::endl;
		//�������� ������� ��������� ������������� ��������.
		if (abs(x_k_plus_1 - x_k) + abs(y_k_plus_1 - y_k) + abs(z_k_plus_1 - z_k) <= f_epsilon)
			break;
		//������� � ��������� �������� � ������, ����� ������� ���� �� ���� ��������������.
		k += 1;
		x_k = x_k_plus_1;
		y_k = y_k_plus_1;
		z_k = z_k_plus_1;
	}
	std::cout << std::endl << "����� �������, ������� ���� �� ��� � ��������� �������� ��������� � ��������� ������������: (x,y,z) = " <<
		"(" << x_k_plus_1 << ", " << y_k_plus_1 << ", " << z_k_plus_1 << ")." << std::endl;
}
//����� ������� (��).
void seidelMethod(double& f_epsilon, double f_init_approx_mas[], bool& f_flag_init_approx)
{
	//������� ���������� �����������.
	getInitialApproximation(f_init_approx_mas, f_flag_init_approx);
	printDash();
	//����� ���������� ��� ��.
	std::cout << "����� ������� (��) ��� �������� ����." << std::endl;
	std::cout << std::setw(33) << "_" << std::endl;
	std::cout << "��������� �����������:\t\tW^(0) = " << "(" << f_init_approx_mas[0] << ", " << f_init_approx_mas[1] << ", " << f_init_approx_mas[2] << ")." << std::endl;
	std::cout << "�������� �������� �������:\t" << f_epsilon << "." << std::endl;
	//������������� ���������� ��� �������� k-�� � (k+1)-�� �����������.
	double x_k{ f_init_approx_mas[0] }, y_k{ f_init_approx_mas[1] }, z_k{ f_init_approx_mas[2] },
		x_k_plus_1{}, y_k_plus_1{}, z_k_plus_1{};
	unsigned int k{ 1 };
	//����� ����� ������� ��.
	printSIMandSMTable();
	//������������ �������.
	while (true)
	{
		//���������� ����������� �� (k+1)-� ���� ��������.
		x_k_plus_1 = 4.f / 3.f + 1.f / 3.f * y_k - 1.f / 3.f * z_k;
		y_k_plus_1 = 40.f / 11.f - 1.f / 11.f * x_k_plus_1 - 5.f / 11.f * z_k;
		z_k_plus_1 = 84.f / 31.f - 1.f / 31.f * x_k_plus_1 - 1.f / 31.f * y_k_plus_1;
		//���������� �������.
		std::cout << "|" << std::setw(5) << k <<
			"|" << std::setw(11) << x_k <<
			"|" << std::setw(11) << y_k <<
			"|" << std::setw(11) << z_k <<
			"|" << std::setw(14) << x_k_plus_1 <<
			"|" << std::setw(14) << y_k_plus_1 <<
			"|" << std::setw(14) << z_k_plus_1 <<
			"|" << std::setw(21) << abs(x_k_plus_1 - x_k) <<
			"|" << std::setw(21) << abs(y_k_plus_1 - y_k) <<
			"|" << std::setw(21) << abs(z_k_plus_1 - z_k) <<
			"|" << std::setw(13) << abs(x_k_plus_1 - x_k) + abs(y_k_plus_1 - y_k) + abs(z_k_plus_1 - z_k) <<
			"|" << std::endl;
		std::cout << std::string(168, '_') << std::endl;
		//�������� ������� ��������� ������������� ��������.
		if (abs(x_k_plus_1 - x_k) + abs(y_k_plus_1 - y_k) + abs(z_k_plus_1 - z_k) <= f_epsilon)
			break;
		//������� � ��������� �������� � ������, ����� ������� ���� �� ���� ��������������.
		k += 1;
		x_k = x_k_plus_1;
		y_k = y_k_plus_1;
		z_k = z_k_plus_1;
	}
	std::cout << std::endl << "����� �������, ������� ���� �� �� � ��������� �������� ��������� � ��������� ������������: (x,y,z) = " <<
		"(" << x_k_plus_1 << ", " << y_k_plus_1 << ", " << z_k_plus_1 << ")." << std::endl;
}
//����� ���������� (����������) (��).
void relaxationMethod(double& f_epsilon, double f_init_approx_mas[], bool& f_flag_init_approx)
{
	//������� ���������� �����������.
	getInitialApproximation(f_init_approx_mas, f_flag_init_approx);
	printDash();
	//����� ���������� ��� ��.
	std::cout << "����� ���������� (����������) (��) ��� �������� ����." << std::endl;
	std::cout << std::setw(33) << "_" << std::endl;
	std::cout << "��������� �����������:\t\tW^(0) = " << "(" << f_init_approx_mas[0] << ", " << f_init_approx_mas[1] << ", " << f_init_approx_mas[2] << ")." << std::endl;
	std::cout << "�������� �������� �������:\t" << f_epsilon << "." << std::endl;
	//������������� ���������� ��� �������� k-�� ����������� � ������� �� �� k-�� ��������, � ����� ������������ �� ������ �������.
	double x_k{ f_init_approx_mas[0] }, y_k{ f_init_approx_mas[1] }, z_k{ f_init_approx_mas[2] },
		R_x_k{}, R_y_k{}, R_z_k{};
	unsigned int k{};
	//����� ����� ������� ��.
	printRMTable();
	//������������ �������.
	while (true)
	{
		//���������� ������� �� k-� ���� ��������.
		R_x_k = 4.f / 3.f - x_k + 1.f / 3.f * y_k - 1.f / 3.f * z_k;
		R_y_k = 40.f / 11.f - 1.f / 11.f * x_k - y_k - 5.f / 11.f * z_k;
		R_z_k = 84.f / 31.f - 1.f / 31.f * x_k - 1.f / 31.f * y_k - z_k;
		//���������� ������������ �� ������ ������� �� ������������ ���.
		double max_abs_R_k{ getMaxOfThreeNumbers(abs(R_x_k), abs(R_y_k), abs(R_z_k)) };
		//���������� �������.
		std::cout << "|" << std::setw(6) << k <<
			"|" << std::setw(11) << x_k <<
			"|" << std::setw(11) << y_k <<
			"|" << std::setw(11) << z_k <<
			"|" << std::setw(14) << R_x_k <<
			"|" << std::setw(14) << R_y_k <<
			"|" << std::setw(14) << R_z_k <<
			"|" << std::setw(19) << max_abs_R_k <<
			"|" << std::endl;
		std::cout << std::string(108, '_') << std::endl;
		//�������� ������� ��������� ������������� ��������.
		if ((abs(R_x_k) <= f_epsilon) && (abs(R_y_k) <= f_epsilon) && (abs(R_z_k) <= f_epsilon))
			break;
		//������� � ��������� �������� � ������, ����� ������� ���� �� ���� ��������������.
		k += 1;
		if (max_abs_R_k == abs(R_x_k))
			x_k += R_x_k;
		else if (max_abs_R_k == abs(R_y_k))
			y_k += R_y_k;
		else
			z_k += R_z_k;
	}
	std::cout << std::endl << "����� �������, ������� ���� �� �� � ��������� �������� ��������� � ��������� ������������: (x,y,z) = " <<
		"(" << x_k << ", " << y_k << ", " << z_k << ")." << std::endl;
}