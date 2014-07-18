#include "car.h"
#include <iostream>
using namespace std;
Car::Car (int _id,string _name,int _price,int _fuel,int _km,int _year,string _city,string _link)
{
  id=_id;
  name=_name;
  price=_price;
  fuel=_fuel;
  km=_km;
  year=_year;
  city=_city;
  link=_link;
}
Car::Car(const Car& source)
{
  id=source.id;
  name=source.name;
  price=source.price;
  fuel=source.fuel;
  km=source.km;
  year=source.year;
  city=source.city;
  link=source.link;

}
Car& Car::operator=(const Car& source)
{
  name=source.name;
  price=source.price;
  fuel=source.fuel;
  km=source.km;
  year=source.year;
  city=source.city;
  link=source.link;
  return (*this);

}
Car::Car(const Object* obj)
{
  Car* source=(Car*) obj;
  name=source->name;
  price=source->price;
  fuel=source->fuel;
  km=source->km;
  year=source->year;
  city=source->city;
  link=source->link;

}
string Car::getName()const
{
  return name;
}
int Car::getPrice()const
{
  return price;
}
int Car::getFuel()const
{
  return fuel;
}
int Car::getKM()const
{
  return km;
}
int Car::getYear()const
{
  return year;
}
string Car::getCity()const
{
  return city;
}
string Car::getLink()const
{
  return link;
}
int Car::who()const
{
  return 17;
}
Car::~Car ()
{
}

/*
 * Implementation for the functions of CarCollection class
 */
CarCollection::CarCollection()
{
  vector<Object*> v;
}
CarCollection& CarCollection::operator=(const CarCollection& source)
{
  vector<Object*>::iterator it;
  cout<<"S-a apelat operatorul egal\n";
  for(it=source.getVector().begin();it!=source.getVector().end();it++)
    v.push_back(new Car(*it));
  return (*this);
}
void CarCollection::read(string fileName)
{
  fstream file;
  file.open(fileName.c_str(),fstream::in);
  string separator;
  int id,price,fuel,km,year;
  string name,city,link;
  while(1)
  {
    file>>separator;
    //TO DO VERIFY SEPARATOR
    file>>id;file.ignore();
    cout<<"Id read"<<id<<endl;
    getline(file,name);
    cout<<"Name read"<<name<<endl;
    file>>price;file.ignore();
    cout<<"Price read"<<price<<endl;
    file>>fuel;file.ignore();
    cout<<"Fuel read"<<fuel<<endl;
    file>>km;file.ignore();
    cout<<"KM read"<<km<<endl;
    file>>year;file.ignore();
    cout<<"Year read"<<year<<endl;
    getline(file,city);
    cout<<"City read"<<city<<endl;
    getline(file,link);
    cout<<"Link read"<<link<<endl;
    v.push_back(new Car(id,name,price,fuel,km,year,city,link));
    if(file.peek()==EOF)
      break;
  }
  
}
void CarCollection::write(string fileName)
{
  string separator("###");
  if(remove(fileName.c_str())!=0)
  {
    //TO DO VERIFY ERROR
  }
  else
  {
    fstream outFile;
    outFile.open(fileName.c_str(),fstream::out);
    vector<Object*>::iterator it;
    for(it=v.begin();it!=v.end();it++)
    {
      Car* car=(Car*)(*it);
      outFile<<separator<<endl;
      outFile<<car->getID()<<endl;
      outFile<<car->getName()<<endl;
      outFile<<car->getPrice()<<endl;
      outFile<<car->getFuel()<<endl;
      outFile<<car->getKM()<<endl;  
      outFile<<car->getYear()<<endl;
      outFile<<car->getCity()<<endl;
      outFile<<car->getLink()<<endl;

    }
    outFile.close();
  }
}
vector<Object*> CarCollection::getVector()const
{
  return v;
}
void CarCollection::sortVector(bool (*pf)(const Object* a,const Object* b))
{
  sort(v.begin(),v.end(),pf);
}
vector<Object*> CarCollection::filter(bool (*function)(const Object* obj))
{
  vector<Object*> resultVector;
  vector<Object*>::iterator it;
  for(it=v.begin();it!=v.end();it++)
  {
    if(function(*it)==1)
      resultVector.push_back(new Car(*it));
  }
  return resultVector;
}
void CarCollection::removeElement(Object obj)
{
  vector<Object*>::iterator it;
  for(it=v.begin();it!=v.end();it++)
  {
    if(obj==(**it) )
    {
      v.erase(it);
      break;
    }
  }
}
Stats CarCollection::statistics(vector<Object*> vect)
{
  
  if(vect.size()==0)
  {
    //TO DO
  }
  Car* min=new Car(vect.front());
  Car* max=new Car(vect.front());
  cout<<"We survived\n";
  double sum=0.0;
  double average=0.0;
  vector<Object*>::iterator it;
  for(it=vect.begin();it!=vect.end();it++)
  {
    Car* car=(Car*)(*it);
    if(car->getPrice()<min->getPrice())
    {
      delete min;
      min=new Car(*car);
    }
    if( car->getPrice()>max->getPrice())
    {
      delete max;
      max=new Car(*car);
    }
    sum=sum+car->getPrice();

  }
  average=sum/vect.size();
  Stats resultValue((Object*)min,(Object*)max,average);
  return resultValue;
}
CarCollection::~CarCollection()
{
  for(unsigned int i=0;i<v.size();i++)
    delete v[i];
  v.clear();
}



