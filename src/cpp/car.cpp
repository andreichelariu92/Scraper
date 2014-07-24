#include "car.h"
#include <iostream>
int global_lower_price=0;
int global_upper_price=0;
std::string global_city=string("");
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
  id=source.id;
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
  id=source->id; 
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
vector< pair<string,string> > Car::getInformation()const
{
  vector< pair<string,string> > infoVector;
  char conversionString[250]={0};
  pair<string,string> pairId,pairName,pairPrice,pairFuel,pairKM,pairCity,pairYear;
  pair<string,string> pairLink;
  pairId.first=string("Id");
  sprintf(conversionString,"%d",id);pairId.second=string(conversionString);
  infoVector.push_back(pairId);
  pairName.first=string("name");pairName.second=name;
  infoVector.push_back(pairName);
  pairPrice.first=string("price");
  sprintf(conversionString,"%d",price);
  pairPrice.second=string(conversionString);infoVector.push_back(pairPrice);
  pairFuel.first=string("fuel");
  if(fuel==GAS)
    pairFuel.second=string("Gas");
  else
    pairFuel.second=string("Diesel");
  infoVector.push_back(pairFuel);
  pairKM.first=string("KM");
  sprintf(conversionString,"%d",km);
  pairKM.second=string(conversionString);  infoVector.push_back(pairKM);
  pairYear.first=string("year");
  sprintf(conversionString,"%d",year);
  pairYear.second=string(conversionString);  infoVector.push_back(pairYear);
  pairCity.first=string("city");pairCity.second=city;
  infoVector.push_back(pairCity);
  pairLink.first=string("link");pairLink.second=link;
  infoVector.push_back(pairLink);
  return infoVector;
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
void CarCollection::read(string fileName)throw(string)
{
  fstream file;
  file.open(fileName.c_str(),fstream::in);
  string separator;
  int id,price,fuel,km,year;
  string name,city,link;
  string emptyString=string("");
  while(1)
  {
    file>>separator;
    if(separator!=string("###"))
      throw (string("read error")); 
    file>>id;file.ignore();
    getline(file,name);
    file>>price;file.ignore();
    file>>fuel;file.ignore();
    file>>km;file.ignore();
    file>>year;file.ignore();
    getline(file,city);
    getline(file,link);
    if(name==emptyString || city==emptyString || link==emptyString)
      throw (string("read error"));
    v.push_back(new Car(id,name,price,fuel,km,year,city,link));
    if(file.peek()==EOF)
      break;
  }
  
}
void CarCollection::write(string fileName)throw(string)
{
  string separator("###");
  if(remove(fileName.c_str())!=0)
  {
  
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
CarCollection::~CarCollection()
{
  for(unsigned int i=0;i<v.size();i++)
    delete v[i];
  v.clear();
}
/**
 *Sorting functions for the car class
 */
bool SortPriceUp(const Object* a,const Object* b)
{
  Car* carP1=(Car*)a;
  Car* carP2=(Car*)b;
  if(carP1->getPrice()<carP2->getPrice())
    return 1;
  else 
    return 0;
}
bool SortPriceDown(const Object* a,const Object* b)
{
  Car* carP1=(Car*)a;
  Car* carP2=(Car*)b;
  if(carP1->getPrice()>carP2->getPrice())
    return 1;
  else 
    return 0;
}
bool SortKmUp(const Object* a,const Object* b)
{
  Car* carP1=(Car*)a;
  Car* carP2=(Car*)b;
  if(carP1->getKM()<carP2->getKM())
    return 1;
  else 
    return 0;
}
bool SortKmDown(const Object* a,const Object* b)
{
  Car* carP1=(Car*)a;
  Car* carP2=(Car*)b;
  if(carP1->getKM()>carP2->getKM())
    return 1;
  else 
    return 0;
}
bool SortYearUp(const Object* a,const Object* b)
{
  Car* carP1=(Car*)a;
  Car* carP2=(Car*)b;
  if(carP1->getYear()>carP2->getYear())
    return 1;
  else 
    return 0;
}
bool SortYearDown(const Object* a,const Object* b)
{
  Car* carP1=(Car*)a;
  Car* carP2=(Car*)b;
  if(carP1->getYear()<carP2->getYear())
    return 1;
  else 
    return 0;
}
/**
 *Filtering functions for car class
 */
bool FilterGas(const Object* obj)
{
  Car* carP=(Car*)obj;
  if(carP->getFuel()==GAS)
    return 1;
  else
    return 0;
}
bool FilterDiesel(const Object* obj)
{
  Car* carP=(Car*)obj;
  if(carP->getFuel()==DIESEL)
    return 1;
  else
    return 0;
}
bool FilterPriceAbove(const Object* obj)
{
  Car* carP=(Car*)obj;
  if(carP->getPrice()>global_lower_price)
    return 1;
  else
    return 0;
}
bool FilterPriceLow(const Object* obj)
{
  Car* carP=(Car*)obj;
  if(carP->getPrice()<global_upper_price)
    return 1;
  else
    return 0;
}
bool FilterCity(const Object* obj)
{
  Car* carP=(Car*)obj;
  if(carP->getCity()==global_city)
    return 1;
  else
    return 0;
}
