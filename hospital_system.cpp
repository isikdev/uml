
#include <iostream>
#include <string>
#include <vector>

// Administrator Class
class Administrator {
public:
    void addEmployee() {
        std::cout << "Adding an employee..." << std::endl;
    }
    void removeEmployee() {
        std::cout << "Removing an employee..." << std::endl;
    }
    void generateReport() {
        std::cout << "Generating report..." << std::endl;
    }
};

// Nurse Class
class Nurse {
public:
    void addPatient() {
        std::cout << "Adding a patient..." << std::endl;
    }
    void manageInventory() {
        std::cout << "Managing inventory..." << std::endl;
    }
};

// Doctor Class
class Doctor {
public:
    void diagnose() {
        std::cout << "Diagnosing a patient..." << std::endl;
    }
    void treatPatient() {
        std::cout << "Treating a patient..." << std::endl;
    }
};

// Patient Class
class Patient {
public:
    std::string name;
    int id;
    Patient(std::string name, int id) : name(name), id(id) {}
};

// Ward Class
class Ward {
public:
    int wardNumber;
    int capacity;
    std::vector<Patient> patients;
    Ward(int number, int cap) : wardNumber(number), capacity(cap) {}
    void addPatient(Patient p) {
        if (patients.size() < capacity) {
            patients.push_back(p);
            std::cout << "Patient added to ward " << wardNumber << std::endl;
        } else {
            std::cout << "Ward is full!" << std::endl;
        }
    }
};

// Inventory Class
class Inventory {
public:
    std::string itemName;
    int quantity;
    Inventory(std::string name, int qty) : itemName(name), quantity(qty) {}
};

// Main Program Demonstration
int main() {
    Administrator admin;
    admin.addEmployee();
    admin.generateReport();

    Nurse nurse;
    nurse.addPatient();
    nurse.manageInventory();

    Doctor doctor;
    doctor.diagnose();
    doctor.treatPatient();

    Ward ward(101, 2);
    Patient p1("John Doe", 1);
    Patient p2("Jane Smith", 2);
    Patient p3("Extra Patient", 3);

    ward.addPatient(p1);
    ward.addPatient(p2);
    ward.addPatient(p3); // Should show "Ward is full!"

    return 0;
}
