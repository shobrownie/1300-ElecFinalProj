//Shoshana Brown, CSCI1300 - Sect. 310, Final Project
//Main function
#include <fstream>
#include "ElecUser.h"
#include "User2.h"
#include <iostream>
#include <sstream>
using namespace std;
 
int main(){
 
string userChoice = "";
 
string tempID;  //temporary ID to use in getline(cin, tempID) to obtain user input for userID
int uID; 
 
ElecUser person(32);        //ElecUser is first class, person is instance (object)
    //(32) is hardcoded as a default userID - calls the constructor 
    // it will be replaced by a user's input via setUserID function in ElecUser class
                    //will only be using this class for options 1-4 in menu
 
User2 user2;    //   User2 is the second class, choice is instance (object)
                //calls the default constructor
 
cout << "______________________________________________________________________________________________" << endl;
cout << "WELCOME USER!" << endl;
cout << "This program will allow you to find out demographic details about a certain population" << endl;
cout << "as well as perform calculations of electricity consumption based on the demographic and" << endl;
cout << "electricity data collected from that population for 31 days." << endl;
while (userChoice != "7") {
    cout << "----------------------------------------------------------------------------------------------\n" << endl;   //skip line to make formatting pretty
    cout << "Please select the calculation you'd like the program to run" << endl;
    cout << "     1) Calculate a report type (average, max or total) for user with specific userID" << endl;
    cout << "     2) Check user's STEM status (0 is non-STEM, 1 is STEM)" << endl;
    cout << "     3) Check if user works from home" << endl;
    cout << "     4) Check a user's home type (apartment, home or townhome)" << endl;
    cout << "     5) Calculate total electricity consumption for all users w/ even or odd # userID's" << endl;
    cout << "     6) Calculate average electricity usage for male or female users" << endl;
    cout << "     7) Quit" << endl;  //7 exits the loop - program won't run again 
    getline(cin, userChoice);  
        //getline removes the new line character (cin will sometimes add the endline character onto the next input
        //will use this for all my user inputs
 
 
    //object: method name called from ElecUser.cpp
    person.processDemographicData("Demographics-FinalProject.csv");
                            //input file from same directory FinalProject to test
    person.processElecData("ElectricityData-FinalProject-Updated.csv");
                            //input file from same directory FinalProjectto test
    user2.processElecData("ElectricityData-FinalProject-Updated.csv");
                            //input file from same directory FinalProjectto test
    user2.processDemographicData("Demographics-FinalProject.csv");
 
    if (userChoice == "1") {  //Calculate a report type (average, max or total) for user with specific userID"
        cout << "Enter userID" << endl;
        getline(cin, tempID); 
        uID = stoi(tempID);
        person.setUserID(uID);
        string reportType;
        cout << "enter report type (average, max or total)" << endl;
        getline(cin, reportType);       
        cout << person.calculateConsumption(reportType) << endl;
                                //prints out to terminal calculateConsumption function
    }
 
    else if (userChoice == "2") {  // Check user's STEM status (0 is non-STEM, 1 is STEM)"
        cout << "Enter userID" << endl;
        getline(cin, tempID); 
        uID = stoi(tempID);
        person.setUserID(uID); 
        cout << "User's STEM status (0 is non-STEM, 1 is STEM): "  << person.getSTEMJobStatus() << endl;
                    //checks if user's job is a STEM or Non-STEM job - calls getSTEMJobStatus
    }
 
    else if (userChoice == "3") {  //Check if user works from home
        cout << "Enter userID" << endl;
        getline(cin, tempID);
        uID = stoi(tempID);
        person.setUserID(uID);   
        cout << "User works from home? (0 is no, 1 is yes): " << person.getWorksAtHomeStatus() << endl;
                    //checks if user works from home - calls getsWorksAtHomeStatus function
    }
 
    else if (userChoice == "4") {  //Check a user's home type (apartment, home or townhome
        cout << "Enter userID" << endl;
        getline(cin, tempID);
        uID = stoi(tempID);
        person.setUserID(uID);   
        cout << "User's home type is " << person.getHomeType() << endl; 
                     //check what user's homeType is (apartment, home, townhome)
    }
 
    else if (userChoice == "5") {  //Calculate total electricity consumption for all users w/ even or odd # userID's
 
        bool isOdd = false;
        string evenOdd;
        cout << "Find electricity consumption total for even or odd UserID's: enter (0) even or (1) odd" << endl;
        getline(cin, evenOdd);
        if (evenOdd == "1"){
            isOdd = true;
        }
        user2.calculateConsumption2(isOdd);
    }
 
    else if (userChoice == "6") {  //Calculate average electricity usage for male or female users
 
        bool isFemale = false;
        string maleFemale;
        cout << "Find average male or female electricity consumption: enter (0) male or (1) female" << endl;
        getline(cin, maleFemale);
        if (maleFemale == "1"){
            isFemale = true;
        }   
        user2.calculateMaleFem(isFemale);       
    }
 
} //end of while loop - user did not quit ("7")
 
cout << "Goodbye." << endl;  //exits loop if user enters 7
return 0;
}
