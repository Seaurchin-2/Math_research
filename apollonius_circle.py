import turtle as t
import math as mt
import time as tm
import os


class spot:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def gotoSpt(self):
        t.penup()
        t.goto(self.x, self.y)
        t.pendown()

    def printDot(self, size):
        self.gotoSpt()
        t.dot(size)

    def F(self, A, B):
        if (mt.sqrt(pow(self.x-B.x, 2)+pow(self.y-B.y, 2))) == 0:
            return -1
        return (
              (mt.sqrt( pow(self.x-A.x, 2) + pow(self.y-A.y, 2) ))
            / (mt.sqrt( pow(self.x-B.x, 2) + pow(self.y-B.y, 2) ))
        )

    x = 0
    y = 0


# input spots of A, B and also input m, n
# always A must left on B
A = spot(int(input()), int(input()))  # red color
B = spot(int(input()), int(input()))  # blue color
m = int(input())
n = int(input())

# basic drawing setting
t.pencolor('red')
A.printDot(5)
t.pencolor('green')
B.printDot(5)

# basic calculating setting
k = m / n  # m : n value
rate = 0
P = spot(0, 0)

t.pencolor('black')
t.speed(0)
print('k= ', k)
print('-'*20)

for num1 in range(A.x, B.x+abs(B.x)*int((1/k-0.3)*20), 2):
    P.x = num1  # change x value of P

    for num2 in range(-1*abs((A.x-B.x)*A.x), abs((A.x-B.x)*A.x), 2):
        # change y value of P and calculate rate value
        print('loop ', num1, '-', num2, end='\t||  ')
        P.y = num2
        rate = P.F(A, B)
        print('rate= ', rate, end='    ')

        # if rate is near to k value, draw that spot
        if (k-0.01 < rate) and (rate < k+0.01):
            print('able', end='')
            P.printDot(5)
        print('')

print('-'*20)
print('A: ', A.x, A.y)
print('B: ', B.x, B.y)
print('m:n = ', m, n)
print('success')
os.system("pause")
