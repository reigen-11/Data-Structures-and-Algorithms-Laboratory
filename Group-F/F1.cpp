#include <iostream>
#include <fstream>
using namespace std;

class Record
{
    int rollno;
    string name;
    int division;
    string address;

public:
    Record();
    int getRollno();
    void getData();
    void putData();
};

Record::Record()
{
    rollno = 0;
    name = "";
    address = "";
    division = 0;
}

int Record::getRollno()
{
    return rollno;
}

void Record::getData()
{
    cout << "\nEnter Details: ";
    cout << "\nRoll no: ";
    cin >> rollno;
    cout << "Name: ";
    cin >> name;
    cout << "Division Code: ";
    cin >> division;
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);
}

void Record::putData()
{
    cout << "\nRoll No.: " << rollno;
    cout << "\t\tName: " << name;
    cout << "\nDivision Code: " << division;
    cout << "\tAddress: " << address;
}

class File
{
    ifstream fin;
    ofstream fout;
    fstream fs;

public:
    void insert();
    void display();
    void search(int);
    int Delete(int);
    int edit(int);
};

void File::insert()
{
    Record r;
    r.getData();

    fout.open("StudentDB.txt", ios::app);
    fout.write((char *)&r, sizeof(r));
    fout.close();
}

void File::display()
{
    Record r;
    fin.open("StudentDB.txt", ios::in);
    while (fin.read((char *)&r, sizeof(r)))
    {
        r.putData();
    }
    fin.close();
}

void File::search(int rollno)
{
    Record r;
    bool found = false;
    fin.open("StudentDB.txt", ios::in);
    while (fin.read((char *)&r, sizeof(r)))
    {
        if (r.getRollno() == rollno)
        {
            found = true;
            break;
        }
    }
    fin.close();

    if (found)
    {
        cout << "\nRecord Found:";
        r.putData();
    }
    else
    {
        cout << "\nRecord not Found";
    }
}

int File::Delete(int rollno)
{
    Record r;
    bool found = false;

    fin.open("StudentDB.txt", ios::in);
    fout.open("Temp.txt", ios::app);
    while (fin.read((char *)&r, sizeof(r)))
    {
        if (r.getRollno() == rollno)
        {
            found = true;
        }
        else
        {
            fout.write((char *)&r, sizeof(r));
        }
    }
    fin.close();
    fout.close();

    remove("StudentDB.txt");
    rename("Temp.txt", "StudentDB.txt");

    return found ? 1 : 0;
}

int File::edit(int rollno)
{
    Record r;
    bool found = false;

    fs.open("StudentDB.txt", ios::in | ios::out);
    while (fs.read((char *)&r, sizeof(r)))
    {
        if (r.getRollno() == rollno)
        {
            found = true;
            cout << "\nEnter New Details: ";
            r.getData();
            fs.seekp((int)fs.tellg() - sizeof(r), ios::beg);
            fs.write((char *)&r, sizeof(r));
            break;
        }
    }
    fs.close();

    return found ? 1 : 0;
}

int main()
{
    File f;
    int ch, n, i, flag = 0;

    do
    {
        cout << "\n\n\t-----M E N U-----";
        cout << "\n\n1. Build A Master Table";
        cout << "\n2. List A Table";
        cout << "\n3. Insert a New Entry";
        cout << "\n4. Delete Old Entry";
        cout << "\n5. Edit an Entry";
        cout << "\n6. Search for a Record";
        cout << "\n7. Quit";
        cout << "\nEnter your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            if (flag == 0)
            {
                cout << "\nEnter No of Records to insert: ";
                cin >> n;
                for (i = 0; i < n; i++)
                {
                    f.insert();
                }
                flag = 1;
            }
            else
            {
                cout << "\nSorry.. Table is Already build... \nIf you want to add record, please select 'Insert a New Entry' option.";
            }
            break;
        case 2:
            f.display();
            break;
        case 3:
            f.insert();
            break;
        case 4:
            cout << "\nEnter Roll No of Student Whose Record is to be Deleted: ";
            cin >> n;
            i = f.Delete(n);
            if (i == 1)
                cout << "\nRecord Deleted Successfully";
            else
                cout << "\nRecord not Found";
            break;
        case 5:
            cout << "\nEnter Roll No of Student Whose Record is to be Edited: ";
            cin >> n;
            i = f.edit(n);
            if (i == 1)
                cout << "\nRecord Modified Successfully";
            else
                cout << "\nRecord not Found";
            break;
        case 6:
            cout << "\nEnter Roll No of Student Whose Record is to be Searched: ";
            cin >> n;
            f.search(n);
            break;
        case 7:
            break;
        default:
            cout << "\nEnter Valid Choice.....";
        }
    } while (ch != 7);

    return 0;
}

