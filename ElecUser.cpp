//Shoshana Brown, CSCI1300 - Sect. 310, Final Project
//ElecUser class methods
#include <fstream>
#include "ElecUser.h"
#include <iomanip>
#include <iostream>
using namespace std;
 
//--------------------public methods------------------------------------------------
 
 
ElecUser::ElecUser(int uID) //default constructor
{
    userID = uID;
}
 
ElecUser::~ElecUser()   //default destructor
{
}
 
 
void ElecUser::setUserID(int uID){ //set userID equal to uID
    userID = uID;
}
 
 
int ElecUser::getUserID(){  //gets user's ID
    return userID;    //returns value stored in variable userID
}
 
string ElecUser::getHomeType(){ //returns the user's home type as a string
    if (homeType == 1)
        {return "House";}   //return string House - 
            //(don't declare as string cause it's not being saved as variable
     
    else if (homeType == 2)
        {return "Townhouse";}   //return string Townhouse
 
    else if (homeType == 3)
        {return "Apartment";} //return string apartment
}
 
bool ElecUser::getSTEMJobStatus(){ //returns whether or not user has a STEM job
    return hasSTEMJob;
}
 
bool ElecUser::getWorksAtHomeStatus(){   //returns whether or not the user works from home
    return worksAtHome;
}
/***********************************************************************/
void ElecUser::processDemographicData(string fileNameDem){  
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
        //break loop if here is a new line character after Residence Type, meaning userDem is an empty string
        //"" indicates empty string, which is indicative of \n, and can't convert empty string to int)
 
if (userID == stoi(userDem)){       //compare int userID to string userDem with typecasting userDem to int
    if (occupationType == "STEM")
        {setSTEMJob(true);}
 
        else if (occupationType == "Non-STEM")
                {setSTEMJob(false);}
 
    if (workFromHome == "Yes")
        {setWorksAtHome(true);}
         
        else if (workFromHome == "No")
                {setWorksAtHome(false);}
 
                //setHomeType:
    if (ResidenceType == "House")
            {homeType = 1;}     //call private variable homeType, and string residenceType = int homeType 
                                //(will reverse later)
 
    if (ResidenceType == "Townhouse")
            {homeType = 2;}
 
    if (ResidenceType == "Apartment")
            {homeType = 3;}
 
 
    } //end of if userID statement
 
}   //end of while loop
 
    infile.close();     //close file
}   //end of if statement checking if file is open
 
else {cout << "Error, demographic data file was not opened." << endl;}
 
 
 
 
} //end of processDemographicData
 
/*****************************************************************************************/
void ElecUser::processElecData(string fileNameElec){
    //reads electricity data from fileName and stores data using setConsumption
    string returnElecValue;
    string line;
    string deviceID;
    string toHour;
    string toMin;
    string consumptionStr;  //minuteConsumption
 
    string user;        //need to create string user for last file in user 
                            //(all getlines use strings)
    string irrelevant;  //variable to get rid of date in front of hour in from/toDate columns
 
    int totalCons=0; //total consumption
    int maxCons=0;  //max consumption (start as a counter)
    double avgCons;  //avg consumption
    int consCount=0; //counter for consumption
    int numCons=0;    //number of consumption data numbers
 
    ifstream infile;    //prepares fileName to be read as an input data stream
    infile.open(fileNameElec);  //open data stream, file named Assignment6ElecData_final.csv
 
if (infile.is_open()){  //checks if file is open
 
    getline (infile, line);   //(gets rid of header)
 
    while (! infile.eof()){                     //get line for each iteration in the data
            getline (infile, deviceID, ',');
            getline (infile, irrelevant, ',');  // skip fromDate
            getline (infile, irrelevant, ' ');  // skip toDate's date
            getline(infile, toHour, ':');
            getline(infile, toMin, ':');
            getline (infile, irrelevant, ',');  // skip toDate's seconds
            getline (infile, consumptionStr, ',');
            getline (infile, user);             //(no ',' because it's the end of the line)
         
        if (deviceID == ""){break;}
                //break the while loop if there is a new line character after "user" number in file
                //(if it reads in the spot of deviceID a new line (an empty string) then break the loop
                    //cause you can't convert an empty string to an integer)
 
        if (userID == stoi(user)){  //do the following below - as long as userID == user
                //convert user to integer to compare to int userID
 
//#include <iomanip> //allows you to convert string to double
           double consump;
           consump = stod(consumptionStr); //typecast consump from string consumption
                        //consump is a double
           //cout << "DEBUG: consumptionStr = " << consumptionStr << ", consump = " << consump << endl;
 
           //need to break up string fromDate or toDate to get the hours
                 
          int minute = stoi(toHour) * 60 + stoi(toMin);
 
          setConsumption(minute, consump); //call private void function setConsumption
     
        } // end of if statement
 
    } // end of while loop
    infile.close(); //close file
 
}  //end of if statement checking if file was opened
 
else {cout << "Error, electricity data file was not opened." << endl;}
 
 
 
 
} //end of processElecData
 
/***********************************************************************/
double ElecUser::calculateConsumption(string reportType){
    //calculate user's consumption based on following values for reportType
 
    double returnValue;
    double maxCount = 0; //set max = 0 so it'll become overwritten by something else
    double avg=0;
    double total=0;
    //int arrayTtl=10;  // really 44640
    int arrayTtl=44640;
 
    if (reportType == "total"){ //will run to find total or avg - not equal max
        for (int i=0; i<arrayTtl; i++){
            total = total + consumption[i];
        }
        returnValue = total;
    }
    //cout << consumption[14] << endl;
 
    if (reportType == "average"){
        for (int i=0; i<arrayTtl; i++){
            total = total + consumption[i];
            //cout << "DEBUG: consumption[" << i << "] = " << consumption[i] << ", total = " << total << endl;
            avg = total/arrayTtl;
        }
        returnValue = avg;
    }   
 
    if (reportType == "max"){
        for (int i=0; i<arrayTtl; i++){
            if (maxCount < consumption[i]) {
                maxCount = consumption[i];
            }
        }
        returnValue = maxCount;
    }
 
return returnValue;
 
} //end of function calculateConsumption
 
 
 
//---------------------private methods------------------------------------------
//private methods for header:
 
 
void ElecUser::setConsumption(int minute, double consump){  
    //stores the consumption in the appropriate index in consumption array
    consumption[minute] = consump;  //at index minute, set consumption value consump in that index 
    //cout << "DEBUG: consump = " << consump << ", consumption[" << minute << "]=" 
    //<< consumption[minute] << endl;
    // Note: really need to take into account the change in date too
}
 
 
void ElecUser::setSTEMJob(bool isSTEM){   //set hasSTEMJob to true if user has a STEM job and false if not
    hasSTEMJob = isSTEM;
}
 
void ElecUser::setHomeType(int hType){ //sets homeType equal hType
    homeType = hType;  //hType is temporary variable
}
     
void ElecUser::setWorksAtHome(bool wfh){
            //sets worksAtHome to true if user works from home - false if they do not
    worksAtHome = wfh;
}
