# printf
 An implementation of C's printf function (from the ```stdio.h``` library).

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
make
```
```bash
gcc -Wall -Wextra -Werror src/main.c libftprintf.a -I include && ./a.out
```

A ```main.c``` file is included in the ```src``` folder where you will be able to try out the ```ft_printf``` function.

## License
This repository is released under the [MIT License](https://github.com/maxdesalle/printf/blob/main/LICENSE).
