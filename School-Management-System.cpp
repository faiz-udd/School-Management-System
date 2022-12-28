#include<iostream>
//#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<limits>
#define sizeLA 50
#define sizeSA 50
#define sizeEA 50
#define sizeTS 50
#define sizelab 50
#define sizeCL 50
using namespace std;
//............this is class of human
class Human
{
protected:
	string name;
	string fathers_name;
	int age;
	string dob;
	string gender;
	string address;
public: 
//constructor initialized
	Human() :name(" "), fathers_name(" "), age(0), dob(" "), gender(" "), address(" ") {}
    //we have virtual Function ;A virtual function in C++ is a base class member function 
    //that you can redefine in a derived class to achieve polymorphism. 
	virtual void set_info();
};
void Human::set_info()
{
	cout << "Enter name: ";
    //The cin. ignore() function is used which is used to ignore or 
    //clear one or more characters from the input buffer.
	cin.ignore();
    //getline is used to get string type with all spaces, if we take cin instead, it will only take
    //the string before first space entry, it will not take after space
	getline(cin, name);
	cout << "Enter father's name: ";
	cin.ignore();
	getline(cin, fathers_name);
	cout << "Enter age: ";
	cin >> age;
	cout << "Enter date of birth: ";
	cin.ignore();
	getline(cin, dob);
	cout << "Enter address: ";
	cin.ignore();
	getline(cin, address);
	cout << "Enter gender: ";
	cin.ignore();
	getline(cin, gender);
}
//............this is class of human
class Book
{
	string title;
	string name;
	string Authors[4];
	int numberofAuthor;
	string publisher;
	int ISBN;
	int price;
	int copies;
public:
//class constructor
	Book() :title(" "), name(" "), Authors(), numberofAuthor(0), publisher(" "), ISBN(0), price(0), copies(0) {}
	//member Functions declarations
    void set_book();
	void display_book();
	void search_a_book_by_its_name(Book[]);
	void search_a_book_by_its_ISBN(Book[]);
};
void Book::set_book()
{
	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter Title: ";
	cin.ignore();
	getline(cin, title);
	cout << "Enter Publisher: ";
	cin.ignore();
	getline(cin, publisher);
	cout << "Enter Number of Authors: ";
	cin >> numberofAuthor;
	for (int i = 0; i < numberofAuthor; i++)
	{
		cout << "Enter Author " << i + 1 << " :";
		cin.ignore();
		getline(cin, Authors[i]);
	}
	cout << "Enter ISBN: ";
	cin >> ISBN;
	cout << "Enter Price: ";
	cin >> price;
	cout << "Enter number of copies available: ";
	cin >> copies;
}
void Book::display_book()
{
	cout << "Title: " << title;
	cout << endl;
	cout << "Name: " << name;
	cout << endl;
	for (int i = 0; i < numberofAuthor; i++)
	{
		cout << "Authors " << i + 1 << ": " << endl;
		cout << Authors[i];
		cout << endl;
	}
	cout << "Number of Authors are: " << numberofAuthor;
	cout << endl;
	cout << "Publisher:" << publisher;
	cout << endl;
	cout << "ISBN: " << ISBN;
	cout << endl;
	cout << "Price: " << price;
	cout << endl;
	cout << "Copes in Stock" << copies;
	cout << endl;
}
void Book::search_a_book_by_its_ISBN(Book books[sizeLA])
{
	int ISBN;
	cout << "Enter ISBN: ";
	cin >> ISBN;
	for (int i = 0; i < sizeLA; i++)
	{
		if (books[i].ISBN == ISBN)
		{
			cout << endl;
			cout << "Record Founded";
			books[i].display_book();
			break;
		}
	}
	cout << endl << "Record Not Founded";
}
void Book::search_a_book_by_its_name(Book books[sizeLA])
{
	string name;
	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, name);
	for (int i = 0; i < sizeLA; i++)
	{
		if (books[i].name == name)
		{
			cout << endl;
			cout << "Record Founded";
			books[i].display_book();
			break;
		}
	}
	cout << endl << "Record Not founded";
}
//Fees class
class Fees
{
	int tution_fee;
	int miscellaneous_fee;
	int lab_fee;
	int library_fee;
	int total_fee;
public:
	Fees() :tution_fee(10000), miscellaneous_fee(5000), lab_fee(2500), library_fee(1250) {};
	void calculate_fee();//calculate fees
	void set_fees();//set fees
	int operator+();//operator overloaded to sum up all the expenses/fees
	void display_fee();//display fees
};
//Functions definitions
void Fees::set_fees()
{
	cout << "Please enter tution fees: ";
	cin >> tution_fee;
	cout << endl;
	cout << "Please enter miscellaneous_fee: ";
	cin >> miscellaneous_fee;
	cout << endl;
	cout << "Please enter lab fees: ";
	cin >> lab_fee;
	cout << endl;
	cout << "Please enter library fees: ";
	cin >> library_fee;
	cout << endl;
}
int Fees::operator+()
{
	total_fee = miscellaneous_fee + lab_fee + library_fee + tution_fee;
	return total_fee;
}
void Fees::display_fee()
{
	Fees::operator+();
	cout << "Total fee is" << total_fee;
}

//Attendence class
class Attendance
{
    //data members
	int total_no_of_days;
public:
//member functions
	void set_Attendance();
	void display_attendence();
};
//Functions definitions
void Attendance::set_Attendance()
{
	static int n = 0;
	string Attendance;
	cout << "Attendance?: " << endl;
	cin >> Attendance;
	if (Attendance == "present")
	{
		n++;
	}
	else
	{
		cout << "Student has been marked abscent" << endl;
	}
	total_no_of_days = n;
}
void Attendance::display_attendence()
{
	cout << "Total No of days of Attendance of student is: " << total_no_of_days;
	cout << endl;
}
//Class Salary
class Salary
{
	int basic_pay;
	int allowence;
	int bonus;
	int total_pay;
public:
	Salary() :basic_pay(0), allowence(0), bonus(0), total_pay(0) {}
	void set_Salary();
	void display_salary();
	int operator+();
};
void Salary::set_Salary()
{
	cout << "Please enter Basic Pay: ";
	cin >> basic_pay;
	cout << "Please enter Allowence: ";
	cin >> allowence;
	cout << "Please enter bonus";
	cin >> bonus;
	cout << endl;
}
int Salary::operator+()
{
	total_pay = basic_pay + allowence + bonus;
	return total_pay;
}
void Salary::display_salary()
{
	Salary::operator+();
	cout << "Total Pay is: " << total_pay;
}
/// Class Progress report
class Progressreport
{
	float marks[5];
	float totalm;
	string subject[5];
	float per;
	string grade;
public:
	Progressreport() :marks(), totalm(0), subject(), per(0.0), grade(" ") {}
	void setmarks();
	void showmarks();
};
//Functions definitions
void Progressreport::setmarks()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter Subject name: ";
		cin >> subject[i];
		cout << "Enter it's marks: ";
		cin >> marks[i];
	}
}
void  Progressreport::showmarks()
{
	float t;
	t = 0;
	for (int i = 0; i < 5; i++)
	{
		t = t + marks[i];
	}
	totalm = t;
	cout << "Total marks: " << totalm;
	cout << endl;
	per = totalm / 500 * 100;
	cout << "Percentage: " << per;
	cout << endl;
	if (per >= 80)
	{
		grade = "A";
	}
	else if (per >= 75)
	{
		grade = "B+";
	}
	else if (per >= 70)
	{
		grade = "B";
	}
	else if (per >= 65)
	{
		grade = "C+";
	}
	else if (per >= 60)
	{
		grade = "C";
	}
	else if (per >= 55)
	{
		grade = "D+";
	}
	else if (per >= 50)
	{
		grade = "D";
	}
	else
	{
		grade = "F";
	}
	cout << "Grade of the Student is: " << grade;
	cout << endl;
}
//Employee class, inherited From Human Class
class Employee :public Human
{
protected:
	string education;
	int employee_no;
	string contact_no;
	string email;
	Salary s;
public:
	Employee() :education(" "), employee_no(0), contact_no(" "), email(" ") {}
	void set_info();
	void display_info()const;
	void search_by_employee_no(Employee[]);
	void search_by_name(Employee[]);
	void set_salary(Employee[]);
	void show_salary(Employee[]);
};
//Functions definitions
void Employee::set_salary(Employee employees[sizeEA])
{
	int reg_no;
	cout << "Enter employee no: ";
	cin >> employee_no;
	int check = 0;
	for (int i = 0; i < sizeEA; i++)
	{
		if (employees[i].employee_no == employee_no)
		{
			employees[i].s.set_Salary();
			cout << "Successfully added";
			check++;
			break;
		}

	}
	if (check == 0)
		cout << "Record Not Found ";

}
void Employee::show_salary(Employee employees[sizeEA])
{
	int reg_no;
	cout << "Enter employee no: ";
	cin >> employee_no;
	int check = 0;
	for (int i = 0; i < sizeEA; i++)
	{
		if (employees[i].employee_no == employee_no)
		{
			employees[i].s.display_salary();
			check++;
			break;
		}

	}
	if (check == 0)
		cout << "Record Not Found";
}
void Employee::set_info()
{
	Human::set_info();
	cout << "Enter employee no: ";
	cin >> employee_no;
	cout << "Enter education: ";
	cin.ignore();
	getline(cin, education);
	cout << "Enter contact no: ";
	cin.ignore();
	getline(cin, contact_no);
	cout << "Enter email: ";
	cin.ignore();
	getline(cin, email);
}
void Employee::display_info()const
{
	cout << "Name: " << name << endl;
	cout << "Fathers name: " << fathers_name << endl;
	cout << "Employee no: " << employee_no << endl;
	cout << "Gender: " << gender << endl;
	cout << "Age: " << age << endl;
	cout << "Education: " << education << endl;
	cout << "Date of birth: " << dob << endl;
	cout << "Contact no: " << contact_no << endl;
	cout << "Email: " << email << endl;
	cout << "Address: " << address << endl;
}
void Employee::search_by_employee_no(Employee employees[sizeEA])
{
	int reg_no;
	cout << "Enter employee no: ";
	cin >> employee_no;
	int check = 0;
	for (int i = 0; i < sizeEA; i++)
	{
		if (employees[i].employee_no == employee_no)
		{
			cout << "Record founded" << endl;
			employees[i].display_info();
			check++;
			break;
		}

	}
	if(check==0)
	cout << endl << "Record Not Founded";
}
void Employee::search_by_name(Employee  employees[sizeEA])
{
	string sname;
	cout << "Enter Employee name ";
	int check = 0;
	cin.ignore();
	getline(cin, sname);
	for (int i = 0; i < sizeEA; i++)
	{
		if (employees[i].name == sname)
		{
			cout << "Record founded" << endl;
			employees[i].display_info();
			check++;
			break;
		}

	}
	if(check==0)
	cout << endl << "Record Not Founded";
}
//Student class  inherited from Human Class
class Student :public Human
{
	int reg_no;
	Progressreport result;
	string contact_no;
	string email;
	string fathers_contact_number;
	Attendance at;
	Fees fees;
public:
	Student() :reg_no(0), contact_no(" "), email(" "), fathers_contact_number(" ") {}
	void set_info();
	void display_info();
	void search_by_reg_no(Student[]);
	void search_by_name(Student[]);
	void calculate(Student students[]);
	void show_progress_report(Student[]);
	void setmarks(Student[]);
	void set_Attendance(Student[]);
	void display_Attendece(Student[]);
	void set_fees(Student[]);
	void display_fees(Student[]);
};
void Student::set_fees(Student students[sizeSA])
{
	int reg_no;
	cout << "Enter registration no: ";
	cin >> reg_no;
	int check = 0;
	for (int i = 0; i < sizeSA; i++)
	{
		if (students[i].reg_no == reg_no)
		{
			cout << "Record founded" << endl;
			students[i].fees.set_fees();
			check++;
			break;
		}

	}
	if (check == 0)
		cout << "Record Not Found";
}
void Student::calculate(Student students[sizeSA])
{
	int reg_no;
	cout << "Enter registration no: ";
	cin >> reg_no;
	int check = 0;
	for (int i = 0; i < sizeSA; i++)
	{
		if (students[i].reg_no == reg_no)
		{
			cout << "Record founded" << endl;
			students[i].fees.display_fee();
			check++;
			break;
		}

	}
	if (check == 0)
		cout << "Not Found";
}
void Student::display_fees(Student students[sizeSA])
{
	int reg_no;
	cout << "Enter registration no: ";
	cin >> reg_no;
	int check = 0;
	for (int i = 0; i < sizeSA; i++)
	{
		if (students[i].reg_no == reg_no)
		{
			cout << "Record founded" << endl;
			students[i].fees.display_fee();
			check++;
			break;
		}

	}
	if (check == 0)
		cout << "NOT FOUND";
}
void Student::display_Attendece(Student students[sizeSA])
{
	int reg_no;
	cout << "Enter registration no: ";
	cin >> reg_no;
	int check = 0;
	for (int i = 0; i < sizeSA; i++)
	{
		if (students[i].reg_no == reg_no)
		{
			cout << "Record founded" << endl;
			students[i].at.display_attendence();
			check++;
			break;
		}

	}
	if (check == 0)
		cout << "Not Found ";
}
void Student::show_progress_report(Student students[sizeSA])
{
	int reg_no;
	cout << "Enter registration no: ";
	cin >> reg_no;
	int check = 0;
	for (int i = 0; i < sizeSA; i++)
	{
		if (students[i].reg_no == reg_no)
		{
			cout << "Record founded" << endl;
			students[i].result.showmarks();
			check++;
			break;
		}

	}
	if (check == 0)
		cout << "Not Found";
}
void Student::set_Attendance(Student students[sizeSA])
{
	int reg_no;
	cout << "Enter registration no: ";
	cin >> reg_no;
	int check = 0;
	for (int i = 0; i < sizeSA; i++)
	{
		if (students[i].reg_no == reg_no)
		{
			cout << "Record founded" << endl;
			students[i].at.set_Attendance();
			cout << "Record added successfuly" << endl;
			check++;
			break;
		}

	}
	if (check == 0)
		cout << "Not Found";
}
void Student::setmarks(Student students[sizeSA])
{
	int reg_no;
	int check = 0;
	cout << "Enter registration no: ";
	cin >> reg_no;
	for (int i = 0; i < sizeSA; i++)
	{
		if (students[i].reg_no == reg_no)
		{
			cout << "Record founded" << endl;
			students[i].result.setmarks();
			cout << "Marks added succesfully" << endl;
			check++;
			break;
		}

	}
	if (check == 0)
		cout << "NOT FOUND";
}
void Student::set_info()
{

	Human::set_info();
	cout << "Enter reg no: ";
	cin >> reg_no;
	cout << "Enter contact no: ";
	cin.ignore();
	getline(cin, contact_no);
	cout << "Enter email: ";
	cin.ignore();
	getline(cin, email);
	cout << "Enter fathers contact no: ";
	cin.ignore();
	getline(cin, fathers_contact_number);
}
void Student::display_info()
{
	cout << "Name: " << name << endl;
	cout << "Fathers name: " << fathers_name << endl;
	cout << "Registartion no: " << reg_no << endl;
	cout << "Gender: " << gender << endl;
	cout << "Age: " << age << endl;
	cout << "Date of birth: " << dob << endl;
	cout << "Contact no: " << contact_no << endl;
	cout << "Fathers contact no: " << fathers_contact_number << endl;
	cout << "Email: " << email << endl;
	cout << "Address: " << address << endl;
	result.showmarks();
	at.display_attendence();
}
void Student::search_by_reg_no(Student students[sizeSA])
{
	int reg_no;
	cout << "Enter registration no: ";
	cin >> reg_no;
	int check = 0;
	for (int i = 0; i < sizeSA; i++)
	{
		if (students[i].reg_no == reg_no)
		{
			cout << "Record founded" << endl;
			students[i].display_info();
			check++;
			break;
		}

	}
	if(check==0)
	cout << endl << "Record Not found";
}
void Student::search_by_name(Student a[sizeSA])
{
	string sname;
	cout << "Enter Student name ";
	int check = 0;
	cin.ignore();
	getline(cin, sname);
	for (int i = 0; i < sizeSA; i++)
	{
		if (a[i].name == sname)
		{
			cout << "Record founded" << endl;
			a[i].display_info();
			check++;
			break;
		}

	}
	if(check==0)
	cout << endl << "Record Not founded";
}
//class Transport
class Transport {
private:
	int vehicle_no;
	string vehicle_type;
	string vehicle_colour;
	int vehicle_capacity;
	string route;
public:
	void set_vehicleinfo();
	void get_vehicleinfo();
	void set_route();

};
void Transport::set_vehicleinfo()
{
    //set info of the vehicles and write in the file
	cout << "enter vehicle no";
	cin >> vehicle_no;
	cout << "enter vehicle colour";
	cin >> vehicle_colour;
	cout << "enter vehicle type";
	cin >> vehicle_type;
	cout << "enter vehicle capacity";
	cin >> vehicle_capacity;
    //open write file
	ofstream transport("transport.txt", ios::app);
	transport.open("transport.txt", ios::app);
    //write in the transport.txt file
	transport << vehicle_no << endl;
	transport << vehicle_colour << endl;
	transport << vehicle_capacity << endl;
	transport << vehicle_type << endl;
	transport.close();
}
void Transport::get_vehicleinfo() {
	cout << "vehicle no::" << vehicle_no << endl;
	cout << "vehicle colour::" << vehicle_colour << endl;
	cout << " vehicle type::" << vehicle_type << endl;
	cout << "vehicle capacity::" << vehicle_capacity << endl;
	cout << "route::" << route << endl;

}
void Transport::set_route() {
	cout << "enter route";
	cin >> route;
    //set the route of the vehicle and save to the file
	ofstream file("file.txt");
	file.open("file.txt");
	file << route;
	file.close();
}

//Lab class
class Lab {
	string LabID, InchargeID, InchargeName, LabName, EquipmentNo;
public:
	Lab() :LabID(" "), InchargeID(" "), InchargeName(" "), LabName(" "), EquipmentNo(" ") {}
	void SetLabDetails();
	void DispLabDetails()const;
};

void Lab::SetLabDetails() {
	cout << "Enter LAB Details\nEnter LAB ID:";
	cin.ignore();
	getline(cin, LabID);
	cout << "Enter Incharge ID:";
	cin.ignore();
	getline(cin, InchargeID);
	cout << "Enter Incharge Name:";
	cin.ignore();
	getline(cin, InchargeName);
	cout << "Enter Lab Name:";
	cin.ignore();
	getline(cin, LabName);
	cout << "Enter Number of equipments:";
	cin.ignore();
	getline(cin, EquipmentNo);

}
void Lab::DispLabDetails()const
{
	cout << "LAB Name:" << LabName << endl;
	cout << "LAB id:" << LabID << endl;
	cout << "LAB Incharge Name:" << InchargeName << endl;
	cout << "LAB Incharge ID:" << InchargeID << endl;
	cout << "Number of equipments:" << EquipmentNo << endl;

}
// class room class
class Classroom {
private:
	string ClassName;
	string Classid;
	string TeacherID;
	string StdCount;
public:
	Classroom() :ClassName(" "), Classid(" "), TeacherID(" "), StdCount(" ") {}
	void SetClassDetails();
	void DispClassDetails()const;
};

void Classroom::SetClassDetails()
{
	cout << "Enter Class Details\nEnter Class Name:";
	cin.ignore();
	getline(cin, ClassName);
	cout << "Enter Class ID:";
	cin.ignore();
	getline(cin, Classid);
	cout << "Enter Class Teacher's ID:";
	cin.ignore();
	getline(cin, TeacherID);
	cout << "Enter Number of Students in Class:";
	cin.ignore();
	getline(cin, StdCount);

}
void Classroom::DispClassDetails() const
{
	cout << "Class Name:" << ClassName << endl;
	cout << "Class id:" << Classid << endl;
	cout << "Class Teacher's ID:" << TeacherID << endl;
	cout << "Class Total Strenth:" << StdCount << endl;
}
class SchoolManagement
{
	string SchoolName, Address, ContactNumber;
public:
	SchoolManagement() :SchoolName(" "), Address(" "), ContactNumber(" ") {}
	void isOpen();
	void SetSchoolDetails();
	void DispSchoolDetails()const;
};
void SchoolManagement::isOpen()
{
	cout << "School is OPEN from MONDAY to SATURDAY from 6AM to 5PM\n";
}
void SchoolManagement::SetSchoolDetails()
{
	cout << "Enter School Details\nEnter School Name:";
	cin.ignore();
	getline(cin, SchoolName);
	cout << "Enter School Address:";
	cin.ignore();
	getline(cin, Address);
	cout << "Enter School's Contact Number:";
	cin.ignore();
	getline(cin, ContactNumber);
}
void SchoolManagement::DispSchoolDetails()const
{
	cout << "SCHOOL NAME:" << SchoolName << endl;
	cout << "SCHOOL Address:" << Address << endl;
	cout << "SCHOOL's Contact Number:" << ContactNumber << endl;
}
void screen()
{
	cout << "\n\n\n\n\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
	cout << "\n\t\t*\t                             \t\t\t\t\t\t        \t*";
	cout << "\n\t\t*\t##################################################################################\t*";
	cout << "\n\t\t*\t##################################################################################\t*";
	cout << "\n\t\t*\t##\t\t\t\t\t\t\t\t\t\t##\t*";
	cout << "\n\t\t*\t##\t\t\t\t  WELCOME TO       \t\t\t        ##\t*";
	cout << "\n\t\t*\t##\t\t\t\tSCHOOL MANAGEMENT\t\t\t\t##\t*";
	cout << "\n\t\t*\t##\t\t\t\t\t\t\t\t\t\t##\t*";
	cout << "\n\t\t*\t##################################################################################\t*";
	cout << "\n\t\t*\t##################################################################################\t*";
	cout << "\n\t\t*\t                             \t\t\t\t\t\t        \t*";
	cout << "\n\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
}
int main(void)
{
	screen();
	Employee employees[sizeEA];
	Employee tempobj1;
	Student students[sizeSA];
	Student tempobj;
	Book books[sizeLA];
	Book tempobj2;
	Transport transport[sizeTS];
	Lab labs[sizelab];
	int choice;
	static int lab = 0;
	int labt = 0;
	static int cl = 0;
	int clt = 0;
	static int transport_var = 0;
	int transport_total = 0;
	static int book_var = 0;
	int book_total = 0;
	int no_of_students;
	static int total_students = 0;
	static int pos_student = 0;
	int no_of_employees;
	static int pos_employee;
	static int total_employees = 0;
	int choice1;
	static int total_books = 0;
	static int total_classrooms = 0;
	static int total_labs = 0;
	static int total_no_busses = 0;
	SchoolManagement school;
	Classroom classroom[sizeCL];
main:
	do {
		cout << endl;
		cout << "Welcome to School Management System" << endl;
		cout << "1. To manage Student information" << endl;
		cout << "2. To manage Employee information" << endl;
		cout << "3. To manage Progress report of student" << endl;
		cout << "4. To manage Attendance of student" << endl;
		cout << "5. To manage fees of students" << endl;
		cout << "6. To manage salary of employees" << endl;
		cout << "7. To manage Library" << endl;
		cout << "8. To manage Transport" << endl;
		cout << "9. To manage Lab" << endl;
		cout << "10. To manage school attributes" << endl;
		cout << "11. To manage class rooms" << endl;
		cout << "12. To exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice1;
		cout << endl;
		switch (choice1)
		{
		case 1:
			system("cls");
			cout << "1. To add a new student" << endl;
			cout << "2. To display record of all students" << endl;
			cout << "3. Search by name" << endl;
			cout << "4. Search by registration number" << endl;
			cout << "Enter choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				try
				{
					if (total_students > sizeSA)
					{
						throw total_students;
					}
				}
				catch (int ex)
				{
					cout << "Record full" << endl;
					break;
				}
				cout << "How many students you want to add?: ";
				cin >> no_of_students;
				for (int i = pos_student; i < no_of_students; i++)
				{
					students[i].set_info();
					cout << "Record added succesfully" << endl;
					total_students = total_students + 1;
				}
				break;
			case 2:
				system("cls");
				for (int i = 0; i < total_students; i++)
				{
					students[i].display_info();
					cout << endl << endl;
					cout << "Record and Particulars of Student " << i + 1 << "are as under: ";
					cout << endl;
				}
				break;
			case 3:
				system("cls");
				tempobj.search_by_name(students);
				break;
			case 4:
				system("cls");
				tempobj.search_by_reg_no(students);
				break;
			}goto main;
		case 2:
			system("cls");
			cout << "1. To add a new employee" << endl;
			cout << "2. To display info of all employees" << endl;
			cout << "3. To search a employee by employee name" << endl;
			cout << "4. To search a employee by employee no" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				try
				{
					if (total_employees > sizeEA)
					{
						throw total_employees;
					}
				}
				catch (int ex)
				{
					cout << "Record full" << endl;
					break;
				}
				system("cls");
				cout << "Enter number of employees you want to add: ";
				cin >> no_of_employees;
				cout << endl;
				for (int i = pos_employee; i < no_of_employees; i++)
				{
					employees[i].set_info();
					cout << "Record added successfully";
					total_employees = total_employees + 1;
				}
				break;
			case 2:
				system("cls");
				for (int i = 0; i < total_employees; i++)
				{
					employees[i].display_info();
				}
				break;
			case 3:
				system("cls");
				tempobj1.search_by_name(employees);
				break;
			case 4:
				system("cls");
				tempobj1.search_by_employee_no(employees);
				break;
			}goto main;
		case 3:
			system("cls");
			cout << "1. To add a grade of student" << endl;
			cout << "2. To display a progress report of particular student" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				tempobj.setmarks(students);
				break;
			case 2:
				system("cls");
				tempobj.show_progress_report(students);
				break;
			}goto main;
		case 4:
			cout << "1. To add a Attendance of student" << endl;
			cout << "2. To display Attendance of student" << endl;
			cout << "Enter choice: " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				tempobj.set_Attendance(students);
				break;
			case 2:
				system("cls");
				tempobj.display_Attendece(students);
				break;
			}goto main;
		case 5:
			cout << "1. To set a fees of a student." << endl;
			cout << "2. To display a fees of a particular student" << endl;
			cout << "Enter choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				tempobj.set_fees(students);
				break;
			case 2:
				system("cls");
				tempobj.calculate(students);
				break;
			}goto main;
		case 6:
			cout << "1. To add a salary of an employee" << endl;
			cout << "2. To show a salary of an employee";
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				tempobj1.set_salary(employees);
				break;
			case 2:
				system("cls");
				tempobj1.show_salary(employees);
				break;
			}goto main;
		case 7:
			cout << "1. To add a new book" << endl;
			cout << "2. To display info of all books" << endl;
			cout << "3. To search a book by its name" << endl;
			cout << "4. To search a book by its ISBN" << endl;
			cout << "Enter your choice";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << endl;
				try
				{
					if (total_books > sizeLA)
					{
						throw total_books;
					}
				}
				catch (int ex)
				{
					cout << "Record full" << endl;
					break;
				}
				system("cls");
				cout << "How many books you want to enter: ";
				cin >> book_total;
				for (int i = book_var; i < book_total; i++)
				{
					books[i].set_book();
					total_books = total_books + 1;
				}
				break;
			case 2:
				system("cls");
				for (int i = 0; i < book_total; i++)
				{
					cout << "Record of Book" << i + 1;
					books[i].display_book();
					cout << endl;
					cout << endl;
				}
				break;
			case 3:
				system("cls");
				tempobj2.search_a_book_by_its_name(books);
				break;
			case 4:
				system("cls");
				tempobj2.search_a_book_by_its_ISBN(books);
				break;
			}goto main;
		case 8:
			cout << "1. To add bus" << endl;
			cout << "2. To set a route" << endl;
			cout << "3. To display info of busses and routes" << endl;
			cout << "Please enter your choice";
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				try
				{
					if (total_no_busses > sizeTS)
					{
						throw total_no_busses;
					}
				}
				catch (int ex)
				{
					cout << endl << "Record full";
					break;
				}
				cout << "How many busses you want to add";
				cin >> transport_total;
				for (int i = transport_var; i < transport_total; i++)
				{
					transport[i].set_vehicleinfo();
					total_no_busses = total_no_busses + 1;
				}
				break;
			case 2:
				system("cls");
				cout << "How many routes you want to set";
				cin >> choice;

				for (int i = 0; i < choice; i++)
				{
					transport[i].set_route();
				}
				break;
			case 3:
				system("cls");
				for (int i = 0; i < sizeLA; i++)
				{
					transport[i].get_vehicleinfo();
					cout << endl;
				}
				break;
			}goto main;
		case 9:
			system("cls");
			cout << "1. To add a lab person" << endl;
			cout << "2. To display record of a lab attendents" << endl;
			cout << "Enter your choice";
			cin >> choice;
			switch (choice)
			{
			case 1:
				try
				{
					if (total_labs > sizelab)
					{
						throw total_labs;
					}
				}
				catch (int ex)
				{
					cout << "Record full" << endl;
					break;
				}
				system("cls");
				cout << "How many lab incharges you want to add";
				cin >> labt;
				for (int i = lab; i < labt; i++)
				{
					labs[i].SetLabDetails();
					total_labs = total_labs + 1;
				}
				break;
			case 2:
				system("cls");
				for (int i = 0; i < lab; i++)
				{
					labs[i].DispLabDetails();
				}
				break;
			}goto main;
		case 10:
			cout << "1. To set school details" << endl;
			cout << "2. To display school details" << endl;
			cout << "Please enter your choice";
			cin >> choice;
			switch (choice)
			{
			case 1:
				school.SetSchoolDetails();
				break;
			case 2:
				school.DispSchoolDetails();
				school.isOpen();
				break;
			}goto main;
		case 11:
			cout << "1. To add classrooms" << endl;
			cout << "2. To display info of all classrooms" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				try
				{
					if (total_classrooms > sizeCL)
					{
						throw total_classrooms;
					}
				}
				catch (int ex)
				{
					cout << "Record full " << endl;
					break;
				}
				cout << "Enter How many classes you want to add";
				cin >> clt;
				for (int i = cl; i < clt; i++)
				{
					classroom[i].SetClassDetails();
					total_classrooms = total_classrooms + 1;
				}
				break;
			case 2:
				for (int i = 0; i < clt; i++)
				{
					cout << "Details of classroom" << i + 1 << "are: " << endl;
					classroom[i].DispClassDetails();
					cout << endl;
					cout << endl;
				}
			}goto main;
		case 12:
			exit(0);
		}
	} while (choice != 12);
	system("pause");
}