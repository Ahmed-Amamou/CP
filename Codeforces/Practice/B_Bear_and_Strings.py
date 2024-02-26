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
#put starting position and ending position of each bear in the string
#then we generate all possible combinations and put them in a set
# then we return the length of the set

s=input()
L = []
n=s.count("bear")
pos = 0
valid = set()
for i in range(n):
    position = s.find('bear',pos)
    L.append([position,position+3])
    pos = position + 4

for positions in L :
    left=positions[0]
    while(left>=0):
        right= positions[1]
        while(right<len(s)):
            valid.add((left,right))
            right +=1
        left -=1
print(len(valid))