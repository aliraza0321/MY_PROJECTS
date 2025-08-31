
import os
def add(a,b):
    return a+b
def sub(a,b):
    return a-b
def mul(a,b):
    return a*b
def div(a,b):
    return a/b
symbols={
    '+': add,
    '-': sub,
    '*': mul,
    '/': div
}
def info():
    print("+ for add\n- for sub\n- for mul\n- for div")
print("Welcome to quick calculator ")
info()
num1=int(input("Enter the first number: "))
flag=True
while flag==True:

    symbol=(input("Enter the symbol for operation: "))
    num2=int(input("Enter the second number: "))
    operation=symbols[symbol]
    result=operation(num1,num2)
    print(f"{num1} + {num2} = {result}")
    choice=(input("Do you want to continue with result enter y for yes or n for no : "))
    if choice=="y":
        os.system("clr")
        num1=result

    else:
        flag=False
        print("Bye")
