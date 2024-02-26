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
n,m=invr()
D={x:[] for x in range(1,n+1)}
for i in range(m):
    a,b=invr()
    D[a].append(b)
    D[b].append(a)
# print(D)
flag = True
k=0

while(flag):
    L = []
    flag = False
    for i in D.keys():
        if(len(D[i])==1):
            L.append(i)
            flag = True
    if flag :
        k+=1
        for i in L:
            del D[i]
        for i in D.keys():
            for j in L:
                if j in D[i]:
                    D[i].remove(j)

print(k)