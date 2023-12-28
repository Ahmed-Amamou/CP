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


t=int(input())
for _ in  range(t):
    a,b=invr()
    xk,yk=invr()
    xq,yq=invr()
    kpos1=(xk-a,yk-b)
    kpos2=(xk-a,yk+b)
    kpos3=(xk+a,yk-b)
    kpos4=(xk+a,yk+b)
    kpos5=(xk-b,yk-a)
    kpos6=(xk-b,yk+a)
    kpos7=(xk+b,yk-a)
    kpos8=(xk+b,yk+a)
    qpos1=(xq-a,yq-b)
    qpos2=(xq-a,yq+b)
    qpos3=(xq+a,yq-b)
    qpos4=(xq+a,yq+b)
    qpos5=(xq-b,yq-a)
    qpos6=(xq-b,yq+a)
    qpos7=(xq+b,yq-a)
    qpos8=(xq+b,yq+a)
    kpos=[kpos1,kpos2,kpos3,kpos4,kpos5,kpos6,kpos7,kpos8]
    kpos=set(kpos)
    qpos=[qpos1,qpos2,qpos3,qpos4,qpos5,qpos6,qpos7,qpos8]
    qpos=set(qpos)
    # print(kpos,qpos)
    res=0
    for i in kpos:
        if i in qpos:
            res+=1
    print(res)
