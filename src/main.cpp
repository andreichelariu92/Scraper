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
}
int main(int argc, const char *argv[])
{
  Collection* cars=new CarCollection();
  string fileName("./cars.txt");
  cout<<"Se incepe citirea\n";
  cars->read(fileName);
  cout<<"Citirea s-a facut cu succes\n";
  vector<Object*> carVector=cars->getVector();
  vector<Object*>::iterator it;
  for(it=carVector.begin();it!=carVector.end();it++)
    cout<<(*it)->who();
  cars->sortVector(comparare);
  cars->write("./cars.txt");
  vector<Object*>resultVector=cars->filter(priceFilter);
  cout<<endl<<resultVector.size();
  delete cars;
  return 0;
}
