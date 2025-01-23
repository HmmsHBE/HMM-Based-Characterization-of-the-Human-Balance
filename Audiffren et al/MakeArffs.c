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

   MakeArffs.exe Faller NonFaller
________________________________________________________________________________________________   
   Example: 
   
   MakeArffs.exe Faller NonFaller
________________________________________________________________________________________________   
*/

int main(int NbArg, char ** MesArg) {
	FILE *f, *g, *h;
	char Faller_FileName[50], NonFaller_FileName[50];
	int i,NbAttributes;
	float vect[MaxComponents];
	char c, x[50];
	
	// Opening the Faller file
	strcpy(Faller_FileName,MesArg[1]);
	strcat(Faller_FileName,"_Vectors.txt");
	f = fopen(Faller_FileName, "rt");
	if(!f){
		printf("Error %s\n",Faller_FileName);
		return -1;
	} 
	
	// Opening the NonFaller file
	strcpy(NonFaller_FileName,MesArg[2]);
	strcat(NonFaller_FileName,"_Vectors.txt");
	g = fopen(NonFaller_FileName, "rt");
	if(!g){
		printf("Error %s\n",NonFaller_FileName);
		return -1;
	} 
	
	// Creating the relations and the classes
	h = fopen("Falls.arff", "wt");
	if(!h){
		printf("Error Falls.arff\n");
		return -1;
	} 
	fprintf(h,"@RELATION Falls\n");
	fprintf(h,"@ATTRIBUTE class {%s,%s}\n",MesArg[1],MesArg[2]);

	// Reading the first vector in the Faller file to get the number numeric attributes
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
	
	
	// Writing the first vector of the Faller file in the Arff file
	fprintf(h,"%s,",MesArg[1]);
	for(i = 0; i < NbAttributes; i++){
		if(i != NbAttributes - 1){
			fprintf(h,"%g,",vect[i]);
		}else{
			fprintf(h,"%g\n",vect[i]);
		}
	}

	// Writing the remaining vectors of the Faller file in the Arff file
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
	

	// Writing all the vectors of the NonFaller file in the Arff file
	do{
		//Copying the vector components
		fscanf(g,"[%i],",&i);
		if(!feof(g)){
			fprintf(h,"%s,",MesArg[2]);
			do{
				fread(&c,sizeof(char),1,g);
				fwrite(&c,sizeof(char),1,h);
			}while(c != '\n');
		}
	}while(!feof(g));

	// Closing all the files
	fclose(f);
	fclose(g);
	fclose(h);
	
	return 0;
}

