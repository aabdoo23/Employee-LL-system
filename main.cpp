#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define endll '\n'

template<class T>
T catcher(T e){
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input. Enter a NUMBER: ";
        cin>>e;
    }
    return e;
}
string input(){
    string s;
    getline(cin,s);
    while (s.empty()){
        cout<<"Invalid Input.\nPlease enter a non empty line: ";
        getline(cin,s);
    }
    return s;
}

class employee{
private:
    string Full_Name,Email,Phone,Position;
    double Salary;
public:
    //constructors
    employee(){
        Full_Name="";
        Email="";
        Phone="";
        Position="";
        Salary=0;
    }
    employee(string FN,string E,string P, string Pos, double S){
        Full_Name=FN;
        Email=E;
        Phone=P;
        Position=Pos;
        Salary=S;
    }
    //setters
    void setFull_Name(string s){Full_Name=s;}
    void setEmail(string s){Email=s;}
    void setPhone(string s){Phone=s;}
    void setPosition(string s){Position=s;}
    void setSalary(double n){Salary=n;}
    //getters
    string getFN(){return Full_Name;}
    string getE(){return Email;}
    string getPN(){return Phone;}
    string getPos(){return Position;}
    double getS(){return Salary;}
    //Functions
    void display_employee_info(){
        cout<<"=========================\n";
        cout<<"Full Name: \t"<<getFN()<<endll;
        cout<<"Email: \t\t"<<getE()<<endll;
        cout<<"Phone Number: \t"<<getPN()<<endll;
        cout<<"Position: \t"<<getPos()<<endll;
        cout<<"Salary= \t"<<getS()<<"$\n";
        cout<<"=========================\n";
    }
    void setAllInfo(){

        cout<<"Enter Full Name: ";
        cin.ignore();
        Full_Name=input();
        cout<<"Enter Email: ";
        cin>>Email;
        cout<<"Enter Phone Number: ";
        cin>>Phone;
        cout<<"Enter Position: ";
        cin>>Position;
        cout<<"Enter Salary: ";
        cin>>Salary;
        Salary=catcher(Salary);
    }
};
template <class T>
class Node{
public:
    T emp;
    Node<T>* next;
    //node constructor
    Node(T e){
        emp =e;
        next = nullptr;
    }
};
template <class T>
class EmployeeList{
    Node<T>* head;
public:
    EmployeeList(){head= nullptr;}

    bool insert_employee(T e){
        auto* newNode = new Node<T>(e);
        if(head == nullptr){ //if not initialized
            head = newNode;
            cout<<newNode->emp.getE()<<" is added to the list"<<endll;
            return true;
        }
        Node<T>* tmp = head;
        while(tmp != nullptr){ //check if same email exists
            if(tmp->emp.getE()==e.getE()){
                cout<<"Employee with the same email already exists.\n";
                return false;
            }
            tmp = tmp->next;
        }
        tmp=head;
        while (tmp->next!= nullptr){
            tmp=tmp->next;
        }

        tmp->next = newNode;
        cout<<e.getE()<<" is added to the list\n";
        return true;
    }
    bool edit_salary(string em,double nws){
        Node<T>* tmp=head;

        while(tmp != nullptr){
            if(tmp->emp.getE()==em){
                tmp->emp.setSalary(nws);
                cout<<"Salary changed\n";
                return true;
            }
            tmp = tmp->next;//iterator
        }
        cout<<"!!Email not found.!!\n";
        return false;
    }
    bool delete_employee(string em){
        Node<T> *tmp=head, *prev=head;
        if (head == nullptr)return true;
        if(head->emp.getE()==em){//if delete head
            head = head->next;
            delete tmp;
            cout<<em<<" deleted successfully. :D\n";
            return true;
        }
        while(tmp != nullptr){//else
            if(tmp->emp.getE()==em){
                prev->next=tmp->next;
                delete tmp;
                cout<<em<<" deleted successfully. <3\n";
                return true;
            }
            prev=tmp;
            tmp = tmp->next;//iterator
        }
        cout<<"!!Email not found.!!\n";
        return false;
    }
    bool update_info(string em){//bonus
        Node<T> *tmp=head;
        while(tmp != nullptr){
            if(tmp->emp.getE()==em){
                cout<<"Email found\nWhich attribute do you want to change?\n";
                cout<<"1.Full Name\n"
                    <<"2.Email\n"
                    <<"3.Phone Number\n"
                    <<"4.Position\n"
                    <<"5.Salary\n";
                int n;
                cin>>n;n=catcher(n);
                string s;
                double nw;
                if(n==1){
                    cout<<"Enter new name: ";
                    cin.ignore();
                    s=input();
                    tmp->emp.setFull_Name(s);
                    cout<<"Name changed successfully\n";
                }
                else if(n==2){
                    cout<<"Enter new Email: ";
                    cin.ignore();
                    cin>>s;
                    tmp->emp.setEmail(s);
                    cout<<"Email changed successfully\n";
                }
                else if(n==3){
                    cout<<"Enter new phone number: ";
                    cin.ignore();
                    cin>>s;
                    tmp->emp.setPhone(s);
                    cout<<"Phone number changed successfully\n";
                }
                else if(n==4){
                    cout<<"Enter new position: ";
                    cin.ignore();
                    cin>>s;
                    tmp->emp.setPosition(s);
                    cout<<"Position changed successfully\n";
                }
                else if(n==5){
                    cout<<"Enter new Salary: ";
                    cin>>nw;
                    nw=catcher(nw);
                    tmp->emp.setSalary(nw);
                    cout<<"Salary changed successfully\n";
                }
                else cout<<"Invalid Input.\n";
                return true;
            }
            tmp = tmp->next;//iterator
        }
        cout<<"!!Email not found!!\n";
        return false;
    }
    void printList()
    {
        int cnt=1;
        Node<T>* curr=head;
        while (curr != nullptr) {
            cout<<"Employee number "<<cnt<<" :\n";
            curr->emp.display_employee_info();
            curr = curr->next;
            cnt++;
        }
        cout<<"\n=======End of list=======\n\n";
    }
};

int main() {
    employee x;
    EmployeeList<employee>s;
    string email;
    double nw;
    cout<<"\tWelcome to the Employee Management System\n";
    while (true){
        cout
        <<"==================================================\n"
        <<"Choose of the following to use the system features\n"
        <<"1. Insert a new Employee\n"
        <<"2. Edit employee's salary\n"
        <<"3. Delete an employee\n"
        <<"4. Update employee info\n"
        <<"5. Print all employees\n"
        <<"6. Close the program\n";
        int n;
        cin>>n;
        n=catcher(n);
        if(n==1) {
            x.setAllInfo();
            s.insert_employee(x);
        }
        else if(n==2){
            cout<<"Enter email: ";
            cin.ignore();
            cin>>email;
            cout<<"Enter new salary: ";
            cin>>nw;
            nw=catcher(nw);
            s.edit_salary(email,nw);
        }
        else if (n==3){
            cout<<"Enter email: ";
            cin.ignore();
            cin>>email;
            s.delete_employee(email);
        }
        else if(n==4){
            cout<<"Enter email: ";
            cin.ignore();
            cin>>email;
            s.update_info(email);
        }
        else if(n==5)s.printList();
        else if(n==6){cout<<"Thank you, bye bye.";sleep(2);return 0;}
        else cout<<"Invalid input.\n";
    }
}
