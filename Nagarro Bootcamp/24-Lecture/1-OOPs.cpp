// 1-OOPs.cpp
#include <iostream>
#include <string.h>
using namespace std;

//template - user defined datatype
class Car {
	//access -modifier
public:
	//datatypes
	char *name;
	int price,avg,model;


	//default constructor
	Car() {
		// cout<<"***default const is invoked*** \n";
		this->name = new char[50];
		// name = NULL;
	}

	//parametrized construtor
	Car(char *name, int price, int avg, int model) {
		// cout<<"***parametrized const is invoked*** \n";
		int len = strlen(name);
		this->name = new char[len+1];
		strcpy(this->name,name);
		this->price = price;
		this->avg = avg;
		this->model = model;
	}

	// copy constructor - deep copy
	Car(Car &X) {
		// cout<<"***copy const is invoked*** \n";
		int len = strlen(X.name);
		this->name = new char[len+1];
		strcpy(this->name,X.name);
		this->price = X.price;
		this->avg = X.avg;
		this->model = X.model;
	}

	//functions ------------------------------------
	void displayDataOfCar(int carNo) {
		cout<<"Car "<<carNo<<" -> "<<endl;
		cout<<"Name      :"<<name<<endl;
		cout<<"Price     :"<<price<<endl;
		cout<<"Average   :"<<avg<<"km/L"<<endl;
		cout<<"model     :"<<model<<endl<<endl;
		return;
	}

	void setName(char *name) {
		strcpy(this->name,name);
		return;
	}
};

int main() {
	//object/instance
	Car C1("nano",24000,23,12);
	Car C2("maruti",15000,15,10); 

	// cout<<sizeof(Car)<<endl; ---112 bytes -memory used when object is created
	// cout<<sizeof(C1)<<endl;  ---112 bytes

	//car1
	// strcpy(C1.name,"nano");
	// C1.price = 24000;
	// C1.avg = 23;
	// C1.model = 12;

	//car2
	// strcpy(C2.name,"maruti");
	// C2.price = 15000;
	// C2.avg = 15;
	// C2.model = 10;

	// C1.displayDataOfCar(1);
	// C2.displayDataOfCar(2); 

	// cout<<"car name is "<<C1.name<<" price "<<C1.price;
	// cout<<" with avg of "<<C1.avg<<"km/L and model number "<<C1.model;

	//Create Car3, C4
	//using C1
	Car C3 = C1;
	Car C4(C1);

	// C3.displayDataOfCar(3);
	// C4.displayDataOfCar(4);

	cout<<"***change name of car1 from nano to audi***\n";
	C1.setName("audi");

	C1.displayDataOfCar(1);
	C3.displayDataOfCar(3);
	C4.displayDataOfCar(4);

	return 0;
}