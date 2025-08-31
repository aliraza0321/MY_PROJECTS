# Game Rules
# Rock wins against Scissors
# Scissors wins against paper
# paper wins  against rock
import random
print("Welcome to Rock Paper Scissors!")
choice=int(input("Enter 0 or rock ,1 for paper and 2 for scissors: "))
if choice>2 or choice<0:
    print("Invalid choice")
    exit
else:
    Com_choice=random.randint(0,2)
    print(f"You chose {choice}")
    print(f"Computer chose {Com_choice}")
    if Com_choice== choice:
        print("It's a draw")
    elif Com_choice==1 and choice==0:
        print("Computer wins the game ")
    elif Com_choice==2 and choice==0:
        print("You wins the game")
    elif Com_choice == 0 and choice==1:
        print("You wins the game")
    elif Com_choice == 2 and choice==1:
        print("Computer wins the game")
    elif Com_choice == 0 and choice == 2:
        print("Computer wins the game")
    elif Com_choice == 1 and choice == 2:
        print("You wins the game")
    else:
        print("Invalid choice")