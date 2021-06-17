# ABBAA
# ABBBB
# ABABA
# ABBBA
import queue

def main():
    T = int(input())
    for i in range(T):
        ans = solve()
        print(f'Case #{i+1}: {ans}')

def solve():
    N, K = [int(s) for s in input().split(' ')]
    words = []
    for i in range(N):
        words.append(input())

    trie = {'#': 0, 'isEnd': False, 'score': 0}
    for word in words:
        node = trie
        for c in word:
            if c not in node:
                node[c] = {'#': 0, 'isEnd': False, 'score': node['score']+1, 'parent': node}
            node = node[c]

        node['#'] += 1
        node['isEnd'] = True
    
    nodes = []
    q = queue.Queue()
    q.put(trie)
    while True:
        if q.empty():
            break
        node = q.get()
        nodes.append(node)

        for key, child_node in node.items():
            if key == '#' or key == 'isEnd' or key == 'score' or key == 'parent':
                continue

            q.put(child_node)

    ret = 0
    nodes.reverse()
    for node in nodes:
        if node == trie:
            continue
        gp_num = node['#'] // K
        node['parent']['#'] += node['#'] - gp_num * K
        ret += gp_num * node['score']

    return ret

if __name__ == '__main__':
    main()