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
s=input()
L=s.split('@')
if (len(L)!=2):
    print('no')
    
else:
    if(L[1]!="odoo.com"):
        print("no")
    else:
        if(L[0]!=L[0].lower()):
            print("no")
        else:
            if(len(L[0])>4 or len(L[0])<2):
                print('no')
            else:
                print('yes')
        