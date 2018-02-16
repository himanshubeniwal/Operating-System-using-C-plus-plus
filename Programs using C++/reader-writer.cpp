#include <iostream>
using namespace std;
#include<stdlib.h>
int wrt=1,readcount=0,mutex=1;
int wait(int);
int signal(int);
void write()
{   wrt=wait(wrt);
    cout<<"\nThis is Write Operation in Critical Section...";
    wrt=signal(wrt);
}
void read()
{
    mutex=wait(mutex);
    readcount++;
    if(readcount==1)
    {
        wrt=wait(wrt);
    }
    mutex=signal(mutex);
    cout<<"\nNow We are in Reader section of Critical Section... ";
    mutex=wait(mutex);
    readcount--;
    if(readcount==0)
    {
        wrt=signal(wrt);
    }
    mutex=signal(mutex);
}
int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return (++s);
}
int main()
{    int choice;
      while(1)
        {
    cout<<"\n****************Menu ****************";
    cout<<"\n1. Write\n2. Read \n3.Exit\n";
    cout<<"\nMake your Choice ..........  :    ";
    cin>>choice;
    switch(choice)
    {
   case 1:
    write();
    break;
   case 2:
    read();
    break;
   case 3:

    exit(1);
    break;
}
        }
return 0;
}
