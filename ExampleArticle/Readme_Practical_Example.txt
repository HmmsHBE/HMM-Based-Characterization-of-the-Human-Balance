This folder contains the codes and data used for the practical example in [1]. More specifically, it contains:
1- The directory "Results" containing the all the experimental results of this pratical example. 
   This directory contains the following items:
      a- The files "results_Kappa_1.txt" and "results_Kappa_3.txt"  containing the long MCs like those depicted in the Figures 7.a and 7.b of [1] 
         for (KAPPA = 1) and (KAPPA = 3) respectivelly. The number of samples, the max angle and the max distance of each statokinesigram are also displayed.
      b- The file "SubjectVectors.txt"  containing the final vector u_KAPPA as presented in the Table 9 of [1]. 
         Note: Given that the values presented in Tables 7, 8 and 9 of [1] has been truncated to two decimal places, 
         they may differ a bit from the values appearing in file the "SubjectVectors.txt".
      c- The directories "Firm_Kappa_1" and "Firm_Kappa_3"  containing the results of the execution of the method proposed in [1] 
         with (KAPPA = 1) and (KAPPA = 3).
2- The C codes(one '.c' file and two '.h' files) used to run the method proposed in [1].
3- The directory "Test"  containing the raw input statokinesigrams in the organized format. This directory is used 
  as input directory during the execution of the method proposed in [1]. All the results are thus saved in that same directory. 

To run the method proposed in [1] in order to obtain the results contained in the directory "ExampleArticle/Results/", 
the program "ExampleArticle/Stabilo.c" is compiled and executed as follow:
____________________________________________________________________________________________   
   Compilation command line:

   gcc -Wall -Wl,--stack,536870912 -o Stabilo.exe Stabilo.c
________________________________________________________________________________________________   
   Execution command line:

   Stabilo.exe DirectoryName FreqDiv TimeShift NbSamples MaxIterations Threshold SaveHMMs
   
    1- 'DirectoryName' is the name of a folder containing the input dataset in the organized format. 
	  The subdirectory "ExampleArticle/Test/" was used in [1] for this purpose.  
    2- 'FreqDiv' is the parameter SIGMA of down-sampling step explained in Section 4.2 of [1].
    3- 'TimeShift' is the desired time-shift.
    4- 'NbSamples' is the number N used in the Equation 3 of [1] to split the interval [0, 100].
    5- 'MaxIterations' is the maximum number of iterations for the Baum-Welch algorithm.
    6- 'Threshold' is the threshold belonging to [0, 100] and corresponding to the learning rate of the Baum-Welch algorithm.
    7- 'SaveHMMs' is a binary parameter such that (SaveHMMs=0) if we do not want to record the resulting HMMs in a textfile, 
	  otherwise (SaveHMMs=1).
________________________________________________________________________________________________   
   Command lines executed to obtain the results in [1]: 
   
   Stabilo.exe Test 1 1 10 100 100.0 1
   Stabilo.exe Test 1 3 10 100 100.0 1
________________________________________________________________________________________________   

[1] Author names,
"HMM-based characterization of the human balance applied to age-group, fall risk and the Parkison’s disease prediction" 
(Under review).