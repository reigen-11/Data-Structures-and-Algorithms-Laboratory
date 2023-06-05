#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;

void addEmployee(){
    ofstream f("db.txt", ios::app);

    string employee_id, name, educataion, salary;

    cout<<"--- ADD Employee IN DATABASE ---"<<endl;

    cout<<"Enter Employee ID : ";
    cin>>employee_id;
    cout<<"\nEnter Employee Name : ";
    cin>>name;
    cout<<"\nEnter Employee Designamtion : ";
    cin>>educataion;
    cout<<"\nEnter Employee Salary : ";
    cin>>salary;
    cout<<endl;

    f<<left<<setw(20)<<employee_id<<setw(20)<<name <<setw(20)<< educataion <<setw(20)<<salary<<endl;
    cout<<"Employee Added Successfully.\n";
    f.close();

}

void deleteEmployee() {
    ifstream inputFile("db.txt");
    string line;
    string employee_id;
    cout << "Enter Employee ID To Delete: ";
    cin >> employee_id;

    vector<string> fileLines;
    while (getline(inputFile, line)) {
        if (line.substr(0, line.find(' ')) != employee_id) {
            fileLines.push_back(line);
        }
    }

    inputFile.close();

    ofstream outputFile("db.txt", ios::out | ios::trunc);
    for (size_t i = 0; i < fileLines.size(); ++i) {
        outputFile << fileLines[i] << endl;
    }

    outputFile.close();
}

void searchEmployee(){
    ifstream f("db.txt");
    string line;
    string employee_id;
    cout<<"Enter Employee ID To Search : ";
    cin>>employee_id;

    bool found = false;

    while(getline(f,line)){
        if(line.find(employee_id) != string::npos){
            cout<<"Employee Details: "<<endl;
            cout<<"\n"<<line <<endl;
            found =true;
            break;
        }
    }
    f.close();

    if(!found){
        cout<<"Sorry, Not found"<<endl;
    }

}

void displayData(){
    ifstream f("db.txt");
    string line;
    cout<<"\nDisplaying Data :- "<<endl;
    while(getline(f,line)){
        cout<<"\n"<<line<<endl;
    }
    f.close();
}

int main(){

    ofstream f("db.txt", ios::out);
    f<<left<<setw(20) << "Employee ID" << setw(20) << "Name" << setw(20) << "educataion" << setw(20) <<"salary"<<endl;
    f.close();

    int choice;
    while(choice != -1){
        cout<<"\n--------- M E N U -----------"<<endl;
        cout<<"1. Add Employee."; 
        cout<<"\n2. Delete Employee.";
        cout<<"\n3. Search Employee. ";
        cout<<"\n4. Display Data.";
        cout<<"\n5. Exit. "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                displayData();
                break;
            case 5:
                return 0;
                break;
            default:
                cout<<"Please ReEnter Your Choice: ";
                break;
        }

    }
}
