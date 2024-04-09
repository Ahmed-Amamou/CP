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
# v_me,dest = invr()
# v_police,p_me,F = invr()

# p_police = 0
# cnt=0
# while(p_me<dest):
#     p_me +=v_me
#     p_police+=v_police
#     if(p_police>=p_me):
#         p_me+=F*v_me
#         cnt+=1
# print(cnt)
L=[,2,3,34]
print(L[-10%4])