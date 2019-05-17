//main.cpp
// A main program used to run a sorting algorithm comparison program.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "Sort.h"

using namespace std;

// Main method for the entire program.
int main(int argc, char** argv)
{
  Sort m_sort;
  m_sort.Run(argv[1]);
  return 0;
}


//timing things: https://stackoverflow.com/questions/2808398/easily-measure-elapsed-time
//bubble sort: from notes
//insertion sort: section 3.1.2 in book
//selection sort: from notes
//Quick sort: https://www.geeksforgeeks.org/quick-sort/
