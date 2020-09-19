Before using Framework:  
Create a file with the contents of the "Unit Testing Framework.cpp" file in .h format.  
For example a file with this name - "test_runner.h"  
Then you need to add line '#include "test_runner.h"' to the top of your program.  

How to use Framework:  
1) First, at the very beginning of your program,  
   we we make an object "TestRunner tr".  
2) We make functions with tests inside.  
   Functions look like:  
     void TestSomething1() { ...}  
     void TestSomething2() { ...} etc.  
   Tests look like:  
     - ASSERT_EQUAL('what do you want to check'(expression1), 'what should it be equal to'(expression2)),  
       if you want to check your value with correct.  
     - ASSERT(your value that you got),  
       if you want to check that your value is true.  
3) At the very beginning of your program, we write:  
   RUN_TEST(tr, TestSomething1);  
   RUN_TEST(tr, TestSomething2); etc.  
That's all.  

Each time when you will run your program tests will be checked.  
If all will be OK, then in ostream for errors will be printed line "test_name OK" as many tests as there were,  
otherwise in ostream for errors will be printed:   
First lines that look like:  
"name_test_function fail: Assertion failed: your_value != excp_value hint: 'value got from expression1' != 'value got from expression1', name_file:line_number"  
 how many tests were failed.  
Last line:  
count_of_failed_test << " unit tests failed. Terminate  
AfteAfter that, your program will be completed.   
To execute it completely, you need to correct the error so that the Framework does not find errors.  

Examle:  
 Let us have a function:  
 int Sqrt(int x) {...}  
Using Framework:  
/  
10 void TestSqrt(){  
11      ASSERT_EQUAL(Sqrt(4), 2);  
12	    ASSERT_EQUAL(Sqrt(9), 3);  
13 }   
14 int main(){  
15     TestRunner tr;  
16	   RUN_TEST(tr, TestSqrt);  
17 }  
/  
if Sqrt(4) return 1, then will be printed:    
"TestSqrt fail: Assertion failed: 1 != 2 hint: Sqrt(4) != 2, ..\src\file.cpp:11  
1 unit tests failed. Terminate"  
if Sqrt(4) return 2 and Sqrt(9) return 2, then will be printed:  
"TestSqrt fail: Assertion failed: 2 != 3 hint: Sqrt(9) != 3, ..\src\1.cpp:12  
1 unit tests failed. Terminate"  
if Sqrt(4) return 2 and Sqrt(9) return 3, then will be printed:  
"TestSqrt OK"  
If we would like to test Sqrt on other tests, we must add them.  
