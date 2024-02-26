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
n = int(input())
l=[]

def unique(a,b,c,d):
    return a!=b and a!=c and a!=d and b!=c and b!=d and c!=d
     
for _ in range(n):
   l.append(input())
d={}
for i in range(n):
    for j in range(n):
        if i != j:
            s = l[i] + l[j]      
            if s in d :
                if unique(d[s][0],d[s][1],i+1,j+1):
                    print("YES")
                    print(d[s][0],d[s][1],i+1,j+1)
                    exit()
            else:
                d[s]=(i+1,j+1)
print("NO")
                         