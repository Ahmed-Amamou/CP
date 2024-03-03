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
for _ in range(int(input())):
    n=int(input())
    s=input()
  
    # print(b)
    
    h=s.split("00")
    
    # print('1'.join(h))
    y='1'.join(h)
    
    # for i in range(len(h)):
    #     if(h[i]==''): 
    #         p=p+'1'
    #     else:
    #         p=p+h[i]
    j=y.split("011")
    # while(len(j)!=1):
    y='1'.join(j)
    count =0
    res=""
    last = n
    for i in range(len(y)):
        if(y[i]=='1'):
            count+=1
        else:
            count -=1
        if(count==-2):
            res+="1"
            last=i
            count=0
            continue
        if(count==1):
            res+="1"
            last = i
            count = 0
            continue
    i=last
    while(i<len(y)):
        res+=y[i]
        i+=1
    print(res[1:])
            
        
    
    # print(y)
    o=''
    