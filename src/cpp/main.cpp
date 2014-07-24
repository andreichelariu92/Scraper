#include "collection.h"
#include "car.h"
#include <iostream>
bool comparare(const Object* ob1,const Object* ob2)
{
  Car* car1=(Car*) ob1;
  Car* car2=(Car*) ob2;
  if(car1->getPrice()<car2->getPrice())
    return 1;
  else
    return 0;
}
bool priceFilter(const Object* obj)
{
  Car* car=(Car*) obj;
  if(car->getPrice()<20000)
    return 1;
  else
    return 0;
}
int main(int argc, const char *argv[])
{
  Collection* cars=new CarCollection();
  string fileName("../python/cars.txt");
  cout<<"Se incepe citirea\n";
  try
  {
    cars->read(fileName);
  }catch(string s)
  {
    cout<<s<<endl;
    cout<<"The program will close";
    return -1;
  }
  cout<<"Citirea s-a facut cu succes\n";
  vector<Object*> carVector=cars->getVector();
  vector<Object*>::iterator it;
  for(it=carVector.begin();it!=carVector.end();it++)
  {
    vector< pair<string,string> > infoVector=(*it)->getInformation();
    vector<pair<string,string> >::iterator it2;
    for(it2=infoVector.begin();it2!=infoVector.end();it2++)
    {
      cout<<(*it2).first<<" "<<(*it2).second<<endl;
    }
  }
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  vector<Object*> filterVector;
  extern string global_city;  
  global_city=string("BOTOSANI");
  filterVector=cars->filter(FilterCity);
  for(it=filterVector.begin();it!=filterVector.end();it++)
  {
    vector< pair<string,string> > infoVector=(*it)->getInformation();
    vector<pair<string,string> >::iterator it2;
    for(it2=infoVector.begin();it2!=infoVector.end();it2++)
    {
      cout<<(*it2).first<<" "<<(*it2).second<<endl;
    }
  }

  delete cars;
  return 0;
}
