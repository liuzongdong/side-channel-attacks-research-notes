# Flush + Reload Experiments

A note contains a simple experiments according to the Flush + Reload, some parts of the code comes from the author.

## Spy program

`args.h`: Defines the arguments for the spy program and the Probe structure.

`attacktools.h`: Contains binary mapping and the Assembly language code

`cpuid.h`: Third party library, check if the CPU is Intel

`elftools.h`: Get the address of binary file

`exitcodes.h`: Exit code

`flushreload.h`: Header files for program

`flushreload.c`: The core function of flush and reload, print the probe results

`spy.c`: Main program to launch

## Compile

Simply run the following command to compile the program:

``` bash
make
```

## Program Arguments

```null
Usage: ./spy -e ELFPATH -t CYCLES -s CYCLES -p PROBE [-p PROBE ...]

    -e, --elf PATH            Path to ELF binary to spy on
    -t, --threshold CYCLES    Max. L3 latency
    -s, --slot CYCLES         Slot duration in cycles
    -p, --probe N:0xDEADBEEF  Name character : Virtual address
```

For the threshold, according to the author, a value of `120` works fine for most operation systems. The value can be checked by the `FR-threshold` program in the Mastik

``` bash
               :  Mem   Cache
Minimum        :  172   63
Bottom decile  :  194   66
Median         :  211   83
Top decile     :  217   86
Maximum        :  36882 6154
```

Besides, A slot size of 2048 was also suggested by the author

After compiling the spy program, we can continue on creating victim program.

## Experiment 1 (Failed - Possible Reason: Address Overlap)

Write a small C program, very easy, inspired from the Fuzzing, a program contains different `path`s. In this case, we will not crash program.

Here is the C code of victim program `hello.c`

```bash
vim hello.c
```

``` C
#include <stdio.h>
#include <stdlib.h>

void fooA() {
    float x = 5;
    float y = 2;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 10; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("A %f\n", x);
}

void fooB() {
    float x = 4;
    float y = 1;
    x += y;
    x += y;
    x += y;
    x *= y;
    for (int i = 0; i < 50; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("B %f\n", x);
}

void fooC() {
    float x = 2;
    float y = 3;
    x += y;
    x *= y;
    for (int i = 0; i < 20; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("C %f\n", x);
}

int main(int argc, char **argv)
{
    char input[16];
    for(int i = 0; i < 1000; i++) {
        printf("Enter either A, B, C, or D:\n");
        fgets(input, 16, stdin);
        if (input[0] == 'A') {
            fooA();
        } else if (input[0] == 'B') {
            fooB();
        } else if (input[0] == 'C') {
            fooC();
        } else if (input[0] == 'Q') {
            exit(0);
        } else {
            printf("Error\n");
        }
    }
}
```

Compile the program with `-g` argument to ensure the debug information will be included in the binary file

```bash
gcc -g hello.c -o hello
```

Find the address by `objdump`

```bash
objdump -D -M intel hello | less
```

Search the function and record the address

```bash
/fooA
```

Run the spy program

```bash
./spy -e hello -t 120 -s 2048 -p A:0x07ca -p B:0x0xxx ...
```

Open another terminal window run the victim program

```bash
./hello
```

However, in this experiment, the spy program outputs random guess constantly insane if we probe more than one memory address. After talking with Toby, we guess it is caused by the address overlap, divide the C program into several files may be a solution for that.

## Experiment 2

To solve the problem, a easy solution, put more codes in the victim program to make sure the program is `big` enough so that the distance of address is larger.

```C
#include <stdio.h>
#include <stdlib.h>

void fooA() {
    float x = 5;
    float y = 2;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 10; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("A %f\n", x);
}

void fooB() {
    float x = 4;
    float y = 1;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 50; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("B %f\n", x);
}

void fooC() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 20; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("C %f\n", x);
}

void fooD() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

void fooE() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

void fooF() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

void fooG() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

void fooH() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

void fooI() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

int main(int argc, char **argv)
{
    char input[16];
    for(int i = 0; i < 1000; i++) {
        printf("Enter either A, B, C, or D:\n");
        fgets(input, 16, stdin);
        if (input[0] == 'A') {
            fooA();
        } else if (input[0] == 'B') {
            fooB();
        } else if (input[0] == 'G') {
            fooG();
        } else if (input[0] == 'I') {
            fooI();
        } else if (input[0] == 'Q') {
            exit(0);
        } else {
            printf("Error\n");
        }
    }
}
```

In this case, Probe in three address also works fine.
