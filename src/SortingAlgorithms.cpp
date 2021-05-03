#include <cassert>
#include <iostream>

void BubbleSortByArshacid(int, int*);
void SelectionSortByArshacid(int, int*);
void InsertionSortByArshacid(int, int*);
void HeapSortByArshacid(int, int*);
void ShellSortByArshacid(int, int*);
void QuickSortByArshacid(int, int*);
void MergeSortByArshacid(int, int*);


namespace 
{	
	void Swap(int& a, int& b) {
		int tmp = a;
		a = b;
		b = tmp;
	}	
}

void BubbleSortByArshacid(int size, int* array) {
	bool is_sorted = true;

	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				is_sorted = false;
				Swap(array[j],array[j + 1]);
			}
		}

		if (is_sorted) {
			return;
		}
	}
}

void SelectionSortByArshacid(int size, int* array) {
	for (int i = 0; i < size - 1; ++i) {
		int min_index = i;
		for (int j = i + 1; j < size; ++j) {
			if (array[j] < array[min_index]) {
				min_index = j;
			}
		}

		//if it is not the same element
        if (i != min_index) {
            // Swap the found min element with the first element
		    Swap(array[min_index],array[i]);
	    }
    }
}

void InsertionSortByArshacid(int size, int* array) {
	for (int i = 1; i < size; ++i) {
		int tmp = array[i], j = i - 1;

		while (j >= 0 && array[j] > tmp) {
			array[j + 1] = array[j];
			--j;
		}

		array[j + 1] = tmp;
	}
}

namespace 
{
	int Partitioning(int* array, int start, int end) {
		int pivot = end; 	 
		int pindex = start;  // index for partitioning

		for (int i = start; i < end; ++i) {
			if (array[i] < array[pivot]) {
				Swap(array[pindex], array[i]);
				++pindex;
			}
		}

		Swap(array[pindex],array[pivot]);

		return pindex;
	}

    void QuickSortHelper(int* array, int start, int end) {
    	if (start >= end) {
	    	return;
	    }

	    int pivot = Partitioning(array, start, end); 

    	QuickSortHelper(array, start, pivot - 1);
	    QuickSortHelper(array, pivot + 1, end);
    }
}

void QuickSortByArshacid(int size, int* array) {   
    QuickSortHelper(array, 0, size - 1);
}

namespace
{	
	void Merge(int* array, int start, int middle, int end) {
		int i = start; 			 // initial index of first subarray
		int j = middle + 1;		 // initial index of second subarray
		int l = end - start + 1; // size of temp array

		int* tmp = new int[l];

		for (int k = 0; k < l; ++k) {
			if ((i <= middle && array[i] < array[j]) || j > end) {
				tmp[k] = array[i];
				++i;
			} else {
				tmp[k] = array[j];
				++j;
			}
		}

		for (int k = 0, p = start; k < l; ++k, ++p) {
			array[p] = tmp[k];
		}
		delete[] tmp;
    }
    
    void MergeSortHelper(int* array, int start, int end) {
	    if (start >= end) {
		    return;
	    }

	    int middle = (start + end) / 2;

	    MergeSortHelper(array, start, middle);
	    MergeSortHelper(array, middle + 1, end);
	    Merge(array, start, middle, end);
    }
}

void MergeSortByArshacid(int size, int* array) {
    MergeSortHelper(array, 0, size - 1);
}

namespace 
{
	void Heapify(int* array, int size, int root) {
    	int max = root;
    	int right = (2 * root) + 1;
    	int left = (2 * root) + 2;

    	if (left < size && array[left] > array[max]) {
    	    max = left;
    	}
    
    	if (right < size && array[right] > array[max]) {
    	    max = right;
    	}

    	if (max != root) {
    	    Swap(array[root], array[max]);
    	    Heapify(array, size, max);              
    	}
	}
}

void HeapSortByArshacid(int size, int* array) {
    for (int i = (size / 2) - 1; i >= 0; --i) {
        Heapify(array, size, i);        
    }

    for (int i = size - 1; i >= 0; --i) {
        Swap(array[i], array[0]);
        Heapify(array, i, 0);
    }
}

void ShellSortByArshacid(int size, int* array) {
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; ++i ) {
			for (int j = i - gap; j >= 0; j -= gap) {
				if (array[j + gap] >= array[j]) {
					break;
				} else {
					Swap(array[j + gap], array[j]);
				}			
			}
		}	
	}
}

