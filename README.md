# Graph Navigator over a generic type T

This is an example on how to use metaprogramming to create a graphs allowing to navigate over its generic type.

Specializations have been created for testing purposes.

The interesting thing of this library is regarding the generics. Each node can be whatever you want, from a document, a web site, a scenario of a text adventure, any type of data that is arranged on a graph. 

This library focus is development on graph navigation, regardless the type of objects contained on its nodes. 

## Download Project
There is a "walker" using Best First Search strategy to navigate testing graphs defined on main. 

Download the repository:

`$ git clone https://github.com/rcolomina/graph_navigator`

## Compiling the Source Code

After downloading, you need to compile the source code@ 

`$ makefile`

## Testing Sample Graphs
Now you can test the source code:

`$ ./main`

Testing graphs will be run over its notes showing its text content.

You can extend testing adding additional graphs. You can have a look to main to see how these are defined.

## Define New Graphs

