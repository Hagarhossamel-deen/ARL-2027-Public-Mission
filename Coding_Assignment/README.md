# 📏 Following Distance Monitor Challenge

Welcome to the **ARL 2027 Workshop** solo coding mission!  
Your task is to ensure the autonomous vehicle maintains a safe following distance from the vehicle ahead.
Make sure to read the guideline on AI Usage at the end of the README.

---

## 📝 Problem Statement

A radar provides the distance to the car ahead, while the speedometer provides the current speed. The "safe following distance" is dynamically defined as `speed * 0.5`. 
You need to write a function that calculates three tailgating metrics based on this data:

```python
def monitor_following_distance(distances: list[float], speeds: list[float]) -> tuple[int, float, int]:
```

---

## ⚙️ Requirements

### 1. Tailgating Seconds
Count the total number of seconds where the actual distance to the lead car was **strictly less than** the safe following distance.

### 2. Minimum Distance
Find the absolute closest the car ever got to the lead car (the minimum value in the `distances` list). If the lists are empty, return `0.0`.

### 3. Tailgate Incidents
Count the number of *separate instances* (streaks) the car started tailgating. 
- A single continuous streak of tailgating counts as exactly **1 incident**, regardless of how many seconds it lasts (whether it's 1 second or 10 seconds). It only becomes a new incident if the car establishes a safe distance and then tailgates again.


---

## ✅ Expected Output

The function should return a tuple:
`(tailgating_seconds, minimum_distance, tailgate_incidents)`

### Example

```python
distances = [30.0, 20.0, 20.0, 30.0, 15.0]
speeds    = [50.0, 50.0, 50.0, 50.0, 50.0]

monitor_following_distance(distances, speeds)
# Expected Output: (3, 15.0, 2)
```
*Explanation:*
- Safe distance is `50.0 * 0.5 = 25.0` for the whole trip.
- Sec 1: 30.0 (Safe)
- Sec 2: 20.0 (Tailgating starts - Incident 1)
- Sec 3: 20.0 (Still tailgating)
- Sec 4: 30.0 (Safe again)
- Sec 5: 15.0 (Tailgating starts - Incident 2). Minimum distance updated to 15.0.
- Total tailgating seconds: 3. Minimum distance: 15.0. Tailgate incidents: 2.

## ▶️ How to Run
1. Write your solution in **`Question.py`**.
2. Test your code using the provided unit tests:
```bash
python -m unittest test_following_distance.py
```

## AI Usage Guidelines
For this coding question, using AI to write the code will result in IMMEDIATE disqualification.
