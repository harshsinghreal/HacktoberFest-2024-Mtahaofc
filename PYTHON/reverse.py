def reverse_number(n):
    reversed_n = 0
    while n > 0:
        digit = n % 10
        reversed_n = reversed_n * 10 + digit
        n //= 10
    return reversed_n

number = 12345
print("Reversed number:", reverse_number(number))
