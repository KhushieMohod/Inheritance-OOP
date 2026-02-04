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
class ACM : public CESA {
public:
    ACM(int members) : CESA(members) {}

    void showClub() {
        cout << "Club: ACM" << endl;
    }
};

// Derived Class 2
class ACMW : public CESA {
public:
    ACMW(int members) : CESA(members) {}

    void showClub() {
        cout << "Club: ACM-W" << endl;
    }
};

// Derived Class 3
class OWASP : public CESA {
public:
    OWASP(int members) : CESA(members) {}

    void showClub() {
        cout << "Club: OWASP" << endl;
    }
};

// Derived Class 4
class GDGC : public CESA {
public:
    GDGC(int members) : CESA(members) {}

    void showClub() {
        cout << "Club: GDGC" << endl;
    }
};

// Derived Class 5
class LFDT : public CESA {
public:
    LFDT(int members) : CESA(members) {}

    void showClub() {
        cout << "Club: LFDT" << endl;
    }
};

// Main Function
int main() {
    ACM acm(500);
    ACMW acmw(500);
    OWASP owasp(500);
    GDGC gdgc(500);
    LFDT lfdt(500);

    acm.showCESA();
    acm.showClub();

    acmw.showClub();
    owasp.showClub();
    gdgc.showClub();
    lfdt.showClub();

    return 0;
}
