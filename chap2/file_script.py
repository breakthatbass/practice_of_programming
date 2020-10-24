# this script is to go with exercise 2-3 as a way to automate 
import random, string

def high_to_low(txtfile):
    '''create a file with a number on each line starting with 400,000 and decreasing to 0'''
    max_num = 900000
    with open(txtfile, 'w') as f:
        while(max_num != 0):
            f.write(f"{max_num}\n")
            max_num -= 1
        f.close()

def all_the_same(txtfile):
    '''write the number 5 once per line 400,000 times in a file'''
    max_num = 900000
    with open(txtfile, 'w') as f:
        while(max_num != 0):
            f.write(f"{5}\n")
            max_num -= 1
        f.close()

def random_nums(txtfile):
    '''create a file of 400,000 random numbers with one on per line'''
    upper = 99999
    max_num = 900000

    with open(txtfile, 'w') as f:
        while(max_num != 0):
            rn = random.randint(0, upper)
            f.write(f"{rn}\n")
            max_num -= 1
        f.close()
    
def rand_chars(txtfile):
    '''create a file of random chars'''
    max_num = 900000

    with open(txtfile, 'w') as f:
        while(max_num != 0):
            rc = random.choice(string.ascii_letters)
            f.write(f"{rc}\n")
            max_num -= 1
        f.close()

import sys

def main():

    if len(sys.argv) < 5:
        print("error: four files need to be supplied as arguments")
        sys.exit(1)

    f1 = sys.argv[1]
    f2 = sys.argv[2]
    f3 = sys.argv[3]
    f4 = sys.argv[4]

    high_to_low(f1)
    all_the_same(f2)
    random_nums(f3)
    rand_chars(f4)

if __name__ == '__main__':
    main()