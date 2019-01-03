# Optimized-Traffic-Camera-Placement
The project is tohelp the local police department with their installation of security cameras at traffic intersections.We will solve a particular kind of optimization problem, called the Vertex Cover problem, in this context.The  idea  is  for  the  police  to  be  able  to  minimize  the  number  of  cameras  they  need  to install, and still be as effective as possible with their monitoring.
The Repository consists of three parts:
#1. Project- Containing the C++,Python Executables of the Project subdivided into various assignments
   a) a1-ece650.py,operations.py (Assignment1)
      This is the  first in a series of assignments that is part of a single large project.For this assignment, we need to:
      Take as input a series of commands that describe streets.
      Use that input to construct a particular kind of undirected graph.
      Write the code in Python (Version 2.7.x).
      Sample Input:
      The  input  comprises  lines  each  of  which  speci es  a  command.   There  are  4  kinds  of  commands (1) add a street,  (2)         change a street,  (3) remove a street,  and,  (4) generate a graph.  Here is an example of how your program should work.                 Visualizing this example using the Cartesian coordinate system may help you understand what's going on.
      a "Weber Street" (2,-1) (2,2) (5,5) (5,6) (3,8)
      a "King Street S" (4,2) (4,8)
      a "Davenport Road" (1,4) (5,8)
      g
      V = {1:  (2,2)
      2:  (4,2)
      3:  (4,4)
      4:  (5,5)
      5:  (1,4)
      6:  (4,7)
      7:  (5,6)
      8:  (5,8)
      9:  (3,8)
      10: (4,8)}
      E = {<1,3>,<2,3>,<3,4>,1
      <3,6>,<7,6>,<6,5>,<9,6>,<6,8>,<6,10>}
      c "Weber Street" (2,1) (2,2)
      g
      V = {2:  (4,2)
      5:  (1,4)
      6:  (4,7)
      8:  (5,8)
      10: (4,8)}
      E = {<2,6>,<6,5>,<6,8>,<6,10>}
      r "King Street S"
      g
      V = {}
      E = {}
      
      Commands
      a is used to add a street.  It is specified as: a "Street Name" (x1,y1) (x2,y2). . .(xn,yn)". Each(xi,yi) is a GPS coordinate.          We interpret the coordinates as a poly-line segment. That is, we draw a line segment from (xi,yi) to (xi+1,yi+1).You are allowed        to assume that each xi and yi is an integer.  (Note,  however,  that the coordinates of an intersection may not be integers.)
      c is used to change the specification of a street. Its format is the same as for a. It is a new specification for a street you've        specified before.
      r is used to remove a street.  It is speci ed as r "Street Name"".
      g causes the program to output the corresponding graph.
  b) a2-ece     
