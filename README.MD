# Nerl backend is here!
Now this is small library for C# for Nerl project. Needs to be compiled. No dependencies yet. Not thread safe now, later will be ready.

### What can you do with it

There is little class for saving/getting files via proceeding them through MD5 hashier and back.   

First, using harpy_csharp.utilities  

Create class save_sys, have just default constructor;

These changes the filepath. There's no base filepath, so they must be called before any saving/loading data.
First calls command line for choosing filepath, second just eats string.  
```c#
void save_sys.choose_base_filepath();
void save_sys.choose_base_filepath(string filepath);  
```
This saves into the base filepath into directory of first two hash letters and into subdirectory of second hash letters, then saves file with name consists of remain hash with .HHF (HarpyHashedFile)     
```c#
void save_sys.save(string hash, string data);  
```
This loads into string everything in file, if you give the right cash.
```c#
string save_sys.load(string hash);
```
That's all for now, later will be implemented multithreading