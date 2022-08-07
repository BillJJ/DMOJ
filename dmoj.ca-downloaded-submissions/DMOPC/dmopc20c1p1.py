import sys
input = sys.stdin.readline

n = int(input())
for i in range(n):
    quiz = str(input())
    if(quiz.count("M") > 0 and quiz.count("C") > 0):
        print("NEGATIVE MARKS")
    elif(quiz.count("M") > 0 or quiz.count("C") > 0):
        print("FAIL")
    else:
        print("PASS")