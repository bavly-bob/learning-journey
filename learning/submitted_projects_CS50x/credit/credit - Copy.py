from cs50 import get_int

def iv():
    print("INVALID")

card = get_int("Card: ")
cal = card
odd_sum = 0
even_sum = 0

# apply Luhn’s algorithm
while cal > 0:
    odd_sum += cal % 10
    cal //= 10
    if cal == 0:
        break
    even_di = cal % 10
    even_di = even_di * 2
    if even_di > 9:
        even_di -= 9
    even_sum += even_di
    cal //= 10

k = even_sum + odd_sum
length = len(str(card))

if k % 10 == 0:
    if length == 15:
        prefix = card // 10**13
        if prefix in (34, 37):
            print("AMEX")
        else:
            iv()
    elif length == 16:
        prefix2 = card // 10**14
        prefix1 = card // 10**15
        if prefix2 in range(51, 56):
            print("MASTERCARD")
        elif prefix1 == 4:
            print("VISA")
        else:
            iv()
    elif length == 13 and card // 10**12 == 4:
        print("VISA")
    else:
        iv()
else:
    iv()
