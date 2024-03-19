# Prime Factorization - Have the user enter a number and find all Prime Factors (if there are any) and display them.

def factorization(num):
    factor_array = []
    for i in range(2, num):
        if num % i == 0:
            factor_array.append(i)
    return factor_array


def product_of_nums_array(nums_array):
    product = 1
    for num in nums_array:
        product *= num

    return product


def prime_factorization(number):
    factors = factorization(number)

    if len(factors) > 1:
        prime_factors = [factors[0]]

        while product_of_nums_array(prime_factors) != number:
            # print(prime_factors)
            end_num = factors[len(factors) - 1]
            # print(end_num)
            factors = factorization(end_num)
            if len(factors) == 0:
                prime_factors.append(end_num)
            else:
                # print("factors: ", factors)
                prime_factors.append(factors[0])

        return prime_factors
    else:
        return number


if __name__ == '__main__':
    print(prime_factorization(330))
