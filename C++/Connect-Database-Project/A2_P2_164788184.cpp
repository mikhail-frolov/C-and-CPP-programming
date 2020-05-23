#define _CRT_SECURE_NO_WARNINGS
#include <mysql.h>
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <iomanip>
using namespace std;

struct Employee {
	int employeeNumber;
	char lastName[50];
	char firstName[50];
	char email[100];
	char phone[50];
	char extension[10];
	char reportsTo[100];
	char jobTitle[50];
	char city[50];
};




int findEmployee(MYSQL* conn, int employeeNumber, struct Employee* emp)
{

	int value = 0;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int exequery;

	if (conn) {

		// cout << "successful connection to database" << endl;

		string query = "select e.employeeNumber, e.lastName, e.firstName, e.email, o.phone, e.extension, e.reportsTo, e.jobTitle, o.city from employees e, offices o where e.officeCode = o.officeCode and e.employeeNumber = ";
		query += to_string(employeeNumber);
		query += ";";

		const char* q = query.c_str();
		exequery = mysql_query(conn, q);

		if (!exequery) {
			//query execution is successful
			//cout << "The query executed successfully with no error." << endl;

			res = mysql_store_result(conn);
			if (mysql_affected_rows(conn) < 1 || res == nullptr)
			{
				value = 0;
			}
			else
			{
				value = 1;
				while (row = mysql_fetch_row(res))
				{
					// stoi from string to int
					emp->employeeNumber = std::stoi(row[0]);
					strcpy_s(emp->lastName, row[1]);
					strcpy_s(emp->firstName, row[2]);
					strcpy_s(emp->email, row[3]);
					strcpy_s(emp->phone, row[4]);
					strcpy_s(emp->extension, row[5]);
					strcpy_s(emp->reportsTo, row[6]);
					strcpy_s(emp->jobTitle, row[7]);
					strcpy_s(emp->city, row[8]);

				}
			}
		}
		else
		{
			//query execution is not successful
			cout << "Error message: " << mysql_error(conn) << mysql_errno(conn) << endl;
		}
	}
	else
	{
		cout << "Connection Failed" << mysql_error(conn) << endl;
	}
	return value;
}


void displayEmployee(MYSQL* conn, struct Employee emp) {
	int num = 0;
	cout << "Enter employee number: ";
	cin >> num;

	if (findEmployee(conn, num, &emp) == 0) {

		cout << "Employee " << num << " does not exist." << endl << endl;

	}
	else {

		cout << "employeeNumber = " << emp.employeeNumber << endl;
		cout << "lastName = " << emp.lastName << endl;
		cout << "firstName = " << emp.firstName << endl;
		cout << "email = " << emp.email << endl;
		cout << "phone = " << emp.phone << endl;
		cout << "extension = " << emp.extension << endl;
		cout << "reportsTo = " << emp.reportsTo << endl;
		cout << "jobTitle = " << emp.jobTitle << endl;
		cout << "city = " << emp.city << endl << endl;

	}


}

void displayAllEmployees(MYSQL* conn) {

	MYSQL_ROW row;
	MYSQL_RES* res;
	int exequery;

	if (conn) {

		// cout << "successful connection to database" << endl;

		string query = "select e.employeeNumber as E, concat(e.firstName, ' ', e.lastName) as EmployeeName, e.email, o.phone, e.extension, coalesce(concat(m.firstName, ' ', m.lastName), ' ') as managerName from employees e left join employees m on e.reportsTo = m.employeeNumber left join offices o on e.officeCode = o.officeCode;";
		const char* q = query.c_str();
		exequery = mysql_query(conn, q);


		if (!exequery) {
			//query execution is successful
			//cout << "The query executed successfully with no error." << endl;

			res = mysql_store_result(conn);
			if (res == nullptr)
			{
				cout << "There is no employees’ information to be displayed." << endl;
			}
			else
			{
				cout << setw(10) << left << "E" << setw(24) << "Employee Name" << setw(35) << "Email"
					<< setw(18) << "Phone" << setw(13) << "Ext" << setw(22) << "Manager" << endl;
				cout << std::setfill('-') << setw(110);
				cout << "-" << endl;
				cout << endl;
				cout << setfill(' ');
				while (row = mysql_fetch_row(res))
				{
					cout << setw(10) << left << row[0] << setw(20) << row[1] << setw(36) << row[2] << setw(20) << row[3] << setw(10) << row[4] << setw(8) << row[5] << endl;
				}
			}
		}
		else
		{
			//query execution is not successful
			cout << "Error message: " << mysql_error(conn) << mysql_errno(conn) << endl;
		}
	}
	else
	{
		cout << "Connection Failed" << mysql_error(conn) << endl;
	}
	cout << endl;
}

void insertEmployee(MYSQL* conn, struct Employee emp) {

	    cout << "Employee Number: ";
		cin >> emp.employeeNumber;

	if (findEmployee(conn, emp.employeeNumber, &emp) == 1) {
		cout << endl;
		cout << "An employee with the same employee number already exists." << endl << endl;
	}
	else {
	//defaukt values
		int office_code = 1;
		string reportsTo = "1002";

		cout << "Last Name: ";
		cin >> emp.lastName;
		cout << "Firts Name: ";
		cin >> emp.firstName;
		cout << "Email: ";
		cin >> emp.email;
		cout << "Extension: ";
		cin >>  emp.extension;
		cout << "Job Title: ";
		cin >> emp.jobTitle;
		cout << "Manager ID (reports to #): ";
		cin >> reportsTo;
		cout << "City: ";
		cin >> emp.city;

		// comparing city to get the office code number

		if (strcmp(emp.city, "San Francisco") == 0)
		{
			office_code = 1;
			
		}
		
		if (strcmp(emp.city, "Boston") == 0) {
			office_code = 2;
		}
		 if (strcmp(emp.city, "NYC") == 0 || strcmp(emp.city, "New York") == 0)
		{
			office_code = 3;
		}
		 if (strcmp(emp.city, "Paris") == 0)
		{
			office_code = 4;
		}
		 if (strcmp(emp.city, "Tokyo") == 0)
		{
			office_code = 5;
		}
		 if (strcmp(emp.city, "Sydney") == 0)
		{
			office_code = 6;
		}
		 if (strcmp(emp.city, "London") == 0)
		{
			office_code = 7;
		}
		

		

		// i could not make it work with string so ihad to do some research on how to make it work
	ostringstream insert;
	insert << "insert into employees values(" << emp.employeeNumber << ", \"" << emp.lastName << "\", \"" << emp.firstName << "\", \"" << emp.extension << "\", \"" << emp.email << "\", \"" << office_code << "\"," << reportsTo << ", \"" << emp.jobTitle << "\");";
	
	int exequery;
	const char* q = insert.str().c_str();
	exequery = mysql_query(conn, q);

	if (!exequery) {
		//query execution is successful
		cout << endl;
		cout << "The new employee is added successfully." << endl;
		cout << endl;
	}
	else
	{
		//query execution is not successful
		cout << endl;
		cout << "Error message: " << mysql_error(conn) << mysql_errno(conn) << endl;
		cout << endl;
	}
	}


}

void updateEmployee(MYSQL* conn, int employeeNumber) {
	struct Employee emp = { 0 };

	if (findEmployee(conn, employeeNumber, &emp) == 1) {
		string ext;

		cout << "New Extension: ";
		cin >> ext;
		string query = "update employees set extension = ";
		query += ext;
		query += " where employeeNumber = ";
		string empnum;
		empnum = to_string(employeeNumber);
		query += empnum;
		query += ";";
		const char* q = query.c_str();
		int exequery;
		exequery = mysql_query(conn, q);
		
		if (!exequery) {
			//query execution is successful
			cout << endl;
			cout << "Extension for employee " << employeeNumber << " is now updated." << endl;
			cout << endl;
		}
		else
		{
			//query execution is not successful
			cout << endl;
			cout << "Error message: " << mysql_error(conn) << mysql_errno(conn) << endl;
			cout << endl;
		}

	}
	else {
	
		cout << endl;
		cout << "An employee with the same employee number does not exists." << endl << endl;
	}
}


void deleteEmployee(MYSQL* conn, int employeeNumber) {
	struct Employee emp = { 0 };

	if (findEmployee(conn, employeeNumber, &emp) == 1) {

		string query = "delete from employees where employeeNumber = ";
		string empnum;
		empnum = to_string(employeeNumber);
		query += empnum;
		query += ";";
		const char* q = query.c_str();
		int exequery;
		exequery = mysql_query(conn, q);

		if (!exequery) {
			//query execution is successful
			cout << endl;
			cout << "Employee " << employeeNumber << " is now deleted." << endl;
			cout << endl;
		}
		else
		{
			//query execution is not successful
			cout << endl;
			cout << "Error message: " << mysql_error(conn) << mysql_errno(conn) << endl;
			cout << endl;
		}

	}
	else {

		cout << endl;
		cout << "An employee with the same employee number does not exists." << endl << endl;
	}

}


int menu(void) {

	int option;
	cout << "1) Find Employee" << endl;
	cout << "2) Employees Report" << endl;
	cout << "3) Add Employee" << endl;
	cout << "4) Update Employee" << endl;
	cout << "5) Remove Employee" << endl;
	cout << "0) Exit" << endl;
	cout << "\nEnter an option: ";
	cin >> option;
	cout << endl;
	while (option > 5 || option < 0) {

		cout << "Please try again (0 - 5): ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> option;
		cout << endl;

	}
	return option;
}
int main(void)
{
	//initializing
	Employee emp{ 0 };
	int employeeNumber;
	MYSQL* conn;
	conn = mysql_init(0);
	int choice = 1;
	conn = mysql_real_connect(conn, "mymysql.senecacollege.ca", "db_mfrolov", "hLkG+e#3z8", "db_mfrolov", 3306, nullptr, 0);
	while (choice == 1) {
		cout << "*********************HR Menu*********************" << endl;
		int option = menu();
		switch (option)
		{
		case 0:
			cout << "Program Terminated" << endl;
			choice = 0;
			break;
		case 1:
			displayEmployee(conn, emp);
			break;

		case 2:
			displayAllEmployees(conn);
			break;
		case 3:
			insertEmployee(conn, emp);
			break;
		case 4:
			cout << "Employee Number to Update: ";
			cin >> employeeNumber;
			updateEmployee(conn, employeeNumber);
			break;
		case 5:
			cout << "Employee Number to Delete: ";
			cin >> employeeNumber;
			deleteEmployee(conn, employeeNumber);
			break;
		default:
			cout << "Not available yet!" << endl << endl;
			break;
		}
	}
	return 0;
}


