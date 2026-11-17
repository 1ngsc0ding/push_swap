# push_swap — Array starter

This is a first implementation of the parsing layer and stack operations using arrays.
Linked lists are intentionally postponed until the array version is understood.

## Current representation

- `values[0]` is the top of a stack.
- `size` is the number of active values.
- Stack A is populated by parsing.
- Stack B starts empty and has enough allocated capacity for all input values.

## Build

```sh
make
```

## Input examples

```sh
./push_swap 3 2 1
./push_swap "3 2 1"
./push_swap --simple 3 2 1
./push_swap --medium "3 2 1"
./push_swap --complex 3 2 1
./push_swap --adaptive 3 2 1
```

The strategy flag is optional; the default is `ADAPTIVE`.

## Important current limitation

This is a parsing and operations foundation, not a complete sorting program.
`main.c` currently validates the input and frees the stacks. The sorting algorithm
must be connected later. The operations modify the arrays but do not print their
instruction names yet; that output layer can be added when the team agrees on the
algorithm interface.

The accepted strategy names are `--simple`, `--medium`, `--complex`, and `--adaptive`.
# push_swap
