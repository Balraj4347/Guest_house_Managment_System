/*
GUEST HOUSE MANAGMENT SYSTEM
USING C++ MYSQL AND XAMPP MyPhpAdmin Connection
BALRAJ GAHLOT 
*/

#include <iostream>
#include <windows.h>
#include <string.h>
#include <mysql.h>
#include<iomanip>
using namespace std;

void addguest(MYSQL* conn){
    string gid, gname, gphn, aadhar;
    cout<<"Enter GUEST_ID:";
    cin>>gid;
    cout<<"Enter GUEST_NAME:";
    cin>>gname;
    cout<<"Enter GUEST_PHN:";
    cin>>gphn;
    cout<<"Enter GUEST_AADHAR NO:";
    cin>>aadhar;

    string query;
    query = "INSERT INTO GUESTS VALUES(" + gid + ",'" + gname + "'," + gphn + ",'" + aadhar + "');";

    const char* q = query.c_str();

    cout<<"query is: "<<q<<endl;
    int qstate = mysql_query(conn,q);

    if(!qstate)
        cout<<"record inserted successfully..."<<endl;
    else
        cout<<"query problem: "<<mysql_error(conn)<<endl;
}

void showguests(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate = mysql_query(conn,"select * from GUESTS");

    if(!qstate)
    {
        res = mysql_store_result(conn);
        cout<<"\n\t****************************************************************************\n";
        cout<<"    \t "<<setw(9)<<"GUEST_ID"<<setw(9)<<"\t     G_NAME"<<setw(9)<<"\t    G_PHN"<<setw(9)<<"\t\tGUEST_AADHAR"<<setw(9)<<endl;
        while(row=mysql_fetch_row(res))
        {
            cout<<"\t  "<<setw(9)<<row[0]<<" \t   "<<setw(9)<<row[1]<<" \t  "<<setw(9)<<row[2]<<"\t\t"<<setw(9)<<row[3]<<""<<endl;
        }
        cout<<"\n\t****************************************************************************\n";
    }
    else
    {
        cout<<"query error: "<<mysql_error(conn)<<endl;
    }
}

void checkoutguest(MYSQL* conn){

    string id;
    cout<<"ENTER id of GUEST to remove: ";
    cin>>id;

    string query;
    query = "DELETE FROM GUESTS WHERE GUEST_ID="+id+";";

    const char* q = query.c_str();

    cout<<"query is: "<<q<<endl;
    int qstate = mysql_query(conn,q);

    if(!qstate)
        cout<<"GUEST REMOVED successfully..."<<endl;
    else
        cout<<"query problem: "<<mysql_error(conn)<<endl;
}

void addroom(MYSQL* conn){
    string rno, rcapacity, rtype;
    cout<<"Enter ROOM NO:";
    cin>>rno;
    cout<<"Enter ROOM CAPACITY:";
    cin>>rcapacity;
    cout<<"Enter ROOM TYPE:";
    cin>>rtype;

    string query;
    query = "INSERT INTO ROOM VALUES(" + rno + ",'" + rcapacity + "','" + rtype + "');";

    const char* q = query.c_str();

    cout<<"query is: "<<q<<endl;
    int qstate = mysql_query(conn,q);

    if(!qstate)
        cout<<"ROOM ADDED successfully..."<<endl;
    else
        cout<<"query problem: "<<mysql_error(conn)<<endl;
}

void showrooms(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate = mysql_query(conn,"select * from ROOM");

    if(!qstate)
    {
        res = mysql_store_result(conn);
        cout<<"\n\t****************************************\n";
        cout<<"\tROOM_NO"<<'\t'<<"    ROOM_CAPACITY"<<'\t'<<"ROOM_TYPE"<<'\t'<<endl;
        while(row=mysql_fetch_row(res))
        {
            cout<<"\t "<<row[0]<<"\t\t "<<row[1]<<"\t \t"<<row[2]<<'\t'<<endl;
        }
        cout<<"\n\t****************************************\n";
    }
    else
    {
        cout<<"query error: "<<mysql_error(conn)<<endl;
    }
}

void removeroom(MYSQL* conn){

    string id;
    cout<<"ROOM NO of ROOM to REMOVE: ";
    cin>>id;

    string query;
    query = "DELETE FROM ROOM WHERE ROOMNO="+id+";";

    const char* q = query.c_str();

    cout<<"query is: "<<q<<endl;
    int qstate = mysql_query(conn,q);

    if(!qstate)
        cout<<"ROOM REMOVED successfully..."<<endl;
    else
        cout<<"query problem: "<<mysql_error(conn)<<endl;
}

void bookroom(MYSQL* conn){
    string bid,gid, rid, book_date, checkout_date;
    cout<<"Give GUEST ID and ROOMNO for GUEST and ROOM to BOOK"<<endl;
    cout<<"BOOKING ID:";
    cin>>bid;
    cout<<"GUEST ID:";
    cin>>gid;
    cout<<"ROOM ID:";
    cin>>rid;

    cout<<"Date OF BOOKING:";
    cin>>book_date;
    cout<<"Date OF CHECKOUT:";
    cin>>checkout_date;

    string query;
    query = "INSERT INTO BOOKING VALUES(" + bid + "," + gid + ",'" + rid + "','" + book_date +"','" + checkout_date + "');";

    const char* q = query.c_str();

    cout<<"query is: "<<q<<endl;
    int qstate = mysql_query(conn,q);

    if(!qstate)
        cout<<"BOOKING DONE successfully..."<<endl;
    else
        cout<<"query problem: "<<mysql_error(conn)<<endl;
}

void showbookings(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate = mysql_query(conn,"select * from BOOKING");

    if(!qstate)
    {
        res = mysql_store_result(conn);
        cout<<"\n\t********************************************************************************\n";
        cout<<"\tBOOKING_ID"<<'\t'<<"GUEST_ID"<<'\t'<<" ROOMNO"<<'\t'<<"\t BOOKNG DATE"<<'\t'<<"CHECKOUT DATE"<<endl;
        while(row=mysql_fetch_row(res))
        {
            cout<<"\t"<<row[0]<<"\t\t   "<<row[1]<<"\t\t  "<<row[2]<<"\t\t "<<row[3]<<"\t"<<row[4]<<endl;
        }
        cout<<"\n\t*******************************************************************************\n";
    }
    else
    {
        cout<<"query error: "<<mysql_error(conn)<<endl;
    }
}

void removebooking(MYSQL* conn){

    string bid;
    cout<<"ENTER BOOKING ID TO REMOVE BOOKING:\n";
    cout<<"BOOKING ID: ";
    cin>>bid;

    string query;
    query = "DELETE FROM BOOKING WHERE bookingid="+bid+";";

    const char* q = query.c_str();

    cout<<"query is: "<<q<<endl;
    int qstate = mysql_query(conn,q);

    if(!qstate)
        cout<<"BOOKING REMOVED successfully..."<<endl;
    else
        cout<<"query problem: "<<mysql_error(conn)<<endl;
}

void menu(MYSQL* conn){
    bool ch = true;

    while(ch){
        int choice;
        cout<<"\n\t\t\t********Welcome to GUEST HOUSE Management System:*******\n"
            <<"\t\t\t1. ADD NEW GUEST\n"
            <<"\t\t\t2. ADD NEW ROOM\n"
            <<"\t\t\t3. REMOVE GUEST\n"
            <<"\t\t\t4. REMOVE ROOM\n"
            <<"\t\t\t5. BOOK ROOM TO GUEST\n"
            <<"\t\t\t6. CHECKOUT GUEST FROM ROOM\n"
            <<"\t\t\t7. Print All Tables\n"
            <<"\t\t\t8. Exit\n";
        cout<<"\t\t\tEnter your choice: ";
        cin>> choice;

        switch(choice){
            case 1: {
                    addguest(conn);
                    cout<<"\n\n Current Table: \n";
                    showguests(conn);
                    break;
                }
            case 2: {
                    addroom(conn);
                    cout<<"\n\n Current Table: \n";
                    showrooms(conn);
                    break;
                }
            case 3: {
                    cout<<"\n\n Current Table: \n";
                    showguests(conn);
                    checkoutguest(conn);
                    break;
                }
            case 4: {
                    cout<<"\n\n Current Table: \n";
                    showrooms(conn);
                    removeroom(conn);
                    break;
                }
            case 5: {
                    cout<<"\n\n Current Tables: \n";
                    showguests(conn);
                    showrooms(conn);
                    bookroom(conn);
                    cout<<"\n\n Current BOOKING: \n";
                    showbookings(conn);
                    break;
                }
            case 6: {
                    cout<<"\n\n Current BOOKING: \n";
                    showbookings(conn);
                    removebooking(conn);
                    break;
                }
            case 7: {
                    cout<<"\n\n THE TABLES ARE: \n ";
                    cout<<"\nGUESTS: \n";
                    showguests(conn);
                    cout<<"\nROOMS: \n";
                    showrooms(conn);
                    cout<<"\nBOOKING: \n";
                    showbookings(conn);
                    break;
                }
            case 8: {
                    ch = false;
                    break;
                }
        }
    }
}

int main()
{
     MYSQL* conn;
     int qstate;


     conn = mysql_init(0);

     conn = mysql_real_connect(conn,"localhost","root","","guesthouse",3306,NULL,0);

     if(conn){
        menu(conn);
     }
     else
        cout<<"connection failure: "<<mysql_error(conn)<<endl;

    return 0;
}
