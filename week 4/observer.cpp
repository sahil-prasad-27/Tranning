#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Observer {
public:
    virtual void update(int temperature) = 0;
    virtual ~Observer() {}
};

class Subject {
public:
    virtual void attach(Observer* o) = 0;
    virtual void detach(Observer* o) = 0;
    virtual void notify() = 0;
    virtual ~Subject() {}
};


class WeatherStation : public Subject {
private:
    vector<Observer*> observers;
    int temperature;

public:
    void attach(Observer* o) override {
        observers.push_back(o);
    }

    void detach(Observer* o) override {
        observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notify() override {
        for (Observer* o : observers) {
            o->update(temperature);
        }
    }

    void setTemperature(int temp) {
        cout << "\nWeatherStation: Temperature changed to " << temp << "°C\n";
        temperature = temp;
        notify();
    }
};

class PhoneDisplay : public Observer {
public:
    void update(int temperature) override {
        cout << "Phone Display: Current temperature is " << temperature << "°C\n";
    }
};

class WindowDisplay : public Observer {
public:
    void update(int temperature) override {
        cout << "Window Display: Temperature updated to " << temperature << "°C\n";
    }
};

int main() {
    WeatherStation station;

    PhoneDisplay phone;
    WindowDisplay window;


    station.attach(&phone);
    station.attach(&window);

    station.setTemperature(25);
    station.setTemperature(30);

    
    station.detach(&phone);
    station.setTemperature(35);

    return 0;
}
