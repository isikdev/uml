
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Authentication System
class AuthSystem {
public:
    bool authenticate(const std::string& username, const std::string& role) {
        std::cout << "Authenticating " << username << " as " << role << std::endl;
        return true; // Simulated authentication
    }
};

// Ward Management
class Ward {
public:
    int wardNumber;
    int capacity;
    bool isAvailable;
    std::vector<std::string> patients;

    Ward(int number, int cap) : wardNumber(number), capacity(cap), isAvailable(true) {}

    void updateAvailability(bool status) {
        isAvailable = status;
        std::cout << "Ward " << wardNumber << " availability updated to: " 
                  << (status ? "Available" : "Unavailable") << std::endl;
    }

    void addPatient(const std::string& patientName) {
        if (isAvailable && patients.size() < capacity) {
            patients.push_back(patientName);
            std::cout << "Patient " << patientName << " added to Ward " << wardNumber << std::endl;
        } else {
            std::cout << "Cannot add patient. Ward is either full or unavailable!" << std::endl;
        }
    }
};

// Inventory Management
class Inventory {
    std::unordered_map<std::string, int> items;

public:
    void addItem(const std::string& itemName, int quantity) {
        items[itemName] += quantity;
        std::cout << "Added " << quantity << " of " << itemName << " to inventory." << std::endl;
    }

    void requestItem(const std::string& itemName, int quantity) {
        if (items[itemName] >= quantity) {
            items[itemName] -= quantity;
            std::cout << "Approved request for " << quantity << " of " << itemName << std::endl;
        } else {
            std::cout << "Insufficient " << itemName << " in inventory!" << std::endl;
        }
    }
};

// Employee Management
class Administrator {
public:
    void addEmployee(const std::string& name) {
        std::cout << "Employee " << name << " added." << std::endl;
    }

    void removeEmployee(const std::string& name) {
        std::cout << "Employee " << name << " removed." << std::endl;
    }

    void updateEmployee(const std::string& name, const std::string& newDetails) {
        std::cout << "Updated employee " << name << " with details: " << newDetails << std::endl;
    }

    void generateReport() {
        std::cout << "Generating hospital report..." << std::endl;
    }
};

// Treatment Process
class TreatmentProcess {
public:
    void collectAnamnesis(const std::string& patientName) {
        std::cout << "Collecting anamnesis for " << patientName << std::endl;
    }

    void performTests(const std::string& patientName) {
        std::cout << "Performing tests for " << patientName << std::endl;
    }

    void diagnose(const std::string& patientName) {
        std::cout << "Diagnosing " << patientName << std::endl;
    }

    void treatPatient(const std::string& patientName) {
        std::cout << "Treating " << patientName << std::endl;
    }
};

// Main Program
int main() {
    AuthSystem auth;
    if (auth.authenticate("admin", "Administrator")) {
        Administrator admin;
        admin.addEmployee("John Doe");
        admin.generateReport();
        
        Ward ward(101, 2);
        ward.addPatient("Patient A");
        ward.addPatient("Patient B");
        ward.updateAvailability(false);
        ward.addPatient("Patient C"); // Should fail

        Inventory inventory;
        inventory.addItem("Bandages", 50);
        inventory.requestItem("Bandages", 20);
        inventory.requestItem("Bandages", 40); // Should fail

        TreatmentProcess treatment;
        treatment.collectAnamnesis("Patient A");
        treatment.performTests("Patient A");
        treatment.diagnose("Patient A");
        treatment.treatPatient("Patient A");
    }

    return 0;
}
