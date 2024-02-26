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
def inset():
    return(set(map(float,input().split())))
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
n,l = invr()
L = set(inlt())
L = list(L)
e = L[0]
if n == 1:
    print("{:.10f}".format(max(l-e,e)))
    exit()
L.sort()
# print(L)
maxx = L[0]
for i in range(1,len(L)):
    maxx = max(maxx,L[i]-L[i-1])
    # print(maxx)
# print(maxx/2,l-L[n-1],L[0])    
print("{:.10f}".format(max(maxx/2,l-L[len(L)-1],L[0])))    
# print(L)



