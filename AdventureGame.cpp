#include <iostream>
using namespace std;

int menu()
{
    int direction = -1;
    while (direction < 1 || direction > 4)
    {
        cout << "\nPlease choose a direction by the number:" << endl;
        cout << "   1 EAST" << endl;
        cout << "   2 WEST" << endl;
        cout << "   3 NORTH" << endl;
        cout << "   4 SOUTH" << endl;
        cout << "Choose a direction: ";
        cin >> direction;
    }
    return direction;
}

string place(string location, int direction, bool& hasSword)
{
    bool success = false;
    bool inDragonsDen = false;
    string tempLocation;

    if (location == "Cave of Cacophony") {
        tempLocation = location;
        if (direction == 1) {
            location = "Twisty Tunnel";
            success = true;
        }
    }
    else if (location == "Twisty Tunnel") {
        tempLocation = location;
        if (direction == 2) {
            location = "Cave of Cacophony";
            success = true;
        }
        else if (direction == 4) {
            location = "Rapid River";
            success = true;
        }
    }
    else if (location == "Rapid River") {
        tempLocation = location;
        if (direction == 3) {
            location = "Twisty Tunnel";
            success = true;
        }
        else if (direction == 2) {
            location = "Secret Sword Stash";
            cout << "\nOh look! A hidden sword... I wonder what this is for?" << endl;
            hasSword = true;
            success = true;
        }
        else if (direction == 1){
            location = "Dragons Den";
            success = true;
        }
    }
    else if (location == "Secret Sword Stash") {
        tempLocation = location;
        if (direction == 1) {
            location = "Rapid River";
            success = true;
        }
    }
    else if (location == "Dragons Den") {
        tempLocation = location;
        inDragonsDen = true;
    }

    if (inDragonsDen){
        if (hasSword) {
            cout << "\nThank the lord you found the sword!... you defeated the dragon!" << endl;
            location = "Victory Vault";
            success = true;
        }
        else if (!hasSword){
            cout << "\nYou came to fight a dragon and had no sword!?... enjoy your trip to an early grave." << endl;
            location = "Grievous Graveyard"; 
            success = true;
        }
    }

    if (success) {
        cout << "\nYou are leaving " << tempLocation << " and entering " << location << endl;
    }
    else {
        cout << "\nYou cannot go that direction!" << endl;
    }

    return location;
}

int main()
{
    string location = "Cave of Cacophony"; // starting location
    bool hasSword = false;
    while (true)
    {
        if (location == "Dragons Den"){
            int direction = 1;
            location = place(location, direction, hasSword); // update location based on selected direction
            break;
        } else {
            int direction = menu();
            location = place(location, direction, hasSword); // update location based on selected direction
        }
    }
    if (location == "Victory Vault") {
        cout << "\nYOU WIN\n" << endl;
    }
    else if (location == "Grievous Graveyard") {
        cout << "\nYOU'RE DEAD\n" << endl;
    }
    return 0;
}
