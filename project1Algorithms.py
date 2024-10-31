def toggleDoors():
    N = int(input("Enter number of Doors(N): "))
    doors = [False] * N  # Initially all doors are closed

    for i in range(1, N + 1):  #loop through each pass
        for j in range(i, N + 1, i):  # Toggle every i-th door
            doors[j - 1] = not doors[j - 1]  # Toggle state of the door
            print(f"i: {i} j: {j} Setp Size {i} Toggling door number {j}.") #print reult of each pass 
            

    print("Algorithm has finished.")
    
    #make list of open and closed doors 
    open_doors = [i + 1 for i, door in enumerate(doors) if door]
    closed_doors = [i + 1 for i, door in enumerate(doors) if not door]
    
    #print out open doors
    for doors in open_doors:
        print(f"Door number {doors} remains open.")
    #new line
    print()
    #print out closed doors
    for doors in closed_doors:
        print(f"Door number {doors} remains closed.")
    print()
        
    #fizzbuzz implementation
    fizz_buzz_result = []
    for i in open_doors:
        #if divisible by 3 and 5
            if i % 3 == 0 and i % 5 == 0:
                fizz_buzz_result.append("FizzBuzz")
                #if divisible by just 3
            elif i % 3 == 0:
                fizz_buzz_result.append("Fizz")
                #if divisible by just 5
            elif i % 5 == 0:
                fizz_buzz_result.append("Buzz")
                #if none of the conditions are true
            else:
                fizz_buzz_result.append(i)
       #Prints FizzBuzz results under output of open and closed doors         
    print(f"N Doors Puzzle's Fizz Buzz Implementation: {fizz_buzz_result}")
        
#execute program            
toggleDoors()