// statistics

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// finds minimum number
float getMin(float arr[],int n){
    float t = arr[0];

    for(int i = 0; i < n; i++){
        if(t > arr[i]){
            t = arr[i];
        }
    }
    return t;

}
// finds max number
float getMax(float arr[],int n){
    float t = arr[0];

    for(int i = 0; i < n; i++){
        if(t < arr[i]){
            t = arr[i];
        }
    }
    return t;

}

// finds average of an array
float getAbv(float arr[], int n){
    float sum = 0;
    for(int i = 0; i <n; i++){
        sum = sum+ arr[i];
    }
    return sum/n;
}

// finds the standard deviation
float getStdv(float arr[], int n){
    float mean = getAbv(arr,n);
    float values = 0;
    for(int i = 0; i <n; i++){
        values += pow(arr[i]-mean,2);
    }

    float variance = values /n;
    float standardDeviation = sqrt(variance);
    return standardDeviation;

}



int main(int argc, char *argv[]){
    // checks if there are missing arguments
	if(argc < 3){
		printf("need more contents in command line");
		exit(0);
	}
	// opens files
	FILE *in_file = fopen(argv[1], "r");
	FILE *out_file = fopen(argv[2], "w");

	
	
	int size = getc(in_file) - '0';
	
	float* nums = (float*)malloc(size * sizeof(float));
    // fills array with contents of the file
	char text[100];
	fgets(text,100,in_file);
	for(int i = 0; i < size; i++){
		fgets(text,100,in_file);
		nums[i]= atof(text);
	}
	
	
	fclose(in_file);
    int n = size;
    float min, max, abv, sd;
    // makes the statistical equations
    min = getMin(nums,n);
    max = getMax(nums,n);
    abv = getAbv(nums,n);
    sd = getStdv(nums,n);

    // makes the outfile
	fprintf(out_file,"%i\n",size );
    fprintf(out_file,"Min:%f\n", min);
    fprintf(out_file,"Max:%f\n",max);
    fprintf(out_file,"Avg:%f\n",abv);
    fprintf(out_file,"Std:%f\n",sd);



	fclose(out_file);
	free(nums);
	
	return 0;



}