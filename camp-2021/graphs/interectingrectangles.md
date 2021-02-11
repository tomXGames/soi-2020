# Intersecting Rectangles
If there is a corner inside the other rectangle, we know they intersect. 

If I take the average of all the points on one rectangle, I know which corner of the other rectangle to check.

First take the average of all the corners on both rectangles (can do this during input to avoid going over the rectangle again).

After that we check the closest corner to the average, by subtracting the oe average from the other and scaling their difference to 1/-1. 

Now we just check for the closest corner, if it is in the other rectangle. Kaboom, we have the solution.

(gross) pseudo-code:
```python

#input:
rectangle1averagex = 0
rectangle1averagey = 0
rectangle1 = []
for i in range(4): 
    cornerx = int(input())
    rectangle1averagex += cornerx
    cornery = int(input())
    rectangle1averagey += cornery
    rectangle1.append([cornerx, cornery])
rectangle1averagex /= 4
rectangle1averagey /= 4

rectangle2averagex = 0
rectangle2averagey = 0
rectangle2 = []
for i in range(4): 
    cornerx = int(input())
    rectangle1averagex += cornerx
    cornery = int(input())
    rectangle2averagey += cornery
    rectangle2.append([cornerx, cornery])
rectangle2averagex /= 4
rectangle2averagey /= 4

rectangle1averagex = ((rectangle1averagex/abs(rectangle1averagex)) < 0) ? 0: rectangle1averagex/abs(rectangle1averagex)
rectangle1averagey = (((rectangle1averagey/abs(rectangle1averagey)) < 0) ? 0: rectangle1averagey/abs(rectangle1averagey)) + 2
cornertocheck = rectangle2[rectangle1averagey * 2 + rectangle1averagex]
if(rectangle1[1][0]>=cornertocheck[0]>=rectangle1[0][0] || rectangle1[0][1]>=cornertocheck[1]>=rectangle1[2][1])
```

It is correct, because when two rectangles intersect at least the corner closest to the middle of the other rectangle is inside that other rectangle. I don'really know how to prove this formally...

The run time is O(1), because it is always the same (a rectangle alwaysw only has 4 corners) and the additional Memory is alsoo constant.