# Simple UNIX command interpreter.
## DESCRIPTION
A simple shell created for Holberton School project by [Dionisio Arango](https://github.com/Dioni1195?tab=repositories) & [Luis Eduardo Diaz](https://github.com/luiseduardiazc?tab=repositories) 

## QUICK START
To start up Simple Shell, compile using `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`.

run
```
./hsh
```
## SYNOPSIS
simple_shell [command_string | file]

## DESCRIPTION
simple_shell is an sh-compatible command language interpreter that executes commands read from the standard input or from a file.
It is the program that is running when the user runs gcc -Wall -Werror -Wextra -pedantic *.c -o hsh and runs the executable file, ./hsh. The simple_shell implements commands that can be typed directly to the running shell or can be put into a file and the file can be executed directly by the shell.
### List of allowed functions and system calls

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)

## Output
    Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
    The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)
#### Example of error with sh:
```sh
 echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

### Same error with your program hsh:
```sh
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

## Useful Commands

  - [x] env - prints environment      
  - [x] cat - prints and concatenates files to the standard output
  - [x] cp -copies a file into another file
  - [x] grep - helps to search for a file in a specific pattern
  - [x] less - will let you go backward and forward in the files
  - [x] ls - will list all files and directories in current working directory
  - [x] mv - helps to move one file into another file
  - [x] pwd - given you the current working directory
  - [x] cd - change to directories

 ## Authors
| [Dionisio Arango](https://github.com/Dioni1195?tab=repositories) | [Luis Eduardo Diaz](https://github.com/luiseduardiazc?tab=repositories) |

