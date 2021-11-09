#include <iostream>
#include <cassert>

class TrainCar{
    int passengersMax = 0;
    int passengers = 0;
    class Train* train = nullptr;
public:
    void load(int value){
        assert(value >= 0);
        passengers += value;
        if(passengers > passengersMax) passengers = passengersMax;
    }
    int getPassengers(){
        return passengers;
    }
    TrainCar(class Train* inTrain, int inPassengersMax):passengersMax(inPassengersMax), train(inTrain){
        assert(inPassengersMax >= 0);
        assert(inTrain != nullptr);
    }
    int GetNumber();
};

class Train{
    int count = 0;
    TrainCar** cars = nullptr;
public:
    TrainCar* getCarAt(int index){
        assert(index < count);
        assert(index >= 0);
        if(this == nullptr) return nullptr;
        return this->cars[index];
    }
    int getCount(){
        return  this->count;
    }
    Train(int inCount, int inPassengersMax):count(inCount){
        assert(inCount >= 0);
        cars = new TrainCar*[inCount];
        for(int i = 0; i < count; ++i){
            cars[i] = new TrainCar(this, inPassengersMax);
        }
    }
};

int TrainCar::GetNumber() {
    for(int i =0; i < train->getCount(); ++i){
        if(train->getCarAt(i) == this) return i;
    }
    assert(false);
}

int main() {
    Train* train = new Train(5, 30);

    int passengers = 0;
    for(int i = 0; i < train->getCount(); ++i){
        std::cout << "Enter passengers quantity for train car #" << i+1 << ": ";
        std::cin >> passengers;
        train->getCarAt(i)->load(passengers);
    }
    for(int i =0; i < train->getCount(); ++i){
        std::cout << "Passengers quantity in train car #" << train->getCarAt(i)->GetNumber() << ": " << train->getCarAt(i)->getPassengers() << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    delete(train);
    return 0;
}
