/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file < stats.c > 
 * @brief < This file executes the statistical analysis on numarical data >
 *
 * The functions which are executing in this file are 
               > Maximum 
               > Minimum 
               > Mean  
               > Median 
   of the data set. In addition, It is going to reorder this data set from large to small. All
   statistics should be rounded down to the nearest integer.
 *
 * @author <D. Naga Siva Sai RaviKanth>
 * @date < 15/5/2020 >
 *
 */



#include <stdio.h>
#include "stats.h"



int MEAN(unsigned char *ptr, int size){
    int i;
    int total;
    if ( ptr == NULL ){
       return 0;
     }
     
     if ( size <= 0 ){
         size = 1;
      }
      
    for ( i = 0; i < size; i++ ){
         total += *ptr;
         ptr++;
     }
     
     return ( total/size );
 }
 
 
 int Round(float a){
     
    int i = a+1;
     
    
     
     if ( (a+0.5) >= ( i ) ){
         
         return a+1;
      }
     else{
     
         return a;
     }    
 }
 
 int MEDIAN(unsigned char *ptr , int size){
     
     int i;
     int i1;
     int k;
     int k1;
     
     if ( (size) % 2 == 0){
        
        i = size / 2;
        i1 = ( size + 1 ) / 2;
        ptr+=i;
        return ( ( *ptr + (*ptr++) ) / 2);
     }
     else {
        i = ( size+1 ) / 2 ;
        ptr+=i;
        return ( *ptr );
     }
  }
  
  
  
  
 int SORT( unsigned char a[] ,int n ){
       
       int i;
       int j;
       
       
       for (int i = 0; i < n; i++)                     //Loop for descending ordering
	{
		for (int j = 0; j < n; j++)             //Loop for comparing other values
		{
			if (a[j] < a[i])                //Comparing other array elements
			{
				int tmp = a[i];         //Using temporary variable for storing last value
				a[i] = a[j];            //replacing value
				a[j] = tmp;             //storing last value
			}
		}
	}
	printf(" Sorted Values :");
	
	for (int i = 0; i < n; i++)                     //Loop for printing array data after sorting
	{
		printf(" %d ", a[i]);                   //Printing data
	}

	
	
	return 0;          //returning 0 status to system
  }

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  
  int i = 0;
  int min;
  int max;
  float Mean;
  float Median;
  int Sort;
  
  
  /* Statistics and Printing Functions Go Here */
  
  while ( i < SIZE ) {
   if ( i == 0 ) {
      max = test[0];
      min = test[0];
   }
   if ( test[i] <= min) {
      min = test[i];
   }
   else if (test[i] >= max){
       max = test[i];
   }
   
   i++;
 }
   
   Mean = MEAN (test,SIZE) ;
   Sort = SORT (test,SIZE) ;
   Median = MEDIAN (test,SIZE) ;
   
   printf(" \nMean Value : %d",Round(Mean) );
   printf(" \nMedian Value : %d ", Round(Median) );
   printf(" \nMaximum Value : %d ", max );
   printf(" \nMaximum Value : %d\n ", min );

}

/* Add other Implementation File Code Here */


