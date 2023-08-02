#include<iostream>//input ouput sathi aapan he use karto
#include<conio.h>//it give clrscr()and getch(); function
#include <windows.h>//system("cls"); sathi 
#include<iomanip> //iomanip for manipulation table or in practice
#include<stdlib.h>//didn't effect on this code if its not there 
#include<string.h>//string la include karnya sathi
#include<fstream>//file managment function use karnya sathi
#include<stdio.h>//this also don't show any effect
#include<process.h>//this also don't effect on code
using namespace std;
//here we have to  create two classes book and student
class book{
    char bno[6];
    char bname[25];
    char aname[20];
    public:
    //classes madhe je function aahet je nanter cha functions madhe use hotat
    void createbook(){
        cout<<"CREATE A NEW BOOK"<<endl;
        cout<<"enter the book number"<<endl;
        cin>>bno;
        cout<<"enter the book name"<<endl;
        //gets(bname);//gets aani puts same as cin and cout
        cin>>bname;
        cout<<"enter the auther name"<<endl;
        //gets(aname);
        cin>>aname;
        cout<<"BOOK CREATED"<<endl;
    }
    void showbook(){
        cout<<"bool number : "<<bno<<endl;
        cout<<"book name: ";
        puts(bname);
        cout<<"auther name: ";
        puts(aname);

    }
    void modifybook(){
        cout<<"book number : "<<bno;
        cout<<"enter book name :"<<gets(bname);
        cout<<"enter auther name :"<<gets(aname);

    }
    char* retno(){
        return bno;
    }
    void report(){
        cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
    }
};
class student{
    char admisionnumber[6];
    char sname[20];
    char stbno[6];
    int token;//number of book issued
    public:
    void createstudent(){
        system("cls");
        cout <<"NEW STUDENT ENTRY ."<<endl;
        cout<<"enter admission number "<<endl;
        cin>>admisionnumber;
        cout<<"enter student name "<<endl;
        cin>>sname;//gets(sname);//gets pahije hota 

        token=0;
        stbno[0]='\0'; //here in stbno arrey at 0th position we assign NULL or initiate it with null
        cout<<"student record created";
    }
    void showstudent(){
        cout<<"admission number : "<<admisionnumber;
        cout<<"student name :";
        cout<<sname;
        cout<<"\nNumber of book issued :"<<token;
        if(token==1){
            cout<<"\nbook number"<<stbno;
        }
    }
    void modifystudent(){
        cout<<"\nAdmission number "<<admisionnumber;
        cout<<"\nModify student name :";
        cin>>sname;//gets(sname);
    }
    char* retadno(){
        return admisionnumber; 
    }
    char* retsbno(){
        return stbno; 
    }
    int rettoken(){
        return token;
    }
    void addtoken(){
        token=1;
    }
    void resettoken(){
        token =0;
    }
    void getstbno(char t[]){
        strcpy(stbno,t);
    }
    void report(){
        cout<<"\t"<<admisionnumber<<setw(20)<<sname<<setw(10)<<token<<endl;
    }

};

fstream fp ,fp1;
student st;
book bk;

void writebook(){
    char ch;
    fp.open("book.txt",ios::out|ios::app);
    do{
        system("cls");
        bk.createbook();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\n\nDo you want to add more books (y/n)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void writestudent(){
    char ch;
    fp.open("student.txt",ios::out|ios::app);
    do{
        system("cls");
        st.createstudent();
        fp.write((char*)&st,sizeof(student));
        cout<<"\n\nDo you want to add more student (y/n)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void displayspb(char n[]){
    cout<<"\nBook details\n";
    int flag =0;
    fp.open("book.txt",ios::in);
    
    while(fp.read((char*)&bk,sizeof(book))){
        if(strcmpi(bk.retno(),n)==0){
            bk.showbook();
            flag=1;

        }
    }
    fp.close();
    if(flag==0){
        cout<<"book does not exist";
        getch();
    }
}

void displaysps(char n[]){
    cout<<"\nstudent details\n";
    int flag =0;
    fp.open("student.txt",ios::in);
    
    while(fp.read((char*)&st,sizeof(student))){
        if(strcmpi(st.retadno(),n)==0){
            st.showstudent();
            flag=1;
        }
    }
    fp.close();
    if(flag==0){
        cout<<"student does not exist";
        getch();
        }
}
void modifybook(){
    char n[6];
    int found =0;
    system("cls");
    cout<<"\n\nMODIFY BOOK RECORD";
    cout<<"\n\nENTER THE BOOK NO.";
    cin>>n;
    fp.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book))&&found==0){
        if(strcmpi(bk.retno(),n)==0){
           bk.showbook();
           cout<<"\nENTER THE NEW DETAILS OF BOOK";
           bk.modifybook();
           int pos =-1*sizeof(bk);//read kelyaver pointer samor chalala jato mhanun tyala parat aanila
           fp.seekp(pos,ios::cur);
           fp.write((char*)&bk,sizeof(book));
           cout<<"\n\n\tRecord updated";
           found=1;
          }
    }
    fp.close();
    if(found==0){
                cout<<"\n\nRecord not found";
    }
    getch();
}

void modifystudent(){
    char n[6];
    int found =0;
    system("cls");
    cout<<"\n\nMODIFY STUDENT RECORD";
    cout<<"\n\nENTER THE BADMISSION NO.";
    cin>>n;
    fp.open("student.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&&found==0){
        if(strcmpi(st.retadno(),n)==0){
           st.showstudent();
           cout<<"\nENTER THE NEW DETAILS OFstudent";
           st.modifystudent();
           int pos =-1*sizeof(st);//read kelyaver pointer samor chalala jato mhanun tyala parat aanila
           fp.seekp(pos,ios::cur);
           fp.write((char*)&st,sizeof(student));
           cout<<"\n\n\tRecord updated";
           found=1;
          }
    }
    fp.close();
    if(found==0){
                cout<<"\n\nRecord not found";
    }
    getch();
}
 void deletestudent(){
    char n[6];
    int flag=0;
    system("cls");
    cout<<"\n\n\n\tDELETE THE STUDENT";
    cout<<"\n\nENTER THE ADMISSION NUMBER";
    cin>>n;
    fp.open("student.txt",ios::in|ios::out);
    fstream fp2;
    fp2.open("temp.txt",ios::out);
    fp.seekg(0,ios::beg);//reset the pointer at the begiing
    while(fp.read((char*)&st,sizeof(student))){
        if(strcmpi(st.retadno(),n)!=0){
            fp2.write((char*)&st,sizeof(student));

        }
        else{
            flag=1;
        }
    }
    fp2.close();
    fp.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
    if(flag==1){
        cout<<"\n\nRECORD DELETED";
    }
    else{ 
        cout<<"\n\nrecord not found";
    }
    getch();

 }

void deletebook(){
    char n[6];
    int flag=0;
    system("cls");
    cout<<"\n\n\n\tDELETE THE book";
    cout<<"\n\nENTER THE book NUMBER";
    cin>>n;
    fp.open("book.txt",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.txt",ios::out);
    fp.seekg(0,ios::beg);//reset the pointer at the begiing
    while(fp.read((char*)&bk,sizeof(book))){
   if(strcmpi(bk.retno(),n)!=0){
            fp2.write((char*)&bk,sizeof(book));

        }
        else{
            flag=1;
        }
    }
    fp2.close();
    fp.close();
    remove("book.txt");
    rename("Temp.txt","book.txt");
    if(flag==1){
        cout<<"\n\nRECORD DELETED";
    }
    else{ 
        cout<<"\n\nrecord not found";
    }
    getch();

 }

void displayalls(){
    system("cls");
    fp.open("student.txt",ios::in);
    if(!fp){
        cout<<"file could not be open";
        getch();
        return;
    }
    cout<<"\n\n\tstudent list\n\n";
    cout<<
    "==============================================================="<<endl;
    cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"bookissued\n";
    cout<<
    "================================================================"<<endl;
    while(fp.read((char*)&st,sizeof(student))){
        st.report();
    }
    fp.close();
    getch();
}
void displayallb(){
    system("cls");
    fp.open("book.txt",ios::in);
    if(!fp){
        cout<<"file could not be open";
        getch();
        return;
    }
    cout<<"\n\n\tbook list\n\n";
    cout<<
    "========================================================================="<<endl;
    cout<<"\nbook number."<<setw(30)<<"book Name"<<setw(35)<<"book auther\n";
    cout<<
    "========================================================================="<<endl;
    while(fp.read((char*)&bk,sizeof(book))){
        bk.report();
    }
    fp.close();
    getch();
}

void bookissue(){
    char sn[6],bn[6];
    int found=0,flag=0;
    system("cls");
    cout<<"\n\nBOOK ISSUE ..";
    cout<<"\n\n\tENTER THE ADMISSION NUMBER OF THE STUDENT";
    cin>>sn;
    fp.open("student.txt",ios::in|ios::out);
    fp1.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&&found==0){
        if(strcmpi(st.retadno(),sn)==0){
            /////////
           if(st.rettoken()==0){
                       found=1;////////
            cout<<"enter the book number";
            cin>>bn;
            while(fp1.read((char*)&bk,sizeof(book))&&flag==0){
                if(strcmpi(bk.retno(),bn)==0){
                    bk.showbook();
                    flag=1;
                    st.addtoken();
                    st.getstbno(bk.retno());
                    int pos =-1*sizeof(st);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&st,sizeof(student));
                    cout<<"\n\n\tbook issued successfully\n\n please note: write thr book issue date in backside of your book else fin";            
                }
            }
            if(flag==0){
                cout<<"\nbook number does not exiest";
            }          
           } 
           else{
            cout<<"you have not returne the last book";
           }
        }
    }
    if(found==0){
        cout<<"\nstudent record does not exiest";

    }
    getch();
    fp.close();
    fp1.close();
}

void bookdeposit(){
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    system("cls");
    cout<<"\n\nBOOK deposit ..";
    cout<<"\n\n\tENTER THE ADMISSION NUMBER OF THE STUDENT";
    cin>>sn;
    fp.open("student.txt",ios::in|ios::out);
    fp1.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&&found==0){
        if(strcmpi(st.retadno(),sn)==0){
            found=1;
           if(st.rettoken()==1){
            while(fp1.read((char*)&bk,sizeof(book))&&flag==0){
                if(strcmpi(bk.retno(),st.retsbno())==0){
                    flag=1;
                    bk.showbook();
                    cout<<"\n\nbook deposited in no. of days :";
                    cin>>day;
                    if(day>15){
                        fine=(day-15)*1;
                        cout<<"\n\nfine has to deposited"<<fine;                      
                    }
                    st.resettoken();
                    int pos =-1*sizeof(st);
                    fp.seekg(pos,ios::cur);
                    fp.write((char*)&st,sizeof(student));
                    cout<<"\n\n\tbook deposited successfully";            
                }
            }
            if(flag==0){
                cout<<"\nbook number does not exiest";
            }          
           } 
           else{
                        cout<<"no book is issued";
           }
        }
    }
    if(found==0){
        cout<<"\nstudent record does not exiest";

    }
    getch();
    fp.close();
    fp1.close();
}
  
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void start(){
    system("cls");//this clear the screan 
    gotoxy(80,0);//aani kuthe lihaicha aahe tithe curcer jato
    cout << "LIBRARY MANAGMENT SYSTEM ";
    cout << "\n\n        Developer   =   Sujal dharme";
    getch();//it wait for some time and after getting any letter or index it run

}
void adminmenu(){
    system("cls");
    int ch2;
    cout<<"\n\n\n\tADMINISTRATION MENU";
    cout<<"\n\n\t1. Create student record";
    cout<<"\n\n\t2. display all student name ";
    cout<<"\n\n\t3. display specific student name ";
    cout<<"\n\n\t4. modify student name ";
    cout<<"\n\n\t5. delete student name from list";
    cout<<"\n\n\t6. Create new book";
    cout<<"\n\n\t7. display all book ";
    cout<<"\n\n\t8. display specific book";
    cout<<"\n\n\t9. modify book name ";
    cout<<"\n\n\t10. delete book name ";
    cout<<"\n\n\t11. back to MAIN MANU";
    cout<<"\n\n\tchoose any option from (1-11)";
    cin>>ch2;
    switch(ch2){
        case 1:
        system("cls");
        writestudent();
        break;
        case 2:
        displayalls();
        break;
        case 3:
        char num[6];
        system("cls");
        cout<<"\n\n\tPLEASE ENTER THE ADMISSION NUMBER.";
        cin>>num;
        displaysps(num);
        getch();
        break;
        case 4:
        modifystudent();
        break;
        case 5:
        deletestudent();
        break;
        case 6:
        writebook();
        break;
        case 7:
        displayallb();
        break;
        case 8:
        char num1[6];
        system("cls");
        cout<<"\n\n\tPLEASE ENTER THE BOOK NUMBER.";
        cin>>num1;
        displayspb(num1);
        getch();
        break;
        case 9:
        modifybook();
        break;
        case 10:
        deletebook();
        break;
        case 11:
        return;
        default:
        cout<<"invalid choice try again";
        break;
    }


}
int main(){
   char ch;
   start();
   do{
    system("cls");
    cout<<"\n\n\n\tMAIN MENU";
    cout<<"\n\n\t01. BOOK ISSUE";
    cout<<"\n\n\t02. BOOK DEPOSIT";//here \n means in next line and in \n\n mean 2 lines
    cout<<"\n\n\t03. ADMIMISTRATION MENU";
    cout<<"\n\n\t04. EXIT";
    cout<<"\n\n\tPLEASE SELECT YOUR OPTION(1-4)";
    ch=getche();//the difference bitween getch and getche is getche show the entered number
    //cin>>ch;
    switch(ch){
        case '1':
        bookissue();
        break;
        case '2':
        bookdeposit();
        break;
        case '3':
        adminmenu();
        break;
        case '4':
        exit(0);//exit ka direct yehi function he
        break;
        default:
        cout<<"INVALID CHOICE,TRY AGAIN";
        break;
    }

   }while(ch!=4);//ek vela jar 4 cha equal zala t mag he menu nahi dakhavnar
 

    return 0;
}