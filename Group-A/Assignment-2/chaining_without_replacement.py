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

        elif self.keys[index] == key:
            self.values[index] = value

        else:
            if not isinstance(self.keys[index], list):
                self.keys[index] = [self.keys[index]]
                self.values[index] = [self.values[index]]
        
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

        while self.keys[index] is not None:
            if isinstance(self.keys[index], list):
                # Search within a list of keys at the same index
                for i in range(len(self.keys[index])):
                    if self.keys[index][i] == key:
                        print(f"Found {key} with value {self.values[index][i]}")
                        return
            elif self.keys[index] == key:
                print(f"Found {key} with value {self.values[index]}")
                return
            index = (index + 1) % self.size

        return

    def hash_delete(self, key):
        index = self.hash_function(key)

        if self.keys[index] is None:
            print(f"{key} not found")
            return

        if isinstance(self.keys[index], list):
            try:
                value_index = self.keys[index].index(key)
            except ValueError:
                print(f"{key} not found")
                return

            print(f"Deleted -[{key} : {self.values[index][value_index]}]")
            self.keys[index].pop(value_index)
            self.values[index].pop(value_index)

            if len(self.keys[index]) == 0:
                self.keys[index] = None
                self.values[index] = None

        elif self.keys[index] == key:
            print(f"Delete {key} : {self.values[index]}")
            self.keys[index] = None
            self.values[index] = None

        else:
            print(f"{key} not found")
            return




