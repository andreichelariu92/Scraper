from bs4 import BeautifulSoup
import urllib
import re
import sys
from CarClass import Car
def get_cars(url,car_list,id):
  """function that parses the url using BeautifulSoup4
     With the information from the site we construct a list of car objects"""

  website=urllib.urlopen(url)
  soup=BeautifulSoup(website.read(),"html5lib")
  dict={"data-photo":re.compile(r"http")}
  for car in soup.find_all("article",class_="om-list-item"):
    name=car.find("a").string
    link="www.autovit.ro"+car.find("a")["href"]
    price=car.find("strong",class_="om-price-amount").string
    year=car.find("strong",text=re.compile(r"[0-9][0-9][0-9][0-9]")).string
    if(car.find("strong",title=re.compile(r"Putere"))!=None):
      fuel=car.find("strong",title=re.compile(r"Putere")).string
    else:
      fuel=""
    km=car.find("strong",text=re.compile(r"[0-9]* km")).string
    city=(car.find("a",attrs=dict)).find_next_sibling().string
    car_object=Car(id,name,link,price,year,fuel,km,city)
    if(car_object.good()):
      car_list.append(car_object)
      id=id+1
  return id

def num_pages(url):
  """determines the number of pages that need to be scraped"""
  page=0
  website=urllib.urlopen(url)
  soup=BeautifulSoup(website.read(),"html5lib")
  for page_number in soup.find_all("a",href=re.compile(r"\?p=[1-9]+")):
    if(page_number.span.string=="Inainte"):
      break
    elif(page<int(page_number.span.string)):
      page=int(page_number.span.string)
  return page


url="http://www.autovit.ro/autoturisme/?q=%s&p=%d&state=2"%(sys.argv[1],1)
pages=num_pages(url)
list=[]
index=1
id=1
while(index<=pages):
  url_2="http://www.autovit.ro/autoturisme/?q=%s&p=%d&state=2"%(sys.argv[1],index)
  id=get_cars(url_2,list,id)
  index=index+1

for car in list:
  with open("./cars.txt","a") as file:
    car.write(file)
  file.close()



