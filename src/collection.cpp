#include "collection.h"
Stats:: Stats(const Object* _min,const Object* _max,double _average)
{
  min=new Object(*_min);
  max=new Object(*_min);
  average=_average;
}
Object* Stats::getMin()
{
  return min;
}
Object* Stats::getMax()
{
  return max;
}
double Stats::getAverage()
{
  return average;
}
int Object::getID()const
{
  return id;
}
bool Object::operator==(const Object& mem2)
{
  if(id==mem2.getID())
    return 1;
  else 
    return 0;
}
int Object::who()const
{
  return 1;
}
Object::~Object()
{
}
Collection::~Collection()
{
}
Stats::~Stats()
{
  delete min;
  delete max;
}
