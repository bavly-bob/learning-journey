def get_int(string):
    try:
        value = int(input(string))
    except ValueError:
        get_int()
    else:
        return value


def main():
    x = get_int("what: ")
    print(x)
main()
