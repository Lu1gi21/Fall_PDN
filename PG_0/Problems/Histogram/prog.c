// histogram

#include <stdio.h>
#include <stdlib.h>

//gets max number
int getMax(int arr[]){
    int max =0;
    for(int i = 0; i < 26; i++){
        if( max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

//gets input and output
int main(int argc, char *argv[]){

    // checks if argument is complete
	if(argc < 3){
		printf("need more contents in command line");
		exit(0);
	}
	
	FILE *in_file = fopen(argv[1], "r");
	FILE *out_file = fopen(argv[2], "w");

	//makes an array to count the number of occurrenses of the letters
	int* alphabet = (int*) malloc(26 * sizeof(int));
    int ch;
    while((ch = getc(in_file))!= EOF){
        alphabet[ch - 'a'] += 1;
    }

    int max = getMax(alphabet);
    
    // builds the histogram
    for(int i = max; i > 0; i--){
         for(int j = 0; j < 26; j++){
            if(alphabet[j] == i){
                fprintf(out_file,"x");
                alphabet[j] -= 1;
            }
            else{
                fprintf(out_file," ");
            }
        }
        
        fprintf(out_file,"\n");
    }
    fprintf(out_file,"__________________________\nabcdefghijklmnopqrstuvwxyz");
    


   
    fclose(in_file);
    free(alphabet);
    fclose(out_file);
    


	



}