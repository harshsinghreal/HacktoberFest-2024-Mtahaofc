def invert_number(number):
    if number == 0:
        return "Undefined (cannot divide by zero)"
    return 1 / number

# Example usage:
number = int(input("Enter a number: "))
print(f"The inverse of {number} is {invert_number(number)}")
