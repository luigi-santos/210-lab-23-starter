#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    bool again = true;
    while (again) {
        int choice = main_menu();

        switch (choice) {
            case 1:
                add_goat(trip, names, colors, names_count, colors_count);
                break;
            case 2:
                delete_goat(trip);
                break;
            case 3:
                dispay_trip(trip);
                break;
            case 4:
                cout << "Quitting Goat Manager 3001" << endl;
                again = false;
                break;
            default:
                cout << "INVALID CHOICE" << endl;
        }
    }
                


    return 0;
}

int main_menu() {
    int choice;

    while (true) {
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] QUIT" << endl
        cout << "Choice --> ";

        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n';
            cout << "ERROR. Please pick a number between 1-4" << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}
