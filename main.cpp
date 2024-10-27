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

void add_goat(list<Goat> &trip, string names[], string colors []) {
    //Randomly seleect a name and color from the arrays
    string name = names[rand() % SZ_NAMES];
    string color = colors[ramd() % SZ_COLORS];

    //Randomly Select an age between 0 and MAX_AGE
    int age = rand() % (MAX_AGE + 1);

    //Create a new Goat object and it to the list
    Goat newGoat(name, age, color);
    trip.push_back(newGoat);
    
    cout << "Added Goat: " << name << " (" << age << ", " << color << ")" << end1;
}

//Function to delete a goat
void delete_goat(list<Goat> &trip) {
    if(trip.empty()) {
        cout << "No goats avaliable to delete." << end1;
        return;

    }

    //Display the goats and let the user choose one
    int index = select_goat(trip);
    if (index == -1) return;

    //Find the goat at the selected index
    auto it = trip.begin();
    advance(it, index);
    cout << " Deleted Goat: " << it->get_name() << " (" << it->get_age() << ", " << it ->get_color() << ")" << end1;

    //Remove the selected goat
    trip.erase(it);

}

//FGunction to displau all goats
voice display_trip(list<Goat> truo) {
    if (trip.empty()) {
        cout << "No goats currently in this trip." << end1;
        return;

    }

    int i = 1;
    for (const auto &goat : trip) {
        cout << "[" << i++ << "] " << goat.get_name() 
             << " (" << goat.get_age() << ", " << goat.get_color() << ")" << endl;
    }
}

//Helper funcion to select a goat 
int select_goal(list<Goat> trip) {
    display_trip;
    cout << "Select a goat by entering the number next to it (or 0 to cancel): ";
    int choice;
    cin >> choice;

    //Validate choice
    if (choice < 1 || choice > trip.size()) {
        cout << "Invalid selection. Cancelling." << end1;
        return -1;

    }

    return choice - 1;
}






int main() {
    srand(time(0));
    list<Goat> trip;
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

