import sqlite3

print("Module loaded; activating Python super powers in 3 2 1..")

def parse(string):
    #clean string starts empty
    cleanedString = ""

    #if there's more than one char in string
    if(len(string) > 0):
        #from immutable string to mutable list
        sarray = list(string)
        #get each individual char
        for key, char in enumerate(sarray):
            #if special chars
            if (sarray[key] == "\\"):
                #if delete char
                if (sarray[key+1] == "d" and len(sarray) >= 3):
                    #delete the char that needs deleted, and delete the delete instructions
                    del sarray[key+1]
                    del sarray[key]
                    del sarray[key - 1]
                #ignore carriage returns, they're handled by texture manager
                elif (sarray[key+1] == "n"):
                    continue

        #string list cleaned, implode list to string and append it to return list
        cleanedString = ''.join(sarray)
    
    #string is at index 0; command list at index 1
    sarray = (cleanedString, stringToCommand(cleanedString))
    print(sarray)
    return sarray

def stringToCommand(string):
    #sanitize string
    found = 0
    while (found != -1):
        found = string.find("\n")
        string = string.replace("\n", " ")

    #split string into words
    sarray = string.split(" ")
    #holds int commands
    commands = list()
    #check each word for valid commands
    for word in sarray:
        if (word.lower() == "left"):
            commands.append(4)
        elif (word.lower() == "right"):
            commands.append(2)
        elif (word.lower() == "up"):
            commands.append(1)
        elif (word.lower() == "down"):
            commands.append(3)

    #return commands as a list
    return commands