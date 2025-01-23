This folder contains:
    1- The directory "Original" which contains the dataset proposed in [1] in the original format.
       Each statokinesigram is saved in '.txt' file named "BDS$NUMBER$.txt" where NUMBER is the number of the statokinesigram in the dataset.
	   Each statokinesigram contains the following information:
          a- 'Time[s]': the recording time.
          b- 'Fx[N]', 'Fy[N]' and 'Fz[N]': The forces applied by the subject on the force platform.
		  c- 'Mx[N.m]', 'My[N.m]' and 'Mz[N.m]': The moments of these forces.
          d- 'COPx[cm]' and 'COPy[cm]': The current coordinates of the Center Of Pressure of the subject.
    2- The directory "Organized" which contains the dataset proposed in [1] in an organized format.
	   The original data are grouped by subject Id, surface and test condition. 
       For example, the subdirectory "Organized/1/Firm/Closed/" contains all the statokinesigrams recorded for the subject number 1 
	   on a firm surface, in the test condition "Eyes Closed". Similarly, , the subdirectory "Organized/Foam/1/Open/" contains 
	   all the statokinesigrams recorded for the subject number 1, on a foam surface, in the test condition "Eyes Open".
    3- The files 'OrganizeDataset.c' and 'FilesList.csv' used to put the original dataset in the organized format as follow:   
________________________________________________________________________________________________   
    Compilation command line:

    gcc -Wall -Wl,--stack,536870912 -o OrganizeDataset.exe OrganizeDataset.c
________________________________________________________________________________________________   
    Execution command line:

    OrganizeDataset.exe FilesList OrganizedDirectory OriginalDirectory

     - 'FilesList' is a file containing the list of all the statokinesigram file names appearing in the dataset, 
	   each statokinesigram been attached with its corresponding subject id, surface and eye condition.
	   The file 'FilesList.csv' is used here for this purpose, do not delete this file.
	 - 'OrganizedDirectory' is the name of the organized directory produced as output. 
	   This directory is created by the program, do not create it yourself.
	 - 'OriginalDirectory' is the name of the directory containing the original dataset.
________________________________________________________________________________________________   
    Example of execution: 
            
    OrganizeDataset.exe FilesList.csv Organized Original
________________________________________________________________________________________________   

[1] Santos, D.A., Duarte, M.
"A public data set of human balance evaluations." 
PeerJ 4, 2648 (2016)