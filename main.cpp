#include <iostream>
#include <string>
using namespace std;

// Maximum number of patients
const int MAX_PATIENTS = 100;

// Structure to store patient information
struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string disease;
    string doctor;
    bool active; // used for delete operation
};

// Global array and counter
Patient patients[MAX_PATIENTS];
int patientCount = 0;

// Function declarations
void addPatient();
void updatePatient();
void deletePatient();
void searchPatient();
void displayAllPatients();
int findPatientIndex(int id);
void menu();

int main() {
    int choice;

    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addPatient();
            break;
        case 2:
            updatePatient();
            break;
        case 3:
            deletePatient();
            break;
        case 4:
            searchPatient();
            break;
        case 5:
            displayAllPatients();
            break;
        case 0:
            cout << "Exiting system..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

// Menu display
void menu() {
    cout << "\n===== Hospital Patient Management System =====" << endl;
    cout << "1. Register New Patient" << endl;
    cout << "2. Update Patient Record" << endl;
    cout << "3. Delete Patient Record" << endl;
    cout << "4. Search Patient" << endl;
    cout << "5. Display All Patients" << endl;
    cout << "0. Exit" << endl;
}

// Add new patient
void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        cout << "Patient limit reached!" << endl;
        return;
    }

    Patient p;
    cout << "Enter Patient ID: ";
    cin >> p.id;

    if (findPatientIndex(p.id) != -1) {
        cout << "Patient ID already exists!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, p.name);
    cout << "Enter Age: ";
    cin >> p.age;
    cin.ignore();
    cout << "Enter Gender: ";
    getline(cin, p.gender);
    cout << "Enter Disease: ";
    getline(cin, p.disease);
    cout << "Enter Doctor Name: ";
    getline(cin, p.doctor);

    p.active = true;
    patients[patientCount++] = p;

    cout << "Patient registered successfully." << endl;
}

// Update patient record
void updatePatient() {
    int id;
    cout << "Enter Patient ID to update: ";
    cin >> id;

    int index = findPatientIndex(id);
    if (index == -1) {
        cout << "Patient not found!" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter New Name: ";
    getline(cin, patients[index].name);
    cout << "Enter New Age: ";
    cin >> patients[index].age;
    cin.ignore();
    cout << "Enter New Gender: ";
    getline(cin, patients[index].gender);
    cout << "Enter New Disease: ";
    getline(cin, patients[index].disease);
    cout << "Enter New Doctor Name: ";
    getline(cin, patients[index].doctor);

    cout << "Patient record updated successfully." << endl;
}

// Delete patient record (logical delete)
void deletePatient() {
    int id;
    cout << "Enter Patient ID to delete: ";
    cin >> id;

    int index = findPatientIndex(id);
    if (index == -1) {
        cout << "Patient not found!" << endl;
        return;
    }

    patients[index].active = false;
    cout << "Patient record deleted successfully." << endl;
}

// Search patient by ID
void searchPatient() {
    int id;
    cout << "Enter Patient ID to search: ";
    cin >> id;

    int index = findPatientIndex(id);
    if (index == -1) {
        cout << "Patient not found!" << endl;
        return;
    }

    Patient p = patients[index];
    cout << "\n--- Patient Details ---" << endl;
    cout << "ID      : " << p.id << endl;
    cout << "Name    : " << p.name << endl;
    cout << "Age     : " << p.age << endl;
    cout << "Gender  : " << p.gender << endl;
    cout << "Disease : " << p.disease << endl;
    cout << "Doctor  : " << p.doctor << endl;
}

// Display all patients
void displayAllPatients() {
    if (patientCount == 0) {
        cout << "No patient records available." << endl;
        return;
    }

    cout << "\n===== Patient List =====" << endl;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].active) {
            cout << "------------------------" << endl;
            cout << "ID      : " << patients[i].id << endl;
            cout << "Name    : " << patients[i].name << endl;
            cout << "Age     : " << patients[i].age << endl;
            cout << "Gender  : " << patients[i].gender << endl;
            cout << "Disease : " << patients[i].disease << endl;
            cout << "Doctor  : " << patients[i].doctor << endl;
        }
    }
}

// Find patient index by ID
int findPatientIndex(int id) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id && patients[i].active) {
            return i;
        }
    }
    return -1;
}
