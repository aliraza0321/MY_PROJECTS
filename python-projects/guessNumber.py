import logo_ascii
import random
EASY=10
HARD=5
def check_level( level):
    if level.upper() == "EASY":
        return EASY
    elif level.upper() == "HARD":
        return HARD
    else:
        print("Invalid level")
        return 0
def check_guess(num,guess):
    if num<guess:
        print("Guess was too low.")
        return False
    elif num>guess:
        print("Guess was too high.")
        return False
    else:
        print("Correct! You guessed correct number ")
        return True
def game():
    print(logo_ascii.logo)
    print("Welcome to Guess Number Game!")
    level=input("Enter level easy or hard which you want to play: ")
    guess=random.randint(1,50)
    # print(f"Guess is {guess}.")
    attempts=check_level(level)
    while attempts != 0:
        print(f"You have {attempts} attempts left !")
        num = int(input("Guess a number between 1 and 50: "))
        condition =check_guess(num,guess)
        attempts=attempts - 1
        if condition:
            print(f"You won at {attempts} attempts")
            break
        if attempts == 0:
            print("You Lose")
            print("Try again ")
game()




