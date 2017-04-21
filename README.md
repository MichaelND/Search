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

Contributions
-------------
