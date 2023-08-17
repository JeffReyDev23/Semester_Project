#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

//Doctor Function Begins

struct Patient {
    string name;
    int age;
    string diagnosis;
};

// Function to store data in a text file
void storeDataToFile(const vector<Patient>& patients) {
    ofstream outFile("patients.txt");
    if (outFile.is_open()) {
        for (const Patient& patient : patients) {
            outFile << patient.name << "," << patient.age << "," << patient.diagnosis << endl;
        }
        outFile.close();
        cout << "Data saved to patients.txt" << endl;
        } else {
        cout << "Unable to open file for writing." << endl;
    }
}
//Function to View Data Begins
void viewStoredData() {
    ifstream inFile("patients.txt");
    if (inFile.is_open()) {
        cout << setfill('*') << setw(65) << "*" << setfill(' ') << endl;      
	    cout << setw(20) << left << "\tName" << setw(10) << "\tAge" << "\tDiagnosis" << endl;
        cout << setfill('*') << setw(65) << "*" << setfill(' ') << endl;
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string name, diagnosis;
            int age;
            getline(ss, name, ',');
            ss >> age;
            ss.ignore();
            getline(ss, diagnosis);
            cout << setw(32) << left << name << setw(24) << age << setw(10) << diagnosis << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}
//Function to View Data Ends
//Doctor Function Ends


//Admin Function Begins
struct Appointment {
    string patientName;
    string doctorName;
    string appointmentDate;
    string appointmentTime;
};
vector<Appointment> appointments;
// Function to save appointments to a text file
void saveAppointmentsToFile() {
    ofstream outFile("appointments.txt");
    for (const Appointment& appointment : appointments) {
        outFile << appointment.patientName << "\n";
        outFile << appointment.doctorName << "\n";
        outFile << appointment.appointmentDate << "\n";
        outFile << appointment.appointmentTime << "\n";
    }
    outFile.close();
    cout << "Appointments saved to file." << endl;
}
// Function to load appointments from a text file
void loadAppointmentsFromFile() {
    ifstream inFile("appointments.txt");
    if (!inFile.is_open()) {
        cout << "No appointments file found." << endl;
        return;
    }
    Appointment newAppointment;
    while (getline(inFile, newAppointment.patientName)) {
        getline(inFile, newAppointment.doctorName);
        getline(inFile, newAppointment.appointmentDate);
        getline(inFile, newAppointment.appointmentTime);
        appointments.push_back(newAppointment);
    }
    inFile.close();
    cout << "Appointments loaded from file." << endl;
}
//Function to add and save appointments to text file
void addAppointment(){
	Appointment newAppointment;
	system("pause");
	system("cls");
	cout << "\n\t\t\tEnter Patient's Name : ";
	cin.ignore(); getline(cin, newAppointment.patientName);
	cout << "\n\t\t\tEnter Doctor's Name : ";
	getline(cin, newAppointment.doctorName);
	cout << "\n\t\t\tEnter Appointment Date (DD/MM/YY) : ";
	getline(cin, newAppointment.appointmentDate);
	cout << "\n\t\t\tEnter Appointment Time (HH:MM AM/PM) : ";
	getline(cin, newAppointment.appointmentTime);
	appointments.push_back(newAppointment);
	cout << "\n\t\t\tAppointment Added Succesfully!" << endl;
}
//Function to Display Appointments
void displayAppointments(){
	if(appointments.empty()) {
		cout << "\n\t\t\tNo Appointments Available" << endl;
		return;
	}
	cout << "\n\t***********************************" << endl;
	cout << "\n\t\t\tAppointment Schedule" << endl;
	cout << "\n\t**************************************" << endl;
	for(const Appointment& appointment : appointments){
		cout << "\n\t\t\tPatient's Name : " << appointment.patientName << endl;
		cout << "\n\t\t\tDoctor's Name : " << appointment.doctorName << endl;
		cout << "\n\t\t\tDate : " << appointment.appointmentDate << endl;
		cout << "\n\t\t\tTime : " << appointment.appointmentTime << endl;
		system("pause");
		system("cls");
	}
}

// Define the EmployeeList struct
struct EmployeeList {
    string employeeName;
    string employeeGender;
    int employeeAge;
    string employeeRole;
    float employeeSalary; // Add this line to fix the missing field
};
// Declare the vector to store employee data
vector<EmployeeList> employeeList;

// Function to add employee details
void addEmployeeList() {
    EmployeeList newEmployee;
    cout << "\n\t\t\t\tEnter Employee's Name : ";
    cin.ignore();
    getline(cin, newEmployee.employeeName);
    cout << "\n\t\t\t\tEnter Employee's Age : ";
    cin >> newEmployee.employeeAge;
    cout << "\n\t\t\t\tEnter Employee's Gender : ";
    cin >> newEmployee.employeeGender;
    cout << "\n\t\t\t\tEnter Employee's Role : ";
    cin.ignore();
    getline(cin, newEmployee.employeeRole); // Use getline to read the entire line
    cout << "\n\t\t\t\tEnter Employee's Salary : ";
    cin >> newEmployee.employeeSalary;
    employeeList.push_back(newEmployee);
    cout << "\n\t\t\t\tEmployee added successfully!" << endl;
}
// Function to store employee data to file
void storeEmployeeList() {
    ofstream outputFile("employee_list.txt");
    
    if (outputFile.is_open()) {
        for (const EmployeeList& employee : employeeList) {
            outputFile << "\n\t\t\t\t*************************************" << endl;
            outputFile << "\n\t\t\t\tEmployee Name : " << employee.employeeName << endl;
            outputFile << "\n\t\t\t\tEmployee Age : " << employee.employeeAge << endl;
            outputFile << "\n\t\t\t\tEmployee Gender : " << employee.employeeGender << endl;
            outputFile << "\n\t\t\t\tEmployee Role : " << employee.employeeRole << endl;
            outputFile << "\n\t\t\t\tEmployee Salary : " << employee.employeeSalary << endl;
            outputFile << "\n\t\t\t\t*************************************" << endl;
            
        }
        outputFile.close();
        cout << "File has been stored in employee_list.txt" << endl;
    } else {
        cerr << "Error opening file for writing." << endl;
    }
}

// Function to display Employee List
void displayEmployeeList() {
    ifstream inputFile("employee_list.txt");
    
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cerr << "Error opening file for reading." << endl;
    }
}
//Admin Function Ends

//Nurse Function Begins
struct Ward {
    string wardName;
    int capacity;
    int occupiedBeds;
}; 
vector<Ward> wards; 
// Function to store wards in a text file
void storeWards() {
    ofstream outputFile("wards.txt"); // Open a file for writing

    if (outputFile.is_open()) {
        for (const Ward& ward : wards) {
        	system("pause");
            system("cls");
            outputFile << "\n\t\t\t*************************************" << endl;
	        outputFile << "\n\t\t\t\tSACRED HEART HOSPITAL" << endl;
	        outputFile << "\n\t\t\t**************************************" << endl;
            outputFile << "\n\t\t\tWard Name: " << ward.wardName << endl;
            outputFile << "\t\t\t\tCapacity: " << ward.capacity << " beds" << endl;
            outputFile << "\n\t\t\tOccupied Beds: " << ward.occupiedBeds << endl;
         
        }
        outputFile.close(); // Close the file
        cout << "\n\t\t\t\tWards have been stored in wards.txt" << endl;
    } else {
        cerr << "\n\t\t\t\tError opening file for writing." << endl;
    }
} 
//Function to add wards
void addWard() {
	system("pause");
    system("cls");
    Ward newWard;
    cout << "\n\t\t\t\tEnter ward name: ";
    cin.ignore();
    getline(cin, newWard.wardName);
    cout << "\n\t\t\t\tEnter ward capacity: ";
    cin >> newWard.capacity;
    newWard.occupiedBeds = 0;  // Initialize with zero occupied beds
    wards.push_back(newWard);
    cout << "\n\t\t\t\tWard added successfully!" << endl;
    system("pause");
    system("cls");
} 
//Function to display avaible wards
void displayWards() {
    if (wards.empty()) {
        cout << "\n\t\t\t\tNo wards available." << endl;
        system("pause");
        system("cls");
        return;
    } 
 cout << "\n\t\t\t*************************************" << endl;
 cout << "\n\t\t\t\tSACRED HEART HOSPITAL" << endl;
 cout << "\n\t\t\t**************************************" << endl;
 
 cout << "\n\t\t\t\tWard Information:" << endl;
    for (const Ward& ward : wards) {
        cout << "\n\t\t\t\tWard Name: " << ward.wardName << endl;
        cout << "\n\t\t\t\tCapacity: " << ward.capacity << " beds" << endl;
        cout << "\n\t\t\t\tOccupied Beds: " << ward.occupiedBeds << endl;
}
}
//Function to Find Beds in Wards
void updateOccupiedBeds() {

     if (wards.empty()) {
        cout << "\n\t\t\t\tNo wards available." << endl;
        system("pause");
        system("cls");
        return;
    } 
    cout << "\n\t\t\t\tEnter ward name to update occupied beds : ";
    cin.ignore();
    string targetWardName;
    getline(cin, targetWardName); 
for (Ward& ward : wards) {
        if (ward.wardName == targetWardName) {
            cout << "\n\t\t\t\tEnter new number of occupied beds: ";
            cin >> ward.occupiedBeds;
            cout << "\n\t\t\t\tOccupied beds updated successfully!" << endl;
            return;
        }
    } 
cout << "\n\t\t\t\tWard not found." << endl;
}
//Patient Vitals Function
struct HealthReadings {
	string patientName;
	string gender;
	float bloodPressure;
	int systolic, diastolic,age;
	float weight;
	float temperature;
};

vector<HealthReadings>healthRecords;

//Function to add Patient Vitals
void addHealthReadings() {
    HealthReadings newReading;
    cout << "\n\t\t\t\tEnter patient name : ";
    cin.ignore();
    getline(cin, newReading.patientName);
    cout << "\n\t\t\t\tEnter patient age : ";
    cin >> newReading.age;
    cout << "\n\t\t\t\tEnter patient gender : ";
    cin >> newReading.gender;
	cout << "\n\t\t\t\tEnter blood pressure (systolic) : ";
    cin >> newReading.systolic;
    cout << "\n\t\t\t\tEnter blood pressure (diastolic) : ";
    cin >> newReading.diastolic;
    cout << "\n\t\t\t\tEnter weight (Kg) : ";
    cin >> newReading.weight;
    cout << "\n\t\t\t\tEnter temperature (celcius) : ";
    cin >> newReading.temperature;
    healthRecords.push_back(newReading);
    cout << "\n\t\t\t\tHealth reading added successfully!" << endl;
}

//Function to store data to file
void storeHealthReadings() {
    ofstream outputFile("health_readings.txt");
if (outputFile.is_open()) {
        for (const HealthReadings& reading : healthRecords) {
        	outputFile << "\n\t\t\t\t*************************************" << endl;
            outputFile << "\n\t\t\t\tPatient Name : " << reading.patientName << endl;
            outputFile << "\n\t\t\t\tPatient Age : " << reading.age << endl;
            outputFile << "\n\t\t\t\tPatient Gender : " << reading.gender << endl;
            outputFile << "\n\t\t\t\tBlood Pressure : " << reading.systolic << "/" << reading.diastolic << endl;
            outputFile << "\n\t\t\t\tWeight (Kg) : " << reading.weight << endl;
            outputFile << "\n\t\t\t\tTemperature (Celcius) : " << reading.temperature << endl;
            outputFile << "\n\t\t\t\t*************************************" << endl;
        }
        outputFile.close();
        cout << "Health readings have been stored in health_readings.txt" << endl;
    } else {
        cerr << "Error opening file for writing." << endl;
    }
}
//Function to display Patient Vitals
void displayHealthReadings() {
    ifstream inputFile("health_readings.txt");
    
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cerr << "Error opening file for reading." << endl;
    }
}
//Nurse Function Ends

//Laboratory Function Begins
struct LabTest {
    string patientName;
    int age;
    string gender;
    string testName;
    string testResult;
};
//Function to add Lab Test
vector<LabTest> labTests;

void addLabTest() {
    LabTest newTest;
    cout << "\n\t\t\t\tEnter Patient Name : ";
    cin.ignore();
    getline(cin, newTest.patientName);
    cout << "\n\t\t\tEnter Patient Gender : ";
    getline(cin, newTest.gender);
    cout << "\n\t\t\tEnter Test Name : ";
    getline(cin, newTest.testName);
    cout << "\n\t\t\tEnter Test Result : ";
    getline(cin, newTest.testResult);
    labTests.push_back(newTest);
    cout << "\n\t\t\tLab test added successfully!" << endl;
    system("pause");
    system("cls");
}
// Function to save lab tests to a text file
vector<LabTest> labTest;
void saveLabTestsToFile()
 {
    ofstream outFile("lab_results.txt");

    for (const LabTest& test : labTests) {
        outFile << test.patientName << endl;
        outFile << test.age << endl;
        outFile << test.gender << endl;
        outFile << test.testName << endl;
        outFile << test.testResult << endl;
    }
outFile.close();
    cout << "\n\t\t\t\tLab tests saved successfully!" << endl;
}
// Function to load lab tests from a text file
void loadLabTestsFromFile() {
    ifstream inFile("lab_results.txt");

    if (!inFile.is_open()) {
        cout << "\n\t\t\t\tError opening file." << endl;
        return;
    }

    labTests.clear();
    while (true) {
        LabTest newTest;
        getline(inFile, newTest.patientName);
        if (inFile.eof()) {
            break;
        }
        getline(inFile, newTest.testName);
        getline(inFile, newTest.testResult);
        labTests.push_back(newTest);
    }

    inFile.close();
    cout << "\n\t\t\t\tLab tests loaded from successfully!" << endl;
}
//Function to display Lab Results
void displayLabTests() {
    if (labTests.empty()) {
        cout << "\n\t\t\t\tNo lab tests available." << endl;
        	system("pause");
			system("cls");
        return;
    }

    cout << "\n\t\t\tLab Test Results:" << endl;
    cout << "\n\t\t\t***********************" << endl;
    for (const LabTest& test : labTests) {
        cout << "\n\t\t\tPatient Name : " << test.patientName << endl;
        cout << "\n\t\t\tPatient Gender : " << test.gender << endl;
        cout << "\n\t\t\tTest Name : " << test.testName << endl;
        cout << "\n\t\t\tTest Result : " << test.testResult << endl;
        cout << "\n\t\t\t***********************" << endl;
        system("pause");
        system("cls");
    }
}
//Function to Modify Lab Test
void modifyLabTest() {
if (labTests.empty()) {
        cout << "\n\t\t\tNo lab tests available to modify." << endl;
        return;
    }
    cout << "\n\t\t\tEnter the patient name whose test you want to modify : ";
    string patientName;
    cin.ignore();
    getline(cin, patientName);
    auto it = find_if(labTests.begin(), labTests.end(), [&](const LabTest& test) {
        return test.patientName == patientName;
    });

    if (it != labTests.end()) {
        cout << "\n\t\t\tEnter new test result : ";
        getline(cin, it->testResult);
        cout << "\n\t\t\tLab test modified successfully!" << endl;
    } else {
        cout << "\n\t\t\t\tLab test for patient not found." << endl;
    }
}
//Function to Delete Lab Results
void deleteLabTest() {
    if (labTests.empty()) {
        cout << "\n\t\t\tNo lab tests available to delete." << endl;
        return;
    }
    cout << "\n\t\t\tEnter the patient name whose test you want to delete : ";
    string patientName;
    cin.ignore();
    getline(cin, patientName);

    auto it = find_if(labTests.begin(), labTests.end(), [&](const LabTest& test) {
        return test.patientName == patientName;
    });
    if (it != labTests.end()) {
        labTests.erase(it);
        cout << "\n\t\t\tLab test deleted successfully!" << endl;
    } else {
        cout << "\n\t\t\tLab test for patient not found." << endl;
    }
}
//Laboratory Function Ends
//Pharmacy Function Begins(Billing and Others)
struct Medication {
    string name;
    double price;
    int quantity;
};
//Function to add Medication
vector<Medication> medications; 

void addMedication() {
    Medication newMed;
    system("pause"); 
    system("cls");
    cout << "\n\t\t\t\tEnter medication name: ";
    cin.ignore();
    getline(cin, newMed.name);
    cout << "\n\t\t\t\tEnter medication price: ";
    cin >> newMed.price;
    cout << "\n\t\t\t\tEnter medication quantity: ";
    cin >> newMed.quantity;
    medications.push_back(newMed);
    cout << "\n\t\t\tMedication added successfully!" << endl;
    system("pause"); 
    system("cls");
    }  
//Function to Display All Medication
void displayMedications() {
    if (medications.empty()) {
        cout << "\n\t\t\t\tNo medications available." << endl;
    system("pause"); 
    system("cls");
    
        return;
    }
	system("pause"); 
    system("cls");
    cout << "\n\t\t\t************************************" << endl;
	cout << "\n\t\t\t\tMedication List : " << endl;
    cout << "\n\t\t\t************************************" << endl;
    for (const Medication& med : medications) {
        cout << "\n\t\t\t\tName : " << med.name << endl;
        cout << "\n\t\t\t\tPrice : $" << med.price << endl;
        cout << "\n\t\t\t\tQuantity : " << med.quantity << endl;
        cout << "\n\t\t\t\t----------------" << endl;
    }
} 
//Function to update Medication
void updateMedication() {
    if (medications.empty()) {
        cout << "\n\t\t\t\tNo medications available." << endl;
        return;
    } 
    cout << "\n\t\t\t\tEnter medication name to update: ";
    cin.ignore();
    string targetName;
    getline(cin, targetName); 

    for (Medication& med : medications) {
        if (med.name == targetName) {
            cout << "\n\t\t\t\tEnter new price: ";
            cin >> med.price;
            cout << "\n\t\t\t\tEnter new quantity: ";
            cin >> med.quantity;
            cout << "\n\t\t\t\tMedication updated successfully!" << endl;
            system("pause"); 
            system("cls");
    
            return;
        }
    } 
    cout << "\n\t\t\t\tMedication not found." << endl;
} 
//Function to store medication in text file
void saveToFile() {
    ofstream outFile("medications.txt");
    if (!outFile) {
        cerr << "\n\t\t\t\tError opening file." << endl;
    system("pause"); 
    system("cls");
    
        return;
    }

    for (const Medication& med : medications) {
        outFile << med.name << "," << med.price << "," << med.quantity << endl;
    }

    outFile.close();
    cout << "\n\t\t\t\tMedications saved to file." << endl;
    system("pause"); 
    system("cls");
    
}
//Pharmacy Function Ends

//Main Program Begins
int main() {
	while(true){
	
	int loginAttempt = 0;
	int choice;
	string fname,sname,pass;
	
	menu1:
	cout << "\n\t\t\t*************************************" << endl;
	cout << "\n\t\t\t\tSACRED HEART HOSPITAL" << endl;
	cout << "\n\t\t\t**************************************" << endl;
	
	cout << "\n\t\t\t\t01.Doctor" << endl;
	cout << "\n\t\t\t\t02.Admin" << endl;
	cout << "\n\t\t\t\t03.Nurse" << endl;
	cout << "\n\t\t\t\t04.Laboratory" << endl;
	cout << "\n\t\t\t\t05.Pharmacy" << endl;
	cout << "\n\t\t\t\t06.Exit" << endl;
	cout << "\n\t\t\t\tEnter Your Choice : ";
	cin >> choice;
	
	system("pause");
	system("cls");
	
	switch (choice) {
		
		case 1:{ 
	
	cout << "\n\t\t\t*************************************" << endl;
	cout << "\n\t\t\t\tSACRED HEART HOSPITAL" << endl;                                                                                                                                                                                                     //i am Jeff_ReyDev21
	cout << "\n\t\t\t**************************************" << endl;
	
	cout << "\n\t\t\t\tEnter First Name : ";
	cin >> fname;
	
	cout << "\n\t\t\t\tEnter Last Name : ";
	cin >> sname;
	
	while (loginAttempt < 3){
		password:
	
	
	cout << "\n\t\t\t\tEnter Password : ";
	cin >> pass;
    if (pass=="doctor") {
    	
    	 cout << "\n\t\t\tWelcome Doctor " << sname << " ! " << endl;
    	
    	system("pause");
    	system("cls");
    	
    	//Doctor Options Menu Begins
    	menu2:
    	cout << "\n\t\t\t1. Enter Patient Details" << endl;
    	cout << "\n\t\t\t2. View Patient Details"  << endl;
    	cout << "\n\t\t\t3. Exit" << endl;
    	cout << "\n\t\t\t Enter Choice : ";
    	cin >> choice;
    	
    	switch(choice){
    		case 1:{
    			system("pause");
    			system("cls");
    			
				int numPatients;
    
	patient_menu:			
    cout << "\n\t\t\tEnter the number of patients : ";
    cin >> numPatients;

    vector<Patient> patients(numPatients);

    for (int i = 0; i < numPatients; ++i) {
        cout << "\n\t\t\tPatient " << i + 1 << " Details :" << endl;
        cout << "\n\t\t\tName : ";
        cin.ignore();
        getline(cin, patients[i].name);

        cout << "\n\t\t\tAge : ";
        cin >> patients[i].age;

        cout << "\n\t\t\tDiagnosis : ";
        cin.ignore();
        getline(cin, patients[i].diagnosis);
    }

    storeDataToFile(patients);
	
	system("pause");
	system("cls");
	goto menu2;

	;			break;
			}
		


case 2:{
	system("pause");
	system("cls");
	viewStoredData();
	system("pause");
	system("cls");
	goto menu2;
	break;
}

case 3: {
	system("pause");
	system("cls");
	
	goto menu1;
	
	break;
}

default: {
	cout << "\n\t\t\tINVALID CHOICE!" << endl;
	system("pause");
	system("cls");
	
	goto menu2;
	break;
}

		}
}
	else {
		cout << "\n\t\t\tWRONG PASSWORD!" << endl;
		loginAttempt++;
		
    
    
if (loginAttempt == 3) {
    	cout << "\n\t\t\tTOO MANY ATTEMPTS, PROGRAM WILL NOW TERMINATE!" << endl;
    	
		system("pause");
    	system("cls");
    	exit(0);
	}}
   
			break;
	}}
//Doctor Password Authentication and Menu Ends	

//Admin Password Authentication and Menu Begins

case 2: {
    cout << "\n\t\t\t*************************************" << endl;
	cout << "\n\t\t\t\tSACRED HEART HOSPITAL" << endl;
	cout << "\n\t\t\t**************************************" << endl;
	
	cout << "\n\t\t\tFirst Name : " ;
    cin >> fname;
    
    cout << "\n\t\t\tLast Name : " ;
    cin >> sname;

while (loginAttempt < 3){
    
	cout << "\n\t\t\tPassword : " ;
    cin >> pass;
    
    if(pass=="admin"){
    	
    	cout << "\n\t\t\tWelcome Admin " << sname << " ! " << endl;
    	
		system("pause");
    	system("cls");
    
	
	do {
	    
		menu3:
    	
	cout << "\n\t\t\t*************************************" << endl;
	cout << "\n\t\t\t\tSACRED HEART HOSPITAL" << endl;
	cout << "\n\t\t\t**************************************" << endl;
	
		
		cout << "\n\t\t\t1. Add Appointment" << endl;
        cout << "\n\t\t\t2. Display Appointments" << endl;
        cout << "\n\t\t\t3. Add Staff" << endl;
        cout << "\n\t\t\t4. Display Staff List" << endl;
        cout << "\n\t\t\t5. Exit" << endl;
        cout << "\n\t\t\tEnter your choice : ";
        cin >> choice;
        
        
    	
    	switch(choice) {
    		case 1:{
    			addAppointment();
    			system("pause");
    			system("cls");
    			goto menu3;
				break;
			}
			case 2: {
				 displayAppointments();
				 system("pause");
				 system("cls");
				break;
			}
			case 3: {
				addEmployeeList();
				storeEmployeeList();
				break;
			}
			
			case 4: {
				system("pause");
				system("cls");
				displayEmployeeList();
				break;
			}
			case 5: {
				system("pause");
				system("cls");
				goto menu1;
				break;
			}
		default: {
			cout << "\n\t\t\tINVALID CHOICE!" << endl;
			system("pause");
			system("cls");
			goto menu3;
			break;
		}
		}
		} while(choice != 4);
		
		saveAppointmentsToFile();
		
    }
else {
    	
    	cout << "\n\t\t\tWRONG PASSWORD!" << endl;
    	loginAttempt++;
    	
    if (loginAttempt == 3) {
    	cout << "\n\t\t\tTOO MANY ATTEMPTS, PROGRAM WILL NOW TERMINATE!" << endl;
    	
		system("pause");
    	system("cls");
    	exit(0);
	}
    
	}
}
	break;
}
//Admin Passwprd Authenticaiton and Menu Ends

case 3: {
	cout << "\n\t\t\t*************************************" << endl;
	cout << "\n\t\t\t\tSACRED HEART HOSPITAL" << endl;
	cout << "\n\t\t\t**************************************" << endl;
	
	cout << "\n\t\t\tFirst Name : " ;
    cin >> fname;
    
    cout << "\n\t\t\tLast Name : " ;
    cin >> sname;

while (loginAttempt < 3){
    
	cout << "\n\t\t\tPassword : " ;
    cin >> pass;
    
    if(pass=="nurse"){
    	
    	cout << "\n\t\t\tWelcome Nurse " << sname << " ! " << endl;
    	
		system("pause");
    	system("cls");
    	
    	do {
    			
	cout << "\n\t\t\t*************************************" << endl;
	cout << "\n\t\t\t\tSACRED HEART HOSPITAL" << endl;
	cout << "\n\t\t\t**************************************" << endl;
        
        cout << "\n\t\t\t\t1. Add Patient Vitals" << endl;
        cout << "\n\t\t\t\t2. Display Patient Vitals" << endl;
		cout << "\n\t\t\t\t3. Add Ward" << endl;
        cout << "\n\t\t\t\t4. Display Wards" << endl;
        cout << "\n\t\t\t\t5. Update Occupied Beds" << endl;
        cout << "\n\t\t\t\t6. Store Wards to File" << endl;
        cout << "\n\t\t\t\t7. Exit" << endl;
        cout << "\n\t\t\t\tEnter your choice: ";
        cin >> choice; 
        
        system("pause");
        system("cls");

        switch (choice) {
            
			case 1:
                addHealthReadings();
                system("pause");
                system("cls");
                storeHealthReadings();
                system("pause");
                system("cls");
                break;
		   case 2:
	            system("pause");
				system("cls"); 	     	
				 displayHealthReadings();
				 system("pause");
				system("cls"); 	     	
				
                break;
		   case 3:
                addWard();
                break;
            case 4:
                displayWards();
                system("pause");
                system("cls");
                break;
            case 5:
                updateOccupiedBeds();
                system("pause");
                system("cls");
                break;
            case 6:
                storeWards();
                system("pause");
                system("cls");
                break;
            case 7:
                cout << "Exiting..." << endl;
                system("pause");
                system("cls");
                goto menu1;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5); 
    }
    
    else {
    	
    	cout << "\n\t\t\tWRONG PASSWORD!" << endl;
    	loginAttempt++;
    	
    if (loginAttempt == 3) {
    	cout << "\n\t\t\tTOO MANY ATTEMPTS, PROGRAM WILL NOW TERMINATE!" << endl;
    	
		system("pause");
    	system("cls");
    	exit(0);
	}
    
	}
	break;
}//Nurse Password Authentication and Menu Option Ends

//Laboratory Password Authentication and Menu Option Begins

case 4: {
	cout << "\n\t\t\t*************************************" << endl;
	cout << "\n\t\t\t\tSACRED HEART HOSPITAL" << endl;
	cout << "\n\t\t\t**************************************" << endl;
	
	cout << "\n\t\t\tFirst Name : " ;
    cin >> fname;
    
    cout << "\n\t\t\tLast Name : " ;
    cin >> sname;

while (loginAttempt < 3){
    
	cout << "\n\t\t\tPassword : " ;
    cin >> pass;
    
    if(pass=="lab"){
    	
    	cout << "\n\t\t\tWelcome " << fname << " ! " << endl;
    	
		system("pause");
    	system("cls");
    
	cout << "\n\t\t\t*************************************" << endl;
	cout << "\n\t\t\t\tSACRED HEART LABORATORIES" << endl;
	cout << "\n\t\t\t**************************************" << endl;
	
	 do {
        cout << "\n\t\t\t\t1. Add Lab Test" << endl;
        cout << "\n\t\t\t\t2. Display Lab Tests" << endl;
        cout << "\n\t\t\t\t3. Modify Lab Test" << endl;
        cout << "\n\t\t\t\t4. Delete Lab Test" << endl;
        cout << "\n\t\t\t\t5. Exit" << endl;
        cout << "\n\t\t\t\tEnter your choice : ";
        cin >> choice;
        
        system("pause");
        system("cls");

        switch (choice) {
            case 1:
                addLabTest();
                system("cls");
                system("pause");
                saveLabTestsToFile();
                break;
            case 2:
                displayLabTests();
                break;
            case 3:
                modifyLabTest();
                break;
            case 4:
                deleteLabTest();
                break;
            case 5:
                cout << "\n\t\t\tExiting program." << endl;
                system("pause");
                system("cls");
                goto menu1;
                break;
            default:
                cout << "\n\t\t\t\tInvalid choice. Please try again." << endl;
        }
    } while (choice != '5');
}
    	
    else {
    	
    	cout << "\n\t\t\tWRONG PASSWORD!" << endl;
    	loginAttempt++;
    	
    if (loginAttempt == 3) {
    	cout << "\n\t\t\tTOO MANY ATTEMPTS, PROGRAM WILL NOW TERMINATE!" << endl;
    	
		system("pause");
    	system("cls");
    	exit(0);
	}
    break;
}
//Laboratory Password Authentication and Menu Option Ends

//Pharmacy Password Authentication and Menu Option Begins
case 5:    
	cout << "\n\t\t\t*************************************" << endl;
	cout << "\n\t\t\t\tSACRED HEART HOSPITAL" << endl;
	cout << "\n\t\t\t**************************************" << endl;
	
	cout << "\n\t\t\tFirst Name : " ;
    cin >> fname;
    
    cout << "\n\t\t\tLast Name : " ;
    cin >> sname;

while (loginAttempt < 3){
    
	cout << "\n\t\t\tPassword : " ;
    cin >> pass;
    
    if(pass=="pharm"){
    	
    	cout << "\n\t\t\tWelcome " << fname << " ! " << endl;
    	
		system("pause");
    	system("cls");
    	
    	 do {
    cout << "\n\t\t\t*************************************" << endl;
	cout << "\n\t\t\t\tSACRED HEART PHARMACY" << endl;
	cout << "\n\t\t\t**************************************" << endl;
	    cout << "\n\t\t\t\t1. Add Medication" << endl;
        cout << "\n\t\t\t\t2. Display Medications" << endl;
        cout << "\n\t\t\t\t3. Update Medication" << endl;
        cout << "\n\t\t\t\t4. Save Medications to File" << endl;
        cout << "\n\t\t\t\t5. Exit" << endl;
        cout << "\n\t\t\t\tEnter your choice: ";
        cin >> choice; 

        switch (choice) {
            case 1:
             system("pause");
			 system("cls");           	
                addMedication();
                break;
            case 2:
                displayMedications();
                break;
            case 3:
                updateMedication();
                break;
            case 4:
                saveToFile();
                break;
            case 5:
                cout << "Exiting..." << endl;
                system("pause");
                system("cls");
                goto menu1;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5); 
    	
    	
}
else {
    	
    	cout << "\n\t\t\tWRONG PASSWORD!" << endl;
    	loginAttempt++;
    	
    if (loginAttempt == 3) {
    	cout << "\n\t\t\tTOO MANY ATTEMPTS, PROGRAM WILL NOW TERMINATE!" << endl;
    	
		system("pause");
    	system("cls");
    	exit(0);
	}
//Pharmacy Password Authentication and Menu Option Begins

//Exit Function
case 6:{
	exit(0);
	break;
}

default: {
	cout << "\n\t\t\t\tINVALID CHOICE!" << endl;
	break;
}

	return 0;
}
}
}
}
}
}
}
}