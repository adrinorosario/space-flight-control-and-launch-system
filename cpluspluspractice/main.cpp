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
    float height, diameter, fuel_level, thrust;
    string launch_site, target_destination;
    bool inputStatus;
        
public:
    int rocket_id;
    string rocket_name;
    
    // default constructor
    Rockets() {
        inputStatus = true;
        rocket_id = 0;
        fuel_level = 0.00;
        thrust = 50.0;
        height = 0.00;
        diameter = 0.00;
        rocket_name = "";
        launch_site = "";
        target_destination = "";
        totalRockets++;
    }
    
    // parameterized constructor
    Rockets(int id, float fuel, float height, float diameter, string name, string site, string target) {
        rocket_id = id;
        inputStatus = true;
        fuel_level = fuel;
        thrust = 50.0;
        this -> height = height;
        this -> diameter = diameter;
        rocket_name = name;
        launch_site = site;
        target_destination = target;
        totalRockets++;
    }
    
    // parameterized constructor
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
    
    // copy constructor
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
    
    bool operator==(Rockets &x) {
        return(this -> rocket_name == x.rocket_name || this -> rocket_id == x.rocket_id);
    }
    
    bool operator>(Rockets &x) const {
        return this->height > x.height;
    }
    
    Rockets& operator++() {
        this->rocket_id++;
        return *this;
    }
    
    
    Rockets& operator--() {
        this->rocket_id--;
        return *this;
    }
    
    bool operator!() {
        return this->fuel_level < 50.0; // true if fuel is too low for launching the rocket
    }
    
    // static function to return the total number of rockets
    static int getTotalRockets() {
        return totalRockets;
    }
    
    // Overload [] operator (subscript operator)
    string &operator[](int index) {
        if (index == 0)
            return rocket_name;
        else if (index == 1)
            return launch_site;
        else if (index == 2)
            return target_destination;
        else {
            cout << "Index out of bounds, returning rocket_name by default." << endl;
            return rocket_name;  // Default case
        }
    }

    
    // function to input the rocket details
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

    // function to display the rocket details
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
    
    // declaration of the friend function
    friend void displayMissionSummary(Rockets &rocket);
};

// initialising the static data member with an initial value
int Rockets::totalRockets = 0;

// simple inheritance implementation
class SpaceShuttle: public Rockets {
private:
    int passengerCount;
    bool isReusable;
    
public:
    SpaceShuttle() {
        Rockets();
        passengerCount = 0;
        isReusable = true;
    }
    
    void setPassengerCount() {
        cout<<"Enter the number of passengers/crew: ";
    }
    
    int getPassengerCount() {
        return passengerCount;
    }
    
    void setResuability() {
        cout<<"Is the rocket reusable?";
        cin>>isReusable;
    }
    
    bool getReusability() {
        return isReusable;
    }
    
    void getShuttleDetails() {
        cout<<"Passenger count: "<<passengerCount<<endl;
        cout<<"Reusable: "<< (isReusable ? "Yes" : "No")<<endl;
    }
};

class Engine {
protected:
    string engineType;
    float thrust;

public:
    Engine(string type = "", float t = 0.0) {
        engineType = type;
        thrust = t;
    }
    
    void setEngineDetails(string type, float t) {
        engineType = type; thrust = t;
    }
    
    void displayEngineDetails() const {
        cout << "Engine Type: " << engineType << ", Thrust: " << thrust << " kN" << endl;
    }
};

// multiple inheritance implementation
class Spacecraft: public Rockets, public Engine {
protected:
    string propulsion_system;
    int crewCapacity;
    
public:
    Spacecraft() {
        propulsion_system = "";
        crewCapacity = 0;
        Rockets();
        Rockets::input_details();
    }
    
    void input_propulsion() {
        cout<<"Enter the propulsion system used by the spacecraft: ";
        cin>>propulsion_system;
    }
    
    string getPropulsionSystem() {
        return propulsion_system;
    }
    
    void displaySpaceCraftDetails() {
        rocket_details();
        displayEngineDetails();
        cout << "Crew Capacity: " << crewCapacity << endl;
    }
};

class Rover: public Spacecraft {
private:
    int lifespan;
    
public:
    Rover() {
        Spacecraft();
        lifespan = 0;
    }
    
    void setLife() {
        cout<<"Enter the lifespan of the rover in 'Sols':";
        cin>>lifespan;
    }
    
    int getLife() {
        return lifespan;
    }
    
    void displayRoverDetails() {
        cout<<"Propulsion System: "<<propulsion_system<<endl;
        cout<<"Life span in Sols: "<<lifespan<<endl;
    }
};

class Astronauts {
private:
    string current_mission_name;
    int age, number_of_missions_completed, number_of_hours_in_space, training_hours_completed, inputStauts;
    
public:
    string first_name, last_name;
    
    // default constructor
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
    
    // parameterized constructor
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
    
    // parameterized constructor
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
    
    // function to input the astronaut data
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

// friend function definition
void displayMissionSummary(Rockets &rocket) {
    cout << "\nMission Summary:\n";
    cout<<"Rocket Name: "<<rocket.rocket_name<<"\nRocket ID: "<<rocket.rocket_id<<endl<<"Launch Site: "<<rocket.launch_site<<"\nTarget Destination: "<<rocket.target_destination<<endl<<endl;
}

class Satellites {
private:
    string satellite_name;
    string satellite_type;
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

class SpaceVehicle {
public:
    virtual void launch() { }
    virtual void displayStatus() { }
    virtual ~SpaceVehicle() { }
};

class ISS: public Rockets, public SpaceVehicle {
private:
    double altitude;
    double velocity;
    int crewCapacity;
    int currentCrewCount;
    double oxygenLevel;
    double waterLevel;
    double foodSupply;
    bool dockingPortAvailable;
    
public:
    ISS() {
        altitude = 420.0;
        velocity = 7.66;
        crewCapacity = 7;
        currentCrewCount = 0;
        oxygenLevel = 100.0;
        waterLevel = 100.0;
        foodSupply = 100.0;
        dockingPortAvailable = true;
    }
    
    virtual void launch() override {
        cout<<"ISS already in orbit\n\n";
    }
    
    
    void updateResourceStatus() {
        oxygenLevel -= 0.1;
        waterLevel -= 0.2;
        foodSupply -= 0.15;
        oxygenLevel = (oxygenLevel < 0) ? 0 : oxygenLevel;
        waterLevel = (waterLevel < 0) ? 0 : waterLevel;
        foodSupply = (foodSupply < 0) ? 0 : foodSupply;
    }
    
    void dockSpacecraft(Rockets r) {
        if(!dockingPortAvailable) { // not operator
            cout<<"Failed to dock "<<r.rocket_name<<": No docking port available.\n";
        } else {
            dockingPortAvailable = false;
            cout<<r.rocket_name<<" successfully docked with ISS.\n";
        }
    }
    
    void undockSpacecraft() {
        
        dockingPortAvailable = true;
        cout<<"Spacecraft undocked from ISS.\n";
    }
    
    void addCrewMember() {
        if (currentCrewCount < crewCapacity) {
            currentCrewCount++;
            cout<<"Crew member added. Current crew count: "<<currentCrewCount<<endl;
        } else {
            cout<<"Cannot add crew member. ISS at maximum capacity."<<endl;
        }
    }

    void removeCrewMember() {
        if (currentCrewCount > 0) {
            currentCrewCount--;
            cout<<"Crew member removed. Current crew count: "<<currentCrewCount<<endl;
        } else {
            cout<<"No crew members to remove."<<endl;
        }
    }
    
    virtual void displayStatus() override {
        cout<<"\n---ISS Status---"<<endl;
        cout<<"Altitude: "<<altitude<< " km"<<endl;
        cout<<"Velocity: "<<velocity<<" km/s"<<endl;
        cout<<"Crew: "<<currentCrewCount<< "/"<<crewCapacity<<endl;
        cout<<"Oxygen Level: "<<oxygenLevel<< "%"<<endl;
        cout<<"Water Level: "<<waterLevel<< "%"<<endl;
        cout<<"Food Supply: "<<foodSupply<<"%"<<endl;
        cout<<"Docking Port Available: "<<(dockingPortAvailable ? "Yes" : "No")<<endl;
    }
    
    
};

class MissionLogs {
public:
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
    
    MissionLogs logs[1000000];
    int logCount;
    

public:
    MissionControl() {
        mission_name = "";
        rocket = Rockets(0, 0.00, 0.00, 0.00, "rocket_x", "site_x", "target_x");
        astronaut = Astronauts("", "", "mission_x", 0, 0, 0, 0);
        missionSuccess = false;
        logCount = 0;
    }
    
    
    MissionControl(string m_name, Rockets r, Astronauts a) {
        mission_name = m_name;
        rocket = r;
        astronaut = a;
        missionSuccess = false;
        logCount = 0;
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
        cout << "Mission Status: " << (missionSuccess?"Successful":"Not Launched") << endl << endl;
    }
    
    void inputMissionLog() {
        logs[logCount].inputLog();
        logCount++;
    }
    
    void displayMissionLogs() {
        for(int i = 0; i < logCount; i++) {
            cout<<"Log name: "<<logs[i].logName<<endl;
            cout<<"Log description: "<<logs[i].logDescription<<endl;
        }
    }
};


int main() {
    cout << "Starting program with basic menu and Rockets functionality...\n\n";

    
    Rockets r1(311, 60.0, 100.0, 9.0, "Falcon", "Cape Canaveral", "Mars");
    Rockets r2(102, 40.0, 90.0, 4.5, "Atlas", "Texas", "Moon");
//    cout<<"Rocket Name: "<<r1[0]<<endl;
//    cout<<"Launch Site: "<<r1[1]<<endl;
//    cout<<"Target Destination: "<< r1[2]<<endl;
    
    if (r1 == r2)
            cout << "Rockets are equal.\n\n";
        else
            cout << "Rockets are not equal.\n\n";
    
    cout << "Before incrementing Rocked ID of " << r1.rocket_name <<": "<<r1.rocket_id<<endl;
    ++r1;
    cout << "After incrementing Rocket ID of " << r1.rocket_name << ": " << r1.rocket_id << endl << endl;
    cout << "Before decrementing Rocked ID of " << r2.rocket_name <<": "<<r2.rocket_id<<endl;
    --r2;
    cout << "After decrementing Rocket ID of " << r2.rocket_name << ": " << r2.rocket_id << endl << endl;
    
    
    cout<<"Rocket name using subscript overloading: "<<r1[0]<<endl;
    cout<<"Rocket launch site using subscript overloading: "<<r2[1]<<endl;

    
    int MAX_ITEMS = 100;
    
    Rockets* rockets = new Rockets[MAX_ITEMS];
    Astronauts* astronauts = new Astronauts[MAX_ITEMS];
    Satellites* satellites = new Satellites[MAX_ITEMS];
    MissionControl* mission_control = new MissionControl[MAX_ITEMS];
    ISS iss;
    
    int rocket_count = 0;
    int astronaut_count = 0;
    int satellite_count = 0;
    char choice;
    
    do {
        cout << "\nSpace Flight Control and Launch System\n";
        cout << "1. Manage Rockets\n";
        cout << "2. Manage Astronauts\n";
        cout << "3. Manage Satellites\n";
        cout << "4. Manage ISS\n";
        cout << "5. Mission Control (currently not yet implemented in the program)\n";
        cout << "6. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case '1': {
                int subchoice;
                cout << "Rocket Management\n";
                cout << "1. Add a new rocket\n";
                cout << "2. View all rockets\n";
                cout << "Enter your choice: ";
                cin>>subchoice;
                
                if (subchoice == 1) {
                    if (rocket_count < MAX_ITEMS) {
                        rockets[rocket_count].input_details();
                        rocket_count++;
                        cout<<"Rocket added successfully.\n";
                    } else {
                        cout<<"Maximum rocket count reached!\n";
                    }
                } else if (subchoice == 2) {
                    if (rocket_count > 0) {
                        for (int i = 0; i < rocket_count; i++) {
                            cout << "Rocket " << i + 1 << ":\n";
                            rockets[i].rocket_details();
                        }
                    } else {
                        cout<<"No rockets to display.\n";
                    }
                } else {
                    cerr<<"Invalid choice.\n";
                }
                break;
            }
            case '2': {
                int subchoice;
                cout<<"ASTRONAUT MANAGEMENT\n";
                cout<<"1. Add a new astronaut.\n";
                cout<<"2. View all astronauts.\n";
                cout<<"Enter your choice: ";
                cin>>subchoice;
                
                if(subchoice == 1) {
                    if(astronaut_count < MAX_ITEMS) {
                        astronauts[astronaut_count].input_astronaut_data();
                        astronaut_count++;
                        cout << "Astronaut added successfully.\n";
                    } else {
                        cout<<"Maximum astronaut count reached!\n";
                    }
                } else if(subchoice == 2) {
                    if(astronaut_count > 0) {
                        for(int i=0; i<astronaut_count; i++) {
                            cout<<"Astronaut " << i+1 << ":\n";
                            astronauts[i].astronaut_data();
                        }
                    } else {
                        cout<<"No astronauts to display.\n";
                    }
                } else {
                    cerr<<"Invalid choice. Please try again.\n";
                }
                break;
            }
            case '3': {
                int subchoice;
                cout<<"SATELLITE MANAGEMENT\n";
                cout<<"1. Add a new satellite.\n";
                cout<<"2. View all satellites.\n";
                cout<<"Enter your choice: ";
                cin>>subchoice;
                
                if(subchoice == 1) {
                    if(satellite_count < MAX_ITEMS) {
                        satellites[satellite_count].input_satellite_details();
                        satellite_count++;
                        cout << "Satellite added successfully.\n";
                    } else {
                        cout<<"Maximum satellite count reached!\n";
                    }
                } else if(subchoice == 2) {
                    if(satellite_count > 0) {
                        for(int i=0; i<satellite_count; i++) {
                            cout << "Satellite " << i+1 << ":\n";
                            satellites[i].satellite_details();
                        }
                    } else {
                        cout<<"No satellites to display.\n";
                    }
                } else {
                    cerr<<"Invalid choice. Please try again.\n";
                }
                break;
            }
            case '4': {
                int choice;
                cout<<"ISS MANAGEMENT\n";
                cout<<"1. Display ISS Status.\n";
                cout<<"2. Update resource status.\n";
                cout<<"3. Dock spacecraft.\n";
                cout<<"4. Undock spacecraft.\n";
                cout<<"5. Add crew member.\n";
                cout<<"6. Remove crew member.\n";
                cout<<"7. Launch ISS.\n";
                cout<<"Enter your choice: ";
                cin>>choice;

                if(choice == 1)
                    iss.displayStatus();
                else if(choice == 2) {
                    iss.updateResourceStatus();
                    iss.displayStatus();
                } else if(choice == 3) {
                    Rockets r;
                    cout<<"Enter the details of the spacecraft you want to dock: \n";
                    r.input_details();
                    iss.dockSpacecraft(r);
                } else if(choice == 4) {
                    iss.undockSpacecraft();
                } else if(choice == 5) {
                    iss.addCrewMember();
                } else if(choice == 6) {
                    iss.removeCrewMember();
                } else if(choice == 7) {
                    iss.launch();
                } else {
                    cerr<<"Invalid choice. Please try again.\n";
                }
                break;
            }
            case '5':
                /*
                 Currently causing the code to dive into an infinite loop,
                 needs to be resolved to implement efficient access and usage of memory
                 */
                cout << "Mission Control - Not implemented yet\n";
                break;
            case '6':
                cout << "Exiting program.\n";
                break;
            default:
                cerr<<"Invalid choice. Please try again.\n";
        }
    } while (choice != '6');
    
    // dynamic memory deallocation
    delete [] rockets;
    delete [] astronauts;
    delete [] satellites;
    delete [] mission_control;
    
    return 0;
}
