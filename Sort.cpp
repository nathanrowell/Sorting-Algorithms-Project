//
// Created by Leighanne on 11/2/2023.
//
// Nathan Rowell CISC220013

#include "Sort.hpp"
#include <iostream>
using namespace std;
Sort::Sort() {
	comparisons = 0;
	moves = 0;
}

void Sort::insertion_sort(int *array, int size) {
    for (int i = 0; i < size; i++) {
        int current = array[i];
        int j = i-1;
        while (j >= 0 and array[j] > current) {
            array[j+1] = array[j];
            j = j-1;
            moves += 1;
            comparisons += 1;

            }
        array[j+1] = current;

    }

}


void Sort::merge_sort(int *array, int size) {
    comparisons = 0;
    moves = 0;
    merge_sort(array,0,size-1);


}

void Sort::merge_insert_sort(int *array, int size) {
    comparisons = 0;
    moves = 0;
    int ending = 100;
    if (size <= ending) {
        insertion_sort(array, size);
    } else {
        int middle = size / 2;
        merge_insert_sort(array, middle);
        merge_insert_sort(array + middle, size - middle);
        merge(array, 0, middle - 1, size - 1);
    }
}

void Sort::merge_sort(int *array, int start, int end) {
    if (start < end) {
        int middle = start + (end-start) / 2;
        merge_sort(array,start,middle);
        merge_sort(array,middle+1,end);
        merge(array,start,middle,end);
    }



}

void Sort::merge(int *array, int start, int mid, int end) {
    // this is the final function used to merge the two sorted arrays
    int array1size = mid-start+1;
    int array2size = end-mid;
    int *array1 = new int[array1size];
    int *array2 = new int[array2size];
    for (int i = 0; i < array1size; i++) {
        array1[i] = array[start+i];
    }
    for (int i =0; i < array2size; i++) {
        array2[i] = array[mid+1+i];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while (i < array1size && j < array2size) {
        if (array1[i] <= array2[j]) {
            array[k] = array1[i];
            i++;
        }
        else {
            array[k] = array2[j];
            j++;
        }
        k++;
        comparisons++;
        moves++;

    }
    while (i < array1size) {
        array[k] = array1[i];
        i++;
        k++;
        moves++;
    }
    while (j <array2size) {
        array[k] = array2[j];
        j++;
        k++;
        moves++;
    }
    delete[] array1;
    delete[] array2;

}

int Sort::getComparisons() {
	return comparisons;
}

int Sort::getMoves() {
	return moves;
}

void Sort::swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}
