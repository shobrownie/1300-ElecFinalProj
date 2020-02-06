//sbrown sect. 310
//User2 header file
#ifndef USER2_H
#define USER2_H
 
#include <iostream>
using namespace std;
 
class User2{
 
    public:
        User2(); //(default constructor)
                         
        ~User2();  //default destructor
 
        double processDemographicData(string fileNameDem); 
            //reads demographic data from fileName and stores data using setConsumption
         
        void processElecData(string fileName);
            //reads electricity data from fileName and stores data using setConsumption
 
        void calculateConsumption2(bool isOdd);
            //calculate user's consumption based on following values for reportType
 
        void calculateMaleFem(bool isFemale);
 
   
    private:
        //used when calculating consumption for both opt 5 & opt 6
        int userID;     //unique number assigned to each individual in study
        int users[44640];  // array of user ids (for option 5 main menu (even/odd))
        double consumptions[44640];   // array of consumption 
        double consumptionMin[44640];
                //60 min/hr * 24 hrs/day*31 days/month = 44,640 min/month
 
//private methods for option 5 (includes electricity data options for opt. 4) from main
        void setConsumption2(int minute, double consump);  
            //stores the consumption in the appropriate index in consumption array
        int arrayUsers[]; //array of userID's of interest read from demographic data
        void setUsers(int index, int user);  // function called from processElec to fill users[]
        void setConsumptions(int index, int consump); //function called from processElec to fill consumptions[]
         
        //private methods for option 6 from main
        int userIds[13];  //array of userID's for option6 (main menu male/female)   
        bool isFemales[13]; //array of bools of gender (false is male, true is female)  (size hardcoded in because array did not account for value at index = 0)
        void setUserIds(int index, int userId); //set userIds[]
        void setIsFemales(int index, bool isFemale);  //set isFemales[]
        bool isFemaleFromUserId(int userId);
 
 
};
 
#endif //end of USER2_H
