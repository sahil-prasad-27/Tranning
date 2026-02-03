#include <iostream>
using namespace std;

class Transport {
public:
    virtual void deliver() = 0;
    virtual ~Transport() {}
};

class Truck : public Transport {
public:
    void deliver() override {
        cout << "Delivering goods by road using a Truck." << endl;
    }
};

class Ship : public Transport {
public:
    void deliver() override {
        cout << "Delivering goods by sea using a Ship." << endl;
    }
};


class Logistics {
public:
    // Factory Method
    virtual Transport* createTransport() = 0;

    // Business logic that uses the product
    void planDelivery() {
        Transport* transport = createTransport();
        transport->deliver();
        delete transport;
    }

    virtual ~Logistics() {}
};

class RoadLogistics : public Logistics {
public:
    Transport* createTransport() override {
        return new Truck();
    }
};

class SeaLogistics : public Logistics {
public:
    Transport* createTransport() override {
        return new Ship();
    }
};

int main() {
    Logistics* logistics;

    logistics = new RoadLogistics();
    logistics->planDelivery();
    delete logistics;

    logistics = new SeaLogistics();
    logistics->planDelivery();
    delete logistics;

    return 0;
}
