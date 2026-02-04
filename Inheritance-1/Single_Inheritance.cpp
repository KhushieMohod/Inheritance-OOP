#include <iostream>
using namespace std;

// Base Class
class CESA
{
protected:
    int totalMembers;

public:
    CESA(int members)
    {
        totalMembers = members;
    }

    void showCESAMembers()
    {
        cout << "Total CESA Members: " << totalMembers << endl;
    }
};

// Derived Class
class ACM : public CESA
{
private:
    int acmMembers;
    int eventsConducted;

public:
    ACM(int cesaMem, int acmMem, int events) : CESA(cesaMem)
    {
        acmMembers = acmMem;
        eventsConducted = events;
    }

    void showACMDetails()
    {
        cout << "ACM Members: " << acmMembers << endl;
        cout << "Events Conducted: " << eventsConducted << endl;
    }

    void contributionToCESA()
    {
        double percentage = (double)(acmMembers) / totalMembers * 100;

        cout << "ACM contributes " << percentage << "% to total CESA members." << endl;
    }
};

// Main Function
int main()
{
    ACM acm(
        500, // Total CESA members
        120, // ACM members
        15   // Events conducted
    );

    acm.showCESAMembers(); // from CESA
    acm.showACMDetails();  // from ACM
    acm.contributionToCESA();

    return 0;
}
