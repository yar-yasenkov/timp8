// tmp8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <string>

using namespace std;
class Base {
public:
	Base() : value(0) {};
	Base(int val) : value(val) {};
	virtual void show() = 0;
protected:
	int value;
};


class BaseA : public Base{
public:
	BaseA() : Base(){};
	BaseA(int x) : Base(x){};
	void show(){ cout << "class A: " << value << endl; }
};
class BaseB : public Base{
public:
	BaseB() : Base(){};
	BaseB(int x) : Base(x){};
	void show(){ cout << "class B: " << value << endl; }
};
class BaseC : public Base{
public:
	BaseC() : Base(){};
	BaseC(int x) : Base(x){};
	void show(){ cout << "class C: " << value << endl; }
};

class Creator{
public:
	//Creator() : 
	virtual Base* factoryMethod(int v)=0;
};

class ConcreteCreatorA : public Creator{
public:
	Base* factoryMethod(int v) { return new BaseA(v); }
};

class ConcreteCreatorB : public Creator{
public:
	Base* factoryMethod(int v) { return new BaseB(v); }
};


class ConcreteCreatorC : public Creator{
public:
	Base* factoryMethod(int v) { return new BaseC(v); }
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n; string s;
	//Base BASE;
	cin >> n;
	Base* arrA = new BaseA[n]; int kA = 0;
	Base* arrB = new BaseB[n]; int kB = 0;
	Base* arrC = new BaseC[n]; int kC = 0;
	//ConcreteCreatorA CreatorA;
	//ConcreteCreatorB CreatorB;
	// An array of creators
	//Creator*creators[] = { &CreatorA, &CreatorB };
	while (n){
		getline(cin, s);
		if (!s.find("create")){
			n--;
			s.erase(0, 7);
			if (s.substr(0, 1) == "A"){
				s.erase(0, 2);
				int y = atoi(s.c_str());
				ConcreteCreatorA CrA;
				Creator*c = &CrA;
				arrA[kA] = *c->factoryMethod(y);
				kA++;
			}
			if (s.substr(0, 1) == "B"){
				s.erase(0, 2);
				int y = atoi(s.c_str());
				ConcreteCreatorB CrB;
				Creator*c = &CrB;
				arrB[kB] = *c->factoryMethod(y);
				kB++;
			}
			if (s.substr(0, 1) == "C"){
				s.erase(0, 2);
				int y = atoi(s.c_str());
				ConcreteCreatorC CrC;
				Creator*c = &CrC;
				arrC[kC] = *c->factoryMethod(y);
				kC++;
			}
		}
			if (s == "showall"){
				n--;
				for (int i = 0; i < kA; i++)  arrA[i].show();
				for (int i = 0; i < kB; i++)  arrB[i].show();
				for (int i = 0; i < kC; i++)  arrC[i].show();
			}
		}
		system("pause");
	
	return 0;
}

