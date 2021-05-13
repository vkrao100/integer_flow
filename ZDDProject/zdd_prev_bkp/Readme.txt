Running the Code:
The inbuilt functions from cudd package 2.5.0 is used in the code.
The source code is in grobner.c and the file cuddZddFuncs.c should also be placed in the folder containing the code.
1.This folder is to be placed in the /CUDD/cudd-2.5.0/.
2.To comiple the code the following code is to be used:

gcc grobner.c -o grobner -std=c99 -I ../include/ -L ../cudd/ -L ../util/ -L ../mtr/ -L ../st/ -L ../epd/ -L cuddZddFuncs.c -lcudd -lutil -lepd -lmtr -lst -lm

3.T view the graph:

dot -O -Tpdf filename.dot 


Contents of this folder:

This folder contains the source code(grobner.c),cuddZddFuncs.c,and the graphs of three cases shown in the report,singular file to calculate the time taken for the remainder in the third case.

We tried running the code for third case on linux machine and for some reason we are getting the time to be 0,but when we tried the code on visual studio on my computer we got it to be 0.001 sec.I am attaching the screen shot of it.

All the cases experimented are placed in comments.To test each case,uncomment the particular case and run the code.
