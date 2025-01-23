This folder contains:
   1- The "Age10" directory containing the '.arff' files used for age-group prediction when the interval [0,100] is split into (N=10) samples.
   2- The "BEST10" directory containing the '.arff' files used for fall risk prediction when the interval [0,100] is split into (N=10) samples.

These '.arff' files are obtained by using the program "Santos_and_Duarte/MakeArffs.c"  as follow:
____________________________________________________________________________________________   
   Compilation command line:

   gcc -Wall -o MakeArffs.exe MakeArffs.c
________________________________________________________________________________________________   
   Execution command line:

   MakeArffs.exe InfoFile VectorFile NbComponents
      1- 'InfoFile' is a file containing information (id, age-group and mini-BEST total score) about each subject in the dataset proposed in [2]. 
         The file "Santos_and_Duarte/BDSinfoSmallClean.csv" was used in [1] for this purpose.
      2- 'VectorFile' is the file containing the final vectors of all the subjects in the dataset proposed in [2].
	     The file named 'Vectors.txt' must be copied from any of the subdirectories "Santos_and_Duarte/Experiments/Time_Shift/Shift_$KAPPA$" for this purpose.
      3- 'NbComponents' is the number of components of each final vector.
________________________________________________________________________________________________   
   Example of execution: 
   
   MakeArffs.exe BDSinfoSmallClean.csv Vectors.txt 52
________________________________________________________________________________________________   

This program produces as output the files "Age.arff" and "BEST.arff" containing the corresponding final vectors.
These files must respectivelly be renamed "Age$N$_shift_$KAPPA$.arff"  and "BEST$N$_shift_$KAPPA$.arff" 
(as those saved in the subdirectories "Santos_and_Duarte/Experiments/Arffs/Age10/" and "Santos_and_Duarte/Experiments/Arffs/BEST10/" ),
where:
    1- N is the number of samples of the interval [0,100]. The value (N=10) was used in [1].
	2- KAPPA is the time-shift. The values (KAPPA = 1, 5, 10) were used in [1].
________________________________________________________________________________________________   

As explained in the Section 6.2 and the Table 10 of [2], we can merge the '.arff' files associated with various time-shifts to obtain 
a new arff file associated with the corresponding subset of time-shifts(e.g: {1,5}, {1,5,10}, ...).
The program "Santos_and_Duarte/MergeArffs.c" is used for merging two '.arff' files as follow:
____________________________________________________________________________________________   
   Compilation command line for "MergeArffs.c" file:

   gcc -Wall -o MergeArffs.exe MergeArffs.c
________________________________________________________________________________________________   
   Execution command line:

   MergeArffs.exe File1 File2 ResultFile
________________________________________________________________________________________________   
   Example of execution:  
   
   MergeArffs.exe Age10_shift_1.arff Age10_shift_5.arff Age10_shift_1_5.arff
   MergeArffs.exe BEST10_shift_1.arff BEST10_shift_5.arff BEST10_shift_1_5.arff
________________________________________________________________________________________________   

[1] Author names,
"HMM-based characterization of the human balance applied to age-group, fall risk and the Parkison’s disease prediction" 
(Under review).

[2] Santos, D.A., Duarte, M.
"A public data set of human balance evaluations."
PeerJ 4, 2648 (2016)