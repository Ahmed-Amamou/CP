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
s=input()
L=[0]*26
for i in s:
    L[ord(i)-ord('A')]+=1
odd_count = 0
ans = ""
lmo2a5ra =""
# print(L)

for i in range(len(L)):
    if(L[i]%2):
        odd_count+=1
        lwost=chr(i+65)*L[i]
        
if(odd_count)>1:
    print("NO SOLUTION")
else:
    for i in range(len(L)):
        if(L[i]%2==0):
            # print(chr(i+65))
            ans +=chr(i+65)*(L[i]//2)
    lmo2a5ra=ans[::-1]
if(odd_count==1):
    ans+=lwost
ans+=lmo2a5ra
print(ans)
