import sys
input = sys.stdin.readline

over = (int(input()) - int(input()))*-1
if over <= 0:
    print("Congratulations, you are within the speed limit!")
elif over < 21:
    print("You are speeding and your fine is $100.")
elif over < 31:
    print("You are speeding and your fine is $270.")
elif over >= 31:
    print("You are speeding and your fine is $500.")