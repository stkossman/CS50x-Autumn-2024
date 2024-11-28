def print_row(spaces, bricks):
    print (" " * spaces, end = "")
    print("#" * bricks)

def main():
    n = 0
    while True:
        user_in = input("height (1-8): ")
        try:
            n = int(user_in)
            if 1 <= n <= 8:
                break
            print("Enter a positive integer between 1 and 8")
        except ValueError:
            print("Invalid input");


    for i in range(n):
        print_row(n-i-1, i+1)

if __name__ == "__main__":
    main()
