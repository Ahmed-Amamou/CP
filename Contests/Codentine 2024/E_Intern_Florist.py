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
def count_files(commands):
    files = set()
    results = []

    for command in commands:
        words = command.split()
        if words[0] == "touch":
            filename = words[1]
            files.add(filename)
        elif words[0] == "rm":
            for filename in words[1:]:
                if filename in files:
                    files.remove(filename)
        elif words[0] == "ask":
            results.append(len(files))

    return results


n = inp()
commands = [input().strip() for _ in range(n)]

results = count_files(commands)
for res in results:
    print(res)


