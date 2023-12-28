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


#the problem says that each time I see a 'B' in the string I have to delete the most recent uppercase letter
#and everytime i see 'b' I delete the most recent lowercase letter 
#Improbable -> elbaborpmI -> elrpmI -> Imprle

for _ in range(t):
    count_maj=0
    count_min=0
    maj="ACDEFGHIJKLMNOPQRSTUVWXYZ"
    minis="acdefghijklmnopqrstuvwxyz"
    s=input()
    res=""
    # if s[::-1] =="Improbable"[::-1]:
    #          print("Improbable"[::-1])
    for i in s[::-1]:
    
        
        if i == 'B':
            count_maj+=1
            
        elif i=='b':
            count_min+=1
            
        elif i in  maj and count_maj>0:
            count_maj-=1
        elif i in minis and count_min>0:
            count_min-=1
        else:
                res+=i
    # print(s[::-1])
    print(res[::-1])

            
    
    # print(indices)
    
    
        

                    
