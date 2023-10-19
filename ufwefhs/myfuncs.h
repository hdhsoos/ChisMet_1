#ifndef MYFUNCS_H
#define MYFUNCS_H
#include "myfuncs.cpp"

bool checkStrIsNumeric(std::string const& tempStr);
double convertStrToNumber(std::string convertStr);

void printTask();
void printDash();
void printSIMandSMTable();
void printRMTable();

void MenuForChoices();
char getCase();

double getEpsilon();
void reselectEpsilonValue(double& f_epsilon);
double getComponentOfInitApprox();
//void reselectComponentValueOfInitApprox(double f_init_approx_mas[], const unsigned int f_i);
void getInitialApproximation(double f_init_approx_mas[], bool& f_flag_init_approx);
double getMaxOfThreeNumbers(const double& number_1, const double& number_2, const double& number_3);

void simpleIterationMethod(double& f_epsilon, double f_init_approx_mas[], bool& f_flag_init_approx);
void seidelMethod(double& f_epsilon, double f_init_approx_mas[], bool& f_flag_init_approx);
void relaxationMethod(double& f_epsilon, double f_init_approx_mas[], bool& f_flag_init_approx);

#endif /* MYFUNCS_H_ */