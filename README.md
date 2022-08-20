# Graph Navigator over a generic type T

This uses metaprogramming to naviage across a graphs regardless the type of objects contained on its nodes i.e. generic types .

Specializations have been created for testing purposes.

Interestingly, due to this library uses generics, each node can be whatever we want to be, from a document, a web site link, a scenario of a text adventure, or any other type of data that arranged on a graph. 

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
