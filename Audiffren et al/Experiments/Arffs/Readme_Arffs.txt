This folder contains the '.arff' files used for classification in the software WEKA.

These '.arff' files are obtained by using the program "Audiffren et al/MakeArffs.c"  as follow:
____________________________________________________________________________________________   
   Compilation command line:

   gcc -Wall -o MakeArffs.exe MakeArffs.c
________________________________________________________________________________________________   
   Execution command line:

   MakeArffs.exe Faller NonFaller
      1- 'Faller' is the file containing the vectors of the Faller subjects in [1]. 
	    Although the program input file name is "Faller_Vectors.txt", just write "Faller", the progam will complete the rest of the name.
      2- 'NonFaller' is the file containing the vectors of the NonFaller subjects in [1].
	    Although the program input file name is "NonFaller_Vectors.txt", just write "NonFaller", the progam will complete the rest of the name.
________________________________________________________________________________________________   
   Execution command line: 
   
   MakeArffs.exe Faller NonFaller
________________________________________________________________________________________________   
The two input files of this program must be copied from any of the subdirectories "Audiffren et al/Experiments/Time_Shift/Shift_$KAPPA$".   
This program produces as output the file "Falls.arff" containing the final vectors of the fallers and the non fallers.
The file "Falls.arff" must be renamed "Falls$N$_shift_$KAPPA$.arff" (as those saved in the subdirectory "Audiffren et al/Experiments/Arffs/"),
where:
    1- N is the number of samples of the interval [0,100]. The value (N=10) was used in [1].
	2- KAPPA is the time-shift. The values (KAPPA = 1, 5, 10) were used in [1].
________________________________________________________________________________________________   

As explained in the Section 6.2 and the Table 10 of [2], we can merge the '.arff' files associated with various time-shifts to obtain 
a new arff file associated with the corresponding subset of time-shifts(e.g: {1,5}, {1,5,10}, ...).
The program "Audiffren et al/MergeArffs.c" is used for merging two '.arff' files as follow:
____________________________________________________________________________________________   
   Compilation command line for "MergeArffs.c" file:

   gcc -Wall -o MergeArffs.exe MergeArffs.c
________________________________________________________________________________________________   
   Execution command line:

   MergeArffs.exe File1 File2 ResultFile
________________________________________________________________________________________________   
   Example of execution:  
   
   MergeArffs.exe Falls10_shift_1.arff Falls10_shift_5.arff Falls10_shift_1_5.arff
________________________________________________________________________________________________   

[1] Mohammad Mourad, A., Tsagmo Denkeng, A.J.,Iloga, S., Romain, O., Baazaoui, H., Mballa Mba, R.M., Djotio, T.,
"HMM-based characterization of the human balance applied to age-group, fall risk and the Parkison’s disease prediction" 
(Under review).

