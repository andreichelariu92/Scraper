#ifndef COLLECTION_H

#define COLLECTION_H
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
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
    ///Method that returns all the atributes of an object and their values in a vector of pairs(atr,value) 
    virtual vector< pair<string,string> > getInformation()const;
    virtual ~Object();
};



/**
 * \class Collection
 * Represents an interface for future collections of objects.
 * Contains all the methods usefull for manipulating a collection.
 */
class Collection 
{

  public:
    ///Reads the collection from the file and constructs a vector of objects
    virtual void read(string fileName)throw(string)=0;
    ///Writes the collection to the file,removing all precedent information
    virtual void write(string fileName)throw(string)=0;
    ///Returns a copy of the vector
    virtual vector<Object*> getVector()const=0;
    ///It uses the sort algorithm from STL
    virtual void sortVector(bool (*pf)(const Object* a ,const Object* b))=0;
    ///Returns a vector of objects for witch function(Object) is TRUE
    virtual vector<Object*> filter(bool (*function)(const Object* obj))=0;
    ///Removes the selected object from the vector
    virtual void removeElement(const Object obj)=0;
    virtual ~Collection();

};


#endif /* end of include guard: COLLECTION_H */
