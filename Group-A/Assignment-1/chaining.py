import random , string
class HashTable:
    def __init__(self, size):
        self.size = size
        self.keys = [None] * size
        self.values = [None] * size
    
    def hash_function(self, key):
        count = 0
        for _ in key:
            count += 1
        hash_value = count % self.size
        
        return hash_value

    def hash_insert(self, key, value):
        
        index = self.hash_function(key)
        
        if self.keys[index] is None:
            self.keys[index] = [key]
            self.values[index] = [value]
        else:
            self.keys[index].append(key)
            self.values[index].append(value)

    def print_table(self):
        print("Hash Table:")
        for i in range(self.size):
            if self.keys[i] is None:
                print(f"Index {i}: None")
            elif isinstance(self.keys[i], list):
                print(f"Index {i}:")
                for j in range(len(self.keys[i])):
                    print(f"  - {self.keys[i][j]}: {self.values[i][j]}")
            else:
                print(f"Index {i}: {self.keys[i]}: {self.values[i]}")

    def hash_search(self, key):
        index = self.hash_function(key)
        comparisons = 1

        while self.keys[index] is not None:
            if isinstance(self.keys[index], list):
                for i, k in enumerate(self.keys[index]):
                    if k == key:
                        print(f"Found {key} : {self.values[index][i]} with comparisons = {comparisons}")
                        return

                    comparisons += 1
            elif self.keys[index] == key:
                print(f"Found {key} : {self.values[index]} with comparisons {comparisons}")
                return

            comparisons += 1
            index = (index + 1) % self.size

        print(f"{key} not found with comparisons = {comparisons}")





