This folder contains the following items:
    1- The directory "Original" which contains the dataset of fallers and non fallers proposed in [1] in the original format.
       Each statokinesigram is saved in '.txt' file named "patient$x$$condition$Eyes.txt" where: 
          a- 'x' is the Id of the subject in his group.
	      b- 'condition' is either 'close' or 'open'. 
	   Each statokinesigram contains the following information:
          a- 'Faller': a Boolean which is true if the subject is a faller and false otherwise.
          b- 'Time': The recording time.
          c- 'X' and 'Y': The current coordinates of the Center Of Pressure of the subject.
    2- The directory "Organized" which contains the dataset of fallers and non fallers proposed in [1]  in an organized format.
	   The original data are grouped by balance condition (faller or non faller), subject Id and test condition. 
       For example, the subdirectory "Organized/Faller/1/Closed/" contains all the statokinesigrams recorded for the subject number 1 
	   who is a faller, in the test condition "Eyes Closed". Similarly, , the subdirectory "Organized/NonFaller/1/Open/" contains 
	   all the statokinesigrams recorded for the subject number 1, who is a non faller, in the test condition "Eyes Open".
________________________________________________________________________________________________   

[1] Audiffren, J., Bargiotas, I., Vayatis, N., Vidal, P.-P., Ricard, D.
"A non linear scoring approach for evaluating balance: classification of elderly as fallers and non-fallers."
Public Library of Science San Francisco, CA USA, Vol. 11(12), 2016.
