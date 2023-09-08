
# Projet Monty

## Description

This Monty project is an interpreter for the Monty programming language. It lets you read and execute Monty programs from text files, using a stack to store and manipulate data.


## Fonctionnalities

- Reading Monty files.
- Manage Monty instructions, including `push`, `pall`, `pint`, `pop`, `swap`, `add`, and `nop`.
- Error handling and appropriate error messages.
- Memory and resource release at the end of execution.

## Used

To run the Monty program, use the command line with a Monty file as argument:

 | shell |
 ```

 ./monty fichier.m
```

Make sure you have the specified Monty file (for example, file.m) in the same directory as the monty executable.



## Examples

Here are a few examples:



Running a Monty :


| shell |

```
Copy code

./monty my_program.m
```





Example of the contents of a Monty file  (my_program.m) :



| text |

| Copy code |
```
push 1

push 2

add

pall
```
| Output |

```
3
```

## Auteurs


[Leticia Habib](https://github.com/letihab) C21 HolbertonSchool

[Erwan Cremey](https://github.com/ER1-53) C21 HolbertonSchool


