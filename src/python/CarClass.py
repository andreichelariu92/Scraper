class Car:
  def __init__(self,_id,_name,_link,_price,_year,_fuel,_km,_city):
    self.id=_id
    
    self.name=_name
    if(not self.name):
      self.name=""
    self.name=self.name.strip()
   
    self.link=_link
    if(not self.link):
      self.link=""
    self.link=self.link.strip()
    
    self.price=_price
    if(not self.price):
      self.price=""
    self.price=self.price.replace(" ","")
    #self.price.strip("\n")
    
    self.year=_year
    if(not self.year):
      self.year=""
    
    self.fuel=_fuel
    if(not self.fuel):
      self.fuel=""
    self.fuel.strip("")
    if ("benzina" in self.fuel):
      self.fuel_id=1
    elif("diesel" in self.fuel):
      self.fuel_id=2
    else:
      self.fuel_id=0
    
    self.km=_km
    if(not self.km):
      self.km=""
    self.km=self.km.replace(" ","")
    self.km=self.km.replace("k","")
    self.km=self.km.replace("m","")
    
    self.city=_city
    if(not self.city):
      self.city=""
    self.city=self.city.upper()
    self.city=self.city.strip()


  def good(self):
    if(self.name=="" or self.link=="" or self.price=="" or self.year=="" or
        self.fuel=="" or self.km=="" or self.city=="" or self.price==0):
      return 0
    else:
      return 1


  def write(self,file):
    print >> file ,"###"
    print >> file ,self.id
    print >> file,self.name
    print >> file,self.price
    print >> file,self.fuel_id
    print >> file,self.km
    print >> file,self.year
    print >> file,self.city
    print >> file,self.link
  
