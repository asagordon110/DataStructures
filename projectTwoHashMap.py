# Define the function to find the indices of two numbers that add up to the target
def twoSum(nums, target):
    # Initialize an empty dictionary to store numbers and their indices
    num_map = {}
    # Iterate over the enumerated list of numbers
    for i, num in enumerate(nums):
        # Calculate the complement needed to reach the target
        complement = target - num
        # Check if the complement exists in the dictionary
        if complement in num_map:
            # If found, return the indices of the complement and current number
            return [num_map[complement], i]
        # Add the current number and its index to the dictionary
        num_map[num] = i


def main():
    #infinite loop for continuous input
    while True:
        try:
            #take input from the user 
            input_data = input("Enter the input data array items: ")
            #convert input string to a list of integers
            nums = list(map(int, input_data.split()))
            #input from the user for the target value
            target = int(input("Enter the target value: "))

            #printing items in hashmap
            for i, num in enumerate(nums):
                print(f"Adding to hash table: key:{num}, value: {i}")

            #find result of twoSum for output 
            result = twoSum(nums, target)

            
            if result:
                print("Output:", result[1], result[0])  
            else:
                print("No solution found.")

        except ValueError:
            #invalid input
            print("Invalid input. Please enter integers.")

        #asks if user wants to continue
        cont = input("Do you want to continue? (yes/no): ")
        #break the loop if the user chooses not to continue
        if cont.lower() != "yes":
            break


main()
