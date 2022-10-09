//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Person {
//protected :
//	string name;
//	string idNum;
//public:
//	Person();
//	Person(const string&, const string&);
//	Person(const Person& person);
//	~Person();
//	virtual void print();
//	string getName();
//
//
//	
//};
//
//Person::Person() {
//	name = "No name";
//	idNum = "0";
//}
//
//Person::Person(const string& nm, const string& id) : name(nm),idNum(id){}
//
//Person::Person(const Person& person) : name(person.name), idNum(person.idNum) {}
//
//Person::~Person() {
//	
//}
//
//void Person::print() {
//	cout << "Name: " << name << endl;
//	cout << "idNum: " << idNum << endl;
//}
//
//
//class Student : public Person {
//private: 
//	string major;
//	int gradYear;
//public:
//	Student();
//	Student(const string&, const string&, const string&, int);
//	Student(const Student& student);
//	~Student();
//	virtual void print();
//	void changeMajor(const string& newMajor);
//
//};
//
//Student::Student() {
//	major = "No major";
//	gradYear = 0;
//}
//
//Student::Student(const string& nm, const string& id, const string& maj, int year) : Person(nm, id),major(maj),gradYear(year) {}
//Student::Student(const Student& student) : Person(student.name, student.idNum), major(student.major), gradYear(student.gradYear){}
//Student::~Student() {
//
//}
//
//
//void Student::print() {
//	Person::print();
//	cout << "Major: " << major << endl;
//	cout << "Year: " << gradYear << endl;
//}
//
//
//int main() {
//
//	Person person("Mary", "12-345");
//	Student	student("Bob", "98-764", "Math", 2012);
//	Person* pp[100];
//	pp[0] = new Person();
//	pp[1] = new Student();
//
//	cout << pp[1]->getName() << endl;
//	pp[0]->print();
//	pp[1]->print();
//	Student* sp = dynamic_cast<Student*>(pp[1]);
//	sp->changeMajor("Chemistry");
//
//
//	
//
//}