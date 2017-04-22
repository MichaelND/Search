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

1. Our search program has more calls than the find program (about 1000). For the type of calls, our search uses much less variety and doesn't have calls such as set_tid_address or set_robust_list and many more compared with find. Find uses a much more complex variety of system calls than search in other words.

2. Our trace for the find program outputted a lot of permission denied files when trying to do the system calls. Find uses fewer system calls and a wider range of system calls than search mainly because we assume that it is made to be more efficient and doesn't involved forking programs. One surprising thing as well was that search uses around 3600 calls of lstat when find uses newfstatat. Checking the manual shows that newfstatat is an underlying system call which is probably built into the system. lstat returns information about the link itself when fstatat dereferences symbolic links like stat. Find also uses this system call fchdir which changes working directories which is different than search which simply recursively goes through directories if they aren't empty. While search does things through symbolic links using lstat, find does things using fstatat. 


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
