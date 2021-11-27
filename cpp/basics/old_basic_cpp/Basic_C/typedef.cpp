#include<iostream>
using namespace std;

typedef string degreeName;
typedef int salary;
enum degree {english, math, cs, history, pornstar};

struct person {
    degreeName job;
    salary rate;
    person()
    {
        job="";
        rate=0;
    }
};

int main()
{

    // degreeName JoeDegree= "english";
    // degreeName isaacDegree= "cs";
    // degreeName KarlDegree="math";
    // degreeName kissDegree= "history";
    // degree Joe, isaac, Karl, kiss;
    // Joe= english;
    // isaac= cs;
    // Karl= math;
    // kiss=history;

    // cout<<"Joe's degree is: "<<Joe<<'\n';
    person isaac;
    person tes;

    isaac.job="justaguy";
    isaac.rate=0;

    tes.job="Bitch";
    tes.rate=9999999;

    //printouts
    cout<<"Isaac's job is: "<<isaac.job<<" and his rate is: "<<isaac.rate<<'\n';
    cout<<"Tes's job is: "<<tes.job<<" and his rate is: "<<tes.rate<<'\n';




    return 0;
}