# why are some algoritms faster than others?

wiki: [source](<https://en.wikipedia.org/wiki/Algorithmic_efficiency>) (visited 2024-01-16)  
> In computer science, algorithmic efficiency is a property of an algorithm which relates to the amount of computational resources used by the algorithm.
> An algorithm must be analyzed to determine its resource usage, and the efficiency of an algorithm can be measured based on the usage of different resources.
> Algorithmic efficiency can be thought of as analogous to engineering productivity for a repeating or continuous process.  
> For maximum efficiency it is desirable to minimize resource usage.  
> However, different resources such as time and space complexity cannot be compared directly, so which of two algorithms is considered to be more efficient often depends on which measure of efficiency is considered most important.  
> For example, bubble sort and timsort are both algorithms to sort a list of items from smallest to largest.  
> Bubble sort sorts the list in time proportional to the number of elements squared ($O(n^2)$, see Big O notation), but only requires a small amount of extra memory which is constant with respect to the length of the list ($O(1)$).  
> Timsort sorts the list in time linearithmic (proportional to a quantity times its logarithm) in the list's length ($O(n \log⁡ n)$), but has a space requirement linear in the length of the list $O(n)$.  
> If large lists must be sorted at high speed for a given application, timsort is a better choice; however, if minimizing the memory footprint of the sorting is more important, bubble sort is a better choice.

![big o graph](./../Assets/big%20o.png)

in short `Big O notation` is a tool used to descrive the time complexity of an algoritm, where the complexity specifies how long it will take to execute an algoritgm as a function of its input.

## general rules

1. big O notation ignores constants
2. certain terms "dominate" others
   - $O(1) < O(\log n) < O(n) < O(n \log n) < O(n^2) < O(2^n) < O(n!)$  
   meaning the lower order gets ignored

## constant time

```py
x = 5 + (15 * 20)
```

the line above is $O(1)$ because it is independant of N.

```py
x = 5 + (15 * 20)
y = 15 - 2
print x + y
```

each of the 3 lines above are $O(1)$, which would make this block $O(1) + O(1) + O(1) = 3*O(1)$.  
but because we ignore constants it becomes $O(1)$.

## linear time

```py
for x in range (0, n):
    print x
```

the print statement is $O(1)$, which means the sum becomes $N*O(1)$ which becomes $O(N)$.

```py
y = 5 + 15 * 20
for x in range (0, n)
    print x
```

calculating y is $O(1)$, and the for loop is  $O(N)$.  
making the sum $ $O(1) + O(N)$  
but because we drop lower oder terms this is still $O(N)$

## quadratic time

```py
for x in range (0,N):
    for y in range(0, N):
        print x * y
```

we know that print is $O(1)$, and that the `y` loop is $O(N)$.  
but by adding the `x` loop around it we made it $O(N^2)$.  
because each iteration of the `x` loop we do the full `y` loop

## exponential time

```py
def fibonacci(n):
    if n in {0, 1}:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

[fibonacci(n) for n in range(15)]
```

this recursive function above shows $O(2^N)$.  
because its rate doubles each time a set is added.
