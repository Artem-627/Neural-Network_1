import math

for a in range(1, 150):
    for b in range(1, 150):
        for c in range(1, 150):
            for d in range(1, 150):
                if ((a ** 5 + b ** 5 + c ** 5 + d ** 5)**0.2) % 1 <= 0.0000000001:
                    print(a, b, c, d,
                          ((a ** 5 + b ** 5 + c ** 5 + d ** 5)**0.2) % 1)
                # exit
