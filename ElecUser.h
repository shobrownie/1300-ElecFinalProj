//sbrown sect. 310
//ElecUser header file
#ifndef ELECUSER_H
#define ELECUSER_H
 
#include <iostream>
using namespace std;
 
class ElecUser{
 
    public:
        ElecUser(int uID); //(parameterized constructor)
                        //creates a user w/ userID equal to uID
        ~ElecUser();
        void setUserID(int uID); //set userID equal to uID
        int getUserID();
        string getHomeType(); //returns the user's home type as a string
        bool getSTEMJobStatus(); //returns whether or not user has a STEM job
        bool getWorksAtHomeStatus();   //returns whether or not the user works from home
        void processDemographicData(string fileName);  
            //reads demographic data from fileName and stores data using setConsumption
        void processElecData(string fileName);
            //reads electricity data from fileName and stores data using setConsumption
        double calculateConsumption(string reportType);
            //calculate user's consumption based on following values for reportType
 
   
    private:
        int userID;     //unique number assigned to each individual in study
        int homeType;   //one of 3 values corresponding to house type
        double consumption[44640]; 
                //an array of doubles that contain electricity consumption per minute of user
        bool hasSTEMJob;   //corresponds to whether a user has a STEM job (true/false)
        bool worksAtHome; //corresponds to whether user works from home (true)/(false)
 
        //private methods for header:
        void setConsumption(int minute, double consump);  
            //stores the consumption in the appropriate index in consumption array
        void setSTEMJob(bool isSTEM);   //set hasSTEMJob to true if user has a STEM job and false if not
        void setHomeType(int hType); //sets homeType equal hType
        void setWorksAtHome(bool wfh); 
            //sets worksAtHome to true if user works from home - false if they do not
 
 
};
 
 
 
#endif // ELECUSER_H
