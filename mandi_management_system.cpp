#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>


using namespace std;
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
class mandi
{
     private:
    string f_code,f_name;
    float price,quantity;
     public:
     void menu();
     void broker();
     void seller();
     void buyer();
     void add_new_fruit();
     void search_fruit();
     void a_display_all_fruit();
     void update_fruit_details();
     void update_fruit_price();
     void delete_fruit();
     void check_seller_request();
     void check_buyer_request();
     void approve_seller_request();
     void approve_buyer_request();
     void s_display_all_fruit();
     void b_display_all_fruit();
     void order_booking_for_sell();
     void order_booking_for_buy();
     void check_selling_status();
     void check_buying_status();


};
void mandi::menu()
{
    p:
    system("cls");
    string email,pass;
    char ch;
    int choice;
    cout<<"\n\t\t\t\tCONTROL PANEL";
    cout<<"\n\n1. Broker panel";
    cout<<"\n2. Seller panel";
    cout<<"\n3. Buyer panel";
    cout<<"\n4. Exit";
    cout<<"\n\nEnter your choice:";
    cin>>choice;
    switch (choice)
    {
        case 1:
        /*system("cls");
        cout<<"\n\t\t\t\t Login Broker Account";
        cout<<"\n\n Email ID: ";
        cin>>email;
        cout<<"\n\n Password: ";
        for(int i=1;i<=7;i++)
        {
            ch=getch();
            pass+=ch;
            cout<<"*";
        }
        getch();
        if(email=="mukeshkmt730@gmail.com"&&"pass=kmt@730")*/
        broker();
        //else
        //cout<<"\n\n\n\t\t\t Email or Password is wrong...";
        break;
        case 2:
        seller();
        break;
        case 3:
        buyer();
        break;
        case 4:
        system("cls");
        exit(0);
        break;
        default:
        cout<<"\n\nInvalid value....Please try again";
        break;

    }
    getch();
    goto p;

}
void mandi::broker()
{
     p:
    system("cls");
    int choice;
    cout<<"\n\t\t\t\tBroker panel";
    cout<<"\n\n1. Add new Fruit";
    cout<<"\n2. Search Fruit";
    cout<<"\n3. Display All Fruits";
    cout<<"\n4. Update Fruit";
    cout<<"\n5. Update Fruit Price";
    cout<<"\n6. Delete Fruit";
    cout<<"\n7. Check Seller Request";
    cout<<"\n8. Check Buyer Request";
    cout<<"\n9. Approve Seller Request";
    cout<<"\n10. Approve Buyer Request";
    cout<<"\n11. Go back";
    cout<<"\n\nEnter your choice:";
    cin>>choice;
    switch (choice)
    {
        case 1:
        add_new_fruit();
        break;
        case 2:
        search_fruit();
        break;
        case 3:
        a_display_all_fruit();
        break;
        case 4:
        update_fruit_details();
        break;
        case 5:
        update_fruit_price();
        break;
        case 6:
        delete_fruit();
        break;
        case 7:
        check_seller_request();
        break;
        case 8:
        check_buyer_request();
        break;
        case 9:
        approve_seller_request();
        break;
        case 10:
        approve_buyer_request();
        break;
        case 11:
        menu();
        break;
        default:
        cout<<"\n\nInvalid value....Please try again";
        break;

    }
    getch();
    goto p;
}
void mandi::seller()
{
    p:
    system("cls");
    int choice;
    cout<<"\n\t\t\t\t Seller panel";
    cout<<"\n\n1. Display All Fruits";
    cout<<"\n2. Seller Order Booking";
    cout<<"\n3. Check Selling order Status";
    cout<<"\n4. Go back";
    cout<<"\n\nEnter your choice:";
    cin>>choice;
    switch (choice)
    {
        case 1:
        s_display_all_fruit();
        break;
        case 2:
        order_booking_for_sell();
        break;
        case 3:
        check_selling_status();
        break;
        case 4:
        menu();
        break;
        default:
        cout<<"\n\nInvalid value....Please try again";
        break;

    }
    getch();
    goto p;
}
void mandi::buyer()
{
    p:
    system("cls");
    int choice;
    cout<<"\n\t\t\t\t Buyer panel";
    cout<<"\n\n1. Display All Fruits";
    cout<<"\n2. Buyer Order Booking";
    cout<<"\n3. Check Buying order Status";
    cout<<"\n4. Go back";
    cout<<"\n\nEnter your choice:";
    cin>>choice;
    switch (choice)
    {
        case 1:
        b_display_all_fruit();
        break;
        case 2:
        order_booking_for_buy();
        break;
        case 3:
        check_buying_status();
        break;
        case 4:
        menu();
        break;
        default:
        cout<<"\n\nInvalid value....Please try again";
        break;

    }
    getch();
    goto p;
}
void mandi::add_new_fruit()
{
    system("cls");
    int found=0;
    string c,n;
    float p,q;
    fstream file;
    cout<<"\n\t\t\t\t Add new Fruit";
   
    file.open("Fruit.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n Fruit Code: ";
    cin>>f_code;
    cout<<"\n\n Fruit Name: ";
    cin>>f_name;
    cout<<"\n\n Price: ";
    cin>>price;
    cout<<"\n\n Quantity: ";
    cin>>quantity;
         file.open("Fruit.txt",ios::app|ios::out);
    file<<" "<<f_code<<" "<<f_name<<" "<<price<<" "<<quantity<<endl;
    file.close();
    cout<<"\n\n\n\t\t\t Fruit Added Successfully";
    }
   else
   {
        cout<<"\n\n Fruit Code: ";
    cin>>f_code;
       file>>c>>n>>p>>q;
       while(!file.eof())
       {
           if(c==f_code)
           {
               file.close();
               cout<<"\n\n Fruit code is already exist...";
               found++;
           }
          file>>c>>n>>p>>q;  
       }
       file.close();
       if(found==0)
       {
        cout<<"\n\n Fruit Name: ";
        cin>>f_name;
        cout<<"\n\n Price: ";
        cin>>price;
        cout<<"\n\n Quantity: ";
        cin>>quantity;
           file.open("Fruit.txt",ios::app|ios::out);
           file<<" "<<f_code<<" "<<f_name<<" "<<price<<" "<<quantity<<endl;
           file.close();
           cout<<"\n\n\n\t\t\t Fruit Added Successfully";

       }
   }
}
void mandi::search_fruit()
{
    system("cls");
    fstream file;
    string c;
    int found=0;
    cout<<"\n\t\t\t\tSearch Fruit";  
    file.open("Fruit.txt",ios::in);
    if(!file)
     {
        cout<<"\n\n\n\t\t\t No Fruit Added...";
        getch();
        broker();

    }
    else
    {
        cout<<"\n\nFruit Code: ";
        cin>>c;
        file>>f_code>>f_name>>price>>quantity;
        while(!file.eof())
        {
            if(c==f_code)
            {
               system("cls");
               cout<<"\n\t\t\t\tSearch paint";
               cout<<"\n\n Fruit Code: "<<f_code;
               cout<<"\n\n Fruit Name: "<<f_name;
               cout<<"\n\n Fruit Price: "<<price;
               cout<<"\n\n Fruit Quantity: "<<quantity;
               found++;

            }
            file>>f_code>>f_name>>price>>quantity;

        }
        file.close();
        if(found==0)
        cout<<"\n\n Fruit code not found...";
    }
}
void mandi::a_display_all_fruit()
{
    system("cls");
   int found=0;
   fstream file;
   cout<<"\n\t\t\t\tDisplay All Fruits";
   file.open("Fruit.txt",ios::in);
   if(!file)
   {
       cout<<"\n\n\n\t\t\t No Fruit Added";
       getch();
       broker();
   }
   else
   {
       int i=1;
       file>>f_code>>f_name>>price>>quantity;
       while(!file.eof())
       {
           //system("cls");
          // Sleep(1000);
           cout<<"\n**************************************";
           cout<<"\n"<<i++<<":";
           cout<<"\n Fruit Code: "<<f_code;
           cout<<"\n\n Fruit Name: "<<f_name;
           cout<<"\n\n Fruit Price: "<<price;
           cout<<"\n\n Fruit Quantity: "<<quantity;
           cout<<"\n\n**************************************";
           found++;
           //getch();
           file>>f_code>>f_name>>price>>quantity;
       }
       file.close();
       if(found==0)
       cout<<"\n\n\n\t\t\t No Fruit remaining...";
       gotoxy(0,0);
   }
}
void mandi::update_fruit_details()
{
     system("cls");
    string c,newname;
    int found=0;
    float newprice,newquantity;
    fstream file,file1;
    cout<<"\n\t\t\t\tUpdate Fruit Details";
    
    
    file.open("Fruit.txt",ios::in);
    if(!file)
     {
        cout<<"\n\n\n\t\t\t No Fruit Added...";
        getch();
        broker();

    }
    else
    {
        cout<<"\n\n Fruit Code: ";
        cin>>c;
        file1.open("Fruit1.txt",ios::app|ios::out);
        file>>f_code>>f_name>>price>>quantity;
        while(!file.eof())
        {
            if(c==f_code)
            {
                cout<<"\n\n Enter New Fruit Name: ";
                cin>>newname;
                cout<<"\n\n Enter New price: ";
                cin>>newprice;
                cout<<"\n\n Enter New Quantity: ";
                cin>>newquantity;
                file1<<" "<<f_code<<" "<<newname<<" "<<newprice<<" "<<newquantity<<endl;
                found++;
                cout<<"\n\n\n\t\t\t Details Updated Successfully";
            }
            else
            {
                file1<<" "<<f_code<<" "<<f_name<<" "<<price<<" "<<quantity<<endl;
            }
            file>>f_code>>f_name>>price>>quantity;
        }
        file.close();
        file1.close();
        remove("Fruit.txt");
        rename("Fruit1.txt","Fruit.txt");
        if(found==0)
        cout<<"\n\n\n\t\t\tFruit code not found...";


    }
}
void mandi::update_fruit_price()
{
    system("cls");
    string c;
    int found=0;
    float newprice;
    fstream file,file1;
    cout<<"\n\t\t\t\tUpdate Fruit Price";
    
    
    file.open("Fruit.txt",ios::in);
    if(!file)
     {
        cout<<"\n\n\n\t\t\t No Fruit Added...";
        getch();
        broker();

    }
    else
    {
        cout<<"\n\n Fruit Code: ";
        cin>>c;
        file1.open("Fruit1.txt",ios::app|ios::out);
        file>>f_code>>f_name>>price>>quantity;
        while(!file.eof())
        {
            if(c==f_code)
            {
                cout<<"\n\n Enter New price: ";
                cin>>newprice;
                file1<<" "<<f_code<<" "<<f_name<<" "<<newprice<<" "<<quantity<<endl;
                found++;
                cout<<"\n\n\n\t\t\t Price of "<<f_name<<" Updated Successfully";
            }
            else
            {
                file1<<" "<<f_code<<" "<<f_name<<" "<<price<<" "<<quantity<<endl;
            }
            file>>f_code>>f_name>>price>>quantity;
        }
        file.close();
        file1.close();
        remove("Fruit.txt");
        rename("Fruit1.txt","Fruit.txt");
        if(found==0)
        cout<<"\n\n\n\t\t\tFruit code not found...";


    }
}
void mandi::delete_fruit()
{
     system("cls");
    string c;
    int found=0;
    fstream file,file1;
    cout<<"\n\t\t\t\tDelete Fruit";
    
    
    file.open("Fruit.txt",ios::in);
    if(!file)
     {
        cout<<"\n\n\n\t\t\t No Fruit Added...";
        getch();
        broker();

    }
    else
    {
        cout<<"\n\n Fruit Code: ";
        cin>>c;
        file1.open("Fruit1.txt",ios::app|ios::out);
        file>>f_code>>f_name>>price>>quantity;
        while(!file.eof())
        {
            if(c==f_code)
            {
                cout<<"\n\n\n\t\t\t Fruit Deleted Successfully";
                found++;
            }
            else
            {
                file1<<" "<<f_code<<" "<<f_name<<" "<<price<<" "<<quantity<<endl;
            }
            file>>f_code>>f_name>>price>>quantity;
        }
        file.close();
        file1.close();
        remove("Fruit.txt");
        rename("Fruit1.txt","Fruit.txt");
        if(found==0)
        cout<<"\n\n\n\t\t\tFruit code not found...";


    }
    

}
void mandi::check_seller_request()
{
    system("cls");
    int found=0,s_id;
    string s_name,s_phone;
    float s_quantity;
    fstream file;
    cout<<"\n\t\t\t\t Broker Check Seller Requests";
    file.open("Seller.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n\t\t\t No Seller Found... ";
        getch();
        broker();
    }
    else
    {
        int i=1;
        file>>s_id>>s_name>>s_phone>>f_code>>s_quantity;
        while(!file.eof())
        {
            cout<<"\n**************************************";
            cout<<"\n"<<i++<<":";
            cout<<"\n Seller ID: "<<s_id;
            cout<<"\n\n Seller Name: "<<s_name;
            cout<<"\n\n Seller Phone no: "<<s_phone;
            cout<<"\n\n Selling Fruit Code: "<<f_code;
            cout<<"\n\n Selling Fruit Quantity: "<<s_quantity;
            cout<<"\n\n**************************************";
            found++;
          file>>s_id>>s_name>>s_phone>>f_code>>s_quantity;
        }
        file.close();
        if(found==0)
        cout<<"\n\n\n\t\t\t All Selling Orders are approved...";
    }

}
void mandi::check_buyer_request()
{
    system("cls");
    int found=0,b_id;
    string b_name,b_phone;
    float b_quantity;
    fstream file;
    cout<<"\n\t\t\t\t Broker Check Buyer Requests";
    file.open("Buyer.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n\t\t\t No Buyer Found... ";
        getch();
        broker();
    }
    else
    {
        int i=1;
        file>>b_id>>b_name>>b_phone>>f_code>>b_quantity;
        while(!file.eof())
        {
            cout<<"\n**************************************";
            cout<<"\n"<<i++<<":";
            cout<<"\n Buyer ID: "<<b_id;
            cout<<"\n\n Buyer Name: "<<b_name;
            cout<<"\n\n Buyer Phone no: "<<b_phone;
            cout<<"\n\n Buying Fruit Code: "<<f_code;
            cout<<"\n\n Buying Fruit Quantity: "<<b_quantity;
            cout<<"\n\n**************************************";
            found++;
          file>>b_id>>b_name>>b_phone>>f_code>>b_quantity;
        }
        file.close();
        if(found==0)
        cout<<"\n\n\n\t\t\t All Buying Orders are Approved...";
    }
}
void mandi::approve_seller_request()
{
     system("cls");
     string s_name,s_phone,c;
     int found1=0,found=0,s_id,id;
     double s_quantity,q;
     fstream file,file1;
     cout<<"\n\t\t\t\t Approve Seller Request";
     file.open("Seller.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n\n\t\t\t No Seller Found";
         getch();
         broker();
     }
     else
     {
         cout<<"\n\n Enter Seller ID: ";
         cin>>id;
         file>>s_id>>s_name>>s_phone>>f_code>>s_quantity;
         while (!file.eof())
         {
             if(id==s_id)
             {
                 found++;
                 c=f_code;
                 q=s_quantity;
             }
             file>>s_id>>s_name>>s_phone>>f_code>>s_quantity;
         }
         file.close();
         if(found==0)
         cout<<"\n\n\n\t\t\t Seller ID Not Found..";
         else
         {
             file.open("Fruit.txt",ios::in);
             file1.open("Fruit1.txt",ios::app|ios::out);
             file>>f_code>>f_name>>price>>quantity;
             while(!file.eof())
             {
                 if(c==f_code)
                 {
                     if((quantity+q)>2000){
                     file1<<" "<<f_code<<" "<<f_name<<" "<<price<<" "<<quantity<<endl;
                     found1++;
                     }
                     else
                     file1<<" "<<f_code<<" "<<f_name<<" "<<price<<" "<<quantity+q<<endl;
                 }
                 else
                 file1<<" "<<f_code<<" "<<f_name<<" "<<price<<" "<<quantity<<endl;
                 file>>f_code>>f_name>>price>>quantity;
             }
             file.close();
             file1.close();
             remove("Fruit.txt");
             rename("Fruit1.txt","Fruit.txt");
             if(found1>0)
             cout<<"\n\n\n\t\t\t No more Space to Store Fruit...";
             else
             {
                  file.open("Seller.txt",ios::in);
                  file1.open("Seller1.txt",ios::app|ios::out);
                  file>>s_id>>s_name>>s_phone>>f_code>>s_quantity;
                  while(!file.eof())
                  {
                      if(id==s_id)
                      cout<<"\n\n\n\t\t\tSeller Order of ID: "<<id<<" Approved Successfully";
                      else
                      file1<<" "<<s_id<<" "<<s_name<<" "<<s_phone<<" "<<f_code<<" "<<s_quantity<<endl;
                      file>>s_id>>s_name>>s_phone>>f_code>>s_quantity;
                  }
                   file.close();
                   file1.close();
                   remove("Seller.txt");
                    rename("Seller1.txt","Seller.txt");
             }
         }
         
     }
}
void mandi::approve_buyer_request()
{
    system("cls");
     string b_name,b_phone,c;
     int found1=0,found=0,b_id,id;
     double b_quantity,q;
     fstream file,file1;
     cout<<"\n\t\t\t\t Approve Buyer Request";
     file.open("Buyer.txt",ios::in);
     if(!file)
     {
         cout<<"\n\n\n\t\t\t No Buyer Found";
         getch();
         broker();
     }
     else
     {
         cout<<"\n\n Enter Buyer ID: ";
         cin>>id;
         file>>b_id>>b_name>>b_phone>>f_code>>b_quantity;
         while (!file.eof())
         {
             if(id==b_id)
             {
                 found++;
                 c=f_code;
                 q=b_quantity;
             }
             file>>b_id>>b_name>>b_phone>>f_code>>b_quantity;
         }
         file.close();
         if(found==0)
         cout<<"\n\n\n\t\t\t Buyer ID Not Found..";
         else
         {
             file.open("Fruit.txt",ios::in);
             file1.open("Fruit1.txt",ios::app|ios::out);
             file>>f_code>>f_name>>price>>quantity;
             while(!file.eof())
             {
                 if(c==f_code)
                 {
                     if(quantity<q){
                     file1<<" "<<f_code<<" "<<f_name<<" "<<price<<" "<<quantity<<endl;
                     found1++;
                     }
                     else
                     file1<<" "<<f_code<<" "<<f_name<<" "<<price<<" "<<quantity-q<<endl;
                 }
                 else
                 file1<<" "<<f_code<<" "<<f_name<<" "<<price<<" "<<quantity<<endl;
                 file>>f_code>>f_name>>price>>quantity;
             }
             file.close();
             file1.close();
             remove("Fruit.txt");
             rename("Fruit1.txt","Fruit.txt");
             if(found1>0)
             cout<<"\n\n\n\t\t\t Not Enough Fruits for Buy...";
             else
             {
                  file.open("Buyer.txt",ios::in);
                  file1.open("Buyer1.txt",ios::app|ios::out);
                  file>>b_id>>b_name>>b_phone>>f_code>>b_quantity;
                  while(!file.eof())
                  {
                      if(id==b_id)
                      cout<<"\n\n\n\t\t\tBuyer Order of ID: "<<id<<" Approved Successfully";
                      else
                      file1<<" "<<b_id<<" "<<b_name<<" "<<b_phone<<" "<<f_code<<" "<<b_quantity<<endl;
                      file>>b_id>>b_name>>b_phone>>f_code>>b_quantity;
                  }
                   file.close();
                   file1.close();
                   remove("Buyer.txt");
                    rename("Buyer1.txt","Buyer.txt");
             }
         }
         
     }
}
void mandi::s_display_all_fruit()
{
    system("cls");
   int found=0;
   fstream file;
   cout<<"\n\t\t\t\tDisplay All Fruits";
   file.open("Fruit.txt",ios::in);
   if(!file)
   {
       cout<<"\n\n\n\t\t\t No Fruit Avaible";
       getch();
       seller();
   }
   else
   {
       int i=1;
       file>>f_code>>f_name>>price>>quantity;
       while(!file.eof())
       {
           //system("cls");
           //Sleep(1000);
           cout<<"\n**************************************";
           cout<<"\n"<<i++<<":";
           cout<<"\n Fruit Code: "<<f_code;
           cout<<"\n\n Fruit Name: "<<f_name;
           cout<<"\n\n Fruit Price: "<<price;
           cout<<"\n\n Fruit Quantity: "<<quantity;
           cout<<"\n\n**************************************";
           found++;
           //getch();
           file>>f_code>>f_name>>price>>quantity;
       }
       file.close();
       if(found==0)
       cout<<"\n\n\n\t\t\t No Fruit remaining...";
       gotoxy(0,0);
   }
}
void mandi::b_display_all_fruit()
{
    system("cls");
   int found=0;
   fstream file;
   cout<<"\n\t\t\t\tDisplay All Fruits";
   file.open("Fruit.txt",ios::in);
   if(!file)
   {
       cout<<"\n\n\n\t\t\t No Fruit Avaible";
       getch();
       buyer();
   }
   else
   {
       int i=1;
       file>>f_code>>f_name>>price>>quantity;
       while(!file.eof())
       {
           //system("cls");
          // Sleep(1000);
           cout<<"\n**************************************";
           cout<<"\n"<<i++<<":";
           cout<<"\n Fruit Code: "<<f_code;
           cout<<"\n\n Fruit Name: "<<f_name;
           cout<<"\n\n Fruit Price: "<<price;
           cout<<"\n\n Fruit Quantity: "<<quantity;
           cout<<"\n\n**************************************";
           found++;
           //getch();
           file>>f_code>>f_name>>price>>quantity;
       }
       file.close();
       if(found==0)
       cout<<"\n\n\n\t\t\t No Fruit remaining...";
       gotoxy(0,0);
   }
}
void mandi::order_booking_for_sell()
{
    system("cls");
    int found=0,s_id,id;
    string s_name,s_phone,s_ph,c,s_n;
    float s_quantity,s_q;
    fstream file;
    cout<<"\n\t\t\t\tOrder Booking For Sell";
    
    file.open("Fruit.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n\t\t\tNo Fruit Avaible";
        seller();
        getch();
    }
    else
    {
        cout<<"\n\n Enter Fruit Code: ";
        cin>>c;
        file>>f_code>>f_name>>price>>quantity;
        while(!file.eof())
        {
            if(c==f_code)
            found++;
            file>>f_code>>f_name>>price>>quantity;
        }
        file.close();
        if(found==0)
        cout<<"\n\n\n\t\t\t Fruit Code Not Found...";
        else
        {
             cout<<"\n\n Enter Your Name: ";
             cin>>s_name;
             cout<<"\n\n Enter Your Phone no: ";
             cin>>s_phone;
             cout<<"\n\n Enter Your Fruit Quantity: ";
             cin>>s_quantity;
             file.open("Seller.txt",ios::in);
             if(!file)
             {
                s_id=1001;
                file.open("Seller.txt",ios::app|ios::out);
                file<<" "<<s_id<<" "<<s_name<<" "<<s_phone<<" "<<c<<" "<<s_quantity<<endl;
                file.close();
                cout<<"\n\n\n\t\t\t Your Order booked successfully";
                cout<<"\n\n\n\t\t\t Your User-ID is: "<<s_id;
                cout<<"\n\n\n\t\t\t Our team member will call you for further process with in 1 hour";
             }
             else
             {
                 file>>id>>s_n>>s_ph>>f_code>>s_q;
                 while(!file.eof())
                 {
                  found++;
                  file>>id>>s_n>>s_ph>>f_code>>s_q;
                 }
                 file.close();
                 file.open("Seller.txt",ios::app|ios::out);
                 if(found==0)
                 {
                  s_id=1001;
                  file<<" "<<s_id<<" "<<s_name<<" "<<s_phone<<" "<<c<<" "<<s_quantity<<endl;
                  file.close();
                 }
                 else
                 {
                    s_id=id+1;
                    file<<" "<<s_id<<" "<<s_name<<" "<<s_phone<<" "<<c<<" "<<s_quantity<<endl;
                    file.close();
                 }
                 cout<<"\n\n\n\t\t\t Your Order booked successfully";
                 cout<<"\n\n\n\t\t\t Your User-ID is: "<<s_id;
                 cout<<"\n\n\n\t\t\t Our team member will call you for further process with in 1 hour";
        

            }
             
        }

    }
    
}
void mandi::order_booking_for_buy()
{
      system("cls");
    int found=0,b_id,id;
    string b_name,b_phone,b_ph,c,b_n;
    float b_quantity,b_q;
    fstream file;
    cout<<"\n\t\t\t\tOrder Booking For Buy";
    
    file.open("Fruit.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n\t\t\tNo Fruit Avaible";
        buyer();
        getch();
    }
    else
    {
        cout<<"\n\n Enter Fruit Code: ";
        cin>>c;
        file>>f_code>>f_name>>price>>quantity;
        while(!file.eof())
        {
            if(c==f_code)
            found++;
            file>>f_code>>f_name>>price>>quantity;
        }
        file.close();
        if(found==0)
        cout<<"\n\n\n\t\t\t Fruit Code Not Found...";
        else
        {
             cout<<"\n\n Enter Your Name: ";
             cin>>b_name;
             cout<<"\n\n Enter Your Phone no: ";
             cin>>b_phone;
             cout<<"\n\n Enter Fruit Quantity: ";
             cin>>b_quantity;
             file.open("Buyer.txt",ios::in);
             if(!file)
             {
                b_id=1001;
                file.open("Buyer.txt",ios::app|ios::out);
                file<<" "<<b_id<<" "<<b_name<<" "<<b_phone<<" "<<c<<" "<<b_quantity<<endl;
                file.close();
                cout<<"\n\n\n\t\t\t Your Order booked successfully";
                cout<<"\n\n\n\t\t\t Your User-ID is: "<<b_id;
                cout<<"\n\n\n\t\t\t Our team member will call you for further process with in 1 hour";
             }
             else
             {
                 file>>id>>b_n>>b_ph>>f_code>>b_q;
                 while(!file.eof())
                 {
                  found++;
                  file>>id>>b_n>>b_ph>>f_code>>b_q;
                 }
                 file.close();
                 file.open("Buyer.txt",ios::app|ios::out);
                 if(found==0)
                 {
                  b_id=1001;
                  file<<" "<<b_id<<" "<<b_name<<" "<<b_phone<<" "<<c<<" "<<b_quantity<<endl;
                  file.close();
                 }
                 else
                 {
                    b_id=id+1;
                    file<<" "<<b_id<<" "<<b_name<<" "<<b_phone<<" "<<c<<" "<<b_quantity<<endl;
                    file.close();
                 }
                 cout<<"\n\n\n\t\t\t Your Order booked successfully";
                 cout<<"\n\n\n\t\t\t Your User-ID is: "<<b_id;
                 cout<<"\n\n\n\t\t\t Our team member will call you for further process with in 1 hour";
        

            }
             
        }

    }
}
void mandi::check_selling_status()
{
    system("cls");
    int id,found=0,s_id;
    string s_name,s_phone;
    float s_quantity;
    fstream file;
    cout<<"\n\t\t\t\t Check Your Selling Order Status";
    
    file.open("Seller.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n\t\t\t No order found ";
        getch();
        seller();

    }
    else
    {
        cout<<"\n\n Enter Your Seller ID: ";
        cin>>id;
        file>>s_id>>s_name>>s_phone>>f_code>>s_quantity;
        while(!file.eof())
        {
            if(id==s_id)
            {
                found++;
            }
            file>>s_id>>s_name>>s_phone>>f_code>>s_quantity;

        }
        file.close();
        if(id>s_id||id<1001)
        cout<<"\n\n\n\t\t\t Your Seller ID is Invalid";
        else{
        if(found==0)
        cout<<"\n\n\n\t\t\t Your order is approved";
        else
        {
            cout<<"\n\n\n\t\t\t Your order on Pending State";
        }
        }
        
    }
}
void mandi::check_buying_status()
{
   system("cls");
    int id,found=0,b_id;
    string b_name,b_phone;
    float b_quantity;
    fstream file;
    cout<<"\n\t\t\t\t Check Your Buying Order Status";
    
    file.open("Buyer.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\n\t\t\t No order found ";
        getch();
        buyer();

    }
    else
    {
        cout<<"\n\n Enter Your Buyer ID: ";
        cin>>id;
        file>>b_id>>b_name>>b_phone>>f_code>>b_quantity;
        while(!file.eof())
        {
            if(id==b_id)
            {
                found++;
            }
            file>>b_id>>b_name>>b_phone>>f_code>>b_quantity;

        }
        file.close();
        if(id>b_id||id<1001)
        cout<<"\n\n\n\t\t\t Your Buyer ID is Invalid";
        else{
        if(found==0)
        cout<<"\n\n\n\t\t\t Your order is approved";
        else
        {
            cout<<"\n\n\n\t\t\t Your order on Pending State";
        }
        }
        
    }
}
int main()
{
   mandi m;
   m.menu();
}