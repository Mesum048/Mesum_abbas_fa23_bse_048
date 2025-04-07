#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to store patient information
struct Patient {
    string name;
    string condition;
    int emergencyLevel; // Lower value means higher priority
    int arrivalOrder;   // Helps break tie when emergency levels are the same
};

// Custom comparison for the priority queue
struct ComparePriority {
    bool operator()(Patient p1, Patient p2) {
        // If both patients have same emergency level, check arrival order
        if (p1.emergencyLevel == p2.emergencyLevel) {
            return p1.arrivalOrder > p2.arrivalOrder; // earlier = higher priority
        }
        return p1.emergencyLevel > p2.emergencyLevel; // lower number = higher priority
    }
};

// Function to print the current patient queue
void printQueue(priority_queue<Patient, vector<Patient>, ComparePriority> tempQueue) {
    cout << "\n--- Current Treatment Order ---\n";
    cout << left << setw(15) << "Name"
         << setw(25) << "Condition"
         << "Priority\n";
    cout << "----------------------------------------------\n";

    while (!tempQueue.empty()) {
        Patient p = tempQueue.top();
        tempQueue.pop();

        cout << left << setw(15) << p.name
             << setw(25) << p.condition
             << p.emergencyLevel << "\n";
    }

    cout << "----------------------------------------------\n";
}

int main() {
    // Priority queue to manage patients
    priority_queue<Patient, vector<Patient>, ComparePriority> patientQueue;

    // List of patients to add
    vector<Patient> patients;

    // Manually adding patients to the list
    patients.push_back({"Patient A", "Fever", 3, 1});
    patients.push_back({"Patient B", "Heart Attack", 1, 2});
    patients.push_back({"Patient C", "Broken Leg", 2, 3});
    patients.push_back({"Patient D", "Mild Cold", 4, 4});
    patients.push_back({"Patient E", "Severe Burn", 2, 5});
    patients.push_back({"Patient F", "Small Cut", 4, 6});
    patients.push_back({"Patient G", "Stroke", 1, 7});
    patients.push_back({"Patient H", "Food Poisoning", 3, 8});
    patients.push_back({"Patient I", "Fractured Arm", 2, 9});
    patients.push_back({"Patient J", "Migraine", 3, 10});

    // Add each patient to the queue and show current state
    for (int i = 0; i < patients.size(); i++) {
        cout << "\nAdding " << patients[i].name << " (" << patients[i].condition
             << ", Priority: " << patients[i].emergencyLevel << ") to the queue.\n";

        patientQueue.push(patients[i]);

        printQueue(patientQueue);
    }

    return 0;
}
