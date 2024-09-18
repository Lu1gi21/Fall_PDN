// Selection Sort
#include <stdio.h>
#include <stdlib.h>


// swaps two numbers
void swap(float* arr, int i, int j){
	float temp = arr[i];
	arr[i] = arr[j];
	arr[j]= temp;
}

// sorting algorythm, inspired by geeks for geeks
void selectionSort(float arr[], int n){
    
	float min = arr[0];
	int min_id = 0;

	// UNROLLED
	// 1
	if(min > arr[1]){
		min = arr[1];
		min_id = 1;
	}

	if(min > arr[2]){
		min = arr[2];
		min_id = 2;
	}

	if(min > arr[3]){
		min = arr[3];
		min_id = 3;
	}

	
	swap(arr,0,min_id);

	//2
	min = arr[1];
	min_id = 1;

	if(min > arr[2]){
		min = arr[2];
		min_id = 2;
	}

	if(min > arr[3]){
		min = arr[3];
		min_id = 3;
	}

	//3
	swap(arr,1,min_id);
	min = arr[2];
	min_id = 2;
	if(min > arr[3]){
		min = arr[3];
		min_id = 3;
	}

	swap(arr,2,min_id);

	

    
}


int main(int argc, char *argv[]){
	// checks if missing arguments
	if(argc < 3){
		printf("need more contents in command line");
		exit(0);
	}
	// opens files
	FILE *in_file = fopen(argv[1], "r");
	FILE *out_file = fopen(argv[2], "w");

	
	
	int size = 4;
	
	float* nums = (float*)malloc(size * sizeof(float));
	// fills the array whit the contents of the file
	char text[100];
	
	for(int i = 0; i < size; i++){
		fgets(text,100,in_file);
		nums[i]= atof(text);
	}
	
	
	fclose(in_file);

    int n = size ;
	// sorts the array
	selectionSort(nums,n);
	// makes the outfile

	for(int i = 0; i < size; i++){
		fprintf(out_file, "%.1f\n", nums[i]);
	}


	fclose(out_file);
	free(nums);
	
	return 0;



}