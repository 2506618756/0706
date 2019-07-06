#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define STUDENTNUMBER 5
#define REFEREENUMBER 5
using namespace std;
struct Referees
{
    string name;
    string telephone;
    string address;
    double grades[STUDENTNUMBER];
}Referee[REFEREENUMBER];
struct Students
{
	string name;
	string college;
	string ID;
	double sum=0;
	double grades[REFEREENUMBER];
}student[STUDENTNUMBER];
