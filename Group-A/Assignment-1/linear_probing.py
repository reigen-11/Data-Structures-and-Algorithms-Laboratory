import random
import string


class Linear_Probing:

    def __init__(self, size):

        self.size = size
        self.keys = [None] * self.size
        self.values = [None] * self.size

    def hash_function(self, key):

        count = 0
        for _ in key:
            count += 1
        hash_value = count % self.size

        return hash_value

    def hash_insert(self, key, value):

        index = self.hash_function(key)

        for i in range(self.size):
            if self.keys[index] is None:
                self.keys[index] = key
                self.values[index] = value
                return

            elif self.keys[index] == key:
                self.values[index] = value

            elif None not in self.keys:
                print("Hashtable Overflow")

            else:
                pass

            index = (index + 1) % self.size

    def print_table(self):

        for i in range(self.size):
            print("{} : [{} - {}]".format(i, self.keys[i], self.values[i]))

    def hash_search(self, key):
        index = self.hash_function(key)
        comparisons = 0

        if self.keys[index] is not None:
            for i in range(self.size):
                if self.keys[i] == key:
                    print(f"Found {key} : {self.values[i]} with comparisons = {comparisons}")
                comparisons += 1
                i = (i + 1) % self.size

        print(f"{key} not found")
        return

linear_probing = Linear_Probing(5)

# Generating 5 random keys and values
random_keys = [''.join(random.choices(string.ascii_lowercase, k=5)) for _ in range(5)]
random_values = [random.randint(1, 100) for _ in range(5)]

# Inserting the keys and values into the hash table
for i in range(3):
    key = random_keys[i]
    value = random_values[i]
    linear_probing.hash_insert(key, value)

linear_probing.hash_insert('Aditya',12345)
linear_probing.hash_insert('Aditya',12345789)

# Printing the hash table
linear_probing.print_table()
