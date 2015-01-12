#include <iostream>
#include <string.h>
using namespace std;

/*
////////////////////////////////////////////////////////////////
class PermanentWorker {
	char _name[20];
	int _salary;
public:
	PermanentWorker(char* name, int money) : _salary(money)
	{ 
		strcpy(_name, name); 
	}
	int getPay() const	{ return _salary; }
	void showSalaryInfo() const 
	{
		cout<<"name: "<<_name<<endl;
		cout<<"salary: "<<getPay()<<endl<<endl;
	}
};

class EmployeeHandler {
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)	{}
	void addEmployee(PermanentWorker* emp) { empList[empNum++] = emp; }
	void showAllSalaryInfo() const 
	{
	 for(int i=0; i<empNum; i++)
		empList[i]->showSalaryInfo();
	}
	void showTotalSalary() const
	{
		int sum = 0;
		for(int i=0; i<empNum; i++)
			sum += empList[i]->getPay();
		cout<<"salary sum: "<<sum<<endl;
	}
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
			delete empList[i];
	}
};
void main()
{
	EmployeeHandler handler;
	handler.addEmployee( new PermanentWorker("Park",1000) );
	handler.addEmployee( new PermanentWorker("Kim",2000) );
	
	handler.showAllSalaryInfo();
	handler.showTotalSalary();
	
}
////////////////////////////////////////////////////////////////
*/

/*
////////////////////////////////////////////////////////////////
class Employee {
	char _name[20];
public:
	Employee(char* name)	{ strcpy(_name, name); }
	void showname() const	{ cout<<"name: "<<_name<<endl; }
};

class PermanentWorker : public Employee {
	int _salary;
public:
	PermanentWorker(char* name, int money)
		: Employee(name), _salary(money) {}
	int getPay() const	{ return _salary; }
	void showSalaryInfo() const 
	{
		showname();
		cout<<"salary: "<<getPay()<<endl<<endl;
	}
};

class EmployeeHandler {
	Employee* empList[50];     // PermanentWorker* -> Employee* 
	int empNum;
public:
	EmployeeHandler() : empNum(0)	{}
	void addEmployee(Employee* emp) // PermanentWorker* -> Employee*
	{ 
		empList[empNum++] = emp; 
	}
	void showAllSalaryInfo() const 
	{
//	 for(int i=0; i<empNum; i++)
//		empList[i]->showSalaryInfo();
	 }
	void showTotalSalary() const
	{
		int sum = 0;
//		for(int i=0; i<empNum; i++)
//			sum += empList[i]->getPay();
		cout<<"salary sum: "<<sum<<endl;
	}
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
			delete empList[i];
	}
};

void main()     //이전과 동일
{
	EmployeeHandler handler;
	handler.addEmployee( new PermanentWorker("Park",1000) );
	handler.addEmployee( new PermanentWorker("Kim",2000) );

	handler.showAllSalaryInfo();
	handler.showTotalSalary();
}
////////////////////////////////////////////////////////////////
*/


///*
////////////////////////////////////////////////////////////////
class Employee {
	char _name[20];
public:
	Employee(char* name)	{ strcpy(_name, name); }
	void showname() const	{ cout<<"name: "<<_name<<endl; }
	virtual int getPay() const { return 0; }
	virtual void showSalaryInfo() const {}
};

class PermanentWorker : public Employee {
	int _salary;
public:
	PermanentWorker(char* name, int money)
		: Employee(name), _salary(money) {}
	int getPay() const	{ return _salary; }
	void showSalaryInfo() const 
	{
		showname();
		cout<<"salary: "<<getPay()<<endl<<endl;
	}
};

class TemporaryWorker : public Employee {
	int _workTime;
	int _payPerHour;
public:
	TemporaryWorker(char* name, int pay) 
		: Employee(name), _workTime(0), _payPerHour(pay) {}
	void addWorkTime(int time) { _workTime += time; }
	int getPay() const { return _workTime*_payPerHour; }
	void showSalaryInfo() const 
	{
		showname();
		cout<<"salary: "<<getPay()<<endl<<endl;
	}
};

class SalesWorker : public PermanentWorker {
	int _salesResult;
	double _bonusRatio;
public:
	SalesWorker(char* name, int money, double ratio)
		: PermanentWorker(name,money), _salesResult(0), _bonusRatio(ratio) {}
	void addSalesResult(int value) { _salesResult += value; }
	int getPay() const	
	{ 
		return PermanentWorker::getPay()
			+ (int)(_salesResult*_bonusRatio);
	}
	void showSalaryInfo() const 
	{
		showname();
		cout<<"salary: "<<getPay()<<endl<<endl;
	}
};

class EmployeeHandler {
	Employee* empList[50];      
	int empNum;
public:
	EmployeeHandler() : empNum(0)	{}
	void addEmployee(Employee* emp) 
	{ 
		empList[empNum++] = emp; 
	}
	void showAllSalaryInfo() const 
	{
	 for(int i=0; i<empNum; i++)
		empList[i]->showSalaryInfo();
	 }
	void showTotalSalary() const
	{
		int sum = 0;
		for(int i=0; i<empNum; i++)
			sum += empList[i]->getPay();
		cout<<"salary sum: "<<sum<<endl;
	}
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
			delete empList[i];
	}
};

void main() 
{
	EmployeeHandler handler;
	
	handler.addEmployee( new PermanentWorker("Park",1000) );
	handler.addEmployee( new PermanentWorker("Kim",2000) );

	TemporaryWorker* alba = new TemporaryWorker("Lee", 700);
	alba->addWorkTime(5);
	handler.addEmployee(alba);

	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->addSalesResult(2000);
	handler.addEmployee(seller);

	handler.showAllSalaryInfo();
	handler.showTotalSalary();
}
////////////////////////////////////////////////////////////////
//*/