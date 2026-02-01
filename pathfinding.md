# Arc Looters – Pathfinding Module

## Overview
The **Pathfinding Module** generates an optimized loot collection path in Arc Looters.

Given:
- a player’s starting location,  
- remaining time until extraction,  
- loot spawn locations, and  
- risk zones,  

the module computes a path that **maximizes total loot value** while respecting time and risk constraints.

The module supports configurable risk profiles, allowing players to adopt high-, medium-, or low-risk strategies as
well as loot type priority or exclusion.

---

## Objectives
- Compute a path from the player’s start location to a valid extraction point.  
- Maximize the total loot value collected along the path.  
- Respect the time constraints of each extraction point.  
- Respect the user-selected risk tolerance level.  

---

## Inputs

| Parameter | Type | Description |
|-----------|------|-------------|
| `start_position` | Coordinates | Player’s current location on the map |
| `loot_spawns` | List of `LootNode` | Each node includes coordinates and loot value |
| `extractions` | List of `ExtractionPoint` | Each extraction includes coordinates and remaining time (`x(t)`) |
| `risk_tolerance` | Enum {High, Medium, Low} | Determines which map areas are considered safe for traversal |
| `time_to_distance_fn` | Function `f(t) -> d` | Maps remaining time to maximum feasible travel distance |

---

## Definitions
- **Loot Node** – A location containing loot with a quantifiable value.  
- **Extraction Point** – Locations where a player can exit; each has a time limit constraint.  
- **Risk Zone** – Map areas categorized as `Red` or `Yellow`. Risk zones affect path feasibility based on tolerance.  
- **Feasible Path** – Any path from start to extraction that respects time and risk constraints.

---

## Risk Tolerance Rules

| Risk Level | Restrictions |
|------------|--------------|
| High | Entire map is available. No exclusions. |
| Medium | Exclude any nodes or edges that intersect red zones. |
| Low | Exclude any nodes or edges that intersect red or yellow zones. |

---

## Graph Model
- **Vertices (V):** Each loot spawn is a vertex with an associated loot value.  
- **Edges (E):** Connect every pair of vertices with edges weighted by travel distance or estimated traversal time.  
- **Filtered Graph (G’):** The graph after pruning vertices and edges that violate risk or feasibility constraints.

---

## Path Constraints
- Paths start at the player’s position and terminate at an extraction point.  
- Total path cost must satisfy:
cost(P) ≤ x(t)

---

## Optimization Objective

For a given path `P`, define the total loot value as:
Value(P) = sum(value(v) for v in P)

The goal is to identify the path P* such that:
P* = argmax Value(P)
subject to feasibility and risk constraints

---

## Algorithm
The algorithm uses a form of approximation of the Orienteering Problem. This algorithm is ran every few seconds with updated
variables as a result, performance-optimized approximation algorithm is needed. More details in algorithm.tex.

---

## Outpus
| Output             | Type                | Description                                      |
| ------------------ | ------------------- | ------------------------------------------------ |
| `optimal_path`     | List of Coordinates | Ordered path of loot nodes to collect            |
| `total_loot_value` | Integer             | Total loot value collected along the path        |
| `total_distance`   | Float               | Total distance required to traverse the path     |
| `estimated_time`   | Float               | Estimated time to complete the path using `f(t)` |

