class item{
char opid[20];
char choice;
public:
    int i,c;
    double value,v;
    char *line;//Using Dynamic Memory Management to calculate size of the line of the file for storing line it in array
    char pid[20];
    char item[20];
    char quantity[20];
    char stock[10];
    char price[20];
public:
    virtual double itemfetch(char p[],int a,int b)//Dynamic Polymorphism used as virtual function created and later defined in the derived class i.e. you will find down
    {

    }
    virtual void edit_date()
    {

    }
    virtual void display_date()
    {

    }
    void edit( char x )//Function Overloading as another edit() function is used but without any parameter i.e. Static polymorphism
{
    int f;
    ifstream ifs1("items.csv");
    ofstream ofs1("temp1.csv");
    ifstream ifs2("itemsdisplay.csv");
    ofstream ofs2("temp2.csv");
    char pc[10];
    cout<<"                                                  ENTER PRODUCT ID :";
    cin>>pc;
    line=new char[sizeof(ifs1)];
    ifs1>>line;
    while(!ifs1.eof())
    {
     c=0;
     i=0;
        for( ;line[i]!=',';i++)
             pid[c++]=line[i];
          pid[c]='\0';
          c=0;
          i++;
        for( ;line[i]!=',';i++)
              item[c++]=line[i];
        item[c]='\0';
        c=0;
        i++;
        for( ;line[i]!=',';i++)
              quantity[c++]=line[i];
        quantity[c]='\0';
        c=0;
        i++;
        for( ;line[i]!=',';i++)
              stock[c++]=line[i];
        stock[c]='\0';
        c=0;
        i++;
        for( ;line[i]!='*';i++)
              price[c++]=line[i];
        price[c]='\0';
     if((strcmpi(pc,pid)==0)&&(x=='2'))
      {
          system("cls");
          cout<<"__________________________________________________________________________________________________________________________________"<<endl;
          cout<<"                                                        OLD DATA                                                                  ";
          gotoxy(30,3);
          cout<<"ID";
          gotoxy(45,3);
          cout<<"Name";
          gotoxy(60,3);
          cout<<"Qty.";
          gotoxy(75,3);
          cout<<"Stock";
          gotoxy(90,3);
          cout<<"Price(Rs)";
          gotoxy(30,5);
          cout<<pid;
          gotoxy(45,5);
          cout<<item;
          gotoxy(60,5);
          cout<<quantity;
          gotoxy(75,5);
          cout<<stock;
          gotoxy(90,5);
          cout<<price;
          cout<<"\n__________________________________________________________________________________________________________________________________"<<endl;
          cout<<"\n\n\n                                               Enter New/Old ID : ";
          cin>>pid;
          cout<<"\n                                               Enter New/Old ITEM name : ";
          cin>>item;
          cout<<"\n                                               Enter New/Old Quantity : ";
          cin>>quantity;
          cout<<"\n                                               Enter New/Old Stock :";
          cin>>stock;
          cout<<"\n                                               Enter New/Old Price :";
          cin>>price;
          ofs1<<pid<<","<<item<<","<<quantity<<","<<stock<<","<<"@"<<price<<"*"<<endl;
          ofs2<<pid<<","<<item<<"*"<<endl;
          cout<<" \n CHANGES SAVED ... ";
       }

        else if((strcmpi(pc,pid)==0)&&(x=='1'))
      {
          cout<<"__________________________________________________________________________________________________________________________________"<<endl;
          cout<<"                                                         DATA                                                                     "<<endl;
          cout<<endl;
          gotoxy(30,28);
          cout<<"ID";
          gotoxy(45,28);
          cout<<"Name";
          gotoxy(60,28);
          cout<<"Qty.";
          gotoxy(75,28);
          cout<<"Stock";
          gotoxy(90,28);
          cout<<"Price(Rs)";
          gotoxy(30,29);
          cout<<pid;
          gotoxy(45,29);
          cout<<item;
          gotoxy(60,29);
          cout<<quantity;
          gotoxy(75,29);
          cout<<stock;
          gotoxy(90,29);
          cout<<price;
          ofs1<<pid<<","<<item<<","<<quantity<<","<<stock<<","<<price<<"*"<<endl;
          ofs2<<pid<<","<<item<<"*"<<endl;
       }
       else
     {
        ofs1<<line<<endl;
        ofs2<<pid<<","<<item<<"*"<<endl;
     }
          delete []line;
          line=new char[sizeof(ifs1)];
          ifs1>>line;
    }
     ifs1.close();
     ofs1.close();
     ifs2.close();
     ofs2.close();
    remove("items.csv");
    remove("itemsdisplay.csv");
    rename("temp1.csv","items.csv");
    rename("temp2.csv","itemsdisplay.csv");
  }
    void edit()//Function Overloading as same function name as above but difference in parameters i.e. Static Polymorphism
    {
        int flag=0;
        ofstream ofs1("items.csv",ios::out|ios::app);
        ofstream ofs2("itemsdisplay.csv",ios::out|ios::app);
        do{
        cout<<"Enter Product ID: ";
        cin>>pid;
        ifstream ifs2("itemsdisplay.csv");
        line=new char[sizeof(ifs2)];
        ifs2>>line;
        while(!ifs2.eof())
            {   flag=0;
                c=0;
                i=0;
              while(line[i]!=',')
              {
                     opid[c]=line[i];
                     c++;
                     i++;
              }
              opid[c]='\0';
              if(strcmpi(opid,pid)==0)
              {
                flag=1;
                system("cls");
                cout<<"__________________________________________________________________________________________________________________________________"<<endl;
                cout<<"                                                       ADDING ITEM                                                                "<<endl;
                cout<<"__________________________________________________________________________________________________________________________________"<<endl;
                cout<<"\nProduct Already Exists!!!"<<endl;
                break;
              }
              delete []line;
              line=new char[sizeof(ifs2)];
              ifs2>>line;
            }
        if(flag==0)
        {
        cout<<"\t\t\t\t\t\tEnter Item Name: ";
        cin>>item;
        cout<<"\n\t\t\t\t\t\tEnter Quantity: ";
        cin>>quantity;
        cout<<"\n\t\t\t\t\t\tEnter Stock: ";
        cin>>stock;
        cout<<"\n\t\t\t\t\t\tEnter Price(Rs): ";
        cin>>price;
        ofs1<<pid<<","<<item<<","<<quantity<<","<<stock<<","<<"@"<<price<<"*"<<endl;
        ofs2<<pid<<","<<item<<"*"<<endl;
        cout<<"\n's' to Save and Exit"<<endl;
        }
        cout<<"Any button to continue"<<endl;
        choice=getch();
        system("cls");
        cout<<"__________________________________________________________________________________________________________________________________"<<endl;
        cout<<"                                                       ADDING ITEM                                                                "<<endl;
        cout<<"__________________________________________________________________________________________________________________________________"<<endl;
        ifs2.close();
        delete []line;
        }while(choice!='s');
        ofs1.close();
        ofs2.close();
    }
    void displayitem()
    { int x=5;int y=3;
     ifstream ifs2("itemsdisplay.csv");
     gotoxy(x,y-1);
     cout<<"P_ID";
     gotoxy(x+8,y-1);
     cout<<"ITEM";
     line=new char[sizeof(ifs2)];
     ifs2>>line;
     while(!ifs2.eof())
     {
          i=0;
          c=0;
              for( ;line[i]!=',';i++)
                  pid[c++]=line[i];
              pid[c]='\0';
              i++;
              c=0;
              for(;line[i]!='*';i++)
                  item[c++]=line[i];
              item[c]='\0';
          if(y==16)
            {
                x=x+25;y=3;
                gotoxy(x,y-1);
            cout<<"P_ID";
            gotoxy(x+8,y-1);
            cout<<"ITEM";
            gotoxy(x,y);
            }
          gotoxy(x,y);
          cout<<pid;
          gotoxy(x+8,y);
          cout<<item;
            y++;
          delete []line;
          line=new char[sizeof(ifs2)];
          ifs2>>line;
      }
    ifs2.close();
   }

     void remove_item(char PID[])//New function added to delete an item
   {
        int flag=0;
        ifstream ifs1("items.csv");
        ofstream ofs1("temp1.csv");
        ofstream ofs2("temp2.csv");
        line=new char[sizeof(ifs1)];
        ifs1>>line;
        while(!ifs1.eof())
        {
            i=0;
            c=0;
            for( ;line[i]!=',';i++)
             pid[c++]=line[i];
          pid[c]='\0';
          c=0;
          i++;
        for( ;line[i]!=',';i++)
              item[c++]=line[i];
        item[c]='\0';
        c=0;
        i++;

        for( ;line[i]!=',';i++)
              quantity[c++]=line[i];
        quantity[c]='\0';
        c=0;
        i++;
        for( ;line[i]!=',';i++)
              stock[c++]=line[i];
        stock[c]='\0';
        c=0;
        i++;
        for( ;line[i]!='*';i++)
            price[c++]=line[i];
          price[c]='\0';
        if(strcmpi(PID,pid)==0)
        {

          cout<<"__________________________________________________________________________________________________________________________________"<<endl;
          cout<<"                                                       DELETED DATA                                                                 "<<endl;
          gotoxy(30,26);
          cout<<"ID";
          gotoxy(45,26);
          cout<<"Name";
          gotoxy(60,26);
          cout<<"Qty.";
          gotoxy(75,26);
          cout<<"Stock";
          gotoxy(90,26);
          cout<<"Price(Rs)";
          gotoxy(30,28);
          cout<<pid;
          gotoxy(45,28);
          cout<<item;
          gotoxy(60,28);
          cout<<quantity;
          gotoxy(75,28);
          cout<<stock;
          gotoxy(90,28);
          cout<<price;
          cout<<endl;
          cout<<"Any Key to continue...";
          getch();

        }
        else
        {

            ofs1<<line<<endl;
            ofs2<<pid<<","<<item<<"*"<<endl;
        }
            delete []line;
            line=new char[sizeof(ifs1)];
            ifs1>>line;
        }

    ifs1.close();
    ofs1.close();
    ofs2.close();
    remove("items.csv");
    remove("itemsdisplay.csv");
    rename("temp1.csv","items.csv");
    rename("temp2.csv","itemsdisplay.csv");
   }
};

class cart:public item //Inheritance used as a derived class is made from base class so that all above variables can be used without redeclaration
{
    char date[20];
    char festival[50];
public:
    double itemfetch(char p[],int a,int b)
   {
    int s;
    ifstream ifs1("items.csv");
    ofstream ofs2("billdetails.csv",ios::out|ios::app);
    line=new char[sizeof(ifs1)];
    ifs1>>line;
    ofstream ofs1("temp.csv");
    while(!ifs1.eof())
    {
       c=0;
       i=0;
       for( ;line[i]!=',';i++)
             pid[c++]=line[i];
          pid[c]='\0';
          c=0;
          i++;
       for( ;line[i]!=',';i++)
              item[c++]=line[i];
        item[c]='\0';
        c=0;
        i++;
       for( ;line[i]!=',';i++)
              quantity[c++]=line[i];
        quantity[c]='\0';
        c=0;
        i++;
       for( ;line[i]!=',';i++)
              stock[c++]=line[i];
        stock[c]='\0';
        c=0;
        i++;
       for( ;line[i]!='*';i++)
            price[c++]=line[i];
          price[c]='\0';
       if(strcmpi(p,pid)==0)
       {
           ofs2<<item<<","<<quantity<<","<<price<<"*"<<endl;
           gotoxy(a,b);
           s=atoi(stock);
           s--;
           if(s<=0)
           {
               cout<<"ITEM OUT OF STOCK";
           }
           else{
           cout<<item;
           gotoxy(a+12,b);
           cout<<quantity;
           gotoxy(a+20,b);
           cout<<price<<endl;
           }
            itoa(s,stock,10);
           ofs1<<pid<<","<<item<<","<<quantity<<","<<stock<<","<<price<<"*"<<endl;

           char pr[20];
           int temp=c;
           c=1;
           i=0;
           while(c!=temp)
           {
           pr[i]=price[c];
           i++;
           c++;
           }
           pr[i]='\0';
           v=atof(pr);
           value=v;
       }
      else{
        ofs1<<line<<endl;
      }


    delete []line;
    line=new char[sizeof(ifs1)];
    ifs1>>line;


    }

    ifs1.close();
    ofs1.close();
    ofs2.close();
    remove("items.csv");
    rename("temp.csv","items.csv");
    return value;


   }

   void edit_date() //New function added to edit/add festive season date/name
   {
       char check_date[20];
       int flag=0;

       display_date();
       gotoxy(4,16);
       cout<<"Enter Date to ADD/EDIT: ";
       cin>>check_date;
       ifstream ifs("dates.csv");

       ofstream ofs("temp.csv");
       line=new char[sizeof(ifs)];
       ifs>>line;
       while(!ifs.eof())
       {

        i=0;
        c=0;
        for(;line[i]!=',';i++)
            date[c++]=line[i];
            date[c]='\0';
            c=0;
            i++;
        for(;line[i]!='*';i++)
            festival[c++]=line[i];
            festival[c]='\0';


        if(strcmp(check_date,date)==0)
        {
            flag=1;
            gotoxy(55,18);
           cout<<"FESTIVAL DETAIL";
           gotoxy(50,20);
           cout<<"Date";
           gotoxy(65,20);
           cout<<"Festival";
           gotoxy(50,22);
           cout<<date;
           gotoxy(65,22);
           cout<<festival;
           gotoxy(55,25);
           cout<<"Enter New/Old Date: ";
           cin>>date;
           gotoxy(55,27);
           cout<<"Enter New/Old Festival: ";
           cin>>festival;
           ofs<<date<<","<<festival<<"*"<<endl;
        }
        else
        {
            ofs<<line<<endl;
        }
        delete []line;
        line=new char[sizeof(ifs)];
        ifs>>line;

       }
       if(flag!=1)
       {
           gotoxy(55,23);
           cout<<"ADD  Festival Name: ";
           cin>>festival;
          ofs<<check_date<<","<<festival<<"*"<<endl;
          gotoxy(3,28);
          cout<<"CHANGES SAVED...";
       }
       else
       {
           gotoxy(3,28);
          cout<<"CHANGES SAVED...";
       }
       ifs.close();
       ofs.close();
       remove("dates.csv");
       rename("temp.csv","dates.csv");

   }

   void display_date()//While add/edit of festival date this function will be called and displays the date and festivals
   {

       int x=4;
       int y=2;
       ifstream ifs("dates.csv");
       line=new char[sizeof(ifs)];
       ifs>>line;
       cout<<"\t\t\t\t\t\tFESTIVAL DATES";
       while(!ifs.eof())
       {
        y++;
        i=0;
        c=0;
        for(;line[i]!=',';i++)
            date[c++]=line[i];
            date[c]='\0';
            c=0;
            i++;
        for(;line[i]!='*';i++)
            festival[c++]=line[i];
            festival[c]='\0';
        if(y==15)
        {
            x=x+33;
            y=2;
        }

        gotoxy(x,y);
        cout<<date;
        gotoxy(x+12,y);
        cout<<festival;
        delete []line;
        line=new char[sizeof(ifs)];
        ifs>>line;
       }
       ifs.close();
   }
};







