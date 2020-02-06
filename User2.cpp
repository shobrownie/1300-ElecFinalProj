//sbrown sect. 310
//User2 class methods
#include <fstream>
#include "User2.h"
#include <iomanip>
#include <iostream>
using namespace std;
 
//--------------------public methods------------------------------------------------
 
 
User2::User2()  //default constructor
{
}
 
User2::~User2() //default destructor
{
}
         
int arrayTtl = 0;
 
double User2::processDemographicData(string fileNameDem){ 
            //reads demographic data from fileName and stores data using setConsumption
         
     
    string returnDemValue;
    string line;
    string userDem;     //UserID for demographic data
    string gender;      //Male or Female
    string smartMeter;  //Yes or No
    string occupation;      
    string occupationType;  //STEM or Non-STEM
    string workFromHome;    //Yes or No
    string monthsInResidence;
    string ResidenceType;   //Townhouse, House, Apartment
    string occupancyType;   //type of occupancy (Own/Rent)
    string numberOccupants; //number of occupants in residence
    string squareFootage;   //approximate square footage of residence
    string numberBedrooms; //number of bedrooms
    string numberBathrooms; //number of bathrooms
    string centralAir;      //Yes or No
    string windowAC;  //window A/C units? Yes or No
    string swampCooler; //swamp cooler? Yes or No
    string ceilingFans;  //Ceiling fans? Yes or No
    string floorFans;  //Floor fans? Yes or No
    string portableAC; //portable air conditioner? Yes or No
 
     
 
    ifstream infile;        //infile is instream
    infile.open(fileNameDem);       //open data stream, file named demographics_final.csv
 
if (infile.is_open()){  //checks if file is open
 
 
    getline (infile, line); //gets rid of header
 
int index = 0;  //counter for array size
     
    while (! infile.eof()){     //get line for each item in the demogrpahic data
        getline (infile, userDem, ',');
        getline (infile, gender, ',');
        getline (infile, smartMeter, ',');
        getline (infile, occupation, ',');
        getline (infile, occupationType, ',');
        getline (infile, workFromHome, ',');
        getline (infile, monthsInResidence, ',');
        getline (infile, ResidenceType, ',');
        getline (infile, occupancyType, ',');
        getline (infile, numberOccupants, ',');
        getline (infile, squareFootage, ',');
        getline (infile, numberBedrooms, ',');
        getline (infile, numberBathrooms, ',');
        getline (infile, centralAir, ',');
        getline (infile, windowAC, ',');
        getline (infile, swampCooler, ',');
        getline (infile, ceilingFans, ',');
        getline (infile, floorFans, ',');
        getline (infile, portableAC);  //last line in file
 
        if(userDem == ""){break;}
        //break loop to handle blank line @ end of file
        //"" indicates empty string, which is indicative of \n, and can't convert empty string to int)
     
         
 
        setUserIds(index, stoi(userDem)); //method call to private for opt 6
         
 
        setIsFemales(index, (gender == "Female"));  //method call to private for opt 6
                                    //if string gender = "Female" bool isFemale is true (else false)
        //DEBUG: cout << index << ":" << userIds[index] << "->" << isFemales[index] << endl;    
 
 
        index++;  //everytime you read through the demogrpahic file 
 
    }   //end of while loop reading the file
 
    infile.close();     //close file
 
 
 
}   //end of if statement checking if file is open
 
else {cout << "Error, demographic data file was not opened." << endl;}
 
 
} //end of processDemographicData
 
/**************************************************************************************/
 
void User2::processElecData(string fileNameElec){
            //reads electricity data from fileNameElec and stores data using setConsumption
 
    string returnElecValue;
    string line;
    string deviceID;
    string fromDate;    //formattedFromDate
    string toDate;      //formattedToDate
    string consumption; //hourlyConsumption
    string user;        //need to create string user for last file in user 
                            //(all getlines use strings)
 
    string irrelevant;  //variable to get rid of date in front of hour in from/toDate columns
    int totalCons=0; //total consumption
    int maxCons=0;  //max consumption (start as a counter)
    double avgCons;  //avg consumption
    int consCount=0; //counter for consumption
    int numCons=0;    //number of consumption data numbers
 
    ifstream infile;    //prepares fileName to be read as an input data stream
    infile.open(fileNameElec);  //open data stream, electricity file
 
if (infile.is_open()){  //checks if file is open
 
    getline (infile, line);   //(gets rid of header)
 
    int index = 0;
    while (! infile.eof() && index < 44640){ //index at 44640 worked when code was last compiled (7/28/17)- if it returns error "-nan", try making array smaller?
                                    //index had to be less than 10,000 because I kept getting a segmentation fault core dumped, and after lots of trouble shooting determined the file was too big
            getline (infile, deviceID, ',');
                getline (infile, irrelevant, ' ');  //gets rid of date in front of hour
            getline (infile, fromDate, ',');
                getline (infile, irrelevant, ' ');  //rewrites irrelevant variable - to isolate minute
            getline (infile, toDate, ',');      //is minute - date has already been stripped out by irrelevant
            getline (infile, consumption, ',');
            getline (infile, user);             //(no ',' because it's the end of the line)
         
            if (deviceID == ""){break;}
                //gets rid of empty line character (if there is one) at end of line after "user"
 
 
            setUsers(index, stoi(user));  //calls setUsers private function to fill array
            setConsumptions(index, stoi(consumption));  //calls setConsumptions private function to fill array
            //cout << "DEBUG: index = " << index << ", user = " << stoi(user) << ", consumption = " << stoi(consumption) << endl;
            index++;  //increment index by 1 everytime you loop through while loop
 
     
    } // end of while loop reading electricity data
 
    arrayTtl = index;   //arrayTtl <10,000 - the # of records in electricity data
    infile.close(); //close file
 
}  //end of if statement checking if file was opened
 
else {cout << "Error, electricity data file was not opened." << endl;}
 
 
} //end of processElecData
/***********************************************************************************/
 
void User2::calculateConsumption2(bool isOdd){
    //calculate user's consumption based on following values for reportType
 
    double totalConsumptionEven = 0;
    double totalConsumptionOdd = 0;
 
    for (int i=0; i<arrayTtl; i++) {
        if ((users[i] % 2) == 0 ) {     //when user is even
            totalConsumptionEven += consumptions[i];    //add consumptions everytime it loops through the array(up until limited array size 10,000)
        } 
        else {
            totalConsumptionOdd += consumptions[i];
        }
    }
 
    if (isOdd) {    //if user is odd (1)
        cout << "Total consumption odd: " << totalConsumptionOdd << endl; 
    } 
    else {          //if user is even (0)
        cout << "Total consumption even: " << totalConsumptionEven << endl;
    }
 
 
return;
 
} //end of function calculateConsumption
 
/***********************************************************************************/
void User2::calculateMaleFem(bool isFemale) {
                //calculate gender-based average consumption 
    double totalConsumptionFemale = 0;
    double totalConsumptionMale = 0;
    int numFemale = 0; //counter for females
    int numMale = 0; //counter for males
 
    for (int i=0; i<arrayTtl; i++) {
        if (isFemaleFromUserId(users[i])) {  //calls private function for option 6
                    //if (isFemaleFromUserId(users[i]) == true) {  //calls private function for option 6
                    //if userId is female, run female:
                    //!!!!!THIS IS MY NESTED LOOP!!!!!!!!!!!!!!!!!!!!!!!! - isFemaleFromUserId(int userId) calls 
 
                                    //the for loop in the function, inside the for loop that will calculate the total consumption)
            numFemale++;
            totalConsumptionFemale += consumptions[i];
        } 
        else {      //if userId is male, run male
            numMale++;
            totalConsumptionMale += consumptions[i];
        }
    }
 
    if (isFemale) { //if user is odd (1)
        cout << "Average consumption for females: " << totalConsumptionFemale / numFemale << endl;    
    } 
    else {          //if user is even (0)
        cout << "Average consumption for males: " << totalConsumptionMale / numMale << endl;
    }
 
 
}
 
/************************************************************************************/
 
//----------------------------------private methods--------------------------------------------
    //methods for option 5 from main
    void User2::setConsumption2(int minute, double consump) { 
            //stores the consumption from electricity data in the appropriate index in consumption array
            consumptionMin[minute] = consump;
        }
    void User2::setUsers(int index, int user) {  // array of user ids
        users[index] = user;
    }
    void User2::setConsumptions(int index, int consump) {  // array of consumption
        consumptions[index] = consump;
    }
 
 
    //methods for option 6 from main
    void User2::setUserIds(int index, int userId){
        userIds[index] = userId;
        //DEBUG: cout << index << " " << userId << endl;
    }
 
    void User2::setIsFemales(int index, bool isFemale){
        isFemales[index] = isFemale;
    }
    bool User2::isFemaleFromUserId(int userId){     //when userID = index in userIds[], print out value at that index for isFemales[]
        for (int i=0; i < 13; i++){      //wouldn't take userIds.size() 
            if (userIds[i] == userId){
                return isFemales[i];
            }
        }
    }
