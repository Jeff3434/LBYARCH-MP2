# LBYARCH-MP2

1. The test cases used in this analysis are uploaded to the GitHub repository. These files are named 'input10.txt', 'input100.txt', and 'input1000.txt'. Respectively, they each contain 10x10, 100x100, and 1000x1000 pixel values. These values are randomly generated from a Python program.
2. To run this program, a Windows Batch file was created to run the necessary command line prompts to create the Executable File. The output will be displayed in an 'output.txt' text file. Each input file can be tested by changing the input file name from 'mp2.bat'.
3. The C program runs the program 50 times and calculates the average time using the function from SASM. Once run, the converted pixel values and the average execution time will be displayed.

Execution Time and Analysis
1. input10.txt - 10 x 10
The average time of the SASM function after 50 runs was 0.000000334 seconds. 

2. input100.txt - 100 x 100
Unlike the first test case, the average time was 0.000022216 seconds. Even though it's less than a second, the execution time was slower due to the higher number of conversions of pixel values.

3. input1000.txt - 1000 x 1000
The average time for this case was 0.001418104 seconds. This case is also less than a second, but the speed of the execution time is still far slower as the input size grows larger.

Program Output and Correctness Check
![image](https://github.com/user-attachments/assets/74c60584-8474-4d32-ab05-79ce3a4fb9f7)
![image](https://github.com/user-attachments/assets/5ef3aea2-1297-4193-b8a8-764dd6925e87)

After running the test case provided by AnimoSpace Canvas, it can be said that the program is calculating the grayscale images correctly. Although there are cases where the value is off by 1, it's usually because the converted double is rounded up. The output can easily be verified by simply multiplying the double by 255.
