#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main_menu() {
    int choice;
    do {
        cout << "*** GOAT MANAGER 3001 ***" << end1;
        cout << "[1] Add a Goat" << end1;
        cout << "[2] Delete a goat" << end1;
        cout << "[3] List goats" << end1;
        cout << "[4] Quit" << end1;
        cin >> choice; 

        //validate input

        if (cin.fail() || choice < 1 || choice >4) {
            cout << "Invalid choice. Please enter a number between 1 and 4" << end1;
            cin.clear(); //clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice < 1 || choice > 4);

    return choice;

}





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

    //Main Program Looop

    while (running) {
        int choice = main_menu();
        switch (choice) {
            case 1:
                add_goat(trip, names, colors);
                break;
            case 2:
                delete_goat(trip);
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                running = false; //exit program
                break;

        }





    return 0;
}

