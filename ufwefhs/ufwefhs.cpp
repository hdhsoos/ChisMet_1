#include <iostream>
#include <string.h>
#include "myfuncs.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	//����� ���������� � �������� �������.
	printTask();
	printDash();
	//������������� �������� �������� ������� � �������, ���������������� ��������� �����������.
	double epsilon{}, init_approx_mas[3]{};
	//���� ��� ����� ������ ��������� ���������� �����������.
	bool flag_init_approx{};
	//����������� ������������ ���������� ���������.
	bool cycle{ true };
	while (cycle)
	{
		switch (getCase())
		{
			//���������� ����������, ��������� � �������.
		case '1':
			//������� �������� ������� pow(10,-3).
			epsilon = 0.001;

			/*��������� ������*/
			//1)
			//�������������� �����.
			printDash();
			std::cout << "����� ������� �������� (���)." << std::endl;
			//����� ������� �������� (���).
			simpleIterationMethod(epsilon, init_approx_mas, flag_init_approx);

			//2)
			//�������������� �����.
			printDash();
			std::cout << "����� ������� (��)." << std::endl;
			//����� ������� (��).
			seidelMethod(epsilon, init_approx_mas, flag_init_approx);

			//3)
			//�������������� �����.
			printDash();
			std::cout << "����� ���������� (����������) (��)." << std::endl;
			//����� ���������� (����������) (��).
			relaxationMethod(epsilon, init_approx_mas, flag_init_approx);

			//������� �������� ������� pow(10,-5).
			epsilon = 0.00001;

			/*��������� ������*/
			//4)
			//�������������� �����.
			printDash();
			std::cout << "����� ������� �������� (���)." << std::endl;
			//����� ������� �������� (���).
			simpleIterationMethod(epsilon, init_approx_mas, flag_init_approx);

			//5))
			//�������������� �����.
			printDash();
			std::cout << "����� ������� (��)." << std::endl;
			//����� ������� (��).
			seidelMethod(epsilon, init_approx_mas, flag_init_approx);

			//6)
			//�������������� �����.
			printDash();
			std::cout << "����� ���������� (����������) (��)." << std::endl;
			//����� ���������� (����������) (��).
			relaxationMethod(epsilon, init_approx_mas, flag_init_approx);

			flag_init_approx = false;
			break;

			//����� ������� �������� �������� �������.
		case '2':
			printDash();
			//������� �������� �������.
			if (epsilon == 0)
				epsilon = getEpsilon();
			else
				reselectEpsilonValue(epsilon);

			/*��������� ������*/
			//1)
			//�������������� �����.
			printDash();
			std::cout << "����� ������� �������� (���)." << std::endl;
			//����� ������� �������� (���).
			simpleIterationMethod(epsilon, init_approx_mas, flag_init_approx);

			//2)
			//�������������� �����.
			printDash();
			std::cout << "����� ������� (��)." << std::endl;
			//����� ������� (��).
			seidelMethod(epsilon, init_approx_mas, flag_init_approx);

			//3)
			//�������������� �����.
			printDash();
			std::cout << "����� ���������� (����������) (��)." << std::endl;
			//����� ���������� (����������) (��).
			relaxationMethod(epsilon, init_approx_mas, flag_init_approx);
			
			flag_init_approx = false;
			break;

			//����� �� ���������.
		case '3':
			cycle = false;
			break;
		default:;
		}
		printDash();
	}
	return 0;
}