import matplotlib.pyplot as plt

def DDA(xa, ya, xb, yb):
    dx, dy = xb - xa, yb - ya
    steps = max(abs(dx), abs(dy))
    xinc, yinc = dx / steps, dy / steps
    x, y = xa, ya
    X, Y = [], []
    for i in range(steps+1):
        X.append(round(x))
        Y.append(round(y))
        x += xinc
        y += yinc
    return X, Y

xa, ya = 100, 100
xb, yb = 500, 300
X, Y = DDA(xa, ya, xb, yb)

plt.scatter(X, Y, c="magenta", s=10)
plt.show()