#include <iostream>
#include<conio.h>
#include<process.h>
using namespace std;
int flag[2]={0,0};
int turn;
void process0()
{
    flag[0]=1;
    turn=1;
    while((turn==1)&&(flag[1]==1));
     {
         cout<<"\nCritical Section for Process 0 .... ";
     }
    flag[0]=0;
}
void process1()
{
    flag[1]=1;
    turn=0;
    while((turn==0)&&(flag[0]==1));
    {
        cout<<"\nCritical Section for Process 1 ....";
    }
    flag[1]=0;
}
int main()
{
    int c;
    while(1)
    {
        cout<<"\n------Menu-------";
        cout<<"\n1.Process 0 \n2.Process 1 \n3.Exit ";
        cout<<"\nPlease Enter your Choice ";
        cin>>c;
        switch(c)
        {
        case 1:
            process0();
        break;
        case 2:
            process1();
        break;
        case 3:

            break;
        }
    }
    return 0;
}
