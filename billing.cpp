class bill
{
char customer[20];
char contact[20];
char d[20];
char fest[20];
char *line;
char pid[20];
char item_name[30];
char price[20];
char date[20];
double mrp;
double amount;
double billedamt;
double totalbill;
double dbill;

public:
     bill()//Initialization through constructor for bill amount i.e. initial amount to be zero
    {
        totalbill=0;
        dbill=0;
    }

    void billdetails()
    {
        system("mode 130,49");
        cout<<"__________________________________________________________________________________________________________________________________"<<endl;
        cout<<"                                                        INFINITY SUPER MARKET                                                     "<<endl;
        cout<<"__________________________________________________________________________________________________________________________________"<<endl;

        using namespace std;
        #include"item.cpp"
        item ob2;
        ob2.displayitem();
        cart ob;
        gotoxy(0,17);
        cout<<"__________________________________________________________________________________________________________________________________"<<endl;
        gotoxy(60,18);
        cout<<"ADD ITEMS"<<endl;
        billedamt=0;
        char z;
        ofstream ofs("billdetails.csv",ios::out|ios::app);
        gotoxy(0,19);
        cout<<endl<<"\nENTER DATE (DD-MM-YYYY): ";
        cin>>date;
        cout<<"ENTER CUSTOMER NAME: ";
        cin>>customer;
        cout<<"ENTER CONTACT NO: ";
        cin>>contact;
        ofs<<date<<","<<customer<<","<<contact<<"*"<<endl;
        int f=0;
        int y=27;
        int x=2;
        cout<<"                                           's' TO SAVE AND EXIT OR ANY KEY TO CONTINUE: ";
        gotoxy(x,y);
        cout<<"ITEM";
        gotoxy(x+12,y);
        cout<<"QTY.";
        gotoxy(x+20,y);
        cout<<"MRP.";
        dbill=0;
        do{
        char pc[10];
        gotoxy(0,25);
        cout<<"ENTER PRODUCT ID: ";
        gotoxy(19,25);
        cout<<"     ";
        gotoxy(19,25);
        cin>>pc;
        y++;
        f++;
        if(f==12)
        {
        f=0;
        x=x+35;
        y=28;
        }
        mrp=ob.itemfetch(pc,x,y);
        amount=billamt(mrp);
        billedamt=billedamt+amount;
        gotoxy(87,24);
        z=getch();

        }while(z!='s');
       ofs.close();
       discount(billedamt,date);
    }

    double billamt(double amt)
{
    totalbill=0;
    amt=amt-(0.1*amt);
    totalbill=totalbill+amt;
    gotoxy(112,28);
    cout<<"        ";
    gotoxy(100,28);
    dbill=dbill+totalbill;
    cout<<"Total Amount: "<<dbill;
    return totalbill;

}
    void discount(double disc,char date_d[])
    {

        billedamt=0;
        int k=0;
        int c=0;
        int flag=0;
        ofstream ofs("billdetails.csv",ios::out|ios::app);
        ifstream ifs("dates.csv");
        line=new char[sizeof(ifs)];
        ifs>>line;
        while(!ifs.eof())
        {
            for(;line[k]!=',';k++)
                d[c++]=line[k];
                d[c]='\0';
                c=0;
                k++;
            for(;line[k]!='*';k++)
                fest[c++]=line[k];
                fest[c]='\0';
                c=0;
                k=0;

            if(strcmp(date,d)==0)
            {
             flag=1;
             break;
            }
            delete []line;
            line=new char[sizeof(ifs)];
            ifs>>line;
        }
      if(flag==1)
      {
          if(disc>=2000)
          {

              billedamt=disc-(0.4*disc);
              gotoxy(90,42);
            cout<<"With 10% Discount On Each Item";
            gotoxy(90,44);
            cout<<"Festive Season, Its "<<"*"<<fest<<"*";
            gotoxy(90,46);
            cout<<"40% "<<"*"<<fest<<"*"<<" Discount >2000";
            gotoxy(90,48);
            cout<<"FINAL BILL= Rs"<<billedamt;
            ofs<<"BILL"<<","<<"Rs"<<","<<billedamt<<"*"<<endl;
            ofs<<"#"<<endl;
          }
          else
          {

            gotoxy(90,42);
            cout<<"With 10% Discount On Each Item";
            gotoxy(90,44);
            cout<<"Festive Season, Its "<<"*"<<fest<<"*";
            gotoxy(90,46);
            cout<<"No "<<"*"<<fest<<"*"<<" Discount <2000";
            gotoxy(90,48);
            cout<<"FINAL BILL= Rs"<<disc;
            ofs<<"BILL"<<","<<"Rs"<<","<<disc<<"*"<<endl;
            ofs<<"#"<<endl;
          }
      }

      else
        {

        if(disc>=5000)
        {
            billedamt=disc-(0.05*disc);
            gotoxy(95,42);
            cout<<"With 10% Discount On Each Item";
            gotoxy(95,44);
            cout<<"5% Extra Discount for >5000";
            gotoxy(95,46);
            cout<<"FINAL BILL= Rs"<<billedamt;
            ofs<<"BILL"<<","<<"Rs"<<","<<billedamt<<"*"<<endl;
            ofs<<"#"<<endl;
        }
        else
        {
            gotoxy(95,42);
            cout<<"With 10% Discount On Each Item"<<endl;
            gotoxy(95,44);
            cout<<"FINAL BILL= Rs"<<disc;
            ofs<<"BILL"<<","<<"Rs"<<","<<disc<<"*"<<endl;
            ofs<<"#"<<endl;
        }
    }
    }
  void see_archived_details(char DATE[])//new funcction for viewing bill by date
    {
        int i,c,y;
        int flag=0;
      ifstream ifs("billdetails.csv");
      line=new char[sizeof(ifs)];
      ifs>>line;
      gotoxy(45,2);
      cout<<"Date";
      gotoxy(57,2);
      cout<<"Customer";
      gotoxy(67,2);
      cout<<"Contact";
      y=5;
      while(!ifs.eof())
      {
         c=0;
         i=0;
         for(;line[i]!=',';i++)
            pid[c++]=line[i];
         pid[c]='\0';
         i++;
         c=0;
         if(strcmp(pid,DATE)==0)
         {
         flag=1;
         while(!ifs.eof()&&line[0]!='#')
         {
         c=0;
         i=0;
         for(;line[i]!=',';i++)
            pid[c++]=line[i];
         pid[c]='\0';
         i++;
         c=0;
         for(;line[i]!=',';i++)
            item_name[c++]=line[i];
         item_name[c]='\0';
         i++;
         c=0;
         for(;line[i]!='*';i++)
            price[c++]=line[i];
         price[c]='\0';
         gotoxy(45,y);
      cout<<pid;
      gotoxy(57,y);
      cout<<item_name;
      gotoxy(67,y);
      cout<<price;
         delete []line;
         line=new char[sizeof(ifs)];
         ifs>>line;
         y++;
         }
         }
         delete []line;
         line=new char[sizeof(ifs)];
         ifs>>line;
    }
    if(flag!=1)
    {
        cout<<"\n\n\nNot Found...";
    }
    }

};








