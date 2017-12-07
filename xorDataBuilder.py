from random import *

with open('xor.csv', 'a') as file:
    for i in range(0,2000):
        a = randint(0, 1)
        b = randint(0, 1)
        c = 0
        if not bool(a) == bool(b):
            c = 1

        file.write('{},{},{}\n'.format(a,b,c))
