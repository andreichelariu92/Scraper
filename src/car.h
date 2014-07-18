#ifndef CAR_H

#define CAR_H

#include "collection.h"
#include <fstream>
#include <algorithm>
#include <stdio.h>
/**
 *\class Car
 *It is derived from class Object
 *Contains information relevant to a car
 */
class Car:public Object
{
  public:
    Car (int _id,string _name,int _price,int _fuel,int _km,int _year,string _city,string _link);
    Car(const Object* obj);
    Car(const Car& source);
    Car& operator=(const Car& source);
    int getFuel()const;
    string getName()const;
    int getPrice()const;
    int getKM()const;
    int getYear()const;
    string getLink()const;
    string getCity()const;
    int who()const;
    ~Car ();
  private:
    string name;
    int price;
    int fuel;
    int km;
    int year;
    string city;
    string link;
};


/**
 *\class CarCollection
 *Implements the collection interface for the Car object
 */
class CarCollection:public Collection 
{
  public:
    CarCollection();
    CarCollection& operator=(const CarCollection& source);
    void read(string fileName);
    void write(string fileName);
    vector<Object*> getVector()const;
    void sortVector(bool (*pf)(const Object* a,const Object* b));
    vector<Object*> filter(bool (*function)(const Object* obj));
    void removeElement(Object obj);
    Stats statistics(vector<Object*> vect);
    ~CarCollection();

  private:
    vector<Object*> v;
};

#endif /* end of include guard: CAR_H */
