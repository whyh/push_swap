# push_swap
## Efficient stack sorting algorithm

An objective was to create a program `./push_swap` that will print out instructions to sort a given stack of integers in an ascending order, using just next opperations
- `pa` push the top first element of stack `a` to stack `b`
- `pb` push the top first element of stack `b` to stack `a`
- `sa` swap first two elements of stack `a`
- `sb` swap first two elements of stack `b`
- `ss` execute `sa` and `sb`
- `ra` rotate stack `a` (the first element becomes the last)
- `rb` rotate stack `b`
- `rr`execute `ra` and `rb`
- `rra` reverse rotate `a` (the last element becomes the first)
- `rrb` reverse rotate `b`
- `rrr` execute `rra` and `rrb`  
And a second objective was to create a program `./checker` , that will execute instructions and tell if the stack waa sorted, or not.  
I was limited by assignment to use just two stacks. At the start one filled with given integers and the other is empty.  

## Approach
I've developed a quicksort based algorithm, coz as was stated in an appointment, i had to perform sorting in the lowest number of instructions possible. One of the difficultes was to emplement it, with just two stacks, allowed to use. I've managed to solve it, using as few rotations as i could.

## Usage
I am using the mlx (mini lib x) library for visualisation, you need to install it first. It's only compitable with MacOS(10.12 and later).  
Run `make` to create `push_swap` and `checker` executables.  
Use `./push_swap 0 2 1 3 5` to get instructions sorting providen numbers.  
Use `./checker 3 1 5 2 0` and provide instructions to see, if they will sort given numbers.  
Or use `./push_swap 5 2 1 3 0 | ./checker 5 2 1 3 0` to check if instructions, provided by push_swap actually sorts stack with given numbers.  

## Visualisation
To start visualisation run `./checker` with `-v` option.  
An example `./push_swap 0 1 6 9 2 5 3 6 4 | ./checker -v 0 1 6 9 2 5 3 6 4`  
To start sorting press `space` or press the start button  
![push_swap](../assets/image/push_swap.png)     
You can turn on the operation counter by pressing `C`  
![counter](../assets/image/counter.gif)     
To restart sorting press 'R', or after sorting completed press the start button  
![restart](../assets/image/restart.gif)     
Hold `H` to see help menu  
![help](../assets/image/help.gif)     

### Few more features
To print out the state of stacks after each operation use option `-c` , just like below  
`./push_swap 0 1 4 3 | ./checker -t 0 1 4 3`  
![minus_t](../assets/image/minus_t.png)     
Numbers could be passed as one or many arguments  
`./push_swap 0 2 3` or `./push_swap "0 2 3"`or `./push_swap " 0" "2 3"` etc

