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

n,k=invr()
count=0
L=[]

for j in range(k+1):
    L.append(j)
# print(L)
for i in range(n):
    flag=True
    a=insr()
    if len(a)<=k:
        continue
    else:
        a=set(a)
        a=sorted(a)
        # print(a)
        
        for i in L:
            if str(i) not in a:
                # print("Hello")
                flag=False
    if flag:
        # print("test")
        count+=1
            
            
print(count)
        
            
            
            