import random
import string

from chaining_without_replacement import HashTable


if __name__ == "__main__":

    n = int(input("size of hashtable : "))
    mob = HashTable(n)

    for i in range(n-1):

        random_name = ''.join(random.choices(string.ascii_lowercase,  k=random.randint(1, 10)))
        random_number = random.randint(100000000, 999999999)

        mob.hash_insert(random_name, random_number)


    name = input("Contact_name : ")
    number = int(input("Contact_number : "))
    mob.hash_insert(name, number)

    mob.print_table()
    print(mob.hash_search(name))
    mob.hash_delete(name)
    mob.print_table()

