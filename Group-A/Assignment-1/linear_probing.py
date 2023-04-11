import random
import string

class Linear_probing:
    def __init__(self,size):
        
        self.size = size
        self.keys = [None] * self.size
        self.values = [None] * self.size

    def hash_function(self, key):
        
        '''
        we will be hashing keys as keys are unique 
        and values may repeat to minimize collisions
        '''

        return hash(key) % self.size

    def hash_insert(self, key , value):
        
        index = self.hash_function(key)

        for i in range(self.size):
            if self.keys[index] is None:
                self.keys[index] = key
                self.values[index] = value
                return

            elif self.keys[index] == key:
                self.values[index] = value
                return

            elif None not in self.keys:
                print("Hashtable Overflow")


            else:
                pass
        
            index = (index + 1) % self.size        

    def print_table(self):
        
        for i in range(self.size):
            print("{} : [{} - {}]".format(i,self.keys[i],self.values[i]))



if __name__ == '__main__':

    # n = int(input("size of the table : "))
    lalo = Linear_probing(10)

    for i in range(10):
        
        #& Yeah Biatch !!!
        name = ''.join(random.choices(string.ascii_uppercase, k=5)) 
        contact_no = random.randint(1000000000, 9999999999)

        #~ To do manually shit contact numbers
        # name = input("Enter contact name : ")
        # contact_no = int(input(f"Enter Contact number of {name}"))

        lalo.hash_insert(name,contact_no)

    lalo.print_table()






