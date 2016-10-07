#PROBLEM 2 : given m, find n so that m= n**3 + (n-1)**3 + ... + 1


#You can use logger.setLevel at the start of the program to set the output level
#If you set it to DEBUG, it will print all the debugs.
#Set it to INFO or higher and immediately all of the debugs will disappear.
#You can also use it to log more serious things, at different levels (INFO, WARNING and ERROR).
logging.basicConfig(level=logging.INFO,stream=sys.stderr, format='%(levelname)s - %(message)s')
#EXAMPLES
#logging.debug('A debug message!')
#logging.info('We processed %d records', 10)

# ITERATIVE SOLUTION
#testing stuff
import math

def find_m(n):
    total = 0
    for i in range(0,n+1):
         total += i**3
    return total

def print_cubes(m):
    prev_total = 1
    prev_ratio = 1
    n=1
    while n < m:
        total = 0
        for i in range(0,n+1):
            total += i**3
        logging.debug("total: ",total, "\t|\t", "prev_total: ",prev_total)
        ratio = total/prev_total
        ratio_ratios = ratio/prev_ratio
        logging.debug("ratio: %.5f \t\t|\t ratio_ratios: %.5f \n", (ratio, ratio_ratios))
        n+=1
        prev_ratio = ratio
        prev_total = total
    print("ratio: \t\t", ratio)
    print("ratio_ratios: \t", ratio_ratios)

#print_cubes(241)

def execution_time(method):
    start_time = time.time()
    exec(method)
    print("--- %s seconds ---" % (time.time() - start_time))

def find_nb_iterative(m):
    if (m == 1): return 1
    if (m <= 0): return -1
    prev_total = 1
    prev_ratio = 1
    jump = 1
    n=2
    while 1: 
        # calculate total for this n
        logging.debug("calculating for n= %d",n)
        total = 0
        for i in range(0,n+1):
            total += i**3
            
        logging.debug("total= %d",total)
        if total == m:
            logging.info("found n: %d",n)
            return n
        if total > m:
            return -1
        
        #increase n if we're far away to reduce complexity
        current_ratio = total/prev_total
        logging.debug("current_ratio: %f", current_ratio)

        ratio_total_m = m/total
        logging.debug("ratio total/m: %f", ratio_total_m)
        estimate_further = int(math.log(ratio_total_m, current_ratio))
        logging.debug("estimate further: %f",estimate_further)
        if (jump == 1 and estimate_further > 1):
                n += estimate_further
                jump = 0 #disable jump to calculate correct ratio in next step
        else:
            n+=1
            jump = 1 #allow jump
        prev_total = total
        prev_ratio = current_ratio

# MATHEMATICAL SOLUTION
def find_nb_math(m):
    a = 1
    b = 1
    c = -2*math.sqrt(m)
    D= b**2 - 4*a*c
    n = (-b + math.sqrt(D))/(2*a)
    n = int(n)
    #test if result is integer
    if ( (n*(n+1)/2)**2 != m):
        return -1
    else: return n



##execution_time("""
##assert find_nb(100)== 4
##assert find_nb(4183059834009)== 2022
##assert find_nb(24723578342962)== -1
##assert find_nb(135440716410000)== 4824
##assert find_nb(40539911473216)== 3568
##assert find_nb(26825883955641)== 3218
##print("All default tests successful!")
##""")



#OTHER PEOPLE's SOLUTIONS
#1:
def find_nb(m):
    n = 1
    volume = 0
    while volume < m:
        volume += n**3
        if volume == m:
            return n
        n += 1
    return -1

#2:
from math import floor, sqrt

def find_nb(m):
    # Used the formula for the sum of cubes: m = (n(n+1)/2)^2
    # Rearranged to find n^2 + n = n(n+1) ~= n^2 ~= 2sqrt(m),
    # so take square root and round down the result.
    n_canidate = int(floor(sqrt(2 * sqrt(m))))
    if (n_canidate * (n_canidate + 1) / 2 )**2 == m:
        return n_canidate
    else:
        return -1
