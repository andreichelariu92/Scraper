#include "collection.h"
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
vector< pair<string,string> > Object::getInformation()const
{
  vector< pair<string,string> >info;
  return info;
}
Object::~Object()
{
}
Collection::~Collection()
{
}

