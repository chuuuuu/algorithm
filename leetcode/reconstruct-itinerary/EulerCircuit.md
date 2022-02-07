# Euler Circuit

We only consider undirected connected graph without self loop below. However, it can be easily to generalize for directed graph.

## Definition

- Euler Path

  - a path is Euler Path if
    - it goes through exactly once for every edges.

- Euler Circuit

  - a path is Euler Circuit if
    - it is an Euler Path.
    - it is also a cycle.

- Euler Walk
  - a random walk is an Euler Walk if
    - it doesnt pass an edge twice.

### Goal

- A path is an Euler Circuit if and only if the degree is even for every nodes.
- Find a Euler Circuit of the graph if it exists

### Lemma 1

If the graph has an Euler Circuit, then the degree is even for every nodes.

- see [site](https://www.youtube.com/watch?v=g929VCcnz5Q&ab_channel=SaradaHerke)

### Lemma 2

If the degree is even for every nodes and the graph is closed, then you can do an Euler Walk.

- see [site](https://www.youtube.com/watch?v=g929VCcnz5Q&ab_channel=SaradaHerke)

### Hierholzer’s Algorithm

see [site](https://www.youtube.com/watch?v=8MpoO2zA2l4&ab_channel=WilliamFiset)
