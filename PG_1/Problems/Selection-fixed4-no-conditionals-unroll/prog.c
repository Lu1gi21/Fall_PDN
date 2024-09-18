// Selection Sort
#include <stdio.h>
#include <stdlib.h>



// sorting algorythm, inspired by geeks for geeks
void selectionSort(float arr[], int n){
	float min, max;
	
    //unroll no condition

	int min_id = 0;
    // first pass
	typeof(arr[0]) a = (arr[0]);
	typeof(arr[1]) b = (arr[1]);

	min = !(a > b) * a + (a > b) * b ;
    max =  (a > b) * a + !(a > b) * b ;
	arr[0] = min;
	arr[1] = max;
	min = 0;
	max = 0;
	

	a = (arr[0]);
	b = (arr[2]);

	min = !(a > b) * a + (a > b) * b ;
    max =  (a > b) * a + !(a > b) * b ;
	arr[0] = min;
	arr[2] = max;
	min = 0;
	max = 0;

	a = (arr[0]);
	b = (arr[3]);

	min = !(a > b) * a + (a > b) * b ;
    max =  (a > b) * a + !(a > b) * b ;
	arr[0] = min;
	arr[3] = max;
	min = 0;
	max = 0;

	//second pass

	a = (arr[1]);
	b = (arr[2]);

	min = !(a > b) * a + (a > b) * b ;
    max =  (a > b) * a + !(a > b) * b ;
	arr[1] = min;
	arr[2] = max;
	min = 0;
	max = 0;
	
	a = (arr[1]);
	b = (arr[3]);

	min = !(a > b) * a + (a > b) * b ;
    max =  (a > b) * a + !(a > b) * b ;
	arr[1] = min;
	arr[3] = max;
	min = 0;
	max = 0;

	
	//third pass
	a = (arr[2]);
	b = (arr[3]);

	min = !(a > b) * a + (a > b) * b ;
    max =  (a > b) * a + !(a > b) * b ;
	arr[2] = min;
	arr[3] = max;
	min = 0;
	max = 0;
        

    
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