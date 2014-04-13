import sqlite3

print("Module loaded; activating Python super powers in 3 2 1..")

def parse(string):
    #clean string starts empty
    cleanedString = "";

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

        #string list cleaned, implode list to string and append it to return string
        cleanedString = ''.join(sarray)
        #empty out list, we're done with it
        sarray = []

    return cleanedString;