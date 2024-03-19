import sys


def nilakantha_series(accuracy):
    pi = 3
    denominator = 2
    for i in range(accuracy):
        temp_denominator = denominator * (denominator + 1) * (denominator + 2)
        if i % 2 == 0:
            pi += 4 / temp_denominator
        else:
            pi -= 4 / temp_denominator

        denominator += 2

    return pi


if __name__ == '__main__':
    accuracyIn = int(input("Accuracy: "))
    print(nilakantha_series(accuracyIn))
