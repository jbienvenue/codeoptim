# Code optimization

This project gathers code examples that optimize performance.

- aos2soa.cpp:<br>
  shows the difference in access time between a struct list and a list struct

- aos2soa_big.cpp:<br>
    same as aos2soa.cpp but with larger structs

- fusion.cpp:<br>
  shows the difference between writing to a list then accessing it in a separate loop and in the same loop

- inline.cpp:<br>
  shows the access time of a function

- matmul_tile2d.cpp:<br>
  shows the difference between matrix product in a naive way and doing it tile by tile in 2d

- space_access.cpp:<br>
  shows the difference between accessing spaced elements to modify them and loading them into another list to reconcile them and then put them back in the list

- split_loop.cpp:<br>
  shows the advantage of changing the loop level of a condition to specialize a loop and make fewer conditions

- swap.cpp: <br>
  shows the difference between looping columns then rows and vice versa

- transpose_tile2d.cpp: <br>
  shows the difference between linear transposition and tile 2d by tile 2d
