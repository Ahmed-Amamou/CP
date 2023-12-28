import math
import random
import sys
import string
 # input = sys.stdin.readline
 
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(str,input().split())))
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
def get_number_of_distinct_distances(L1,L2):
    s=set()
    for i in range(len(L1)):
        s.add(L2[i]-L1[i])
    return len(s)

def inna():
    n,m=invr()
    geez=[]
    seez=[]
    for _ in range(n):
        L=insr()
        # print(L)
        G=L.index('G')
        geez.append(G)
        S=L.index('S')
        seez.append(S)
        if S<G:
            print(-1)
            return 
    
    print(get_number_of_distinct_distances(geez,seez))        
    
        
inna()