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
def distinct(s):
    for i in range(len(s)-1):
        if(s[i]==s[i+1]):
            return False
    return True
#I need to find the longest sequence of equal letters and return it

def longuest_equal_sequence(s):
    


def calcul(s):
    if(distinct(s)):
        return len(s)%2
    else:
        if(len(set(s))==1):
            return len(s)
        else:

        

t=inp()
while(t>0):
    n=inp()
    s=input()

    t-=1 