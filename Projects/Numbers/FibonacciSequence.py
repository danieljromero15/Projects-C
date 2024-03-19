# Fibonacci Sequence - Enter a number and have the program generate the Fibonacci sequence to that number or to the
# Nth number.
def fibonacci(n):
    a = 0
    b = 1
    print(a)
    print(b)

    for i in range(n):
        c = a + b
        print(c)
        a = b
        b = c


if __name__ == '__main__':
    indexNum = int(input("Number of numbers to produce: "))
    fibonacci(indexNum)
