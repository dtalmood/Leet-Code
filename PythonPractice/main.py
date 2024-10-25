
# run command: python .\main.py
# Python Syntax Refresher:


# Input Syntax

'''

def main():
    x = input()
    print(float(x)) # x is now a float


    y = input()
    print(int(x)) # y is now a integer


    z = int(input()) # Ensure integer is a input 

    d = float(input()) #Ensure input is float 
    	
if __name__ == "__main__":
    main()
    pass

'''

# List Syntax
'''

friends = ["Dylan", "Bruce", "Alfred", "Clark"]

object = ["Dylan", 27, True]

# Print all freinds 
print(friends) # Output = ['Dylan', 'Bruce', 'Alfred', 'Clark']


# First Element 
print(friends[0]) # Output = ['Dylan']

# Last Element 
print(friends[-1]) # Output = ['Clark'] 

# Everything after index 2 and beyond 
print("\n", friends[2:]) # Output  = ['Alfred', 'Clark']

# Between index 1 and 2 
print("\n", friends[0:2]) # Output =  ['Dylan', 'Bruce']


# Append(): Adds to end of list
print("\nAppend: ")
friends.append("Bobby")
print("\n",friends) # Output = ['Dylan', 'Bruce', 'Alfred', 'Clark', 'Bobby']

# Insert(): Add at specific index 
print("\nInsert:")
friends.insert(1, "Tony")
print("\n",friends) # Output = ['Dylan', 'Tony', 'Bruce', 'Alfred', 'Clark', 'Bobby']

# Remove(): Remove by value 
print("\nRemove: ")
friends.remove("Bobby")
print("\n",friends) # Output = ['Dylan', 'Tony', 'Bruce', 'Alfred', 'Clark']

# Remove and print last element 
print("\nPop:")
lastFriend = friends.pop()
print("\n" + lastFriend) # Output = Clark
print(friends) # Output = ['Dylan', 'Tony', 'Bruce', 'Alfred']

# Length():
print("\nLength:") 
print(len(friends)) # Output = 4 


# For Loop: Print all elements
print("\nFor Loop:")
for x in friends:
    print(x + ", ")

# For Each Loop:
print("\nFor Each Loop:")
for i in range(1, len(friends),1):
    print(friends[i])

# While Loop:
print("\nWhile Loop:")
while i < len(friends):
    print(friends[i])
    i += 1

# Access Index and Value: 
print("\nAccess Index + Value Loop:")
for index, value in enumerate(friends):
    print(f"Index: {index}, Value: {value}")

#Sort a list:
print("\nSort:") 
friends.sort()

# Reverse list 
print("\nReverse: ")
friends.reverse()
print("\n", friends)


#Combine two lists
print("\nCombine Lists: ")
even = [2,4,6,8]
odd = [1,3,5,7,9]

odd.extend(even)
total = odd
print(total) # Output: [1, 3, 5, 7, 9, 2, 4, 6, 8]
                                 
#index(): Tells location of where element is 
print("\nIndex:")
print("Index of element 9 in the list = ", total.index(9))

'''

# Defining Functions Syntax

'''
def cube(x):
    return x * x * x

if __name__ == "__main__":
    x = 3
    y = cube(3)
    print(y)
    pass
    
'''

# If Statments Syntax

'''
male = True
tall = True
if male and tall:
    print("Male and Tall")

elif male or tall:
    print("Male or Tall")

elif(male and not(tall)):
    print("Male and not Tall")

elif(not(male) and tall):
    print("Mot male and Tall")

else:
    print("Not male and Not Tall")

'''

# Dictionary Syntax

# Declare Dictioanry, Method 1: 
dictOne = dict()
print("Dictionary One = ", dictOne) # Output =  EMPTY

# Declare Dictioanry Method 2: 
dictTwo = {}
print("Dictionary Two = ", dictTwo) # Output =  s

# Declare and Define Dictionary, Method 3:
dictThree = {
    'a':1,
    'b':2
}

# Add Individual Elements:
print("\nAdd Elements: ")
dictOne['a'] = 1
dictOne['b'] = 2
dictOne['c'] = 3
dictOne['d'] = 4
dictOne['e'] = 5
print("Dictionary One = ", dictOne) # Output = {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5}

# Delete Element:
print("\nDelete Elements: ")
del dictOne["a"]
print("Dictionary One = ", dictOne) # Output = {'b': 2, 'c': 3, 'd': 4, 'e': 5}

#Pop
print("\nPop: ")
dictOne.pop("e")
print("Dictionary One = ", dictOne) # Output = {'b': 2, 'c': 3, 'd': 4}

# Populate Dictionary: 
# in:  checks if specific value exits wthin itetable list, tupple, dictionary, set, string
print("\nPopulate Dictionary: ")
myString = "aabbcd"
letterDictionary = {}

for letter in myString:
    if letter in letterDictionary:
        letterDictionary[letter] += 1
    else:
        letterDictionary[letter] = 1

print(letterDictionary) # Output = {'a': 2, 'b': 2, 'c': 1, 'd': 1}

# Iterate through Keys of Dictionary 
print("\nIterate through Keys Dictionary: ")
for key in letterDictionary:
    print(key)

# Iterate through key-value Dictionary 
print("\nIterate through Key-Value Dictionary: ")
for key, value in letterDictionary.items():
    print("key = ", key, ", value = ", str(value))

# Length of dictionary:
print("\nLength of Dictionary: ")
print("Length = ",len(letterDictionary))
print("Add element ... ")
letterDictionary['e'] = 1
print("Length = ",len(letterDictionary))

# Clear Dictionary: Remove all elements
letterDictionary.clear()