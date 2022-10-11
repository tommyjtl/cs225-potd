#pragma once

#include <string>

using namespace std;

class Pet
{
public:
    // Declare your constructors here!
    Pet()
    {
        // name: Rover
        // birth_year: 2018
        // type: dog
        // owner_name: Wade
        name = "Rover";
        birth_year = 2018;
        type = "dog";
        owner_name = "Wade";
    };

    Pet(string name_, int birth_year_, string type_, string owner_name_)
    {
        name = name_;
        birth_year = birth_year_;
        type = type_;
        owner_name = owner_name_;
    }

    // Other member functions
    void setName(string newName);
    void setBY(int newBY);
    void setType(string newType);
    void setOwnerName(string newName);
    string getName();
    int getBY();
    string getType();
    string getOwnerName();

private:
    string name;
    int birth_year;
    string type;
    string owner_name;
};
