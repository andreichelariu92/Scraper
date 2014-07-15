#include "collection.h"
Stats:: Stats(const Object& _min,const Object& _max,int _average)
{
  min=_min;
  max=_max;
  average=_average;
}
Object Stats::getMin()
{
  return min;
}
Object Stats::getMax()
{
  return max;
}
int Stats::getAverage()
{
  return average;
}
