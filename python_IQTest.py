# CODEWARS PROBLEM 1: IQ TEST

#PROBLEM 1 : find the odd number in the even sequence or vice versa
def iq_test(numbers):
    numbers= numbers.split(" ")
    logging.debug(numbers)
    nb_odd = int(numbers[0]) % 2 + int(numbers[1]) % 2 + int(numbers[2]) % 2
    logging.debug(nb_odd)
    if nb_odd >=2: #sequence is odd
        for index in range(len(numbers)):
            if numbers[index]%2 == 0:
                return index+1
    else: #sequence is even
        for index in range(len(numbers)):
            if numbers[index]%2 == 0:
                return index+1

##print(iq_test("2 4 7 8 10"))
###Test.assert_equals(iq_test("2 4 7 8 10"),3)
###Test.assert_equals(iq_test("1 2 2"), 1)
##22395855845476 
##24723578342962
