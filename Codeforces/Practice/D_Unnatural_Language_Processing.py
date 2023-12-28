import math
import random
import sys
import string
 # input = sys.stdin.readline
 
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():                              #For taking string inputs. Actually it returns a List of Characters, instead of a string,
    s = input()                          # which is easier to use in Python, because in Python, Strings are Immutable.
    return(list(s[:len(s) ]))
def invr():
    return(map(int,input().split())) #For taking space seperated integer variable inputs//
 
def construct_graph(num_nodes, edges):
    graph = {node: [] for node in range(1, num_nodes + 1)}
 
    for edge in edges:
        node1, node2 = edge
        graph[node1].append(node2)
        graph[node2].append(node1)
 
    return graph
#############################################
vowels = ['a', 'e']
consonants = ['b', 'c', 'd']
def generate_words():
    words = []
    for c1 in consonants:
        for v in vowels:
            words.append(c1 + v)
            for c2 in consonants:
                words.append(c1 + v + c2)
    return words

possible_words = generate_words()

words_with_length_3 = [word for word in possible_words if len(word) == 3]
words_with_length_2 = [word for word in possible_words if len(word) == 2]
# now given a string , split into worlds of length 3
def split_into_words(string):
    words = []
    for i in range(len(string) - 2):
        word = string[i:i+3]
        if word in words_with_length_3 and len(set(word)) == len(word):
            words.append(word)
    return words

s = input()
print(split_into_words(s))

