# CSCI 3010 - python intro/review

# Comments in python start with a #

############################## Python Interpreter Questions ##########################
# Explore these questions in a python interpreter from the command line
# Run the python interpreter by typing "python". Make sure that you are running python version 3
# You'll see something like "Python 3.6.1 |Anaconda 4.4.0 (x86_64)| (default, May 11 2017, 13:04:09)"
# When you start the interpreter.
# If you start it and the version is not 3.x.x, try running "python3".
#
# 1. how do you declare a variable? Give an example.
#
###### Declare the name, no type needed
#
# 2. How do you declare a variable of type int? float? string? boolean?
#
###### you define the variable's value according to what type you want it to be
#
# 3. How do you declare a variable that is an empty list? a non-empty list?
#
###### myEmptyList = list()
###### myNonEmptyList = list(5)
#
# 4. How do you find the length of a string or a list in python?
#
###### using the len() function
#
# 5. How do you print to standard out?
#
###### you use print()
#
# 6. What does whitespace (spaces, tabs) indicate in python?
#
###### indentation means everything in python, it is the main tell for the 
###### interpreter that allows us to get rid of the curly brackets.
###### without it, your program would not recognize what is in your if statement
#
#
#####################################################################################


# 1. run this file from the command line. What command did you use?
# Answer:
#### python pythonintro.py

# Here is a function defined in python
def add_values(val1, val2):
    added = val1 + val2
    print(added)

# 2. Write at least 3 function calls to add_values using different types as parameters

add_values(1, 2)
add_values(2, 3)
add_values(3, 4)


def print_all_values(thing):
    for subthing in thing:
        print(subthing)


# 3. Write at least 2 function calls to print_all_values using different types as parameters

print_all_values([ 1, 2, 3 ])
print_all_values("ThingString")

# 4. Modify the function below so that if any 2 (or 3) colors are within 10 of each other,
# it prints "Mixed!" instead.
def color_dominance(red, green, blue):
    dominant = max(red, green, blue)
    if dominant == red:
        print("Most red!")
    elif dominant == green:
        print("Most green!")
    else:
        print("Most blue!")

# 5. Write at least 3 function calles to color_dominance here


# 6. Write a function that returns a value, call that function, save the value in a variable, and print the value.
