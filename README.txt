-------
SUMMARY
-------
The program is a demonstration of Naive Bayes algorithm for classification mining.
The implementation also handles zero probabilities using M-Estimation.
The program is also capable of handling large data sets high dimension. 
Logarithm on probability is used to achive high prescision.

---------------
BUILD & EXECUTE
---------------
The program has been developed in C.
The code development linux environment running CentOS Linux release 7.2.1511.
gcc version 4.8.5 was used to compile.
To compile the source code, run the make command.
It will produce the executable Digger using the targets mentioned in the makefile.
After compiling the application can be executed by runnning the below, 
$./Digger

--------------
INPUT & OUTPUT
--------------
Interactive command line inputs are required.
The program takes three mandatory inputs and one optional input,
	File Name -	Name of the file containing the data for mining. 
			The input can also be prefixed by path if the file is in a different location than that of execution.
			The columns are space separated.
			First line should be column header.
	Target -	The attribute or column to be classified.
			The list of attributes is displayed in a numbered list, out of which one has to be chosen by entering the number.
	Test File -	Name of the file containing the test data set.
			The input can also be prefixed by path if the file is in a different location than that of execution.
			The columns are space separated.
			First line should be column header.
			The data format should be same as that of the training data set.

Training & testing output is printed in the screen along with the performance statistics.
The outputs are also stored in files name Rules and Test respectively.

Train Sample input:
Enter the input file name:data1
Please choose an attribute (by number):
        1. outlook
        2. temperature
        3. Humidity
        4. Windy
        5. PlayTennis
Target:5
Enter the test file name:data2

-----------
PERFORMANCE
-----------
The execution time for the application is measured accross three different tasks loading input, finding probability and prediction.
Given below is the statistics for the training using data1 and testing it againts data2.

Loading Time Taken:4.319 ms
Training Time Taken:0.032 ms
Testing Time Taken:3.571 ms

The statistics shows that execution time is fairly faster with a all tasks completing in lot less than 10 milli second.

-----------
ASSUMPTIONS
-----------
Field should not have space in between.
Should not have missing values.
Dataset should not have replicated rows.
Test dataset should follow the same structure as that of training dataset.

------------------------------
PREPROCESSING & NOISE HANDLING
------------------------------
Continous attributes should be converted to nominal or categorical values.
Records with missing values should be removed.
Duplicate records should be removed.

---------------
MODULES & TASKS
---------------
The code contain the below files,
	digger.h - Structure, Global variable and Function declaration.
	digger.c - main() program.
	load.c - Reads data from input and forms the training dataset.
	count.c - Counts the occurences of the targets and items to find the probability.
	predict.c - Reads test data set and classifies using the probability identified..
	
Given below the flow of control between modules,

DIGGER:main()
  |
  |
LOAD-->load()			#file name & target input
  |      |
  |	 |
  |    load_headers()		#read first line from file. gathers info such as number of columns and column names.
  |      |
  |	 |
  |    load_records()		#read all records. gather info such as number records.
  |
  |
COUNT-->count()			#counts the occurences of the targets and items to find the probability.
  |
  |
  |
TEST-->predict()		#read test dataset. based on the probability values find classification.
  |	  			#print predicted output. calculate accuracy.
  |
  |	
RELEASE-->free_mem()		#free all the dynamic allocated memory.

----------
EVALUATION
----------
[1]"UCI Machine Learning Repository: Lenses Data Set", Archive.ics.uci.edu, 2017. [Online]. Available: http://archive.ics.uci.edu/ml/datasets/Lenses. [Accessed: 28- Mar- 2017]

The data set is contains atributes to classify the type of contact lens to used.
The original dataset had used numberic values to represent category, which has 
been replaced with nominal values obtained from the metadata provided.
The data set conatins 24 records which is split into two sets one with 17 records
for training and another with 7 records for testing. Delimeter ',' is used in the
files for Weka(C4.5) and space is used for developed ID3 & NB solutions.
The dataset is provided in the file Bonus_Data.csv. The training and test files 
along with outputs are available under the Bonus_Exec directory.

---------------------
CLASSIFICATION RESULT
---------------------
		|NB				|C4.5					|ID3
-----------------------------------------------------------------------------------------------------------------------------
Key Concept	|Probable Class			|Probable Model				|Probable Model
Basic Entity	|Prior probability		|Entropy & Information gain		|Entropy & Information gain ratio
Noise		|Ignores Noise			|Needs to be fixed in pre-processing	|Needs to be fixed in pre-processing
Visual Rep	|Not Applicable			|Tree					|Tree
Pruning		|Not applicable			|Not possible				|Can be achived

------------------
PERFORMANCE RESULT
------------------
		|NB				|C4.5					|ID3
-----------------------------------------------------------------------------------------------------------------------------
Accuracy	|5/7				|6/7					|5/7
Time Taken	|16 ms				|50 ms					|12 ms
General Speed	|Average			|Average				|Low
Observation	|Average			|Low					|Average
Comments	|Expected performance		|Lower due to PC process power		|Better due to fewer items

-------------------
OBSERVATION SUMMARY
-------------------
ID3 & C4.5 takes a wholistic approach on the dataset, while NB works as one step at time.
This property of ID3 & C4.5 makes it mandatory for prediction to run through the dataset
for the exhaustic list of items & targets. In NB, all target information is gathered 
but it is enough to gather information only on the specified items available in test set.
This makes NB the most suitable option for huge datasets, when topic of testing is gauged.
In case of uncertain topic of interest, it is ideal to use ID3 or C4.5 which is fastest
of the three in providing complete picture. Pruning in C4.5 also support this cause making
it the best out of three when classification topics are very broad.
In short it can be claimed that C4.5 stands as the best algorithm when there is no focused
classification involved, while NB gives the highest performance even with huge datasets 
when topics of focus are determined.

