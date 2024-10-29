/*
Write a C++ program to store the name of the state and its population in the map associative container. When the user inputs the name of the state, the program should display its population
*/

#include<iostream>
#include<map>
#include <algorithm> // for transform
#include <cctype>    // for tolower
#include<string>
using namespace std;

int main(){
    map<string, int> statePopulation;

    // Sample data
    statePopulation["maharashtra"] = 120000000;
    statePopulation["punjab"] = 50000000;
    statePopulation["gujarat"] = 21538187;
    statePopulation["goa"] = 300000;
    statePopulation["kerala"] = 30000000;

    string srch;
    cout << "Enter state name: ";
    getline(cin, srch); 

    // Convert the entire string to lowercase to avoid naming confusion
    transform(srch.begin(), srch.end(), srch.begin(), ::tolower);

    //create a iterator and find the state name in the map
    auto it = statePopulation.find(srch);
    if(it!=statePopulation.end()){
        cout << "Population of " << srch << ": " << it->second << endl;
    }
    else{
        cout << "State not found in the database! " << endl;
    }

    return 0;
}
