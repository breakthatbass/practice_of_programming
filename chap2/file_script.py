# this script is to go with exercise 2-3 as a way to automate 
import random, string

def high_to_low():
    '''create a file with a number on each line starting with 400,000 and decreasing to 0'''
    max_num = 900000
    with open('high_to_low.txt', 'w') as f:
        while(max_num != 0):
            f.write(f"{max_num}\n")
            max_num -= 1
        f.close()

def all_the_same():
    '''write the number 5 once per line 400,000 times in a file'''
    max_num = 900000
    with open('all_the_same.txt', 'w') as f:
        while(max_num != 0):
            f.write(f"{5}\n")
            max_num -= 1
        f.close()

def random_nums():
    '''create a file of 400,000 random numbers with one on per line'''
    upper = 99999
    max_num = 900000

    with open('random_nums.txt', 'w') as f:
        while(max_num != 0):
            rn = random.randint(0, upper)
            f.write(f"{rn}\n")
            max_num -= 1
        f.close()
    
def rand_chars():
    '''create a file of random chars'''
    max_num = 900000

    with open('rand_chars.txt', 'w') as f:
        while(max_num != 0):
            rc = random.choice(string.ascii_letters)
            f.write(f"{rc}\n")
            max_num -= 1
        f.close()

def main():
    high_to_low()
    all_the_same()
    random_nums()
    rand_chars()

if __name__ == '__main__':
    main()