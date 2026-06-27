# LFUsim

A **Least Frequently Used (LFU) cache** simulator written in C, built to explore the data structures behind an efficient cache eviction policy.

## About

LFU evicts the item with the lowest access frequency when the cache is full (ties broken by recency). This implementation backs the cache with:

- A **hash table** for O(1) lookup of cached keys
- A **doubly linked list** of nodes to track ordering and frequency

When the cache reaches capacity, the least frequently used entry is evicted to make room for a new one.

## Project structure

```
LFUsim/
├── includes/        # headers (cache.h, hashtable.h, node.h)
├── src/             # implementation
├── main.c           # driver / demo
└── CMakeLists.txt   # build configuration
```

## Building and running

```bash
git clone https://github.com/vNullptr/LFUsim.git
cd LFUsim
cmake -B build
cmake --build build
./build/LFUsim
```

The driver runs a fixed access sequence against a capacity-4 cache and prints the cache state after each insertion, so you can watch eviction decisions happen step by step.

## Concepts demonstrated

`Cache eviction` · `Hash tables` · `Doubly linked lists` · `C memory management` · `CMake`
