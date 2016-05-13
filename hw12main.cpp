//=======================================================================================
// Class       : CS 3304 - Data Structures with Dr. Gayler
// Author      : Nathaniel Klein
// Assignment  : Assignment 12, Project 13, p.682: Shell Sort
// File Name   : hw12main.cpp
// Date        : 04/27/16
//=======================================================================================

#include <iostream>
#include <cmath>

using namespace std;

void print_list(int mylist[], int size);
void shell_sort(int (&mylist)[8], int size);
void swap(int lower, int higher, int (&mylist)[8]);

int main(int argc, char **argv)
{
	int data [8] = {2,13,8,-5,7,22,16,1};
	int size = 8;
	print_list(data, size);

	shell_sort(data, size);
	print_list(data, size);

	return 0;
}

void print_list(int mylist[], int size){

	for(int i = 0; i < size; ++i)
		cout << mylist[i] << " ";
	cout << "\n" << endl;
}

void shell_sort(int (&mylist)[8], int size){

    int j = 0;
    int ss = size/2;
    
	while(ss > 0){

		for(int i = 0; i < size-ss; ++i){

			if(mylist[i+ss] < mylist[i]){
				swap(i+ss, i, mylist);

				// use j below based on i
				j = i;

				// while loop keeps j-ss from running off front of list
				while(j-ss >= 0){
					if(mylist[j] < mylist[j-ss]){
						swap(j, j-ss, mylist);
						j = j-ss;
					}
					// no swap needed, so break
					else
						break;
				}
			}
		}
		ss = round(ss/2.2);
	}
}

void swap(int lower, int higher, int (&mylist)[8]){

    int temp = mylist[lower];
	mylist[lower] = mylist[higher];
	mylist[higher] = temp;
}
