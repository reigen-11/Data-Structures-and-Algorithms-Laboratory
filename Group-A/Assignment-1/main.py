import random
import string

from chaining import HashTable
from linear_probing import Linear_Probing


if __name__ == "__main__":

    n = int(input("size of hashtable : "))
    rick = Linear_Probing(n)
    morty = HashTable(n)

    for i in range(n-1):

        random_name = ''.join(random.choices(string.ascii_lowercase,  k=random.randint(1, 10)))
        random_number = random.randint(100000000, 999999999)

        rick.hash_insert(random_name, random_number)
        morty.hash_insert(random_name, random_number)

    name = input("Contact_name : ")
    number = int(input("Contact_number : "))

    rick.hash_insert(name, number)
    morty.hash_insert(name, number)

    print(f"Hashtable of Linear Probing :- {rick.print_table()} \n\n")

    print(f"Hashtable of Chaining :- {morty.print_table()} \n\n")

    _name = input("Any contact you wanna search for : ")


    print(rick.hash_search(_name))
    print(morty.hash_search(_name))
