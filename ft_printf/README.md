# ```ft_printf```
```ft_printf``` is one of the three projects following [**```libft```**](https://github.com/maxdesalle/42/tree/main/libft).

The project consists of re-creating from scratch the ```printf``` function in C from the ```stdio.h``` library.

## How to use it
The ```ft_printf``` function supports the following types: 
```
c: char
s: string
p: pointer
d: int
i: int
u: unsigned int
x: lowercase hexadecimal number
X: uppercase hexadecimal number
```

as well as the following flags: ```-0.* +```.

if you want to try it out, simply clone this repository and execute the following commands:
```bash
cd 42/ft_printf/
```
```bash
make
```
```bash
gcc -Wall -Wextra -Werror src/main.c libftprintf.a -I include && ./a.out
```

I have included a ```main.c``` file in the ```src``` folder where you will be able to try it out the ```ft_printf``` function. Have fun!

## What I have learned
This project has been tremendously helpful for me as it allowed me to understand the inner workings of linked lists which I didn't understand before this, even if I knew more or less how it worked. Additionally, I discovered the use of variadic arguments through the ```stdarg.h``` library, which I think is incredibly interesting. Finally, it's also worth mentioning that this project pushed me to learn how to efficiently debug code, as well as create one coherent system which works with a lot of independant functions.

## Warning
The structure of this repository does **not** follow the guidelines.
The reason for this is to add some clarity in how the files are structured.

## License
Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
