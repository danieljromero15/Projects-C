# Binary to Decimal and Back Converter - Develop a converter to convert a decimal number to binary or a binary number
# to its decimal equivalent.
def to_binary(decimal_number):
    binaryNumber = []
    while decimal_number > 0:
        binaryNumber.append(decimal_number % 2)
        decimal_number //= 2
    binaryNumber.reverse()
    binaryNumberFinal = ''
    for i in binaryNumber:
        binaryNumberFinal += str(i)
    return binaryNumberFinal


def to_decimal(binary_number):
    decimal_number = 0
    binaryArray = []
    binaryArrayStr = list(str(binary_number))
    for i in binaryArrayStr:
        binaryArray.append(int(i))
    binaryArray.reverse()
    for index, i in enumerate(binaryArray):
        decimal_number += i * pow(2, index)
    # print(binaryArray)
    return decimal_number


DecimalToConvert = int(input("Enter a decimal number to convert to binary: "))
binary = to_binary(DecimalToConvert)
decimal = to_decimal(binary)
print("Binary: " + str(binary))
print("Back to decimal: " + str(decimal))
