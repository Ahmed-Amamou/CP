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
n,a=invr()
l=inlt()
# print(l)
count=0
i=j=a-1
if l[a-1]==1:
    count+=1
i-=1
j+=1  
# print(l)
while (True):
    if (i<0 or j>=len(l)):
        break
    if (l[i]==1 and l[j]==1):
        count+=2
        j+=1
        i-=1
    else:
        j+=1
        i-=1
    
while(True):
    if(i<0 and j<len(l)):
        if (l[j]==1):
            count+=1
            j+=1
            i-=1
        else:
            j+=1
            i-=1
    else:
        break
while(True):
    if(j>=len(l) and i>=0):
        if (l[i]==1):
            count+=1
            j+=1
            i-=1
        else:
            j+=1
            i-=1
    else:
        break


print(count)