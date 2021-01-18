class login_interface
{
      char *line;//Using Dynamic Memory Management to calculate size of the line of the file for storing line it in array
      char id[20];
      char pass[20];
      char ch;
      char name[20];
      char age[10];
      int i,k,c,flag;

public:

void employee(char ID[],char PASS[])
{
       item obj;
       i=0;
       k=0;
       c=0;
       flag=0;
      ifstream ifs("employeecredentials.csv");
      line=new char[sizeof(ifs)];
      ifs>>line;
     while(!ifs.eof())
      {
      i=0;
      for(;line[i]!=',';i++)
        id[k++]=line[i];
      id[k]='\0';
      i++;
      k=0;
      for(;line[i]!='*';i++)
        pass[k++]=line[i];
      pass[k]='\0';
      i++;
      k=0;
      if(strcmp(ID,id)==0&&strcmp(pass,PASS)==0)
      {
          flag=1;
          break;
      }
      delete []line;
      line=new char[sizeof(ifs)];
      ifs>>line;
      }
       ifs.close();
      if(flag==1)
      {
            while(1)
            {
            system("cls");
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"                                                     LOGIN SUCCESSFUL                                                             "<<endl;
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"                                                      WELCOME,EMPLOYEE                                                            "<<endl;
            cout<<"\n\n                                                    1.TO START BILLING                                                        "<<endl;
            cout<<"                                                    2.TO DISPLAY THE ITEMS                                                        "<<endl;
            cout<<"                                                    3.EXIT                                                                        "<<endl;
            cout<<"\n\nINPUT: ";
            cin>>ch;
            system("cls");
            switch(ch)
            {
        case '1':
            {
             system("cls");
             bill ob1;
             ob1.billdetails();
             cout<<"\nPress Any Key to Return...";
             getch();
             break;
            }
        case '2':
            {
            obj.displayitem();
            gotoxy(5,15);
            cout<<"\n\n\n Enter any key to return .... ";
            getch();
             break;
            }
        case '3':
            exit(0);
            break;
        default: cout<<" Wrong Input !!!!!";
             }
         }
      }
      else
      {
            system("cls");
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"                                                       LOGIN FAILED                                                               "<<endl;
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"\n\n                                                   ENTER ID:";
            cout<<"\n\n                                                   PASSWORD:";
            gotoxy(60,5);
            cin>>ID;
            gotoxy(60,7);
            cin>>PASS;
            employee(ID,PASS);
      }
}
void credentials()
    {
    ofstream ofs1("employees.csv",ios::out|ios::app);
    ofstream ofs2("employeecredentials.csv",ios::out|ios::app);
    do{
    cout<<"\t\t\t\t\t\tEnter Name: ";
    cin>>name;
    cout<<"\n\t\t\t\t\t\tEnter Age: ";
    cin>>age;
    cout<<"\n\t\t\t\t\t\tLogin ID: ";
    cin>>id;
    cout<<"\n\t\t\t\t\t\tPassword: ";
    cin>>pass;
    ofs1<<name<<","<<age<<","<<id<<","<<pass<<"*"<<endl;
    ofs2<<id<<","<<pass<<"*"<<endl;
    cout<<"\n's' TO SAVE"<<endl;
    ch=getch();
    }while(ch!='s');
    cout<<"\n Press any key to return ..... ";
    getch();
    }
void admin(char ID[],char PASS[])
    {
    item ob;
    cart ob1;
    bill obj2;
      i=0;
      k=0;
      c=0;
      ifstream ifs("admin.csv");
      line=new char[sizeof(ifs)];
      ifs>>line;
      while(!ifs.eof())
      {
      for(;line[i]!=',';i++)
         id[k++]=line[i];
      id[k]='\0';
      i++;
      k=0;
      for(;line[i]!='*';i++)
         pass[k++]=line[i];
      pass[k]='\0';
      i++;
      k=0;
      if (strcmp(ID,id)==0&&strcmp(PASS,pass)==0)
        {
            while(1)
            {
            system("cls");
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"                                                     LOGIN SUCCESSFUL                                                             "<<endl;
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"                                                      WELCOME, ADMIN                                                              "<<endl;
            cout<<"\n\n                                                    1.TO ADD NEW ITEM                                                         "<<endl;
            cout<<"                                                    2.TO DISPLAY THE ITEMS                                                        "<<endl;
            cout<<"                                                    3.TO ADD/EDIT FESTIVAL DATES                                                  "<<endl;
            cout<<"                                                    4.TO VIEW OLD BILLS                                                           "<<endl;
            cout<<"                                                    5.TO DELETE AN ITEM                                                           "<<endl;
            cout<<"                                                    6.TO REGISTER AN EMPLOYEE                                                     "<<endl;
            cout<<"                                                    7.EXIT                                                                        "<<endl;
            cout<<"\n\nINPUT: ";
            cin>>ch;
            system("cls");
            switch(ch)
            {
        case '1':
           {
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"                                                       ADDING ITEM                                                                "<<endl;
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            ob.edit(); //Overloaded Function edit()  i.e. Dynamic Polymorphism as an OOP feature
            break;
           }
        case '2':
           {
            char f;
            ob.displayitem();
            gotoxy(5,18);
            cout<<"\n 1.TO VIEW/EDIT AN ITEM      "<<endl;
            cout<<"   ANY KEY TO RETURN....       "<<endl;
            f=getch();
            if(f!='1')
               break;

            else
            {
             item itemedit;
             cout<<"\n\n                                           1.TO VIEW DETAILS OF AN ITEM"<<endl;
             cout<<"                                           2.TO EDIT DETAILS OF AN ITEM"<<endl;
             editing:
             cout<<"\n                                         INPUT:";
             cin>>f;
             if(f=='1'||f=='2')
                itemedit.edit(f);
             else
             {
              cout<<"\n Wrong input...press any key to continue";
              getch();
              goto editing;
             }
            cout<<"\nANY KEY TO RETURN....";
            getch();
            continue;
            }
            }
        case '3':
            {
            ob1.edit_date();
            cout<<"\nANY KEY TO RETURN....";
            getch();
              break;
            }
        case '4':
            {
            char date[20];
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"                                                     BILL DETAILS                                                                 "<<endl;
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"\t Enter Date: ";
            cin>>date;
            obj2.see_archived_details(date);
            cout<<"\n\n\n\nANY KEY TO RETURN....       ";
            getch();
            break;
            }
        case '5':
            {
            ob.displayitem();
            gotoxy(40,19);
            cout<<"\n__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"                                                      DELETING ITEM                                                               "<<endl;
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"Enter Product id: ";
            cin>>id;
            ob.remove_item(id);
            break;
            }
        case '6':
            {
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"                                             EMPLOYEE REGISTRATION                                                                "<<endl;
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            credentials();
            break;
            }
        case '7':
            exit(0);
            break;
        default:
            cout<<" Wrong Input !!!!!";
            }

            }
        }
    else
            {system("cls");
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"                                                       LOGIN FAILED                                                               "<<endl;
            cout<<"__________________________________________________________________________________________________________________________________"<<endl;
            cout<<"\n\n                                                   ENTER ID:";
            cout<<"\n\n                                                   PASSWORD:";
            gotoxy(60,5);
            cin>>id;
            gotoxy(60,7);
            cin>>pass;
            admin(id,pass);
            }
       delete []line;
       line=new char[sizeof(ifs)];
       ifs>>line;
      }}
};




