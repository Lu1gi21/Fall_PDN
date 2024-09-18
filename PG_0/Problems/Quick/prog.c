
// Quick Sort
#include <stdio.h>
#include <stdlib.h>

// swap the numbers
void swap(float* a, float*b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

int partition(float arr[], int low, int high){

    //get the pivot
    float pivot = arr[high];

    // smaller elements index
    int i = low-1;

    //traverse the array and swap if true
    for(int j = low; j <= high -1; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    //move pivot and return
    swap(&arr[i+1], &arr[high]);
    return i+1;

}

void quickSort(float arr[], int low, int high){
    if (low < high){
        int partition_index = partition(arr,low,high);

        //Recursive calls
        quickSort(arr,low,partition_index -1);
        quickSort(arr,partition_index +1, high);

    }

}

int main(int argc, char *argv[]){

	if(argc < 3){
		printf("need more contents in command line");
		exit(0);
	}
	
	FILE *in_file = fopen(argv[1], "r");
	FILE *out_file = fopen(argv[2], "w");

	
	
	int size = getc(in_file) - '0';
	
	float* nums = (float*)malloc(size * sizeof(float));

	char text[100];
	fgets(text,100,in_file);
	for(int i = 0; i < size; i++){
		fgets(text,100,in_file);
		nums[i]= atof(text);
	}
	
	
	fclose(in_file);
    int n = size ;
	quickSort(nums,0,n-1);

	fprintf(out_file,"%i\n",size );
	for(int i = 0; i < size; i++){
		fprintf(out_file, "%f\n", nums[i]);
	}


	fclose(out_file);
	free(nums);
	
	return 0;



}
