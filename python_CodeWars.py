#PROBLEM 3: find length of loop in linked list
#solution 1
def loop_size(node):
    visited = []
    current = node
    found = 0
    while found == 0:
        visited.append(current)
        current = current.next
        if (current in visited):
            found = 1
    return len(visited) - visited.index(current)

#solution 2: faster, less memory
#fast goes 2x faster than slow, so eventually will overtake (guaranteed loop)
def loop_size(node):
    slow_p = fast_p = node
     
    while(slow_p and fast_p and fast_p.next):
        slow_p = slow_p.next
        fast_p = fast_p.next.next

        # If slow_p and fast_p meet at some point then
        # there is a loop
        if slow_p == fast_p: #now keep ptr2 stuck and loop ptr1 till meet again -> length known
            ptr1 = slow_p
            ptr2 = slow_p
     
            # Count the number of nodes in loop
            k = 1
            while(ptr1.next != ptr2):
               ptr1 = ptr1.next
               k += 1
            return k
    # Return 0 to indicate that there is no loop
    return 0







            
