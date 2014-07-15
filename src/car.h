#ifndef CAR_H

#define CAR_H

#include "collection.h"

/**
 *\class Car
 *It is derived from class Object
 *Contains information relevant to a car
 */
class Car:public Object
{
  public:
    Car (string _name,int _price,int _fuel,int _km,int _year,string _city);
    Car& operator=(const Car& source);
    string getName();
    int getPrice();
    int getFuel();
    int getKM();
    int getYear();
    string getCity();
    ~Car ();
  private:
    string name;
    int price;
    int fuel;
    int km;
    int year;
    string city;
};

#endif /* end of include guard: CAR_H */
