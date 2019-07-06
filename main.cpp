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
    double score[STUDENTNUMBER];
}referee[REFEREENUMBER];
struct Students
{
    string name;
    string college;
    string ID;
    double sum=0;
    double grades[REFEREENUMBER];
}student[STUDENTNUMBER];
bool compare(Students first,Students second)
{
    if( first.sum > second.sum )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
	int n = 0,k = 0;
    ifstream refereeinput,studentinput;
    ofstream Matchoutput("/Users/chenxi/Desktop/190619/190620/Competition results.csv");
    refereeinput.open("/Users/chenxi/Desktop/190619/190620/Refereeinformation.txt");
    if( !refereeinput.is_open() )
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    while( !refereeinput.eof() && n < REFEREENUMBER )
    {
        refereeinput >> referee[n].name;
        refereeinput >> referee[n].telephone;
        refereeinput >> referee[n].address;
        while( k<STUDENTNUMBER )
        {
            refereeinput >> referee[n].score[k];
            k++;
        }
        n++;
        k = 0;
    }
    refereeinput.close();
    studentinput.open("/Users/chenxi/Desktop/190619/190620/Studentinformation.txt");
    if(!studentinput.is_open())
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    while( !studentinput.eof() && k < STUDENTNUMBER )
    {
        studentinput >> student[k].ID >> student[k].college >> student[k].name;
        k++;
    }
    studentinput.close();
    cout << "�����Ǹ�������Ա�ĸ�����Ϣ��"  << endl << endl;
    for( int i=0; i<REFEREENUMBER; i++ )
    {
        cout << "������"      << referee[i].name;
        cout << "  ��ϵ��ʽ��" << referee[i].telephone;
        cout << "  ��ͥ��ַ��" << referee[i].address;
        cout << endl;
    }
    cout << endl << endl;
    cout << "�����Ǹ�������Ա��������Ϣ��"  << endl << endl;
    for( int i=0; i<REFEREENUMBER; i++ )
    {
        cout << referee[i].name << endl;
        cout << "���֣�";
        for( int k=0; k<STUDENTNUMBER; k++ )
        {
            cout << setw(10) << student[k].name;
            cout << setw(4)  << referee[i].score[k];
        }
        cout << endl;
    }
    cout << endl << endl;
    for( int i=0; i<REFEREENUMBER; i++ )
    {
        for( int j=0; j<STUDENTNUMBER; j++ )
        {
            student[j].grades[i] = referee[i].score[j];
        }
    }
    for( int i=0; i<STUDENTNUMBER; i++ )
    {
        sort( student[i].grades , student[i].grades + REFEREENUMBER );
        for( int j=1; j<REFEREENUMBER-1; j++ )
            student[i].sum += student[i].grades[j];
        student[i].sum /= ( REFEREENUMBER - 2 );
    }
    sort( student , student + STUDENTNUMBER , compare );
    cout << "�����Ǹ�����ѡ�ֵľ�����Ϣ��"  << endl << endl;
    cout << left << setw(10)  << "����";
    cout << left << setw(18)  << "ѧ��";
    cout << left << setw(11)  << "ѧԺ";
    cout << left << setw(10)  << "����";
    cout << left << setw(6)   << "�ɼ�" << endl;
    for( int i=0; i<STUDENTNUMBER; i++ )
    {
        cout << left << setw(7)  << i+1;;
        cout << left << setw(15) << student[i].ID;
        cout << left << setw(14) << student[i].college;
        cout << left << setw(12) << student[i].name;
        cout << left << setw(2)  << floor(student[i].sum) << endl;
    }
    cout  << endl << endl;
    cout  << "���α�����ȫ����߷��ǣ�" << student[0].sum  << "  ��" << endl;
    cout  << "��ϲ���α����Ĺھ�������" << student[0].name << " ͬѧ" << endl;
    cout  << "��������Ϊ���ǵĹھ��������ҵ�������" << endl;
    cout  << "žžžžžžžžžžžž-----------";
    Matchoutput << left << setw(24)  << "����";
    Matchoutput << left << setw(34)  << "ѧ��";
    Matchoutput << left << setw(24)  << "ѧԺ";
    Matchoutput << left << setw(21)  << "����";
    Matchoutput << left << setw(16)   << "�ɼ�" << endl;
    for( int i=0; i<STUDENTNUMBER; i++ )
    {
        Matchoutput << left << setw(23) << i+1;
        Matchoutput << left << setw(25) << student[i].ID;
        Matchoutput << left << setw(24) << student[i].college;
        Matchoutput << left << setw(22) << student[i].name;
        Matchoutput << left << setw(12)  << floor(student[i].sum) << endl;
    }
    return 0;
}
