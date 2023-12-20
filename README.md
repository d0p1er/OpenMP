# OPENMP
> sorry for my English

# Content
0. [Compile](#compile)
1. [INFO](#info)
2. [PI](#pi)
3. [Strassen algorithm](#strassen)
4. [Matrix multiplication](#matrix)

<a name="compile"></a>
## 0. Compile
In root directory:
```console
make
```
### Output:

![1.png](images/1.png)


<a name="pi"></a>
## 1. INFO
### See info about commands:
```console
./main info
```

### Output:

![2.png](images/2.png)


<a name="pi"></a>
## 2. PI
There are simple realization and OpenMP implementation
### PI simple:
```console
./main pi
```

### Output:

![3.png](images/3.png)

### PI with OpenMP:

```console
./main pi 4  
```
The second value 4 is amount of threads

### Output:

![4.png](images/4.png)


<a name="strassen"></a>
## 3. Matrix multiplication using Strassen algorithm
There is posibility to enter amount of threads
### Start Strassen algorithm:
```console
./main strassen
```

### Output:

![5.png](images/5.png)

### Start Strassen algorithm with amount of threads:
```console
./main strassen 4
```
The second value 4 is amount of threads

### Output:

![6.png](images/6.png)


<a name="matrix"></a>
## 4. Matrix multiplication AVX, SSE
There are simple multiplication, AVX and SSE optimizations
### Start simple matrix multiplication:
```console
./main multiply 1024
```
The second value 1024 is size of matrix

### Output:

![7.png](images/7.png)

Also there is posibility to enter amount of threads like this:

### Start simple matrix multiplication in parallel:
```console
./main multiply 1024 4
```
The second value 1024 is size of matrix. \
The third value 4 is amount of threads.

### Output:

![8.png](images/8.png)


### Start simple matrix multiplication with AVX optimization:
```console
./main multiply_avx 1024
```
The second value 1024 is size of matrix

### Output:

![9.png](images/9.png)

### Start simple matrix multiplication with SSE optimization:
```console
./main multiply_sse 1024
```
The second value 1024 is size of matrix

### Output:

![10.png](images/10.png)
