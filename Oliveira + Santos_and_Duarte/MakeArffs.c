#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MaxComponents 500

/*
____________________________________________________________________________________________   
   Compilation command line:

   gcc -Wall -o MakeArffs.exe MakeArffs.c
________________________________________________________________________________________________   
   Execution command line:

   MakeArffs.exe Positive Negative ListOfNegative
________________________________________________________________________________________________   
   Example: 
   
   MakeArffs.exe Positive Negative No_illness.txt
________________________________________________________________________________________________   
*/

int main(int NbArg, char ** MesArg) {
	FILE *f, *g, *h, *w;
	char Positive_FileName[50], Negative_FileName[50];
	int i,j,NbAttributes;
	double vect[MaxComponents];
	char c, x[50];
	
	// Opening the Positive file
	strcpy(Positive_FileName,MesArg[1]);
	strcat(Positive_FileName,"_Vectors.txt");
	f = fopen(Positive_FileName, "rt");
	if(!f){
		printf("Error %s\n",Positive_FileName);
		return -1;
	} 
	
	// Opening the Negative file
	strcpy(Negative_FileName,MesArg[2]);
	strcat(Negative_FileName,"_Vectors.txt");
	g = fopen(Negative_FileName, "rt");
	if(!g){
		printf("Error %s\n",Negative_FileName);
		return -1;
	} 
	
	
	// Opening the ListOfNegative file
	w = fopen(MesArg[3], "rt");
	if(!w){
		printf("Error %s\n",MesArg[3]);
		return -1;
	} 
	
	// Creating the relations and the classes
	h = fopen("Parkinson.arff", "wt");
	if(!h){
		printf("Error Parkinson.arff\n");
		return -1;
	} 
	fprintf(h,"@RELATION Parkinson\n");
	fprintf(h,"@ATTRIBUTE class {%s,%s}\n",MesArg[1],MesArg[2]);

	// Reading the first vector in the Positive file to get the number numeric attributes
	fscanf(f,"[%i]",&i);
	NbAttributes = 0;
	fread(&c,sizeof(char),1,f);
	do{
		if(c != '\n'){
			i = 0;
			do{
				fread(&c,sizeof(char),1,f);
				if((c != '\n')&&(c != ',')){
					x[i++] = c;
				}
			}while((c != '\n')&&(c != ','));
			if(i > 0){
				x[i] = 0;
				vect[NbAttributes++] = atof(x);
			}
		}
	}while(c != '\n');
	
	// Writing the attributes identifiers
	for(i = 1; i <= NbAttributes; i++){
		fprintf(h,"@ATTRIBUTE x%i NUMERIC\n",i);
	}
	
	// Data start here
	fprintf(h,"@DATA\n");
	
	
	// Writing the first vector of the Positive file in the Arff file
	fprintf(h,"%s,",MesArg[1]);
	for(i = 0; i < NbAttributes; i++){
		if(i != NbAttributes - 1){
			fprintf(h,"%lf,",vect[i]);
		}else{
			fprintf(h,"%lf\n",vect[i]);
		}
	}

	// Writing the remaining vectors of the Positive file in the Arff file
	do{
		//Copying the vector components
		fscanf(f,"[%i],",&i);
		if(!feof(f)){
			fprintf(h,"%s,",MesArg[1]);
			do{
				fread(&c,sizeof(char),1,f);
				fwrite(&c,sizeof(char),1,h);
			}while(c != '\n');
		}
	}while(!feof(f));
	

	// Writing the vectors of the Negative file whose identifier appear in ListOfNegative in the Arff file
	fscanf(w,"%i\n",&j);
	do{
		//Copying the vector components
		fscanf(g,"%i,",&i);
		if(!feof(g)){
			if(i == j){
				fprintf(h,"%s,",MesArg[2]);
			}
			do{
				fread(&c,sizeof(char),1,g);
				if(i == j){
					fwrite(&c,sizeof(char),1,h);
				}
			}while(c != '\n');
			if(i == j){
				fscanf(w,"%i\n",&j);
			}
		}
	}while(!feof(g));

	// Closing all the files
	fclose(f);
	fclose(g);
	fclose(h);
	fclose(w);
	
	return 0;
}

