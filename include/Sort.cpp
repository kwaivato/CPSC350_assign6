// sort.h
// An implemented sorting class used to sort an array of doubles.
// @author Vidal M. Arroyo
// @author arroy118@mail.chapman.edu
// @version 1.0

#include "Sort.h"

using namespace std;

//Constructor
Sort::Sort()
{
  m_array_size = 0;
  m_temp__double = 0.0;
  m_arrays_filled = false;
  m_bubble_start = 0.0;
  m_bubble_end = 0.0;
  m_bubble_diff = 0.0;
  m_insertion_start = 0.0;
  m_insertion_end = 0.0;
  m_insertion_diff = 0.0;
  m_selection_start = 0.0;
  m_selection_end = 0.0;
  m_selection_diff = 0.0;
  m_quick_start = 0.0;
  m_quick_end = 0.0;
  m_quick_diff = 0.0;
}

//Destructor
Sort::~Sort()
{
  //Only destroys the arrays if they have been filled
  if (m_arrays_filled)
  {
    delete[] m_bubble_array;
    delete[] m_insertion_array;
    delete[] m_selection_array;
    delete[] m_quick_array;
  }
}

void Sort::Read(string fileName)
{
  m_input_stream.open(fileName);
  //Checks if file even exists
  if(m_input_stream.fail())
  {
    cout << "File does not exist! Please run again with a valid file." << endl;
  }
  else
  {
    //First line is the array_size
    m_input_stream >> m_array_size;
    //Use the array_size to allocate sizes for arrays
    m_bubble_array = new double[m_array_size];
    m_insertion_array = new double[m_array_size];
    m_selection_array = new double[m_array_size];
    m_quick_array = new double[m_array_size];
    //add the elements to each of the arrays
    for (int i = 0; i < m_array_size; ++i)
    {
      m_input_stream >> m_temp__double;
      m_bubble_array[i] = m_temp__double;
      m_insertion_array[i] = m_temp__double;
      m_selection_array[i] = m_temp__double;
      m_quick_array[i] = m_temp__double;
    }
    //Now we set the bool to be true so that we can destroy these arrays later.
    m_arrays_filled = true;
  }
  m_input_stream.close();
}

void Sort::BubbleSort(double* myArray, int n)
{
  //Iterate through all variables
  for (int i = 0; i < n-1; ++i)
  {
    //Look through all variables
    for (int j = 0; j < n-1; ++j)
    {
      //If a value is greater, swap it and put it up front
      //This leads to the ith highest value 'bubbling' to the top in the ith iteration
      if(myArray[j] > myArray[i+1])
      {
        swap(&myArray[j],&myArray[i+1]);
      }
    }
  }
}

void Sort::InsertionSort(double* myArray, int n)
{
  //Iterate through all the values starting at the second
  for (int i = 1; i < n; ++i)
  {
    //This is our current variable
    double cur = myArray[i];
    //We make the valye we're comparing it to just the index right below
    int j = i - 1;
    //J must be 0 so its valid; also, must be greater than our current variable
    while((j >= 0) && (myArray[j] > cur))
    {
      //if it is greater we move it back
      myArray[j+1] = myArray[j];
      j--;
    }
    //We now set the variable ahead (or right on the spot) to the current.
    myArray[j+1] = cur;
  }
}

void Sort::SelectionSort(double* myArray, int n)
{
  //We start by iterating through all the bottom indices except the top
  for (int i = 0; i < n-1; ++i)
  {
    //This is our current minimum
    int minimum_index = i;
    //We will now iterate through all the values above
    for (int j = i + 1; j < n; ++j)
    {
      //If the values above are smaller, they become our new minimum
      if (myArray[j] < myArray[minimum_index])
      {
        minimum_index = j;
      }
      //We will now swap the ith position with our minimum.
      swap(&myArray[minimum_index],&myArray[i]);
    }
  }
}

//The quick sort method uses the partition helper function to accomplish its task. We will be fed the lowest and highest indices of the array
void Sort::QuickSort(double* myArray, int low, int high)
{
  //As long as the algorithm is used right, low will always be lower than high; but this is just a safety net
  if (low < high)
  {
    //We will recursively sort the array by using the partition function
    int pi = partition(myArray, low, high);
    //Quick sorting the left side of the pivot
    QuickSort(myArray,low,pi-1);
    //Quick sorting the right side of the pivot
    QuickSort(myArray,pi+1,high);
  }
}

void Sort::Out()
{
  //Bubble Sort Output
  cout << "Bubble Sort Results" << endl;
  m_bubble_diff = double(m_bubble_end-m_bubble_start)/CLOCKS_PER_SEC;
  cout << "   Start Clock Time: " << m_bubble_start << endl;
  cout << "   End Clock Time: " << m_bubble_end << endl;
  cout << "   Actual Lapsed Time: " << m_bubble_diff << endl;

  //Insertion Sort Output
  cout << "Insertion Sort Results" << endl;
  m_insertion_diff = double(m_insertion_end-m_insertion_start)/CLOCKS_PER_SEC;
  cout << "   Start Clock Time: " << m_insertion_start << endl;
  cout << "   End Clock Time: " << m_insertion_end << endl;
  cout << "   Actual Lapsed Time: " << m_insertion_diff << endl;

  //Selection Sort Output
  cout << "Selection Sort Results" << endl;
  m_selection_diff = double(m_selection_end-m_selection_start)/CLOCKS_PER_SEC;
  cout << "   Start Clock Time: " << m_selection_start << endl;
  cout << "   End Clock Time: " << m_selection_end << endl;
  cout << "   Actual Lapsed Time: " << m_selection_diff << endl;

  //Quick Sort Output
  cout << "Quick Sort Results" << endl;
  m_quick_diff = double(m_quick_end-m_quick_start)/CLOCKS_PER_SEC;
  cout << "   Start Clock Time: " << m_quick_start << endl;
  cout << "   End Clock Time: " << m_quick_end << endl;
  cout << "   Actual Lapsed Time: " << m_quick_diff << endl;
}

//make it throw a non-type error (see assign5)
void Sort::Run(string fileName)
{
  //First I read in the file
  Read(fileName);

  //Now I time the algorithms
  //Timing bubble sort
  m_bubble_start = clock();
  BubbleSort(m_bubble_array, m_array_size);
  m_bubble_end = clock();
  //Timing insertion sort
  m_insertion_start = clock();
  InsertionSort(m_insertion_array, m_array_size);
  m_insertion_end = clock();
  //Timing selection sort
  m_selection_start = clock();
  SelectionSort(m_selection_array, m_array_size);
  m_selection_end = clock();
  //Timing quick sort
  m_quick_start = clock();
  QuickSort(m_quick_array,0,m_array_size-1);
  m_quick_end = clock();
  //Output all the results
  Out();
}

//Swapping helper function
void Sort::swap(double* a, double* b)
{
  //This function swapts a pair of values; I use it extensively in all the algorithms
  double temp = *a;
  *a = *b;
  *b = temp;
}

//This is the helper function that will help us partition values for quick sort
int Sort::partition(double* myArray, int low, int high)
{
  //The pivot for quick sort is generally chosen as the highest value
  double pivot = myArray[high];
  //This will be the lowest value
  int i = (low - 1);
  //We will look through the array, from low, to high, and swap values that are out of place based on the pivot
  for (int j = low; j < high; ++j)
  {
    //We keep swapping these values as long as we need to to sort the array
    if (myArray[j] <= pivot)
    {
      i++;
      swap(&myArray[i], &myArray[j]);
    }
  }
  //We will finally swap the pivot into its correct place
  swap(&myArray[i+1], &myArray[high]);
  //We will be returning the index of the pivot
  return (i+1);
}
