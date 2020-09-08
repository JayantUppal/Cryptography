#Decryption in substitution cypher
import itertools as it
import json

dictionary = json.load(open("dictionary.json")) 
# Uploaded dictionary.json in the same folder

n = len(input("Enter encrypted string: "))

for tuple in [p for p in it.permutations([chr(ord('a')+i) for i in range(26)], n)]:
    string = ''.join(tuple)
    if string in dictionary: 
        print(string)
        

