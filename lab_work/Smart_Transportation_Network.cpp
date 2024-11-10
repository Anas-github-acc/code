#include<iostream>

using namespace std;

// Implement appropriate constructors, methods, and use polymorphism to calculate the
// time for a vehicle to travel a given distance.

class Vehicle {
    private:
    string vehicleID;
    double maxSpeed;
    public:
    Vehicle(string id, double speed) {
        vehicleID = id;
        maxSpeed = speed;
    }
    string getVehicleID() {
        return vehicleID;
    }
    double calculateTime(double distance) {
        return distance / maxSpeed;
    }
    double getMaxSpeed() {
        return maxSpeed;
    }
};

class Car : public Vehicle {
    private:
    string fuelType;
    double fuelCost;
    public:
    Car(string id, double speed, string fuel, double cost) : Vehicle(id, speed) {
        fuelType = fuel;
        fuelCost = cost;
    }
    double calculateTime(double distance) {
        return distance / getMaxSpeed();
    }
    double calculateCost(double distance) {
        return distance * fuelCost;
    }
};

class Bus : public Vehicle {
    private:
    int passengerCapacity;
    public:
    Bus(string id, double speed, int capacity) : Vehicle(id, speed) {
        passengerCapacity = capacity;
    }
    double calculateTime(double distance) {
        return distance / getMaxSpeed();
    }
    int calculateTotalCapacity(int numBuses) {
        return passengerCapacity * numBuses;
    }
};

class Bicycle : public Vehicle {
    public:
    Bicycle(string id, double speed) : Vehicle(id, speed) {}
    bool isSuitable(double distance) {
        return distance <= 50;
    }0+
    double calculateTime(double distance) {
        return distance / getMaxSpeed();
    }
};


int main() {
    Vehicle v("V123", 100);
    cout << "Vehicle ID: " << v.getVehicleID() << endl;
    cout << "Time taken: " << v.calculateTime(100) << endl;
    Car c("C123", 80, "Petrol", 2.5);
    cout << "Vehicle ID: " << c.getVehicleID() << endl;
    cout << "Time taken: " << c.calculateTime(100) << endl;
    cout << "Cost of trip: " << c.calculateCost(100) << endl;
    Bus b("B123", 60, 50);
    cout << "Vehicle ID: " << b.getVehicleID() << endl;
    cout << "Time taken: " << b.calculateTime(100) << endl;
    cout << "Total passenger capacity: " << b.calculateTotalCapacity(2) << endl;
    Bicycle bi("BI123", 30);
    cout << "Vehicle ID: " << bi.getVehicleID() << endl;
    cout << "Time taken: " << bi.calculateTime(100) << endl;
    cout << "Is suitable: " << bi.isSuitable(100) << endl;
    return 0;
}