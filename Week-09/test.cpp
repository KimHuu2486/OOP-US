#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() = 0;
};
class Dog : public Animal {
public:
    void speak() {
        cout << "Dog barks" << endl;
    }
};
class Cat : public Animal {
public:
    void speak() {
        cout << "Cat meows" << endl;
    }
};
void giveVoice(Animal* p) {
    p->speak();
}

int main () {
    //Animal a;
    Cat c;
    Dog d;
    //giveVoice(a); // Animal speaks
    giveVoice(&c); // Animal speaks  
    giveVoice(&d); // Animal speaks
    Animal *p;
    // p = &a;
    // p->speak(); // Animal speaks
    p = &c;
    p->speak(); // Animal speaks
    p = &d;
    p->speak(); // Animal speaks
}