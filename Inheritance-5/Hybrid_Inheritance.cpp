/*Diamond Problem - Because inheritance forms a diamond shape, and the top base class (CESA) gets duplicated.
Now, showCESA to be inherited from which path? 
Student → ACM → CESA
Student → LFDT → CESA

Either you do - s.ACM::showCESA();
                s.LFDT::showCESA();
This proves:
Two copies of CESA exist
Hence ambiguity is real   
You are not fixing the problem
You are bypassing it using scope resolution

ACM::CESA::totalMembers ≠ LFDT::CESA::totalMembers
Any change in one does not reflect in the other
Student
 ├── ACM
 │    └── CESA   (copy #1)
 └── LFDT
      └── CESA   (copy #2)

Correct way:
Use virtual inheritance:
class ACM : virtual public CESA {};
class LFDT : virtual public CESA {};
Virtual Inheritance: No matter how many times you inherit from CESA, keep only one shared copy

Object layout with virtual inheritance
Student
 ├── ACM
 ├── LFDT
 └── CESA   (ONE shared instance)

This ensures:
Only ONE shared CESA
No ambiguity

When a base class is virtual, it is constructed ONLY by the most-derived class.
That means:
ACM ❌ does NOT construct CESA
LFDT ❌ does NOT construct CESA
Student ✅ MUST construct CESA

Without virtual inheritance:
ACM constructs its own CESA
LFDT constructs its own CESA
Student gets TWO CESAs

With Virtual Inheritance:
There must be ONLY ONE CESA
That one CESA must be built ONCE
Who builds it? → the most-derived class
*/

#include <iostream>
using namespace std;

// Base Class
class CESA {
protected:
    int totalMembers;

public:
    CESA(int members) {
        totalMembers = members;
    }

    void showCESA() {
        cout << "CESA Total Members: " << totalMembers << endl;
    }
};

// Derived Class 1
class ACM : virtual public CESA {
public:
    ACM(int members) : CESA(members) {}

    void showClub() {
        cout << "ACM Club\n";
    }
};

// Derived Class 2
class LFDT : virtual public CESA {
public:
    LFDT(int members) : CESA(members) {}

    void showClub() {
        cout << "LFDT Club\n";
    }
};

// Derived Class (Diamond)
class Student : public ACM, public LFDT {
public:
    Student(int members) : CESA(members), ACM(members), LFDT(members) {}

    void showStudent() {
        cout << "Student is in ACM and LFDT\n";
    }
};

int main() {
    Student s(500);

    s.showCESA(); 
    return 0;
}
