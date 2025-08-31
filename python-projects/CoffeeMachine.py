# import logo_ascii
menu={
    'capichino':250,
    'lattee':260,
    'white':190
}
def deposit_payment():
    notes10 = int(input("Enter no of notes of 10: "))
    notes20 = int(input("Enter no of notes of 20: "))
    notes50 = int(input("Enter no of notes of 50: "))
    received_amount = notes10 * 10 + notes20 * 20 + notes50 * 50
    print(f"You give me {received_amount} ruppess")
    return received_amount
def check_money(payment,price):
    if payment > price:
        price=payment-price
        print(f"Your remaining amount is {price} Kindly collect is from deposite table")
    elif payment < price:
        price =price-payment
        print(f"You have insufficient payment kindly give me {price} more\n.....I am waiting for you remaining payment.....   ")
        print("Thanks you  gave remaining amount now you can go ")
    else:
        print("You  have given whole amount of money ")
def info(type_of_coffee):
    print(f"Your coffee is {type_of_coffee}! Good")
    print("Give me notes of 10,20 ,50 only for payment")
    payment = deposit_payment()
    price = menu[type_of_coffee]
    check_money(payment, price)
# print(logo_ascii.logo2)
print("Welcome to Coffee Machine!")
flag = True
while flag:
    type_of_coffee = input("What type of coffee do you have?(capichino,lattee,white) : ")
    if type_of_coffee == "capichino":
        info(type_of_coffee)
    elif type_of_coffee == "lattee":
         info(type_of_coffee)
    elif type_of_coffee == "white":
         info(type_of_coffee)
    else:
         print("Sorry, you have not this coffee machine")
    choice=input("Would you like to some other?(yes/no) : ")
    if choice.lower() == "no":
        flag = False
        print("Thank you for using Coffee Machine!")

