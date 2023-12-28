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
n, k = map(int,input().split())
D = {}
for i in range(n):
    
    a, b = map(int,input().split())
    D[a] = b

D = dict(sorted(D.items(), reverse=True))  # Sort the dictionary D by keys in descending order
count=0
sum=0

#k=5 {4: 2, 3: 1, 2: 3}
for i in (D.keys()):
    if (k<=D[i]):
        sum+=(k) * i
        break
    if k<=0: 
        break
    sum += D[i] * i
    k-=D[i]
print(sum)