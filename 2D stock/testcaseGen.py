from operator import xor
import random
import sys
import math


def main():


    args = sys.argv

    # M - Number of Bits in the Filter
    m = int(args[1])
    n = int(args[2])
    k = 1
    if (len(args) > 3):
        k = int(args[3])
    
    f = open('testcase'+str(m)+'_'+str(n)+'_'+str(k)+'.txt', 'w')

    f.write(str(k)+" "+str(m)+" "+str(n)+"\n")

    
    arr = [[0 for _ in range(n)] for _ in range(m)]

    for i in range(m):
        for j in range(n):
            arr[i][j] = random.randint(0,(2*m*n))

    for i in range(m):
        for j in range(n):
            f.write(str(arr[i][j]))
            f.write(" ")
        f.write("\n")
    # print(arr)
    print("testcases created")

    
if __name__ == "__main__":
    main()