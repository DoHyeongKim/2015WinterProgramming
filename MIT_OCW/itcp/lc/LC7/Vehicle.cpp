#include <string>
using namespace std;

class Vehicle {
protected:
    string license;
    int year;

public:
    Vehicle(const string &myLicense, const int myYear) : license(myLicense), year(myYear){};
    const string getDesc() const {
        return license + " from ";
    }
    const string &getLicense() const {
       return license;
   }
    const int getYear() const {
        return year;
    }
};