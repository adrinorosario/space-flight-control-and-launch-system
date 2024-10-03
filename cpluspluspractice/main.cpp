//
//  main.cpp
//  cpluspluspractice
//
//  Created by Adrino Rosario on 30/07/24.
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Rockets {
private:
    static int totalRockets;
    int rocket_id;
    float height, diameter, fuel_level, thrust;
    string rocket_name, launch_site, target_destination;
    bool inputStatus;
        
public:
    Rockets() {
        inputStatus = true;
        fuel_level = 0.00;
        thrust = 50.0;
        height = 0.00;
        diameter = 0.00;
        rocket_name = "";
        launch_site = "";
        target_destination = "";
        totalRockets++;
    }
    
    Rockets(int id, float fuel, float height, float diameter, string name, string site, string target) {
        rocket_id = id;
        inputStatus = true;
        fuel_level = fuel;
        thrust = 50.0;
        height = height;
        diameter = diameter;
        rocket_name = name;
        launch_site = site;
        target_destination = target;
        totalRockets++;
    }
    
    Rockets(float height, float diameter, string name) {
        rocket_id = rand();
        inputStatus = true;
        height = height;
        diameter = diameter;
        rocket_name = name;
        thrust = 50.0;
        fuel_level = 0.00;
        launch_site = "";
        target_destination = "";
        totalRockets++;
    }
    
    Rockets(Rockets &rocket) {
        rocket_id = rocket.rocket_id;
        inputStatus = true;
        height = rocket.height;
        diameter = rocket.diameter;
        rocket_name = rocket.rocket_name + "_copy";
        thrust = rocket.thrust;
        fuel_level = rocket.fuel_level;
        launch_site = rocket.launch_site;
        target_destination = rocket.target_destination;
        totalRockets++;
    }
    
    static int getTotalRockets() {
        return totalRockets;
    }
    
    void input_details() {
        while(inputStatus) {
            cout<<"Enter the Rocket ID and Rocket Name:\n";
            cin>>rocket_id>>rocket_name;
            
            if(rocket_id < 1) {
                cout<<"Rocket ID cannot be 0 or a negative number. Re-eneter the details.\n\n";
                continue;
            }

            cout<<"\nEnter the height and diamter of the rocket:\n";
            cin>>height>>diameter;
            
            if(height < 1 || diameter < 1){
                cout<<"Height and diameter cannot be 0 or a negative number. Re-enter the values.\n\n";
                continue;
            }
            
            cout<<"\nEnter the launch site and target destination:\n";
            cin>>launch_site>>target_destination;
            inputStatus = false;
        }
    }

    void rocket_details() {
        cout<<"\n\nRocket name: "<<rocket_name<<"\nRocket ID: "<<rocket_id<<"\nHeight: "<<height<<"\nDiameter: "<<diameter<<"\nLaunch Site: "<<launch_site<<"\nTarget Destination: "<<target_destination<<endl<<endl;
    }
    
    // Pass by value (makes a copy of the object)
    void updateRocketDetailsByValue(Rockets rocket) {
        rocket.rocket_name = "Updated_" + rocket.rocket_name;
        cout << "Inside updateRocketDetailsByValue: " << rocket.rocket_name << endl;
    }
    
    // Pass by reference (modifies the original object)
    void updateRocketDetailsByReference(Rockets &rocket) {
        rocket.rocket_name = "Modified_" + rocket.rocket_name;
        cout << "Inside updateRocketDetailsByReference: " << rocket.rocket_name << endl;
    }
    
    // Return by reference function for rocket_name
    string &getRocketName() {
        return rocket_name;
    }
    
    
    void launch() {
        cout<<"Enter the fuel level: ";
        cin>>fuel_level;
        if(fuel_level < 50.0) {
            cout<<"Fuel level too low for launch activity\n\n";
            launch();
        } else {
            cout<<rocket_name<<" launched with default thrust of "<<thrust<<"%.\n\n";
        }
    }
    
    void launch(double customThrust) {
        cout<<"Enter the fuel level: ";
        cin>>fuel_level;
        if (fuel_level <= 50.0) {
            cout<<rocket_name<<"cannot launch. Fuel level too low.\n";
        } else {
            thrust = customThrust;
            cout<<rocket_name<<" launched with thrust set to "<< thrust<< "%.\n\n";
        }
    }
    
    void launch(double customThrust, string targetOrbit) {
        cout<<"Enter the fuel level: ";
        cin>>fuel_level;
        if (fuel_level <= 50.0) {
            cout<<rocket_name<<" cannot launch. Fuel level too low.\n\n";
        } else {
            thrust = customThrust;
            cout<<rocket_name<<" launched with thrust set to "<<thrust<<"% towards "<<targetOrbit<<" orbit.\n\n";
        }
    }
    
    friend void displayMissionSummary(Rockets &rocket);
};
int Rockets::totalRockets = 0;

class Astronauts {
private:
    string current_mission_name;
    int age, number_of_missions_completed, number_of_hours_in_space, training_hours_completed, inputStauts;
    
public:
    string first_name, last_name;
    
    Astronauts() {
        inputStauts = true;
        first_name = "Astronaut";
        last_name = "Astronaut";
        current_mission_name = "";
        age = 0;
        number_of_missions_completed = 0;
        number_of_hours_in_space = 0;
        training_hours_completed = 0;
    }
    
    Astronauts(string fname, string lname, string cur_mis, int age, int numMisComp, int numHrsSpc, int trainHrsComp) {
        inputStauts = true;
        first_name = fname;
        last_name = lname;
        current_mission_name = cur_mis;
        age = age;
        number_of_missions_completed = numMisComp;
        number_of_hours_in_space = numHrsSpc;
        training_hours_completed = trainHrsComp;
    }
    
    Astronauts(string fname, string lname, int age) {
        inputStauts = true;
        first_name = fname;
        last_name = lname;
        current_mission_name = "";
        age = age;
        number_of_missions_completed = 0;
        number_of_hours_in_space = 0;
        training_hours_completed = 0;
    }
    
    void input_astronaut_data(){
        
        while(inputStauts) {
            printf("Enter the first name and last name: \n");
            cin>>first_name>>last_name;
            cout<<"\nEnter the age: \n";
            cin>>age;
            
            if(age < 24) {
                cout<<"An astronaut cannot be less than 24 years of age. Re-enter the details.\n";
                continue;
            }
            
            cout<<"\nEnter the astronaut's current mission name: \n";
            cin>>current_mission_name;
            cout<<"\nHow many hours has the astronauts completed in space and how many training hours has the astronaut completed?\n";
            cin>>number_of_hours_in_space>>training_hours_completed;
            
            if(training_hours_completed < 100){
                cout<<"\nAn astronaut should have completed a minimum of 100 HOURS to be allowed to fly the misssion. Re-enter the details.\n";
                continue;
            }
            
            cout<<"\nAnd how many missions has the astronaut completed?\n";
            cin>>number_of_missions_completed;
            inputStauts = false;
        }
    }
    
    void input_astronaut_data(string firstName, string lastName, int age, string currentMissionName = "None", int numberOfHoursInSpace = 0, int trainingHoursCompleted = 0, int numberOfMissionsCompleted = 0) {
        
        while(inputStauts) {
            first_name = firstName;
            last_name = lastName;
            
            if(age < 24) {
                cout<<"An astronaut cannot be less than 24 years of age. Re-enter the details.\n\n";
                input_astronaut_data();
                break;
            } else {
                age = age;
                current_mission_name = currentMissionName;
                number_of_hours_in_space = numberOfHoursInSpace;
                training_hours_completed = trainingHoursCompleted;
                number_of_missions_completed = numberOfMissionsCompleted;
                inputStauts = false;
            }
        }
    }

    
    void astronaut_data(){
        cout<<"\n\nAstronaut name: "<<first_name<<" "<<last_name<<endl<<"Age: "<<age<<"\nCurrent mission: "<<current_mission_name<<"\nNumber of hours completed in space: "<<number_of_hours_in_space<<"\nTraining hours completed: "<<training_hours_completed<<"\nMissions completed: "<<number_of_missions_completed<<endl<<endl;
    }
    
};

void displayMissionSummary(Rockets &rocket) {
    cout << "\nMission Summary:\n";
    cout<<"Rocket Name: "<<rocket.rocket_name<<"\nRocket ID: "<<rocket.rocket_id<<endl<<"Launch Site: "<<rocket.launch_site<<"\nTarget Destination: "<<rocket.target_destination<<endl<<endl;
}

class Satellites {
private:
    string satellite_name;
    string satellite_type;  // e.g., communication, weather, GPS, etc.
    float satellite_weight;
    string orbit_destination;

public:
    Satellites() {
        satellite_name = "";
        satellite_type = "";
        satellite_weight = 0.0;
        orbit_destination = "";
    }

    Satellites(string name, string type, float weight, string orbit) {
        satellite_name = name;
        satellite_type = type;
        satellite_weight = weight;
        orbit_destination = orbit;
    }
    
    void input_satellite_details() {
        cout << "Enter Satellite Name: ";
        cin >> satellite_name;
        cout << "Enter Satellite Type: ";
        cin >> satellite_type;
        cout << "Enter Satellite Weight: ";
        cin >> satellite_weight;
        cout << "Enter Orbit Destination: ";
        cin >> orbit_destination;
    }
    
    void satellite_details() {
        cout << "\nSatellite Name: " << satellite_name << endl;
        cout << "Type: " << satellite_type << endl;
        cout << "Weight: " << satellite_weight << " kg" << endl;
        cout << "Orbit Destination: " << orbit_destination << endl << endl;
    }
};

class MissionLogs {
protected:
    int logId;
    string logName, logDescription;
    bool isCritical, isIssue, isVulnerability;

public:
    MissionLogs() {
        logId = rand();
        logName = "";
        logDescription = "";
        isCritical =  false;
        isIssue = false;
        isVulnerability = false;
    }
    
    MissionLogs(int id, string name, bool isCritical) {
        logId = id;
        logName = name;
        isCritical = isCritical;
    }
    
    void inputLog() {
        cout<<"Enter the Log Name:\n";
        cin>>logName;
        cout<<"Enter the description or log datas (keep it descriptive for further analysis):\n";
        cin>>logDescription;
        cout<<"Is it the critical? (Does the log pertain to something that can affect the mission or future missions?):\n";
        cin>>isCritical;
        cout<<"Is it an issue?:\n";
        cin>>isIssue;
        cout<<"Is it a vulnerability in an asepct of the mission?:\n";
        cin>>isVulnerability;
    }
};


class MissionControl {
private:
    string mission_name;
    Rockets rocket;
    Astronauts astronaut;
    bool missionSuccess;
    
    static MissionLogs logs[1000000];
    

public:
    MissionControl() {
        mission_name = "";
        rocket = Rockets(0, 0.00, 0.00, 0.00, "rocket_x", "site_x", "target_x");
        astronaut = Astronauts("", "", "mission_x", 0, 0, 0, 0);
        missionSuccess = false;
    }
    
    
    MissionControl(string m_name, Rockets r, Astronauts a) {
        mission_name = m_name;
        rocket = r;
        astronaut = a;
        missionSuccess = false;
    }
    
    void startMission() {
        cout << "Starting mission: " << mission_name << endl;
        if (rocket.getRocketName() != "" && astronaut.first_name != "") {
            rocket.launch();
            missionSuccess = true;
            cout << "Mission " << mission_name << " is successful!" << endl;
        } else {
            cout << "Mission " << mission_name << " cannot be started due to missing details." << endl;
        }
    }
    
    void missionDetails() {
        cout << "Mission Name: " << mission_name << endl;
        rocket.rocket_details();
        astronaut.astronaut_data();
        cout << "Mission Status: " << (missionSuccess ? "Successful" : "Not Launched") << endl << endl;
    }
};



int main(int argc, const char * argv[]) {
    cout<<"\tSPACE FLIGHT CONTROL AND LAUNCH SYSTEM\n\n";

    
//    char c;
//    cout<<"Enter 'A' to enter the astronaut details and 'R' to enter the rocket details:\n";
//    cin>>c;
//    
//    switch (c) {
//        case 'A': {
//            int n = 0;
//            while(!n) {
//                cout<<"Enter the number of rockets:\n";
//                cin>>n;
//                if(n < 1){
//                    cout<<"Size cannot be less than 1. Re-enter the size.\n";
//                    continue;
//                }
//            }
//
//            Astronauts astr[n];
//            int i = 0;
//            
//            while(i<n){
//                cout<<"Enter the details of Astronaut "<<i+1<<endl;
//                astr[i].input_astronaut_data();
//                cout<<endl;
//                i++;
//            }
//            
//            cout<<"The Astronaut details for "<<n<<" astronauts:\n";
//            i = 0;
//            while(i<n){
//                astr[i].astronaut_data();
//                cout<<endl;
//                i++;
//            }
//            break;
//        }
//            
//        case 'R': {
//            int n = 0;
//            while(!n) {
//                cout<<"Enter the number of rockets:\n";
//                cin>>n;
//                if(n < 1){
//                    cout<<"Size cannot be less than 1. Re-enter the size.\n";
//                    continue;
//                }
//            }
//            
//            Rockets rcts[n];
//            int j = 0;
//            
//            while(j<n){
//                cout<<"Enter the details of Rocket "<<j+1<<endl;
//                rcts[j].input_details();
//                cout<<endl;
//                j++;
//            }
//            
//            cout<<"The Rocket details for "<<n<<" rockets:\n";
//            j = 0;
//            while(j<n){
//                rcts[j].rocket_details();
//                cout<<endl;
//                j++;
//            }
//            break;
//        }
//            
//        default:
//            cout<<"Something went wrong\n";
//    }
    
//---------------------------------------------------------------------------------------------------------
    
    /*

         Rockets r1(55.6, 5.4, "Vulcan_Centaur");
         Astronauts a1("John", "Doe", "Lunar Mission", 32, 3, 120, 250);
         Satellites s1("ComSat-X", "Communication", 1500.5, "GEO");

         // Display rocket, astronaut, and satellite details
         r1.rocket_details();
         a1.astronaut_data();
         s1.satellite_details();

         // Create a mission
         MissionControl mission("MoonLanding", r1, a1);
         mission.startMission();
         mission.missionDetails();

     */
    

    //Astronauts a1("Michael", "Trevor", "Artemis Moon Landing", 31, 4, 57, 142);
    //a1.input_astronaut_data("Adrino", "Rosario", 45);

    Rockets r1 = Rockets(55.6, 5.4, "Vulcan_Centaur");
//    Rockets r2 = Rockets(40.6, 4.4, "Firefly_Alpha");
//    //a1.astronaut_data();
//    //r1.input_details();
//    displayMissionSummary(r1);
    
    cout<<"Returning rocket name using return by reference: "<<r1.getRocketName()<<endl;
    
    
    // Pass by value (no change to the original object)
    r1.updateRocketDetailsByValue(r1);
    r1.rocket_details();  // Name should remain the same

    // Pass by reference (changes the original object)
    r1.updateRocketDetailsByReference(r1);
    r1.rocket_details();  // Name should be modified
    
    Rockets r2 = r1;
    r2.rocket_details();
    
    cout << "Total Rockets: " << Rockets::getTotalRockets() << endl << endl;

    return 0;
}

