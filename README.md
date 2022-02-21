# SantaProject

Create a project that allows Santa Claus to keep track of all children and all the toys they are supposed to receive on Christmas Eve.

Santa Claus distributes different toys to either good or bad children, depending on their number of good deeds.

All toys have the following characteristics:
- a name
- a dimension (the volume of the box the toy is in)
- a type (examples for a car: racing car, remote-control car, lego car)

There are 4 possibilities of toys Santa can provide, each having its own characteristics, along with the aforementioned ones:
- ***Classic Toys***
    - material
    - colour 
- ***Educative Toys***
    - ability they help develop (reading, comprehension, thinking etc)
- ***Electronic Toys***
    - number of batteries
- ***Modern Toys*** (have the characteristics of both educative and electronic toys)
    - number of batteries ( =1 )
    - ability they help develop ( ="general ")
    - brand 
    - model
    
For all the children in the system, Santa has the next set of data:

- an unique ID
    - automatically incremented
- name
- last name
- adress
- number of good deeds
- toys 
    - the number of which corresponds with the number of good deeds

The ***Good*** Children receive a number of sweets.
The ***Bad*** Children receive a number of coals.

For evey Good Child the number of good deeds has to be >= 10. Otherwise the value has to be reintroduced.

The tasks of this software are:

- To store, read and write n children (whether they are good or bad)
- For each child, read and write m toys (no matter the type of toy)
- Allow Santa to find a child by name and surname
- Allow Santa to order the children by age
- Allow Santa to order the children by the number of good deeds
- Allow Santa to increase the number of good deeds with a value x for a child (identified by ID) and adding X toys to said child
- Allow Santa to have an overview of the number of toys created and how many of each types there are.
