# push_swap
## Efficient stack sorting algorithm


Used just 3 standard C library functions
```c
ssize_t read(int fd, void *buf, size_t count);
void    *malloc(size_t size);
void    free(void *ptr);
```

Created `./push_swap` program to sorts stack in the least amount of operations and with a constrained auxiliar space


### Allowed operations
- `pa` push top first element of stack `a` to stack `b`
- `pb` push top first element of stack `b` to stack `a`
- `sa` swap first two elements of stack `a`
- `sb` swap first two elements of stack `b`
- `ss` execute `sa` and `sb`
- `ra` rotate stack `a` (the first element becomes the last)
- `rb` rotate stack `b`
- `rr`execute `ra` and `rb`
- `rra` reverse rotate `a` (the last element becomes the first)
- `rrb` reverse rotate `b`
- `rrr` execute `rra` and `rrb`  


Create `./checker` program to test and grade the first program  


## Approach
Experimented with multiple sorting algorithms (`Merge sort`, `Radix sort`, `Timsort`) but settled on `Quicksort`, because it was the best fit for given constraints. Standard `Quicksort` algorithm wouldn't work, so I had to reimplement it, using allowed operations, and optimizing for the constrained auxilar space

## Usage
I am using `mlx` (mini lib x) library for visualisation. Install it (only compitable with MacOS 10.12 and later)

Run `make` to create `push_swap` and `checker` executables

Use `./push_swap 0 2 1 3 5` to get instructions sorting providen numbers

Use `./checker 3 1 5 2 0` and provide instructions to see, if they will sort given numbers

Or use `./push_swap 5 2 1 3 0 | ./checker 5 2 1 3 0` to check if instructions, provided by push_swap actually sorts stack with given numbers


## Visualisation
To start visualisation run `./checker` with `-v` option  

Example `./push_swap 0 1 6 9 2 5 3 6 4 | ./checker -v 0 1 6 9 2 5 3 6 4`  

To start sorting press `space` or the Start button  
![push_swap](../assets/image/push_swap.png)     

You can turn on the operation counter by pressing `C`  
![counter](../assets/image/counter.gif)     

To restart sorting press 'R', or after sorting completed press the start button  
![restart](../assets/image/restart.gif)     

Hold `H` to see help menu  
![help](../assets/image/help.gif)     

### Features
To print out the state of stacks after each operation use option `-t` 

`./push_swap 0 1 4 3 | ./checker -t 0 1 4 3`  
![minus_t](../assets/image/minus_t.png)     

Numbers can be passed as one or many arguments  
`./push_swap 0 2 3` or `./push_swap "0 2 3"` or `./push_swap " 0" "2 3"`

