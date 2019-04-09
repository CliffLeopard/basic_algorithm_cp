
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main() {

    double i, j;
    j = 10.0;
    if (j == 10)
        cout << "Sounds Good" << endl;
    else
        cout << "Sounds Bad" << endl;
    for (i = 9; i != j && i < 12; i += 0.1) {
        if (i != j)
            cout << fixed << setprecision(3) << i;
        if (i < j)
            cout << "   smaller than " << j << endl;
        else if (i > 10)
            cout << "   bigger than " << j << endl;
        else
            cout << "   equal " << j << endl;
    }
}