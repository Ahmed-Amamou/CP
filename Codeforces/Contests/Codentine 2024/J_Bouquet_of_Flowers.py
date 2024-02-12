import math
import random
import sys
import string
 # input = sys.stdin.readline
 
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(float,input().split())))
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
n = inp()
while(n>0):
    nb,budget = invr()
    L = inlt()
    L.sort(reverse=True)
    # print(L)
    res = 0
    for i in L:
        if budget >100:
            res += i * 100
            budget -= 100
        else :
            res += i * budget
            break
        # print(budget)
    
    print("{:.15f}".format(res/sum(L)))
    n-=1
        
    
    