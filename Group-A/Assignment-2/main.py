import random
import string

from chaining_without_replacement import HashTable


if __name__ == "__main__":

    n = int(input("size of hashtable : "))
    mob = HashTable(n)

    

    #     random_name = ''.join(random.choices(string.ascii_lowercase,  k=random.randint(1, 10)))
    #     random_number = random.randint(100000000, 999999999)

    #     mob.hash_insert(random_name, random_number)


    for i in range(n):
        name = input("Contact_name : ")
        number = int(input("Contact_number : "))
        mob.hash_insert(name, number)


    mob.print_table()

    _name = input("\n\nAny contact you wanna search for : ")
    mob.hash_search(_name)

    __name = input("Any contact you wanna delete : ")
    mob.hash_delete(__name)

    mob.print_table()


