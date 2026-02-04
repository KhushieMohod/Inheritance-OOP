/*Rename the showCESA and ShowIndia codes as show() in common and address the ambiguity.
For that you can either change the main() function into acm.CESA::show() or acm.ACMIndia::show() which now is acm.show()
or you can define a seperate show function in PCCoEACM such that
void show()
{
    CESA::show();
    ACMIndia::show();
}
*/

#include <iostream>
using namespace std;

// Base Class 1
class CESA {
protected:
    int cesaMembers;

public:
    CESA(int members) {
        cesaMembers = members;
    }

    void showCESA() {
        cout << "CESA Total Members: " << cesaMembers << endl;
    }
};

// Base Class 2
class ACMIndia {
protected:
    int indiaMembers;

public:
    ACMIndia(int members) {
        indiaMembers = members;
    }

    void showIndia() {
        cout << "ACM India Members: " << indiaMembers << endl;
    }
};

// Derived Class (Multiple Inheritance)
class PCCoEACM : public CESA, public ACMIndia {
private:
    int acmMembers;
    int events;

public:
    PCCoEACM(int cesaMem, int indiaMem, int acmMem, int ev)
        : CESA(cesaMem), ACMIndia(indiaMem) {
        acmMembers = acmMem;
        events = ev;
    }

    void showACM() {
        cout << "ACM Members: " << acmMembers << endl;
        cout << "Events Conducted: " << events << endl;
    }

    void contributionToCESA() {
        double percent = (double)(acmMembers) / cesaMembers * 100;

        cout << "ACM contributes "
             << percent
             << "% to CESA." << endl;
    }
};

// Main Function
int main() {
    PCCoEACM acm(
        500,   // CESA members
        8000,  // ACM India members
        120,   // ACM members
        15     // Events
    );

    acm.showCESA();   // from CESA
    acm.showIndia();  // from ACMIndia
    acm.showACM();    // from ACM
    acm.contributionToCESA();

    return 0;
}
