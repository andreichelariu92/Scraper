#ifndef COLLECTION_H

#define COLLECTION_H
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

/**
 * \class Object
 * This is the parent class of all actual objects that will be scraped from the internet.
 * It's purpose is to isolate the collection from the actual type of objects used.
 */
class Object
{
  public:
    ///Identification Number
    int id;
    bool operator==(const Object& mem2);
    int getID()const;
    virtual int who()const;
    virtual ~Object();
};


class Stats;

/**
 * \class Collection
 * Represents an interface for future collections of objects.
 * Contains all the methods usefull for manipulating a collection.
 */
class Collection 
{

  public:
    ///Reads the collection from the file and constructs a vector of objects
    virtual void read(string fileName)=0;
    ///Writes the collection to the file,removing all precedent information
    virtual void write(string fileName)=0;
    ///Returns a copy of the vector
    virtual vector<Object*> getVector()const=0;
    ///It uses the sort algorithm from STL
    virtual void sortVector(bool (*pf)(const Object* a ,const Object* b))=0;
    ///Returns a vector of objects for witch function(Object) is TRUE
    virtual vector<Object*> filter(bool (*function)(const Object* obj))=0;
    ///Removes the selected object from the vector
    virtual void removeElement(const Object obj)=0;
    ///Returns a Stats object witch contains the minimum ,medium and average price
    virtual Stats statistics(vector<Object*> vect)=0;
    virtual ~Collection();

};


/**
 * \class Stats
 * Contains the Objects with the minimum and maximum price
 * It also contains the average prdasdce
 */
class Stats 
{
  public:
    Stats(const Object* min,const Object* max,double average);
    Object* getMin();
    Object* getMax();
    double getAverage();
    ~Stats();
  private:
    Object* min;
    Object* max;
    double average;
};
#endif /* end of include guard: COLLECTION_H */
