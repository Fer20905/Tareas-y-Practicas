def fibonacci_bottom_up(n):
    if n == 0:
        return 0
    if n == 1:
        return 1

    f = [0, 1]

    for i in range(2, n + 1):
        f.append(f[i - 1] + f[i - 2])

    return f[n]

if __name__ == "__main__":
    num = 10
    print(f"Fibonacci Bottom-Up de {num} =", fibonacci_bottom_up(num))
    
