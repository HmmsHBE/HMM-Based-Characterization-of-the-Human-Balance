This folder contains the '.arff' files used for classification in the software WEKA.

These '.arff' files are obtained by using the program "Oliveira + Santos_and_Duarte/MakeArffs.c"  as follow:
____________________________________________________________________________________________   
   Compilation command line:

   gcc -Wall -o MakeArffs.exe MakeArffs.c
________________________________________________________________________________________________   
   Execution command line:

   MakeArffs.exe Positive Negative ListOfNegative
      1- 'Positive' is the file containing the resulting vectors of the subjects suffering from the Parkinson's disease in the dataset proposed in[2] after the method in [1] has been used. 
         Although the program input file name is "Positive_Vectors.txt", just write "Positive", the progam will complete the rest of the name.
      2- 'Negative' is the file containing the resulting vectors of all the subjects in the dataset proposed in [3] after the method in [1] has been used. 
         Although the program input file name is "Negative_Vectors.txt", just write "Negative", the progam will complete the rest of the name.
      3- 'ListOfNegative' is the file containing the ids of the subjects who declared no illness in the datased proposed in [3].
________________________________________________________________________________________________   
   Example of execution command line: 
   
   MakeArffs.exe Positive Negative No_illness.txt
________________________________________________________________________________________________   

The three input files of this program must be copied from any of the subdirectories "Oliveira + Santos_and_Duarte/Experiments/Time_Shift/Shift_$KAPPA$".   
This program produces as output the file "Parkinson.arff" containing the final vectors of all the subjects suffering from the Parkinson's disease in the dataset proposed in[2].
The file "Parkinson.arff" must be renamed "Parkinson$N$_shift_$KAPPA$.arff" (as those saved in the subdirectory "Oliveira + Santos_and_Duarte/Experiments/Arffs/"),
where:
    1- N is the number of samples of the interval [0,100]. The value (N=10) was used in [1].
	2- KAPPA is the time-shift. The values (KAPPA = 1, 5, 10) were used in [1].
________________________________________________________________________________________________   

[1] Author names,
"HMM-based characterization of the human balance applied to age-group, fall risk and the Parkison’s disease prediction" 
(Under review).

[2] Oliveira, C.E.N., Souza, C., Treza, R.d.C., Hondo, S.M., Los Angeles, E., Bernardo, C., Shida, T.K.F., Oliveira, L., Novaes, T.M., Campos, D.d.S.F., et al.
"A public data set with ground reaction forces of human balance in individuals with parkinson’s disease."
Frontiers in neuroscience 16, 865882 (2022)

[3] Santos, D.A., Duarte, M.
"A public data set of human balance evaluations."
PeerJ 4, 2648 (2016)