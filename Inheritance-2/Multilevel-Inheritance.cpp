#include <iostream>
using namespace std;

// Base Class
class ACM
{
protected:
    int globalMembers;

public:
    ACM(int gm) : globalMembers(gm) {}

    void showGlobalMembers()
    {
        cout << "Total ACM Global Members: " << globalMembers << endl;
    }
};

// Derived Class (Level 2)
class ACMIndia : public ACM
{
protected:
    int indiaMembers;

public:
    ACMIndia(int gm, int im) : ACM(gm)
    {
        indiaMembers = im;
    }

    void showIndiaMembers()
    {
        cout << "Total ACM India Members: " << indiaMembers << endl;
    }

    void indiaContribution()
    {

        // indiaMembers / globalMembers  →  8000 / 100000  →  0  (integer division) -> 0 * 100 → 0
        // This type-casts (Converting a value from one data type to another data type) indiaMembers from int to double.
        double percentage = (double)indiaMembers / globalMembers * 100;
        cout << "India contributes " << percentage << "% of global ACM members." << endl;
    }
};

// Derived Class (Level 3)
class PCCoEACM : public ACMIndia
{
private:
    int collegeMembers;
    int eventsConducted;

public:
    PCCoEACM(int gm, int im, int cm, int ev) : ACMIndia(gm, im)
    {
        collegeMembers = cm;
        eventsConducted = ev;
    }

    void showCollegeDetails()
    {
        cout << "PCCoE ACM Members: " << collegeMembers << endl;
        cout << "Events Conducted This Year: " << eventsConducted << endl;
    }

    void eventMemberRatio()
    {
        double ratio = (double)eventsConducted / collegeMembers;
        cout << "Events-to-Member Ratio: " << ratio << endl;
    }
};

// Main Function
int main()
{
    PCCoEACM chapter(
        100000, // Global ACM members
        8000,   // ACM India members
        120,    // PCCoE ACM members
        15      // Events conducted
    );

    chapter.showGlobalMembers();
    chapter.showIndiaMembers();
    chapter.indiaContribution();
    chapter.showCollegeDetails();
    chapter.eventMemberRatio();

    return 0;
}
