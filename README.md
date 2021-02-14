# C-Phonebook
A functional phonebook written in C, capable of editing, searching and deleting entries. The phonebook uses a linkedlist to store entires and they are always sorted in alphabetical order. The user enters a number to select the options.

## Phonebook Enteries
The entries in the phonebook consist of three main parts namely:
- Contact name
- Contact phone-number
- A note. 
Notes are implemented as a dynamic string which allows inputs continuously until the period character is given i.e ".". An example of a note would be:

```sh
This is a sample note.
```

## Features
- **New Entry** - This allows the user add a new Entry into the phonebook.
- **List all Entries** - This lists all the entries currently in the phonebook.
- **Edit** - This allows the user edit currently saved entries. 
- **Delete** - This allows the user to delete an entry by name. Name given is case insensitive.
- **Search** - This allows the user to search from entries currently saved in the phonebook. 
- **save and exit** - This allows the user save the phonebook as a txt file and terminates. The file is saved in the project directory.
- **Load** - This allows the user to load a phoneboook txt file and displays it on the console.

## Compiling
To compile
```sh
make 
```

To remove files (complied object and resulting txt files in the directory)
```sh
make clean
```

> **WARNING** The clean command will remove **ALL** txt files in the directory. So be careful.

