#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include <windows.h>
#include<conio.h>

  void gotoxy( int x, int y ){
    COORD p = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
    }
using namespace std;
#include"item.cpp"
#include"billing.cpp"
#include"login.cpp"
int main()
{
    item object;
    int i;
    char f;
    char choice;
    system("color 74");
    system("mode 130,30");
    while(1)
    {
    system("cls");
    cout<<"__________________________________________________________________________________________________________________________________"<<endl;
    cout<<"                                                        INFINITY SUPER MARKET                                                     "<<endl;
    cout<<"__________________________________________________________________________________________________________________________________"<<endl;
    cout<<"\n\n__________________________________________________________________________________________________________________________________"<<endl;
    cout<<"\n\nAt INFINITY,we research, identify and make available new products and categories that suit the everyday needs of the Indian familyOur mission is to provide the best value possible for our customers,so that every rupee they spend on shopping with us gives them more value for money than they would get anywhere else."<<endl;
    cout<<"\n\n\nAt INFINITY,we place strong emphasis on excellence in customer service.Our employees rely on the ACT formula to get the job done, with Dedication and Determination."<<endl;
    cout<<"__________________________________________________________________________________________________________________________________"<<endl;
    cout<<"\n\n"<<endl;
    cout<<"                                                       1.DISPLAY ITEMS IN MARKET                                                  "<<endl;
    cout<<"                                                       2.PROCEED                                                                  "<<endl;
    cout<<"                                                       3.EXIT                                                                     "<<endl;
    cout<<"\n\nINPUT:";
    cin>>choice;
    switch(choice)
    {
    case '1':
        system("cls");

        object.displayitem();
        gotoxy(2,18);
        cout<<"ANY KEY TO RETURN...";
        getch();
        break;

    case '2':

        admin://admin library is used for goto function to jump to this library its not an OOP feature
        system("cls");
        cout<<"__________________________________________________________________________________________________________________________________"<<endl;
        cout<<"                                                       LOGIN TO CONTINUE                                                          "<<endl;
        cout<<"__________________________________________________________________________________________________________________________________"<<endl;
        cout<<"\n\n\n                                                     1.ADMIN LOGIN                                                          "<<endl;
        cout<<"\n                                                     2.EMPLOYEE LOGIN                                                           "<<endl;
        cout<<"\n\nINPUT: ";
        cin>>f;
        if(f!='1'&&f!='2')
        {
            cout<<"\n Wrong input...press any key to continue";
            getch();

            goto admin;//goto function is used to make program jump from one line to another.....here admin: as a library  is used
        }
        system("cls");
        cout<<"__________________________________________________________________________________________________________________________________"<<endl;
        cout<<"                                                       LOGIN TO CONITNUE                                                          "<<endl;
        cout<<"__________________________________________________________________________________________________________________________________"<<endl;
        char id[20];
        char pass[20];
        cout<<"\n\n                                                   ENTER ID:";
        cout<<"\n\n                                                   PASSWORD:";
        gotoxy(60,5);
        cin>>id;
        char z;
        i=0;
        gotoxy(60,7);
        while(z!='\r')
        {
            z=getch();
            cout<<"*";
            pass[i++]=z;
        }
        pass[--i]='\0';
        cout<<endl<<id;
        if(f=='1'){
            login_interface admin_login;
        admin_login.admin(id,pass);}
        else if(f=='2'){
            login_interface emp_login;
        emp_login.employee(id,pass);}
        break;


    case '3':
        exit(0);
        break;
    default:
        cout<<"Wrong Input.."<<endl;
    }

    }
return 0;
}
