# Graph Navigator over a generic type T

This is an example on how to use metaprogramming to create a graphs allowing to navigate over its generic type.

Specializations have been created for testing purposes.

The interesting thing of this library is regarding the generics. Each node can be whatever you want, from a document, a web site, a scenario of a text adventure, any type of data that is arranged on a graph. 

This library focus is development on graph navigation, regardless the type of objects contained on its nodes. 

## Download Project

Download the repository:

`$ git clone https://github.com/rcolomina/graph_navigator`

## Compiling the Source Code

After downloading, you need to compile the source code@ 

`$ makefile`

## Testing Sample Graphs
Now you can test the source code:

`$ ./main`

Testing graphs will run a strategy over its notes and showing text content of any node visited. There is implemented a "walker" which is using Best First Search (BFS) strategy to explore a graph. There are some testing graph defined in main. You can add easily additional graphs as it is done on main.

## Creating New Graphs
Not documented yet.
