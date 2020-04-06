from points import Point


class Rectangle:

    def __init__(self, x1=0, y1=0, x2=0, y2=0):

        # lewy dolny wierzcholek
        self.pt1 = Point(x1, y1)
        # prawy gorny wierzcholek
        self.pt2 = Point(x2, y2)

    def __str__(self):         # "[(x1, y1), (x2, y2)]"
        return "[" + str(self.pt1) + ", " + str(self.pt2) + "]"

    def __repr__(self):        # "Rectangle(x1, y1, x2, y2)"
        return "Rectangle(" + str(self.pt1.x) + ", " + str(self.pt1.y) + ", " + str(self.pt2.x) + ", " + str(self.pt2.y) + ")"

    def __eq__(self, other):
        if self.pt1 == other.pt1 and self.pt2 == other.pt2:
            return True
        else:
            return False

    def __ne__(self, other):
        return not self == other

    def center(self):
        x = round(abs(float(self.pt2.x - self.pt1.x))/2 + self.pt1.x, 2)
        y = round(abs(float(self.pt2.y - self.pt1.y))/2 + self.pt1.y, 2)
        return Point(x, y)

    def area(self):
        return round(abs(self.pt2.x - self.pt1.x) * abs(self.pt2.y - self.pt1.y), 2)

    def move(self, x, y):
        self.pt1.x += x
        self.pt2.x += x
        self.pt1.y += y
        self.pt2.y += y
        return self
