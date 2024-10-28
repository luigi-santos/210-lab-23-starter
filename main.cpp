#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;


void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string names[], string colors[], int names_size, int colors_size);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(static_cast<unsigned int>(time(0)));
    list <Goat> trip;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int names_count = 0;
    while (fin >> names[names_count] && names_cout < SZ_NAMES) {
        names_count++;
    }
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    while (fin1 >> colors[colors_count] && colors_count < SZ_COLORS) {
        colors_count++;
    }
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
        cout << "[4] QUIT" << endl;
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

void add_goat(list<Goat> &trip, string names[], string colors[], int names_size, int colors_size) {
    string name = names[rand() % names_size];
    int age = rand() % (MAX_AGE + 1);
    string color = colors[rand() % colors_size];
    trip.emplace_back(name, age, color);
    cout << name << " (" << age << ", " << color << ")" << endl;
}

void delete_goat(list<Goat> &trip {
    if (trip.empty()) {
        cout << "No goats" << endl;
        return;
    }

    display_trip(trip);

    int index;
    cout << "Enter the number of goats to delete: ";
    cin >> index;

    if (cin.fail() || index < 1 || index > trip.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ERROR" << endl;
        return;
    }

    auto it = trip.begin();
    advance(it, index - 1);
    trip.erase(it);
    cout << "Goat deleted" << endl;
}

void display_trip(comst list<Goat> &trip) {
    if (trip.empty()) {
        cout << "ERROR" << endl;
        return;
    }
    cout << "List of Goats:" << endl;
    int count = 1;
    for (const auto& goat : trip) {
        cout << count << " " << goat.get_name() << " ("
             << goat.get_age() << ", " << got.get_color()
             << ")" << endl;
        count++;
    }
}
