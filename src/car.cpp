#include "car.h"
Car::Car (string _name,int _price,int _fuel,int _km,int _year,string _city)
{
  name=_name;
  price=_price;
  fuel=_fuel;
  km=_km;
  year=_year;
  city=_city;
}
Car& Car::operator=(const Car& source)
{
  name=source.name;
  price=source.price;
  fuel=source.fuel;
  km=source.km;
  year=source.year;
  city=source.city;

}
int Car::getPrice()
{
  return price;
}
int Car::getFuel()
{
  return fuel;
}
int Car::getKM()
{
  return km;
}
int Car::getYear()
{
  return year;
}
string Car::getCity()
{
  return city;
}
Car::~Car ()
{
}

