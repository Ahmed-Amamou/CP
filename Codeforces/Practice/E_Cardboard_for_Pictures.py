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


# If you want to take tt as input, uncomment the line below:
# tt = int(input())
tt = int(input())
# print(tt)
for _ in range(tt):
    n, c = invr()
    somme = 0
    sqr_somme = 0

    
    x = inlt()
    somme = sum(x)
    for  j in x:
        sqr_somme += j * j
    # print(x)
    delta = somme * somme - n * (sqr_somme - c)
    x1 = (-somme - math.sqrt(delta)) / (2 * n)
    x2 = (-somme + math.sqrt(delta)) / (2 * n)

    if x1 >= x2:
        print(int(x1))
    else:
        print(int(x2))      
