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
def longest_sequences(s):
    max_ones = 0
    max_zeros = 0
    current_ones = 0
    current_zeros = 0

    for char in s:
        if char == '1':
            current_ones += 1
            current_zeros = 0
            max_ones = max(max_ones, current_ones)
        else:
            current_zeros += 1
            current_ones = 0
            max_zeros = max(max_zeros, current_zeros)

    return max_ones, max_zeros
#############################################
t=inp()
for _ in range(t):
    s=input().strip()
    o = s.count("0")
    z = s.count("1")
    ans=""
    for i in range(len(s)):
        if (s[i]=='0' and o<1): 
            break
        if (s[i]=='1' and z<1):
            break
        if (s[i]=='0' and o>1): 
            ans+='1'
            o-=1
        elif(s[i]=='1' and z>0):
            ans+='0'
            z-=1
    print(abs(len(s)-len(ans)))
    