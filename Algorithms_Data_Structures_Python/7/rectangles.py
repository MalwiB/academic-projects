from points import Point


class Rectangle:

    def __init__(self, x1=0, y1=0, x2=0, y2=0):
        # Chcemy, aby x1 <= x2, y1 <= y2.
        if not (x1 <= x2 and y1 <= y2):
            raise ValueError, "Wartosci musza spelniac warunek: x1 <= x2, y1 <= y2"
        self.pt1 = Point(x1, y1)
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

    def rect_contains(self, other):
        # other zawiera sie w self
        if other.pt1.x >= self.pt1.x and other.pt1.y >= self.pt1.y and other.pt2.x <= self.pt2.x and other.pt2.y <= self.pt2.y:
            return 1
        # self zawiera sie w other
        elif self.pt1.x >= other.pt1.x and self.pt1.y >= other.pt1.y and self.pt2.x <= other.pt2.x and self.pt2.y <= other.pt2.y:
            return -1
        else:
            return 0

    def intersection(self, other):
        # zawieraja sie
        if self.rect_contains(other) == 1:
            return other
        elif self.rect_contains(other) == -1:
            return self
        # inne mozliwosci
        elif self.pt1.x < other.pt1.x < self.pt2.x < other.pt2.x and self.pt1.y < other.pt1.y < self.pt2.y < other.pt2.y:
            return Rectangle(other.pt1.x, other.pt1.y, self.pt2.x, self.pt2.y)
        elif other.pt1.x < self.pt1.x < other.pt2.x < self.pt2.x and other.pt1.y < self.pt1.y < other.pt2.y < self.pt2.y:
            return Rectangle(self.pt1.x, self.pt1.y, other.pt2.x, other.pt2.y)
        elif self.pt1.x < other.pt1.x < self.pt2.x < other.pt2.x and self.pt2.y > other.pt2.y > self.pt1.y > other.pt1.y:
            return Rectangle(other.pt1.x, self.pt1.y, self.pt2.x, other.pt2.y)
        elif other.pt1.x < self.pt1.x < other.pt2.x < self.pt2.x and other.pt2.y > self.pt2.y > other.pt1.y > self.pt1.y:
            return Rectangle(self.pt1.x, other.pt1.y, other.pt2.x, self.pt2.y)
        # nie przecinaja sie wcale
        else:
            return -1

    def cover(self, other):
        # sytuacja zawierania sie
        if self.rect_contains(other) == 1:
            return self
        elif self.rect_contains(other) == -1:
            return other
        # gdy prostokat znajduje sie po lewej dolnej stronie
        elif self.pt1.x <= other.pt1.x and self.pt1.y <= other.pt1.y:
            return Rectangle(self.pt1.x, self.pt1.y, other.pt2.x, other.pt2.y)
        elif self.pt1.x > other.pt1.x and self.pt1.y > other.pt1.y:
            return Rectangle(other.pt1.x, other.pt1.y, self.pt2.x, self.pt2.y)
        # gdy prostokat znajduje sie po lewej gornej stronie
        elif self.pt1.x <= other.pt1.x and self.pt1.y >= other.pt1.y:
            return Rectangle(self.pt1.x, other.pt1.y, other.pt2.x, self.pt2.y)
        elif self.pt1.x > other.pt1.x and self.pt1.y < other.pt1.y:
            return Rectangle(other.pt1.x, self.pt1.y, self.pt2.x, other.pt2.y)

    def make4(self):
        return [
            Rectangle(self.pt1.x, self.center().y, self.center().x, self.pt2.y),
            Rectangle(self.center().x, self.center().y, self.pt2.x, self.pt2.y),
            Rectangle(self.pt1.x, self.pt1.y, self.center().x, self.center().y),
            Rectangle(self.center().x, self.pt1.y, self.pt2.x, self.center().y)
        ]
