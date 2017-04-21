Project 01 - README
===================

Members
-------

- Philip Baumann (pbaumann@nd.edu)
- Michael Wang (mwang6@nd.edu)

Responses
---------
1. This program, unlike others, parses the command line arguments via 
streq. This function compares two strings and returns whether they match. 
If they do, then the settings struct variables are manipulated to fit what 
the user inputs. This is accomplished through multiple if/else statements. 

2. To walk the directory tree, we mimicked the programs we've created in 
class. If the directory can be opened via opendir, the program then uses 
readdir to iterate over the contents of the folder to check if it is a file or a directory. If it is a directory, then search is called recurisvely on this directory. 

3. The program uses several different checks to determine whether or not 
to print a filesystem objects path. First, the program checks if the file 
passes the filter specified by the user. If this passes the filter via the 
filter.c program, the objects path will be printed if the '-print' 
argument was used or any expression was used. This way, the only 
filesystem object paths that will be printed are the objects with criteria 
that meet the settings specified by the user and when print is specified 
according to the directions. 

Script Questions
----------------

1.

2.



Contributions
-------------
Philip Baumann
	created utilities
	jointly created search, filter, main, and exec
	wrote README

Michael Wang
	created Makefile
	jointly created search, filter, main, and exec
	finished syscalls.py
