#include<iostream>
#include<fstream>
#include<windows.h>
#include <sstream>
#include <string>
#include<windows.h>
using namespace std;
class studentManagementSystem{
    public:
    string sname,scontactno,srollno,saddress;
    void modify();
    void deleteData();
    void search();
    void menu(){
        int option;
        char response;
        system("CLS");
    // SetConsoleTextAttribute(h,11);
    startCode:
    //SetConsoleTextAttribute(h,11);

        cout<<"\t\t\t\t|-------------------------------------------------------|"<<endl;
        cout<<"\t\t\t\t|------------< STUDENT MANAGEMENT SYSTEM >--------------|"<<endl;
        cout<<"\t\t\t\t|------------< GHODAGHODI MULTIPLE CAMPUS >-------------|"<<endl;
        cout<<"\t\t\t\t|-------------------------------------------------------|"<<endl;

        cout<<"---------------> CHOOSE OPTION 1 TO 6 ! "<<endl;


        cout<<"\t\t\t\t[<1>] INSERT NEW RECORD !"<<endl;
        cout<<"\t\t\t\t[<2>] DELETE RECORD !"<<endl;
        cout<<"\t\t\t\t[<3>] EDIT RECORD !"<<endl;
        cout<<"\t\t\t\t[<4>] SEARCH RECORD !"<<endl;
        cout<<"\t\t\t\t[<5>] DISPLAY RECORD !"<<endl;
        cout<<"\t\t\t\t[<6>] MODIFY RECORD !"<<endl;
        cout<<"\t\t\t\t[<7>] EXIT !"<<endl;

        
        cout<<"\t\t\t\t------------> Enter a Option : "<<endl;
        cin>>option;

        switch (option)
        {
        case 1:
            do
            {
                insert();
                cout<<"\n\t\t\tAdd Another Student Record [Y/N] : ";
                cin>>response;
            } while (response == 'Y' || response == 'y');
            
            break;

        case 2:
        deleteData();
        break;


        case 4:
        search();
        break;


        case 5:
            display();
            break;

        case 6:
        modify();
        break;

        case 7:
            exit(0);
            break;
        
        
        default:
            break;
        }

       
    }
    void insert(){
			system("cls");
			fstream file;
			cout<<"\n\t\t\t|------------------------------------------------|"<<endl;
			cout<<"\n\t\t\t|-----------------INSERT RECORD------------------|"<<endl;
			cout<<"\n\t\t\t|------------------------------------------------|"<<endl;
			
			cout<<"\t\t \t|------------------->Enter Name of Student:";
            
            cin.ignore();
            getline(cin,sname);
			cout<<"\t\t\t Enter Contact no of Student:";
			cin>>scontactno;
			cout<<"\t\t\t Enter Roll no of Student:";
			cin>>srollno;
			cout<<"\t\t\t Enter Address  of Student:";
			cin>>saddress;
			file.open("student.txt",ios::out | ios::app);
    
			file<<" " <<sname <<" "<<scontactno<<" "<<srollno<<" "<<saddress<<"\n";
			file.close();
            char num;
            cout<<"\t\t\t|------------> EXIT PROGRAM [Y/N] : ";
            cin>>num;
            if(num == 'N' || num == 'n'){
                menu();
            }else{
                exit(0);
            }
		}


        void display(){

    int totalStudent=0;
    system("cls");
    fstream file;
    cout<<"|------------------------------------------------|"<<endl;
    cout<<"|-------------< RECORD OF STUDENT >--------------|"<<endl;
    cout<<"|------------------------------------------------|"<<endl;
    file.open("student.txt", ios :: in);
    if(!file){
        cout<<"Current file is not opening !";
        file.close();
    }
    string line;


    while (getline(file, line)){
        cout<< line<< endl;
        totalStudent++;
    }
   if(totalStudent==0){

    if( file.tellg() == -1){
    cout<<"\n\t\t\t NO RECORD FOUND !";
    }
   }

    char num;
            cout<<"\n\n\n\t\t\t|------------> EXIT PROGRAM [Y/N] : ";
            cin>>num;
            if(num == 'N' || num == 'n'){
                menu();
            }else{
                exit(0);
            }


}

};


//Display dtata


int main()
{
 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
studentManagementSystem obj1;
obj1.menu();

return 0;
}//@rajendra_chimala;


void studentManagementSystem::search(){
    fstream file("student.txt");
   

    if(!file){
        cout<<"Error opening File !" ;
        return;


    }

    string inputRollNo;
    cout<<"|----------------------------> Enter the rool no of student : ";
    cin>>inputRollNo;




bool found = false;

string line;
while(getline(file,line)){
    istringstream iss(line);
//<<sname <<" "<<scontactno<<" "<<srollno<<" "<<saddress<<
    if(iss>> sname >> scontactno >> srollno >> saddress){
       // cout<<sname;
        if(srollno == inputRollNo){
            found = true;
            cout<<"Name : "<<sname<<"\n";
            cout<<"Contact No  : "<<scontactno<<"\n";
            cout<<"Roll No : "<<srollno<<"\n";
            cout<<"Address  : "<<saddress<<"\n";
            break;
        }
    }
}

if(!found)

    cout<<"|---------------------------> Student Record Not Found !";
    file.close();

}


void studentManagementSystem::deleteData(){
    system("CLS");
    string rollno;
    int found =0;
    fstream file, file1;
cout<<"|------------------------------------------------|"<<endl;
cout<<"|-------------< RECORD OF STUDENT >--------------|"<<endl;
cout<<"|------------------------------------------------|"<<endl;
file.open("student.txt",ios::in);
if(!file){
    cout<<"\n\n|-----------------------------> RECORD DOES NOT FOUND !";

}
else{
    cout<<"|-----------------> Enter Roll No ofstudent which you want delete datat : ";
    cin>>rollno;
    file1.open("record.txt",ios::app|ios::out);
    file>>sname>>scontactno>>srollno>>saddress;
    while (!file.eof())
    {

       if (rollno != srollno)
       {
        file1<<" "<<sname<<" "<<scontactno<<" "<<srollno<<" "<<saddress<<"\n";
       }
       found++;
    
    file>>sname>>scontactno>>srollno>>saddress;
    }

if(found==0){
    cout<<"\n\n|---------------------------> Student Roll NO not Found !";
}
file1.close();
file.close();
remove("student.txt");
rename("record.txt","student.txt");

}
}


void studentManagementSystem::modify(){

     system("CLS");
    string rollno;
    int found =0;
    fstream file, file1;
cout<<"|------------------------------------------------|"<<endl;
cout<<"|-------------< RECORD OF STUDENT >--------------|"<<endl;
cout<<"|------------------------------------------------|"<<endl;
file.open("student.txt",ios::in);
if(!file){
    cout<<"\n\n|-----------------------------> RECORD DOES NOT FOUND !";

}
else{
    cout<<"|-----------------> Enter Roll No ofstudent which you want modify Data  : ";
    cin>>rollno;
    file1.open("record.txt",ios::app|ios::out);
    file>>sname>>scontactno>>srollno>>saddress;
    while (!file.eof())
    {

       if (rollno != srollno)
       {
        file1<<" "<<sname<<" "<<scontactno<<" "<<srollno<<" "<<saddress<<"\n";
       }else{
        cout<<"\t\t \t|------------------->Enter Name of Student:";
            
            cin.ignore();
            getline(cin,sname);
			cout<<"\t\t\t Enter Contact no of Student:";
			cin>>scontactno;
			cout<<"\t\t\t Enter Roll no of Student:";
			cin>>srollno;
			cout<<"\t\t\t Enter Address  of Student:";
			cin>>saddress;
        file1<<" "<<sname<<" "<<scontactno<<" "<<srollno<<" "<<saddress<<"\n";

            
   found++;
            

       }
    
    
    file>>sname>>scontactno>>srollno>>saddress;
    }

if(found==0){
    cout<<"\n\n|---------------------------> Student Roll NO not Found !";
}
file1.close();
file.close();
remove("student.txt");
rename("record.txt","student.txt");

}


}