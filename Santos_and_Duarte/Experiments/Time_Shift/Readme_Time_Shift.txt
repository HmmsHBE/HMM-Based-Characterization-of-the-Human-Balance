This folder contains the results of different executions of the method proposed in [1] with various time-shifts(1, 5 and 10) 
It contains the subdirectories "Shift_$KAPPA$", with KAPPA = 1, 5 and 10. Each subdirectory has the following items:
   1- The subdirectory "Organized_Processed" which contains the dataset proposed in [2] in an organized format 
     alongside with the corresponding experimental results.
   2- The file "SubjectVectors.txt" containing the final vectors of all the subjects in the dataset proposed in [2] after the method described in [1] 
     has been applied on it with the corresponding time-shift. This file is obtained using the program "Santos_and_Duarte/Stabilo.c" as described below.  
	 and each line starts with the subjects' Id in squared bracked, followed by the vector components. 
	 The lines of this file are sorted in increasing ALPHABETIC order of the subjects' Ids.
   3- The file "Vectors.txt" which is a copy of the file "SubjectVectors.txt" where each line starts with the subjects' Id WITHOUT squared bracked,
	 and the lines of this file are sorted in increasing NUMERIC order of the subjects' Ids.
 
The program "Santos_and_Duarte/Stabilo.c" is compiled and executed as follow:
___________________________________________________________________________________________   
   Compilation command line:

   gcc -Wall -Wl,--stack,536870912 -o Stabilo.exe Stabilo.c
________________________________________________________________________________________________   
   Execution command line:

   Stabilo.exe DirectoryName FreqDiv TimeShift NbSamples MaxIterations Threshold SaveHMMs
   
    1- 'DirectoryName' is the name of a folder containing the input dataset in the organized format. 
	  The subdirectory "Santos_and_Duarte/The_Dataset/Organized" was used in [1] for this purpose.
	  You must paste a copy of that subdirectory in the folder "Santos_and_Duarte/" before running the program.
    2- 'FreqDiv' is the parameter SIGMA of down-sampling step explained in Section 4.2 of [1].
    3- 'TimeShift' is the desired time-shift.
    4- 'NbSamples' is the number N used in the Equation 3 of [1] to split the interval [0, 100].
    5- 'MaxIterations' is the maximum number of iterations for the Baum-Welch algorithm.
    6- 'Threshold' is the threshold belonging to [0, 100] and corresponding to the learning rate of the Baum-Welch algorithm.
    7- 'SaveHMMs' is a binary parameter such that (SaveHMMs=0) if we do not want to record the resulting HMMs in a textfile, 
	  otherwise (SaveHMMs=1).
________________________________________________________________________________________________   
   Example of execution: 
   
   Stabilo.exe StatoDirectory 5 1 10 100 100.0 1
________________________________________________________________________________________________   

The execution of the previous program produces several files and directories:
1- It produces under each test condition of each subject (e.g: "Organized/1/Firm/Closed") of the "Organized" directory, a subdirectory named "Results".
   a- The subdirectory "Results" contains the files : "MCs.txt", "AllVectors.txt" and "MeanVector.txt".
   b- "MCs.txt" contains the Markov chains produced by the method proposed in [1] (Section 4.2.1).
      These Markov chains are represented as ORDERED sequences of pairs (e,s) such that each pair (e,s) 
      materializes the fact that the symbol (s) is observed from the state (e). These Markov chains are generated 
      following the method explained at the Sections 4.2.1 and 4.2.2 of [1]. Two consecutive pairs (e,s)(x,y) mean that 
	  there is a state transition from the state e to the state x.
   c- "AllVectors.txt" contains the vectors derived from the HMMs as explained in the Section 4.2.4 of [1]. 
       A vector is derived for each file representing a statokinesigram.
   d- "MeanVector.txt" contains the mean vector of the vectors in "AllVectors.txt" as explained in the Section 4.2.5 and the Equation 10 of [1].
2- A file named "SubjectVectors.txt" whose containt is already described at the beginning of the current file.
3- If the parameter 'SaveHMMs' is 1, it produces a subdirectory containing the initial and final HMMs.
________________________________________________________________________________________________   

[1] Mohammad Mourad, A., Tsagmo Denkeng, A.J.,Iloga, S., Romain, O., Baazaoui, H., Mballa Mba, R.M., Djotio, T.,
"HMM-based characterization of the human balance applied to age-group, fall risk and the Parkison’s disease prediction" 
(Under review).

[2] Santos, D.A., Duarte, M.
"A public data set of human balance evaluations."
PeerJ 4, 2648 (2016)