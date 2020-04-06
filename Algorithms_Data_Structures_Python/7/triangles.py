from points import Point
from math import fabs


class Triangle:

    def collinear(self, x1, y1, x2, y2, x3, y3):
        # y = ax + b
        if (x1 * y2 + x2 * y3 + x3 * y1 - y2 * x3 - y1 * x2 - x1 * y3) == 0:
            return True
        else:
            return False

    def __init__(self, x1=0, y1=0, x2=0, y2=0, x3=0, y3=0):
        if self.collinear(x1, y1, x2, y2, x3, y3):
            raise ValueError, "Punkty nie moga byc wspolliniowe"
        self.pt1 = Point(x1, y1)
        self.pt2 = Point(x2, y2)
        self.pt3 = Point(x3, y3)

    def __str__(self):        # "[(x1, y1), (x2, y2), (x3, y3)]"
        return "[" + str(self.pt1) + ", " + str(self.pt2) + ", " + str(self.pt3) + "]"

    def __repr__(self):        # "Triangle(x1, y1, x2, y2, x3, y3)"
        return "Triangle(" + str(self.pt1.x) + ", " + str(self.pt1.y) + ", " + str(self.pt2.x) + ", " + str(self.pt2.y) + ", " + str(self.pt3.x) + ", " + str(self.pt3.y) + ")"

    def __eq__(self, other):
        if self.pt1 == other.pt1 and self.pt2 == other.pt2 and self.pt3 == other.pt3:
            return True
        elif self.pt1 == other.pt2 and self.pt2 == other.pt3 and self.pt3 == other.pt1:
            return True
        elif self.pt1 == other.pt3 and self.pt2 == other.pt2 and self.pt3 == other.pt1:
            return True
        else:
            return False

    def __ne__(self, other):
        return not self == other

    def center(self):
        return Point((self.pt1.x + self.pt2.x + self.pt3.x) / 3, (self.pt1.y + self.pt2.y + self.pt3.y) / 3)

    def area(self):
        return fabs(self.pt1.x * (self.pt2.y - self.pt3.y) + self.pt2.x * (self.pt3.y - self.pt1.y) + self.pt3.x * (self.pt1.y - self.pt2.y)) / 2

    def move(self, x, y):
        return Triangle(self.pt1.x + x, self.pt1.y + y, self.pt2.x + x, self.pt2.y + y, self.pt3.x + x, self.pt3.y + y)

    def make3(self):
        return [
            Triangle(self.pt1.x, self.pt1.y, self.pt2.x, self.pt2.y, self.center().x, self.center().y),
            Triangle(self.pt2.x, self.pt2.y, self.pt3.x, self.pt3.y, self.center().x, self.center().y),
            Triangle(self.pt1.x, self.pt1.y, self.pt3.x, self.pt3.y, self.center().x, self.center().y),
        ]
