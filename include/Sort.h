// sort.h
// A declared sorting class used to sort an array of doubles.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Sort
{
  public:
    Sort(); //constructor
    ~Sort(); //destructor
    void Read(string fileName); //reads in an array of doubles
    void BubbleSort(double* myArray, int n); //bubble sort algorithm
    void InsertionSort(double* myArray, int n); //insertion sort algorithm
    void SelectionSort(double* myArray, int n); //selection sort algorithm
    void QuickSort(double* myArray, int low, int high); // quick sort algorithm
    void Out(); //outputs results for all sorting algorithms
    void Run(string fileName); //runs all functions together;
  private:
    //reading variables
    ifstream m_input_stream; //input stream for reading in file
    int m_array_size; //integer of array size; used to initiate the 4 arrays below
    double m_temp__double; //used to hold the double at each line that will fill the arrays
    double* m_bubble_array; //array for bubble sort
    double* m_insertion_array; //array for insertion sort
    double* m_selection_array; //array for selection sort (my choice of sorting)
    double* m_quick_array; //array for quick sort
    bool m_arrays_filled; //tells whether the arrays have been filled, which helps us with the destructor.
    //time variables
    clock_t m_bubble_start; //time of bubble sort start
    clock_t m_bubble_end; //time of bubble sort end
    double m_bubble_diff; //time duration of bubble sort
    clock_t m_insertion_start; //time of insertion sort start
    clock_t m_insertion_end; //time of insertion sort end
    double m_insertion_diff; //time duration of insertion sort
    clock_t m_selection_start; //time of selection sort start
    clock_t m_selection_end; //time of selection sort end
    double m_selection_diff; //time duration of selection sort
    clock_t m_quick_start; //time of quick sort start
    clock_t m_quick_end; //time of quick sort end
    double m_quick_diff; //time duration of quick sort
    //Helper Methods
    void swap(double* a, double* b); //utility swap function
    int partition(double* myArray, int low, int high); //utility partition function for quick sort
};
