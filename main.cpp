#include <iostream>
#include <cassert>

class TrainCar{
    int passengersMax = 0;
    int passengers = 0;
public:
    void load(int value){
        assert(value >= 0);
        passengers += value;
        if(passengers > passengersMax) passengers = passengersMax;
    }
    int getPassengers(){
        return passengers;
    }
    TrainCar(int inPassengersMax):passengersMax(inPassengersMax){
        assert(inPassengersMax >= 0);
    }
};

class Train{
    int count = 0;
    TrainCar** cars = nullptr;
public:
    TrainCar* getCarAt(int index){
        assert(index >= 0);
        return cars[index];
    }
    int getCount(){
        return  count;
    }
    Train(int inCount, int inPassengersMax):count(inCount){
        assert(inCount >= 0);
        cars = new TrainCar*[inCount];
        for(int i = 0; i < count; ++i){
            cars[i] = new TrainCar(inPassengersMax);
        }
    }
};
int main() {
    Train* train = new Train(5, 30);
    int passengers = 0;
    for(int i = 0; i < train->getCount(); ++i){
        std::cout << "Enter passengers quantity for train car #" << i+1 << ": ";
        std::cin >> passengers;
        train->getCarAt(i)->load(passengers);
    }
    for(int i =0; i < train->getCount(); ++i){
        std::cout << "Passengers quantity in train car #" << i+1 << ": " << train->getCarAt(i)->getPassengers() << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
