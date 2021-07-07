#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

// Class Vechicle
class Vehicle {
// Private Variables
private:
	string model, registrationNumber, color;
	int parkingCost;

// Public Functions
public:
	Vehicle() {}

	// Initialize a Vehicle with given params
	Vehicle(string registrationNumber, string model, string color) {
		this->registrationNumber = registrationNumber;
		this->model = model;
		this->color = color;
	}

	// Getters
	string getVehicleRegistrationNumber() {
		return this->registrationNumber;
	}

	string getVehicleModel() {
		return this->model;
	}

	string getVehicleColor() {
		return this->color;
	}

	// Setters
	void setParkingCost(int parkingCost) {
		this->parkingCost = parkingCost;
	}

	// Destroy Vehicle
	~Vehicle(){
		cout << "Vehicle Destroyed." << endl;
	}

};

// Class ParkingLot
class ParkingLot: public Vehicle {
// Private Variables
private:
	int totalSlots, freeSlots;
	int costPerSlot;
	priority_queue<int, vector<int>, greater<int> > slots; // Min Heap to allot nearest parking slot
	map<int, string> carAtSlot; // Map slot number with vehicle registration number
	map<string, int> allParkedCars; // Map registration number with slot number

public:
	ParkingLot(int totalSlots) {
		this->totalSlots = totalSlots;
		this->freeSlots = totalSlots;
		this->costPerSlot = 50;

		for (int t=0;t<totalSlots;++t) {
			slots.push(t+1);
		}
	}

	// Allot nearest Parking Slot
	int allotSlot(Vehicle *v) {
		if (this->slots.size() == 0) {
			cout << "No Slots free." << endl;
			return -1;
		}

		string vehicleRegistrationNumber = v->getVehicleRegistrationNumber();
		int allotedSlot = this->slots.top();

		if (this->allParkedCars[vehicleRegistrationNumber]) {
			cout << "Vehicle with Registration Number " << vehicleRegistrationNumber << " already parked." << endl;
			return -1;
		}

		cout << "Alloting Slot " << allotedSlot << " for vehicle with registration number " << vehicleRegistrationNumber << "." << endl;
		this->slots.pop();
		--this->freeSlots;

		this->carAtSlot[allotedSlot] = vehicleRegistrationNumber;
		this->allParkedCars[vehicleRegistrationNumber] = allotedSlot;

		return allotedSlot;
	}

	// Free a slot given, vehicle registration number
	int freeSlot(string vehicleRegistrationNumber) {
		int slot = allParkedCars[vehicleRegistrationNumber];
		if (!slot) {
			cout << "No Vehicle found with registration number " << vehicleRegistrationNumber << endl;
			return -1;
		}
		this->slots.push(slot);
		this->freeSlots++;

		cout << "Vehicle with Registration Number " << vehicleRegistrationNumber << " at slot " << slot << " exits." << endl;
		return slot;
	}

	// Show all free parking slots
	void showAvailableSlots() {
		auto xx = this->slots;
		while (!xx.empty()) {
			cout << xx.top() << " ";
			xx.pop();
		}
	}

	// Free all slots once Parking Lot's Destructor is called
	void freeAllSlots() {
		int totalSlots = this->totalSlots;
		this->freeSlots = totalSlots;
		this->allParkedCars.clear();
		this->carAtSlot.clear();
		for (int t=0;t<totalSlots;++t) {
			this->carAtSlot[t+1] = nullptr;
			this->slots.pop();
		}

		for (int t=0;t<totalSlots;++t) {
			this->slots.push(t+1);
		}
	}

	// Parking Lot Destructor
	~ParkingLot() {
		this->freeAllSlots();
		cout << "Parking Lot Destroyed." << endl;
	}
};

int main() {
	// Create Parking Lot and Vehicle Objects
	ParkingLot *p = new ParkingLot(4);
	Vehicle *v = new Vehicle("AP431", "i10", "Maroon");
	Vehicle *v1 = new Vehicle("AP423", "Eon", "White");

	// Alloting Slots
	p->allotSlot(v);
	p->allotSlot(v1);

	// Free Slots
	p->freeSlot(v->getVehicleRegistrationNumber());

	// Free Memory
	delete v;
	delete p;
}