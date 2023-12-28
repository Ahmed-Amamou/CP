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
t=inp()
for i in range(t):
    s=input()
    frst=s[0]
    # Find the first occurrence of a non-zero number in s[1:]
    second = next((num for num in s[1:] if num != '0'), None)
    ind_second=s[1:].find(second)+1
    
    if int(s[:ind_second])<int(s[ind_second:]):
        print(s[:ind_second],s[ind_second:])
    else:
        print(-1)