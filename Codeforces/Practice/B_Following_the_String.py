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
t= inp()
lowercase_alphabets = list(string.ascii_lowercase)
while(t>0):
    a = 0
    D={}
    n = inp()
    L = inlt()
    res = ""
    for i in L:
        if i == 0:
            # print(D)
            res +=lowercase_alphabets[a]
            D[lowercase_alphabets[a]] = 1
            a+=1
        for key,value in D.items():
            if i == value:
                res+=key
                D[key]+=1
                break
        

    print(res)                
 
    
    
    
    t-=1