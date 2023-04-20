#include <iostream>
#include <vector>
#include <any>
#include <functional>
class Subject {
public:
    void addObserver(const std::any& observer) {
        observers.push_back(observer);
    }
    
    void notifyObservers(const std::any& data) {
        for (auto& observer : observers) {
            try {
                std::any_cast<std::function<void(std::any)>>(observer)(data);
            } catch (const std::bad_any_cast& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }

private:
    std::vector<std::any> observers;
};

class Observer {
public:
    explicit Observer(Subject& subject) {
        subject.addObserver(std::function<void(std::any)>([](std::any data) {
            try {
                // do something with data...
                std::cout << "Received data: " << std::any_cast<int>(data) << std::endl;
            } catch (const std::bad_any_cast& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }));
    }
};

int main() {
    Subject subject;
    Observer observer(subject);
    
    subject.notifyObservers(42);
    
    return 0;
}
